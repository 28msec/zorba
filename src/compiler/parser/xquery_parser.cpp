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
      case 421: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "PostfixExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2706 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2715 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2724 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2733 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2742 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2751 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2760 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 646: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2769 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 647: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2778 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 648: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2787 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 649: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 652: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2823 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 653: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2832 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 654: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2841 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 657: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2850 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 658: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2859 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 659: /* "EQNAME" */

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
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2180 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2185 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2191 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2196 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2201 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2207 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2216 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2226 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2236 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2247 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2265 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2272 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2280 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2284 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2292 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2300 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
    }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2305 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2312 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2319 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2329 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 265:

/* Line 690 of lalr1.cc  */
#line 2339 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 266:

/* Line 690 of lalr1.cc  */
#line 2349 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 267:

/* Line 690 of lalr1.cc  */
#line 2359 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 268:

/* Line 690 of lalr1.cc  */
#line 2369 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 269:

/* Line 690 of lalr1.cc  */
#line 2379 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 270:

/* Line 690 of lalr1.cc  */
#line 2389 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 271:

/* Line 690 of lalr1.cc  */
#line 2399 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 272:

/* Line 690 of lalr1.cc  */
#line 2409 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2418 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 274:

/* Line 690 of lalr1.cc  */
#line 2428 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 275:

/* Line 690 of lalr1.cc  */
#line 2438 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 276:

/* Line 690 of lalr1.cc  */
#line 2450 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2456 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2462 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2468 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2474 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2482 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2490 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2498 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2506 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2516 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2522 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2532 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2536 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2543 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2547 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2555 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2559 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2563 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2569 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2575 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2581 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2587 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 2595 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 2599 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 2607 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2615 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2623 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(1) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, NULL);
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2631 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarRef* varRef = dynamic_cast<VarRef*>((yysemantic_stack_[(2) - (1)].expr));
      if (varRef != NULL)
        (yyval.node) = new GroupSpec(LOC((yyloc)), varRef, NULL, NULL, static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
      else
        (yyval.node) = new GroupSpec(LOC((yyloc)), NULL, NULL, (yysemantic_stack_[(2) - (1)].expr), static_cast<GroupCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2641 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2647 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2653 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2661 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2667 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2675 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2679 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2687 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2693 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 2699 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 2705 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2714 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2723 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2732 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2743 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2747 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 2753 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2759 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2767 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2773 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2782 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2820 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2826 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2832 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2840 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2846 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2852 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2860 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2866 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2872 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2880 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 2886 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2893 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2903 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2910 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2920 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2926 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 2934 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2940 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2949 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 2955 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2963 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2969 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2978 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 2984 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 2992 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 2998 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3002 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3008 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3013 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3019 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3023 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3032 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3038 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3047 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3056 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            driver.getXqueryLexer()->interpretAsLessThan();
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3060 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3069 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3078 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3087 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3098 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3102 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3113 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3117 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3122 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3126 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3132 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3136 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3142 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3146 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3150 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3156 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3160 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3166 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3172 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3178 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3186 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3190 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3194 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3200 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3204 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3210 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3218 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3222 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3230 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3234 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3242 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3246 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3254 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3258 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3266 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3270 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3276 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3280 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3286 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3290 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3294 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3298 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3311 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3316 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3322 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3326 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3330 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3334 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3338 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3342 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3348 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3352 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3356 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3362 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3366 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3370 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3374 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3383 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3391 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 3397 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 3405 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 3409 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 3413 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 3419 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 3423 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 3431 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;
      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);
      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 3439 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
        driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_AXIS_STEP));
      }
      if ((yyval.expr) == NULL)
        (yyval.expr) = (rpe ?
              new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)) :
              (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 3459 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
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

  case 438:

/* Line 690 of lalr1.cc  */
#line 3475 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 3479 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 3489 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 3495 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 3503 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 3509 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 3519 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 3525 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 3533 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 3537 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 3541 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 3545 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 3549 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 3555 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 3561 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 3567 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 3571 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 3577 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 3581 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 3590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 3594 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 3598 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 3604 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 3608 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 3620 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 3624 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 3630 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 3634 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 3638 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 3642 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 3648 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 3652 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 3656 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 3660 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 3666 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      PredicateList* pl = new PredicateList( LOC((yyloc)) );
      pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.node) = pl;
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 3672 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if (PredicateList* pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)))
        pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 3680 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 3702 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 3706 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 3712 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 3719 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 3726 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 3735 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 3741 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 3745 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 3751 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 3758 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 3764 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 3770 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FunctionCall(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL);
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
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

  case 506:

/* Line 690 of lalr1.cc  */
#line 3792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList* al = new ArgList(LOC((yyloc)));
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 3798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if (ArgList* al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)))
        al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 3804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 3810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 3818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 3822 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 3828 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 3834 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 3853 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
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

  case 521:

/* Line 690 of lalr1.cc  */
#line 3877 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
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

  case 523:

/* Line 690 of lalr1.cc  */
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

  case 524:

/* Line 690 of lalr1.cc  */
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

  case 525:

/* Line 690 of lalr1.cc  */
#line 3939 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 3945 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 3954 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 3960 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 3969 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 3979 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 3984 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 3990 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 3994 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4000 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4006 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4012 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4019 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4027 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4031 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4037 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4043 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4049 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4056 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4065 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4069 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4075 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4079 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4085 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4089 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4093 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4098 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4105 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4109 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4113 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4117 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4123 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4128 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4134 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4140 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4147 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4153 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 4158 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 4163 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 4168 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 4173 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 4178 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 4186 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 4192 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 4196 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 4202 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 4206 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 4212 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 4218 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 4224 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 4228 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 4234 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 4238 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 4244 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 4250 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 4254 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 4258 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 4264 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 4270 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 4276 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 4284 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 589:

/* Line 690 of lalr1.cc  */
#line 4298 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 4302 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 4306 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 4310 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 4314 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 4318 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 4324 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 4330 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 4338 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 4344 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 4350 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 4354 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 4358 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 4362 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 4366 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 4370 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 4374 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 4378 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 4382 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 4386 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 4392 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 4398 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 4404 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 4408 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 4412 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 4418 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 4423 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 4429 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 4435 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 4439 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(4) - (3)].expr), (yylocation_stack_[(4) - (3)]));
            (yyval.node) = new PITest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 4444 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 4450 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 4454 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 4460 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 4466 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 4470 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 4478 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 4484 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 4488 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 4494 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 4503 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 4512 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 4518 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 4524 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 4532 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 4538 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 4544 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 4550 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 4556 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 4560 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 4566 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 4572 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 4576 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 4584 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 4590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 4596 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 4602 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 4610 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 4614 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 4620 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 4626 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 4630 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 4636 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 4640 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 4646 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 4652 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 4659 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 4667 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 4672 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 4678 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 4684 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 4692 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 4698 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 4705 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 4711 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 4720 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 4726 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 4732 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 4738 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 4747 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 4754 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 4760 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 4766 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 4775 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 4782 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 4786 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 4792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 4797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 4804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 4808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 4814 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 4818 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 4824 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 4828 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 4834 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 4838 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 4846 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 4856 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 4860 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 4865 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 4869 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 4875 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 4881 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 4889 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 4893 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 4898 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 4902 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 4908 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 4917 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 4921 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 4927 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 4937 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 4943 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 4950 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 4954 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 4960 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 4964 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 4968 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 4973 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 4977 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 4982 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 4986 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 4992 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 4996 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 5000 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 5004 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 5008 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 5014 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 5020 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 5030 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 5040 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 5044 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 5048 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 5054 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 5060 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 5068 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 5072 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 5076 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 5080 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 5084 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 5088 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 5092 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 5096 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 5102 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 5106 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 5110 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 5114 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 5120 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 5126 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 5134 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 5142 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 5146 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 5152 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 742:

/* Line 690 of lalr1.cc  */
#line 5162 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 743:

/* Line 690 of lalr1.cc  */
#line 5173 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 5179 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 5183 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 5188 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 5192 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 5198 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 5203 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 5210 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 5217 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 5221 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 5227 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 5231 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 5237 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 5246 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 5253 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 5261 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 5265 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 5271 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 5277 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 5284 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 5288 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 5294 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 5299 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 5309 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 5317 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 5327 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 5333 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 5337 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 5343 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 5347 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 5351 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 5357 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 5363 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 5367 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 5371 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 5375 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 5381 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 5389 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 5399 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 5403 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 5409 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 5415 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 5419 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 5425 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 5429 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 5435 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 5439 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 5445 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 5452 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 5458 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 5467 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 5473 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 795:

/* Line 690 of lalr1.cc  */
#line 5483 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 5489 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 5495 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 798:

/* Line 690 of lalr1.cc  */
#line 5516 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 799:

/* Line 690 of lalr1.cc  */
#line 5540 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 800:

/* Line 690 of lalr1.cc  */
#line 5564 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 5568 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 5572 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 5581 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 5582 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 5583 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 5584 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 5585 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 5586 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 5587 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 5588 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 5589 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 5590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 5591 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 5592 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 5593 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 5594 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 5595 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 5596 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 5597 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 5598 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 5599 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 5600 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 5601 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 5602 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 5606 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 5607 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 5608 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 5609 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 5610 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 5611 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 5612 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 5613 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 5614 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 5615 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 5616 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 5617 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 5618 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 5619 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 5620 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 5621 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 5622 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 5623 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 5624 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 5625 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 5626 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 5627 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 5628 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 5629 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 5630 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 5631 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 5632 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 5633 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 5634 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 5635 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 5636 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 5637 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 5638 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 5639 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 5640 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 5641 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 5643 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 5644 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 5645 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 5646 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 5647 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 5648 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 5649 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 5650 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 5651 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 5652 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 5653 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 5654 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 5655 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 5656 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 5657 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 5658 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 5659 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 5660 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 5661 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 5662 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 5663 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 5664 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 5665 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 5666 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 5667 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 5668 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 5669 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 5670 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 5671 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 5672 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 5673 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 5674 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 5675 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 5676 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 5677 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 5678 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 5679 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 5680 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 5681 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 5682 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 5683 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 5684 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 5685 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 5686 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 5687 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 5688 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 5689 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 5690 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 5691 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 5692 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 5693 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 5694 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 5695 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 5696 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 5697 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 5698 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 5699 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 5700 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 5701 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 5702 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 5703 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 5704 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 5705 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 5706 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 5707 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 5708 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 5709 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 5710 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 5711 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 5712 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 5713 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 5714 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 5715 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 5716 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 5717 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 5718 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 5719 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 5720 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 5721 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 5722 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 5723 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 5724 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 5725 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 5726 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 5727 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 5728 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 5729 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 5730 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 5731 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 5732 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 5733 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 5734 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 5735 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 5736 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 5737 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 5738 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 5739 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 5740 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 5741 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 5742 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 5743 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 5744 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 5745 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 5746 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 5747 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 5748 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 5749 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 5750 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 5751 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 5752 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 5753 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 5754 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 5755 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 5756 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 5757 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 5758 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 5759 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 5760 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 5761 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 5762 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 5763 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 5764 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 5765 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 5766 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 5767 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 5768 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 5769 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 5770 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 5771 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 5772 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 5773 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 5774 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 5775 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 5776 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 5777 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 5778 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 5779 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 5780 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 5781 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 5782 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 5783 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 5784 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 5785 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 5786 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 5787 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 5788 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 5789 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 5790 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 5791 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 5792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 5793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 5794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 5795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 5796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 5797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 5798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1021:

/* Line 690 of lalr1.cc  */
#line 5799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1022:

/* Line 690 of lalr1.cc  */
#line 5800 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1023:

/* Line 690 of lalr1.cc  */
#line 5801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1024:

/* Line 690 of lalr1.cc  */
#line 5802 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1025:

/* Line 690 of lalr1.cc  */
#line 5803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1026:

/* Line 690 of lalr1.cc  */
#line 5804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1027:

/* Line 690 of lalr1.cc  */
#line 5805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1028:

/* Line 690 of lalr1.cc  */
#line 5808 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12098 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1454;
  const short int
  xquery_parser::yypact_[] =
  {
      4351, -1454, -1454, -1454, -1454,  5905,  5905,  5905,  5905, -1454,
   -1454,   187,   512, -1454,  1686,   301, -1454, -1454, -1454,    20,
   -1454, -1454, -1454,   493,   581,   721,  2551,   599,   638,   847,
   -1454,   -18, -1454,   665, -1454, -1454, -1454, -1454, -1454,   826,
   -1454,   672,   683, -1454, -1454, -1454, -1454,   731, -1454,   827,
   -1454,   728,   786, -1454,   363, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,   595,
     806, -1454, -1454, -1454, -1454,   692, 12105, -1454, -1454, -1454,
     814, -1454, -1454, -1454,   843, -1454,   850,   855, -1454, -1454,
   15976, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,   879,
   -1454, -1454,   882,   889, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454,  4975,  8385,  8695, 15976, -1454, -1454,   862, -1454, -1454,
   -1454, -1454,   866, -1454, -1454,   901, 15976, -1454, 13016,   909,
     912, -1454, -1454, -1454,   914, -1454, -1454, 11485, -1454, -1454,
   -1454, -1454, -1454, -1454,   892, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454,   128,   833, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454,   199,   894,   323, -1454,   -90,   -84, -1454,
   -1454, -1454, -1454, -1454, -1454,   933, -1454,   816,   818,   812,
   -1454, -1454,   898,   902, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454,  9005,  9315, -1454,
     747, -1454, -1454, -1454, -1454, -1454,  4663,  6215,  1065, -1454,
    6525, -1454, -1454,   133,    93, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,    96,
   -1454, -1454, -1454, -1454, -1454, -1454,   456, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454,  5905, -1454, -1454, -1454, -1454,
     299, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
     233, -1454,   876, -1454, -1454, -1454,   616, -1454,   122, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454,   903,   975, -1454,   906,
     822,   972,     2,   622,   746,   208, -1454,  1023,   874,   973,
     974,  9935, -1454,   885, -1454, -1454,   305, -1454, -1454, 11795,
   -1454,   327, -1454,   924, 12105, -1454,   924, 12105, -1454, -1454,
   -1454,   817, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,   923,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454,    22, -1454, -1454,
   -1454, -1454, -1454,   900, -1454,  5905,   904,   908,   910,  5905,
     503,   503,  1052,   529,   579,   685, 16564, 15976,   -12,  1039,
   15976,   934,   971,   694, 15976,   788,   849, 15976, 15976,   789,
     247,    51, -1454, -1454, -1454, 15976,  5905,   911,  5905,   165,
   10245, 13312, 15976,    28,   943, 10245,  1100,   162,    79, 15976,
     983,   960,   997, -1454,   919, 10245, 13608, 15976, 15976, 15976,
    5905,   921, 10245, 10245, 15976,  5905,   962,   966, -1454, -1454,
   -1454, 10245, 13904,   964, -1454,   965, -1454, -1454, -1454, -1454,
     967, -1454,   968, -1454, -1454, -1454, -1454, -1454,   969, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, 15976, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454,   984, 15976, -1454, -1454, -1454,   944,  5285,  1009,   510,
     979,   980,   981, 15976,  5905, -1454,   978,   258, -1454,   616,
   -1454,   127,  1104, 10245, 10245, -1454,    83, -1454, -1454,  1135,
   -1454, -1454, -1454, -1454, 10245,   939, -1454,  1124, 10245, 10245,
   16276, 10245, 10245, 10245, 10245, 16276, 10245,   925,   927, 15976,
     970,   976, 10245, 10245,  4975,   913, -1454,    57, -1454,    52,
   10245,  6215, -1454, -1454, -1454, -1454, -1454,  1686,   847,   101,
     117,  1152,  6835,  3100,  7145,  3421,   843, -1454, -1454,   386,
     843, -1454, 10245,  4041, -1454,  1040,   678,   -18,   993,   992,
     998, -1454, 10245, -1454, -1454,  5905, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454,   883,   887, 15976,  1044, 10555, 10555, 10555,
   -1454, 10555, 10555, -1454, 10555, -1454, 10555, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, 10555, 10555,  1098, 10555, 10555, 10555,
   10555, 10555, 10555, 10555, 10555, 10555, 10555, 10555, 10555,   945,
    1082,  1085,  1088, -1454, -1454, -1454, 11175,  5905, -1454, -1454,
   11485, 11485, 10245,   924, -1454, -1454,   924, -1454,  7765,   924,
     999,  1037,  8075, -1454, -1454, -1454, -1454,   308, -1454,   329,
   -1454, -1454, -1454, -1454, -1454, -1454,  1081,  1083,   599,  1160,
   -1454, -1454, 16564,  1060,   668, 15976,  1031,  1032,  1060,  1052,
    1066,  1062, -1454, -1454, -1454,   170,   950,  1103,   905, 15976,
    1056, 10245,  1084, 15976, 15976, -1454,  1067,  1017, -1454,  1018,
     965,   683, -1454,  1019,  1021,   314, -1454,   342,   369,  1097,
   -1454,    37, 15976,  1114,   379, -1454,  5905, -1454,   161, -1454,
   15976,  1113,  1167, 15976,  1052,  1116,   601, 15976, 10245,   -18,
   -1454,   362,  1027, -1454,  1028,  1030,  1033,     7, -1454,    59,
    1034, -1454,   166,   195,  1068, -1454,  1035,  5905,  5905,   402,
   -1454,   392,   394,   676, 10245,   355, -1454, -1454, 10245, 10245,
   -1454, 10245, 10245, 10245, -1454, 10245, -1454, 10245, -1454, 15976,
    1104, -1454,    17,   437,   459, -1454, -1454, -1454,   466, -1454,
      18, -1454, -1454,  1069,  1070,  1071,  1072,  1073,   817,    22,
     359,   458,   -15,   -13,  1133,   515,   994,  1004,  1001,    35,
   -1454,  1087, -1454, -1454,  1043,   212,  5285,   467, 12415,   913,
   -1454, -1454, -1454,  1002, -1454,   133,   793,  1201,   698, -1454,
   -1454,   123, -1454, -1454, -1454,   135, -1454,   124, -1454, -1454,
   -1454, -1454, -1454,  3731, -1454, -1454, -1454, 15976,  1074, 10245,
   10865, -1454, -1454, -1454, -1454, -1454,  1097, 15976,    50,   975,
   -1454, -1454, -1454, -1454, -1454, 10555, -1454, -1454, -1454,    62,
   -1454,   622,   622,    10,   746,   746,   746,   746,   208,   208,
   -1454, -1454, 15088, 15088, 15976, 15976, -1454,  1053, -1454, -1454,
     373, -1454, -1454, -1454, -1454,   416, -1454, -1454, -1454,   420,
     503, -1454, -1454,   725,   771,   785, -1454,   599, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,  1060, -1454,
    1105, 15384,  1093, 10245, -1454, -1454, -1454,  1145,  1052,  1052,
    1060, -1454,   770,  1052,   687, 15976,   -91,   339,  1211, -1454,
   -1454,   956,   596, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454,   170,    60,  1020,   661, 10245, -1454,
   15976,  1150,   947,  1052, -1454, -1454, -1454, -1454,  1094, 15976,
   -1454, 15976, -1454, 15680,  1121, 15088,  1132, 10245,    81,  1106,
      36,  1145, 15088,  1134,  1157,  1076,  1058,  1125,  1052,  1096,
    1128,  1165,  1052, 10245,   -31, -1454, -1454, -1454,  1110, -1454,
   -1454, -1454, -1454,  1146, 10245, 10245,  1118, -1454,  1166,  1168,
    5905, -1454,  1086,  1089,  1117, 15976, -1454, 15976, -1454, 10245,
    1129,  1078, 10245, -1454,  1154,   221,   222,   231,  1242, -1454,
     533, -1454,   193,  1126, -1454, -1454,  1251, -1454,   774, 10245,
   10245, 10245,   783, 10245, 10245, 10245, 10245, 10245, 10245, 10245,
   10245, 10245, 16276,  1163, 10245, 10245, -1454,  7455,   443,  1038,
   -1454,     1, -1454, 10245,   136,   210,   124,  7145,  3421,  7145,
    1204, -1454, -1454, 10245,   798,  1178, -1454, 15976,  1181,  1183,
   -1454,   464,  1041, -1454, -1454,   739,    50, -1454, 10245,    62,
     538,   671, -1454,  1007,   180,  1036,  1042, -1454, -1454,   849,
   -1454,  1029,   -72,  1141,  1142, 15384,  1143,  1147,  1153,  1155,
    1158, -1454,   609, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454,  1162, -1454, -1454, -1454, -1454,  9625, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,   787, -1454,
    1273,   815, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454,  1025, -1454, -1454,  1284, -1454, -1454, -1454, -1454, -1454,
     610,  1286, -1454,    91, -1454, -1454, -1454,   964,   581,   665,
     967,   672,   968,   969, -1454,  1147,  1153,  1155, -1454,   609,
     609, 11175,  1046,  1012, -1454,  1145,    60,  1095,  1131,  5905,
    1136,  1138,  1182,  1144,  1151, 15976, -1454,   535, -1454, 15976,
   -1454, 10245,  1180, 10245,  1206, 10245,   202,  1189, -1454, -1454,
   -1454, 15088, -1454,  5905,  1052,  1232, -1454, -1454, -1454,  1052,
    1232, -1454, 10245,  1198,  5905, 15976, -1454, -1454, 10245, 10245,
     654, -1454,   322,   751, -1454, 14200,   772, -1454,   778, -1454,
    1161, -1454, -1454,  5905,  1159,  1164, -1454, 10245, -1454, -1454,
   10245,  1149,  1166,  1241, -1454,  1216, -1454,   578, -1454, -1454,
    1337, -1454, -1454,  5905, 15976, -1454,   737, -1454, -1454, -1454,
    5905,  1171,  1120,  1122, -1454, -1454, -1454,  1123,  1139, -1454,
   -1454, -1454,  1253, -1454, -1454, -1454, -1454,  1127,   491, 15976,
    1179, -1454,  1200,  1209,  1210,  1215, -1454,   876,   616, 12415,
    1038, -1454,  5595, 12415, -1454, -1454,  1201,    63, -1454, -1454,
   -1454,  1178, -1454,  1052, -1454,   861, -1454,   383,  1264, -1454,
   10245,   717,  1052, -1454, 10865, 10245,  1226, -1454,  1256,  1257,
   10245, 15976,   917,  1299, -1454, -1454, -1454,   468,  1191, -1454,
      62,  1130, -1454, -1454,   -54, -1454,   546,   100,  1137,    62,
     546, 10555, -1454,   109, -1454, -1454, -1454, -1454, -1454, -1454,
      62,  1231,  1101,   950,   100, -1454, -1454,  1099,  1305, -1454,
   -1454, -1454, 12711,  1199,  1203,  1205,  1207,  1208,  1212,  1214,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454,  1361,   418,  1366,   418,  1140,  1289, -1454,
   -1454,  1228, 15976,  1148, -1454, -1454, 11175, -1454,  1218, -1454,
   -1454, -1454, -1454, -1454, -1454, 10245,  1255, -1454, -1454, 10245,
   -1454,   587, -1454, 10245,  1258, 10245, -1454,  1277,  1280,  1311,
    1052,  1232, -1454, 10245,  1225, -1454, -1454, -1454,  1179, -1454,
     322, 10245,  5905,  1179,   322, -1454, 15976,   634, -1454, 14496,
      23, -1454, 14792,  1179, -1454, -1454,  1229, -1454, -1454, -1454,
   -1454, 10245,   796,  1242, 15976,   780, -1454,  1234,  1242, 15976,
   -1454,  1235, -1454, 10245, 10245, 10245, 10245,  1107, 10245, 10245,
   -1454, 10245, 10245, 10245, 10245,  7455,   511, -1454, -1454, -1454,
   -1454, -1454,  1264, -1454, -1454, -1454, 10245,  1267, -1454, -1454,
   -1454, 10245, 15976, 15976, -1454,   805, -1454, 10245, -1454, -1454,
   -1454,  1236, 10555, -1454, -1454, -1454, -1454, -1454,    87, 10555,
   10555,   627, -1454,  1036, -1454,   561, -1454,  1042,    62,  1261,
   -1454, -1454,  1156, -1454, -1454, -1454, -1454,  1317,  1237, -1454,
     500, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,   560,
     560, -1454,   418, -1454, -1454,   518, -1454,  1386,   100,  1325,
    1238, 11175,    21,  1170,  1259, -1454, -1454, 10245, -1454, 10245,
    1278, -1454, 10245, -1454,  7455, 10245,  1052, -1454, -1454, -1454,
   10245, 10245, -1454, -1454, -1454,  7455,  7455,  1332, 15088,  5905,
   15976,   634, 15976, 10245, 15976,   634,  7455, -1454,   336,   295,
    1242, 15976, -1454,  1233,  1242, -1454, -1454, -1454, -1454, -1454,
   10245, -1454, -1454, -1454,   252,   357,   395, 10245, -1454, -1454,
    1181, 10245, -1454, -1454,  1374, -1454, -1454, -1454,   746, 10555,
   10555,    10,   584, -1454, -1454, -1454, -1454, -1454, -1454, 10245,
   -1454, 15088, -1454, 15088,  1336, -1454, -1454, -1454,  1403, -1454,
   -1454, -1454,  1169,  1329, -1454, -1454,  1331, -1454,   824, 15976,
    1321,  1217, 15976, 11175, -1454, -1454, 10245, -1454, -1454, -1454,
    1232, -1454, -1454, 15088, -1454, -1454, -1454,  1346, 10245,  1179,
   -1454,  1348,  7455, -1454, 15976,   588,   646, -1454,  1247,  1242,
   -1454,  1248, -1454,  1249,  1166,  1168,   475, -1454,  1181,  1327,
      10,    10, 10555,   490, -1454, -1454, 15088, -1454, -1454,  1325,
   11175, -1454,  1264,  1172, 15976,  1333,  1223,  1331, -1454,   634,
   15088,  5905, 15088,  1179, -1454, -1454,  1357,   625, -1454, -1454,
   -1454, -1454,  1270,   809, -1454, -1454, -1454,  1263, -1454,  7455,
     813, -1454, -1454, 15976,    10, -1454, -1454, -1454, -1454, -1454,
   10245,  1173, 15976,  1342,  5905,   634, -1454, -1454,   634, 10245,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454,  1343, -1454, -1454,
    1174,  1175, 15976, -1454, -1454, 10245,  7455, 15976,  1176, 10245,
    1177,  1179, 11175, -1454, 11175,  7455, -1454,  1265,  1184, 15976,
    1240,  1344, 15976,  1185, 11175, -1454
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       165,   469,   470,   805,   471,   168,   168,   168,     0,   828,
    1028,   120,   122,   636,   921,   930,   870,   833,   831,   807,
     922,   925,   877,   837,   808,   810,     0,   931,   812,   928,
     899,   879,   853,   809,   874,   875,   926,   923,   873,   814,
     929,   815,   816,   970,   982,   969,   871,   890,   884,   817,
     872,   819,   818,   971,   908,   909,   876,   850,   992,   993,
     994,   995,   996,   997,   998,   999,  1000,  1001,  1002,  1016,
    1023,   898,   894,   885,   864,   806,     0,   893,   901,   910,
    1017,   889,   495,   865,   866,   924,  1018,  1024,   886,   903,
       0,   501,   458,   497,   896,   830,   887,   888,   917,   891,
     907,   916,  1022,  1025,   836,   878,   919,   496,   906,   912,
     811,     0,     0,     0,     0,   405,   904,   915,   920,   918,
     897,   883,   972,   881,   882,  1019,     0,   404,     0,  1020,
    1026,   913,   867,   892,  1021,   212,   436,     0,   468,   914,
     895,   902,   911,   905,   973,   858,   863,   862,   861,   860,
     859,   820,   880,     0,   829,   927,   851,   963,   962,   964,
     835,   834,   854,   961,   813,   958,   966,   960,   959,   857,
     900,   956,   968,   967,   955,   855,   965,   977,   978,   975,
     976,   974,   821,   979,   980,   981,   947,   946,   933,   849,
     842,   940,   936,   852,   848,   948,   869,   838,   839,   832,
     841,   945,   944,   941,   937,   953,   954,   952,   943,   939,
     932,   840,   951,   950,   844,   846,   845,   938,   942,   934,
     847,   935,   843,   949,  1003,  1004,  1005,  1006,  1007,  1008,
     984,   985,   983,   989,   990,   991,   986,   987,   988,   856,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,     0,     0,   822,
     957,  1027,   824,   823,   825,   826,   165,   165,     0,     2,
     165,     9,    11,    23,     0,    28,    31,    36,    37,    38,
      39,    40,    41,    42,    32,    58,    59,    33,    34,     0,
      76,    79,    80,    35,    81,    82,     0,   118,    83,    84,
      85,    86,    18,   162,   163,   164,   171,   174,   488,   175,
       0,   176,   177,   178,   179,   180,   181,   182,   185,   186,
       0,   213,   221,   216,   249,   255,     0,   247,     0,   248,
     223,   217,   184,   218,   183,   219,   222,   356,   358,   360,
     370,   372,   376,   378,   381,   386,   389,   392,   394,   396,
     398,     0,   402,   409,   408,   410,     0,   427,   411,   432,
     435,   437,   440,   442,     0,   447,   444,     0,   455,   465,
     467,   441,   472,   479,   493,   480,   481,   482,   485,   486,
     483,   487,   510,   511,   484,   514,   516,   517,   518,   515,
     563,   564,   565,   566,   567,   568,   569,   464,   608,     0,
     599,   607,   606,   605,   604,   601,   603,   600,   602,   494,
      43,   224,   225,   227,   226,   228,   220,   490,   491,   492,
     489,   230,   233,   229,   231,   232,   466,   804,   827,   921,
     930,   928,   829,     0,   166,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   278,   279,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   460,   463,
     450,     0,     0,   807,   837,   810,   868,   931,   812,   879,
     814,   890,   817,   819,   818,   908,  1016,  1023,   806,  1017,
     866,  1018,  1024,   891,  1022,  1025,   915,   972,  1019,  1020,
    1026,  1021,   973,   961,   958,   960,   959,   855,   977,   978,
     975,   821,   979,   957,   456,   804,   448,     0,   193,   449,
     452,   807,   808,   810,   809,   814,   815,   816,   817,   806,
     813,   498,     0,   454,   453,   188,     0,     0,   213,     0,
     812,   819,   818,     0,   168,   784,   979,     0,   221,     0,
     499,     0,   530,     0,     0,   459,     0,   430,   431,     0,
     462,   461,   451,   434,     0,     0,   559,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   786,     0,   788,     0,
       0,   165,     3,     4,     1,    10,    12,     0,     0,     0,
       0,     6,   165,     0,   165,     0,     0,   119,   172,     0,
       0,   191,     0,     0,   200,     0,     0,     0,     0,     0,
       0,   236,     0,   205,   234,     0,   254,   250,   256,   251,
     253,   252,   259,     0,     0,     0,     0,     0,     0,     0,
     421,     0,     0,   419,     0,   365,     0,   420,   413,   418,
     417,   416,   415,   414,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   407,   406,   403,     0,   168,   428,   433,
       0,     0,     0,   443,   476,   446,   445,   457,     0,   473,
       0,     0,     0,   571,   573,   577,   579,     0,   124,     0,
     803,    47,    44,    45,    48,    49,     0,     0,     0,     0,
      50,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   643,   644,   645,     0,   103,   142,     0,     0,
     112,     0,     0,     0,     0,   127,     0,     0,   616,     0,
       0,     0,   611,     0,     0,     0,   626,     0,     0,   258,
     261,     0,     0,   134,     0,   138,   168,   513,     0,    60,
       0,    69,     0,     0,     0,    61,     0,     0,     0,     0,
     614,     0,     0,   617,     0,     0,     0,     0,   327,     0,
       0,   615,     0,     0,     0,   634,     0,     0,     0,     0,
     620,     0,     0,   195,     0,     0,   189,   187,     0,     0,
     790,     0,     0,     0,   498,     0,   785,     0,   500,   531,
     530,   527,     0,     0,     0,   561,   560,   429,     0,   558,
       0,   656,   657,     0,     0,     0,     0,     0,   797,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     662,     0,   203,   204,     0,     0,     0,     0,     0,   208,
     209,   787,   789,     0,     5,    24,     0,    25,     0,     7,
      29,     0,    15,     8,    30,     0,    19,   921,    77,    16,
      78,    20,   194,     0,   192,   214,   215,     0,     0,     0,
       0,   296,   206,   235,   237,   238,   257,     0,     0,   357,
     359,   363,   369,   368,   367,     0,   364,   361,   362,     0,
     373,   380,   379,   377,   383,   384,   385,   382,   387,   388,
     391,   390,     0,     0,     0,     0,   412,     0,   438,   439,
       0,   477,   506,   474,   508,     0,   609,   512,   504,     0,
       0,   121,   123,     0,     0,     0,   102,     0,    92,    94,
      95,    96,    97,    99,   100,   101,    93,    98,    88,    89,
       0,     0,   108,     0,   104,   106,   107,   114,     0,     0,
      87,    46,     0,     0,     0,     0,     0,     0,     0,   734,
     739,     0,     0,   735,   769,   722,   724,   725,   726,   728,
     730,   729,   727,   731,     0,     0,     0,     0,     0,   111,
       0,   144,     0,     0,   576,   570,   612,   613,     0,     0,
     630,     0,   627,     0,     0,     0,     0,     0,     0,     0,
       0,   140,     0,     0,   135,     0,     0,     0,     0,     0,
       0,    62,     0,     0,     0,   277,   283,   280,     0,   619,
     618,   625,   633,     0,     0,     0,     0,   575,     0,     0,
       0,   422,     0,     0,     0,     0,   623,     0,   621,     0,
     196,     0,     0,   791,     0,     0,     0,     0,   530,   528,
       0,   519,     0,     0,   502,   503,     0,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,     0,     0,     0,
     670,     0,   210,     0,     0,     0,     0,   165,     0,   165,
       0,   173,   246,     0,   311,   307,   309,     0,   304,   297,
     298,     0,     0,   239,   240,     0,   245,   366,     0,     0,
       0,     0,   700,   374,   673,   677,   679,   681,   683,   686,
     693,   694,   702,   931,   811,     0,   820,   824,   823,   825,
     826,   393,   582,   588,   589,   592,   637,   638,   593,   594,
     597,   395,   397,   400,   598,   399,   426,   478,     0,   475,
     505,   125,    56,    57,    54,    55,   131,   130,     0,    90,
       0,     0,   109,   110,   115,    74,    75,    52,    53,    73,
     740,     0,   743,   770,     0,   733,   732,   737,   736,   768,
       0,     0,   745,     0,   741,   744,   723,     0,     0,     0,
       0,     0,     0,     0,   610,     0,     0,     0,   143,   146,
     148,     0,     0,     0,   113,   116,     0,     0,     0,   168,
       0,     0,   634,     0,     0,     0,   263,     0,   581,     0,
     264,     0,     0,     0,     0,     0,     0,     0,   141,   136,
     139,     0,   190,     0,     0,    71,    65,    68,    67,     0,
      63,   281,     0,     0,   168,     0,   325,   329,     0,     0,
       0,   332,     0,     0,   338,     0,     0,   345,     0,   349,
       0,   424,   423,   168,     0,     0,   197,     0,   199,   326,
       0,     0,     0,     0,   531,     0,   521,     0,   554,   551,
       0,   555,   556,     0,     0,   550,     0,   525,   553,   552,
       0,     0,     0,     0,   649,   650,   646,     0,     0,   654,
     655,   651,   793,   794,   660,   798,   658,     0,     0,     0,
       0,   664,   812,   819,   818,   979,   202,     0,     0,     0,
     665,   666,     0,     0,   211,   796,    26,     0,    17,    21,
      22,   308,   320,     0,   321,     0,   312,   313,   314,   315,
       0,   498,     0,   305,     0,     0,     0,   241,     0,     0,
       0,     0,   290,     0,   287,   292,   244,     0,     0,   684,
     697,     0,   371,   375,     0,   716,     0,     0,     0,     0,
       0,     0,   672,   674,   675,   711,   712,   713,   715,   714,
       0,     0,   688,   687,     0,   691,   695,   709,   707,   706,
     699,   703,     0,     0,     0,     0,     0,     0,     0,     0,
     585,   587,   586,   583,   401,   507,   509,   133,   132,    91,
     105,   757,   738,     0,   762,     0,   762,   751,   746,   147,
     149,     0,     0,     0,   117,   145,     0,    27,     0,   631,
     632,   635,   628,   629,   262,     0,     0,   276,   268,     0,
     272,     0,   266,     0,     0,     0,   137,     0,     0,    70,
       0,    64,   282,     0,     0,   328,   330,   335,     0,   333,
       0,     0,     0,     0,     0,   339,     0,     0,   353,     0,
       0,   346,     0,     0,   350,   425,     0,   624,   622,   198,
     792,     0,     0,   530,     0,     0,   562,     0,   530,     0,
     526,     0,    14,     0,     0,     0,     0,     0,     0,     0,
     663,     0,     0,     0,     0,     0,     0,   667,   671,   324,
     322,   323,   316,   317,   318,   310,     0,     0,   306,   299,
     285,     0,     0,     0,   243,   288,   291,     0,   701,   692,
     698,     0,     0,   771,   772,   782,   781,   780,     0,     0,
       0,     0,   773,   678,   779,     0,   676,   680,     0,     0,
     685,   689,     0,   710,   705,   708,   704,     0,     0,   595,
       0,   590,   642,   584,   802,   801,   800,   591,   758,     0,
       0,   756,   763,   764,   760,     0,   755,     0,   753,     0,
       0,     0,     0,     0,     0,   572,   265,     0,   274,     0,
       0,   270,     0,   273,     0,     0,     0,    66,   284,   578,
       0,     0,   336,   340,   334,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   574,     0,     0,
     530,     0,   557,     0,   530,   580,   647,   648,   652,   653,
       0,   659,   799,   661,     0,     0,     0,     0,   668,   319,
     300,     0,   286,   294,   295,   289,   242,   696,   783,     0,
       0,   775,     0,   721,   720,   719,   718,   717,   682,     0,
     774,     0,   639,     0,     0,   767,   766,   765,     0,   759,
     752,   750,     0,   747,   748,   742,   150,   152,   154,     0,
       0,     0,     0,     0,   269,   267,     0,   275,   207,   355,
      72,   331,   337,     0,   354,   351,   347,     0,     0,     0,
     341,     0,     0,   343,     0,   540,   534,   529,     0,   530,
     520,     0,   795,     0,     0,     0,     0,   303,   301,     0,
     777,   776,     0,     0,   640,   596,     0,   761,   754,     0,
       0,   156,   155,     0,     0,     0,     0,   151,   271,     0,
       0,     0,     0,     0,   548,   542,     0,   541,   543,   549,
     546,   536,     0,   535,   537,   547,   522,     0,   523,     0,
       0,   669,   302,     0,   778,   690,   641,   749,   153,   157,
       0,     0,     0,     0,     0,     0,   344,   342,     0,     0,
     533,   544,   545,   532,   538,   539,   524,     0,   293,   158,
       0,     0,     0,   352,   348,     0,     0,     0,     0,     0,
       0,     0,     0,   160,     0,     0,   159,     0,     0,     0,
       0,     0,     0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1454, -1454,  -225,  -201, -1454,  1213,  1219, -1454,  1239,  -541,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1017, -1454, -1454, -1454, -1454,  -221,  -578, -1454,   730,   -40,
   -1454, -1454, -1454, -1454, -1454,   275,   497, -1454, -1454,    14,
    -186,  1045, -1454,  1024, -1454, -1454,  -639, -1454,   439, -1454,
     234, -1454,  -239,  -279, -1454,  -556, -1454,     4,    80,    69,
    -276,  -181, -1454,  -890, -1454, -1454,   292, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454,   628, -1454,    32,
    1306,     0, -1454, -1454,  -315, -1454, -1454,   358, -1454, -1454,
    -303, -1454,    16, -1454, -1454,   841,  -943,  -742,  -736, -1454,
   -1454,   709, -1454, -1454,   -56,   118, -1454, -1454, -1454,   129,
   -1239, -1454,   378,   134, -1454, -1454,   138, -1316, -1454,   954,
     232, -1454, -1454,   229, -1038, -1454, -1454,   227, -1454, -1454,
   -1259, -1248, -1454,   223, -1439, -1454, -1454,   857,   854, -1454,
    -545,   838, -1454, -1454,  -653,   316,  -650,   333,   335, -1454,
   -1454, -1454,   582, -1454, -1454,  1186, -1454, -1454, -1454, -1454,
   -1454,  -878,  -332,  -660, -1454,  -100, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454,   -17,  -819, -1454,  -550,   629,   239, -1454,
    -413, -1454, -1454, -1454, -1454, -1454, -1454, -1454,   807, -1454,
   -1454, -1454, -1454, -1011, -1454,   211, -1454,   690,  -815, -1454,
   -1454, -1454, -1454, -1454,  -262,  -255, -1226,  -978, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,  -756,
    -929,  -189,  -833, -1454, -1454, -1454,  -689, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454,  1075,  1077,  -233,   504,
     334, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,
   -1454, -1454,   190, -1454, -1454,   176, -1454,   181, -1078, -1454,
   -1454, -1454,   132,   130,   -46,   393, -1454, -1454, -1454, -1454,
   -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454, -1454,   139,
   -1454, -1454, -1454,   -37,   390,   537, -1454, -1454, -1454, -1454,
   -1454,   330, -1454, -1454, -1453, -1454, -1454, -1454,  -557, -1454,
      98, -1454,   -57, -1454, -1454, -1454, -1454, -1321, -1454,   146,
   -1454, -1454, -1454, -1454, -1454,   955, -1454, -1454, -1454, -1454,
   -1454,  -935,  -384,   552,   -64, -1454
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   258,   633,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
    1265,   784,   276,   277,   278,   279,   280,   281,   968,   969,
     970,   282,   283,   284,   974,   975,   976,   285,   450,   286,
     287,   717,   288,   452,   453,   454,   464,   774,   775,   289,
    1228,   290,  1706,  1707,   291,   292,   293,   556,   294,   295,
     296,   297,   298,   777,   299,   300,   538,   301,   302,   303,
     304,   305,   306,   643,   307,   308,   869,   870,   309,   310,
     311,   568,   313,   644,  1643,   656,  1135,  1136,   314,   646,
     315,   648,   569,   317,   318,   769,   770,  1382,   471,   319,
     472,   473,   908,  1383,  1384,  1385,   649,   650,  1129,  1130,
    1373,   651,  1125,  1126,  1366,  1367,  1368,  1369,   320,   797,
     798,   321,  1280,  1281,  1490,   322,  1283,  1284,   323,   324,
    1286,  1287,  1288,  1289,  1497,   325,   326,   327,   328,   915,
     329,   330,  1392,   331,   332,   333,   334,   335,   336,   337,
     338,   339,  1172,   340,   341,   342,   343,   674,   675,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   709,   704,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   945,   371,
     372,   373,   374,   375,   376,  1316,   830,   831,   832,  1737,
    1782,  1783,  1776,  1777,  1784,  1778,  1317,  1318,   377,   378,
    1319,   379,   380,   381,   382,   383,   384,   385,   386,  1030,
    1498,  1433,  1162,  1590,  1163,  1173,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   804,  1241,
     399,  1165,  1166,  1167,  1168,   400,   401,   402,   403,   404,
     405,   859,   860,   406,  1350,  1351,  1668,  1111,  1143,  1402,
    1403,  1144,  1145,  1146,  1147,  1148,  1412,  1580,  1581,  1149,
    1415,  1150,  1561,  1151,  1152,  1420,  1421,  1586,  1584,  1404,
    1405,  1406,  1407,  1686,   746,   995,   996,   997,   998,   999,
    1000,  1214,  1610,  1703,  1215,  1608,  1701,  1001,  1446,  1605,
    1601,  1602,  1603,  1002,  1003,  1408,  1416,  1571,  1409,  1567,
    1393,   407,   408,   409,   410,   559,   411,   412,   413,   414,
     415,  1169,  1266,   416,   417,   418
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -869;
  const short int
  xquery_parser::yytable_[] =
  {
       312,   645,   605,  1161,  1171,   312,   312,   312,   312,   423,
     426,   427,   535,   647,   698,  1080,   316,   718,   718,   628,
    1282,   316,   316,   316,   316,  1270,   535,   923,   451,  1028,
    1044,   924,   925,   926,   927,  1029,   936,   583,  1501,   623,
     848,  1141,   620,  1056,  1512,   855,   888,   890,   721,  1110,
     535,  1543,  1544,   621,   625,   612,   613,  1070,   621,   534,
    1641,  1388,   535,  1645,   535,  1187,   882,   886,   889,   891,
    1230,  1315,  1254,  1024,   425,   425,   425,   429,    11,    12,
    1246,   880,   884,   781,   785,   424,   424,   424,   428,   955,
    1520,   835,    13,  1582,   621,   819,  1248,   621,   436,  1217,
     627,   469,   621,  1259,  1218,   760,  1132,   818,   736,   720,
     737,   312,  1272,  1219,   911,  1053,   912,   913,   621,   914,
    1220,   916,  1221,   761,   621,   652,   439,   316,   621,   917,
     918,  1222,  1025,  1026,  1026,   594,   621,   621,  1191,  1679,
    1709,   596,  1642,  1103,   567,   571,   597,   772,  1081,   628,
    1086,    11,    12,   628,  1025,  1352,  1704,   730,  1223,   585,
     632,   678,   621,  1563,   752,   632,   617,   621,   711,   678,
     739,   436,  1205,    82,   456,  1417,  1418,   457,   679,   712,
     557,   437,   618,  1206,  1255,  1027,   679,    93,  1211,   653,
     731,   424,   720,   782,   654,  1054,   621,  1568,  1419,   439,
    1564,   680,  1308,  1309,   440,  1212,  1394,  1055,  1087,   641,
     760,  1353,   107,   621,  1082,   773,  1138,  1680,  1096,  1139,
    1097,  1194,   621,   621,   595,   984,  1669,   985,   761,  1251,
     598,   740,   621,  -169,   621,   632,   441,   442,  1120,   128,
     783,   655,   470,  1164,  1164,  1494,  1710,   432,   433,   699,
     434,   435,  1481,   621,   827,   470,   312,   312,   836,   621,
     312,  1141,  1141,  1305,  1501,   627,   647,  1133,   438,   632,
    1104,   986,   316,   316,   632,  1258,   316,  1394,  1395,   607,
     609,   628,  1164,   622,  1769,  1224,   624,  1702,  1256,  1520,
     535,   875,  1252,   535,  1257,   312,  1315,  1310,  1438,   888,
     890,  1230,  1464,   632,  1134,  1315,  1797,   877,  1273,   470,
     470,   316,  1560,  1117,   828,   621,  1229,  1311,  1188,  1312,
     632,  1140,  1424,   780,  1357,  1119,  1356,   629,  1711,   632,
     632,  1805,  1476,  1808,   880,   884,  1164,   705,   753,   632,
     707,   632,   586,  1164,   430,   687,   754,  1313,  1036,  1395,
    1473,   114,   762,  1058,   470,   981,  1569,  1570,   621,   688,
     632,  1396,  1397,   621,  1398,   872,   632,   126,   871,   902,
    1137,   444,   728,   535,   621,  1376,   535,  1225,  1226,  1227,
     535,  1400,  1059,   535,   535,   750,  -170,   621,  1314,  1735,
     751,   535,  1761,  1401,   876,   878,   621,   535,   535,  1107,
    1041,   881,   885,   621,   893,   535,   153,   630,  1301,  1302,
     874,   447,   535,   535,   535,   535,   950,  -169,  1303,   448,
     535,   987,   632,  1491,   588,   312,   589,   449,   535,   312,
     445,  1747,  1396,  1397,   988,  1398,   989,   950,   621,  1743,
     484,   316,  1399,   826,   621,   316,  1799,   990,   991,   992,
    1019,   993,  1400,   994,  1088,  1734,   312,   629,   312,   697,
     621,   629,   455,  1053,  1401,   632,  1164,   621,   621,   621,
     632,   446,   316,   535,   316,   470,   621,  1021,  1736,  1454,
     312,   632,   128,    11,    12,   312,  1790,  1033,   535,   631,
    1363,   621,   765,  1589,   632,   951,   316,   778,  1018,   535,
    1065,   316,  1067,   632,  1315,  1466,  1142,   791,   641,  1792,
     632,  1365,  1141,   590,   802,   803,   952,   485,   700,   701,
    1474,  1141,   641,   809,  1178,   429,   849,   429,  1178,  1020,
    1110,   849,  1141,    13,  1538,   535,   757,  1181,   759,   888,
     890,   888,  1501,  1072,  1744,   632,  1048,  1229,   591,   429,
     592,   632,  1338,  1092,   429,  1599,  1022,   312,  1177,  1025,
     800,  1358,  1359,  1360,   312,   806,  1034,   632,    13,   626,
    -170,  1451,  1164,   316,   632,   632,   632,  1089,  1090,  1066,
     316,  1068,  1745,   632,   486,   487,  1064,  1308,  1309,   629,
     628,   535,  1091,  1774,  1195,  1196,  1164,  1308,   632,  1199,
     938,   939,  1207,  1179,   312,   833,   834,  1180,  1693,  1720,
    1099,   312,  1375,  1208,    82,  1547,   838,  1121,   819,  1600,
     316,  1083,   312,   312,   312,   312,  1698,   316,    93,  1238,
    1774,   451,  1026,   425,  1308,   865,   867,   593,   316,   316,
     316,   316,   551,  1084,   424,   312,   702,   458,   708,    82,
    1085,  1109,  1558,   107,  1114,  1308,  1118,  1443,   635,  1791,
     878,   316,   636,    93,  1306,  1667,   572,   637,   957,   431,
     702,   535,   708,   866,  1795,  1780,  1093,  1094,   576,   462,
     579,  -260,  1310,  1465,  1026,   535,   638,  1694,   107,   535,
     535,  1095,  1138,  1211,   820,  1139,  1025,   312,  1649,   883,
    1141,   937,  1311,  1653,  1312,  1699,  1494,  1443,   535,  1724,
    1212,   722,  1311,   316,  1312,   128,   535,  1445,   488,   535,
     678,  1353,  1775,   535,  1444,   723,  1142,  1142,  1529,  1620,
    1307,  1116,  1313,  1164,   940,  1619,   114,   679,   459,   736,
     681,   737,  1313,   678,  1043,  -260,  1308,  1309,  1575,  1311,
    -260,  1312,   126,  1213,  1430,  1279,   463,  1779,  1785,  1811,
     679,   724,  1754,   971,  1755,   535,   425,  1445,  1488,   682,
    1311,  1025,  1312,  1514,   738,   725,   312,   424,   888,  1313,
    1035,  1781,   683,  1752,   639,  1431,  1240,   640,  1243,  1308,
    1309,   153,   316,  1378,   883,   465,  1614,  -260,  1379,  1779,
    1313,   739,   641,  1432,   535,  1785,   972,   312,   312,   698,
    1164,   973,  1025,  1164,  1565,   490,   684,  1380,  1308,  1069,
     641,  1566,   474,   316,   316,  1390,  1115,  1796,   642,   477,
    1683,  1346,  1294,   535,  1295,  1738,  1026,  1684,  1780,  1741,
     478,  1310,   618,   535,  1638,   425,   491,  1685,   128,   492,
     479,   726,  1279,  1075,  1076,  1077,   424,   867,  1381,  1378,
    1546,  1311,   740,  1312,  1379,  1493,   312,   727,   535,   535,
     535,   535,   466,  1499,  1182,   460,   429,   429,   461,  1502,
    1479,   467,   316,   893,  1310,   482,  1500,  1062,  1063,   878,
    1183,  1313,  1503,   312,  1362,   114,  1683,  1499,  1108,  1197,
    1198,   451,  1026,  1684,  1311,  1363,  1312,   535,   468,   316,
    1648,   126,  1678,  1685,  1499,  1364,  1681,  1682,   892,  1025,
    1184,   535,   894,  1186,  1787,  1437,  1365,  1817,  1189,   489,
    1354,  1363,  1519,  1311,  1313,  1312,  1185,   536,   114,   776,
    1189,   776,   941,   483,  1814,   941,   535,   685,   941,  1164,
     153,  1708,  1762,   972,   126,   535,   686,   535,   973,   535,
    1232,   535,   537,  1313,  1200,  1201,  1202,  1492,   535,  1233,
    1203,  1378,   702,   539,   708,  1651,  1379,  1142,   540,  1539,
     475,   480,   703,   476,   481,   706,  1142,  1477,  1548,   729,
    1540,  1541,   733,   153,   921,   922,   741,  1142,   552,   747,
     748,   535,  1164,   535,  1164,   553,  1322,   756,  1323,   742,
     743,   744,   554,   768,   771,  1327,   573,  1328,   928,   929,
     574,   786,   930,   931,   575,  1531,  1750,  1751,   794,   795,
     796,   799,   580,  1535,  1164,   581,   805,   582,   849,   659,
    1449,  1450,  1695,  1696,   812,   647,   584,   660,   661,   587,
     662,  -610,   599,  1708,   602,   603,   604,   600,   663,   601,
     312,   610,   664,   535,   665,   614,   634,  1164,   658,   666,
     657,   676,   677,   689,   690,   691,   316,   692,   696,   702,
     710,  1164,   720,  1164,   713,   667,   732,   734,   714,   813,
     735,   535,   715,   749,   716,   745,  1627,   776,   758,  1794,
    1708,   779,   787,   788,   799,   789,   790,  1347,   801,   668,
     669,   670,   671,   672,   673,   824,   807,   312,   312,   312,
     808,   457,   461,  1348,   476,   481,   492,   814,   816,   429,
     451,   818,   825,   316,   316,   316,   821,   822,   823,   829,
    1290,   958,   959,   960,   961,   962,   963,   964,   965,   966,
     967,   861,   837,   839,   840,   879,   857,   858,   868,   897,
     862,   898,   899,   907,   605,  1142,   863,   904,   900,   919,
    1387,   905,  1836,  1630,  1837,  1631,   932,   933,  1635,  1636,
     934,   535,  1639,   935,  1845,   535,   946,   947,  1646,   953,
     956,   954,   978,   979,   982,   983,  1004,   535,  1005,  1008,
    1013,  1014,  1015,  1010,  1006,  1023,  1016,   771,  1017,  1032,
    1038,   535,  1039,  1042,  1049,  1050,  1633,  1051,  1057,  1061,
    1052,   535,  1060,   456,   460,   475,   480,   491,  1098,  1101,
    1105,  1100,  1102,  1106,  1116,  1113,   973,  1176,  1190,   312,
    1025,  1209,  1210,  1458,  1123,  1236,  1237,  1231,  1239,  1247,
     535,  1249,  1261,   772,  1253,   316,  1263,  1267,  1264,   902,
    1262,  1268,  1269,   312,  1274,  1275,  1278,  1279,  1298,  1285,
    1291,  1293,  1297,  1292,   312,   535,  1300,  1304,  1484,   316,
    1320,  1321,  1339,  1349,   738,   535,  1370,   977,  1372,   535,
     316,  1374,  1391,   312,  1410,  1377,  1414,  1506,  1422,  1423,
    1425,  1007,  1411,    13,  1426,  1011,  1012,  1434,   425,   316,
    1427,  1441,  1428,   312,  1442,  1429,  1447,   535,  1453,   424,
     312,  1457,  1456,  1459,  1031,  1460,  1728,  1461,  1469,   316,
    1732,  1462,  1037,  1452,  1471,  1040,   316,  1475,  1463,  1045,
    1480,  1483,  1499,   425,  1516,  1505,  1507,  1511,  1718,  1513,
    1527,  1508,  1347,  1523,   424,  1524,  1525,  1532,   535,  1722,
    1633,  1522,   425,  1725,  1528,   641,  1533,  1534,  1348,  1352,
    1733,  1363,  1526,   424,  1551,  1552,  1553,  1557,  1559,  1578,
    1562,  1078,   429,  1579,  1585,  1583,  1591,  1572,   535,   429,
    1592,  1598,  1593,  1517,  1594,  1595,  1604,  1609,  1611,  1596,
    1521,  1597,  1615,  1617,  1624,  1613,  1622,  1625,  1626,  1629,
    1671,  1607,  1691,  1647,  1771,  1689,  1700,   558,  1652,  1655,
    1677,   866,  1211,  1660,  1692,  1705,  1716,  1723,  1749,  1713,
    1740,  1756,   535,  1757,  1758,   535,  1690,  1759,   535,  1760,
    1764,  1770,  1765,  1772,  1786,  1788,  1793,  1789,  1803,  1122,
     535,  1810,  1802,  1813,  1804,   535,  1725,  1712,  1809,  1131,
    1816,  1822,  1827,  1842,  1838,  1841,  1440,  1828,   980,  1192,
    1455,  1839,  1260,   615,  1767,   755,   719,  1800,  1820,   616,
    1829,  1798,  1832,  1834,  1170,  1170,  1174,  1174,   535,   535,
    1825,  1844,   312,  1826,  1386,  1806,   906,  1112,  1047,  1675,
    1556,  1361,   619,  1549,  1545,  1542,   815,  1485,   316,  1489,
    1495,  1504,   910,  1477,   909,   920,  1835,  1175,  1515,   949,
    1079,  1815,  1812,  1170,  1439,  1244,  1537,   695,  1823,  1530,
    1536,  1573,  1688,  1389,   763,  1347,   764,  1204,  1687,  1413,
    1577,  1216,  1576,  1448,  1606,  1697,  1574,     0,   853,     0,
    1823,  1348,     0,     0,     0,     0,     0,     0,     0,  1806,
       0,     0,  1235,     0,  1664,  1665,  1666,     0,     0,     0,
       0,  1242,     0,  1242,   535,   771,   535,  1170,   535,     0,
     535,     0,     0,     0,  1170,     0,     0,   535,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   805,     0,   805,
       0,     0,     0,     0,  1347,     0,     0,   535,     0,   535,
       0,     0,     0,     0,     0,  1347,  1347,     0,     0,   312,
    1348,     0,     0,     0,     0,   535,  1347,     0,   535,     0,
       0,  1348,  1348,     0,     0,   316,     0,     0,     0,   535,
       0,     0,  1348,     0,     0,     0,     0,     0,     0,     0,
     535,     0,     0,     0,     0,     0,     0,     0,     0,  1371,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   535,     0,     0,     0,     0,     0,     0,  1746,
     535,     0,     0,     0,     0,     0,   535,  1170,   535,     0,
       0,     0,     0,    11,    12,     0,     0,     0,     0,     0,
       0,  1753,     0,   432,   433,     0,   434,   435,     0,   535,
       0,     0,  1347,   436,     0,     0,     0,     0,   535,     0,
       0,     0,     0,   437,   438,     0,     0,     0,  1348,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   535,     0,
       0,   439,     0,   535,     0,     0,   440,     0,     0,     0,
       0,   312,     0,     0,     0,   535,     0,     0,   535,     0,
       0,     0,     0,     0,     0,     0,     0,   316,     0,  1347,
       0,     0,     0,     0,     0,     0,     0,   771,   441,   442,
     443,  1467,     0,     0,   312,  1348,     0,     0,     0,     0,
       0,     0,     0,  1170,     0,     0,     0,     0,     0,     0,
     316,     0,     0,     0,     0,     0,  1347,   799,     0,     0,
       0,     0,     0,     0,     0,  1347,     0,  1170,     0,     0,
       0,     0,  1348,     0,     0,     0,     0,   444,     0,     0,
       0,  1348,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1518,     0,     0,     0,
     558,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   861,     0,     0,   841,   842,     0,   850,   851,   852,
     854,     0,   856,     0,     0,     0,   445,     0,   864,     0,
       0,     0,     0,     0,     0,     0,   873,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1555,     0,     0,     0,     0,   895,   896,
       0,     0,     0,     0,     0,     0,     0,   446,   901,     0,
       0,   903,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   447,  1170,     0,     0,     0,     0,     0,
       0,   448,     0,     0,     0,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   944,     0,     0,     0,   944,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1637,     0,
       0,  1170,     0,     0,  1170,     0,     0,  1009,     0,     0,
       0,     0,     0,     0,     0,     0,  1650,     0,     0,     0,
       0,  1654,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1046,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1673,  1674,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1071,     0,     0,     0,  1073,  1074,     0,     0,     0,     0,
       0,     0,     0,   903,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1170,     0,  1727,     0,  1729,     0,  1731,     0,     0,   896,
       0,     0,     0,  1739,     0,  1124,  1128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1170,     0,  1170,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1763,     0,     0,  1766,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1170,     0,     0,     0,  1193,
       0,     0,     0,     0,     0,     0,  1773,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1170,     0,
       0,     0,     0,     0,  1234,     0,  1801,     0,     0,     0,
       0,     0,  1170,     0,  1170,     0,     0,     0,     0,     0,
       0,     0,     0,  1250,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1818,     0,     0,     0,  1271,
       0,     0,     0,     0,  1821,     0,     0,     0,     0,     0,
    1276,  1277,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1830,  1296,     0,     0,  1299,  1831,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1840,     0,     0,  1843,  1324,  1325,  1326,     0,  1329,
    1330,  1331,  1332,  1333,  1334,  1335,  1336,  1337,     0,     0,
    1340,  1341,     0,     0,     0,     0,     0,     0,     0,  1355,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1436,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -868,   462,     0,  -260,     0,     0,  1468,     0,  1470,
       0,  1472,     0,     0,     0,     0,     0,     0,     0,  1478,
       0,     0,     0,     0,     0,     0,     0,     0,  1482,     0,
       0,     0,     0,     0,  1486,  1487,     0,     0,     0,     0,
       0,     0,     0,  -868,     0,     0,     0,  -868,     0,     0,
       0,  -868,  -868,  1509,     0,     0,  1510,  -868,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -260,     0,
       0,  -868,     0,  -260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -868,     0,  -868,  -868,  -868,     0,
       0,  -868,  -868,  -868,  -868,     0,     0,     0,  -868,  -868,
       0,     0,     0,     0,     0,  -868,     0,     0,  -868,  -868,
    -260,     0,     0,  -868,     0,     0,  1124,     0,  -868,  -868,
    1128,  1550,     0,     0,  -868,     0,  1554,     0,  -868,     0,
       0,     0,  -868,  -868,     0,  -868,     0,  -868,  -868,     0,
       0,     0,  -868,  -868,     0,     0,  -868,  -868,  -868,  -868,
    -868,  -868,     0,     0,  -868,     0,     0,     0,  -868,  -868,
       0,     0,  -868,     0,     0,     0,     0,  -868,     0,     0,
    -868,     0,     0,     0,     0,  -868,  -868,  -868,  -868,  -868,
       0,  -868,  -868,  -868,  -868,  -868,     0,     0,     0,     0,
    -868,  -868,  -868,     0,  -868,  -868,  -868,  -868,  -868,  -868,
       0,  -868,     0,  -868,     0,     0,     0,     0,  -868,  -868,
    -868,  1616,     0,     0,     0,  1618,     0,     0,     0,  1621,
       0,  1623,     0,     0,  -868,     0,  -868,     0,  -868,  1628,
       0,     0,     0,     0,     0,     0,     0,  1632,  1634,     0,
    -868,     0,     0,     0,     0,  -868,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1478,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1656,
    1657,  1658,  1659,     0,  1661,  1662,     0,  1663,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1670,     0,     0,     0,     0,  1672,     0,     0,
       0,     0,  -868,  1676,  -868,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1714,     0,  1715,     0,     0,  1717,     0,
       0,  1719,     0,     0,     0,     0,  1721,  1634,     0,     0,
       0,     0,     0,     0,     0,  1726,     0,     0,     0,  1730,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1742,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1748,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1768,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1726,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1807,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -165,   883,     0,     0,     0,     0,  1819,     0,     0,     0,
    1824,     1,     2,     0,     0,  1807,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,  1824,     0,    14,   420,  1833,    16,    17,    18,    19,
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
       0,   151,   152,   153,     0,   422,   155,   156,   157,   158,
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
     255,  -165,   883,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   887,   420,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
     421,    30,    31,    32,    33,    34,     0,    35,    36,    37,
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
     134,   135,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   422,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   883,   248,     0,   249,   250,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
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
      90,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,   135,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   422,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   883,   248,     0,   249,   250,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   419,   420,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   560,
     421,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   561,   562,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   510,    85,    86,    87,    88,    89,
     563,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   564,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   422,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   528,
     529,   530,   180,   181,   531,   566,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     0,   249,   250,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
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
     134,   135,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     0,   249,   250,   251,   252,   253,
     254,   255,   256,   257,     1,     2,     0,     0,     0,     3,
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
      88,    89,    90,    91,    92,     0,     0,     0,    93,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
     113,   114,   115,   116,   117,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,   125,     0,   126,     0,   127,
     128,     0,     0,   129,   130,   131,     0,     0,     0,   132,
       0,   133,   134,   135,   136,   137,     0,   138,     0,   139,
       0,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,     0,     0,   151,   152,   153,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,     0,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,     0,   248,     0,   249,   250,   251,
     252,   253,   254,   255,     0,   611,     1,     2,     0,     0,
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
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,   555,
       0,   132,     0,   133,   134,   135,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
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
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,   817,
       0,   132,     0,   133,   134,   135,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,  1342,   421,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,  1343,  1344,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,   555,
       0,   132,     0,   133,   134,   135,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,  1345,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
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
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,   135,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,    13,     0,     0,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
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
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,    13,     0,     0,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,   135,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
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
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,   135,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,    13,     0,     0,   887,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,   421,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,   135,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,  1342,   421,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,  1343,  1344,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,   135,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,  1345,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   560,   421,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,   561,   562,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   510,    85,
      86,    87,    88,    89,   563,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
     942,     0,   104,   105,   106,   107,   108,   109,   110,   564,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,   943,   133,   134,     0,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   528,   529,   530,   180,   181,   531,   566,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   560,   421,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,   561,   562,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   510,    85,
      86,    87,    88,    89,   563,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
     942,     0,   104,   105,   106,   107,   108,   109,   110,   564,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,   948,   133,   134,     0,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   528,   529,   530,   180,   181,   531,   566,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   560,   421,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,   561,   562,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   510,    85,
      86,    87,    88,    89,   563,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   564,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
     565,   132,     0,   133,   134,     0,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   528,   529,   530,   180,   181,   531,   566,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   560,   421,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,   561,   562,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   510,    85,
      86,    87,    88,    89,   563,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   564,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,   570,   133,   134,     0,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   528,   529,   530,   180,   181,   531,   566,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   560,   421,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,   561,   562,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   510,    85,
      86,    87,    88,    89,   563,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   564,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,     0,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   528,   529,   530,   180,   181,   531,   566,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   606,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   560,   421,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,   561,   562,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   510,    85,
      86,    87,    88,    89,   563,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   564,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,     0,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   528,   529,   530,   180,   181,   531,   566,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,   608,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   560,   421,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,   561,   562,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   510,    85,
      86,    87,    88,    89,   563,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
    1435,     0,   104,   105,   106,   107,   108,   109,   110,   564,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,     0,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   528,   529,   530,   180,   181,   531,   566,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
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
      86,    87,    88,    89,   563,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   513,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   564,
     112,     0,   113,   114,   693,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   694,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,     0,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   523,
     164,   524,   166,   525,   526,   169,   170,   171,   172,   173,
     174,   527,   176,   528,   529,   530,   180,   181,   531,   532,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     533,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   560,   421,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,   561,   562,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   510,    85,
      86,    87,    88,    89,   563,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   564,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,     0,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   528,   529,   530,   180,   181,   531,   566,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
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
      86,    87,    88,    89,   563,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   513,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   564,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,     0,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   523,
     164,   524,   166,   525,   526,   169,   170,   171,   172,   173,
     174,   527,   176,   528,   529,   530,   180,   181,   531,   532,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     533,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   560,   421,    30,    31,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,     0,    48,    49,    50,   561,   562,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   510,    85,
      86,    87,    88,    89,  1127,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,    99,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   564,
     112,     0,   113,   114,   115,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,   127,   128,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,     0,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   528,   529,   530,   180,   181,   531,   566,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     250,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   496,    27,   498,   421,    30,   499,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,   501,     0,    48,    49,    50,   503,   504,
      53,   505,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   510,    85,
      86,    87,    88,    89,   563,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   513,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   564,
     112,     0,   113,   114,     0,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,     0,     0,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,     0,   136,   137,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   523,
     164,   524,   166,   525,   526,   169,   170,   171,   172,   173,
     174,   527,   176,   528,   529,   530,   180,   181,   531,   532,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     533,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   496,    27,   498,   421,    30,   499,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,   501,     0,    48,    49,    50,   503,   504,
      53,   505,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   510,    85,
      86,    87,    88,    89,   563,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   513,   100,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,   110,   564,
     112,     0,   113,   114,     0,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,     0,     0,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,     0,     0,     0,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   523,
     164,   524,   166,   525,   526,   169,   170,   171,   172,   173,
     174,   527,   176,   528,   529,   530,   180,   181,   531,   532,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     533,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   419,   420,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   496,    27,   498,   421,    30,   499,    32,    33,    34,
       0,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,   501,     0,    48,    49,    50,   503,   504,
      53,   505,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
      72,    73,    74,    75,    76,     0,    77,    78,    79,     0,
       0,    80,    81,     0,     0,     0,    82,    83,   510,    85,
      86,    87,    88,    89,   563,    91,    92,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   513,     0,   101,   102,   103,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,     0,   109,   110,   564,
     112,     0,   113,   114,     0,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   125,     0,   126,
       0,     0,     0,     0,     0,   129,   130,   131,     0,     0,
       0,   132,     0,   133,   134,     0,     0,     0,     0,   138,
       0,   139,     0,   140,     0,   142,     0,   144,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,   153,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   523,
     164,   524,   166,   525,   526,   169,   170,   171,   172,   173,
     174,   527,   176,   528,   529,   530,   180,   181,   531,   532,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     0,   249,
     533,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     0,     0,     0,     0,
       9,    10,     0,     0,     0,     0,     0,     0,   419,   420,
       0,    16,    17,    18,   493,    20,    21,    22,   494,    24,
     495,   496,   497,   498,   421,    30,   499,    32,    33,    34,
       0,    35,    36,    37,    38,   500,    40,    41,    42,    43,
      44,    45,    46,   501,     0,    48,   502,    50,   503,   504,
      53,   505,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   506,   507,    71,     0,
      72,    73,    74,   508,     0,     0,    77,    78,    79,     0,
       0,   509,    81,     0,     0,     0,     0,    83,   510,    85,
     511,   512,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   513,   100,   101,   514,   515,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,   110,     0,
       0,     0,     0,     0,     0,   116,   516,     0,     0,     0,
     118,   119,   120,   121,   517,   123,   124,   518,     0,     0,
       0,     0,     0,     0,     0,   519,   520,   131,     0,     0,
       0,   132,     0,   133,   521,     0,     0,     0,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   522,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,     0,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   523,
     164,   524,   166,   525,   526,   169,   170,   171,   172,   173,
     174,   527,   176,   528,   529,   530,   180,   181,   531,   532,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,     0,     0,     0,     0,   249,
     533,   251,   252,   253,   254,   255,     1,     2,     0,     0,
       0,     3,     0,     0,     0,     4,     0,     0,     0,     0,
       9,    10,     0,     0,     0,     0,     0,     0,   419,   420,
       0,    16,    17,    18,   541,    20,    21,    22,   494,   542,
     543,   496,   497,   498,   421,    30,   499,    32,   544,    34,
       0,    35,    36,    37,    38,   545,    40,   546,   547,    43,
      44,    45,    46,   501,     0,    48,   548,    50,   503,   504,
      53,   505,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   506,   507,    71,     0,
      72,    73,    74,   549,     0,     0,    77,    78,    79,     0,
       0,   509,    81,     0,     0,     0,     0,    83,   510,    85,
     511,   512,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   513,   100,   101,   514,   515,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,   110,     0,
       0,     0,     0,     0,     0,   116,   516,     0,     0,     0,
     118,   119,   120,   121,   517,   123,   124,   518,     0,     0,
       0,     0,     0,     0,     0,   519,   520,   131,     0,     0,
       0,   132,     0,   133,   521,     0,     0,     0,     0,   138,
       0,   139,     0,   140,   141,   142,   143,   522,   145,   146,
     147,   148,   149,   150,     0,     0,   151,   152,     0,     0,
     422,   155,   156,   157,   158,   159,   160,   161,   162,   523,
     550,   524,   166,   525,   526,   169,   170,   171,   172,   173,
     174,   527,   176,   528,   529,   530,   180,   181,   531,   532,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,     0,     0,     3,     0,   249,
     533,   251,   252,   253,   254,   255,     9,    10,     0,     0,
       0,     0,     0,     0,   419,   420,     0,    16,    17,    18,
     493,    20,    21,    22,   494,    24,   495,   496,  1153,   498,
     421,    30,   499,    32,    33,    34,     0,    35,    36,    37,
      38,   500,    40,    41,    42,    43,    44,    45,    46,   501,
       0,    48,   502,    50,   503,   504,    53,   505,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   506,   507,    71,     0,    72,    73,    74,   508,
       0,     0,    77,    78,    79,     0,     0,   509,    81,     0,
       0,     0,     0,    83,   510,    85,   511,   512,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   513,   100,   101,
     514,   515,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,  1154,     0,     0,     0,  1155,     0,
       0,   116,   516,     0,     0,     0,   118,   119,   120,   121,
     517,   123,   124,   518,     0,     0,     0,     0,     0,     0,
       0,   519,   520,   131,     0,     0,     0,   132,  1587,   133,
     521,     0,     0,     0,     0,  1588,     0,   139,     0,   140,
     141,   142,   143,   522,   145,   146,   147,   148,   149,   150,
       0,     0,  1156,   152,     0,     0,   422,   155,   156,   157,
     158,   159,   160,   161,   162,   523,   164,   524,   166,   525,
     526,   169,   170,   171,   172,   173,   174,   527,   176,   528,
     529,   530,   180,   181,   531,   532,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,     0,     0,     0,     0,   249,   533,   251,  1157,  1158,
    1159,  1160,     3,     0,   577,   578,     0,     0,     0,     0,
       0,     9,    10,     0,     0,     0,     0,     0,     0,   419,
     420,     0,    16,    17,    18,   541,    20,    21,    22,   494,
     542,   543,   496,   497,   498,   421,    30,   499,    32,   544,
      34,     0,    35,    36,    37,    38,   545,    40,   546,   547,
      43,    44,    45,    46,   501,     0,    48,   548,    50,   503,
     504,    53,   505,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   506,   507,    71,
       0,    72,    73,    74,   549,     0,     0,    77,    78,    79,
       0,     0,   509,    81,     0,     0,     0,     0,    83,   510,
      85,   511,   512,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   513,   100,   101,   514,   515,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,   110,
       0,     0,     0,     0,     0,     0,   116,   516,     0,     0,
       0,   118,   119,   120,   121,   517,   123,   124,   518,     0,
       0,     0,     0,     0,     0,     0,   519,   520,   131,     0,
       0,     0,   132,     0,   133,   521,     0,     0,     0,     0,
       0,     0,   139,     0,   140,   141,   142,   143,   522,   145,
     146,   147,   148,   149,   150,     0,     0,   151,   152,     0,
       0,   422,   155,   156,   157,   158,   159,   160,   161,   162,
     523,   550,   524,   166,   525,   526,   169,   170,   171,   172,
     173,   174,   527,   176,   528,   529,   530,   180,   181,   531,
     532,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     3,     0,
     249,   533,   251,   252,   253,   254,   255,     9,    10,     0,
       0,     0,     0,     0,     0,   419,   420,     0,    16,    17,
      18,   541,    20,    21,    22,   494,   542,   543,   496,   497,
     498,   421,    30,   499,    32,   544,    34,     0,    35,    36,
      37,    38,   545,    40,   546,   547,    43,    44,    45,    46,
     501,     0,    48,   548,    50,   503,   504,    53,   505,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   506,   507,    71,     0,    72,    73,    74,
     549,     0,     0,    77,    78,    79,     0,     0,   509,    81,
       0,     0,     0,     0,    83,   510,    85,   511,   512,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   513,   100,
     101,   514,   515,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,   116,   516,     0,     0,     0,   118,   119,   120,
     121,   517,   123,   124,   518,     0,     0,     0,     0,     0,
       0,     0,   519,   520,   131,     0,     0,     0,   132,   766,
     133,   521,     0,     0,     0,     0,   767,     0,   139,     0,
     140,   141,   142,   143,   522,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,     0,     0,   422,   155,   156,
     157,   158,   159,   160,   161,   162,   523,   550,   524,   166,
     525,   526,   169,   170,   171,   172,   173,   174,   527,   176,
     528,   529,   530,   180,   181,   531,   532,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,     0,     3,     0,   249,   533,   251,   252,
     253,   254,   255,     9,    10,     0,     0,     0,   792,     0,
       0,   419,   420,     0,    16,    17,    18,   541,    20,    21,
      22,   494,   542,   543,   496,   497,   498,   421,    30,   499,
      32,   544,    34,     0,    35,    36,    37,    38,   545,    40,
     546,   547,    43,    44,    45,    46,   501,     0,    48,   548,
      50,   503,   504,    53,   505,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   506,
     507,    71,     0,    72,    73,    74,   549,     0,     0,    77,
      78,    79,     0,     0,   509,    81,     0,     0,     0,     0,
      83,   510,    85,   511,   512,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   513,   100,   101,   514,   515,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,   116,   516,
       0,     0,     0,   118,   119,   120,   121,   517,   123,   124,
     518,     0,     0,     0,     0,     0,     0,     0,   519,   520,
     131,     0,     0,     0,   132,   793,   133,   521,     0,     0,
       0,     0,     0,     0,   139,     0,   140,   141,   142,   143,
     522,   145,   146,   147,   148,   149,   150,     0,     0,   151,
     152,     0,     0,   422,   155,   156,   157,   158,   159,   160,
     161,   162,   523,   550,   524,   166,   525,   526,   169,   170,
     171,   172,   173,   174,   527,   176,   528,   529,   530,   180,
     181,   531,   532,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,     0,
       3,     0,   249,   533,   251,   252,   253,   254,   255,     9,
      10,     0,     0,     0,     0,     0,     0,   419,   420,     0,
      16,    17,    18,   541,    20,    21,    22,   494,   542,   543,
     496,   497,   498,   421,    30,   499,    32,   544,    34,     0,
      35,    36,    37,    38,   545,    40,   546,   547,    43,    44,
      45,    46,   501,     0,    48,   548,    50,   503,   504,    53,
     505,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   506,   507,    71,     0,    72,
      73,    74,   549,     0,     0,    77,    78,    79,     0,     0,
     509,    81,     0,     0,     0,     0,    83,   510,    85,   511,
     512,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     513,   100,   101,   514,   515,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,   110,     0,     0,
       0,     0,     0,     0,   116,   516,     0,     0,     0,   118,
     119,   120,   121,   517,   123,   124,   518,     0,     0,     0,
       0,     0,     0,     0,   519,   520,   131,     0,     0,     0,
     132,   810,   133,   521,     0,     0,     0,     0,   811,     0,
     139,     0,   140,   141,   142,   143,   522,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,     0,     0,   422,
     155,   156,   157,   158,   159,   160,   161,   162,   523,   550,
     524,   166,   525,   526,   169,   170,   171,   172,   173,   174,
     527,   176,   528,   529,   530,   180,   181,   531,   532,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,     0,     3,     0,   249,   533,
     251,   252,   253,   254,   255,     9,    10,     0,     0,     0,
       0,     0,     0,   419,   420,     0,    16,    17,    18,   493,
      20,    21,    22,   494,    24,   495,   496,  1153,   498,   421,
      30,   499,    32,    33,    34,     0,    35,    36,    37,    38,
     500,    40,    41,    42,    43,    44,    45,    46,   501,     0,
      48,   502,    50,   503,   504,    53,   505,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   506,   507,    71,     0,    72,    73,    74,   508,     0,
       0,    77,    78,    79,     0,     0,   509,    81,     0,     0,
       0,     0,    83,   510,    85,   511,   512,    88,    89,  1496,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   513,   100,   101,   514,
     515,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,  1154,     0,     0,     0,  1155,     0,     0,
     116,   516,     0,     0,     0,   118,   119,   120,   121,   517,
     123,   124,   518,     0,     0,     0,     0,     0,     0,     0,
     519,   520,   131,     0,     0,     0,   132,     0,   133,   521,
       0,     0,     0,     0,     0,     0,   139,     0,   140,   141,
     142,   143,   522,   145,   146,   147,   148,   149,   150,     0,
       0,  1156,   152,     0,     0,   422,   155,   156,   157,   158,
     159,   160,   161,   162,   523,   164,   524,   166,   525,   526,
     169,   170,   171,   172,   173,   174,   527,   176,   528,   529,
     530,   180,   181,   531,   532,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,     0,     3,     0,   249,   533,   251,  1157,  1158,  1159,
    1160,     9,    10,     0,     0,     0,     0,     0,     0,   419,
     420,     0,    16,    17,    18,   493,    20,    21,    22,   494,
      24,   495,   496,  1153,   498,   421,    30,   499,    32,    33,
      34,     0,    35,    36,    37,    38,   500,    40,    41,    42,
      43,    44,    45,    46,   501,     0,    48,   502,    50,   503,
     504,    53,   505,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   506,   507,    71,
       0,    72,    73,    74,   508,     0,     0,    77,    78,    79,
       0,     0,   509,    81,     0,     0,     0,     0,    83,   510,
      85,   511,   512,    88,    89,  1640,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   513,   100,   101,   514,   515,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,  1154,
       0,     0,     0,  1155,     0,     0,   116,   516,     0,     0,
       0,   118,   119,   120,   121,   517,   123,   124,   518,     0,
       0,     0,     0,     0,     0,     0,   519,   520,   131,     0,
       0,     0,   132,     0,   133,   521,     0,     0,     0,     0,
       0,     0,   139,     0,   140,   141,   142,   143,   522,   145,
     146,   147,   148,   149,   150,     0,     0,  1156,   152,     0,
       0,   422,   155,   156,   157,   158,   159,   160,   161,   162,
     523,   164,   524,   166,   525,   526,   169,   170,   171,   172,
     173,   174,   527,   176,   528,   529,   530,   180,   181,   531,
     532,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     3,     0,
     249,   533,   251,  1157,  1158,  1159,  1160,     9,    10,     0,
       0,     0,     0,     0,     0,   419,   420,     0,    16,    17,
      18,   493,    20,    21,    22,   494,    24,   495,   496,  1153,
     498,   421,    30,   499,    32,    33,    34,     0,    35,    36,
      37,    38,   500,    40,    41,    42,    43,    44,    45,    46,
     501,     0,    48,   502,    50,   503,   504,    53,   505,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   506,   507,    71,     0,    72,    73,    74,
     508,     0,     0,    77,    78,    79,     0,     0,   509,    81,
       0,     0,     0,     0,    83,   510,    85,   511,   512,    88,
      89,  1644,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   513,   100,
     101,   514,   515,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,  1154,     0,     0,     0,  1155,
       0,     0,   116,   516,     0,     0,     0,   118,   119,   120,
     121,   517,   123,   124,   518,     0,     0,     0,     0,     0,
       0,     0,   519,   520,   131,     0,     0,     0,   132,     0,
     133,   521,     0,     0,     0,     0,     0,     0,   139,     0,
     140,   141,   142,   143,   522,   145,   146,   147,   148,   149,
     150,     0,     0,  1156,   152,     0,     0,   422,   155,   156,
     157,   158,   159,   160,   161,   162,   523,   164,   524,   166,
     525,   526,   169,   170,   171,   172,   173,   174,   527,   176,
     528,   529,   530,   180,   181,   531,   532,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,     0,     3,     0,   249,   533,   251,  1157,
    1158,  1159,  1160,     9,    10,     0,     0,     0,     0,     0,
       0,   419,   420,     0,    16,    17,    18,   493,    20,    21,
      22,   494,    24,   495,   496,  1153,   498,   421,    30,   499,
      32,    33,    34,     0,    35,    36,    37,    38,   500,    40,
      41,    42,    43,    44,    45,    46,   501,     0,    48,   502,
      50,   503,   504,    53,   505,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   506,
     507,    71,     0,    72,    73,    74,   508,     0,     0,    77,
      78,    79,     0,     0,   509,    81,     0,     0,     0,     0,
      83,   510,    85,   511,   512,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   513,   100,   101,   514,   515,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,  1154,     0,     0,     0,  1155,     0,     0,   116,   516,
       0,     0,     0,   118,   119,   120,   121,   517,   123,   124,
     518,     0,     0,     0,     0,     0,     0,     0,   519,   520,
     131,     0,     0,     0,   132,     0,   133,   521,     0,     0,
       0,     0,     0,     0,   139,     0,   140,   141,   142,   143,
     522,   145,   146,   147,   148,   149,   150,     0,     0,  1156,
     152,     0,     0,   422,   155,   156,   157,   158,   159,   160,
     161,   162,   523,   164,   524,   166,   525,   526,   169,   170,
     171,   172,   173,   174,   527,   176,   528,   529,   530,   180,
     181,   531,   532,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,     0,
       3,     0,   249,   533,   251,  1157,  1158,  1159,  1160,     9,
      10,     0,     0,     0,     0,     0,     0,   419,   420,     0,
      16,    17,    18,   493,    20,    21,    22,   494,    24,   495,
     496,  1153,   498,   421,    30,   499,    32,    33,    34,     0,
      35,    36,    37,    38,   500,    40,    41,    42,    43,    44,
      45,    46,   501,     0,    48,   502,    50,   503,   504,    53,
     505,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   506,   507,    71,     0,    72,
      73,    74,   508,     0,     0,    77,    78,    79,     0,     0,
     509,    81,     0,     0,     0,     0,    83,   510,    85,   511,
     512,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     513,   100,   101,   514,   515,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,  1154,     0,     0,
       0,  1155,     0,     0,   116,   516,     0,     0,     0,   118,
     119,   120,   121,   517,   123,   124,   518,     0,     0,     0,
       0,     0,     0,     0,   519,   520,   131,     0,     0,     0,
     132,     0,   133,   521,     0,     0,     0,     0,     0,     0,
     139,     0,   140,   141,   142,   143,   522,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,     0,     0,   422,
     155,   156,   157,   158,   159,   160,   161,   162,   523,   164,
     524,   166,   525,   526,   169,   170,   171,   172,   173,   174,
     527,   176,   528,   529,   530,   180,   181,   531,   532,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,     0,     3,     0,   249,   533,
     251,  1157,  1158,  1159,  1160,     9,    10,     0,     0,     0,
       0,     0,     0,   419,   420,     0,    16,    17,    18,   541,
      20,    21,    22,   494,   542,   543,   496,   497,   498,   421,
      30,   499,    32,   544,    34,     0,    35,    36,    37,    38,
     545,    40,   546,   547,    43,    44,    45,    46,   501,     0,
      48,   548,    50,   503,   504,    53,   505,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   506,   507,    71,     0,    72,    73,    74,   549,     0,
       0,    77,    78,    79,     0,     0,   509,    81,     0,     0,
       0,     0,    83,   510,    85,   511,   512,    88,    89,  1245,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   513,   100,   101,   514,
     515,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,   110,     0,     0,     0,     0,     0,     0,
     116,   516,     0,     0,     0,   118,   119,   120,   121,   517,
     123,   124,   518,     0,     0,     0,     0,     0,     0,     0,
     519,   520,   131,     0,     0,     0,   132,     0,   133,   521,
       0,     0,     0,     0,     0,     0,   139,     0,   140,   141,
     142,   143,   522,   145,   146,   147,   148,   149,   150,     0,
       0,   151,   152,     0,     0,   422,   155,   156,   157,   158,
     159,   160,   161,   162,   523,   550,   524,   166,   525,   526,
     169,   170,   171,   172,   173,   174,   527,   176,   528,   529,
     530,   180,   181,   531,   532,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,     0,     3,     0,   249,   533,   251,   252,   253,   254,
     255,     9,    10,     0,     0,     0,     0,     0,     0,   419,
     420,     0,    16,    17,    18,   541,    20,    21,    22,   494,
     542,   543,   496,   497,   498,   421,    30,   499,    32,   544,
      34,     0,    35,    36,    37,    38,   545,    40,   546,   547,
      43,    44,    45,    46,   501,     0,    48,   548,    50,   503,
     504,    53,   505,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   506,   507,    71,
       0,    72,    73,    74,   549,     0,     0,    77,    78,    79,
       0,     0,   509,    81,     0,     0,     0,     0,    83,   510,
      85,   511,   512,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   513,   100,   101,   514,   515,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,   110,
       0,     0,     0,     0,     0,     0,   116,   516,     0,     0,
       0,   118,   119,   120,   121,   517,   123,   124,   518,     0,
       0,     0,     0,     0,     0,     0,   519,   520,   131,     0,
       0,     0,   132,     0,   133,   521,     0,     0,     0,     0,
       0,     0,   139,     0,   140,   141,   142,   143,   522,   145,
     146,   147,   148,   149,   150,     0,     0,   151,   152,     0,
       0,   422,   155,   156,   157,   158,   159,   160,   161,   162,
     523,   550,   524,   166,   525,   526,   169,   170,   171,   172,
     173,   174,   527,   176,   528,   529,   530,   180,   181,   531,
     532,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     0,     0,
     249,   533,   251,   252,   253,   254,   255,     5,     6,     7,
       8,     9,    10,     0,     0,     0,    13,     0,     0,   419,
     420,     0,    16,    17,    18,   843,    20,    21,    22,    23,
       0,   844,   496,    27,     0,   421,    30,   499,    32,     0,
      34,     0,    35,    36,    37,    38,   845,    40,     0,     0,
      43,    44,    45,    46,   501,     0,    48,   846,    50,     0,
       0,    53,   505,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   506,   507,    71,
       0,    72,    73,    74,   847,     0,     0,    77,    78,    79,
       0,     0,   509,    81,     0,     0,     0,    82,    83,   510,
      85,   511,   512,    88,    89,   563,    91,     0,     0,     0,
       0,    93,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   513,   100,   101,   514,   515,     0,     0,     0,
       0,     0,     0,   104,   105,   106,   107,   108,   109,     0,
     564,   112,     0,   113,   114,     0,   116,   117,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,   518,     0,
     126,     0,     0,     0,     0,     0,   519,   520,   131,     0,
       0,     0,   132,     0,   133,   521,     0,     0,     0,     0,
       0,     0,   139,     0,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,     0,     0,     0,   152,   153,
       0,   422,   155,   156,   157,   158,   159,   160,   161,   162,
     523,     0,   524,   166,   525,   526,   169,   170,   171,   172,
     173,   174,   527,   176,   528,   529,   530,   180,   181,     0,
     532,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,     0,   248,     9,
      10,   533,   251,     0,     0,     0,     0,   419,   420,     0,
      16,    17,    18,     0,    20,    21,    22,   494,     0,     0,
     496,   497,     0,   421,    30,   499,    32,     0,    34,     0,
      35,    36,    37,    38,     0,    40,     0,     0,    43,    44,
      45,    46,   501,     0,    48,     0,    50,     0,     0,    53,
     505,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   506,   507,    71,     0,    72,
      73,    74,     0,     0,     0,    77,    78,    79,     0,     0,
     509,    81,     0,     0,     0,     0,    83,   510,    85,   511,
     512,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     513,   100,   101,   514,   515,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,     0,     0,     0,
       0,     0,     0,     0,   116,   516,     0,     0,     0,   118,
     119,   120,   121,   517,   123,   124,   518,     0,     0,     0,
       0,     0,     0,     0,   519,   520,   131,     0,     0,     0,
     132,     0,   133,   521,     0,     0,     0,     0,     0,     0,
     139,     0,   140,   141,   142,   143,   522,   145,   146,   147,
     148,   149,   150,     0,     0,     0,   152,     0,     0,   422,
     155,   156,   157,   158,   159,   160,   161,   162,   523,     0,
     524,   166,   525,   526,   169,   170,   171,   172,   173,   174,
     527,   176,   528,   529,   530,   180,   181,     0,   532,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,     0,     0,     0,     0,   533,
     251
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   316,   183,   932,   933,     5,     6,     7,     8,     5,
       6,     7,    76,   316,   346,   830,     0,   430,   431,   295,
    1058,     5,     6,     7,     8,  1042,    90,   680,    14,   771,
     786,   681,   682,   683,   684,   771,   696,   137,  1286,   264,
     590,   919,   263,   799,  1303,   595,   624,   625,   432,   868,
     114,  1367,  1368,     1,   279,   256,   257,   813,     1,    76,
    1499,  1139,   126,  1502,   128,   955,   622,   623,   624,   625,
    1005,  1082,    36,    36,     5,     6,     7,     8,    27,    28,
    1023,   622,   623,   467,   468,     5,     6,     7,     8,   728,
    1316,     8,    30,  1414,     1,   108,  1025,     1,    47,    39,
     286,   119,     1,  1032,    44,    45,    56,   122,    45,    30,
      47,   111,   143,    53,   659,   108,   661,   662,     1,   664,
      60,   666,    62,    63,     1,     3,    75,   111,     1,   674,
     675,    71,    95,    97,    97,   225,     1,     1,   971,    52,
     119,   225,   119,   108,   112,   113,   230,   119,   131,   425,
     132,    27,    28,   429,    95,   154,  1609,   169,    98,    31,
     108,   159,     1,   217,   113,   108,    33,     1,   146,   159,
     107,    47,   263,   111,   154,   247,   248,   157,   176,   157,
     111,    57,    49,   274,   148,   148,   176,   125,    97,    67,
     202,   111,    30,   114,    72,   188,     1,    97,   270,    75,
     254,   199,     9,    10,    80,   114,    97,   148,   190,   186,
      45,   210,   150,     1,   197,   187,   154,   130,   233,   157,
     233,   977,     1,     1,   314,    55,  1542,    57,    63,   148,
     314,   168,     1,     0,     1,   108,   112,   113,   114,   177,
     161,   119,   273,   932,   933,  1283,   225,    37,    38,   349,
      40,    41,  1269,     1,   569,   273,   256,   257,   175,     1,
     260,  1139,  1140,  1078,  1512,   451,   569,   217,    58,   108,
     235,   101,   256,   257,   108,  1031,   260,    97,   169,   247,
     248,   557,   971,   190,  1723,   225,   190,  1608,  1030,  1515,
     354,   190,  1028,   357,  1030,   295,  1307,   104,  1188,   877,
     878,  1236,  1245,   108,   254,  1316,  1759,   190,  1044,   273,
     273,   295,  1390,   190,   187,     1,  1005,   124,   957,   126,
     108,   259,  1155,   161,   114,   190,   190,   295,   307,   108,
     108,  1770,  1261,  1772,   875,   876,  1025,   354,   287,   108,
     357,   108,   214,  1032,   157,   137,   295,   154,   187,   169,
     148,   158,   187,   187,   273,   739,   256,   257,     1,   151,
     108,   252,   253,     1,   255,   313,   108,   174,   311,   645,
     915,   161,   436,   437,     1,  1131,   440,   317,   318,   319,
     444,   272,   187,   447,   448,   138,     0,     1,   195,    94,
     143,   455,  1708,   284,   619,   620,     1,   461,   462,   187,
     784,   622,   623,     1,   629,   469,   213,   108,   187,   187,
     611,   287,   476,   477,   478,   479,   108,   184,   187,   295,
     484,   251,   108,   101,   225,   425,   227,   303,   492,   429,
     220,  1670,   252,   253,   264,   255,   266,   108,     1,   187,
      77,   425,   262,   185,     1,   429,  1762,   277,   278,   279,
     108,   281,   272,   283,    95,   119,   456,   425,   458,   154,
       1,   429,   161,   108,   284,   108,  1155,     1,     1,     1,
     108,   261,   456,   537,   458,   273,     1,   108,   183,  1235,
     480,   108,   177,    27,    28,   485,  1745,   108,   552,   190,
     107,     1,   460,  1422,   108,   187,   480,   465,   184,   563,
     108,   485,   108,   108,  1515,  1247,   919,   475,   186,  1748,
     108,   128,  1390,   314,   482,   483,   187,   154,   191,   192,
    1256,  1399,   186,   491,   108,   456,   590,   458,   108,   187,
    1349,   595,  1410,    30,  1353,   599,   456,   950,   458,  1117,
    1118,  1119,  1790,   188,   187,   108,   184,  1236,   225,   480,
     227,   108,  1102,    95,   485,   137,   187,   557,   185,    95,
     480,  1117,  1118,  1119,   564,   485,   187,   108,    30,   113,
     184,  1231,  1261,   557,   108,   108,   108,   218,   219,   187,
     564,   187,   187,   108,   221,   222,   184,     9,    10,   557,
     866,   655,   233,     5,   978,   979,  1285,     9,   108,   983,
     700,   701,   263,   187,   604,   573,   574,   187,   108,  1626,
      95,   611,   148,   274,   111,  1371,   584,   893,   108,   201,
     604,   184,   622,   623,   624,   625,   108,   611,   125,  1013,
       5,   617,    97,   564,     9,   603,   604,   314,   622,   623,
     624,   625,    90,   184,   564,   645,   155,   154,   157,   111,
     184,   184,   184,   150,   875,     9,   881,    97,    42,   184,
     885,   645,    46,   125,   131,   154,   114,    51,   732,   157,
     155,   735,   157,   604,   184,    29,   218,   219,   126,     1,
     128,     3,   104,   148,    97,   749,    70,   187,   150,   753,
     754,   233,   154,    97,   184,   157,    95,   697,  1513,     1,
    1578,   697,   124,  1518,   126,   187,  1744,    97,   772,  1638,
     114,   182,   124,   697,   126,   177,   780,   157,   123,   783,
     159,   210,   134,   787,   114,   196,  1139,  1140,   237,  1471,
     197,    33,   154,  1422,   702,   148,   158,   176,   157,    45,
     118,    47,   154,   159,   143,    67,     9,    10,  1401,   124,
      72,   126,   174,   157,   145,   101,   157,  1735,  1736,   134,
     176,   182,  1691,    95,  1693,   829,   697,   157,   114,   147,
     124,    95,   126,   195,    80,   196,   776,   697,  1356,   154,
     776,   135,   160,   199,   168,   176,  1019,   171,  1021,     9,
      10,   213,   776,    54,     1,   157,  1456,   119,    59,  1777,
     154,   107,   186,   194,   868,  1783,   138,   807,   808,  1141,
    1499,   143,    95,  1502,   268,   123,   194,    78,     9,   143,
     186,   275,   157,   807,   808,   154,    33,  1756,   212,   157,
     269,  1107,  1065,   897,  1067,  1650,    97,   276,    29,  1654,
     157,   104,    49,   907,   210,   776,   154,   286,   177,   157,
     119,   166,   101,   821,   822,   823,   776,   825,   119,    54,
     143,   124,   168,   126,    59,   114,   866,   182,   932,   933,
     934,   935,    25,   101,   149,   154,   807,   808,   157,   101,
    1264,    34,   866,  1108,   104,   157,   114,   807,   808,  1114,
     165,   154,   114,   893,    96,   158,   269,   101,   866,   129,
     130,   887,    97,   276,   124,   107,   126,   971,    61,   893,
     114,   174,  1562,   286,   101,   117,  1569,  1570,   626,    95,
     149,   985,   630,   138,  1739,   138,   128,   114,   968,   123,
    1111,   107,   195,   124,   154,   126,   165,   123,   158,   154,
     980,   154,   703,   157,   135,   706,  1010,   201,   709,  1638,
     213,  1611,  1708,   138,   174,  1019,   210,  1021,   143,  1023,
     299,  1025,   119,   154,   277,   278,   279,  1282,  1032,   308,
     283,    54,   155,   123,   157,   195,    59,  1390,   123,  1363,
     154,   154,   353,   157,   157,   356,  1399,  1263,  1372,   437,
     129,   130,   440,   213,   678,   679,   444,  1410,   119,   447,
     448,  1065,  1691,  1067,  1693,   123,   232,   455,   234,   221,
     222,   223,   123,   461,   462,   232,   154,   234,   685,   686,
     154,   469,   687,   688,   123,  1340,  1679,  1680,   476,   477,
     478,   479,   123,  1348,  1723,   123,   484,   123,  1102,   133,
    1229,  1230,  1599,  1600,   492,  1348,   154,   141,   142,   216,
     144,   157,   119,  1713,   242,   157,   154,   241,   152,   241,
    1060,   314,   156,  1127,   158,     0,   190,  1756,    93,   163,
     167,   249,   100,    50,   200,   102,  1060,   103,   193,   155,
     157,  1770,    30,  1772,   184,   179,    47,   153,   184,   537,
     119,  1155,   184,   304,   184,   246,  1480,   154,   187,  1752,
    1760,     1,   119,   143,   552,   108,   187,  1107,   187,   203,
     204,   205,   206,   207,   208,   563,   154,  1117,  1118,  1119,
     154,   157,   157,  1107,   157,   157,   157,   143,   184,  1060,
    1116,   122,   154,  1117,  1118,  1119,   157,   157,   157,    35,
    1060,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,   599,    17,   214,    30,     3,   231,   230,   245,   119,
     190,   168,   170,   119,  1345,  1578,   190,   284,   170,    71,
    1138,   284,  1832,  1488,  1834,  1490,   231,    95,  1493,  1494,
      95,  1245,  1497,    95,  1844,  1249,   187,   150,  1503,   108,
      30,   108,   161,   161,   128,   133,   246,  1261,    95,   143,
     133,   184,   184,   119,   299,   108,   187,   655,   187,    95,
      97,  1275,    45,    97,   187,   187,  1492,   187,   184,   184,
     187,  1285,   154,   154,   154,   154,   154,   154,    95,   225,
     143,   237,   231,   190,    33,   233,   143,   184,   133,  1239,
      95,    30,   286,  1239,   170,    95,   299,   227,   154,   128,
    1314,   119,    95,   119,   148,  1239,   198,   161,   133,  1535,
     184,   133,    97,  1263,   154,   119,   148,   101,   190,   101,
     184,   154,   143,   184,  1274,  1339,   122,    35,  1274,  1263,
     154,    30,   119,   245,    80,  1349,   108,   735,   107,  1353,
    1274,   108,   285,  1293,   258,   254,   267,  1293,   157,   157,
     157,   749,   260,    30,   157,   753,   754,   145,  1239,  1293,
     157,   286,   157,  1313,    30,   157,    30,  1381,   306,  1239,
    1320,   190,   227,   187,   772,   187,  1641,   145,   148,  1313,
    1645,   187,   780,   287,   128,   783,  1320,   148,   187,   787,
     108,   143,   101,  1274,     7,   184,   187,   198,  1624,   133,
      97,   187,  1352,   233,  1274,   233,   233,   157,  1422,  1635,
    1636,   190,  1293,  1639,   237,   186,   157,   157,  1352,   154,
    1646,   107,   233,  1293,   148,   119,   119,    78,   187,   148,
     250,   829,  1313,   282,    79,   286,   187,   250,  1452,  1320,
     187,    30,   187,  1313,   187,   187,    30,   108,   170,   187,
    1320,   187,   184,   148,   127,   257,   148,   127,    97,   184,
     143,   271,    95,   184,  1729,   154,    30,   111,   184,   184,
     184,  1352,    97,   316,   187,   187,   148,    95,    54,   170,
     197,    95,  1496,    30,   265,  1499,   280,   108,  1502,   108,
     119,    95,   225,    95,   197,   197,   119,   198,   225,   897,
    1514,    94,   119,   183,  1769,  1519,  1732,   287,  1773,   907,
     197,   119,   119,   119,   199,   225,  1191,   293,   738,   972,
    1236,   287,  1033,   260,  1713,   451,   431,   305,   305,   260,
     305,  1760,   306,   306,   932,   933,   934,   935,  1552,  1553,
    1805,   306,  1492,  1808,  1136,  1771,   655,   869,   789,  1555,
    1382,  1123,   263,  1374,  1370,  1367,   552,  1275,  1492,  1280,
    1283,  1288,   658,  1789,   657,   677,  1831,   935,  1307,   712,
     830,  1783,  1777,   971,  1190,  1021,  1350,   341,  1804,  1339,
    1349,  1399,  1578,  1140,   459,  1535,   459,   985,  1575,  1149,
    1410,  1004,  1403,  1213,  1446,  1602,  1400,    -1,   593,    -1,
    1826,  1535,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1835,
      -1,    -1,  1010,    -1,  1532,  1533,  1534,    -1,    -1,    -1,
      -1,  1019,    -1,  1021,  1638,  1023,  1640,  1025,  1642,    -1,
    1644,    -1,    -1,    -1,  1032,    -1,    -1,  1651,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1065,    -1,  1067,
      -1,    -1,    -1,    -1,  1624,    -1,    -1,  1691,    -1,  1693,
      -1,    -1,    -1,    -1,    -1,  1635,  1636,    -1,    -1,  1639,
    1624,    -1,    -1,    -1,    -1,  1709,  1646,    -1,  1712,    -1,
      -1,  1635,  1636,    -1,    -1,  1639,    -1,    -1,    -1,  1723,
      -1,    -1,  1646,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1734,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1756,    -1,    -1,    -1,    -1,    -1,    -1,  1667,
    1764,    -1,    -1,    -1,    -1,    -1,  1770,  1155,  1772,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,  1689,    -1,    37,    38,    -1,    40,    41,    -1,  1793,
      -1,    -1,  1732,    47,    -1,    -1,    -1,    -1,  1802,    -1,
      -1,    -1,    -1,    57,    58,    -1,    -1,    -1,  1732,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1822,    -1,
      -1,    75,    -1,  1827,    -1,    -1,    80,    -1,    -1,    -1,
      -1,  1771,    -1,    -1,    -1,  1839,    -1,    -1,  1842,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1771,    -1,  1789,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1245,   112,   113,
     114,  1249,    -1,    -1,  1804,  1789,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1261,    -1,    -1,    -1,    -1,    -1,    -1,
    1804,    -1,    -1,    -1,    -1,    -1,  1826,  1275,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1835,    -1,  1285,    -1,    -1,
      -1,    -1,  1826,    -1,    -1,    -1,    -1,   161,    -1,    -1,
      -1,  1835,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1314,    -1,    -1,    -1,
     564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1339,    -1,    -1,   588,   589,    -1,   591,   592,   593,
     594,    -1,   596,    -1,    -1,    -1,   220,    -1,   602,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   610,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1381,    -1,    -1,    -1,    -1,   632,   633,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,   642,    -1,
      -1,   645,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   287,  1422,    -1,    -1,    -1,    -1,    -1,
      -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1452,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   708,    -1,    -1,    -1,   712,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1496,    -1,
      -1,  1499,    -1,    -1,  1502,    -1,    -1,   751,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1514,    -1,    -1,    -1,
      -1,  1519,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   788,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1552,  1553,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     814,    -1,    -1,    -1,   818,   819,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   827,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1638,    -1,  1640,    -1,  1642,    -1,  1644,    -1,    -1,   893,
      -1,    -1,    -1,  1651,    -1,   899,   900,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1691,    -1,  1693,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1709,    -1,    -1,  1712,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1723,    -1,    -1,    -1,   973,
      -1,    -1,    -1,    -1,    -1,    -1,  1734,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1756,    -1,
      -1,    -1,    -1,    -1,  1008,    -1,  1764,    -1,    -1,    -1,
      -1,    -1,  1770,    -1,  1772,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1027,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1793,    -1,    -1,    -1,  1043,
      -1,    -1,    -1,    -1,  1802,    -1,    -1,    -1,    -1,    -1,
    1054,  1055,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1822,  1069,    -1,    -1,  1072,  1827,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1839,    -1,    -1,  1842,  1089,  1090,  1091,    -1,  1093,
    1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,    -1,    -1,
    1104,  1105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,     3,    -1,    -1,  1251,    -1,  1253,
      -1,  1255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1263,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1272,    -1,
      -1,    -1,    -1,    -1,  1278,  1279,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    50,    51,  1297,    -1,    -1,  1300,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,    95,    96,    97,    -1,
      -1,   100,   101,   102,   103,    -1,    -1,    -1,   107,   108,
      -1,    -1,    -1,    -1,    -1,   114,    -1,    -1,   117,   118,
     119,    -1,    -1,   122,    -1,    -1,  1370,    -1,   127,   128,
    1374,  1375,    -1,    -1,   133,    -1,  1380,    -1,   137,    -1,
      -1,    -1,   141,   142,    -1,   144,    -1,   146,   147,    -1,
      -1,    -1,   151,   152,    -1,    -1,   155,   156,   157,   158,
     159,   160,    -1,    -1,   163,    -1,    -1,    -1,   167,   168,
      -1,    -1,   171,    -1,    -1,    -1,    -1,   176,    -1,    -1,
     179,    -1,    -1,    -1,    -1,   184,   185,   186,   187,   188,
      -1,   190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,
     199,   200,   201,    -1,   203,   204,   205,   206,   207,   208,
      -1,   210,    -1,   212,    -1,    -1,    -1,    -1,   217,   218,
     219,  1465,    -1,    -1,    -1,  1469,    -1,    -1,    -1,  1473,
      -1,  1475,    -1,    -1,   233,    -1,   235,    -1,   237,  1483,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1491,  1492,    -1,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1511,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1523,
    1524,  1525,  1526,    -1,  1528,  1529,    -1,  1531,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1546,    -1,    -1,    -1,    -1,  1551,    -1,    -1,
      -1,    -1,   311,  1557,   313,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1617,    -1,  1619,    -1,    -1,  1622,    -1,
      -1,  1625,    -1,    -1,    -1,    -1,  1630,  1631,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1639,    -1,    -1,    -1,  1643,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1660,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1671,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1728,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1771,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,    -1,    -1,    -1,  1800,    -1,    -1,    -1,
    1804,    11,    12,    -1,    -1,  1809,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,  1825,    -1,    33,    34,  1829,    36,    37,    38,    39,
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
     189,   190,   191,   192,    -1,   194,    -1,   196,    -1,   198,
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
     189,   190,   191,   192,    -1,   194,    -1,   196,    -1,   198,
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
     189,   190,   191,   192,    -1,   194,    -1,   196,    -1,   198,
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
     319,   320,   321,   322,    11,    12,    -1,    -1,    -1,    16,
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
     307,   308,   309,   310,    -1,   312,    -1,   314,   315,   316,
     317,   318,   319,   320,    -1,   322,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,   184,
      -1,   186,    -1,   188,   189,   190,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,   190,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,   190,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,   190,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,   190,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,   190,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,   190,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,   189,    -1,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,   189,    -1,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
     185,   186,    -1,   188,   189,    -1,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,   189,    -1,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,   313,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
     145,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,    -1,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,   153,   154,
     155,    -1,   157,   158,    -1,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
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
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,    -1,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,    -1,   152,   153,   154,
     155,    -1,   157,   158,    -1,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,
      -1,   196,    -1,   198,    -1,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
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
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,
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
     305,   306,   307,   308,   309,    -1,    -1,    -1,    -1,   314,
     315,   316,   317,   318,   319,   320,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
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
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,
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
      -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,   188,
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
     319,   320,    16,    -1,    18,    19,    -1,    -1,    -1,    -1,
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
     308,   309,    -1,    -1,    16,    -1,   314,   315,   316,   317,
     318,   319,   320,    25,    26,    -1,    -1,    -1,    30,    -1,
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
      -1,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,
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
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
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
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
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
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
      -1,   151,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,
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
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
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
     304,   305,   306,   307,   308,   309,    -1,    -1,    -1,    -1,
     314,   315,   316,   317,   318,   319,   320,    21,    22,    23,
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
      -1,   125,    -1,   127,   128,   129,   130,    -1,   132,    -1,
      -1,    -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,
      -1,    -1,    -1,   147,   148,   149,   150,   151,   152,    -1,
     154,   155,    -1,   157,   158,    -1,   160,   161,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,    -1,   212,   213,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,    -1,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,    -1,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,    -1,   312,    25,
      26,   315,   316,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    -1,    40,    41,    42,    43,    -1,    -1,
      46,    47,    -1,    49,    50,    51,    52,    -1,    54,    -1,
      56,    57,    58,    59,    -1,    61,    -1,    -1,    64,    65,
      66,    67,    68,    -1,    70,    -1,    72,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    -1,    95,
      96,    97,    -1,    -1,    -1,   101,   102,   103,    -1,    -1,
     106,   107,    -1,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,   151,   152,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,    -1,   212,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,    -1,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,    -1,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,    -1,    -1,    -1,    -1,   315,
     316
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
     413,   414,   415,   416,   422,   424,   426,   427,   428,   433,
     452,   455,   459,   462,   463,   469,   470,   471,   472,   474,
     475,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     487,   488,   489,   490,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   523,   524,   525,   526,   527,   528,   542,   543,   545,
     546,   547,   548,   549,   550,   551,   552,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   574,
     579,   580,   581,   582,   583,   584,   587,   645,   646,   647,
     648,   650,   651,   652,   653,   654,   657,   658,   659,    33,
      34,    49,   215,   391,   392,   393,   391,   391,   392,   393,
     157,   157,    37,    38,    40,    41,    47,    57,    58,    75,
      80,   112,   113,   114,   161,   220,   261,   287,   295,   303,
     372,   373,   377,   378,   379,   161,   154,   157,   154,   157,
     154,   157,     1,   157,   380,   157,    25,    34,    61,   119,
     273,   432,   434,   435,   157,   154,   157,   157,   157,   119,
     154,   157,   157,   157,    77,   154,   221,   222,   123,   123,
     123,   154,   157,    39,    43,    45,    46,    47,    48,    51,
      60,    68,    71,    73,    74,    76,    91,    92,    98,   106,
     113,   115,   116,   136,   139,   140,   161,   169,   172,   180,
     181,   189,   202,   224,   226,   228,   229,   236,   238,   239,
     240,   243,   244,   315,   507,   658,   123,   119,   400,   123,
     123,    39,    44,    45,    53,    60,    62,    63,    71,    98,
     225,   657,   119,   123,   123,   184,   391,   393,   414,   649,
      48,    73,    74,   119,   154,   185,   244,   413,   415,   426,
     187,   413,   657,   154,   154,   123,   657,    18,    19,   657,
     123,   123,   123,   499,   154,    31,   214,   216,   225,   227,
     314,   225,   227,   314,   225,   314,   225,   230,   314,   119,
     241,   241,   242,   157,   154,   395,   311,   413,   313,   413,
     314,   322,   337,   337,     0,   339,   340,    33,    49,   342,
     359,     1,   190,   336,   190,   336,   113,   374,   394,   413,
     108,   190,   108,   336,   190,    42,    46,    51,    70,   168,
     171,   186,   212,   407,   417,   418,   423,   424,   425,   440,
     441,   445,     3,    67,    72,   119,   419,   167,    93,   133,
     141,   142,   144,   152,   156,   158,   163,   179,   203,   204,
     205,   206,   207,   208,   491,   492,   249,   100,   159,   176,
     199,   118,   147,   160,   194,   201,   210,   137,   151,    50,
     200,   102,   103,   159,   176,   489,   193,   154,   496,   499,
     191,   192,   155,   511,   512,   507,   511,   507,   157,   511,
     157,   146,   157,   184,   184,   184,   184,   375,   514,   375,
      30,   656,   182,   196,   182,   196,   166,   182,   658,   657,
     169,   202,    47,   657,   153,   119,    45,    47,    80,   107,
     168,   657,   221,   222,   223,   246,   618,   657,   657,   304,
     138,   143,   113,   287,   295,   377,   657,   392,   187,   392,
      45,    63,   187,   570,   571,   413,   187,   194,   657,   429,
     430,   657,   119,   187,   381,   382,   154,   397,   413,     1,
     161,   656,   114,   161,   355,   656,   657,   119,   143,   108,
     187,   413,    30,   187,   657,   657,   657,   453,   454,   657,
     392,   187,   413,   413,   572,   657,   392,   154,   154,   413,
     187,   194,   657,   657,   143,   453,   184,   184,   122,   108,
     184,   157,   157,   157,   657,   154,   185,   418,   187,    35,
     530,   531,   532,   413,   413,     8,   175,    17,   413,   214,
      30,   414,   414,    39,    45,    60,    71,    98,   510,   658,
     414,   414,   414,   649,   414,   510,   414,   231,   230,   585,
     586,   657,   190,   190,   414,   413,   393,   413,   245,   410,
     411,   311,   313,   414,   337,   190,   336,   190,   336,     3,
     343,   359,   389,     1,   343,   359,   389,    33,   360,   389,
     360,   389,   400,   336,   400,   414,   414,   119,   168,   170,
     170,   414,   394,   414,   284,   284,   429,   119,   436,   471,
     472,   474,   474,   474,   474,   473,   474,   474,   474,    71,
     475,   479,   479,   478,   480,   480,   480,   480,   481,   481,
     482,   482,   231,    95,    95,    95,   497,   391,   499,   499,
     413,   512,   145,   187,   414,   522,   187,   150,   187,   522,
     108,   187,   187,   108,   108,   380,    30,   658,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,   362,   363,
     364,    95,   138,   143,   368,   369,   370,   657,   161,   161,
     362,   656,   128,   133,    55,    57,   101,   251,   264,   266,
     277,   278,   279,   281,   283,   619,   620,   621,   622,   623,
     624,   631,   637,   638,   246,    95,   299,   657,   143,   414,
     119,   657,   657,   133,   184,   184,   187,   187,   184,   108,
     187,   108,   187,   108,    36,    95,    97,   148,   431,   432,
     553,   657,    95,   108,   187,   391,   187,   657,    97,    45,
     657,   656,    97,   143,   553,   657,   414,   435,   184,   187,
     187,   187,   187,   108,   188,   148,   553,   184,   187,   187,
     154,   184,   392,   392,   184,   108,   187,   108,   187,   143,
     553,   414,   188,   414,   414,   413,   413,   413,   657,   531,
     532,   131,   197,   184,   184,   184,   132,   190,    95,   218,
     219,   233,    95,   218,   219,   233,   233,   233,    95,    95,
     237,   225,   231,   108,   235,   143,   190,   187,   413,   184,
     508,   591,   411,   233,   359,    33,    33,   190,   336,   190,
     114,   394,   657,   170,   414,   446,   447,   119,   414,   442,
     443,   657,    56,   217,   254,   420,   421,   474,   154,   157,
     259,   495,   514,   592,   595,   596,   597,   598,   599,   603,
     605,   607,   608,    47,   153,   157,   211,   317,   318,   319,
     320,   554,   556,   558,   560,   575,   576,   577,   578,   655,
     657,   554,   486,   559,   657,   486,   184,   185,   108,   187,
     187,   514,   149,   165,   149,   165,   138,   397,   380,   363,
     133,   556,   370,   414,   553,   656,   656,   129,   130,   656,
     277,   278,   279,   283,   657,   263,   274,   263,   274,    30,
     286,    97,   114,   157,   625,   628,   619,    39,    44,    53,
      60,    62,    71,    98,   225,   317,   318,   319,   384,   560,
     655,   227,   299,   308,   414,   657,    95,   299,   656,   154,
     572,   573,   657,   572,   573,   119,   430,   128,   554,   119,
     414,   148,   432,   148,    36,   148,   431,   432,   553,   554,
     382,    95,   184,   198,   133,   354,   656,   161,   133,    97,
     354,   414,   143,   432,   154,   119,   414,   414,   148,   101,
     456,   457,   458,   460,   461,   101,   464,   465,   466,   467,
     392,   184,   184,   154,   572,   572,   414,   143,   190,   414,
     122,   187,   187,   187,    35,   532,   131,   197,     9,    10,
     104,   124,   126,   154,   195,   527,   529,   540,   541,   544,
     154,    30,   232,   234,   414,   414,   414,   232,   234,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   510,   119,
     414,   414,    48,    73,    74,   244,   394,   415,   426,   245,
     588,   589,   154,   210,   395,   414,   190,   114,   389,   389,
     389,   446,    96,   107,   117,   128,   448,   449,   450,   451,
     108,   657,   107,   444,   108,   148,   553,   254,    54,    59,
      78,   119,   431,   437,   438,   439,   421,   413,   592,   599,
     154,   285,   476,   644,    97,   169,   252,   253,   255,   262,
     272,   284,   593,   594,   613,   614,   615,   616,   639,   642,
     258,   260,   600,   618,   267,   604,   640,   247,   248,   270,
     609,   610,   157,   157,   556,   157,   157,   157,   157,   157,
     145,   176,   194,   555,   145,   145,   414,   138,   397,   574,
     369,   286,    30,    97,   114,   157,   632,    30,   625,   555,
     555,   497,   287,   306,   553,   384,   227,   190,   391,   187,
     187,   145,   187,   187,   430,   148,   431,   657,   414,   148,
     414,   128,   414,   148,   432,   148,   554,   394,   414,   656,
     108,   354,   414,   143,   391,   454,   414,   414,   114,   457,
     458,   101,   418,   114,   458,   461,   119,   468,   554,   101,
     114,   465,   101,   114,   467,   184,   391,   187,   187,   414,
     414,   198,   464,   133,   195,   529,     7,   392,   657,   195,
     540,   392,   190,   233,   233,   233,   233,    97,   237,   237,
     586,   418,   157,   157,   157,   418,   591,   589,   508,   656,
     129,   130,   450,   451,   451,   447,   143,   553,   656,   443,
     414,   148,   119,   119,   414,   657,   439,    78,   184,   187,
     592,   606,   250,   217,   254,   268,   275,   643,    97,   256,
     257,   641,   250,   596,   643,   478,   613,   597,   148,   282,
     601,   602,   641,   286,   612,    79,   611,   187,   194,   554,
     557,   187,   187,   187,   187,   187,   187,   187,    30,   137,
     201,   634,   635,   636,    30,   633,   634,   271,   629,   108,
     626,   170,   657,   257,   497,   184,   414,   148,   414,   148,
     431,   414,   148,   414,   127,   127,    97,   656,   414,   184,
     418,   418,   414,   394,   414,   418,   418,   657,   210,   418,
     119,   468,   119,   418,   119,   468,   418,   184,   114,   532,
     657,   195,   184,   532,   657,   184,   414,   414,   414,   414,
     316,   414,   414,   414,   413,   413,   413,   154,   590,   451,
     414,   143,   414,   657,   657,   438,   414,   184,   480,    52,
     130,   478,   478,   269,   276,   286,   617,   617,   598,   154,
     280,    95,   187,   108,   187,   632,   632,   636,   108,   187,
      30,   630,   641,   627,   628,   187,   386,   387,   497,   119,
     225,   307,   287,   170,   414,   414,   148,   414,   394,   414,
     354,   414,   394,    95,   554,   394,   414,   657,   418,   657,
     414,   657,   418,   394,   119,    94,   183,   533,   532,   657,
     197,   532,   414,   187,   187,   187,   413,   444,   414,    54,
     478,   478,   199,   413,   554,   554,    95,    30,   265,   108,
     108,   451,   553,   657,   119,   225,   657,   386,   414,   468,
      95,   418,    95,   657,     5,   134,   536,   537,   539,   541,
      29,   135,   534,   535,   538,   541,   197,   532,   197,   198,
     464,   184,   444,   119,   478,   184,   554,   628,   387,   451,
     305,   657,   119,   225,   418,   468,   394,   414,   468,   418,
      94,   134,   539,   183,   135,   538,   197,   114,   657,   414,
     305,   657,   119,   394,   414,   418,   418,   119,   293,   305,
     657,   657,   306,   414,   306,   418,   497,   497,   199,   287,
     657,   225,   119,   657,   306,   497
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
     415,   415,   415,   415,   416,   417,   418,   419,   419,   420,
     420,   420,   421,   421,   422,   422,   423,   424,   424,   424,
     425,   425,   425,   425,   425,   426,   426,   427,   427,   427,
     428,   429,   429,   429,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   430,   430,   431,   432,   433,   434,
     434,   435,   435,   435,   435,   436,   436,   437,   437,   437,
     438,   438,   438,   439,   439,   439,   440,   441,   442,   442,
     443,   443,   443,   443,   443,   443,   444,   445,   445,   446,
     446,   447,   447,   448,   448,   448,   448,   448,   448,   448,
     449,   449,   450,   450,   451,   452,   452,   453,   453,   454,
     454,   455,   456,   456,   457,   458,   458,   459,   460,   460,
     461,   462,   462,   463,   463,   464,   464,   465,   465,   466,
     466,   467,   467,   468,   468,   469,   470,   470,   471,   471,
     472,   472,   472,   472,   472,   473,   472,   472,   472,   472,
     474,   474,   475,   475,   476,   476,   477,   477,   478,   478,
     478,   479,   479,   479,   479,   479,   480,   480,   480,   481,
     481,   481,   482,   482,   483,   483,   484,   484,   485,   485,
     486,   486,   487,   487,   488,   488,   488,   488,   489,   489,
     489,   490,   490,   491,   491,   491,   491,   491,   491,   492,
     492,   492,   493,   493,   493,   493,   494,   495,   495,   496,
     496,   496,   497,   497,   497,   497,   498,   499,   499,   499,
     500,   500,   501,   501,   501,   501,   502,   502,   503,   503,
     503,   503,   503,   503,   503,   504,   504,   505,   505,   506,
     506,   506,   506,   506,   507,   507,   508,   508,   509,   509,
     509,   509,   510,   510,   510,   510,   511,   511,   512,   513,
     513,   513,   513,   513,   513,   513,   513,   513,   513,   513,
     513,   513,   513,   514,   514,   515,   515,   515,   516,   517,
     517,   518,   519,   520,   521,   521,   522,   522,   522,   522,
     523,   523,   524,   525,   526,   526,   527,   527,   527,   528,
     528,   528,   528,   528,   528,   529,   529,   530,   530,   531,
     532,   532,   533,   533,   534,   534,   535,   535,   535,   535,
     536,   536,   537,   537,   537,   537,   538,   538,   539,   539,
     540,   540,   540,   540,   541,   541,   541,   541,   542,   542,
     543,   543,   544,   545,   545,   545,   545,   545,   545,   545,
     546,   547,   547,   548,   548,   549,   550,   551,   551,   552,
     552,   553,   554,   554,   554,   555,   555,   555,   556,   556,
     556,   556,   556,   556,   556,   557,   557,   558,   559,   560,
     560,   560,   560,   560,   560,   560,   560,   560,   560,   561,
     562,   563,   563,   563,   564,   565,   566,   567,   567,   567,
     568,   568,   568,   568,   568,   569,   570,   570,   570,   570,
     570,   570,   570,   571,   572,   573,   574,   575,   575,   576,
     577,   577,   578,   579,   579,   579,   580,   580,   580,   580,
     580,   580,   580,   580,   580,   580,   581,   581,   582,   582,
     583,   584,   585,   585,   586,   587,   588,   588,   589,   590,
     591,   591,   592,   593,   593,   594,   594,   595,   595,   596,
     596,   597,   597,   598,   598,   599,   600,   600,   601,   601,
     602,   603,   603,   603,   604,   604,   605,   606,   606,   607,
     608,   608,   609,   609,   610,   610,   610,   611,   611,   612,
     612,   613,   613,   613,   613,   613,   614,   615,   616,   617,
     617,   617,   618,   618,   619,   619,   619,   619,   619,   619,
     619,   619,   620,   620,   620,   620,   621,   621,   622,   623,
     623,   624,   624,   624,   625,   625,   626,   626,   627,   627,
     628,   629,   629,   630,   630,   631,   631,   631,   632,   632,
     633,   633,   634,   634,   635,   635,   636,   636,   637,   638,
     638,   639,   639,   639,   640,   641,   641,   641,   641,   642,
     642,   643,   643,   644,   645,   645,   646,   646,   647,   647,
     648,   649,   649,   650,   650,   650,   651,   652,   653,   654,
     655,   655,   655,   656,   657,   657,   657,   657,   657,   657,
     657,   657,   657,   657,   657,   657,   657,   657,   657,   657,
     657,   657,   657,   657,   657,   657,   657,   658,   658,   658,
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
     658,   658,   658,   658,   658,   658,   658,   658,   659
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
       1,     1,     1,     1,     2,     2,     1,     2,     2,     1,
       1,     2,     4,     3,     5,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     2,
       1,     1,     4,     3,     3,     5,     4,     6,     4,     6,
       5,     7,     4,     5,     5,     6,     3,     3,     2,     1,
       3,     4,     5,     3,     6,     4,     5,     1,     2,     3,
       1,     2,     1,     6,     3,     3,     2,     3,     1,     3,
       4,     5,     6,     5,     1,     2,     2,     3,     4,     1,
       3,     1,     2,     1,     1,     1,     2,     2,     2,     3,
       1,     1,     2,     2,     2,     5,     5,     1,     4,     3,
       4,     8,     1,     2,     3,     2,     3,     8,     1,     2,
       3,     8,    10,     8,    10,     1,     2,     4,     7,     1,
       2,     4,     7,     1,     3,     8,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     0,     4,     3,     3,     3,
       1,     5,     1,     3,     0,     1,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     4,     1,     4,     1,     4,     1,     4,
       1,     2,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     5,     6,     4,     1,     2,     3,
       2,     2,     1,     2,     2,     1,     1,     1,     3,     3,
       1,     1,     1,     2,     1,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     4,     1,     2,     3,     1,
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
       7,     2,     1,     2,     3,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     4,     4,     3,     3,     3,     3,     4,     4,
       3,     4,     6,     4,     6,     4,     3,     4,     6,     6,
       4,     6,     6,     4,     1,     2,     1,     1,     1,     4,
       5,     6,     3,     3,     3,     3,     5,     7,     7,     5,
       5,     5,     7,     7,     5,     5,     3,     3,     5,     7,
       5,     7,     1,     4,     3,     5,     1,     2,     3,     3,
       1,     3,     2,     0,     1,     1,     2,     1,     3,     1,
       3,     1,     4,     1,     2,     3,     0,     1,     0,     1,
       4,     2,     3,     1,     0,     1,     4,     0,     1,     2,
       1,     3,     0,     1,     2,     2,     1,     0,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     2,     2,     3,     1,
       2,     2,     5,     2,     1,     1,     0,     2,     1,     3,
       4,     0,     2,     0,     2,     4,     4,     3,     2,     3,
       1,     3,     0,     1,     1,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     3,     2,     3,     3,     4,     2,
       2,     1,     1,     3,     2,     3,     2,     3,     2,     3,
       3,     3,     5,     5,     5,     8,     5,     3,     5,     7,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
  "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE", "UNARY_PREC",
  "STEP_REDUCE", "SIMPLEMAPEXPR_REDUCE", "MULTIPLICATIVE_REDUCE", "SELECT",
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
      -1,   341,   342,   190,   359,   190,    -1,    34,   161,   657,
     133,   656,   190,    -1,   343,    -1,   342,   190,   343,    -1,
     342,   336,   343,    -1,   344,    -1,   352,    -1,   357,    -1,
     358,    -1,   366,    -1,   345,    -1,   346,    -1,   347,    -1,
     348,    -1,   349,    -1,   350,    -1,   351,    -1,   579,    -1,
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
     574,    -1,    81,    -1,    89,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    90,    -1,    86,    -1,    87,    -1,
      88,    -1,    33,    57,   657,    30,    -1,    33,   261,   618,
      -1,    33,   112,   153,   368,    -1,    95,   556,   369,    -1,
     369,    -1,   370,    -1,   138,    -1,   138,   370,    -1,   143,
     414,    -1,    33,   372,   143,   414,    -1,    33,   372,   138,
      -1,    33,   372,   138,   143,   414,    -1,   113,   119,   657,
      -1,   113,   119,   657,   553,    -1,   373,   113,   119,   657,
      -1,   373,   113,   119,   657,   553,    -1,   374,    -1,   373,
     374,    -1,    27,    -1,    27,   157,   375,   187,    -1,    28,
      -1,    28,   157,   375,   187,    -1,   514,    -1,   375,   108,
     514,    -1,    33,   377,    -1,    33,   373,   377,    -1,   378,
      -1,   379,    -1,    47,   658,   380,   397,    -1,    47,   658,
     380,   138,    -1,    75,    47,   658,   380,   397,    -1,    75,
      47,   658,   380,   138,    -1,   157,   187,    -1,   157,   381,
     187,    -1,   157,   187,    95,   554,    -1,   157,   381,   187,
      95,   554,    -1,   382,    -1,   381,   108,   382,    -1,   119,
     657,    -1,   119,   657,   553,    -1,    33,   287,   657,    -1,
      33,   287,   657,    95,   384,    -1,    33,   373,   287,   657,
      -1,    33,   373,   287,   657,    95,   384,    -1,   560,    -1,
     560,   555,    -1,   655,    -1,   655,   555,    -1,    33,   295,
     657,   299,   227,   497,   170,   386,    -1,    33,   373,   295,
     657,   299,   227,   497,   170,   386,    -1,   387,    -1,   386,
     108,   387,    -1,   497,    -1,   497,   553,    -1,   497,   451,
      -1,   497,   553,   451,    -1,    33,   303,   304,   657,   299,
     287,   657,   119,   657,   305,   414,    -1,    33,   303,   304,
     657,   299,   287,   657,   225,   119,   657,   305,   293,   306,
     497,    -1,    33,   303,   304,   657,   299,   287,   657,   307,
     225,   119,   657,   305,   414,    -1,    33,   303,   304,   657,
     308,   306,   257,   287,   657,   225,   119,   657,   306,   497,
     199,   287,   657,   225,   119,   657,   306,   497,    -1,   390,
      -1,   392,    -1,   393,    -1,    -1,   392,    -1,   393,    -1,
      -1,   413,    -1,   393,   413,    -1,   394,    -1,   393,   394,
      -1,   393,   413,   336,   394,    -1,   395,    -1,   398,    -1,
     401,    -1,   402,    -1,   403,    -1,   404,    -1,   405,    -1,
     406,    -1,   408,    -1,   463,    -1,   459,    -1,   409,    -1,
     412,    -1,   154,   393,   184,    -1,   154,   184,    -1,   154,
     391,   184,    -1,   154,   391,   184,    -1,   399,   190,    -1,
     399,   108,   400,    -1,   113,   400,    -1,   373,   113,   400,
      -1,   119,   657,    -1,   119,   657,   553,    -1,   119,   657,
     143,   414,    -1,   119,   657,   553,   143,   414,    -1,   119,
     657,   143,   414,   190,    -1,   415,   190,    -1,   240,   242,
     414,   190,    -1,   243,   157,   413,   187,   394,    -1,   238,
     241,   190,    -1,   239,   241,   190,    -1,   426,   407,    -1,
     418,   394,    -1,    48,   157,   413,   187,   198,   394,   127,
     394,    -1,   244,   395,   410,    -1,   411,    -1,   410,   411,
      -1,   245,   591,   395,    -1,   190,    -1,   414,    -1,   413,
     108,   414,    -1,   413,   336,   414,    -1,   416,    -1,   455,
      -1,   462,    -1,   469,    -1,   587,    -1,   415,    -1,   470,
      -1,   452,    -1,   580,    -1,   581,    -1,   583,    -1,   582,
      -1,   584,    -1,   652,    -1,   650,    -1,   653,    -1,   654,
      -1,   651,    -1,   426,   417,    -1,   418,   414,    -1,   186,
      -1,    67,   284,    -1,    72,   284,    -1,   217,    -1,   254,
      -1,    56,   254,    -1,   420,   437,    78,   414,    -1,   420,
      78,   414,    -1,   428,   419,   436,   421,   421,    -1,   428,
     419,   436,   421,    -1,    42,   119,   657,    -1,   427,    -1,
     433,    -1,   422,    -1,   424,    -1,   440,    -1,   445,    -1,
     441,    -1,   423,    -1,   424,    -1,   426,   425,    -1,   428,
     119,   429,    -1,    46,     1,   429,    -1,   428,     3,    -1,
      46,    -1,   430,    -1,   429,   108,   119,   430,    -1,   429,
     108,   430,    -1,   657,   148,   414,    -1,   657,    36,   128,
     148,   414,    -1,   657,   553,   148,   414,    -1,   657,   553,
      36,   128,   148,   414,    -1,   657,   431,   148,   414,    -1,
     657,    36,   128,   431,   148,   414,    -1,   657,   553,   431,
     148,   414,    -1,   657,   553,    36,   128,   431,   148,   414,
      -1,   657,   432,   148,   414,    -1,   657,   553,   432,   148,
     414,    -1,   657,   431,   432,   148,   414,    -1,   657,   553,
     431,   432,   148,   414,    -1,    97,   119,   657,    -1,   273,
     119,   657,    -1,    51,   434,    -1,   435,    -1,   434,   108,
     435,    -1,   119,   657,   143,   414,    -1,   119,   657,   553,
     143,   414,    -1,   432,   143,   414,    -1,   119,   657,   553,
     432,   143,   414,    -1,   119,   657,   148,   414,    -1,   119,
     657,   553,   148,   414,    -1,   438,    -1,   119,   657,    -1,
     119,   657,   438,    -1,   431,    -1,   431,   439,    -1,   439,
      -1,    59,   119,   657,    54,   119,   657,    -1,    54,   119,
     657,    -1,    59,   119,   657,    -1,   212,   414,    -1,   171,
     170,   442,    -1,   443,    -1,   442,   108,   443,    -1,   119,
     657,   143,   414,    -1,   119,   657,   553,   143,   414,    -1,
     119,   657,   553,   143,   414,   444,    -1,   119,   657,   143,
     414,   444,    -1,   414,    -1,   414,   444,    -1,   107,   656,
      -1,   168,   170,   446,    -1,    70,   168,   170,   446,    -1,
     447,    -1,   446,   108,   447,    -1,   414,    -1,   414,   448,
      -1,   449,    -1,   450,    -1,   451,    -1,   449,   450,    -1,
     449,   451,    -1,   450,   451,    -1,   449,   450,   451,    -1,
      96,    -1,   117,    -1,   128,   129,    -1,   128,   130,    -1,
     107,   656,    -1,    68,   119,   453,   188,   414,    -1,   136,
     119,   453,   188,   414,    -1,   454,    -1,   453,   108,   119,
     454,    -1,   657,   148,   414,    -1,   657,   553,   148,   414,
      -1,    73,   157,   413,   187,   456,   114,   418,   414,    -1,
     457,    -1,   456,   457,    -1,   458,   418,   414,    -1,   101,
     414,    -1,   458,   101,   414,    -1,    73,   157,   413,   187,
     460,   114,   418,   394,    -1,   461,    -1,   460,   461,    -1,
     458,   418,   394,    -1,    74,   157,   413,   187,   464,   114,
     418,   414,    -1,    74,   157,   413,   187,   464,   114,   119,
     657,   418,   414,    -1,    74,   157,   413,   187,   466,   114,
     418,   394,    -1,    74,   157,   413,   187,   464,   114,   119,
     657,   418,   394,    -1,   465,    -1,   464,   465,    -1,   101,
     468,   418,   414,    -1,   101,   119,   657,    95,   468,   418,
     414,    -1,   467,    -1,   466,   467,    -1,   101,   468,   418,
     394,    -1,   101,   119,   657,    95,   468,   418,   394,    -1,
     554,    -1,   468,   210,   554,    -1,    48,   157,   413,   187,
     198,   414,   127,   414,    -1,   471,    -1,   470,   167,   471,
      -1,   472,    -1,   471,    93,   472,    -1,   474,    -1,   474,
     491,   474,    -1,   474,   492,   474,    -1,   474,   133,   474,
      -1,   474,   163,   474,    -1,    -1,   474,   158,   473,   474,
      -1,   474,   156,   474,    -1,   474,   144,   474,    -1,   474,
     142,   474,    -1,   475,    -1,   475,   249,    71,   592,   476,
      -1,   477,    -1,   477,   100,   475,    -1,    -1,   644,    -1,
     478,    -1,   478,   199,   478,    -1,   479,    -1,   478,   176,
     479,    -1,   478,   159,   479,    -1,   480,    -1,   479,   194,
     480,    -1,   479,   118,   480,    -1,   479,   147,   480,    -1,
     479,   160,   480,    -1,   481,    -1,   480,   201,   481,    -1,
     480,   210,   481,    -1,   482,    -1,   481,   151,   482,    -1,
     481,   137,   482,    -1,   483,    -1,   483,    50,   231,   554,
      -1,   484,    -1,   484,   200,    95,   554,    -1,   485,    -1,
     485,   102,    95,   486,    -1,   487,    -1,   487,   103,    95,
     486,    -1,   559,    -1,   559,   145,    -1,   489,    -1,   488,
     489,    -1,   176,    -1,   159,    -1,   488,   176,    -1,   488,
     159,    -1,   493,    -1,   490,    -1,   494,    -1,   497,    -1,
     490,   193,   497,    -1,   203,    -1,   208,    -1,   207,    -1,
     206,    -1,   205,    -1,   204,    -1,   152,    -1,   179,    -1,
     141,    -1,    76,   154,   392,   184,    -1,    76,   222,   154,
     392,   184,    -1,    76,   221,   154,   392,   184,    -1,    76,
      77,   572,   154,   392,   184,    -1,   495,   154,   391,   184,
      -1,   496,    -1,   495,   496,    -1,   177,   657,    17,    -1,
     177,    18,    -1,   177,    19,    -1,   498,    -1,   498,   499,
      -1,   192,   499,    -1,   499,    -1,   191,    -1,   500,    -1,
     500,   191,   499,    -1,   500,   192,   499,    -1,   501,    -1,
     510,    -1,   502,    -1,   502,   511,    -1,   505,    -1,   505,
     511,    -1,   503,   507,    -1,   504,    -1,   106,   123,    -1,
     115,   123,    -1,    98,   123,    -1,   189,   123,    -1,   116,
     123,    -1,   140,   123,    -1,   139,   123,    -1,   507,    -1,
      99,   507,    -1,   506,   507,    -1,   121,    -1,   172,   123,
      -1,    91,   123,    -1,   181,   123,    -1,   180,   123,    -1,
      92,   123,    -1,   560,    -1,   508,    -1,   657,    -1,   509,
      -1,   194,    -1,    11,    -1,    12,    -1,    20,    -1,   513,
      -1,   510,   511,    -1,   510,   157,   187,    -1,   510,   157,
     522,   187,    -1,   512,    -1,   511,   512,    -1,   155,   413,
     185,    -1,   514,    -1,   516,    -1,   517,    -1,   518,    -1,
     521,    -1,   526,    -1,   519,    -1,   520,    -1,   523,    -1,
     396,    -1,   648,    -1,   645,    -1,   646,    -1,   647,    -1,
     515,    -1,   574,    -1,   111,    -1,   150,    -1,   125,    -1,
     119,   657,    -1,   157,   187,    -1,   157,   413,   187,    -1,
     120,    -1,   169,   154,   413,   184,    -1,   202,   154,   413,
     184,    -1,   658,   157,   187,    -1,   658,   157,   522,   187,
      -1,   145,    -1,   522,   108,   145,    -1,   414,    -1,   522,
     108,   414,    -1,   524,    -1,   525,    -1,   658,   146,   150,
      -1,    47,   380,   397,    -1,   527,    -1,   545,    -1,   528,
      -1,   542,    -1,   543,    -1,   158,   657,   532,   131,    -1,
     158,   657,   532,   197,   195,   657,   532,   197,    -1,   158,
     657,   530,   532,   131,    -1,   158,   657,   530,   532,   197,
     195,   657,   532,   197,    -1,   158,   657,   532,   197,   529,
     195,   657,   532,   197,    -1,   158,   657,   530,   532,   197,
     529,   195,   657,   532,   197,    -1,   540,    -1,   529,   540,
      -1,   531,    -1,   530,   531,    -1,    35,   657,   532,   133,
     532,   533,    -1,    -1,    35,    -1,   183,   534,   183,    -1,
      94,   536,    94,    -1,    -1,   535,    -1,   135,    -1,   538,
      -1,   535,   135,    -1,   535,   538,    -1,    -1,   537,    -1,
     134,    -1,   539,    -1,   537,   134,    -1,   537,   539,    -1,
      29,    -1,   541,    -1,     5,    -1,   541,    -1,   527,    -1,
      10,    -1,   544,    -1,   541,    -1,     9,    -1,   124,    -1,
     126,    -1,   154,   392,   184,    -1,   213,    31,   214,    -1,
     213,   214,    -1,   174,   657,   175,    -1,   174,   657,     8,
      -1,   104,     7,    -1,   546,    -1,   547,    -1,   548,    -1,
     549,    -1,   550,    -1,   551,    -1,   552,    -1,    43,   154,
     392,   184,    -1,    21,   391,   184,    -1,    45,   154,   413,
     184,   154,   391,   184,    -1,    22,   391,   184,    -1,    98,
     154,   413,   184,   154,   391,   184,    -1,    71,   154,   392,
     184,    -1,    39,   154,   392,   184,    -1,    23,   391,   184,
      -1,    60,   154,   413,   184,   154,   391,   184,    -1,    24,
     392,   184,    -1,   161,   154,   413,   184,   154,   392,   184,
      -1,    95,   554,    -1,   556,    -1,   556,   555,    -1,   211,
     157,   187,    -1,   145,    -1,   194,    -1,   176,    -1,   558,
      -1,   560,    -1,   153,   157,   187,    -1,   320,   157,   187,
      -1,   575,    -1,   578,    -1,   655,    -1,   554,    -1,   557,
     108,   554,    -1,   657,    -1,   657,    -1,   563,    -1,   570,
      -1,   568,    -1,   571,    -1,   569,    -1,   567,    -1,   566,
      -1,   565,    -1,   564,    -1,   561,    -1,   562,   157,   187,
      -1,   225,    -1,    44,   157,   187,    -1,    44,   157,   570,
     187,    -1,    44,   157,   571,   187,    -1,    53,   157,   187,
      -1,    71,   157,   187,    -1,    39,   157,   187,    -1,    60,
     157,   187,    -1,    60,   157,   657,   187,    -1,    60,   157,
      30,   187,    -1,    98,   157,   187,    -1,    98,   157,   657,
     187,    -1,    98,   157,   657,   108,   572,   187,    -1,    98,
     157,   194,   187,    -1,    98,   157,   194,   108,   572,   187,
      -1,    62,   157,   657,   187,    -1,    45,   157,   187,    -1,
      45,   157,   657,   187,    -1,    45,   157,   657,   108,   572,
     187,    -1,    45,   157,   657,   108,   573,   187,    -1,    45,
     157,   194,   187,    -1,    45,   157,   194,   108,   572,   187,
      -1,    45,   157,   194,   108,   573,   187,    -1,    63,   157,
     657,   187,    -1,   657,    -1,   657,   145,    -1,    30,    -1,
     576,    -1,   577,    -1,    47,   157,   194,   187,    -1,    47,
     157,   187,    95,   554,    -1,    47,   157,   557,   187,    95,
     554,    -1,   157,   556,   187,    -1,    33,   220,   221,    -1,
      33,   220,   222,    -1,    33,   220,   223,    -1,   226,   225,
     414,   233,   414,    -1,   226,   225,   414,    95,   232,   233,
     414,    -1,   226,   225,   414,    95,   234,   233,   414,    -1,
     226,   225,   414,   218,   414,    -1,   226,   225,   414,   219,
     414,    -1,   226,   227,   414,   233,   414,    -1,   226,   227,
     414,    95,   232,   233,   414,    -1,   226,   227,   414,    95,
     234,   233,   414,    -1,   226,   227,   414,   218,   414,    -1,
     226,   227,   414,   219,   414,    -1,   224,   225,   414,    -1,
     224,   227,   414,    -1,   229,   225,   414,   237,   414,    -1,
     229,   230,   231,   225,   414,   237,   414,    -1,   228,   225,
     414,    95,   414,    -1,   236,   119,   585,   235,   414,   418,
     414,    -1,   586,    -1,   585,   108,   119,   586,    -1,   657,
     143,   414,    -1,   244,   154,   413,   184,   588,    -1,   589,
      -1,   588,   589,    -1,   245,   591,   590,    -1,   154,   413,
     184,    -1,   508,    -1,   591,   210,   508,    -1,   595,   593,
      -1,    -1,   594,    -1,   613,    -1,   594,   613,    -1,   596,
      -1,   595,   262,   596,    -1,   597,    -1,   596,   258,   597,
      -1,   598,    -1,   597,   260,   148,   598,    -1,   599,    -1,
     259,   599,    -1,   603,   600,   601,    -1,    -1,   618,    -1,
      -1,   602,    -1,   282,   154,   413,   184,    -1,   607,   604,
      -1,   157,   592,   187,    -1,   605,    -1,    -1,   640,    -1,
     495,   154,   606,   184,    -1,    -1,   592,    -1,   608,   609,
      -1,   514,    -1,   154,   413,   184,    -1,    -1,   610,    -1,
     248,   611,    -1,   247,   612,    -1,   270,    -1,    -1,    79,
      -1,    -1,   286,    -1,   614,    -1,   615,    -1,   616,    -1,
     642,    -1,   639,    -1,   169,    -1,   284,   478,   617,    -1,
     253,   641,   617,    -1,   286,    -1,   276,    -1,   269,    -1,
     246,   619,    -1,   618,   246,   619,    -1,   620,    -1,   621,
      -1,   622,    -1,   637,    -1,   623,    -1,   631,    -1,   624,
      -1,   638,    -1,   101,   274,    -1,   101,   263,    -1,   266,
      -1,   281,    -1,   251,   274,    -1,   251,   263,    -1,    57,
     657,    30,    -1,   277,    -1,    55,   277,    -1,   279,   625,
      -1,   279,   157,   625,   626,   187,    -1,    55,   279,    -1,
     628,    -1,   114,    -1,    -1,   108,   627,    -1,   628,    -1,
     627,   108,   628,    -1,    97,    30,   629,   630,    -1,    -1,
     271,    30,    -1,    -1,   641,   265,    -1,   278,   286,   632,
     634,    -1,   278,   286,   114,   634,    -1,    55,   278,   286,
      -1,    97,    30,    -1,   157,   633,   187,    -1,    30,    -1,
     633,   108,    30,    -1,    -1,   635,    -1,   636,    -1,   635,
     636,    -1,   201,   632,    -1,   137,   632,    -1,   264,    30,
      -1,   283,    -1,    55,   283,    -1,    97,   217,    -1,    97,
     254,    -1,   255,   250,    -1,   267,   641,   280,    -1,   256,
     478,    -1,    97,   130,   478,    -1,    97,    52,   478,    -1,
     257,   478,   199,   478,    -1,   272,   643,    -1,   252,   643,
      -1,   275,    -1,   268,    -1,   285,   250,   480,    -1,   155,
     185,    -1,   155,   413,   185,    -1,   310,   311,    -1,   310,
     413,   311,    -1,   312,   313,    -1,   312,   413,   313,    -1,
     154,   649,   184,    -1,   414,   122,   414,    -1,   649,   108,
     414,   122,   414,    -1,   226,   314,   414,   233,   414,    -1,
     226,   314,   649,   233,   414,    -1,   226,   314,   414,   233,
     414,    97,   316,   414,    -1,   315,   314,   414,   233,   414,
      -1,   224,   314,   510,    -1,   228,   314,   510,    95,   414,
      -1,   229,   314,   230,   231,   510,   237,   414,    -1,   319,
     157,   187,    -1,   318,   157,   187,    -1,   317,   157,   187,
      -1,    30,    -1,   658,    -1,    16,    -1,    98,    -1,    39,
      -1,    44,    -1,    53,    -1,    45,    -1,   153,    -1,    48,
      -1,   225,    -1,    60,    -1,    62,    -1,    63,    -1,    71,
      -1,    74,    -1,    73,    -1,   211,    -1,   243,    -1,   314,
      -1,   318,    -1,   317,    -1,   319,    -1,   320,    -1,   659,
      -1,    25,    -1,   215,    -1,   128,    -1,    38,    -1,   261,
      -1,    37,    -1,   222,    -1,   221,    -1,   147,    -1,    43,
      -1,   259,    -1,   260,    -1,   274,    -1,   263,    -1,   251,
      -1,   285,    -1,   277,    -1,   279,    -1,   278,    -1,   283,
      -1,   255,    -1,   250,    -1,    79,    -1,   217,    -1,   254,
      -1,    52,    -1,   223,    -1,   236,    -1,   302,    -1,   230,
      -1,   203,    -1,   208,    -1,   207,    -1,   206,    -1,   205,
      -1,   204,    -1,    97,    -1,   112,    -1,   113,    -1,   186,
      -1,    46,    -1,   257,    -1,    36,    -1,    67,    -1,    72,
      -1,    59,    -1,    54,    -1,    56,    -1,    78,    -1,    42,
      -1,   148,    -1,    51,    -1,   212,    -1,   170,    -1,   171,
      -1,   168,    -1,    70,    -1,    96,    -1,   117,    -1,   129,
      -1,   130,    -1,   107,    -1,    68,    -1,   136,    -1,   188,
      -1,   101,    -1,    95,    -1,   198,    -1,   127,    -1,   167,
      -1,    93,    -1,    50,    -1,   231,    -1,   102,    -1,   199,
      -1,   118,    -1,   160,    -1,   201,    -1,   151,    -1,   137,
      -1,    76,    -1,    77,    -1,   103,    -1,   200,    -1,   152,
      -1,   182,    -1,   196,    -1,   161,    -1,   138,    -1,   132,
      -1,   166,    -1,   149,    -1,   165,    -1,    33,    -1,    40,
      -1,    58,    -1,   114,    -1,    41,    -1,    57,    -1,   216,
      -1,    49,    -1,    61,    -1,    34,    -1,    47,    -1,   273,
      -1,   249,    -1,   282,    -1,   284,    -1,   253,    -1,   267,
      -1,   280,    -1,   272,    -1,   252,    -1,   266,    -1,   281,
      -1,   271,    -1,   265,    -1,   264,    -1,   248,    -1,   247,
      -1,   256,    -1,   286,    -1,   276,    -1,   275,    -1,   270,
      -1,   268,    -1,   269,    -1,   235,    -1,   232,    -1,   315,
      -1,   226,    -1,   229,    -1,   228,    -1,   224,    -1,   219,
      -1,   218,    -1,   220,    -1,   237,    -1,   227,    -1,   234,
      -1,   233,    -1,    66,    -1,    64,    -1,    75,    -1,   169,
      -1,   202,    -1,   242,    -1,   240,    -1,   241,    -1,   238,
      -1,   239,    -1,   244,    -1,   245,    -1,   246,    -1,    65,
      -1,   295,    -1,   293,    -1,   294,    -1,   299,    -1,   300,
      -1,   301,    -1,   296,    -1,   297,    -1,   298,    -1,    80,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,
      -1,   287,    -1,   288,    -1,   289,    -1,   290,    -1,   291,
      -1,   292,    -1,   303,    -1,   304,    -1,   305,    -1,   306,
      -1,   307,    -1,   308,    -1,   309,    -1,    91,    -1,   106,
      -1,   115,    -1,   172,    -1,   180,    -1,   189,    -1,   139,
      -1,    92,    -1,   116,    -1,   140,    -1,   181,    -1,   316,
      -1,    26,    -1
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
     845,   847,   849,   851,   853,   856,   859,   861,   864,   867,
     869,   871,   874,   879,   883,   889,   894,   898,   900,   902,
     904,   906,   908,   910,   912,   914,   916,   919,   923,   927,
     930,   932,   934,   939,   943,   947,   953,   958,   965,   970,
     977,   983,   991,   996,  1002,  1008,  1015,  1019,  1023,  1026,
    1028,  1032,  1037,  1043,  1047,  1054,  1059,  1065,  1067,  1070,
    1074,  1076,  1079,  1081,  1088,  1092,  1096,  1099,  1103,  1105,
    1109,  1114,  1120,  1127,  1133,  1135,  1138,  1141,  1145,  1150,
    1152,  1156,  1158,  1161,  1163,  1165,  1167,  1170,  1173,  1176,
    1180,  1182,  1184,  1187,  1190,  1193,  1199,  1205,  1207,  1212,
    1216,  1221,  1230,  1232,  1235,  1239,  1242,  1246,  1255,  1257,
    1260,  1264,  1273,  1284,  1293,  1304,  1306,  1309,  1314,  1322,
    1324,  1327,  1332,  1340,  1342,  1346,  1355,  1357,  1361,  1363,
    1367,  1369,  1373,  1377,  1381,  1385,  1386,  1391,  1395,  1399,
    1403,  1405,  1411,  1413,  1417,  1418,  1420,  1422,  1426,  1428,
    1432,  1436,  1438,  1442,  1446,  1450,  1454,  1456,  1460,  1464,
    1466,  1470,  1474,  1476,  1481,  1483,  1488,  1490,  1495,  1497,
    1502,  1504,  1507,  1509,  1512,  1514,  1516,  1519,  1522,  1524,
    1526,  1528,  1530,  1534,  1536,  1538,  1540,  1542,  1544,  1546,
    1548,  1550,  1552,  1557,  1563,  1569,  1576,  1581,  1583,  1586,
    1590,  1593,  1596,  1598,  1601,  1604,  1606,  1608,  1610,  1614,
    1618,  1620,  1622,  1624,  1627,  1629,  1632,  1635,  1637,  1640,
    1643,  1646,  1649,  1652,  1655,  1658,  1660,  1663,  1666,  1668,
    1671,  1674,  1677,  1680,  1683,  1685,  1687,  1689,  1691,  1693,
    1695,  1697,  1699,  1701,  1704,  1708,  1713,  1715,  1718,  1722,
    1724,  1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,
    1744,  1746,  1748,  1750,  1752,  1754,  1756,  1758,  1760,  1763,
    1766,  1770,  1772,  1777,  1782,  1786,  1791,  1793,  1797,  1799,
    1803,  1805,  1807,  1811,  1815,  1817,  1819,  1821,  1823,  1825,
    1830,  1839,  1845,  1855,  1865,  1876,  1878,  1881,  1883,  1886,
    1893,  1894,  1896,  1900,  1904,  1905,  1907,  1909,  1911,  1914,
    1917,  1918,  1920,  1922,  1924,  1927,  1930,  1932,  1934,  1936,
    1938,  1940,  1942,  1944,  1946,  1948,  1950,  1952,  1956,  1960,
    1963,  1967,  1971,  1974,  1976,  1978,  1980,  1982,  1984,  1986,
    1988,  1993,  1997,  2005,  2009,  2017,  2022,  2027,  2031,  2039,
    2043,  2051,  2054,  2056,  2059,  2063,  2065,  2067,  2069,  2071,
    2073,  2077,  2081,  2083,  2085,  2087,  2089,  2093,  2095,  2097,
    2099,  2101,  2103,  2105,  2107,  2109,  2111,  2113,  2115,  2117,
    2121,  2123,  2127,  2132,  2137,  2141,  2145,  2149,  2153,  2158,
    2163,  2167,  2172,  2179,  2184,  2191,  2196,  2200,  2205,  2212,
    2219,  2224,  2231,  2238,  2243,  2245,  2248,  2250,  2252,  2254,
    2259,  2265,  2272,  2276,  2280,  2284,  2288,  2294,  2302,  2310,
    2316,  2322,  2328,  2336,  2344,  2350,  2356,  2360,  2364,  2370,
    2378,  2384,  2392,  2394,  2399,  2403,  2409,  2411,  2414,  2418,
    2422,  2424,  2428,  2431,  2432,  2434,  2436,  2439,  2441,  2445,
    2447,  2451,  2453,  2458,  2460,  2463,  2467,  2468,  2470,  2471,
    2473,  2478,  2481,  2485,  2487,  2488,  2490,  2495,  2496,  2498,
    2501,  2503,  2507,  2508,  2510,  2513,  2516,  2518,  2519,  2521,
    2522,  2524,  2526,  2528,  2530,  2532,  2534,  2536,  2540,  2544,
    2546,  2548,  2550,  2553,  2557,  2559,  2561,  2563,  2565,  2567,
    2569,  2571,  2573,  2576,  2579,  2581,  2583,  2586,  2589,  2593,
    2595,  2598,  2601,  2607,  2610,  2612,  2614,  2615,  2618,  2620,
    2624,  2629,  2630,  2633,  2634,  2637,  2642,  2647,  2651,  2654,
    2658,  2660,  2664,  2665,  2667,  2669,  2672,  2675,  2678,  2681,
    2683,  2686,  2689,  2692,  2695,  2699,  2702,  2706,  2710,  2715,
    2718,  2721,  2723,  2725,  2729,  2732,  2736,  2739,  2743,  2746,
    2750,  2754,  2758,  2764,  2770,  2776,  2785,  2791,  2795,  2801,
    2809,  2813,  2817,  2821,  2823,  2825,  2827,  2829,  2831,  2833,
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
    3255,  3257,  3259,  3261,  3263,  3265,  3267,  3269,  3271
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
    2150,  2151,  2152,  2153,  2156,  2168,  2174,  2179,  2184,  2190,
    2195,  2200,  2206,  2215,  2225,  2235,  2246,  2252,  2253,  2254,
    2257,  2258,  2259,  2260,  2261,  2264,  2271,  2279,  2283,  2291,
    2299,  2304,  2311,  2318,  2328,  2338,  2348,  2358,  2368,  2378,
    2388,  2398,  2408,  2417,  2427,  2437,  2449,  2455,  2461,  2467,
    2473,  2481,  2489,  2497,  2505,  2515,  2521,  2530,  2531,  2535,
    2542,  2546,  2551,  2554,  2558,  2562,  2568,  2574,  2580,  2586,
    2594,  2598,  2606,  2614,  2622,  2630,  2640,  2646,  2652,  2660,
    2666,  2674,  2678,  2686,  2692,  2698,  2704,  2713,  2722,  2731,
    2742,  2746,  2752,  2758,  2766,  2772,  2781,  2792,  2798,  2806,
    2810,  2819,  2825,  2831,  2839,  2845,  2851,  2859,  2865,  2871,
    2879,  2885,  2892,  2902,  2909,  2919,  2925,  2933,  2939,  2948,
    2954,  2962,  2968,  2977,  2983,  2991,  2997,  3001,  3007,  3012,
    3018,  3022,  3031,  3037,  3046,  3056,  3055,  3068,  3077,  3086,
    3097,  3101,  3112,  3116,  3122,  3125,  3131,  3135,  3141,  3145,
    3149,  3155,  3159,  3165,  3171,  3177,  3185,  3189,  3193,  3199,
    3203,  3209,  3217,  3221,  3229,  3233,  3241,  3245,  3253,  3257,
    3265,  3269,  3275,  3279,  3285,  3289,  3293,  3297,  3305,  3306,
    3307,  3310,  3315,  3321,  3325,  3329,  3333,  3337,  3341,  3347,
    3351,  3355,  3361,  3365,  3369,  3373,  3382,  3390,  3396,  3404,
    3408,  3412,  3418,  3422,  3430,  3438,  3458,  3464,  3474,  3478,
    3484,  3485,  3488,  3494,  3502,  3508,  3518,  3524,  3532,  3536,
    3540,  3544,  3548,  3554,  3560,  3566,  3570,  3576,  3580,  3589,
    3593,  3597,  3603,  3607,  3615,  3616,  3619,  3623,  3629,  3633,
    3637,  3641,  3647,  3651,  3655,  3659,  3665,  3671,  3679,  3685,
    3686,  3687,  3688,  3689,  3690,  3691,  3692,  3693,  3694,  3695,
    3696,  3697,  3698,  3701,  3705,  3711,  3718,  3725,  3734,  3740,
    3744,  3750,  3757,  3763,  3769,  3773,  3791,  3797,  3803,  3809,
    3817,  3821,  3827,  3833,  3843,  3844,  3847,  3848,  3849,  3852,
    3860,  3876,  3884,  3900,  3918,  3938,  3944,  3953,  3959,  3968,
    3975,  3976,  3978,  3983,  3990,  3993,  3999,  4005,  4011,  4018,
    4027,  4030,  4036,  4042,  4048,  4055,  4064,  4068,  4074,  4078,
    4084,  4088,  4092,  4097,  4104,  4108,  4112,  4116,  4122,  4127,
    4133,  4139,  4146,  4152,  4157,  4162,  4167,  4172,  4177,  4182,
    4185,  4191,  4195,  4201,  4205,  4211,  4217,  4223,  4227,  4233,
    4237,  4243,  4249,  4253,  4257,  4263,  4269,  4275,  4283,  4297,
    4301,  4305,  4309,  4313,  4317,  4323,  4329,  4337,  4343,  4349,
    4353,  4357,  4361,  4365,  4369,  4373,  4377,  4381,  4385,  4391,
    4397,  4403,  4407,  4411,  4417,  4422,  4428,  4434,  4438,  4443,
    4449,  4453,  4459,  4465,  4469,  4477,  4483,  4487,  4493,  4502,
    4511,  4517,  4523,  4531,  4537,  4543,  4549,  4555,  4559,  4565,
    4571,  4575,  4583,  4589,  4595,  4601,  4609,  4613,  4619,  4625,
    4629,  4635,  4639,  4645,  4651,  4658,  4666,  4671,  4677,  4683,
    4691,  4697,  4704,  4710,  4719,  4725,  4731,  4737,  4746,  4753,
    4759,  4765,  4774,  4781,  4785,  4791,  4796,  4803,  4807,  4813,
    4817,  4823,  4827,  4833,  4837,  4845,  4856,  4859,  4865,  4868,
    4874,  4880,  4888,  4892,  4898,  4901,  4907,  4917,  4920,  4926,
    4936,  4942,  4950,  4953,  4959,  4963,  4967,  4973,  4976,  4982,
    4985,  4991,  4995,  4999,  5003,  5007,  5013,  5019,  5029,  5039,
    5043,  5047,  5053,  5059,  5067,  5071,  5075,  5079,  5083,  5087,
    5091,  5095,  5101,  5105,  5109,  5113,  5119,  5125,  5133,  5141,
    5145,  5151,  5161,  5172,  5178,  5182,  5188,  5191,  5197,  5202,
    5209,  5217,  5220,  5226,  5230,  5236,  5245,  5252,  5260,  5264,
    5270,  5276,  5284,  5287,  5293,  5298,  5308,  5316,  5326,  5332,
    5336,  5342,  5346,  5350,  5356,  5362,  5366,  5370,  5374,  5380,
    5388,  5398,  5402,  5408,  5414,  5418,  5424,  5428,  5434,  5438,
    5444,  5451,  5457,  5466,  5472,  5482,  5488,  5494,  5515,  5539,
    5563,  5567,  5571,  5577,  5580,  5581,  5582,  5583,  5584,  5585,
    5586,  5587,  5588,  5589,  5590,  5591,  5592,  5593,  5594,  5595,
    5596,  5597,  5598,  5599,  5600,  5601,  5602,  5605,  5606,  5607,
    5608,  5609,  5610,  5611,  5612,  5613,  5614,  5615,  5616,  5617,
    5618,  5619,  5620,  5621,  5622,  5623,  5624,  5625,  5626,  5627,
    5628,  5629,  5630,  5631,  5632,  5633,  5634,  5635,  5636,  5637,
    5638,  5639,  5640,  5641,  5642,  5643,  5644,  5645,  5646,  5647,
    5648,  5649,  5650,  5651,  5652,  5653,  5654,  5655,  5656,  5657,
    5658,  5659,  5660,  5661,  5662,  5663,  5664,  5665,  5666,  5667,
    5668,  5669,  5670,  5671,  5672,  5673,  5674,  5675,  5676,  5677,
    5678,  5679,  5680,  5681,  5682,  5683,  5684,  5685,  5686,  5687,
    5688,  5689,  5690,  5691,  5692,  5693,  5694,  5695,  5696,  5697,
    5698,  5699,  5700,  5701,  5702,  5703,  5704,  5705,  5706,  5707,
    5708,  5709,  5710,  5711,  5712,  5713,  5714,  5715,  5716,  5717,
    5718,  5719,  5720,  5721,  5722,  5723,  5724,  5725,  5726,  5727,
    5728,  5729,  5730,  5731,  5732,  5733,  5734,  5735,  5736,  5737,
    5738,  5739,  5740,  5741,  5742,  5743,  5744,  5745,  5746,  5747,
    5748,  5749,  5750,  5751,  5752,  5753,  5754,  5755,  5756,  5757,
    5758,  5759,  5760,  5761,  5762,  5763,  5764,  5765,  5766,  5767,
    5768,  5769,  5770,  5771,  5772,  5773,  5774,  5775,  5776,  5777,
    5778,  5779,  5780,  5781,  5782,  5783,  5784,  5785,  5786,  5787,
    5788,  5789,  5790,  5791,  5792,  5793,  5794,  5795,  5796,  5797,
    5798,  5799,  5800,  5801,  5802,  5803,  5804,  5805,  5808
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
  const int xquery_parser::yylast_ = 16880;
  const int xquery_parser::yynnts_ = 326;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 614;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 334;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 588;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17534 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 5810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"

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

