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
#line 1 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"

#define XQUERY_PARSER

/* Line 293 of lalr1.cc  */
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


/* Line 293 of lalr1.cc  */
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



/* Line 293 of lalr1.cc  */
#line 102 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 784 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"

template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}


/* Line 299 of lalr1.cc  */
#line 121 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 207 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 783 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 125: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 782 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 150: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 781 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "VoidStatement" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "PostfixExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2706 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2715 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2724 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2733 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2742 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2751 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2760 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2769 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2778 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 646: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2787 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 647: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 648: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 649: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2823 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2832 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 652: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2841 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 655: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2850 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 656: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2859 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 657: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2868 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
#line 128 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2965 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 843 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 847 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 851 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 857 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 861 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 865 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 871 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 877 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 885 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 891 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 900 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 905 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 911 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 917 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 923 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 931 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 936 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 944 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 952 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 960 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 969 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 974 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 980 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 986 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 995 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (3)].expr), (yylocation_stack_[(6) - (3)]));
      (yyval.node) = new ModuleDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1003 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1010 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1016 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 1042 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1047 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1053 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1059 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1065 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1070 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1076 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1081 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1087 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1092 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1098 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1103 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1108 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1113 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1123 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\"");
      YYERROR;
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1131 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1136 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1144 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1152 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1161 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1168 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1176 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1182 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1188 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1194 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(6) - (4)].expr), (yylocation_stack_[(6) - (4)]));
      (yyval.node) = new ModuleImport(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1201 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1209 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1220 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(5) - (3)].expr), (yylocation_stack_[(5) - (3)]));
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1227 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1234 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1242 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1249 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1255 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration");
      YYERROR;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1274 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1280 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1287 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1294 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1302 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1309 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1310 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1311 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1312 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinity"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1313 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1314 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1315 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1316 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1317 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1318 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1322 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1336 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1342 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1348 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1355 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1361 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1368 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1373 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1379 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1385 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1397 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1409 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1422 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1427 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1435 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1443 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1452 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1457 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1464 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1469 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1476 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1481 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1489 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1494 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1501 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1507 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1520 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1534 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1547 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1562 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1575 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1580 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1585 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1596 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1603 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1611 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1616 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1624 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1632 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1640 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1648 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1658 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1662 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1668 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1672 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1679 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1688 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1699 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1705 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1712 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1717 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1724 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1731 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1741 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1751 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1761 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1772 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1785 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1819 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1823 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1829 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1834 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1842 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1849 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1856 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 1884 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1889 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      driver.addCommonLanguageWarning((yylocation_stack_[(2) - (1)]), ZED(ZWST0009_EMPTY_BLOCK));
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1896 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* block = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (2)].expr));
      if (block == NULL && (yysemantic_stack_[(3) - (2)].expr) != NULL)
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

  case 190:

/* Line 690 of lalr1.cc  */
#line 1912 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1918 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1924 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1931 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1938 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1947 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                          NULL,
                                          NULL,
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 1956 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)),
                                          NULL,
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 1965 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                          NULL,
                                          (yysemantic_stack_[(4) - (4)].expr),
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 1974 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                                          (yysemantic_stack_[(5) - (5)].expr),
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1985 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1991 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1997 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2003 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 203:

/* Line 690 of lalr1.cc  */
#line 2015 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2020 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2026 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 206:

/* Line 690 of lalr1.cc  */
#line 2038 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 207:

/* Line 690 of lalr1.cc  */
#line 2051 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 208:

/* Line 690 of lalr1.cc  */
#line 2071 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2077 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2084 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2093 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2100 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2106 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2111 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 215:

/* Line 690 of lalr1.cc  */
#line 2123 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 234:

/* Line 690 of lalr1.cc  */
#line 2157 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 235:

/* Line 690 of lalr1.cc  */
#line 2169 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2175 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2180 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2186 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2191 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2196 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2202 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2211 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2222 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 244:

/* Line 690 of lalr1.cc  */
#line 2234 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 245:

/* Line 690 of lalr1.cc  */
#line 2245 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2263 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2270 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2279 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2283 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2293 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2301 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2308 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2315 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2325 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 263:

/* Line 690 of lalr1.cc  */
#line 2335 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 264:

/* Line 690 of lalr1.cc  */
#line 2345 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 265:

/* Line 690 of lalr1.cc  */
#line 2355 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 266:

/* Line 690 of lalr1.cc  */
#line 2365 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 267:

/* Line 690 of lalr1.cc  */
#line 2375 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 268:

/* Line 690 of lalr1.cc  */
#line 2385 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 269:

/* Line 690 of lalr1.cc  */
#line 2395 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 270:

/* Line 690 of lalr1.cc  */
#line 2405 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2414 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 272:

/* Line 690 of lalr1.cc  */
#line 2424 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 273:

/* Line 690 of lalr1.cc  */
#line 2434 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 274:

/* Line 690 of lalr1.cc  */
#line 2446 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2452 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2458 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2464 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2470 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2478 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2486 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2494 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2502 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2512 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2518 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2528 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2532 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2539 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2543 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2551 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2555 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2559 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2565 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2571 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2577 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2583 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2591 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2595 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2603 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2611 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2619 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(1) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, NULL);
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2627 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(2) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(2) - (1)].expr), static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2637 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2643 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2649 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2657 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2663 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2671 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2675 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2683 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2689 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2695 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
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

  case 315:

/* Line 690 of lalr1.cc  */
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

  case 316:

/* Line 690 of lalr1.cc  */
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

  case 317:

/* Line 690 of lalr1.cc  */
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

  case 318:

/* Line 690 of lalr1.cc  */
#line 2739 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2743 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2749 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2755 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 2763 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
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

  case 324:

/* Line 690 of lalr1.cc  */
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

  case 325:

/* Line 690 of lalr1.cc  */
#line 2789 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2822 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2828 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2836 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2842 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2848 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2856 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2862 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2868 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2876 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2882 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2889 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2899 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2906 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2916 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2922 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2930 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2936 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 2945 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2951 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2959 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 2965 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2974 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2980 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2988 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 2994 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 2998 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3004 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3009 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3015 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
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

  case 360:

/* Line 690 of lalr1.cc  */
#line 3028 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
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

  case 362:

/* Line 690 of lalr1.cc  */
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

  case 363:

/* Line 690 of lalr1.cc  */
#line 3052 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            driver.getXqueryLexer()->interpretAsLessThan();
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
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

  case 365:

/* Line 690 of lalr1.cc  */
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

  case 366:

/* Line 690 of lalr1.cc  */
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

  case 367:

/* Line 690 of lalr1.cc  */
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

  case 368:

/* Line 690 of lalr1.cc  */
#line 3094 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
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

  case 370:

/* Line 690 of lalr1.cc  */
#line 3109 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3113 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3118 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3122 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3128 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3132 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3138 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3142 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3146 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3152 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3156 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3162 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3168 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3174 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3182 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3186 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3190 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3196 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3200 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3206 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3214 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3218 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3226 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3230 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3238 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3242 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3250 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3254 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3262 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3266 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3272 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3276 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3282 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3286 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3290 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3294 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3307 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3312 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3318 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3322 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3326 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3330 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3334 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3338 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3344 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3348 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3352 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3358 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3362 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3366 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3370 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3379 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3387 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3393 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3401 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 3405 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 3409 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 3415 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 3419 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 3427 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 3435 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3453 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 3459 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

/* Line 690 of lalr1.cc  */
#line 3469 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 3473 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 3483 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 3489 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 3497 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 3503 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 3513 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 3519 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 3527 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 3531 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 3535 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 3539 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 3543 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 3549 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 3555 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 3561 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 3565 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 3571 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 3575 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 3584 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 3588 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 3592 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 3598 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 3602 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 3614 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 3618 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 3624 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 3628 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 3632 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 3636 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 3642 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 3646 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 3650 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 3654 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 3660 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      PredicateList* pl = new PredicateList( LOC((yyloc)) );
      pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.node) = pl;
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 3666 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if (PredicateList* pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)))
        pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 3674 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 3696 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 3700 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 3706 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 3713 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 3720 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 3729 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 3735 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 3739 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 3745 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 3752 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 3758 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 3764 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FunctionCall(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL);
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 3768 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3786 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList* al = new ArgList(LOC((yyloc)));
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 3792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if (ArgList* al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)))
        al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 3798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 3804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 3812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 3816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 3822 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 3828 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3847 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3855 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3871 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3879 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3897 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3915 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3933 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 3939 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 3948 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 3954 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 3963 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 3973 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 3978 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 3984 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 3988 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 3994 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4000 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4006 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4013 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4021 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4025 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4031 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4037 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4043 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4050 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4059 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4063 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4069 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4073 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4079 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4083 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4087 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4092 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4099 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4103 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4107 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4111 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4117 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4122 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4128 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4134 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4141 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4147 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4152 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4157 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 4162 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 4167 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 4172 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 4180 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 4186 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 4190 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 4196 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 4200 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 4206 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 4212 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 4218 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 4222 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 4228 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 4232 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 4238 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 4244 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 4248 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 4252 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 4258 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 4264 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 4270 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 4278 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            GeneralizedAtomicType* gat = static_cast<GeneralizedAtomicType*>((yysemantic_stack_[(1) - (1)].node));
            QName* q = gat->get_qname();
            if (q->get_qname() == "item")
            {
              driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_JSONIQ_TYPE_KEYWORDS));
              (yyval.node) = new ItemType( LOC((yyloc)), true );
            }
            else
            {
              (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            }
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 4292 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 4296 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 4300 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 4304 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 4308 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 4312 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 4318 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 4324 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 4332 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 4338 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 4344 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 4348 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 4352 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 4356 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 4360 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 4364 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 4368 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 4372 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 4376 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 4380 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 4386 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 4392 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 4398 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 4402 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 4406 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 4412 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 4417 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 4423 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 4429 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 4433 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(4) - (3)].expr), (yylocation_stack_[(4) - (3)]));
            (yyval.node) = new PITest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 4438 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 4444 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 4448 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 4454 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 4460 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 4464 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 4472 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 4478 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 4482 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 4488 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 4497 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 4506 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 4512 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 4518 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 4526 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 4532 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 4538 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 4544 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 4550 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 4554 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 4560 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 4566 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 4570 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 4578 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 4584 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 4590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 4596 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 4604 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 4608 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 4614 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 4620 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 4624 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 4630 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 4634 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 4640 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 4646 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 4653 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 4661 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 4666 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 4672 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 4678 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 4686 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 4692 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 4699 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 4705 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 4714 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 4720 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 4726 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 4732 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 4741 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 4748 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 4754 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 4760 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 4769 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 4776 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 4780 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 4786 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 4791 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 4798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 4802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 4808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 4812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 4818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 4822 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 4828 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 4832 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 4840 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 4850 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 4854 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 4859 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 4863 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 4869 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 4875 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 4883 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 4887 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 4892 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 4896 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 4902 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 4911 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 4915 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 4921 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 4931 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 4937 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 4944 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 4948 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 4954 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 4958 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 4962 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 4967 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 4971 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 4976 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 4980 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 4986 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 4990 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 4994 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 4998 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 5002 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 5008 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 5014 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5024 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5034 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 5038 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 5042 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 5048 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 5054 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 5062 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 5066 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 5070 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 5074 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 5078 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 5082 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 5086 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 5090 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 5096 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 5100 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 5104 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 5108 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 5114 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 5120 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 5128 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 5136 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 5140 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 5146 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5156 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5167 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 5173 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 5177 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 5182 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 5186 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 5192 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 5197 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 5204 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 5211 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 5215 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 5221 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 5225 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 5231 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5240 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 5247 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 5255 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 5259 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 5265 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 5271 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 5278 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 5282 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 5288 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 5293 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5303 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5311 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5321 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 5327 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 5331 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 5337 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 5341 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 5345 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 5351 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 5357 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 5361 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 5365 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 5369 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 5375 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5383 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5393 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 5397 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 5403 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 5409 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 5413 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 5419 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 5423 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 5429 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 5433 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 5439 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 5446 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 5452 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 5461 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 5467 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5477 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 5483 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 5489 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5510 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5534 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5558 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 5562 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 5566 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 5575 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 5576 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 5577 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 5578 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 5579 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 5580 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 5581 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 5582 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 5583 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 5584 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 5585 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 5586 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 5587 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 5588 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 5589 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 5590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 5591 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 5592 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 5593 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 5594 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 5595 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 5596 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 5600 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 5601 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 5602 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 5603 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 5604 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 5605 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 5606 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 5607 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 5608 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 5609 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 5610 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 5611 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 5612 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 5613 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 5614 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 5615 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 5616 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 5617 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 5618 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 5619 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 5620 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 5621 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 5622 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 5623 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 5624 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 5625 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 5626 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 5627 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 5628 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 5629 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 5630 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 5631 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 5632 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 5633 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 5634 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 5635 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 5636 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 5637 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 5638 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 5639 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 5640 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 5641 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 5643 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 5644 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 5645 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 5646 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 5647 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 5648 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 5649 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 5650 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 5651 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 5652 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 5653 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 5654 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 5655 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 5656 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 5657 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 5658 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 5659 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 5660 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 5661 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 5662 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 5663 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 5664 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 5665 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 5666 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 5667 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 5668 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 5669 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 5670 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 5671 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 5672 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 5673 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 5674 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 5675 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 5676 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 5677 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 5678 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 5679 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 5680 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 5681 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 5682 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 5683 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 5684 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 5685 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 5686 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 5687 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 5688 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 5689 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 5690 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 5691 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 5692 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 5693 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 5694 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 5695 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 5696 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 5697 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 5698 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 5699 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 5700 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 5701 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 5702 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 5703 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 5704 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 5705 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 5706 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 5707 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 5708 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 5709 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 5710 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 5711 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 5712 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 5713 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 5714 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 5715 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 5716 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 5717 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 5718 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 5719 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 5720 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 5721 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 5722 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 5723 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 5724 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 5725 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 5726 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 5727 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 5728 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 5729 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 5730 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 5731 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 5732 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 5733 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 5734 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 5735 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 5736 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 5737 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 5738 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 5739 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 5740 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 5741 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 5742 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 5743 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 5744 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 5745 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 5746 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 5747 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 5748 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 5749 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 5750 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 5751 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 5752 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 5753 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 5754 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 5755 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 5756 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 5757 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 5758 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 5759 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 5760 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 5761 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 5762 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 5763 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 5764 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 5765 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 5766 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 5767 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 5768 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 5769 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 5770 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 5771 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 5772 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 5773 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 5774 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 5775 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 5776 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 5777 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 5778 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 5779 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 5780 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 5781 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 5782 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 5783 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 5784 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 5785 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 5786 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 5787 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 5788 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 5789 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 5790 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 5791 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 5792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 5793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 5794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1021:

/* Line 690 of lalr1.cc  */
#line 5795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1022:

/* Line 690 of lalr1.cc  */
#line 5796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1023:

/* Line 690 of lalr1.cc  */
#line 5797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1024:

/* Line 690 of lalr1.cc  */
#line 5798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1025:

/* Line 690 of lalr1.cc  */
#line 5799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1026:

/* Line 690 of lalr1.cc  */
#line 5802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12080 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1438;
  const short int
  xquery_parser::yypact_[] =
  {
      5056, -1438, -1438, -1438, -1438,  6610,  6610,  6610,  6610, -1438,
   -1438,    -5,    14, -1438,   140,    40, -1438, -1438, -1438,   774,
   -1438, -1438, -1438,   266,   224,   860,  4774,   328,   349,   129,
   -1438,    50, -1438,   357, -1438, -1438, -1438, -1438, -1438,   864,
   -1438,   395,   483, -1438, -1438, -1438, -1438,   291, -1438,   865,
   -1438,   527,   541, -1438,   269, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,   581,
     601, -1438, -1438, -1438, -1438,    28, 12810, -1438, -1438, -1438,
     607, -1438, -1438, -1438,   722, -1438,   654,   778, -1438, -1438,
   16681, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,   744,
   -1438, -1438,   840,   869, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438,  5680,  9090,  9400, 16681, -1438, -1438,   728, -1438, -1438,
   -1438, -1438,   801, -1438, -1438,   884, 16681, -1438, 13721,   892,
     901, -1438, -1438, -1438,   922, -1438, -1438, 12190, -1438, -1438,
   -1438, -1438, -1438, -1438,   894, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438,   135,   834, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438,   -65,   917,   179, -1438,   -84,   148, -1438,
   -1438, -1438, -1438, -1438, -1438,   956, -1438,   835,   836,   841,
   -1438, -1438,   927,   926, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438,  9710, 10020, -1438,
     772, -1438, -1438, -1438, -1438, -1438,  5368,  6920,  1088, -1438,
    7230, -1438, -1438,   123,    80, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,    92,
   -1438, -1438, -1438, -1438, -1438, -1438,   361, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438,  6610, -1438, -1438, -1438, -1438,
      21, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
     237, -1438,   899, -1438, -1438, -1438,   686, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438,   924,   997, -1438,   853,   843,
     993,   498,   636,   755,   474, -1438,  1044,   895,   994,   995,
   10640, -1438,   904, -1438, -1438,   617, -1438, -1438, 12500, -1438,
     838, -1438,   944, 12810, -1438,   944, 12810, -1438, -1438, -1438,
     889, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,   943, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438,   789, -1438, -1438, -1438,
   -1438, -1438,   918, -1438,  6610,   919,   920,   921,  6610,   329,
     329,  1071,   655,   761,    -8, 17269, 16681,   508,  1059, 16681,
     954,   989,   719, 16681,   805,   866, 16681, 16681,   806,   832,
      37, -1438, -1438, -1438, 16681,  6610,   929,  6610,   149, 10950,
   14017, 16681, -1438,   829,   830, 16681,   998,    12,   965, 10950,
    1119,    72,   402, 16681,  1005,   982,  1018, -1438,   940, 10950,
   14313, 16681, 16681, 16681,  6610,   942, 10950, 10950, 16681,  6610,
     976,   977, -1438, -1438, -1438, 10950, 14609,   978, -1438,   981,
   -1438, -1438, -1438, -1438,   983, -1438,   984, -1438, -1438, -1438,
   -1438, -1438,   985, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438, 16681, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438,   990, 16681, -1438, -1438, -1438,
     955,  5990,  1021,   310,   991,   992,   996, 16681,  6610, -1438,
    1000,   287, -1438,   746, -1438,   132,  1112, 10950, 10950, -1438,
      93, -1438, -1438,  1134, -1438, -1438, -1438, -1438, 10950,   941,
   -1438,  1126, 10950, 10950, 16981, 10950, 10950, 10950, 10950, 16981,
   10950,   928,   931, 16681,   967,   973, 10950, 10950,  5680,   932,
   -1438,    45, -1438,    56, 10950,  6920, -1438, -1438, -1438, -1438,
   -1438,   140,   129,    94,    95,  1162,  7540,  3512,  7850,  3833,
     722, -1438, -1438,   351,   722, -1438, 10950,  4453, -1438,  1047,
     621,    50,   999,  1002,  1003,  6610, 10950, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, 11260, 11260, 11260, -1438, 11260,
   11260, -1438, 11260, -1438, 11260, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, 11260, 11260,  1098, 11260, 11260, 11260, 11260, 11260,
   11260, 11260, 11260, 11260, 11260, 11260, 11260,   939,  1079,  1084,
    1085, -1438, -1438, -1438, 11880,  6610, -1438, -1438, 12190, 12190,
   10950,   944, -1438, -1438,   944, -1438,  8470,   944,  1001,  1031,
    8780, -1438, -1438, -1438, -1438,    19, -1438,   375, -1438, -1438,
   -1438, -1438, -1438, -1438,  1074,  1075,   328,  1154, -1438, -1438,
   17269,   952,   680, 16681,  1024,  1025,   952,  1071,  1061,  1054,
   -1438, -1438, -1438,   465,   945,  1095,   893, 16681,  1050, 10950,
    1076, 16681, 16681, -1438,  1063,  1010, -1438,  1013,   981,   483,
   -1438,  1011,  1012,    85, -1438,   409,   415,  1092, -1438,    52,
   -1438, -1438,  1092, 16681,    22, 16681,  1106,   417, -1438,  6610,
   -1438,   134, -1438, 16681,  1105,  1158, 16681,  1071,  1107,   558,
   16681, 10950,    50, -1438,   262,  1019, -1438,  1020,  1022,  1023,
     223, -1438,   431,  1027, -1438,   142,   147,  1051, -1438,  1028,
    6610,  6610,   314, -1438,   425,   443,   568, 10950,   294, -1438,
   -1438, 10950, 10950, -1438, 10950, 10950, 10950, -1438, 10950, -1438,
   10950, -1438, 16681,  1112, -1438,    26,   373,   392, -1438, -1438,
   -1438,   416, -1438,    13, -1438, -1438,  1060,  1062,  1064,  1065,
    1066,   889,   789,   461,   502,    -6,     2,  1113,   548,   986,
     988,  1007,   118, -1438,  1072, -1438, -1438,  1032,   154,  5990,
     432, 13120,   932, -1438, -1438, -1438,  1006, -1438,   123,   754,
    1188,   666, -1438, -1438,    97, -1438, -1438, -1438,    99, -1438,
     161, -1438, -1438, -1438, -1438, -1438,  4143, -1438, -1438, -1438,
   16681,  1055, 10950, 11570, -1438, -1438, -1438,   997, -1438, -1438,
   -1438, -1438, -1438, 11260, -1438, -1438, -1438,   153, -1438,   636,
     636,   592,   755,   755,   755,   755,   474,   474, -1438, -1438,
   15793, 15793, 16681, 16681, -1438,  1040, -1438, -1438,   365, -1438,
   -1438, -1438, -1438,   447, -1438, -1438, -1438,   475,   329, -1438,
   -1438,   695,   740,   753, -1438,   328, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438,   952, -1438,  1093, 16089,
    1086, 10950, -1438, -1438, -1438,  1132,  1071,  1071,   952, -1438,
     923,  1071,   723, 16681,   709,   717,  1198, -1438, -1438,   946,
     551, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438,   465,    46,  1004,   690, 10950, -1438, 16681,  1135,
     934,  1071, -1438, -1438, -1438, -1438,  1080, 16681, -1438, 16681,
   -1438, 16385,  1108, 15793,  1121, 10950,   -51,  1096,    43,   499,
     987, -1438, -1438,   826,    22,  1132, 15793,  1124,  1150,  1067,
    1048,  1114,  1071,  1087,  1116,  1153,  1071, 10950,   -54, -1438,
   -1438, -1438,  1099, -1438, -1438, -1438, -1438,  1133, 10950, 10950,
    1109, -1438,  1157,  1160,  6610, -1438,  1070,  1078,  1101, 16681,
   -1438, 16681, -1438, 10950,  1120,  1069, 10950, -1438,  1142,   185,
     203,   204,  1230, -1438,   370, -1438,   334,  1115, -1438, -1438,
    1236, -1438,   677, 10950, 10950, 10950,   815, 10950, 10950, 10950,
   10950, 10950, 10950, 10950, 10950, 10950, 16981,  1148, 10950, 10950,
   -1438,  8160,   113,  1026, -1438,   243, -1438, 10950,   104,   176,
     161,  7850,  3833,  7850,  1190, -1438, -1438, 10950,   854,  1164,
   -1438, 16681,  1161,  1166, -1438, -1438, 10950,   153,   797,   675,
   -1438,  1008,   333,  1017,  1016, -1438, -1438,   866, -1438,  1014,
     515,  1122,  1123, 16089,  1125,  1129,  1130,  1131,  1137, -1438,
     232, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438,  1138, -1438, -1438, -1438, -1438, 10330, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438,   759, -1438,  1247,   861,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,  1009,
   -1438, -1438,  1260, -1438, -1438, -1438, -1438, -1438,   595,  1261,
   -1438,   741, -1438, -1438, -1438,   978,   224,   357,   983,   395,
     984,   985, -1438,  1129,  1130,  1131, -1438,   232,   232, 11880,
    1015,  1029, -1438,  1132,    46,  1073,  1102,  6610,  1110,  1111,
    1159,  1118,  1127, 16681, -1438,   283, -1438, 16681, -1438, 10950,
    1151, 10950,  1178, 10950,   -41,  1163, 10950,  1165, -1438,  1191,
    1193, 10950, 16681,   949,  1231, -1438, -1438, -1438, -1438, -1438,
   -1438, 15793, -1438,  6610,  1071,  1211, -1438, -1438, -1438,  1071,
    1211, -1438, 10950,  1177,  6610, 16681, -1438, -1438, 10950, 10950,
     770, -1438,    -7,   848, -1438, 14905,   852, -1438,   859, -1438,
    1140, -1438, -1438,  6610,  1141,  1144, -1438, 10950, -1438, -1438,
   10950,  1136,  1157,  1220, -1438,  1189, -1438,   406, -1438, -1438,
    1318, -1438, -1438,  6610, 16681, -1438,   532, -1438, -1438, -1438,
    6610,  1139,  1094,  1100, -1438, -1438, -1438,  1103,  1104, -1438,
   -1438, -1438,  1235, -1438, -1438, -1438, -1438,  1128,   -42, 16681,
    1152, -1438,  1182,  1183,  1184,  1195, -1438,   899,   747, 13120,
    1026, -1438,  6300, 13120, -1438, -1438,  1188,   640, -1438, -1438,
   -1438,  1164, -1438,  1071, -1438,   925, -1438,   264,  1237, -1438,
   10950,   658,  1071, -1438, 11570,   451,  1155, -1438,   153,  1097,
   -1438, -1438,   -44, -1438,   346,   105,  1145,   153,   346, 11260,
   -1438,   389, -1438, -1438, -1438, -1438, -1438, -1438,   153,  1197,
    1068,   945,   105, -1438, -1438,  1057,  1273, -1438, -1438, -1438,
   13416,  1168,  1169,  1170,  1171,  1172,  1173,  1174, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438,  1333,   268,  1336,   268,  1117,  1262, -1438, -1438,  1199,
   16681,  1146, -1438, -1438, 11880, -1438,  1187, -1438, -1438, -1438,
   -1438, -1438, -1438, 10950,  1224, -1438, -1438, 10950, -1438,   301,
   -1438, 10950,  1225, 10950, -1438, 10950, 16681, 16681, -1438,   802,
   -1438, 10950, -1438,  1250,  1252,  1277,  1071,  1211, -1438, 10950,
    1196, -1438, -1438, -1438,  1204, -1438,   253, 10950,  6610,  1205,
     256, -1438, 16681,   413, -1438, 15201,   284, -1438, 15497,  1215,
   -1438, -1438,  1200, -1438, -1438, -1438, -1438, 10950,   863,  1230,
   16681,   565, -1438,  1213,  1230, 16681, -1438,  1221, -1438, 10950,
   10950, 10950, 10950,  1143, 10950, 10950, -1438, 10950, 10950, 10950,
   10950,  8160,   380, -1438, -1438, -1438, -1438, -1438,  1237, -1438,
   -1438, -1438, 10950,  1238, -1438, -1438, -1438, -1438, -1438,  1226,
   11260, -1438, -1438, -1438, -1438, -1438,   315, 11260, 11260,   614,
   -1438,  1017, -1438,   500, -1438,  1016,   153,  1228, -1438, -1438,
    1167, -1438, -1438, -1438, -1438,  1288,  1222, -1438,   479, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438,    35,    35, -1438,
     268, -1438, -1438,   484, -1438,  1381,   105,  1315,  1229, 11880,
      -1,  1156,  1245, -1438, -1438, 10950, -1438, 10950,  1271, -1438,
   10950, -1438, -1438, -1438,  1366, -1438, -1438,  8160, 10950,  1071,
   -1438, -1438, -1438, 10950, 10950, -1438, -1438, -1438,  8160,  8160,
    1327,  6610, 15793, 16681,   526, 16681, 10950, 16681,   563,  8160,
   -1438,   317,   164,  1230, 16681, -1438,  1227,  1230, -1438, -1438,
   -1438, -1438, -1438, 10950, -1438, -1438, -1438,   227,   242,   247,
   10950, -1438, -1438,  1161, 10950, -1438,   755, 11260, 11260,   592,
     591, -1438, -1438, -1438, -1438, -1438, -1438, 10950, -1438, 15793,
   -1438, 15793,  1328, -1438, -1438, -1438,  1395, -1438, -1438, -1438,
    1175,  1322, -1438, -1438,  1323, -1438,   318, 16681,  1313,  1214,
   16681, 11880, -1438, -1438, 10950, -1438,  1319, -1438, -1438,  1211,
   -1438, -1438, 15793, -1438, -1438, -1438,  1347, 10950,  1259, -1438,
    1351,  8160, -1438, 16681,   752,   646, -1438,  1251,  1230, -1438,
    1253, -1438,  1254,  1157,  1160,   462, -1438,  1161,   592,   592,
   11260,   470, -1438, -1438, 15793, -1438, -1438,  1315, 11880, -1438,
    1237,  1176, 16681,  1332,  1232,  1323, -1438, 16681,   594, 15793,
    6610, 15793,  1267, -1438, -1438,  1361,   786, -1438, -1438, -1438,
   -1438,  1275,   813, -1438, -1438, -1438,  1263, -1438,  8160,   867,
   -1438, -1438,   592, -1438, -1438, -1438, -1438, -1438, 10950,  1179,
   16681,  1342, -1438,  6610,   639, -1438, -1438,   649, 10950, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438,  1343, -1438,  1180,  1181,
   16681, -1438, -1438, 10950,  8160, 16681,  1186, 10950,  1194,  1278,
   11880, -1438, 11880,  8160, -1438,  1264,  1185, 16681,  1240,  1348,
   16681,  1202, 11880, -1438
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       165,   467,   468,   803,   469,   168,   168,   168,     0,   826,
    1026,   120,   122,   634,   919,   928,   868,   831,   829,   805,
     920,   923,   875,   835,   806,   808,     0,   929,   810,   926,
     897,   877,   851,   807,   872,   873,   924,   921,   871,   812,
     927,   813,   814,   968,   980,   967,   869,   888,   882,   815,
     870,   817,   816,   969,   906,   907,   874,   848,   990,   991,
     992,   993,   994,   995,   996,   997,   998,   999,  1000,  1014,
    1021,   896,   892,   883,   862,   804,     0,   891,   899,   908,
    1015,   887,   493,   863,   864,   922,  1016,  1022,   884,   901,
       0,   499,   456,   495,   894,   828,   885,   886,   915,   889,
     905,   914,  1020,  1023,   834,   876,   917,   494,   904,   910,
     809,     0,     0,     0,     0,   403,   902,   913,   918,   916,
     895,   881,   970,   879,   880,  1017,     0,   402,     0,  1018,
    1024,   911,   865,   890,  1019,   212,   434,     0,   466,   912,
     893,   900,   909,   903,   971,   856,   861,   860,   859,   858,
     857,   818,   878,     0,   827,   925,   849,   961,   960,   962,
     833,   832,   852,   959,   811,   956,   964,   958,   957,   855,
     898,   954,   966,   965,   953,   853,   963,   975,   976,   973,
     974,   972,   819,   977,   978,   979,   945,   944,   931,   847,
     840,   938,   934,   850,   846,   946,   867,   836,   837,   830,
     839,   943,   942,   939,   935,   951,   952,   950,   941,   937,
     930,   838,   949,   948,   842,   844,   843,   936,   940,   932,
     845,   933,   841,   947,  1001,  1002,  1003,  1004,  1005,  1006,
     982,   983,   981,   987,   988,   989,   984,   985,   986,   854,
    1007,  1008,  1009,  1010,  1011,  1012,  1013,     0,     0,   820,
     955,  1025,   822,   821,   823,   824,   165,   165,     0,     2,
     165,     9,    11,    23,     0,    28,    31,    36,    37,    38,
      39,    40,    41,    42,    32,    58,    59,    33,    34,     0,
      76,    79,    80,    35,    81,    82,     0,   118,    83,    84,
      85,    86,    18,   162,   163,   164,   171,   174,   486,   175,
       0,   176,   177,   178,   179,   180,   181,   182,   185,   186,
       0,   213,   221,   216,   248,   254,     0,   246,   247,   223,
     217,   184,   218,   183,   219,   222,   354,   356,   358,   368,
     370,   374,   376,   379,   384,   387,   390,   392,   394,   396,
       0,   400,   407,   406,   408,     0,   425,   409,   430,   433,
     435,   438,   440,     0,   445,   442,     0,   453,   463,   465,
     439,   470,   477,   491,   478,   479,   480,   483,   484,   481,
     485,   508,   509,   482,   512,   514,   515,   516,   513,   561,
     562,   563,   564,   565,   566,   567,   462,   606,     0,   597,
     605,   604,   603,   602,   599,   601,   598,   600,   492,    43,
     224,   225,   227,   226,   228,   220,   488,   489,   490,   487,
     230,   233,   229,   231,   232,   464,   802,   825,   919,   928,
     926,   827,     0,   166,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,   258,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   276,   277,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   458,   461,   448,     0,     0,   805,   835,   808,
     866,   929,   810,   877,   812,   888,   815,   817,   816,   906,
    1014,  1021,   804,  1015,   864,  1016,  1022,   889,  1020,  1023,
     913,   970,  1017,  1018,  1024,  1019,   971,   959,   956,   958,
     957,   853,   975,   976,   973,   819,   977,   955,   454,   802,
     446,     0,   193,   447,   450,   805,   806,   808,   807,   812,
     813,   814,   815,   804,   811,   496,     0,   452,   451,   188,
       0,     0,   213,     0,   810,   817,   816,     0,   168,   782,
     977,     0,   221,     0,   497,     0,   528,     0,     0,   457,
       0,   428,   429,     0,   460,   459,   449,   432,     0,     0,
     557,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     784,     0,   786,     0,     0,   165,     3,     4,     1,    10,
      12,     0,     0,     0,     0,     6,   165,     0,   165,     0,
       0,   119,   172,     0,     0,   191,     0,     0,   200,     0,
       0,     0,     0,     0,     0,     0,     0,   205,   234,   253,
     249,   255,   250,   252,   251,     0,     0,     0,   419,     0,
       0,   417,     0,   363,     0,   418,   411,   416,   415,   414,
     413,   412,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   405,   404,   401,     0,   168,   426,   431,     0,     0,
       0,   441,   474,   444,   443,   455,     0,   471,     0,     0,
       0,   569,   571,   575,   577,     0,   124,     0,   801,    47,
      44,    45,    48,    49,     0,     0,     0,     0,    50,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     641,   642,   643,     0,   103,   142,     0,     0,   112,     0,
       0,     0,     0,   127,     0,     0,   614,     0,     0,     0,
     609,     0,     0,     0,   624,     0,     0,   257,   259,     0,
     236,   237,   256,     0,     0,     0,   134,     0,   138,   168,
     511,     0,    60,     0,    69,     0,     0,     0,    61,     0,
       0,     0,     0,   612,     0,     0,   615,     0,     0,     0,
       0,   325,     0,     0,   613,     0,     0,     0,   632,     0,
       0,     0,     0,   618,     0,     0,   195,     0,     0,   189,
     187,     0,     0,   788,     0,     0,     0,   496,     0,   783,
       0,   498,   529,   528,   525,     0,     0,     0,   559,   558,
     427,     0,   556,     0,   654,   655,     0,     0,     0,     0,
       0,   795,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   660,     0,   203,   204,     0,     0,     0,
       0,     0,   208,   209,   785,   787,     0,     5,    24,     0,
      25,     0,     7,    29,     0,    15,     8,    30,     0,    19,
     919,    77,    16,    78,    20,   194,     0,   192,   214,   215,
       0,     0,     0,     0,   206,   235,   294,   355,   357,   361,
     367,   366,   365,     0,   362,   359,   360,     0,   371,   378,
     377,   375,   381,   382,   383,   380,   385,   386,   389,   388,
       0,     0,     0,     0,   410,     0,   436,   437,     0,   475,
     504,   472,   506,     0,   607,   510,   502,     0,     0,   121,
     123,     0,     0,     0,   102,     0,    92,    94,    95,    96,
      97,    99,   100,   101,    93,    98,    88,    89,     0,     0,
     108,     0,   104,   106,   107,   114,     0,     0,    87,    46,
       0,     0,     0,     0,     0,     0,     0,   732,   737,     0,
       0,   733,   767,   720,   722,   723,   724,   726,   728,   727,
     725,   729,     0,     0,     0,     0,     0,   111,     0,   144,
       0,     0,   574,   568,   610,   611,     0,     0,   628,     0,
     625,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,   239,     0,   244,   140,     0,     0,   135,     0,
       0,     0,     0,     0,     0,    62,     0,     0,     0,   275,
     281,   278,     0,   617,   616,   623,   631,     0,     0,     0,
       0,   573,     0,     0,     0,   420,     0,     0,     0,     0,
     621,     0,   619,     0,   196,     0,     0,   789,     0,     0,
       0,     0,   528,   526,     0,   517,     0,     0,   500,   501,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,     0,     0,     0,   668,     0,   210,     0,     0,     0,
       0,   165,     0,   165,     0,   173,   245,     0,   309,   305,
     307,     0,   302,   295,   296,   364,     0,     0,     0,     0,
     698,   372,   671,   675,   677,   679,   681,   684,   691,   692,
     700,   929,   809,     0,   818,   822,   821,   823,   824,   391,
     580,   586,   587,   590,   635,   636,   591,   592,   595,   393,
     395,   398,   596,   397,   424,   476,     0,   473,   503,   125,
      56,    57,    54,    55,   131,   130,     0,    90,     0,     0,
     109,   110,   115,    74,    75,    52,    53,    73,   738,     0,
     741,   768,     0,   731,   730,   735,   734,   766,     0,     0,
     743,     0,   739,   742,   721,     0,     0,     0,     0,     0,
       0,     0,   608,     0,     0,     0,   143,   146,   148,     0,
       0,     0,   113,   116,     0,     0,     0,   168,     0,     0,
     632,     0,     0,     0,   261,     0,   579,     0,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   240,     0,
       0,     0,     0,   288,     0,   285,   290,   243,   141,   136,
     139,     0,   190,     0,     0,    71,    65,    68,    67,     0,
      63,   279,     0,     0,   168,     0,   323,   327,     0,     0,
       0,   330,     0,     0,   336,     0,     0,   343,     0,   347,
       0,   422,   421,   168,     0,     0,   197,     0,   199,   324,
       0,     0,     0,     0,   529,     0,   519,     0,   552,   549,
       0,   553,   554,     0,     0,   548,     0,   523,   551,   550,
       0,     0,     0,     0,   647,   648,   644,     0,     0,   652,
     653,   649,   791,   792,   658,   796,   656,     0,     0,     0,
       0,   662,   810,   817,   816,   977,   202,     0,     0,     0,
     663,   664,     0,     0,   211,   794,    26,     0,    17,    21,
      22,   306,   318,     0,   319,     0,   310,   311,   312,   313,
       0,   496,     0,   303,     0,     0,     0,   682,   695,     0,
     369,   373,     0,   714,     0,     0,     0,     0,     0,     0,
     670,   672,   673,   709,   710,   711,   713,   712,     0,     0,
     686,   685,     0,   689,   693,   707,   705,   704,   697,   701,
       0,     0,     0,     0,     0,     0,     0,     0,   583,   585,
     584,   581,   399,   505,   507,   133,   132,    91,   105,   755,
     736,     0,   760,     0,   760,   749,   744,   147,   149,     0,
       0,     0,   117,   145,     0,    27,     0,   629,   630,   633,
     626,   627,   260,     0,     0,   274,   266,     0,   270,     0,
     264,     0,     0,     0,   283,     0,     0,     0,   242,   286,
     289,     0,   137,     0,     0,    70,     0,    64,   280,     0,
       0,   326,   328,   333,     0,   331,     0,     0,     0,     0,
       0,   337,     0,     0,   351,     0,     0,   344,     0,     0,
     348,   423,     0,   622,   620,   198,   790,     0,     0,   528,
       0,     0,   560,     0,   528,     0,   524,     0,    14,     0,
       0,     0,     0,     0,     0,     0,   661,     0,     0,     0,
       0,     0,     0,   665,   669,   322,   320,   321,   314,   315,
     316,   308,     0,     0,   304,   297,   699,   690,   696,     0,
       0,   769,   770,   780,   779,   778,     0,     0,     0,     0,
     771,   676,   777,     0,   674,   678,     0,     0,   683,   687,
       0,   708,   703,   706,   702,     0,     0,   593,     0,   588,
     640,   582,   800,   799,   798,   589,   756,     0,     0,   754,
     761,   762,   758,     0,   753,     0,   751,     0,     0,     0,
       0,     0,     0,   570,   263,     0,   272,     0,     0,   268,
       0,   271,   284,   292,   293,   287,   241,     0,     0,     0,
      66,   282,   576,     0,     0,   334,   338,   332,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     572,     0,     0,   528,     0,   555,     0,   528,   578,   645,
     646,   650,   651,     0,   657,   797,   659,     0,     0,     0,
       0,   666,   317,   298,     0,   694,   781,     0,     0,   773,
       0,   719,   718,   717,   716,   715,   680,     0,   772,     0,
     637,     0,     0,   765,   764,   763,     0,   757,   750,   748,
       0,   745,   746,   740,   150,   152,   154,     0,     0,     0,
       0,     0,   267,   265,     0,   273,     0,   207,   353,    72,
     329,   335,     0,   349,   345,   352,     0,     0,     0,   339,
       0,     0,   341,     0,   538,   532,   527,     0,   528,   518,
       0,   793,     0,     0,     0,     0,   301,   299,   775,   774,
       0,     0,   638,   594,     0,   759,   752,     0,     0,   156,
     155,     0,     0,     0,     0,   151,   269,     0,     0,     0,
       0,     0,     0,   546,   540,     0,   539,   541,   547,   544,
     534,     0,   533,   535,   545,   520,     0,   521,     0,     0,
     667,   300,   776,   688,   639,   747,   153,   157,     0,     0,
       0,     0,   291,     0,     0,   342,   340,     0,     0,   531,
     542,   543,   530,   536,   537,   522,     0,   158,     0,     0,
       0,   350,   346,     0,     0,     0,     0,     0,     0,     0,
       0,   160,     0,     0,   159,     0,     0,     0,     0,     0,
       0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1438, -1438,  -224,  -196, -1438,  1206,  1209, -1438,  1207,  -551,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
   -1020, -1438, -1438, -1438, -1438,  -241,  -584, -1438,   735,  -159,
   -1438, -1438, -1438, -1438, -1438,   285,   505, -1438, -1438,   -11,
    -199,  1049, -1438,  1030, -1438, -1438,  -646, -1438,   440, -1438,
     244, -1438,  -229,  -275, -1438,  -577, -1438,     5,    64,   114,
    -263,  -179, -1438,  -887, -1438, -1438,   300, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438,   613, -1438,  -111,
    1703,     0, -1438, -1438, -1438, -1438,   453, -1438, -1438,  -307,
   -1438,    23, -1438,  1034,  -938,  -736,  -726, -1438, -1438,   696,
   -1438, -1438,    10,   230, -1438, -1438, -1438,   106, -1108, -1438,
     368,   116, -1438, -1438,   120, -1319, -1438,   947,   216, -1438,
   -1438,   212, -1047, -1438, -1438,   211, -1438, -1438, -1257, -1271,
   -1438,   207, -1431, -1438, -1438,   851,   855, -1438,  -534,   837,
   -1438, -1438,  -665,   386,  -644,   382,   383, -1438, -1438, -1438,
     577, -1438, -1438,  1192, -1438, -1438, -1438, -1438, -1438,  -893,
    -326,  -680, -1438,  -117, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438,   -14,  -832, -1438,  -552,   668,   286, -1438,  -412, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438,   803, -1438, -1438, -1438,
   -1438, -1045, -1438,   197, -1438,   682,  -817, -1438, -1438, -1438,
   -1438, -1438,  -265,  -258, -1244,  -929, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438,  -768,  -877,  -157,
    -845, -1438, -1438, -1438,  -827, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438,  1077,  1081,  -399,   503,   331, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438, -1438,
     174, -1438, -1438,   166, -1438,   165, -1074, -1438, -1438, -1438,
     130,   121,   -48,   393, -1438, -1438, -1438, -1438, -1438, -1438,
   -1438, -1438, -1438, -1438, -1438, -1438, -1438,   133, -1438, -1438,
   -1438,   -43,   390,   531, -1438, -1438, -1438, -1438, -1438,   325,
   -1438, -1438, -1437, -1438, -1438, -1438,  -525, -1438,    98, -1438,
     -57, -1438, -1438, -1438, -1438, -1320, -1438,   146, -1438, -1438,
   -1438, -1438, -1438,   948, -1438, -1438, -1438, -1438, -1438,  -930,
    -404,   953,   385, -1438
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   258,   637,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
    1275,   787,   276,   277,   278,   279,   280,   281,   966,   967,
     968,   282,   283,   284,   972,   973,   974,   285,   449,   286,
     287,   715,   288,   451,   452,   453,   468,   777,   778,   289,
    1226,   290,  1704,  1705,   291,   292,   293,   560,   294,   295,
     296,   297,   298,   780,   299,   300,   542,   301,   302,   303,
     304,   305,   306,   647,   307,   308,   872,   873,   309,   310,
     311,   572,   313,   648,   466,  1033,  1034,   314,   649,   315,
     651,   573,   317,   767,   768,  1263,   475,   318,   476,   477,
     774,  1264,  1265,  1266,   652,   653,  1133,  1134,  1383,   654,
    1129,  1130,  1376,  1377,  1378,  1379,   319,   800,   801,   320,
    1290,  1291,  1496,   321,  1293,  1294,   322,   323,  1296,  1297,
    1298,  1299,  1503,   324,   325,   326,   327,   913,   328,   329,
    1390,   330,   331,   332,   333,   334,   335,   336,   337,   338,
    1170,   339,   340,   341,   342,   672,   673,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   707,   702,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   943,   370,   371,   372,
     373,   374,   375,  1326,   833,   834,   835,  1736,  1781,  1782,
    1775,  1776,  1783,  1777,  1327,  1328,   376,   377,  1329,   378,
     379,   380,   381,   382,   383,   384,   385,  1028,  1504,  1431,
    1160,  1588,  1161,  1171,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   807,  1239,   398,  1163,
    1164,  1165,  1166,   399,   400,   401,   402,   403,   404,   862,
     863,   405,  1360,  1361,  1671,  1115,  1141,  1400,  1401,  1142,
    1143,  1144,  1145,  1146,  1410,  1578,  1579,  1147,  1413,  1148,
    1559,  1149,  1150,  1418,  1419,  1584,  1582,  1402,  1403,  1404,
    1405,  1684,   744,   993,   994,   995,   996,   997,   998,  1212,
    1608,  1701,  1213,  1606,  1699,   999,  1444,  1603,  1599,  1600,
    1601,  1000,  1001,  1406,  1414,  1569,  1407,  1565,  1391,   406,
     407,   408,   409,   563,   410,   411,   412,   413,   414,  1167,
    1276,   415,   416,   417
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -867;
  const short int
  xquery_parser::yytable_[] =
  {
       312,   571,   575,   450,   609,   312,   312,   312,   312,   650,
     422,   425,   426,   921,   934,  1292,  1084,   716,   716,   696,
     587,  1048,   624,   316,  1139,  1507,  1280,   719,   316,   316,
     316,   316,   632,  1026,  1060,   922,   923,   924,   925,  1114,
     627,  1325,   851,  1027,   891,   893,   625,   858,  1074,   885,
     889,   892,   894,  1159,  1169,   629,  1518,   625,  1549,  1550,
     616,   617,   538,  1386,    11,    12,  1185,   784,   788,   423,
     423,   423,   427,  1228,  1644,   883,   887,  1648,  1030,  1252,
     953,   625,  1526,  1244,   435,  1215,   625,   631,  1022,  1282,
    1216,   758,  1580,   625,  1497,   625,   625,  1249,   625,  1217,
     625,   838,   718,  1162,  1162,   625,  1218,  1471,  1219,   759,
     822,   312,   438,   700,   625,   706,   821,  1220,  1707,   424,
     424,   424,   428,   909,  1189,   910,   911,   948,   912,   634,
     914,   775,  1441,   625,   316,   625,   611,   613,   915,   916,
    1024,   598,  1162,   625,  1221,  1090,  1246,  1023,   625,  1024,
     750,   494,   429,   636,   470,   625,   621,  1085,   724,  1269,
     592,   632,   593,   471,   636,   632,   589,    11,    12,   473,
    1702,   430,   622,  1561,   725,   423,  1227,   431,   432,  1498,
     433,   434,   495,    13,   633,   496,   625,   435,    11,    12,
     472,  1253,  1443,   636,   758,  1535,  1162,   436,   437,   776,
    1025,   454,  1566,  1091,   625,   625,   949,  1192,   435,  1162,
    1562,   635,   759,   431,   432,   438,   433,   434,   436,   474,
     439,   636,   474,  1086,  1708,   561,  1107,  1100,   625,  1672,
     599,   697,   474,   783,   437,  1101,   438,  -169,   625,  1031,
     636,   439,   636,   625,  1139,  1139,  1500,  1507,   625,   594,
     636,   631,   440,   441,   442,   636,   312,   312,  1734,  1487,
     312,  1257,   636,   625,    82,  1315,   650,  1268,   839,  1016,
     626,  1222,  1325,   440,   441,  1124,  1032,  1526,    93,   316,
     316,  1325,   628,   316,   878,   880,  1700,  1121,   625,  1123,
    1367,  1768,  1254,   636,  1366,   312,   891,   893,   632,  1436,
    1250,   443,  1255,   107,  1228,  1462,  1709,  1136,  1422,  1186,
    1137,   636,   636,   633,  1558,   625,   474,   633,   316,   831,
    1795,  1040,  1283,   474,   751,   474,  1162,   883,   887,  1062,
     128,  1057,   752,   979,  1063,   636,   760,   443,  1804,   703,
    1807,  1111,   705,  1318,  1319,   636,   488,  1735,   763,   590,
     636,  -170,   625,  1108,  1497,   636,   874,  1497,   781,    13,
     444,  1567,  1568,  1223,  1224,  1225,   625,  1677,   794,   875,
     636,  1373,  1311,   600,   625,   805,   806,  1428,   601,  1135,
    1024,   458,   904,  1045,   812,   884,   888,  1759,    11,    12,
    1312,  1313,  1375,   625,  1482,   636,   444,  1362,  1024,   879,
     881,   445,  1057,  1645,   595,  1597,   596,  1227,  1429,   896,
     483,  1058,  1138,  1023,  1742,  1318,  1319,   625,   822,   877,
     457,  -169,   636,   489,   312,  1373,  1430,   446,   312,  1743,
    1392,  1463,   718,   625,  1744,   447,  1733,   445,  1320,  1634,
      82,  1797,  1639,   448,  1162,  1678,  1052,   316,   446,  1617,
     633,   316,   625,  1363,    93,   312,   447,   312,  1321,   636,
    1322,   539,   602,   625,   448,  1452,   836,   837,  1162,  1598,
    1646,   625,   829,   636,   630,   539,  1325,   841,   316,   107,
     316,   636,  1076,   948,   312,   467,  1392,  1789,  1323,   312,
     490,   491,   114,   597,   823,  1139,   868,   870,  1068,   539,
     636,  1316,  1393,  1646,  1139,  1140,   469,   316,   126,  1464,
    1320,   539,   316,   539,   478,  1139,   785,  1017,  1507,   755,
     982,   757,   983,  1019,   636,  1037,  1023,  1114,  1472,  1324,
    1321,  1544,  1322,  1069,  1670,  -170,  1179,   891,   893,   891,
     636,  1318,  1319,  1587,  1368,  1369,  1370,   153,   803,  1449,
    1175,  1071,   481,   809,  1348,  1176,  1092,  1087,  1393,   636,
    1323,   312,   950,   786,   114,  1746,   984,  1317,   312,   428,
     636,   428,  1193,  1194,  1318,  1319,  1088,  1197,   636,  1059,
     126,   936,   937,  1176,   316,  1394,  1395,  1691,  1396,   938,
    1363,   316,  1696,  1162,  1023,  1397,  1018,  1096,   428,  1641,
    1089,  1520,  1020,   428,  1038,  1398,   632,  1236,   312,  1719,
     450,   685,  1070,  1553,  1563,   312,  1113,  1399,  1238,   153,
    1241,  1564,   461,  1642,   462,   686,   312,   312,   312,   312,
    1072,   316,   423,  1125,  1177,  1556,  1320,  1118,   316,  1791,
     482,  1394,  1395,  1103,  1396,   312,  1790,  1256,  1209,   316,
     316,   316,   316,  1023,  1793,  1318,  1321,   676,  1322,   676,
    1122,  1398,  1178,  1023,   881,  1210,  1692,   886,   316,  1320,
    1304,  1697,  1305,  1399,   677,  1779,   677,   728,  1162,  1093,
    1094,  1162,   424,  1139,   486,   734,  1323,   735,   463,  1321,
     114,  1322,  1441,   464,  1095,   312,  1500,   678,   487,  1120,
     935,  1047,  1652,   700,   492,   706,   126,  1656,  1211,  1442,
     729,  1073,  1727,  1079,  1080,  1081,   985,   870,   316,  1323,
    1097,  1098,   869,   114,   493,  1140,  1140,  1525,   639,   986,
     540,   987,   640,  1618,  1573,  1099,  1642,   641,   539,   126,
     465,   539,   988,   989,   990,   153,   991,   737,   992,  1731,
     676,   676,  1443,  1023,   679,   886,   642,  1773,  1112,   423,
    1654,  1318,  1415,  1416,   734,  1725,   735,   677,   677,  1681,
    1321,   695,  1322,  1642,  1612,   969,  1682,   543,   153,   312,
    1803,  1780,   891,   680,  1039,  1417,  1683,  1119,   639,   639,
    1750,  1773,   640,   640,   128,  1318,   681,   641,   641,   736,
    1323,  1552,   316,   622,  1642,  1778,  1784,  1187,   738,   424,
     312,   312,  1752,   696,  1753,  1162,   642,   642,   970,  1187,
     726,   539,  1318,   971,   539,  1823,   737,    13,   539,  1388,
     682,   539,   539,   316,   316,  1824,  1737,   720,  1209,   539,
    1740,   541,  1779,   423,  1180,   539,   539,  1778,  1356,  1642,
     539,   721,   128,  1784,   643,  1210,  1259,   644,   539,  1642,
    1181,  1260,  1162,   556,  1162,   539,   539,   539,   539,   312,
    1485,  1289,   645,   539,  1066,  1067,  1321,  1794,  1322,   450,
    1259,   539,   577,  1681,  1494,  1260,  1774,   738,   896,  1182,
    1682,  1184,   316,   424,   881,  1162,   312,  1435,   646,  1024,
    1683,   544,  1679,  1680,  1261,  1183,  1323,   779,    82,  1332,
    1321,  1333,  1322,   779,   643,   643,  1676,   644,   644,   316,
    1810,  1786,    93,  1024,   428,   428,   539,  1162,   455,  1706,
     895,   456,   830,  1541,   897,   709,  1364,  1321,  1760,  1322,
    1323,   539,  1162,   722,  1162,  1262,   710,   107,  1813,  1289,
    1372,  1136,   539,  1505,  1137,   578,   683,   723,   646,   646,
    1508,  1373,  1499,   557,  1505,   684,  1506,  1323,  1505,  1545,
     748,  1374,  1203,  1509,   128,   749,  1140,  1651,  1554,   852,
    1205,  1816,  1375,  1204,   852,  1140,   657,   939,   539,  1230,
     939,  1206,   558,   939,   658,   659,  1140,   660,  1231,   970,
    1198,  1199,  1200,  1259,   971,   661,  1201,   579,  1260,   662,
    1483,   663,  1748,  1749,   459,   584,   664,   460,   479,   484,
     701,   480,   485,   704,   585,  1385,   740,   741,   742,   698,
     699,  1706,   665,   956,   957,   958,   959,   960,   961,   962,
     963,   964,   965,   555,   700,   586,   706,  1337,   588,  1338,
     591,   650,  1195,  1196,  1546,  1547,   666,   667,   668,   669,
     670,   671,   919,   920,   312,   926,   927,   576,   928,   929,
    1447,  1448,  1693,  1694,  -608,   603,   604,   605,  1706,   580,
     608,   583,  1630,   606,   607,  1792,   614,   316,   618,   638,
     656,   655,   674,   675,   687,   688,   689,   694,   690,   700,
     708,   718,   711,   712,   713,   714,   730,   732,   733,   450,
     747,  1357,   743,   770,   771,   955,   756,   773,   539,   779,
     782,   312,   312,   312,   790,   791,   792,   793,  1300,   804,
     810,   811,   539,   817,  1358,   456,   539,   539,   460,   819,
     480,   485,   496,   821,   316,   316,   316,   832,   824,   825,
    1834,   840,  1835,   826,   828,   842,   843,   865,   539,   860,
     539,   861,  1843,   866,  1140,   882,   900,   901,   539,   917,
     930,   539,   902,   903,   931,   539,   609,   871,   428,   932,
     933,   945,   951,   952,   954,   976,   977,   981,   944,   980,
    1003,  1002,  1004,  1006,  1012,  1008,  1011,  1013,  1014,  1015,
    1021,  1036,  1042,  1043,  1046,  1064,  1053,  1054,  1102,  1055,
    1056,  1061,  1065,  1105,   455,  1109,   459,   539,   479,   484,
     495,  1120,  1110,  1104,  1174,  1127,  1188,  1023,  1207,   971,
    1234,  1229,  1208,  1235,  1237,  1636,  1245,   312,  1106,  1117,
    1247,  1258,  1456,   775,  1251,  1271,  1273,  1274,  1277,  1278,
    1279,  1272,  1285,  1284,  1301,  1303,   539,  1288,  1289,  1308,
     316,  1295,  1302,  1307,  1310,  1314,  1331,  1349,  1382,  1330,
     736,  1359,  1380,   312,  1384,  1408,  1409,    13,   904,  1420,
    1421,  1412,  1423,  1432,   312,   539,  1424,  1425,  1426,  1490,
    1440,  1445,  1455,  1389,  1427,  1439,   316,  1457,  1458,  1467,
    1454,   423,  1450,   312,  1459,  1460,  1469,   316,  1512,  1481,
    1476,  1473,  1477,  1475,  1461,   539,   539,   539,   539,  1486,
    1489,  1505,  1519,   312,  1511,  1522,   316,  1529,  1513,  1528,
     312,  1514,  1533,  1530,  1517,  1451,  1531,  1532,  1537,  1538,
    1539,  1540,  1557,  1581,  1373,  1576,   316,  1560,   423,  1362,
    1577,   424,  1583,   316,   539,  1589,  1590,  1591,  1592,  1593,
    1594,  1595,  1357,  1596,  1717,  1534,  1602,   423,   539,  1609,
    1607,  1613,  1615,  1620,  1629,  1721,  1636,  1627,  1723,  1628,
    1632,  1674,  1687,  1689,  1650,  1358,  1732,  1523,  1605,   727,
    1633,  1638,   731,   539,  1527,  1570,   739,  1655,   424,   745,
     746,  1649,   539,  1611,   539,  1658,   539,   754,   539,  1690,
    1675,  1698,  1209,   766,   769,  1711,  1703,   424,   769,  1714,
    1716,   539,  1722,  1754,  1739,  1755,   789,  1667,  1668,  1669,
    1757,  1758,  1762,   797,   798,   799,   802,   428,  1767,  1763,
    1756,   808,  1769,  1710,   428,  1770,  1771,  1688,  1785,   815,
    1787,  1800,  1788,  1808,   539,  1809,   539,  1801,  1812,  1663,
    1815,  1820,  1825,  1836,  1833,  1839,   619,  1840,  1723,   620,
     623,   978,  1837,  1826,  1438,  1190,   869,  1270,  1453,   717,
     753,  1798,  1765,  1796,  1818,  1116,  1827,  1267,  1051,  1625,
    1555,   852,  1830,  1480,   816,  1371,  1551,  1548,   312,   772,
    1832,  1491,  1495,   818,  1501,  1510,   907,  1805,  1842,   802,
    1173,   908,   918,   947,  1521,  1083,   539,  1814,  1811,  1437,
     827,   316,  1242,  1536,  1542,  1483,  1543,  1571,  1686,  1575,
    1685,  1387,   693,  1214,  1574,   761,  1446,  1411,   539,   762,
    1821,  1357,  1604,  1695,  1572,   856,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   864,     0,     0,  1745,
       0,  1821,     0,     0,  1358,     0,     0,     0,     0,     0,
    1805,     0,     0,     0,     0,     0,  1751,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1357,   539,     0,
       0,     0,   539,     0,     0,     0,     0,     0,  1357,  1357,
       0,   312,     0,     0,     0,     0,     0,   539,     0,  1357,
    1358,     0,     0,     0,     0,     0,   539,     0,     0,     0,
       0,  1358,  1358,     0,   316,     0,     0,     0,     0,     0,
     539,     0,  1358,     0,     0,     0,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,   975,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1005,     0,     0,     0,  1009,  1010,     0,     0,     0,   539,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1029,     0,  1035,     0,
       0,  1357,     0,     0,   539,     0,  1041,     0,     0,  1044,
       0,     0,     0,  1049,   539,     0,     0,     0,   539,     0,
       0,     0,     0,     0,  1358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1082,     0,     0,  1357,     0,
       0,     0,     0,   316,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   312,     0,   539,     0,     0,     0,     0,
       0,  1358,     0,     0,   562,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1357,     0,   316,     0,     0,     0,
       0,     0,     0,  1357,     0,   539,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1358,     0,     0,
       0,     0,     0,  1126,     0,     0,  1358,     0,     0,     0,
       0,   539,   539,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1168,  1168,  1172,  1172,   539,     0,     0,
     539,     0,     0,   539,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   539,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1202,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1233,     0,     0,     0,     0,     0,     0,     0,     0,
    1240,     0,  1240,     0,   769,     0,  1168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   808,     0,   808,     0,     0,   539,   539,     0,
     539,     0,   539,     0,     0,     0,     0,     0,     0,   539,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   539,     0,   539,     0,     0,     0,
       0,     0,     0,     0,  1381,     0,     0,     0,     0,     0,
       0,     0,   539,     0,     0,   539,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1168,   539,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   539,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   539,
       0,     0,     0,     0,     0,     0,     0,   539,     0,     0,
       0,     0,   539,     0,   539,     0,   539,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   769,     0,     0,     0,
    1465,     0,     0,     0,     0,   539,     0,     0,     0,     0,
     539,     0,     0,     0,     0,  1479,     0,     0,     0,     0,
       0,     0,   539,     0,  1168,   539,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   802,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   562,     0,     0,     0,     0,     0,  1524,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   844,   845,     0,   853,   854,
     855,   857,   864,   859,     0,     0,     0,     0,     0,   867,
       0,     0,     0,     0,     0,     0,     0,   876,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   898,
     899,     0,     0,     0,     0,     0,     0,     0,   905,   906,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1610,     0,     0,     0,     0,     0,   942,
       0,     0,     0,   942,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1623,
    1624,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1007,     0,     0,  1640,     0,     0,  1168,     0,
       0,  1168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1653,     0,     0,     0,     0,  1657,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1050,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1075,     0,     0,     0,  1077,  1078,     0,     0,     0,     0,
       0,     0,     0,   905,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1168,  1726,     0,  1728,   899,
    1730,     0,     0,     0,     0,  1128,  1132,  1738,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1168,     0,  1168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1761,     0,     0,  1764,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1191,  1168,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1772,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1168,     0,  1232,
       0,     0,     0,     0,     0,  1799,     0,     0,     0,     0,
    1802,     0,  1168,     0,  1168,     0,     0,     0,  1248,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1281,     0,     0,  1819,     0,     0,     0,     0,     0,     0,
       0,  1286,  1287,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1828,     0,     0,  1306,     0,  1829,  1309,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1838,     0,     0,  1841,     0,     0,  1334,  1335,  1336,     0,
    1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,  1347,     0,
       0,  1350,  1351,     0,     0,     0,     0,     0,     0,     0,
    1365,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1128,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1434,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1466,     0,  1468,     0,  1470,     0,     0,  1474,
       0,     0,     0,     0,  1478,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1484,     0,     0,     0,
       0,     0,     0,     0,     0,  1488,     0,     0,     0,     0,
       0,  1492,  1493,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1515,     0,     0,  1516,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1128,     0,     0,     0,  1132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1614,     0,     0,     0,
    1616,     0,     0,     0,  1619,     0,  1621,     0,  1622,     0,
       0,     0,     0,     0,  1626,     0,     0,     0,     0,     0,
       0,     0,  1631,     0,     0,     0,     0,     0,     0,     0,
    1635,  1637,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1484,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1659,  1660,  1661,  1662,     0,  1664,  1665,     0,
    1666,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1673,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1712,     0,
    1713,     0,     0,  1715,     0,     0,     0,     0,     0,     0,
       0,  1718,     0,     0,     0,     0,  1720,  1637,     0,     0,
       0,     0,     0,     0,  1724,     0,     0,     0,     0,  1729,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1741,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1747,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1766,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1724,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1806,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1817,     0,     0,     0,     0,  1822,     0,     0,     0,
       0,  1806,  -165,   886,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     0,  1822,     0,     3,     0,
    1831,     0,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,     0,     0,    14,   419,     0,    16,    17,
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
     133,   134,   135,   136,   137,     0,   138,     0,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   421,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     0,   248,     0,   249,   250,   251,   252,
     253,   254,   255,  -165,   886,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,    13,     0,     0,   890,   419,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,   420,    30,    31,    32,    33,    34,     0,    35,
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
       0,   133,   134,   135,   136,   137,     0,   138,     0,   139,
       0,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,     0,     0,   151,   152,   153,     0,   421,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,     0,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   886,   248,     0,   249,   250,   251,
     252,   253,   254,   255,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,    13,     0,     0,   418,   419,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,   420,    30,    31,    32,    33,    34,     0,    35,
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
       0,   133,   134,   135,   136,   137,     0,   138,     0,   139,
       0,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,     0,     0,   151,   152,   153,     0,   421,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,     0,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   886,   248,     0,   249,   250,   251,
     252,   253,   254,   255,     1,     2,     0,     0,     0,     3,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,    13,     0,     0,   418,   419,     0,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   564,   420,    30,    31,    32,    33,    34,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     0,    48,    49,    50,   565,   566,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,    77,    78,    79,     0,     0,    80,
      81,     0,     0,     0,    82,    83,   514,    85,    86,    87,
      88,    89,   567,    91,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   568,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
       0,   133,   134,     0,   136,   137,     0,   138,     0,   139,
       0,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,     0,     0,   151,   152,   153,     0,   421,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   532,   533,   534,   180,   181,   535,   570,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,     0,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,     0,   248,     0,   249,   250,   251,
     252,   253,   254,   255,  -866,   461,     0,   462,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -866,     0,     0,     0,
    -866,     0,     0,     0,  -866,  -866,     0,     0,     0,     0,
    -866,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   463,     0,     0,  -866,     0,   464,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -866,     0,  -866,
    -866,  -866,     0,     0,  -866,  -866,  -866,  -866,     0,     0,
       0,  -866,  -866,     0,     0,     0,     0,     0,  -866,     0,
       0,  -866,  -866,   465,     0,     0,  -866,     0,     0,     0,
       0,  -866,  -866,     0,     0,     0,     0,  -866,     0,     0,
       0,  -866,     0,     0,     0,  -866,  -866,     0,  -866,     0,
    -866,  -866,     0,     0,     0,  -866,  -866,     0,     0,  -866,
    -866,  -866,  -866,  -866,  -866,     0,     0,  -866,     0,     0,
       0,  -866,  -866,     0,     0,  -866,     0,     0,     0,     0,
    -866,     0,     0,  -866,     0,     0,     0,     0,  -866,  -866,
    -866,  -866,  -866,     0,  -866,  -866,  -866,  -866,  -866,     0,
       0,     0,     0,  -866,  -866,  -866,     0,  -866,  -866,  -866,
    -866,  -866,  -866,     0,  -866,     0,  -866,     0,     0,     0,
       0,  -866,  -866,  -866,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -866,     0,  -866,
       0,  -866,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -866,     0,     0,     0,     0,  -866,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     0,
       0,     0,     3,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,  -866,    13,  -866,     0,    14,
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
       0,     0,   132,     0,   133,   134,   135,   136,   137,     0,
     138,     0,   139,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,     0,     0,   151,   152,   153,
       0,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,     0,   248,     0,
     249,   250,   251,   252,   253,   254,   255,   256,   257,     1,
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
     131,     0,     0,     0,   132,     0,   133,   134,   135,   136,
     137,     0,   138,     0,   139,     0,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,     0,     0,   151,
     152,   153,     0,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,     0,
     248,     0,   249,   250,   251,   252,   253,   254,   255,     0,
     615,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   420,
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
     129,   130,   131,     0,   559,     0,   132,     0,   133,   134,
     135,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   420,
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
     129,   130,   131,     0,   820,     0,   132,     0,   133,   134,
     135,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,  1352,   420,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,  1353,  1354,    53,    54,    55,    56,    57,
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
     129,   130,   131,     0,   559,     0,   132,     0,   133,   134,
     135,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,  1355,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   420,
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
     135,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
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
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
     135,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
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
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
     135,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,    14,   419,     0,    16,    17,    18,    19,
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
     135,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,   890,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   420,
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
     135,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,  1352,   420,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,  1353,  1354,    53,    54,    55,    56,    57,
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
     135,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,  1355,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   564,   420,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   565,   566,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   514,    85,    86,    87,    88,    89,   567,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,   940,     0,   104,   105,   106,
     107,   108,   109,   110,   568,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,   941,   133,   134,
       0,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   532,   533,
     534,   180,   181,   535,   570,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   564,   420,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   565,   566,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   514,    85,    86,    87,    88,    89,   567,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,   940,     0,   104,   105,   106,
     107,   108,   109,   110,   568,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,   946,   133,   134,
       0,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   532,   533,
     534,   180,   181,   535,   570,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   564,   420,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   565,   566,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   514,    85,    86,    87,    88,    89,   567,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   568,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,   569,   132,     0,   133,   134,
       0,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   532,   533,
     534,   180,   181,   535,   570,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   564,   420,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   565,   566,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   514,    85,    86,    87,    88,    89,   567,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   568,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,   574,   133,   134,
       0,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   532,   533,
     534,   180,   181,   535,   570,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   564,   420,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   565,   566,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   514,    85,    86,    87,    88,    89,   567,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   568,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
       0,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   532,   533,
     534,   180,   181,   535,   570,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   610,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   564,   420,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   565,   566,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   514,    85,    86,    87,    88,    89,   567,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   568,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
       0,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   532,   533,
     534,   180,   181,   535,   570,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,   612,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   564,   420,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   565,   566,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   514,    85,    86,    87,    88,    89,   567,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,  1433,     0,   104,   105,   106,
     107,   108,   109,   110,   568,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
       0,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   532,   533,
     534,   180,   181,   535,   570,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   500,    27,   502,   420,
      30,   503,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,   505,     0,
      48,    49,    50,   507,   508,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   514,    85,    86,    87,    88,    89,   567,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   517,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   568,   112,     0,   113,   114,   691,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   692,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
       0,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   527,   164,   528,   166,   529,   530,
     169,   170,   171,   172,   173,   174,   531,   176,   532,   533,
     534,   180,   181,   535,   536,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   537,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   564,   420,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   565,   566,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   514,    85,    86,    87,    88,    89,   567,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   568,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
       0,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   532,   533,
     534,   180,   181,   535,   570,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   500,    27,   502,   420,
      30,   503,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,   505,     0,
      48,    49,    50,   507,   508,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   514,    85,    86,    87,    88,    89,   567,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   517,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   568,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
       0,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   527,   164,   528,   166,   529,   530,
     169,   170,   171,   172,   173,   174,   531,   176,   532,   533,
     534,   180,   181,   535,   536,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   537,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   564,   420,
      30,    31,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,     0,
      48,    49,    50,   565,   566,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   514,    85,    86,    87,    88,    89,  1131,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,    99,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   568,   112,     0,   113,   114,   115,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,   127,   128,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
       0,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   532,   533,
     534,   180,   181,   535,   570,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   500,    27,   502,   420,
      30,   503,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,   505,     0,
      48,    49,    50,   507,   508,    53,   509,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   514,    85,    86,    87,    88,    89,   567,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   517,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   568,   112,     0,   113,   114,     0,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,     0,     0,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
       0,   136,   137,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   527,   164,   528,   166,   529,   530,
     169,   170,   171,   172,   173,   174,   531,   176,   532,   533,
     534,   180,   181,   535,   536,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   537,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   500,    27,   502,   420,
      30,   503,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,   505,     0,
      48,    49,    50,   507,   508,    53,   509,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   514,    85,    86,    87,    88,    89,   567,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   517,   100,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,   108,   109,   110,   568,   112,     0,   113,   114,     0,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,     0,     0,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
       0,     0,     0,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   527,   164,   528,   166,   529,   530,
     169,   170,   171,   172,   173,   174,   531,   176,   532,   533,
     534,   180,   181,   535,   536,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   537,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
      13,     0,     0,   418,   419,     0,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   500,    27,   502,   420,
      30,   503,    32,    33,    34,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,   505,     0,
      48,    49,    50,   507,   508,    53,   509,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,    72,    73,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,     0,     0,
       0,    82,    83,   514,    85,    86,    87,    88,    89,   567,
      91,    92,     0,     0,     0,    93,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   517,     0,   101,   102,
     103,     0,     0,     0,     0,     0,     0,   104,   105,   106,
     107,     0,   109,   110,   568,   112,     0,   113,   114,     0,
     116,   117,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,   125,     0,   126,     0,     0,     0,     0,     0,
     129,   130,   131,     0,     0,     0,   132,     0,   133,   134,
       0,     0,     0,     0,   138,     0,   139,     0,   140,     0,
     142,     0,   144,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,   153,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   527,   164,   528,   166,   529,   530,
     169,   170,   171,   172,   173,   174,   531,   176,   532,   533,
     534,   180,   181,   535,   536,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,     0,   248,     0,   249,   537,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     0,     0,     0,     0,     9,    10,     0,     0,     0,
       0,     0,     0,   418,   419,     0,    16,    17,    18,   497,
      20,    21,    22,   498,    24,   499,   500,   501,   502,   420,
      30,   503,    32,    33,    34,     0,    35,    36,    37,    38,
     504,    40,    41,    42,    43,    44,    45,    46,   505,     0,
      48,   506,    50,   507,   508,    53,   509,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   510,   511,    71,     0,    72,    73,    74,   512,     0,
       0,    77,    78,    79,     0,     0,   513,    81,     0,     0,
       0,     0,    83,   514,    85,   515,   516,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   517,   100,   101,   518,
     519,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
     116,   520,     0,     0,     0,   118,   119,   120,   121,   521,
     123,   124,   522,     0,     0,     0,     0,     0,     0,     0,
     523,   524,   131,     0,     0,     0,   132,     0,   133,   525,
       0,     0,     0,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   526,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,     0,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   527,   164,   528,   166,   529,   530,
     169,   170,   171,   172,   173,   174,   531,   176,   532,   533,
     534,   180,   181,   535,   536,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,     0,     0,     0,   249,   537,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     0,     0,     0,     0,     9,    10,     0,     0,     0,
       0,     0,     0,   418,   419,     0,    16,    17,    18,   545,
      20,    21,    22,   498,   546,   547,   500,   501,   502,   420,
      30,   503,    32,   548,    34,     0,    35,    36,    37,    38,
     549,    40,   550,   551,    43,    44,    45,    46,   505,     0,
      48,   552,    50,   507,   508,    53,   509,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   510,   511,    71,     0,    72,    73,    74,   553,     0,
       0,    77,    78,    79,     0,     0,   513,    81,     0,     0,
       0,     0,    83,   514,    85,   515,   516,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   517,   100,   101,   518,
     519,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
     116,   520,     0,     0,     0,   118,   119,   120,   121,   521,
     123,   124,   522,     0,     0,     0,     0,     0,     0,     0,
     523,   524,   131,     0,     0,     0,   132,     0,   133,   525,
       0,     0,     0,     0,   138,     0,   139,     0,   140,   141,
     142,   143,   526,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,     0,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   527,   554,   528,   166,   529,   530,
     169,   170,   171,   172,   173,   174,   531,   176,   532,   533,
     534,   180,   181,   535,   536,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,     0,     3,     0,   249,   537,   251,   252,   253,   254,
     255,     9,    10,     0,     0,     0,     0,     0,     0,   418,
     419,     0,    16,    17,    18,   497,    20,    21,    22,   498,
      24,   499,   500,  1151,   502,   420,    30,   503,    32,    33,
      34,     0,    35,    36,    37,    38,   504,    40,    41,    42,
      43,    44,    45,    46,   505,     0,    48,   506,    50,   507,
     508,    53,   509,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   510,   511,    71,
       0,    72,    73,    74,   512,     0,     0,    77,    78,    79,
       0,     0,   513,    81,     0,     0,     0,     0,    83,   514,
      85,   515,   516,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   517,   100,   101,   518,   519,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,  1152,
       0,     0,     0,  1153,     0,     0,   116,   520,     0,     0,
       0,   118,   119,   120,   121,   521,   123,   124,   522,     0,
       0,     0,     0,     0,     0,     0,   523,   524,   131,     0,
       0,     0,   132,  1585,   133,   525,     0,     0,     0,     0,
    1586,     0,   139,     0,   140,   141,   142,   143,   526,   145,
     146,   147,   148,   149,   150,     0,     0,  1154,   152,     0,
       0,   421,   155,   156,   157,   158,   159,   160,   161,   162,
     527,   164,   528,   166,   529,   530,   169,   170,   171,   172,
     173,   174,   531,   176,   532,   533,   534,   180,   181,   535,
     536,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     0,     0,
     249,   537,   251,  1155,  1156,  1157,  1158,     3,     0,   581,
     582,     0,     0,     0,     0,     0,     9,    10,     0,     0,
       0,     0,     0,     0,   418,   419,     0,    16,    17,    18,
     545,    20,    21,    22,   498,   546,   547,   500,   501,   502,
     420,    30,   503,    32,   548,    34,     0,    35,    36,    37,
      38,   549,    40,   550,   551,    43,    44,    45,    46,   505,
       0,    48,   552,    50,   507,   508,    53,   509,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   510,   511,    71,     0,    72,    73,    74,   553,
       0,     0,    77,    78,    79,     0,     0,   513,    81,     0,
       0,     0,     0,    83,   514,    85,   515,   516,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   517,   100,   101,
     518,   519,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,   110,     0,     0,     0,     0,     0,
       0,   116,   520,     0,     0,     0,   118,   119,   120,   121,
     521,   123,   124,   522,     0,     0,     0,     0,     0,     0,
       0,   523,   524,   131,     0,     0,     0,   132,     0,   133,
     525,     0,     0,     0,     0,     0,     0,   139,     0,   140,
     141,   142,   143,   526,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,     0,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   527,   554,   528,   166,   529,
     530,   169,   170,   171,   172,   173,   174,   531,   176,   532,
     533,   534,   180,   181,   535,   536,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,     0,     0,     3,     0,   249,   537,   251,   252,   253,
     254,   255,     9,    10,     0,     0,     0,     0,     0,     0,
     418,   419,     0,    16,    17,    18,   545,    20,    21,    22,
     498,   546,   547,   500,   501,   502,   420,    30,   503,    32,
     548,    34,     0,    35,    36,    37,    38,   549,    40,   550,
     551,    43,    44,    45,    46,   505,     0,    48,   552,    50,
     507,   508,    53,   509,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   510,   511,
      71,     0,    72,    73,    74,   553,     0,     0,    77,    78,
      79,     0,     0,   513,    81,     0,     0,     0,     0,    83,
     514,    85,   515,   516,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   517,   100,   101,   518,   519,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
     110,     0,     0,     0,     0,     0,     0,   116,   520,     0,
       0,     0,   118,   119,   120,   121,   521,   123,   124,   522,
       0,     0,     0,     0,     0,     0,     0,   523,   524,   131,
       0,     0,     0,   132,   764,   133,   525,     0,     0,     0,
       0,   765,     0,   139,     0,   140,   141,   142,   143,   526,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
       0,     0,   421,   155,   156,   157,   158,   159,   160,   161,
     162,   527,   554,   528,   166,   529,   530,   169,   170,   171,
     172,   173,   174,   531,   176,   532,   533,   534,   180,   181,
     535,   536,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,     0,     3,
       0,   249,   537,   251,   252,   253,   254,   255,     9,    10,
       0,     0,     0,   795,     0,     0,   418,   419,     0,    16,
      17,    18,   545,    20,    21,    22,   498,   546,   547,   500,
     501,   502,   420,    30,   503,    32,   548,    34,     0,    35,
      36,    37,    38,   549,    40,   550,   551,    43,    44,    45,
      46,   505,     0,    48,   552,    50,   507,   508,    53,   509,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   510,   511,    71,     0,    72,    73,
      74,   553,     0,     0,    77,    78,    79,     0,     0,   513,
      81,     0,     0,     0,     0,    83,   514,    85,   515,   516,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   517,
     100,   101,   518,   519,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,   110,     0,     0,     0,
       0,     0,     0,   116,   520,     0,     0,     0,   118,   119,
     120,   121,   521,   123,   124,   522,     0,     0,     0,     0,
       0,     0,     0,   523,   524,   131,     0,     0,     0,   132,
     796,   133,   525,     0,     0,     0,     0,     0,     0,   139,
       0,   140,   141,   142,   143,   526,   145,   146,   147,   148,
     149,   150,     0,     0,   151,   152,     0,     0,   421,   155,
     156,   157,   158,   159,   160,   161,   162,   527,   554,   528,
     166,   529,   530,   169,   170,   171,   172,   173,   174,   531,
     176,   532,   533,   534,   180,   181,   535,   536,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,     0,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,     0,     0,     3,     0,   249,   537,   251,
     252,   253,   254,   255,     9,    10,     0,     0,     0,     0,
       0,     0,   418,   419,     0,    16,    17,    18,   545,    20,
      21,    22,   498,   546,   547,   500,   501,   502,   420,    30,
     503,    32,   548,    34,     0,    35,    36,    37,    38,   549,
      40,   550,   551,    43,    44,    45,    46,   505,     0,    48,
     552,    50,   507,   508,    53,   509,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     510,   511,    71,     0,    72,    73,    74,   553,     0,     0,
      77,    78,    79,     0,     0,   513,    81,     0,     0,     0,
       0,    83,   514,    85,   515,   516,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   517,   100,   101,   518,   519,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,   110,     0,     0,     0,     0,     0,     0,   116,
     520,     0,     0,     0,   118,   119,   120,   121,   521,   123,
     124,   522,     0,     0,     0,     0,     0,     0,     0,   523,
     524,   131,     0,     0,     0,   132,   813,   133,   525,     0,
       0,     0,     0,   814,     0,   139,     0,   140,   141,   142,
     143,   526,   145,   146,   147,   148,   149,   150,     0,     0,
     151,   152,     0,     0,   421,   155,   156,   157,   158,   159,
     160,   161,   162,   527,   554,   528,   166,   529,   530,   169,
     170,   171,   172,   173,   174,   531,   176,   532,   533,   534,
     180,   181,   535,   536,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,     0,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
       0,     3,     0,   249,   537,   251,   252,   253,   254,   255,
       9,    10,     0,     0,     0,     0,     0,     0,   418,   419,
       0,    16,    17,    18,   497,    20,    21,    22,   498,    24,
     499,   500,  1151,   502,   420,    30,   503,    32,    33,    34,
       0,    35,    36,    37,    38,   504,    40,    41,    42,    43,
      44,    45,    46,   505,     0,    48,   506,    50,   507,   508,
      53,   509,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   510,   511,    71,     0,
      72,    73,    74,   512,     0,     0,    77,    78,    79,     0,
       0,   513,    81,     0,     0,     0,     0,    83,   514,    85,
     515,   516,    88,    89,  1502,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   517,   100,   101,   518,   519,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,  1152,     0,
       0,     0,  1153,     0,     0,   116,   520,     0,     0,     0,
     118,   119,   120,   121,   521,   123,   124,   522,     0,     0,
       0,     0,     0,     0,     0,   523,   524,   131,     0,     0,
       0,   132,     0,   133,   525,     0,     0,     0,     0,     0,
       0,   139,     0,   140,   141,   142,   143,   526,   145,   146,
     147,   148,   149,   150,     0,     0,  1154,   152,     0,     0,
     421,   155,   156,   157,   158,   159,   160,   161,   162,   527,
     164,   528,   166,   529,   530,   169,   170,   171,   172,   173,
     174,   531,   176,   532,   533,   534,   180,   181,   535,   536,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,     0,     0,     3,     0,   249,
     537,   251,  1155,  1156,  1157,  1158,     9,    10,     0,     0,
       0,     0,     0,     0,   418,   419,     0,    16,    17,    18,
     497,    20,    21,    22,   498,    24,   499,   500,  1151,   502,
     420,    30,   503,    32,    33,    34,     0,    35,    36,    37,
      38,   504,    40,    41,    42,    43,    44,    45,    46,   505,
       0,    48,   506,    50,   507,   508,    53,   509,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   510,   511,    71,     0,    72,    73,    74,   512,
       0,     0,    77,    78,    79,     0,     0,   513,    81,     0,
       0,     0,     0,    83,   514,    85,   515,   516,    88,    89,
    1643,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   517,   100,   101,
     518,   519,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,  1152,     0,     0,     0,  1153,     0,
       0,   116,   520,     0,     0,     0,   118,   119,   120,   121,
     521,   123,   124,   522,     0,     0,     0,     0,     0,     0,
       0,   523,   524,   131,     0,     0,     0,   132,     0,   133,
     525,     0,     0,     0,     0,     0,     0,   139,     0,   140,
     141,   142,   143,   526,   145,   146,   147,   148,   149,   150,
       0,     0,  1154,   152,     0,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   527,   164,   528,   166,   529,
     530,   169,   170,   171,   172,   173,   174,   531,   176,   532,
     533,   534,   180,   181,   535,   536,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,     0,     0,     3,     0,   249,   537,   251,  1155,  1156,
    1157,  1158,     9,    10,     0,     0,     0,     0,     0,     0,
     418,   419,     0,    16,    17,    18,   497,    20,    21,    22,
     498,    24,   499,   500,  1151,   502,   420,    30,   503,    32,
      33,    34,     0,    35,    36,    37,    38,   504,    40,    41,
      42,    43,    44,    45,    46,   505,     0,    48,   506,    50,
     507,   508,    53,   509,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   510,   511,
      71,     0,    72,    73,    74,   512,     0,     0,    77,    78,
      79,     0,     0,   513,    81,     0,     0,     0,     0,    83,
     514,    85,   515,   516,    88,    89,  1647,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   517,   100,   101,   518,   519,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
    1152,     0,     0,     0,  1153,     0,     0,   116,   520,     0,
       0,     0,   118,   119,   120,   121,   521,   123,   124,   522,
       0,     0,     0,     0,     0,     0,     0,   523,   524,   131,
       0,     0,     0,   132,     0,   133,   525,     0,     0,     0,
       0,     0,     0,   139,     0,   140,   141,   142,   143,   526,
     145,   146,   147,   148,   149,   150,     0,     0,  1154,   152,
       0,     0,   421,   155,   156,   157,   158,   159,   160,   161,
     162,   527,   164,   528,   166,   529,   530,   169,   170,   171,
     172,   173,   174,   531,   176,   532,   533,   534,   180,   181,
     535,   536,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,     0,     0,     3,
       0,   249,   537,   251,  1155,  1156,  1157,  1158,     9,    10,
       0,     0,     0,     0,     0,     0,   418,   419,     0,    16,
      17,    18,   497,    20,    21,    22,   498,    24,   499,   500,
    1151,   502,   420,    30,   503,    32,    33,    34,     0,    35,
      36,    37,    38,   504,    40,    41,    42,    43,    44,    45,
      46,   505,     0,    48,   506,    50,   507,   508,    53,   509,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   510,   511,    71,     0,    72,    73,
      74,   512,     0,     0,    77,    78,    79,     0,     0,   513,
      81,     0,     0,     0,     0,    83,   514,    85,   515,   516,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   517,
     100,   101,   518,   519,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,  1152,     0,     0,     0,
    1153,     0,     0,   116,   520,     0,     0,     0,   118,   119,
     120,   121,   521,   123,   124,   522,     0,     0,     0,     0,
       0,     0,     0,   523,   524,   131,     0,     0,     0,   132,
       0,   133,   525,     0,     0,     0,     0,     0,     0,   139,
       0,   140,   141,   142,   143,   526,   145,   146,   147,   148,
     149,   150,     0,     0,  1154,   152,     0,     0,   421,   155,
     156,   157,   158,   159,   160,   161,   162,   527,   164,   528,
     166,   529,   530,   169,   170,   171,   172,   173,   174,   531,
     176,   532,   533,   534,   180,   181,   535,   536,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,     0,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,     0,     0,     3,     0,   249,   537,   251,
    1155,  1156,  1157,  1158,     9,    10,     0,     0,     0,     0,
       0,     0,   418,   419,     0,    16,    17,    18,   497,    20,
      21,    22,   498,    24,   499,   500,  1151,   502,   420,    30,
     503,    32,    33,    34,     0,    35,    36,    37,    38,   504,
      40,    41,    42,    43,    44,    45,    46,   505,     0,    48,
     506,    50,   507,   508,    53,   509,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     510,   511,    71,     0,    72,    73,    74,   512,     0,     0,
      77,    78,    79,     0,     0,   513,    81,     0,     0,     0,
       0,    83,   514,    85,   515,   516,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   517,   100,   101,   518,   519,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,  1152,     0,     0,     0,  1153,     0,     0,   116,
     520,     0,     0,     0,   118,   119,   120,   121,   521,   123,
     124,   522,     0,     0,     0,     0,     0,     0,     0,   523,
     524,   131,     0,     0,     0,   132,     0,   133,   525,     0,
       0,     0,     0,     0,     0,   139,     0,   140,   141,   142,
     143,   526,   145,   146,   147,   148,   149,   150,     0,     0,
     151,   152,     0,     0,   421,   155,   156,   157,   158,   159,
     160,   161,   162,   527,   164,   528,   166,   529,   530,   169,
     170,   171,   172,   173,   174,   531,   176,   532,   533,   534,
     180,   181,   535,   536,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,     0,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
       0,     3,     0,   249,   537,   251,  1155,  1156,  1157,  1158,
       9,    10,     0,     0,     0,     0,     0,     0,   418,   419,
       0,    16,    17,    18,   545,    20,    21,    22,   498,   546,
     547,   500,   501,   502,   420,    30,   503,    32,   548,    34,
       0,    35,    36,    37,    38,   549,    40,   550,   551,    43,
      44,    45,    46,   505,     0,    48,   552,    50,   507,   508,
      53,   509,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   510,   511,    71,     0,
      72,    73,    74,   553,     0,     0,    77,    78,    79,     0,
       0,   513,    81,     0,     0,     0,     0,    83,   514,    85,
     515,   516,    88,    89,  1243,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   517,   100,   101,   518,   519,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,   110,     0,
       0,     0,     0,     0,     0,   116,   520,     0,     0,     0,
     118,   119,   120,   121,   521,   123,   124,   522,     0,     0,
       0,     0,     0,     0,     0,   523,   524,   131,     0,     0,
       0,   132,     0,   133,   525,     0,     0,     0,     0,     0,
       0,   139,     0,   140,   141,   142,   143,   526,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,     0,     0,
     421,   155,   156,   157,   158,   159,   160,   161,   162,   527,
     554,   528,   166,   529,   530,   169,   170,   171,   172,   173,
     174,   531,   176,   532,   533,   534,   180,   181,   535,   536,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,     0,     0,     3,     0,   249,
     537,   251,   252,   253,   254,   255,     9,    10,     0,     0,
       0,     0,     0,     0,   418,   419,     0,    16,    17,    18,
     545,    20,    21,    22,   498,   546,   547,   500,   501,   502,
     420,    30,   503,    32,   548,    34,     0,    35,    36,    37,
      38,   549,    40,   550,   551,    43,    44,    45,    46,   505,
       0,    48,   552,    50,   507,   508,    53,   509,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   510,   511,    71,     0,    72,    73,    74,   553,
       0,     0,    77,    78,    79,     0,     0,   513,    81,     0,
       0,     0,     0,    83,   514,    85,   515,   516,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   517,   100,   101,
     518,   519,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,   110,     0,     0,     0,     0,     0,
       0,   116,   520,     0,     0,     0,   118,   119,   120,   121,
     521,   123,   124,   522,     0,     0,     0,     0,     0,     0,
       0,   523,   524,   131,     0,     0,     0,   132,     0,   133,
     525,     0,     0,     0,     0,     0,     0,   139,     0,   140,
     141,   142,   143,   526,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,     0,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   527,   554,   528,   166,   529,
     530,   169,   170,   171,   172,   173,   174,   531,   176,   532,
     533,   534,   180,   181,   535,   536,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,     0,     0,     0,     0,   249,   537,   251,   252,   253,
     254,   255,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
     846,    20,    21,    22,    23,     0,   847,   500,    27,     0,
     420,    30,   503,    32,     0,    34,     0,    35,    36,    37,
      38,   848,    40,     0,     0,    43,    44,    45,    46,   505,
       0,    48,   849,    50,     0,     0,    53,   509,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   510,   511,    71,     0,    72,    73,    74,   850,
       0,     0,    77,    78,    79,     0,     0,   513,    81,     0,
       0,     0,    82,    83,   514,    85,   515,   516,    88,    89,
     567,    91,     0,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   517,   100,   101,
     518,   519,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,     0,   568,   112,     0,   113,   114,
       0,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   522,     0,   126,     0,     0,     0,     0,
       0,   523,   524,   131,     0,     0,     0,   132,     0,   133,
     525,     0,     0,     0,     0,     0,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,     0,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   527,     0,   528,   166,   529,
     530,   169,   170,   171,   172,   173,   174,   531,   176,   532,
     533,   534,   180,   181,     0,   536,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     9,    10,   537,   251,     0,     0,
       0,     0,   418,   419,     0,    16,    17,    18,     0,    20,
      21,    22,   498,     0,     0,   500,   501,     0,   420,    30,
     503,    32,     0,    34,     0,    35,    36,    37,    38,     0,
      40,     0,     0,    43,    44,    45,    46,   505,     0,    48,
       0,    50,     0,     0,    53,   509,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     510,   511,    71,     0,    72,    73,    74,     0,     0,     0,
      77,    78,    79,     0,     0,   513,    81,     0,     0,     0,
       0,    83,   514,    85,   515,   516,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   517,   100,   101,   518,   519,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,     0,     0,     0,     0,     0,     0,     0,   116,
     520,     0,     0,     0,   118,   119,   120,   121,   521,   123,
     124,   522,     0,     0,     0,     0,     0,     0,     0,   523,
     524,   131,     0,     0,     0,   132,     0,   133,   525,     0,
       0,     0,     0,     0,     0,   139,     0,   140,   141,   142,
     143,   526,   145,   146,   147,   148,   149,   150,     0,     0,
       0,   152,     0,     0,   421,   155,   156,   157,   158,   159,
     160,   161,   162,   527,     0,   528,   166,   529,   530,   169,
     170,   171,   172,   173,   174,   531,   176,   532,   533,   534,
     180,   181,     0,   536,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,     0,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
       0,     0,     0,     0,   537,   251
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   112,   113,    14,   183,     5,     6,     7,     8,   316,
       5,     6,     7,   678,   694,  1062,   833,   429,   430,   345,
     137,   789,   263,     0,   917,  1296,  1046,   431,     5,     6,
       7,     8,   295,   769,   802,   679,   680,   681,   682,   871,
     264,  1086,   594,   769,   628,   629,     1,   599,   816,   626,
     627,   628,   629,   930,   931,   279,  1313,     1,  1377,  1378,
     256,   257,    76,  1137,    27,    28,   953,   471,   472,     5,
       6,     7,     8,  1003,  1505,   626,   627,  1508,    56,    36,
     726,     1,  1326,  1021,    47,    39,     1,   286,    36,   143,
      44,    45,  1412,     1,   101,     1,     1,   148,     1,    53,
       1,     8,    30,   930,   931,     1,    60,   148,    62,    63,
     108,   111,    75,   155,     1,   157,   122,    71,   119,     5,
       6,     7,     8,   657,   969,   659,   660,   108,   662,   108,
     664,   119,    97,     1,   111,     1,   247,   248,   672,   673,
      97,   225,   969,     1,    98,   132,  1023,    95,     1,    97,
     113,   123,   157,   108,    25,     1,    33,   131,   166,  1036,
     225,   424,   227,    34,   108,   428,    31,    27,    28,   119,
    1607,   157,    49,   217,   182,   111,  1003,    37,    38,   186,
      40,    41,   154,    30,   295,   157,     1,    47,    27,    28,
      61,   148,   157,   108,    45,   237,  1023,    57,    58,   187,
     148,   161,    97,   190,     1,     1,   187,   975,    47,  1036,
     254,   190,    63,    37,    38,    75,    40,    41,    57,   273,
      80,   108,   273,   197,   225,   111,   108,   233,     1,  1548,
     314,   348,   273,   161,    58,   233,    75,     0,     1,   217,
     108,    80,   108,     1,  1137,  1138,  1293,  1518,     1,   314,
     108,   450,   112,   113,   114,   108,   256,   257,    94,  1279,
     260,  1029,   108,     1,   111,  1082,   573,  1035,   175,   184,
     190,   225,  1317,   112,   113,   114,   254,  1521,   125,   256,
     257,  1326,   190,   260,   190,   190,  1606,   190,     1,   190,
     114,  1722,  1028,   108,   190,   295,   880,   881,   561,  1186,
    1026,   161,  1028,   150,  1234,  1243,   307,   154,  1153,   955,
     157,   108,   108,   424,  1388,     1,   273,   428,   295,   187,
    1757,   187,  1048,   273,   287,   273,  1153,   878,   879,   187,
     177,   108,   295,   737,   187,   108,   187,   161,  1769,   353,
    1771,   187,   356,     9,    10,   108,    77,   183,   459,   214,
     108,     0,     1,   235,   101,   108,   311,   101,   469,    30,
     220,   256,   257,   317,   318,   319,     1,    52,   479,   313,
     108,   107,   187,   225,     1,   486,   487,   145,   230,   913,
      97,   157,   645,   787,   495,   626,   627,  1706,    27,    28,
     187,   187,   128,     1,  1271,   108,   220,   154,    97,   623,
     624,   261,   108,   119,   225,   137,   227,  1234,   176,   633,
     119,   188,   259,    95,   187,     9,    10,     1,   108,   615,
     154,   184,   108,   154,   424,   107,   194,   287,   428,   187,
      97,   148,    30,     1,   187,   295,   119,   261,   104,   186,
     111,  1760,   186,   303,  1271,   130,   184,   424,   287,   148,
     561,   428,     1,   210,   125,   455,   295,   457,   124,   108,
     126,    76,   314,     1,   303,  1233,   577,   578,  1295,   201,
     186,     1,   185,   108,   113,    90,  1521,   588,   455,   150,
     457,   108,   188,   108,   484,   157,    97,  1744,   154,   489,
     221,   222,   158,   314,   184,  1388,   607,   608,   184,   114,
     108,   131,   169,   186,  1397,   917,   157,   484,   174,  1245,
     104,   126,   489,   128,   157,  1408,   114,   108,  1789,   455,
      55,   457,    57,   108,   108,   108,    95,  1359,  1254,   195,
     124,  1363,   126,   108,   154,   184,   948,  1121,  1122,  1123,
     108,     9,    10,  1420,  1121,  1122,  1123,   213,   484,  1229,
     185,   108,   157,   489,  1106,   108,    95,   184,   169,   108,
     154,   561,   187,   161,   158,  1673,   101,   197,   568,   455,
     108,   457,   976,   977,     9,    10,   184,   981,   108,   148,
     174,   698,   699,   108,   561,   252,   253,   108,   255,   700,
     210,   568,   108,  1420,    95,   262,   187,    95,   484,   186,
     184,   195,   187,   489,   187,   272,   869,  1011,   608,  1629,
     621,   137,   187,  1381,   268,   615,   184,   284,  1017,   213,
    1019,   275,     1,   210,     3,   151,   626,   627,   628,   629,
     187,   608,   568,   896,   187,   184,   104,   878,   615,  1747,
     157,   252,   253,    95,   255,   645,   184,   148,    97,   626,
     627,   628,   629,    95,   184,     9,   124,   159,   126,   159,
     884,   272,   187,    95,   888,   114,   187,     1,   645,   104,
    1069,   187,  1071,   284,   176,    29,   176,   169,  1505,   218,
     219,  1508,   568,  1576,   157,    45,   154,    47,    67,   124,
     158,   126,    97,    72,   233,   695,  1743,   199,   157,    33,
     695,   143,  1519,   155,   123,   157,   174,  1524,   157,   114,
     202,   143,   186,   824,   825,   826,   251,   828,   695,   154,
     218,   219,   608,   158,   123,  1137,  1138,   195,    42,   264,
     123,   266,    46,  1469,  1399,   233,   210,    51,   353,   174,
     119,   356,   277,   278,   279,   213,   281,   107,   283,   186,
     159,   159,   157,    95,   118,     1,    70,     5,   869,   695,
     195,     9,   247,   248,    45,  1642,    47,   176,   176,   269,
     124,   154,   126,   210,  1454,    95,   276,   123,   213,   779,
     186,   135,  1366,   147,   779,   270,   286,    33,    42,    42,
     199,     5,    46,    46,   177,     9,   160,    51,    51,    80,
     154,   143,   779,    49,   210,  1734,  1735,   966,   168,   695,
     810,   811,  1689,  1139,  1691,  1642,    70,    70,   138,   978,
     435,   436,     9,   143,   439,   186,   107,    30,   443,   154,
     194,   446,   447,   810,   811,   186,  1653,   182,    97,   454,
    1657,   119,    29,   779,   149,   460,   461,  1776,  1111,   210,
     465,   196,   177,  1782,   168,   114,    54,   171,   473,   210,
     165,    59,  1689,   119,  1691,   480,   481,   482,   483,   869,
    1274,   101,   186,   488,   810,   811,   124,  1754,   126,   890,
      54,   496,   154,   269,   114,    59,   134,   168,  1112,   149,
     276,   138,   869,   779,  1118,  1722,   896,   138,   212,    97,
     286,   123,  1567,  1568,    78,   165,   154,   154,   111,   232,
     124,   234,   126,   154,   168,   168,  1560,   171,   171,   896,
     134,  1738,   125,    97,   810,   811,   541,  1754,   154,  1609,
     630,   157,   186,   186,   634,   146,  1115,   124,  1706,   126,
     154,   556,  1769,   182,  1771,   119,   157,   150,   135,   101,
      96,   154,   567,   101,   157,   154,   201,   196,   212,   212,
     101,   107,   114,   123,   101,   210,   114,   154,   101,  1373,
     138,   117,   263,   114,   177,   143,  1388,   114,  1382,   594,
     263,   114,   128,   274,   599,  1397,   133,   701,   603,   299,
     704,   274,   123,   707,   141,   142,  1408,   144,   308,   138,
     277,   278,   279,    54,   143,   152,   283,   123,    59,   156,
    1273,   158,  1677,  1678,   154,   123,   163,   157,   154,   154,
     352,   157,   157,   355,   123,  1136,   221,   222,   223,   191,
     192,  1711,   179,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    90,   155,   123,   157,   232,   154,   234,
     216,  1358,   129,   130,   129,   130,   203,   204,   205,   206,
     207,   208,   676,   677,  1064,   683,   684,   114,   685,   686,
    1227,  1228,  1597,  1598,   157,   119,   241,   241,  1758,   126,
     154,   128,  1486,   242,   157,  1750,   314,  1064,     0,   190,
      93,   167,   249,   100,    50,   200,   102,   193,   103,   155,
     157,    30,   184,   184,   184,   184,    47,   153,   119,  1120,
     304,  1111,   246,   284,   284,   730,   187,   119,   733,   154,
       1,  1121,  1122,  1123,   119,   143,   108,   187,  1064,   187,
     154,   154,   747,   143,  1111,   157,   751,   752,   157,   184,
     157,   157,   157,   122,  1121,  1122,  1123,    35,   157,   157,
    1830,    17,  1832,   157,   154,   214,    30,   190,   773,   231,
     775,   230,  1842,   190,  1576,     3,   119,   168,   783,    71,
     231,   786,   170,   170,    95,   790,  1355,   245,  1064,    95,
      95,   150,   108,   108,    30,   161,   161,   133,   187,   128,
      95,   246,   299,   143,   184,   119,   133,   184,   187,   187,
     108,    95,    97,    45,    97,   154,   187,   187,    95,   187,
     187,   184,   184,   225,   154,   143,   154,   832,   154,   154,
     154,    33,   190,   237,   184,   170,   133,    95,    30,   143,
      95,   227,   286,   299,   154,  1498,   128,  1237,   231,   233,
     119,   254,  1237,   119,   148,    95,   198,   133,   161,   133,
      97,   184,   119,   154,   184,   154,   871,   148,   101,   190,
    1237,   101,   184,   143,   122,    35,    30,   119,   107,   154,
      80,   245,   108,  1273,   108,   258,   260,    30,  1541,   157,
     157,   267,   157,   145,  1284,   900,   157,   157,   157,  1284,
      30,    30,   190,   285,   157,   286,  1273,   187,   187,   148,
     227,  1237,   287,  1303,   145,   187,   128,  1284,  1303,    78,
     119,   148,   119,   148,   187,   930,   931,   932,   933,   108,
     143,   101,   133,  1323,   184,     7,  1303,   233,   187,   190,
    1330,   187,    97,   233,   198,   306,   233,   233,   186,   157,
     157,   157,   187,   286,   107,   148,  1323,   250,  1284,   154,
     282,  1237,    79,  1330,   969,   187,   187,   187,   187,   187,
     187,   187,  1362,    30,  1627,   237,    30,  1303,   983,   170,
     108,   184,   148,   148,    97,  1638,  1639,   127,  1641,   127,
     184,   143,   154,    95,   184,  1362,  1649,  1323,   271,   436,
     186,   186,   439,  1008,  1330,   250,   443,   184,  1284,   446,
     447,   186,  1017,   257,  1019,   184,  1021,   454,  1023,   187,
     184,    30,    97,   460,   461,   170,   187,  1303,   465,   148,
      54,  1036,    95,    95,   197,    30,   473,  1538,  1539,  1540,
     108,   108,   119,   480,   481,   482,   483,  1323,   119,   225,
     265,   488,    95,   287,  1330,   186,    95,   280,   197,   496,
     197,   119,   198,   186,  1069,    94,  1071,   225,   183,   316,
     197,   119,   119,   199,   186,   225,   260,   119,  1731,   260,
     263,   736,   287,   293,  1189,   970,  1362,  1037,  1234,   430,
     450,   305,  1711,  1758,   305,   872,   305,  1034,   792,  1479,
    1384,  1106,   306,  1263,   541,  1127,  1380,  1377,  1498,   465,
     306,  1285,  1290,   556,  1293,  1298,   655,  1770,   306,   556,
     933,   656,   675,   710,  1317,   833,  1131,  1782,  1776,  1188,
     567,  1498,  1019,  1349,  1359,  1788,  1360,  1397,  1576,  1408,
    1573,  1138,   340,  1002,  1401,   458,  1211,  1147,  1153,   458,
    1803,  1541,  1444,  1600,  1398,   597,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   603,    -1,    -1,  1670,
      -1,  1824,    -1,    -1,  1541,    -1,    -1,    -1,    -1,    -1,
    1833,    -1,    -1,    -1,    -1,    -1,  1687,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1627,  1243,    -1,
      -1,    -1,  1247,    -1,    -1,    -1,    -1,    -1,  1638,  1639,
      -1,  1641,    -1,    -1,    -1,    -1,    -1,  1262,    -1,  1649,
    1627,    -1,    -1,    -1,    -1,    -1,  1271,    -1,    -1,    -1,
      -1,  1638,  1639,    -1,  1641,    -1,    -1,    -1,    -1,    -1,
    1285,    -1,  1649,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1295,    -1,    -1,    -1,    -1,    -1,   733,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     747,    -1,    -1,    -1,   751,   752,    -1,    -1,    -1,  1324,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   773,    -1,   775,    -1,
      -1,  1731,    -1,    -1,  1349,    -1,   783,    -1,    -1,   786,
      -1,    -1,    -1,   790,  1359,    -1,    -1,    -1,  1363,    -1,
      -1,    -1,    -1,    -1,  1731,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1770,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   832,    -1,    -1,  1788,    -1,
      -1,    -1,    -1,  1770,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1803,    -1,  1420,    -1,    -1,    -1,    -1,
      -1,  1788,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1824,    -1,  1803,    -1,    -1,    -1,
      -1,    -1,    -1,  1833,    -1,  1450,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1824,    -1,    -1,
      -1,    -1,    -1,   900,    -1,    -1,  1833,    -1,    -1,    -1,
      -1,  1476,  1477,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   930,   931,   932,   933,  1502,    -1,    -1,
    1505,    -1,    -1,  1508,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1520,    -1,    -1,    -1,    -1,
    1525,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   969,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   983,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1008,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1017,    -1,  1019,    -1,  1021,    -1,  1023,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1036,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1069,    -1,  1071,    -1,    -1,  1642,  1643,    -1,
    1645,    -1,  1647,    -1,    -1,    -1,    -1,    -1,    -1,  1654,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1689,    -1,  1691,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1707,    -1,    -1,  1710,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1153,  1722,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1733,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1754,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1762,    -1,    -1,
      -1,    -1,  1767,    -1,  1769,    -1,  1771,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1800,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1243,    -1,    -1,    -1,
    1247,    -1,    -1,    -1,    -1,  1820,    -1,    -1,    -1,    -1,
    1825,    -1,    -1,    -1,    -1,  1262,    -1,    -1,    -1,    -1,
      -1,    -1,  1837,    -1,  1271,  1840,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1285,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1295,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   568,    -1,    -1,    -1,    -1,    -1,  1324,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   592,   593,    -1,   595,   596,
     597,   598,  1349,   600,    -1,    -1,    -1,    -1,    -1,   606,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   614,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   636,
     637,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   645,   646,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1420,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1450,    -1,    -1,    -1,    -1,    -1,   706,
      -1,    -1,    -1,   710,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1476,
    1477,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   749,    -1,    -1,  1502,    -1,    -1,  1505,    -1,
      -1,  1508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1520,    -1,    -1,    -1,    -1,  1525,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   791,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     817,    -1,    -1,    -1,   821,   822,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   830,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1642,  1643,    -1,  1645,   896,
    1647,    -1,    -1,    -1,    -1,   902,   903,  1654,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1689,    -1,  1691,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1707,    -1,    -1,  1710,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   971,  1722,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1733,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1754,    -1,  1006,
      -1,    -1,    -1,    -1,    -1,  1762,    -1,    -1,    -1,    -1,
    1767,    -1,  1769,    -1,  1771,    -1,    -1,    -1,  1025,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1047,    -1,    -1,  1800,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1058,  1059,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1820,    -1,    -1,  1073,    -1,  1825,  1076,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1837,    -1,    -1,  1840,    -1,    -1,  1093,  1094,  1095,    -1,
    1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,    -1,
      -1,  1108,  1109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1176,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1249,    -1,  1251,    -1,  1253,    -1,    -1,  1256,
      -1,    -1,    -1,    -1,  1261,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1273,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1282,    -1,    -1,    -1,    -1,
      -1,  1288,  1289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1307,    -1,    -1,  1310,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1380,    -1,    -1,    -1,  1384,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1463,    -1,    -1,    -1,
    1467,    -1,    -1,    -1,  1471,    -1,  1473,    -1,  1475,    -1,
      -1,    -1,    -1,    -1,  1481,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1497,  1498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1517,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1529,  1530,  1531,  1532,    -1,  1534,  1535,    -1,
    1537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1552,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1615,    -1,
    1617,    -1,    -1,  1620,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1628,    -1,    -1,    -1,    -1,  1633,  1634,    -1,    -1,
      -1,    -1,    -1,    -1,  1641,    -1,    -1,    -1,    -1,  1646,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1663,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1674,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1714,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1727,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1770,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1798,    -1,    -1,    -1,    -1,  1803,    -1,    -1,    -1,
      -1,  1808,     0,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    12,    -1,  1823,    -1,    16,    -1,
    1827,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
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
     188,   189,   190,   191,   192,    -1,   194,    -1,   196,    -1,
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
     318,   319,   320,     0,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,
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
     117,   118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,   190,   191,   192,    -1,   194,    -1,   196,
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
     307,   308,   309,   310,     1,   312,    -1,   314,   315,   316,
     317,   318,   319,   320,    11,    12,    -1,    -1,    -1,    16,
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
     117,   118,   119,   120,   121,    -1,    -1,    -1,   125,    -1,
     127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,   136,
     137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,   158,   159,   160,   161,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,   190,   191,   192,    -1,   194,    -1,   196,
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
     307,   308,   309,   310,     1,   312,    -1,   314,   315,   316,
     317,   318,   319,   320,    11,    12,    -1,    -1,    -1,    16,
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
     317,   318,   319,   320,     0,     1,    -1,     3,    -1,    -1,
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
      -1,   117,   118,   119,    -1,    -1,   122,    -1,    -1,    -1,
      -1,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,    -1,
      -1,   137,    -1,    -1,    -1,   141,   142,    -1,   144,    -1,
     146,   147,    -1,    -1,    -1,   151,   152,    -1,    -1,   155,
     156,   157,   158,   159,   160,    -1,    -1,   163,    -1,    -1,
      -1,   167,   168,    -1,    -1,   171,    -1,    -1,    -1,    -1,
     176,    -1,    -1,   179,    -1,    -1,    -1,    -1,   184,   185,
     186,   187,   188,    -1,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,   199,   200,   201,    -1,   203,   204,   205,
     206,   207,   208,    -1,   210,    -1,   212,    -1,    -1,    -1,
      -1,   217,   218,   219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,   235,
      -1,   237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,   311,    30,   313,    -1,    33,
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
      -1,    -1,   186,    -1,   188,   189,   190,   191,   192,    -1,
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
     314,   315,   316,   317,   318,   319,   320,   321,   322,    11,
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
     182,    -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    -1,
     322,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     180,   181,   182,    -1,   184,    -1,   186,    -1,   188,   189,
     190,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     180,   181,   182,    -1,   184,    -1,   186,    -1,   188,   189,
     190,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     180,   181,   182,    -1,   184,    -1,   186,    -1,   188,   189,
     190,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     190,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     190,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     190,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     190,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     190,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     190,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,   145,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,   189,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,   145,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,   189,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,   185,   186,    -1,   188,   189,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,   159,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,   189,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     310,   311,   312,    -1,   314,   315,   316,   317,   318,   319,
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     310,    -1,   312,   313,   314,   315,   316,   317,   318,   319,
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,   145,    -1,   147,   148,   149,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,    -1,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,   151,   152,   153,   154,   155,    -1,   157,   158,    -1,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,    -1,    -1,    -1,   194,    -1,   196,    -1,   198,   199,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
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
     120,   121,    -1,    -1,    -1,   125,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,    -1,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
     150,    -1,   152,   153,   154,   155,    -1,   157,   158,    -1,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,    -1,    -1,    -1,   194,    -1,   196,    -1,   198,    -1,
     200,    -1,   202,   203,   204,   205,   206,   207,   208,    -1,
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
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,
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
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
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
      -1,    -1,    -1,    -1,   314,   315,   316,   317,   318,   319,
     320,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,
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
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
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
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,   151,   152,   153,
      -1,    -1,    -1,   157,    -1,    -1,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,    -1,
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
     314,   315,   316,   317,   318,   319,   320,    16,    -1,    18,
      19,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,
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
      -1,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,    36,
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
     187,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
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
     181,   182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,
      -1,    -1,    -1,   194,    -1,   196,    -1,   198,   199,   200,
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
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,    -1,   151,   152,   153,    -1,
      -1,    -1,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,
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
     309,    -1,    -1,    -1,    -1,   314,   315,   316,   317,   318,
     319,   320,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    45,    46,    47,    -1,
      49,    50,    51,    52,    -1,    54,    -1,    56,    57,    58,
      59,    60,    61,    -1,    -1,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    98,
      -1,    -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,   125,    -1,   127,   128,
     129,   130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,
     139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,
     149,   150,   151,   152,    -1,   154,   155,    -1,   157,   158,
      -1,   160,   161,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    -1,    -1,   212,   213,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    -1,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,    -1,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,    -1,   312,    25,    26,   315,   316,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    -1,    40,
      41,    42,    43,    -1,    -1,    46,    47,    -1,    49,    50,
      51,    52,    -1,    54,    -1,    56,    57,    58,    59,    -1,
      61,    -1,    -1,    64,    65,    66,    67,    68,    -1,    70,
      -1,    72,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    -1,    -1,    -1,
     101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,   130,
      -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,   140,
      -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,
     161,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
      -1,   212,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
      -1,    -1,    -1,    -1,   315,   316
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
     181,   182,   186,   188,   189,   190,   191,   192,   194,   196,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   211,   212,   213,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   259,   260,   261,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   312,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   335,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   356,   357,   358,   359,
     360,   361,   365,   366,   367,   371,   373,   374,   376,   383,
     385,   388,   389,   390,   392,   393,   394,   395,   396,   398,
     399,   401,   402,   403,   404,   405,   406,   408,   409,   412,
     413,   414,   415,   416,   421,   423,   425,   426,   431,   450,
     453,   457,   460,   461,   467,   468,   469,   470,   472,   473,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   485,
     486,   487,   488,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     521,   522,   523,   524,   525,   526,   540,   541,   543,   544,
     545,   546,   547,   548,   549,   550,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   572,   577,
     578,   579,   580,   581,   582,   585,   643,   644,   645,   646,
     648,   649,   650,   651,   652,   655,   656,   657,    33,    34,
      49,   215,   391,   392,   393,   391,   391,   392,   393,   157,
     157,    37,    38,    40,    41,    47,    57,    58,    75,    80,
     112,   113,   114,   161,   220,   261,   287,   295,   303,   372,
     373,   377,   378,   379,   161,   154,   157,   154,   157,   154,
     157,     1,     3,    67,    72,   119,   418,   157,   380,   157,
      25,    34,    61,   119,   273,   430,   432,   433,   157,   154,
     157,   157,   157,   119,   154,   157,   157,   157,    77,   154,
     221,   222,   123,   123,   123,   154,   157,    39,    43,    45,
      46,    47,    48,    51,    60,    68,    71,    73,    74,    76,
      91,    92,    98,   106,   113,   115,   116,   136,   139,   140,
     161,   169,   172,   180,   181,   189,   202,   224,   226,   228,
     229,   236,   238,   239,   240,   243,   244,   315,   505,   656,
     123,   119,   400,   123,   123,    39,    44,    45,    53,    60,
      62,    63,    71,    98,   225,   655,   119,   123,   123,   184,
     391,   393,   414,   647,    48,    73,    74,   119,   154,   185,
     244,   413,   415,   425,   187,   413,   655,   154,   154,   123,
     655,    18,    19,   655,   123,   123,   123,   497,   154,    31,
     214,   216,   225,   227,   314,   225,   227,   314,   225,   314,
     225,   230,   314,   119,   241,   241,   242,   157,   154,   395,
     311,   413,   313,   413,   314,   322,   337,   337,     0,   339,
     340,    33,    49,   342,   359,     1,   190,   336,   190,   336,
     113,   374,   394,   413,   108,   190,   108,   336,   190,    42,
      46,    51,    70,   168,   171,   186,   212,   407,   417,   422,
     423,   424,   438,   439,   443,   167,    93,   133,   141,   142,
     144,   152,   156,   158,   163,   179,   203,   204,   205,   206,
     207,   208,   489,   490,   249,   100,   159,   176,   199,   118,
     147,   160,   194,   201,   210,   137,   151,    50,   200,   102,
     103,   159,   176,   487,   193,   154,   494,   497,   191,   192,
     155,   509,   510,   505,   509,   505,   157,   509,   157,   146,
     157,   184,   184,   184,   184,   375,   512,   375,    30,   654,
     182,   196,   182,   196,   166,   182,   656,   655,   169,   202,
      47,   655,   153,   119,    45,    47,    80,   107,   168,   655,
     221,   222,   223,   246,   616,   655,   655,   304,   138,   143,
     113,   287,   295,   377,   655,   392,   187,   392,    45,    63,
     187,   568,   569,   413,   187,   194,   655,   427,   428,   655,
     284,   284,   427,   119,   434,   119,   187,   381,   382,   154,
     397,   413,     1,   161,   654,   114,   161,   355,   654,   655,
     119,   143,   108,   187,   413,    30,   187,   655,   655,   655,
     451,   452,   655,   392,   187,   413,   413,   570,   655,   392,
     154,   154,   413,   187,   194,   655,   655,   143,   451,   184,
     184,   122,   108,   184,   157,   157,   157,   655,   154,   185,
     186,   187,    35,   528,   529,   530,   413,   413,     8,   175,
      17,   413,   214,    30,   414,   414,    39,    45,    60,    71,
      98,   508,   656,   414,   414,   414,   647,   414,   508,   414,
     231,   230,   583,   584,   655,   190,   190,   414,   413,   393,
     413,   245,   410,   411,   311,   313,   414,   337,   190,   336,
     190,   336,     3,   343,   359,   389,     1,   343,   359,   389,
      33,   360,   389,   360,   389,   400,   336,   400,   414,   414,
     119,   168,   170,   170,   394,   414,   414,   469,   470,   472,
     472,   472,   472,   471,   472,   472,   472,    71,   473,   477,
     477,   476,   478,   478,   478,   478,   479,   479,   480,   480,
     231,    95,    95,    95,   495,   391,   497,   497,   413,   510,
     145,   187,   414,   520,   187,   150,   187,   520,   108,   187,
     187,   108,   108,   380,    30,   656,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   362,   363,   364,    95,
     138,   143,   368,   369,   370,   655,   161,   161,   362,   654,
     128,   133,    55,    57,   101,   251,   264,   266,   277,   278,
     279,   281,   283,   617,   618,   619,   620,   621,   622,   629,
     635,   636,   246,    95,   299,   655,   143,   414,   119,   655,
     655,   133,   184,   184,   187,   187,   184,   108,   187,   108,
     187,   108,    36,    95,    97,   148,   429,   430,   551,   655,
      56,   217,   254,   419,   420,   655,    95,   108,   187,   391,
     187,   655,    97,    45,   655,   654,    97,   143,   551,   655,
     414,   433,   184,   187,   187,   187,   187,   108,   188,   148,
     551,   184,   187,   187,   154,   184,   392,   392,   184,   108,
     187,   108,   187,   143,   551,   414,   188,   414,   414,   413,
     413,   413,   655,   529,   530,   131,   197,   184,   184,   184,
     132,   190,    95,   218,   219,   233,    95,   218,   219,   233,
     233,   233,    95,    95,   237,   225,   231,   108,   235,   143,
     190,   187,   413,   184,   506,   589,   411,   233,   359,    33,
      33,   190,   336,   190,   114,   394,   655,   170,   414,   444,
     445,   119,   414,   440,   441,   472,   154,   157,   259,   493,
     512,   590,   593,   594,   595,   596,   597,   601,   603,   605,
     606,    47,   153,   157,   211,   317,   318,   319,   320,   552,
     554,   556,   558,   573,   574,   575,   576,   653,   655,   552,
     484,   557,   655,   484,   184,   185,   108,   187,   187,   512,
     149,   165,   149,   165,   138,   397,   380,   363,   133,   554,
     370,   414,   551,   654,   654,   129,   130,   654,   277,   278,
     279,   283,   655,   263,   274,   263,   274,    30,   286,    97,
     114,   157,   623,   626,   617,    39,    44,    53,    60,    62,
      71,    98,   225,   317,   318,   319,   384,   558,   653,   227,
     299,   308,   414,   655,    95,   299,   654,   154,   570,   571,
     655,   570,   571,   119,   428,   128,   552,   119,   414,   148,
     430,   148,    36,   148,   429,   430,   148,   551,   254,    54,
      59,    78,   119,   429,   435,   436,   437,   420,   551,   552,
     382,    95,   184,   198,   133,   354,   654,   161,   133,    97,
     354,   414,   143,   430,   154,   119,   414,   414,   148,   101,
     454,   455,   456,   458,   459,   101,   462,   463,   464,   465,
     392,   184,   184,   154,   570,   570,   414,   143,   190,   414,
     122,   187,   187,   187,    35,   530,   131,   197,     9,    10,
     104,   124,   126,   154,   195,   525,   527,   538,   539,   542,
     154,    30,   232,   234,   414,   414,   414,   232,   234,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   508,   119,
     414,   414,    48,    73,    74,   244,   394,   415,   425,   245,
     586,   587,   154,   210,   395,   414,   190,   114,   389,   389,
     389,   444,    96,   107,   117,   128,   446,   447,   448,   449,
     108,   655,   107,   442,   108,   413,   590,   597,   154,   285,
     474,   642,    97,   169,   252,   253,   255,   262,   272,   284,
     591,   592,   611,   612,   613,   614,   637,   640,   258,   260,
     598,   616,   267,   602,   638,   247,   248,   270,   607,   608,
     157,   157,   554,   157,   157,   157,   157,   157,   145,   176,
     194,   553,   145,   145,   414,   138,   397,   572,   369,   286,
      30,    97,   114,   157,   630,    30,   623,   553,   553,   495,
     287,   306,   551,   384,   227,   190,   391,   187,   187,   145,
     187,   187,   428,   148,   429,   655,   414,   148,   414,   128,
     414,   148,   430,   148,   414,   148,   119,   119,   414,   655,
     437,    78,   552,   394,   414,   654,   108,   354,   414,   143,
     391,   452,   414,   414,   114,   455,   456,   101,   186,   114,
     456,   459,   119,   466,   552,   101,   114,   463,   101,   114,
     465,   184,   391,   187,   187,   414,   414,   198,   462,   133,
     195,   527,     7,   392,   655,   195,   538,   392,   190,   233,
     233,   233,   233,    97,   237,   237,   584,   186,   157,   157,
     157,   186,   589,   587,   506,   654,   129,   130,   448,   449,
     449,   445,   143,   551,   654,   441,   184,   187,   590,   604,
     250,   217,   254,   268,   275,   641,    97,   256,   257,   639,
     250,   594,   641,   476,   611,   595,   148,   282,   599,   600,
     639,   286,   610,    79,   609,   187,   194,   552,   555,   187,
     187,   187,   187,   187,   187,   187,    30,   137,   201,   632,
     633,   634,    30,   631,   632,   271,   627,   108,   624,   170,
     655,   257,   495,   184,   414,   148,   414,   148,   429,   414,
     148,   414,   414,   655,   655,   436,   414,   127,   127,    97,
     654,   414,   184,   186,   186,   414,   394,   414,   186,   186,
     655,   186,   210,   119,   466,   119,   186,   119,   466,   186,
     184,   114,   530,   655,   195,   184,   530,   655,   184,   414,
     414,   414,   414,   316,   414,   414,   414,   413,   413,   413,
     154,   588,   449,   414,   143,   184,   478,    52,   130,   476,
     476,   269,   276,   286,   615,   615,   596,   154,   280,    95,
     187,   108,   187,   630,   630,   634,   108,   187,    30,   628,
     639,   625,   626,   187,   386,   387,   495,   119,   225,   307,
     287,   170,   414,   414,   148,   414,    54,   394,   414,   354,
     414,   394,    95,   394,   414,   552,   655,   186,   655,   414,
     655,   186,   394,   119,    94,   183,   531,   530,   655,   197,
     530,   414,   187,   187,   187,   413,   442,   414,   476,   476,
     199,   413,   552,   552,    95,    30,   265,   108,   108,   449,
     551,   655,   119,   225,   655,   386,   414,   119,   466,    95,
     186,    95,   655,     5,   134,   534,   535,   537,   539,    29,
     135,   532,   533,   536,   539,   197,   530,   197,   198,   462,
     184,   442,   476,   184,   552,   626,   387,   449,   305,   655,
     119,   225,   655,   186,   466,   394,   414,   466,   186,    94,
     134,   537,   183,   135,   536,   197,   114,   414,   305,   655,
     119,   394,   414,   186,   186,   119,   293,   305,   655,   655,
     306,   414,   306,   186,   495,   495,   199,   287,   655,   225,
     119,   655,   306,   495
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
     394,   394,   394,   394,   394,   394,   394,   395,   395,   396,
     397,   398,   399,   399,   399,   400,   400,   400,   400,   401,
     402,   403,   404,   405,   405,   406,   407,   408,   409,   410,
     410,   411,   412,   413,   413,   413,   414,   414,   414,   414,
     414,   414,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   416,   417,   418,   418,   419,   419,
     419,   420,   420,   421,   421,   422,   423,   423,   423,   424,
     424,   424,   424,   424,   425,   425,   426,   426,   426,   427,
     427,   427,   428,   428,   428,   428,   428,   428,   428,   428,
     428,   428,   428,   428,   429,   430,   431,   432,   432,   433,
     433,   433,   433,   434,   434,   435,   435,   435,   436,   436,
     436,   437,   437,   437,   438,   439,   440,   440,   441,   441,
     441,   441,   441,   441,   442,   443,   443,   444,   444,   445,
     445,   446,   446,   446,   446,   446,   446,   446,   447,   447,
     448,   448,   449,   450,   450,   451,   451,   452,   452,   453,
     454,   454,   455,   456,   456,   457,   458,   458,   459,   460,
     460,   461,   461,   462,   462,   463,   463,   464,   464,   465,
     465,   466,   466,   467,   468,   468,   469,   469,   470,   470,
     470,   470,   470,   471,   470,   470,   470,   470,   472,   472,
     473,   473,   474,   474,   475,   475,   476,   476,   476,   477,
     477,   477,   477,   477,   478,   478,   478,   479,   479,   479,
     480,   480,   481,   481,   482,   482,   483,   483,   484,   484,
     485,   485,   486,   486,   486,   486,   487,   487,   487,   488,
     488,   489,   489,   489,   489,   489,   489,   490,   490,   490,
     491,   491,   491,   491,   492,   493,   493,   494,   494,   494,
     495,   495,   495,   495,   496,   497,   497,   497,   498,   498,
     499,   499,   499,   499,   500,   500,   501,   501,   501,   501,
     501,   501,   501,   502,   502,   503,   503,   504,   504,   504,
     504,   504,   505,   505,   506,   506,   507,   507,   507,   507,
     508,   508,   508,   508,   509,   509,   510,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   511,
     511,   512,   512,   513,   513,   513,   514,   515,   515,   516,
     517,   518,   519,   519,   520,   520,   520,   520,   521,   521,
     522,   523,   524,   524,   525,   525,   525,   526,   526,   526,
     526,   526,   526,   527,   527,   528,   528,   529,   530,   530,
     531,   531,   532,   532,   533,   533,   533,   533,   534,   534,
     535,   535,   535,   535,   536,   536,   537,   537,   538,   538,
     538,   538,   539,   539,   539,   539,   540,   540,   541,   541,
     542,   543,   543,   543,   543,   543,   543,   543,   544,   545,
     545,   546,   546,   547,   548,   549,   549,   550,   550,   551,
     552,   552,   552,   553,   553,   553,   554,   554,   554,   554,
     554,   554,   554,   555,   555,   556,   557,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   559,   560,   561,
     561,   561,   562,   563,   564,   565,   565,   565,   566,   566,
     566,   566,   566,   567,   568,   568,   568,   568,   568,   568,
     568,   569,   570,   571,   572,   573,   573,   574,   575,   575,
     576,   577,   577,   577,   578,   578,   578,   578,   578,   578,
     578,   578,   578,   578,   579,   579,   580,   580,   581,   582,
     583,   583,   584,   585,   586,   586,   587,   588,   589,   589,
     590,   591,   591,   592,   592,   593,   593,   594,   594,   595,
     595,   596,   596,   597,   598,   598,   599,   599,   600,   601,
     601,   601,   602,   602,   603,   604,   604,   605,   606,   606,
     607,   607,   608,   608,   608,   609,   609,   610,   610,   611,
     611,   611,   611,   611,   612,   613,   614,   615,   615,   615,
     616,   616,   617,   617,   617,   617,   617,   617,   617,   617,
     618,   618,   618,   618,   619,   619,   620,   621,   621,   622,
     622,   622,   623,   623,   624,   624,   625,   625,   626,   627,
     627,   628,   628,   629,   629,   629,   630,   630,   631,   631,
     632,   632,   633,   633,   634,   634,   635,   636,   636,   637,
     637,   637,   638,   639,   639,   639,   639,   640,   640,   641,
     641,   642,   643,   643,   644,   644,   645,   645,   646,   647,
     647,   648,   648,   648,   649,   650,   651,   652,   653,   653,
     653,   654,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   656,   656,   656,   656,
     656,   656,   656,   656,   656,   656,   657
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
       1,     1,     1,     1,     1,     1,     1,     3,     2,     3,
       3,     2,     3,     2,     3,     2,     3,     4,     5,     5,
       2,     4,     5,     3,     3,     2,     2,     8,     3,     1,
       2,     3,     1,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       2,     4,     3,     5,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     3,     2,     1,
       4,     3,     3,     5,     4,     6,     4,     6,     5,     7,
       4,     5,     5,     6,     3,     3,     2,     1,     3,     4,
       5,     3,     6,     4,     5,     1,     2,     3,     1,     2,
       1,     6,     3,     3,     2,     3,     1,     3,     4,     5,
       6,     5,     1,     2,     2,     3,     4,     1,     3,     1,
       2,     1,     1,     1,     2,     2,     2,     3,     1,     1,
       2,     2,     2,     5,     5,     1,     4,     3,     4,     8,
       1,     2,     3,     2,     3,     8,     1,     2,     3,     8,
      10,     8,    10,     1,     2,     4,     7,     1,     2,     4,
       7,     1,     3,     8,     1,     3,     1,     3,     1,     3,
       3,     3,     3,     0,     4,     3,     3,     3,     1,     5,
       1,     3,     0,     1,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     4,     1,     4,     1,     4,     1,     4,     1,     2,
       1,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     5,     6,     4,     1,     2,     3,     2,     2,
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
       5,     5,     5,     8,     5,     3,     5,     7,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
  "CatchStatement", "VoidStatement", "Expr", "ExprSingle", "ExprSimple",
  "FLWORExpr", "ReturnExpr", "WindowType", "FLWORWinCondType",
  "FLWORWinCond", "WindowClause", "CountClause", "ForLetWinClause",
  "FLWORClause", "FLWORClauseList", "ForClause", "VarInDeclList",
  "VarInDecl", "PositionalVar", "FTScoreVar", "LetClause",
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
  "OrExpr", "AndExpr", "ComparisonExpr", "$@1", "FTContainsExpr",
  "StringConcatExpr", "opt_FTIgnoreOption", "RangeExpr", "AdditiveExpr",
  "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
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
  "JSONTest", "URI_LITERAL", "QNAME", "FUNCTION_NAME", "EQNAME", 0
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
      -1,   341,   342,   190,   359,   190,    -1,    34,   161,   655,
     133,   654,   190,    -1,   343,    -1,   342,   190,   343,    -1,
     342,   336,   343,    -1,   344,    -1,   352,    -1,   357,    -1,
     358,    -1,   366,    -1,   345,    -1,   346,    -1,   347,    -1,
     348,    -1,   349,    -1,   350,    -1,   351,    -1,   577,    -1,
      33,    38,   182,    -1,    33,    38,   196,    -1,    33,   114,
     107,   654,    -1,    33,    37,   654,    -1,    33,    40,   182,
      -1,    33,    40,   196,    -1,    33,    58,   169,    -1,    33,
      58,   202,    -1,    33,   114,   168,   128,   129,    -1,    33,
     114,   168,   128,   130,    -1,    33,    41,   182,   108,   149,
      -1,    33,    41,   182,   108,   165,    -1,    33,    41,   166,
     108,   149,    -1,    33,    41,   166,   108,   165,    -1,   353,
      -1,   356,    -1,    49,    25,     1,    -1,    49,    61,   654,
      -1,    49,    61,   355,   654,    -1,    49,    61,   654,    97,
     354,    -1,    49,    61,   355,   654,    97,   354,    -1,   654,
      -1,   354,   108,   654,    -1,   161,   655,   133,    -1,   114,
      45,   161,    -1,    49,    34,   654,    -1,    49,    34,   161,
     655,   133,   654,    -1,    49,    34,   654,    97,   354,    -1,
      49,    34,   161,   655,   133,   654,    97,   354,    -1,    33,
     161,   655,   133,   654,    -1,    33,   114,    45,   161,   654,
      -1,    33,   114,    47,   161,   654,    -1,   360,    -1,   359,
     190,   360,    -1,   359,   336,   360,    -1,   361,    -1,   365,
      -1,   367,    -1,   371,    -1,   376,    -1,   383,    -1,   385,
      -1,   388,    -1,    33,   114,    80,   362,    -1,    33,    80,
     655,   362,    -1,   363,    -1,   362,   363,    -1,   364,   133,
     572,    -1,    81,    -1,    89,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    90,    -1,    86,    -1,    87,    -1,
      88,    -1,    33,    57,   655,    30,    -1,    33,   261,   616,
      -1,    33,   112,   153,   368,    -1,    95,   554,   369,    -1,
     369,    -1,   370,    -1,   138,    -1,   138,   370,    -1,   143,
     414,    -1,    33,   372,   143,   414,    -1,    33,   372,   138,
      -1,    33,   372,   138,   143,   414,    -1,   113,   119,   655,
      -1,   113,   119,   655,   551,    -1,   373,   113,   119,   655,
      -1,   373,   113,   119,   655,   551,    -1,   374,    -1,   373,
     374,    -1,    27,    -1,    27,   157,   375,   187,    -1,    28,
      -1,    28,   157,   375,   187,    -1,   512,    -1,   375,   108,
     512,    -1,    33,   377,    -1,    33,   373,   377,    -1,   378,
      -1,   379,    -1,    47,   656,   380,   397,    -1,    47,   656,
     380,   138,    -1,    75,    47,   656,   380,   397,    -1,    75,
      47,   656,   380,   138,    -1,   157,   187,    -1,   157,   381,
     187,    -1,   157,   187,    95,   552,    -1,   157,   381,   187,
      95,   552,    -1,   382,    -1,   381,   108,   382,    -1,   119,
     655,    -1,   119,   655,   551,    -1,    33,   287,   655,    -1,
      33,   287,   655,    95,   384,    -1,    33,   373,   287,   655,
      -1,    33,   373,   287,   655,    95,   384,    -1,   558,    -1,
     558,   553,    -1,   653,    -1,   653,   553,    -1,    33,   295,
     655,   299,   227,   495,   170,   386,    -1,    33,   373,   295,
     655,   299,   227,   495,   170,   386,    -1,   387,    -1,   386,
     108,   387,    -1,   495,    -1,   495,   551,    -1,   495,   449,
      -1,   495,   551,   449,    -1,    33,   303,   304,   655,   299,
     287,   655,   119,   655,   305,   414,    -1,    33,   303,   304,
     655,   299,   287,   655,   225,   119,   655,   305,   293,   306,
     495,    -1,    33,   303,   304,   655,   299,   287,   655,   307,
     225,   119,   655,   305,   414,    -1,    33,   303,   304,   655,
     308,   306,   257,   287,   655,   225,   119,   655,   306,   495,
     199,   287,   655,   225,   119,   655,   306,   495,    -1,   390,
      -1,   392,    -1,   393,    -1,    -1,   392,    -1,   393,    -1,
      -1,   413,    -1,   393,   413,    -1,   394,    -1,   393,   394,
      -1,   393,   413,   336,   394,    -1,   395,    -1,   398,    -1,
     401,    -1,   402,    -1,   403,    -1,   404,    -1,   405,    -1,
     406,    -1,   408,    -1,   461,    -1,   457,    -1,   409,    -1,
     412,    -1,   154,   393,   184,    -1,   154,   184,    -1,   154,
     391,   184,    -1,   154,   391,   184,    -1,   399,   190,    -1,
     399,   108,   400,    -1,   113,   400,    -1,   373,   113,   400,
      -1,   119,   655,    -1,   119,   655,   551,    -1,   119,   655,
     143,   414,    -1,   119,   655,   551,   143,   414,    -1,   119,
     655,   143,   414,   190,    -1,   415,   190,    -1,   240,   242,
     414,   190,    -1,   243,   157,   413,   187,   394,    -1,   238,
     241,   190,    -1,   239,   241,   190,    -1,   425,   407,    -1,
     186,   394,    -1,    48,   157,   413,   187,   198,   394,   127,
     394,    -1,   244,   395,   410,    -1,   411,    -1,   410,   411,
      -1,   245,   589,   395,    -1,   190,    -1,   414,    -1,   413,
     108,   414,    -1,   413,   336,   414,    -1,   416,    -1,   453,
      -1,   460,    -1,   467,    -1,   585,    -1,   415,    -1,   468,
      -1,   450,    -1,   578,    -1,   579,    -1,   581,    -1,   580,
      -1,   582,    -1,   650,    -1,   648,    -1,   651,    -1,   652,
      -1,   649,    -1,   425,   417,    -1,   186,   414,    -1,    67,
     284,    -1,    72,   284,    -1,   217,    -1,   254,    -1,    56,
     254,    -1,   419,   435,    78,   414,    -1,   419,    78,   414,
      -1,    46,   418,   434,   420,   420,    -1,    46,   418,   434,
     420,    -1,    42,   119,   655,    -1,   426,    -1,   431,    -1,
     421,    -1,   423,    -1,   438,    -1,   443,    -1,   439,    -1,
     422,    -1,   423,    -1,   425,   424,    -1,    46,   119,   427,
      -1,    46,     1,   427,    -1,    46,     3,    -1,   428,    -1,
     427,   108,   119,   428,    -1,   427,   108,   428,    -1,   655,
     148,   414,    -1,   655,    36,   128,   148,   414,    -1,   655,
     551,   148,   414,    -1,   655,   551,    36,   128,   148,   414,
      -1,   655,   429,   148,   414,    -1,   655,    36,   128,   429,
     148,   414,    -1,   655,   551,   429,   148,   414,    -1,   655,
     551,    36,   128,   429,   148,   414,    -1,   655,   430,   148,
     414,    -1,   655,   551,   430,   148,   414,    -1,   655,   429,
     430,   148,   414,    -1,   655,   551,   429,   430,   148,   414,
      -1,    97,   119,   655,    -1,   273,   119,   655,    -1,    51,
     432,    -1,   433,    -1,   432,   108,   433,    -1,   119,   655,
     143,   414,    -1,   119,   655,   551,   143,   414,    -1,   430,
     143,   414,    -1,   119,   655,   551,   430,   143,   414,    -1,
     119,   655,   148,   414,    -1,   119,   655,   551,   148,   414,
      -1,   436,    -1,   119,   655,    -1,   119,   655,   436,    -1,
     429,    -1,   429,   437,    -1,   437,    -1,    59,   119,   655,
      54,   119,   655,    -1,    54,   119,   655,    -1,    59,   119,
     655,    -1,   212,   414,    -1,   171,   170,   440,    -1,   441,
      -1,   440,   108,   441,    -1,   119,   655,   143,   414,    -1,
     119,   655,   551,   143,   414,    -1,   119,   655,   551,   143,
     414,   442,    -1,   119,   655,   143,   414,   442,    -1,   414,
      -1,   414,   442,    -1,   107,   654,    -1,   168,   170,   444,
      -1,    70,   168,   170,   444,    -1,   445,    -1,   444,   108,
     445,    -1,   414,    -1,   414,   446,    -1,   447,    -1,   448,
      -1,   449,    -1,   447,   448,    -1,   447,   449,    -1,   448,
     449,    -1,   447,   448,   449,    -1,    96,    -1,   117,    -1,
     128,   129,    -1,   128,   130,    -1,   107,   654,    -1,    68,
     119,   451,   188,   414,    -1,   136,   119,   451,   188,   414,
      -1,   452,    -1,   451,   108,   119,   452,    -1,   655,   148,
     414,    -1,   655,   551,   148,   414,    -1,    73,   157,   413,
     187,   454,   114,   186,   414,    -1,   455,    -1,   454,   455,
      -1,   456,   186,   414,    -1,   101,   414,    -1,   456,   101,
     414,    -1,    73,   157,   413,   187,   458,   114,   186,   394,
      -1,   459,    -1,   458,   459,    -1,   456,   186,   394,    -1,
      74,   157,   413,   187,   462,   114,   186,   414,    -1,    74,
     157,   413,   187,   462,   114,   119,   655,   186,   414,    -1,
      74,   157,   413,   187,   464,   114,   186,   394,    -1,    74,
     157,   413,   187,   462,   114,   119,   655,   186,   394,    -1,
     463,    -1,   462,   463,    -1,   101,   466,   186,   414,    -1,
     101,   119,   655,    95,   466,   186,   414,    -1,   465,    -1,
     464,   465,    -1,   101,   466,   186,   394,    -1,   101,   119,
     655,    95,   466,   186,   394,    -1,   552,    -1,   466,   210,
     552,    -1,    48,   157,   413,   187,   198,   414,   127,   414,
      -1,   469,    -1,   468,   167,   469,    -1,   470,    -1,   469,
      93,   470,    -1,   472,    -1,   472,   489,   472,    -1,   472,
     490,   472,    -1,   472,   133,   472,    -1,   472,   163,   472,
      -1,    -1,   472,   158,   471,   472,    -1,   472,   156,   472,
      -1,   472,   144,   472,    -1,   472,   142,   472,    -1,   473,
      -1,   473,   249,    71,   590,   474,    -1,   475,    -1,   475,
     100,   473,    -1,    -1,   642,    -1,   476,    -1,   476,   199,
     476,    -1,   477,    -1,   476,   176,   477,    -1,   476,   159,
     477,    -1,   478,    -1,   477,   194,   478,    -1,   477,   118,
     478,    -1,   477,   147,   478,    -1,   477,   160,   478,    -1,
     479,    -1,   478,   201,   479,    -1,   478,   210,   479,    -1,
     480,    -1,   479,   151,   480,    -1,   479,   137,   480,    -1,
     481,    -1,   481,    50,   231,   552,    -1,   482,    -1,   482,
     200,    95,   552,    -1,   483,    -1,   483,   102,    95,   484,
      -1,   485,    -1,   485,   103,    95,   484,    -1,   557,    -1,
     557,   145,    -1,   487,    -1,   486,   487,    -1,   176,    -1,
     159,    -1,   486,   176,    -1,   486,   159,    -1,   491,    -1,
     488,    -1,   492,    -1,   495,    -1,   488,   193,   495,    -1,
     203,    -1,   208,    -1,   207,    -1,   206,    -1,   205,    -1,
     204,    -1,   152,    -1,   179,    -1,   141,    -1,    76,   154,
     392,   184,    -1,    76,   222,   154,   392,   184,    -1,    76,
     221,   154,   392,   184,    -1,    76,    77,   570,   154,   392,
     184,    -1,   493,   154,   391,   184,    -1,   494,    -1,   493,
     494,    -1,   177,   655,    17,    -1,   177,    18,    -1,   177,
      19,    -1,   496,    -1,   496,   497,    -1,   192,   497,    -1,
     497,    -1,   191,    -1,   498,    -1,   498,   191,   497,    -1,
     498,   192,   497,    -1,   499,    -1,   508,    -1,   500,    -1,
     500,   509,    -1,   503,    -1,   503,   509,    -1,   501,   505,
      -1,   502,    -1,   106,   123,    -1,   115,   123,    -1,    98,
     123,    -1,   189,   123,    -1,   116,   123,    -1,   140,   123,
      -1,   139,   123,    -1,   505,    -1,    99,   505,    -1,   504,
     505,    -1,   121,    -1,   172,   123,    -1,    91,   123,    -1,
     181,   123,    -1,   180,   123,    -1,    92,   123,    -1,   558,
      -1,   506,    -1,   655,    -1,   507,    -1,   194,    -1,    11,
      -1,    12,    -1,    20,    -1,   511,    -1,   508,   509,    -1,
     508,   157,   187,    -1,   508,   157,   520,   187,    -1,   510,
      -1,   509,   510,    -1,   155,   413,   185,    -1,   512,    -1,
     514,    -1,   515,    -1,   516,    -1,   519,    -1,   524,    -1,
     517,    -1,   518,    -1,   521,    -1,   396,    -1,   646,    -1,
     643,    -1,   644,    -1,   645,    -1,   513,    -1,   572,    -1,
     111,    -1,   150,    -1,   125,    -1,   119,   655,    -1,   157,
     187,    -1,   157,   413,   187,    -1,   120,    -1,   169,   154,
     413,   184,    -1,   202,   154,   413,   184,    -1,   656,   157,
     187,    -1,   656,   157,   520,   187,    -1,   145,    -1,   520,
     108,   145,    -1,   414,    -1,   520,   108,   414,    -1,   522,
      -1,   523,    -1,   656,   146,   150,    -1,    47,   380,   397,
      -1,   525,    -1,   543,    -1,   526,    -1,   540,    -1,   541,
      -1,   158,   655,   530,   131,    -1,   158,   655,   530,   197,
     195,   655,   530,   197,    -1,   158,   655,   528,   530,   131,
      -1,   158,   655,   528,   530,   197,   195,   655,   530,   197,
      -1,   158,   655,   530,   197,   527,   195,   655,   530,   197,
      -1,   158,   655,   528,   530,   197,   527,   195,   655,   530,
     197,    -1,   538,    -1,   527,   538,    -1,   529,    -1,   528,
     529,    -1,    35,   655,   530,   133,   530,   531,    -1,    -1,
      35,    -1,   183,   532,   183,    -1,    94,   534,    94,    -1,
      -1,   533,    -1,   135,    -1,   536,    -1,   533,   135,    -1,
     533,   536,    -1,    -1,   535,    -1,   134,    -1,   537,    -1,
     535,   134,    -1,   535,   537,    -1,    29,    -1,   539,    -1,
       5,    -1,   539,    -1,   525,    -1,    10,    -1,   542,    -1,
     539,    -1,     9,    -1,   124,    -1,   126,    -1,   154,   392,
     184,    -1,   213,    31,   214,    -1,   213,   214,    -1,   174,
     655,   175,    -1,   174,   655,     8,    -1,   104,     7,    -1,
     544,    -1,   545,    -1,   546,    -1,   547,    -1,   548,    -1,
     549,    -1,   550,    -1,    43,   154,   392,   184,    -1,    21,
     391,   184,    -1,    45,   154,   413,   184,   154,   391,   184,
      -1,    22,   391,   184,    -1,    98,   154,   413,   184,   154,
     391,   184,    -1,    71,   154,   392,   184,    -1,    39,   154,
     392,   184,    -1,    23,   391,   184,    -1,    60,   154,   413,
     184,   154,   391,   184,    -1,    24,   392,   184,    -1,   161,
     154,   413,   184,   154,   392,   184,    -1,    95,   552,    -1,
     554,    -1,   554,   553,    -1,   211,   157,   187,    -1,   145,
      -1,   194,    -1,   176,    -1,   556,    -1,   558,    -1,   153,
     157,   187,    -1,   320,   157,   187,    -1,   573,    -1,   576,
      -1,   653,    -1,   552,    -1,   555,   108,   552,    -1,   655,
      -1,   655,    -1,   561,    -1,   568,    -1,   566,    -1,   569,
      -1,   567,    -1,   565,    -1,   564,    -1,   563,    -1,   562,
      -1,   559,    -1,   560,   157,   187,    -1,   225,    -1,    44,
     157,   187,    -1,    44,   157,   568,   187,    -1,    44,   157,
     569,   187,    -1,    53,   157,   187,    -1,    71,   157,   187,
      -1,    39,   157,   187,    -1,    60,   157,   187,    -1,    60,
     157,   655,   187,    -1,    60,   157,    30,   187,    -1,    98,
     157,   187,    -1,    98,   157,   655,   187,    -1,    98,   157,
     655,   108,   570,   187,    -1,    98,   157,   194,   187,    -1,
      98,   157,   194,   108,   570,   187,    -1,    62,   157,   655,
     187,    -1,    45,   157,   187,    -1,    45,   157,   655,   187,
      -1,    45,   157,   655,   108,   570,   187,    -1,    45,   157,
     655,   108,   571,   187,    -1,    45,   157,   194,   187,    -1,
      45,   157,   194,   108,   570,   187,    -1,    45,   157,   194,
     108,   571,   187,    -1,    63,   157,   655,   187,    -1,   655,
      -1,   655,   145,    -1,    30,    -1,   574,    -1,   575,    -1,
      47,   157,   194,   187,    -1,    47,   157,   187,    95,   552,
      -1,    47,   157,   555,   187,    95,   552,    -1,   157,   554,
     187,    -1,    33,   220,   221,    -1,    33,   220,   222,    -1,
      33,   220,   223,    -1,   226,   225,   414,   233,   414,    -1,
     226,   225,   414,    95,   232,   233,   414,    -1,   226,   225,
     414,    95,   234,   233,   414,    -1,   226,   225,   414,   218,
     414,    -1,   226,   225,   414,   219,   414,    -1,   226,   227,
     414,   233,   414,    -1,   226,   227,   414,    95,   232,   233,
     414,    -1,   226,   227,   414,    95,   234,   233,   414,    -1,
     226,   227,   414,   218,   414,    -1,   226,   227,   414,   219,
     414,    -1,   224,   225,   414,    -1,   224,   227,   414,    -1,
     229,   225,   414,   237,   414,    -1,   229,   230,   231,   225,
     414,   237,   414,    -1,   228,   225,   414,    95,   414,    -1,
     236,   119,   583,   235,   414,   186,   414,    -1,   584,    -1,
     583,   108,   119,   584,    -1,   655,   143,   414,    -1,   244,
     154,   413,   184,   586,    -1,   587,    -1,   586,   587,    -1,
     245,   589,   588,    -1,   154,   413,   184,    -1,   506,    -1,
     589,   210,   506,    -1,   593,   591,    -1,    -1,   592,    -1,
     611,    -1,   592,   611,    -1,   594,    -1,   593,   262,   594,
      -1,   595,    -1,   594,   258,   595,    -1,   596,    -1,   595,
     260,   148,   596,    -1,   597,    -1,   259,   597,    -1,   601,
     598,   599,    -1,    -1,   616,    -1,    -1,   600,    -1,   282,
     154,   413,   184,    -1,   605,   602,    -1,   157,   590,   187,
      -1,   603,    -1,    -1,   638,    -1,   493,   154,   604,   184,
      -1,    -1,   590,    -1,   606,   607,    -1,   512,    -1,   154,
     413,   184,    -1,    -1,   608,    -1,   248,   609,    -1,   247,
     610,    -1,   270,    -1,    -1,    79,    -1,    -1,   286,    -1,
     612,    -1,   613,    -1,   614,    -1,   640,    -1,   637,    -1,
     169,    -1,   284,   476,   615,    -1,   253,   639,   615,    -1,
     286,    -1,   276,    -1,   269,    -1,   246,   617,    -1,   616,
     246,   617,    -1,   618,    -1,   619,    -1,   620,    -1,   635,
      -1,   621,    -1,   629,    -1,   622,    -1,   636,    -1,   101,
     274,    -1,   101,   263,    -1,   266,    -1,   281,    -1,   251,
     274,    -1,   251,   263,    -1,    57,   655,    30,    -1,   277,
      -1,    55,   277,    -1,   279,   623,    -1,   279,   157,   623,
     624,   187,    -1,    55,   279,    -1,   626,    -1,   114,    -1,
      -1,   108,   625,    -1,   626,    -1,   625,   108,   626,    -1,
      97,    30,   627,   628,    -1,    -1,   271,    30,    -1,    -1,
     639,   265,    -1,   278,   286,   630,   632,    -1,   278,   286,
     114,   632,    -1,    55,   278,   286,    -1,    97,    30,    -1,
     157,   631,   187,    -1,    30,    -1,   631,   108,    30,    -1,
      -1,   633,    -1,   634,    -1,   633,   634,    -1,   201,   630,
      -1,   137,   630,    -1,   264,    30,    -1,   283,    -1,    55,
     283,    -1,    97,   217,    -1,    97,   254,    -1,   255,   250,
      -1,   267,   639,   280,    -1,   256,   476,    -1,    97,   130,
     476,    -1,    97,    52,   476,    -1,   257,   476,   199,   476,
      -1,   272,   641,    -1,   252,   641,    -1,   275,    -1,   268,
      -1,   285,   250,   478,    -1,   155,   185,    -1,   155,   413,
     185,    -1,   310,   311,    -1,   310,   413,   311,    -1,   312,
     313,    -1,   312,   413,   313,    -1,   154,   647,   184,    -1,
     414,   122,   414,    -1,   647,   108,   414,   122,   414,    -1,
     226,   314,   414,   233,   414,    -1,   226,   314,   647,   233,
     414,    -1,   226,   314,   414,   233,   414,    97,   316,   414,
      -1,   315,   314,   414,   233,   414,    -1,   224,   314,   508,
      -1,   228,   314,   508,    95,   414,    -1,   229,   314,   230,
     231,   508,   237,   414,    -1,   319,   157,   187,    -1,   318,
     157,   187,    -1,   317,   157,   187,    -1,    30,    -1,   656,
      -1,    16,    -1,    98,    -1,    39,    -1,    44,    -1,    53,
      -1,    45,    -1,   153,    -1,    48,    -1,   225,    -1,    60,
      -1,    62,    -1,    63,    -1,    71,    -1,    74,    -1,    73,
      -1,   211,    -1,   243,    -1,   314,    -1,   318,    -1,   317,
      -1,   319,    -1,   320,    -1,   657,    -1,    25,    -1,   215,
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
      -1,   235,    -1,   232,    -1,   315,    -1,   226,    -1,   229,
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
      -1,   140,    -1,   181,    -1,   316,    -1,    26,    -1
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
     688,   690,   692,   694,   696,   698,   700,   702,   706,   709,
     713,   717,   720,   724,   727,   731,   734,   738,   743,   749,
     755,   758,   763,   769,   773,   777,   780,   783,   792,   796,
     798,   801,   805,   807,   809,   813,   817,   819,   821,   823,
     825,   827,   829,   831,   833,   835,   837,   839,   841,   843,
     845,   847,   849,   851,   853,   856,   859,   862,   865,   867,
     869,   872,   877,   881,   887,   892,   896,   898,   900,   902,
     904,   906,   908,   910,   912,   914,   917,   921,   925,   928,
     930,   935,   939,   943,   949,   954,   961,   966,   973,   979,
     987,   992,   998,  1004,  1011,  1015,  1019,  1022,  1024,  1028,
    1033,  1039,  1043,  1050,  1055,  1061,  1063,  1066,  1070,  1072,
    1075,  1077,  1084,  1088,  1092,  1095,  1099,  1101,  1105,  1110,
    1116,  1123,  1129,  1131,  1134,  1137,  1141,  1146,  1148,  1152,
    1154,  1157,  1159,  1161,  1163,  1166,  1169,  1172,  1176,  1178,
    1180,  1183,  1186,  1189,  1195,  1201,  1203,  1208,  1212,  1217,
    1226,  1228,  1231,  1235,  1238,  1242,  1251,  1253,  1256,  1260,
    1269,  1280,  1289,  1300,  1302,  1305,  1310,  1318,  1320,  1323,
    1328,  1336,  1338,  1342,  1351,  1353,  1357,  1359,  1363,  1365,
    1369,  1373,  1377,  1381,  1382,  1387,  1391,  1395,  1399,  1401,
    1407,  1409,  1413,  1414,  1416,  1418,  1422,  1424,  1428,  1432,
    1434,  1438,  1442,  1446,  1450,  1452,  1456,  1460,  1462,  1466,
    1470,  1472,  1477,  1479,  1484,  1486,  1491,  1493,  1498,  1500,
    1503,  1505,  1508,  1510,  1512,  1515,  1518,  1520,  1522,  1524,
    1526,  1530,  1532,  1534,  1536,  1538,  1540,  1542,  1544,  1546,
    1548,  1553,  1559,  1565,  1572,  1577,  1579,  1582,  1586,  1589,
    1592,  1594,  1597,  1600,  1602,  1604,  1606,  1610,  1614,  1616,
    1618,  1620,  1623,  1625,  1628,  1631,  1633,  1636,  1639,  1642,
    1645,  1648,  1651,  1654,  1656,  1659,  1662,  1664,  1667,  1670,
    1673,  1676,  1679,  1681,  1683,  1685,  1687,  1689,  1691,  1693,
    1695,  1697,  1700,  1704,  1709,  1711,  1714,  1718,  1720,  1722,
    1724,  1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,
    1744,  1746,  1748,  1750,  1752,  1754,  1756,  1759,  1762,  1766,
    1768,  1773,  1778,  1782,  1787,  1789,  1793,  1795,  1799,  1801,
    1803,  1807,  1811,  1813,  1815,  1817,  1819,  1821,  1826,  1835,
    1841,  1851,  1861,  1872,  1874,  1877,  1879,  1882,  1889,  1890,
    1892,  1896,  1900,  1901,  1903,  1905,  1907,  1910,  1913,  1914,
    1916,  1918,  1920,  1923,  1926,  1928,  1930,  1932,  1934,  1936,
    1938,  1940,  1942,  1944,  1946,  1948,  1952,  1956,  1959,  1963,
    1967,  1970,  1972,  1974,  1976,  1978,  1980,  1982,  1984,  1989,
    1993,  2001,  2005,  2013,  2018,  2023,  2027,  2035,  2039,  2047,
    2050,  2052,  2055,  2059,  2061,  2063,  2065,  2067,  2069,  2073,
    2077,  2079,  2081,  2083,  2085,  2089,  2091,  2093,  2095,  2097,
    2099,  2101,  2103,  2105,  2107,  2109,  2111,  2113,  2117,  2119,
    2123,  2128,  2133,  2137,  2141,  2145,  2149,  2154,  2159,  2163,
    2168,  2175,  2180,  2187,  2192,  2196,  2201,  2208,  2215,  2220,
    2227,  2234,  2239,  2241,  2244,  2246,  2248,  2250,  2255,  2261,
    2268,  2272,  2276,  2280,  2284,  2290,  2298,  2306,  2312,  2318,
    2324,  2332,  2340,  2346,  2352,  2356,  2360,  2366,  2374,  2380,
    2388,  2390,  2395,  2399,  2405,  2407,  2410,  2414,  2418,  2420,
    2424,  2427,  2428,  2430,  2432,  2435,  2437,  2441,  2443,  2447,
    2449,  2454,  2456,  2459,  2463,  2464,  2466,  2467,  2469,  2474,
    2477,  2481,  2483,  2484,  2486,  2491,  2492,  2494,  2497,  2499,
    2503,  2504,  2506,  2509,  2512,  2514,  2515,  2517,  2518,  2520,
    2522,  2524,  2526,  2528,  2530,  2532,  2536,  2540,  2542,  2544,
    2546,  2549,  2553,  2555,  2557,  2559,  2561,  2563,  2565,  2567,
    2569,  2572,  2575,  2577,  2579,  2582,  2585,  2589,  2591,  2594,
    2597,  2603,  2606,  2608,  2610,  2611,  2614,  2616,  2620,  2625,
    2626,  2629,  2630,  2633,  2638,  2643,  2647,  2650,  2654,  2656,
    2660,  2661,  2663,  2665,  2668,  2671,  2674,  2677,  2679,  2682,
    2685,  2688,  2691,  2695,  2698,  2702,  2706,  2711,  2714,  2717,
    2719,  2721,  2725,  2728,  2732,  2735,  2739,  2742,  2746,  2750,
    2754,  2760,  2766,  2772,  2781,  2787,  2791,  2797,  2805,  2809,
    2813,  2817,  2819,  2821,  2823,  2825,  2827,  2829,  2831,  2833,
    2835,  2837,  2839,  2841,  2843,  2845,  2847,  2849,  2851,  2853,
    2855,  2857,  2859,  2861,  2863,  2865,  2867,  2869,  2871,  2873,
    2875,  2877,  2879,  2881,  2883,  2885,  2887,  2889,  2891,  2893,
    2895,  2897,  2899,  2901,  2903,  2905,  2907,  2909,  2911,  2913,
    2915,  2917,  2919,  2921,  2923,  2925,  2927,  2929,  2931,  2933,
    2935,  2937,  2939,  2941,  2943,  2945,  2947,  2949,  2951,  2953,
    2955,  2957,  2959,  2961,  2963,  2965,  2967,  2969,  2971,  2973,
    2975,  2977,  2979,  2981,  2983,  2985,  2987,  2989,  2991,  2993,
    2995,  2997,  2999,  3001,  3003,  3005,  3007,  3009,  3011,  3013,
    3015,  3017,  3019,  3021,  3023,  3025,  3027,  3029,  3031,  3033,
    3035,  3037,  3039,  3041,  3043,  3045,  3047,  3049,  3051,  3053,
    3055,  3057,  3059,  3061,  3063,  3065,  3067,  3069,  3071,  3073,
    3075,  3077,  3079,  3081,  3083,  3085,  3087,  3089,  3091,  3093,
    3095,  3097,  3099,  3101,  3103,  3105,  3107,  3109,  3111,  3113,
    3115,  3117,  3119,  3121,  3123,  3125,  3127,  3129,  3131,  3133,
    3135,  3137,  3139,  3141,  3143,  3145,  3147,  3149,  3151,  3153,
    3155,  3157,  3159,  3161,  3163,  3165,  3167,  3169,  3171,  3173,
    3175,  3177,  3179,  3181,  3183,  3185,  3187,  3189,  3191,  3193,
    3195,  3197,  3199,  3201,  3203,  3205,  3207,  3209,  3211,  3213,
    3215,  3217,  3219,  3221,  3223,  3225,  3227,  3229,  3231,  3233,
    3235,  3237,  3239,  3241,  3243,  3245,  3247,  3249,  3251,  3253,
    3255,  3257,  3259,  3261,  3263,  3265,  3267
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   841,   841,   842,   846,   850,   856,   860,   864,   870,
     876,   884,   890,   899,   904,   910,   916,   922,   930,   935,
     943,   951,   959,   968,   973,   979,   985,   994,  1002,  1009,
    1015,  1024,  1025,  1026,  1027,  1028,  1031,  1032,  1033,  1034,
    1035,  1036,  1037,  1038,  1041,  1046,  1052,  1058,  1064,  1069,
    1075,  1080,  1086,  1091,  1097,  1102,  1107,  1112,  1118,  1120,
    1122,  1130,  1135,  1143,  1151,  1160,  1167,  1175,  1181,  1187,
    1193,  1200,  1208,  1219,  1226,  1233,  1241,  1248,  1254,  1263,
    1264,  1265,  1266,  1267,  1268,  1269,  1270,  1273,  1279,  1286,
    1293,  1301,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,
    1317,  1318,  1321,  1335,  1341,  1347,  1354,  1360,  1367,  1372,
    1378,  1384,  1396,  1408,  1421,  1426,  1434,  1442,  1451,  1456,
    1463,  1468,  1475,  1480,  1488,  1493,  1500,  1506,  1515,  1516,
    1519,  1533,  1546,  1561,  1574,  1579,  1584,  1589,  1595,  1602,
    1610,  1615,  1623,  1631,  1639,  1647,  1657,  1661,  1667,  1671,
    1678,  1687,  1698,  1704,  1711,  1716,  1723,  1730,  1739,  1749,
    1759,  1769,  1784,  1800,  1804,  1809,  1814,  1818,  1823,  1828,
    1833,  1841,  1848,  1855,  1868,  1869,  1870,  1871,  1872,  1873,
    1874,  1875,  1876,  1877,  1878,  1879,  1880,  1883,  1888,  1895,
    1911,  1917,  1923,  1930,  1937,  1946,  1955,  1964,  1973,  1984,
    1990,  1996,  2002,  2014,  2019,  2025,  2037,  2050,  2070,  2076,
    2083,  2092,  2099,  2105,  2110,  2122,  2134,  2135,  2136,  2137,
    2138,  2139,  2142,  2143,  2144,  2145,  2146,  2147,  2148,  2149,
    2150,  2151,  2152,  2153,  2156,  2168,  2174,  2179,  2185,  2190,
    2195,  2201,  2210,  2220,  2232,  2244,  2250,  2251,  2252,  2255,
    2256,  2257,  2258,  2259,  2262,  2269,  2277,  2282,  2291,  2300,
    2307,  2314,  2324,  2334,  2344,  2354,  2364,  2374,  2384,  2394,
    2404,  2413,  2423,  2433,  2445,  2451,  2457,  2463,  2469,  2477,
    2485,  2493,  2501,  2511,  2517,  2526,  2527,  2531,  2538,  2542,
    2547,  2550,  2554,  2558,  2564,  2570,  2576,  2582,  2590,  2594,
    2602,  2610,  2618,  2626,  2636,  2642,  2648,  2656,  2662,  2670,
    2674,  2682,  2688,  2694,  2700,  2709,  2718,  2727,  2738,  2742,
    2748,  2754,  2762,  2768,  2777,  2788,  2794,  2802,  2806,  2815,
    2821,  2827,  2835,  2841,  2847,  2855,  2861,  2867,  2875,  2881,
    2888,  2898,  2905,  2915,  2921,  2929,  2935,  2944,  2950,  2958,
    2964,  2973,  2979,  2987,  2993,  2997,  3003,  3008,  3014,  3018,
    3027,  3033,  3042,  3052,  3051,  3064,  3073,  3082,  3093,  3097,
    3108,  3112,  3118,  3121,  3127,  3131,  3137,  3141,  3145,  3151,
    3155,  3161,  3167,  3173,  3181,  3185,  3189,  3195,  3199,  3205,
    3213,  3217,  3225,  3229,  3237,  3241,  3249,  3253,  3261,  3265,
    3271,  3275,  3281,  3285,  3289,  3293,  3301,  3302,  3303,  3306,
    3311,  3317,  3321,  3325,  3329,  3333,  3337,  3343,  3347,  3351,
    3357,  3361,  3365,  3369,  3378,  3386,  3392,  3400,  3404,  3408,
    3414,  3418,  3426,  3434,  3452,  3458,  3468,  3472,  3478,  3479,
    3482,  3488,  3496,  3502,  3512,  3518,  3526,  3530,  3534,  3538,
    3542,  3548,  3554,  3560,  3564,  3570,  3574,  3583,  3587,  3591,
    3597,  3601,  3609,  3610,  3613,  3617,  3623,  3627,  3631,  3635,
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
    4243,  4247,  4251,  4257,  4263,  4269,  4277,  4291,  4295,  4299,
    4303,  4307,  4311,  4317,  4323,  4331,  4337,  4343,  4347,  4351,
    4355,  4359,  4363,  4367,  4371,  4375,  4379,  4385,  4391,  4397,
    4401,  4405,  4411,  4416,  4422,  4428,  4432,  4437,  4443,  4447,
    4453,  4459,  4463,  4471,  4477,  4481,  4487,  4496,  4505,  4511,
    4517,  4525,  4531,  4537,  4543,  4549,  4553,  4559,  4565,  4569,
    4577,  4583,  4589,  4595,  4603,  4607,  4613,  4619,  4623,  4629,
    4633,  4639,  4645,  4652,  4660,  4665,  4671,  4677,  4685,  4691,
    4698,  4704,  4713,  4719,  4725,  4731,  4740,  4747,  4753,  4759,
    4768,  4775,  4779,  4785,  4790,  4797,  4801,  4807,  4811,  4817,
    4821,  4827,  4831,  4839,  4850,  4853,  4859,  4862,  4868,  4874,
    4882,  4886,  4892,  4895,  4901,  4911,  4914,  4920,  4930,  4936,
    4944,  4947,  4953,  4957,  4961,  4967,  4970,  4976,  4979,  4985,
    4989,  4993,  4997,  5001,  5007,  5013,  5023,  5033,  5037,  5041,
    5047,  5053,  5061,  5065,  5069,  5073,  5077,  5081,  5085,  5089,
    5095,  5099,  5103,  5107,  5113,  5119,  5127,  5135,  5139,  5145,
    5155,  5166,  5172,  5176,  5182,  5185,  5191,  5196,  5203,  5211,
    5214,  5220,  5224,  5230,  5239,  5246,  5254,  5258,  5264,  5270,
    5278,  5281,  5287,  5292,  5302,  5310,  5320,  5326,  5330,  5336,
    5340,  5344,  5350,  5356,  5360,  5364,  5368,  5374,  5382,  5392,
    5396,  5402,  5408,  5412,  5418,  5422,  5428,  5432,  5438,  5445,
    5451,  5460,  5466,  5476,  5482,  5488,  5509,  5533,  5557,  5561,
    5565,  5571,  5574,  5575,  5576,  5577,  5578,  5579,  5580,  5581,
    5582,  5583,  5584,  5585,  5586,  5587,  5588,  5589,  5590,  5591,
    5592,  5593,  5594,  5595,  5596,  5599,  5600,  5601,  5602,  5603,
    5604,  5605,  5606,  5607,  5608,  5609,  5610,  5611,  5612,  5613,
    5614,  5615,  5616,  5617,  5618,  5619,  5620,  5621,  5622,  5623,
    5624,  5625,  5626,  5627,  5628,  5629,  5630,  5631,  5632,  5633,
    5634,  5635,  5636,  5637,  5638,  5639,  5640,  5641,  5642,  5643,
    5644,  5645,  5646,  5647,  5648,  5649,  5650,  5651,  5652,  5653,
    5654,  5655,  5656,  5657,  5658,  5659,  5660,  5661,  5662,  5663,
    5664,  5665,  5666,  5667,  5668,  5669,  5670,  5671,  5672,  5673,
    5674,  5675,  5676,  5677,  5678,  5679,  5680,  5681,  5682,  5683,
    5684,  5685,  5686,  5687,  5688,  5689,  5690,  5691,  5692,  5693,
    5694,  5695,  5696,  5697,  5698,  5699,  5700,  5701,  5702,  5703,
    5704,  5705,  5706,  5707,  5708,  5709,  5710,  5711,  5712,  5713,
    5714,  5715,  5716,  5717,  5718,  5719,  5720,  5721,  5722,  5723,
    5724,  5725,  5726,  5727,  5728,  5729,  5730,  5731,  5732,  5733,
    5734,  5735,  5736,  5737,  5738,  5739,  5740,  5741,  5742,  5743,
    5744,  5745,  5746,  5747,  5748,  5749,  5750,  5751,  5752,  5753,
    5754,  5755,  5756,  5757,  5758,  5759,  5760,  5761,  5762,  5763,
    5764,  5765,  5766,  5767,  5768,  5769,  5770,  5771,  5772,  5773,
    5774,  5775,  5776,  5777,  5778,  5779,  5780,  5781,  5782,  5783,
    5784,  5785,  5786,  5787,  5788,  5789,  5790,  5791,  5792,  5793,
    5794,  5795,  5796,  5797,  5798,  5799,  5802
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
  const int xquery_parser::yylast_ = 17585;
  const int xquery_parser::yynnts_ = 324;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 618;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 334;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 588;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17656 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 5804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"

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

