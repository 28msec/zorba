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
#line 1531 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1544 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1556 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1569 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1574 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1579 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1584 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1597 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1605 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1610 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1618 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1626 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1634 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1642 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1652 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1656 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1662 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1666 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1673 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1682 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1693 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1699 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1706 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1711 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1718 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1725 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1735 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1745 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1755 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1766 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1779 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1799 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1809 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1813 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1823 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1828 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1836 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1843 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1850 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1878 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1883 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      driver.addCommonLanguageWarning((yylocation_stack_[(2) - (1)]), ZED(ZWST0009_EMPTY_BLOCK));
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 1890 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 190:

/* Line 690 of lalr1.cc  */
#line 1906 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1912 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1918 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1925 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1932 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 1941 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1950 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1959 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1968 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1979 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1985 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1991 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 1997 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2009 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2014 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2020 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2032 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2045 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2065 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2071 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2078 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2087 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2094 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2100 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2105 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2117 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2151 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2163 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2169 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2174 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2180 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2185 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2190 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2196 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2205 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2216 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2228 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2239 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2257 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2264 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2273 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2277 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2287 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2295 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2302 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2309 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2319 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2329 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2339 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2349 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2359 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2369 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2379 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2389 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2399 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2408 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2418 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2428 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2440 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2446 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2452 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2458 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2464 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2472 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2480 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2488 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2496 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2506 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2512 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2522 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2526 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2533 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2537 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2545 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2549 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2553 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2559 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2565 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2571 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2577 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2585 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 2589 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2597 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2605 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2613 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2621 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2631 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2637 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2643 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2651 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2657 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2665 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2669 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2677 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2683 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 2689 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 2695 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2704 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2713 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2722 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2733 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2737 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2743 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2749 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 2757 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 2763 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2772 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2783 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2789 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2822 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2830 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2836 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2842 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2850 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2856 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2862 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2870 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 2876 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2883 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2893 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2900 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2910 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2916 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2924 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2930 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 2939 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2945 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2953 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 2959 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2968 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2974 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2982 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 2988 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 2992 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
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
#line 3003 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3009 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3013 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3022 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3028 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3037 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3046 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            driver.getXqueryLexer()->interpretAsLessThan();
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3050 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3059 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3068 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3077 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3088 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3092 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3103 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3107 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3112 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3116 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3122 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3126 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
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
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3140 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3146 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3150 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3156 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3162 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3168 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3176 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3180 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3184 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3190 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3194 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3200 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3208 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3212 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3220 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3224 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3232 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3236 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3244 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3248 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3256 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3260 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3266 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3270 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3276 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3280 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3284 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3288 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3301 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3306 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3312 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3316 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3320 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3324 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3328 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3332 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3338 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3342 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3346 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3352 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3356 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3360 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3364 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3373 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr)
            );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3381 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3387 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3395 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 3399 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 3403 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 3409 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 3413 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3421 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3429 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3447 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 3453 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3463 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 3467 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 3477 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 3483 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3491 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 3497 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3507 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 3513 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 3521 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 3525 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 3529 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 3533 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 3537 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 3543 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 3549 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 3555 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 3559 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 3565 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 3569 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 3578 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 3582 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 3586 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 3592 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 3596 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 3608 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 3612 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 3618 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 3622 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 3626 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 3630 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 3636 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 3640 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 3644 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 3648 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 3654 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      PredicateList* pl = new PredicateList( LOC((yyloc)) );
      pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.node) = pl;
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 3660 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if (PredicateList* pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)))
        pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 3668 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 3690 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 3694 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 3700 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 3707 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 3714 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 3723 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 3729 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 3733 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 3739 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 3746 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 3752 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 3758 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FunctionCall(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL);
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 3762 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3780 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList* al = new ArgList(LOC((yyloc)));
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 3786 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if (ArgList* al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)))
        al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 3792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 3798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 3806 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 3810 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 3816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 3822 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3841 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3849 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3865 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3873 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3891 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3909 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3927 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 3933 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 3942 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 3948 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 3957 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 3967 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 3972 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 3978 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 3982 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 3988 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 3994 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4000 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4007 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4015 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4019 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4025 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4031 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4037 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4044 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4053 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4057 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4063 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4067 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4073 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4077 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4081 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4086 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4093 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4097 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4101 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4105 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4111 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4116 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4122 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4128 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4135 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4141 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4146 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4151 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 4156 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 4161 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 4166 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 4174 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 4180 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 4184 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 4190 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 4194 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 4200 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 4206 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 4212 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 4216 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 4222 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 4226 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 4232 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 4238 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 4242 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 4246 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 4252 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 4258 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 4264 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 4272 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            GeneralizedAtomicType* gat = static_cast<GeneralizedAtomicType*>((yysemantic_stack_[(1) - (1)].node));
            if (gat->get_qname()->get_localname() == "item")
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
#line 4285 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 4289 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 4293 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 4297 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 4301 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 4305 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 4311 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 4317 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 4325 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 4331 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 4337 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 4341 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 4345 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 4349 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 4353 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 4357 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 4361 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 4365 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 4369 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 4373 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 4379 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 4385 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 4391 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 4395 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 4399 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 4405 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 4410 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 4416 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 4422 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 4426 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(4) - (3)].expr), (yylocation_stack_[(4) - (3)]));
            (yyval.node) = new PITest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 4431 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 4437 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 4441 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 4447 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 4453 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 4457 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 4465 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 4471 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 4475 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 4481 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 4490 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 4499 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 4505 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 4511 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 4519 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 4525 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 4531 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 4537 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 4543 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 4547 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 4553 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 4559 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 4563 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 4571 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 4577 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 4583 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 4589 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 4597 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 4601 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 4607 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 4613 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 4617 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 4623 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 4627 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 4633 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 4639 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 4646 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 4654 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 4659 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 4665 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 4671 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 4679 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 4685 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 4692 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 4698 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 4707 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 4713 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 4719 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 4725 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 4734 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 4741 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 4747 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 4753 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 4762 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 4769 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 4773 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 4779 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 4784 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 4791 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 4795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 4801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 4805 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 4811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 4815 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 4821 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 4825 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 4833 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 4843 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 4847 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 4852 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 4856 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 4862 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 4868 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 4876 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 4880 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 4885 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 4889 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 4895 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 4904 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 4908 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 4914 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 4924 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 4930 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 4937 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 4941 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 4947 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 4951 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 4955 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 4960 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 4964 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 4969 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 4973 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 4979 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 4983 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 4987 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 4991 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 4995 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 5001 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 5007 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5017 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5027 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 5031 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 5035 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 5041 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 5047 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 5055 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 5059 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 5063 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 5067 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 5071 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 5075 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 5079 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 5083 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 5089 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 5093 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 5097 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 5101 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 5107 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 5113 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 5121 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 5129 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 5133 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 5139 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5149 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5160 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 5166 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 5170 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 5175 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 5179 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 5185 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 5190 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 5197 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 5204 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 5208 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 5214 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 5218 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 5224 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5233 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 5240 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 5248 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 5252 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 5258 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 5264 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 5271 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 5275 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 5281 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 5286 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5296 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5304 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5314 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 5320 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 5324 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 5330 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 5334 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 5338 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 5344 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 5350 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 5354 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 5358 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 5362 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 5368 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5376 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5386 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 5390 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 5396 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 5402 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 5406 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 5412 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 5416 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 5422 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 5426 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 5432 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 5439 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 5445 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 5454 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 5460 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5470 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 5476 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 5482 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5503 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5527 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 5551 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 5555 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 5559 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 5568 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 5569 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 5570 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 5571 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 5572 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 5573 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 5574 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 5575 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 5576 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 5577 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 5578 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 5579 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 5580 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 5581 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 5582 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 5583 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 5584 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 5585 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 5586 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 5587 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 5588 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 5589 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 5593 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 5594 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 5595 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 5596 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 5597 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 5598 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 5599 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 5600 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 5601 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 5602 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 5603 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 5604 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 5605 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 5606 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 5607 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 5608 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 5609 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 5610 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 5611 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 5612 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 5613 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 5614 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 5615 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 5616 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 5617 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 5618 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 5619 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 5620 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 5621 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 5622 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 5623 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 5624 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 5625 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 5626 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 5627 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 5628 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 5629 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 5630 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 5631 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 5632 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 5633 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 5634 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 5635 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 5636 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 5637 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 5638 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 5639 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 5640 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 5641 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 5643 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 5644 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 5645 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 5646 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 5647 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 5648 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 5649 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 5650 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 5651 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 5652 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 5653 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 5654 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 5655 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 5656 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 5657 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 5658 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 5659 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 5660 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 5661 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 5662 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 5663 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 5664 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 5665 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 5666 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 5667 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 5668 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 5669 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 5670 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 5671 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 5672 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 5673 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 5674 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 5675 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 5676 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 5677 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 5678 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 5679 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 5680 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 5681 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 5682 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 5683 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 5684 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 5685 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 5686 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 5687 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 5688 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 5689 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 5690 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 5691 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 5692 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 5693 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 5694 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 5695 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 5696 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 5697 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 5698 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 5699 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 5700 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 5701 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 5702 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 5703 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 5704 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 5705 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 5706 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 5707 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 5708 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 5709 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 5710 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 5711 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 5712 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 5713 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 5714 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 5715 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 5716 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 5717 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 5718 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 5719 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 5720 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 5721 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 5722 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 5723 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 5724 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 5725 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 5726 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 5727 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 5728 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 5729 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 5730 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 5731 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 5732 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 5733 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 5734 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 5735 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 5736 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 5737 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 5738 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 5739 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 5740 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 5741 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 5742 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 5743 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 5744 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 5745 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 5746 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 5747 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 5748 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 5749 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 5750 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 5751 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 5752 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 5753 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 5754 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 5755 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 5756 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 5757 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 5758 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 5759 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 5760 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 5761 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 5762 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 5763 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 5764 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 5765 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 5766 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 5767 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 5768 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 5769 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 5770 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 5771 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 5772 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 5773 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 5774 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 5775 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 5776 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 5777 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 5778 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 5779 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 5780 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 5781 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 5782 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 5783 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 5784 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 5785 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 5786 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 5787 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1021:

/* Line 690 of lalr1.cc  */
#line 5788 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1022:

/* Line 690 of lalr1.cc  */
#line 5789 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1023:

/* Line 690 of lalr1.cc  */
#line 5790 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1024:

/* Line 690 of lalr1.cc  */
#line 5791 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1025:

/* Line 690 of lalr1.cc  */
#line 5792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1026:

/* Line 690 of lalr1.cc  */
#line 5795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12073 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1487;
  const short int
  xquery_parser::yypact_[] =
  {
      4927, -1487, -1487, -1487, -1487,  6481,  6481,  6481,  6481, -1487,
   -1487,   285,   490, -1487,   652,    31, -1487, -1487, -1487,   820,
   -1487, -1487, -1487,   403,   604,   829,  4645,   666,   705,   857,
   -1487,    28, -1487,   709, -1487, -1487, -1487, -1487, -1487,   837,
   -1487,   733,   757, -1487, -1487, -1487, -1487,   451, -1487,   839,
   -1487,   767,   781, -1487,   329, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,   479,
     591, -1487, -1487, -1487, -1487,    61, 12681, -1487, -1487, -1487,
     826, -1487, -1487, -1487,   838, -1487,   847,   853, -1487, -1487,
   16552, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,   842,
   -1487, -1487,   859,   874, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487,  5551,  8961,  9271, 16552, -1487, -1487,   854, -1487, -1487,
   -1487, -1487,   858, -1487, -1487,   878, 16552, -1487, 13592,   894,
     898, -1487, -1487, -1487,   905, -1487, -1487, 12061, -1487, -1487,
   -1487, -1487, -1487, -1487,   880, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487,   141,   827, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487,   202,   879,   241, -1487,  -106,   167, -1487,
   -1487, -1487, -1487, -1487, -1487,   923, -1487,   806,   808,   804,
   -1487, -1487,   893,   899, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487,  9581,  9891, -1487,
     740, -1487, -1487, -1487, -1487, -1487,  5239,  6791,  1055, -1487,
    7101, -1487, -1487,   165,    98, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,    99,
   -1487, -1487, -1487, -1487, -1487, -1487,   383, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487,  6481, -1487, -1487, -1487, -1487,
      21, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
     209, -1487,   866, -1487, -1487, -1487,   421, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487,   891,   967, -1487,   962,   812,
     965,   649,   459,   742,   248, -1487,  1017,   868,   968,   966,
   10511, -1487,   885, -1487, -1487,   698, -1487, -1487, 12371, -1487,
     814, -1487,   916, 12681, -1487,   916, 12681, -1487, -1487, -1487,
     527, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,   915, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487,    55, -1487, -1487, -1487,
   -1487, -1487,   889, -1487,  6481,   896,   900,   901,  6481,   628,
     628,  1044,   622,   655,   519, 17140, 16552,    27,  1032, 16552,
     929,   964,   631, 16552,   777,   840, 16552, 16552,   785,   813,
      69, -1487, -1487, -1487, 16552,  6481,   903,  6481,   160, 10821,
   13888, 16552, -1487,   807,   809, 16552,   973,   480,   942, 10821,
    1096,   187,   112, 16552,   979,   957,   993, -1487,   918, 10821,
   14184, 16552, 16552, 16552,  6481,   921, 10821, 10821, 16552,  6481,
     948,   955, -1487, -1487, -1487, 10821, 14480,   953, -1487,   956,
   -1487, -1487, -1487, -1487,   959, -1487,   960, -1487, -1487, -1487,
   -1487, -1487,   969, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, 16552, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487,   976, 16552, -1487, -1487, -1487,
     928,  5861,  1002,   396,   970,   971,   972, 16552,  6481, -1487,
     977,   151, -1487,   682, -1487,   105,  1095, 10821, 10821, -1487,
     182, -1487, -1487,  1115, -1487, -1487, -1487, -1487, 10821,   922,
   -1487,  1105, 10821, 10821, 16852, 10821, 10821, 10821, 10821, 16852,
   10821,   906,   908, 16552,   949,   952, 10821, 10821,  5551,   902,
   -1487,    59, -1487,    58, 10821,  6791, -1487, -1487, -1487, -1487,
   -1487,   652,   857,   100,   122,  1140,  7411,  3383,  7721,  3704,
     838, -1487, -1487,   233,   838, -1487, 10821,  4324, -1487,  1030,
     553,    28,   983,   982,   984,  6481, 10821, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, 11131, 11131, 11131, -1487, 11131,
   11131, -1487, 11131, -1487, 11131, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, 11131, 11131,  1082, 11131, 11131, 11131, 11131, 11131,
   11131, 11131, 11131, 11131, 11131, 11131, 11131,   924,  1061,  1063,
    1064, -1487, -1487, -1487, 11751,  6481, -1487, -1487, -1487, 12061,
   12061, 10821,   916, -1487, -1487,   916, -1487,  8341,   916,   974,
    1013,  8651, -1487, -1487, -1487, -1487,    52, -1487,    68, -1487,
   -1487, -1487, -1487, -1487, -1487,  1056,  1065,   666,  1141, -1487,
   -1487, 17140,  1097,   641, 16552,  1011,  1015,  1097,  1044,  1046,
    1057, -1487, -1487, -1487,   175,   943,  1093,   892, 16552,  1053,
   10821,  1078, 16552, 16552, -1487,  1066,  1014, -1487,  1016,   956,
     757, -1487,  1018,  1019,   158, -1487,   324,   327,  1094, -1487,
      33, -1487, -1487,  1094, 16552,    24, 16552,  1108,   362, -1487,
    6481, -1487,   137, -1487, 16552,  1107,  1162, 16552,  1044,  1111,
     457, 16552, 10821,    28, -1487,   236,  1022, -1487,  1023,  1024,
    1025,    65, -1487,   463,  1033, -1487,   138,   139,  1060, -1487,
    1034,  6481,  6481,   250, -1487,   385,   410,   592, 10821,   245,
   -1487, -1487, 10821, 10821, -1487, 10821, 10821, 10821, -1487, 10821,
   -1487, 10821, -1487, 16552,  1095, -1487,   274,   253,   264, -1487,
   -1487, -1487,   276, -1487,   458, -1487, -1487,  1062,  1067,  1068,
    1069,  1070,   527,    55,   255,   284,     5,    67,  1124,   288,
     988,   995,   996,    37, -1487,  1083, -1487, -1487,  1038,   140,
    5861,   293, 12991,   902, -1487, -1487, -1487,   998, -1487,   165,
     761,  1196,   540, -1487, -1487,   124, -1487, -1487, -1487,   131,
   -1487,    51, -1487, -1487, -1487, -1487, -1487,  4014, -1487, -1487,
   -1487, 16552,  1071, 10821, 11441, -1487, -1487, -1487,   967, -1487,
   -1487, -1487, -1487, -1487, 11131, -1487, -1487, -1487,    45, -1487,
     459,   459,   400,   742,   742,   742,   742,   248,   248, -1487,
   -1487, 15664, 15664, 16552, 16552, -1487, -1487, -1487,   188, -1487,
   -1487, -1487, -1487,   418, -1487, -1487, -1487,   426,   628, -1487,
   -1487,   621,   675,   727, -1487,   666, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487,  1097, -1487,  1100, 15960,
    1091, 10821, -1487, -1487, -1487,  1142,  1044,  1044,  1097, -1487,
     881,  1044,   702, 16552,   401,   658,  1205, -1487, -1487,   954,
     526, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487,   175,    50,  1012,   646, 10821, -1487, 16552,  1143,
     944,  1044, -1487, -1487, -1487, -1487,  1088, 16552, -1487, 16552,
   -1487, 16256,  1117, 15664,  1127, 10821,   214,  1099,    40,   575,
     994, -1487, -1487,   723,    24,  1142, 15664,  1130,  1155,  1072,
    1054,  1118,  1044,  1092,  1121,  1158,  1044, 10821,   -29, -1487,
   -1487, -1487,  1103, -1487, -1487, -1487, -1487,  1139, 10821, 10821,
    1112, -1487,  1160,  1161,  6481, -1487,  1079,  1080,  1113, 16552,
   -1487, 16552, -1487, 10821,  1122,  1084, 10821, -1487,  1146,   142,
     173,   176,  1235, -1487,   433, -1487,   703,  1119, -1487, -1487,
    1245, -1487,   716, 10821, 10821, 10821,   770, 10821, 10821, 10821,
   10821, 10821, 10821, 10821, 10821, 10821, 16852,  1157, 10821, 10821,
   -1487,  8031,   134,  1036, -1487,   359, -1487, 10821,   132,   113,
      51,  7721,  3704,  7721,  1197, -1487, -1487, 10821,   805,  1177,
   -1487, 16552,  1179,  1180, -1487, -1487, 10821,    45,   606,   738,
   -1487,  1004,   326,  1029,  1031, -1487, -1487,   840, -1487,  1026,
     574,  1133,  1135, 15960,  1137,  1144,  1147,  1148,  1150, -1487,
     512, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487,  1151, -1487, -1487, -1487, 10201, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487,   772, -1487,  1269,   821, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,  1027, -1487,
   -1487,  1270, -1487, -1487, -1487, -1487, -1487,   572,  1273, -1487,
      89, -1487, -1487, -1487,   953,   604,   709,   959,   733,   960,
     969, -1487,  1144,  1147,  1148, -1487,   512,   512, 11751,  1021,
    1005, -1487,  1142,    50,  1089,  1120,  6481,  1128,  1132,  1169,
    1134,  1136, 16552, -1487,   557, -1487, 16552, -1487, 10821,  1172,
   10821,  1189, 10821,   228,  1176, 10821,  1178, -1487,  1208,  1209,
   10821, 16552,   913,  1253, -1487, -1487, -1487, -1487, -1487, -1487,
   15664, -1487,  6481,  1044,  1225, -1487, -1487, -1487,  1044,  1225,
   -1487, 10821,  1191,  6481, 16552, -1487, -1487, 10821, 10821,    93,
   -1487,    54,   308, -1487, 14776,   580, -1487,   795, -1487,  1152,
   -1487, -1487,  6481,  1153,  1154, -1487, 10821, -1487, -1487, 10821,
    1145,  1160,  1234, -1487,  1206, -1487,   745, -1487, -1487,  1331,
   -1487, -1487,  6481, 16552, -1487,   849, -1487, -1487, -1487,  6481,
    1156,  1109,  1114, -1487, -1487, -1487,  1116,  1123, -1487, -1487,
   -1487,  1247, -1487, -1487, -1487, -1487,  1125,   307, 16552,  1164,
   -1487,  1194,  1198,  1201,  1199, -1487,   866,   895, 12991,  1036,
   -1487,  6171, 12991, -1487, -1487,  1196,   548, -1487, -1487, -1487,
    1177, -1487,  1044, -1487,   890, -1487,    78,  1241, -1487, 10821,
     645,  1044, -1487, 11441,   322,  1167, -1487,    45,  1110, -1487,
   -1487,   -34, -1487,   660,   146,  1126,    45,   660, 11131, -1487,
     166, -1487, -1487, -1487, -1487, -1487, -1487,    45,  1215,  1086,
     943,   146, -1487, -1487,  1085,  1286, -1487, -1487, -1487, 13287,
    1182,  1183,  1185,  1186,  1187,  1188,  1190, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
    1336,   411,  1349,   411,  1129,  1272, -1487, -1487,  1211, 16552,
    1131, -1487, -1487, 11751, -1487,  1202, -1487, -1487, -1487, -1487,
   -1487, -1487, 10821,  1237, -1487, -1487, 10821, -1487,   577, -1487,
   10821,  1239, 10821, -1487, 10821, 16552, 16552, -1487,   736, -1487,
   10821, -1487,  1255,  1256,  1292,  1044,  1225, -1487, 10821,  1207,
   -1487, -1487, -1487,  1204, -1487,   290, 10821,  6481,  1213,   311,
   -1487, 16552,   565, -1487, 15072,    38, -1487, 15368,  1216, -1487,
   -1487,  1210, -1487, -1487, -1487, -1487, 10821,   828,  1235, 16552,
     864, -1487,  1217,  1235, 16552, -1487,  1219, -1487, 10821, 10821,
   10821, 10821,  1077, 10821, 10821, -1487, 10821, 10821, 10821, 10821,
    8031,   467, -1487, -1487, -1487, -1487, -1487,  1241, -1487, -1487,
   -1487, 10821,  1254, -1487, -1487, -1487, -1487, -1487,  1220, 11131,
   -1487, -1487, -1487, -1487, -1487,   413, 11131, 11131,   609, -1487,
    1029, -1487,   239, -1487,  1031,    45,  1257, -1487, -1487,  1138,
   -1487, -1487, -1487, -1487,  1313,  1223, -1487,   445, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487,    64,    64, -1487,   411,
   -1487, -1487,   454, -1487,  1382,   146,  1316,  1228, 11751,     3,
    1149,  1246, -1487, -1487, 10821, -1487, 10821,  1271, -1487, 10821,
   -1487, -1487, -1487,  1366, -1487, -1487,  8031, 10821,  1044, -1487,
   -1487, -1487, 10821, 10821, -1487, -1487, -1487,  8031,  8031,  1326,
    6481, 15664, 16552,   582, 16552, 10821, 16552,   583,  8031, -1487,
     456,    42,  1235, 16552, -1487,  1226,  1235, -1487, -1487, -1487,
   -1487, -1487, 10821, -1487, -1487, -1487,   178,   179,   199, 10821,
   -1487, -1487,  1179, 10821, -1487,   742, 11131, 11131,   400,   708,
   -1487, -1487, -1487, -1487, -1487, -1487, 10821, -1487, 15664, -1487,
   15664,  1327, -1487, -1487, -1487,  1394, -1487, -1487, -1487,  1163,
    1317, -1487, -1487,  1318, -1487,   724, 16552,  1308,  1212, 16552,
   11751, -1487, -1487, 10821, -1487,  1310, -1487, -1487,  1225, -1487,
   -1487, 15664, -1487, -1487, -1487,  1335, 10821,  1248, -1487,  1337,
    8031, -1487, 16552,   470,   511, -1487,  1236,  1235, -1487,  1238,
   -1487,  1233,  1160,  1161,   338, -1487,  1179,   400,   400, 11131,
     351, -1487, -1487, 15664, -1487, -1487,  1316, 11751, -1487,  1241,
    1159, 16552,  1319,  1214,  1318, -1487, 16552,   587, 15664,  6481,
   15664,  1258, -1487, -1487,  1346,   537, -1487, -1487, -1487, -1487,
    1259,   776, -1487, -1487, -1487,  1244, -1487,  8031,   830, -1487,
   -1487,   400, -1487, -1487, -1487, -1487, -1487, 10821,  1165, 16552,
    1324, -1487,  6481,   588, -1487, -1487,   644, 10821, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487,  1328, -1487,  1168,  1166, 16552,
   -1487, -1487, 10821,  8031, 16552,  1170, 10821,  1171,  1260, 11751,
   -1487, 11751,  8031, -1487,  1249,  1175, 16552,  1224,  1332, 16552,
    1173, 11751, -1487
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
     927,   813,   814,   967,   979,   966,   869,   888,   882,   815,
     870,   817,   816,   968,   906,   907,   874,   848,   989,   990,
     991,   992,   993,   994,   995,   996,   997,   998,   999,  1013,
    1020,   896,   892,   883,   862,   804,     0,   891,   899,   908,
    1014,   887,   493,   863,   864,   922,  1015,  1021,   884,   901,
       0,   499,   456,   495,   894,   828,   885,   886,   915,   889,
     905,   914,  1019,  1022,   834,   876,   917,   494,   904,   910,
     809,     0,     0,     0,     0,   403,   902,   913,   918,   916,
     895,   881,   969,   879,   880,  1016,     0,   402,     0,  1017,
    1023,   911,   865,   890,  1018,   212,   434,     0,   466,   912,
     893,   900,   909,   903,   970,   856,   861,   860,   859,   858,
     857,   818,   878,     0,   827,   925,   849,   960,   959,   961,
     833,   832,   852,   958,   811,   956,   963,   957,   955,   855,
     898,   954,   965,   964,   953,   853,   962,   974,   975,   972,
     973,   971,   819,   976,   977,   978,   945,   944,   931,   847,
     840,   938,   934,   850,   846,   946,   867,   836,   837,   830,
     839,   943,   942,   939,   935,   951,   952,   950,   941,   937,
     930,   838,   949,   948,   842,   844,   843,   936,   940,   932,
     845,   933,   841,   947,  1000,  1001,  1002,  1003,  1004,  1005,
     981,   982,   980,   986,   987,   988,   983,   984,   985,   854,
    1006,  1007,  1008,  1009,  1010,  1011,  1012,     0,     0,   820,
     821,  1024,  1025,   823,   822,   824,   165,   165,     0,     2,
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
    1013,  1020,   804,  1014,   864,  1015,  1021,   889,  1019,  1022,
     913,   969,  1016,  1017,  1023,  1018,   970,   958,   956,   957,
     955,   853,   974,   975,   972,   819,   976,   821,   454,   802,
     446,     0,   193,   447,   450,   805,   806,   808,   807,   812,
     813,   814,   815,   804,   811,   496,     0,   452,   451,   188,
       0,     0,   213,     0,   810,   817,   816,     0,   168,   782,
     976,     0,   221,     0,   497,     0,   528,     0,     0,   457,
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
       0,   405,   404,   401,     0,   168,   424,   426,   431,     0,
       0,     0,   441,   474,   444,   443,   455,     0,   471,     0,
       0,     0,   569,   571,   575,   577,     0,   124,     0,   801,
      47,    44,    45,    48,    49,     0,     0,     0,     0,    50,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   641,   642,   643,     0,   103,   142,     0,     0,   112,
       0,     0,     0,     0,   127,     0,     0,   614,     0,     0,
       0,   609,     0,     0,     0,   624,     0,     0,   257,   259,
       0,   236,   237,   256,     0,     0,     0,   134,     0,   138,
     168,   511,     0,    60,     0,    69,     0,     0,     0,    61,
       0,     0,     0,     0,   612,     0,     0,   615,     0,     0,
       0,     0,   325,     0,     0,   613,     0,     0,     0,   632,
       0,     0,     0,     0,   618,     0,     0,   195,     0,     0,
     189,   187,     0,     0,   788,     0,     0,     0,   496,     0,
     783,     0,   498,   529,   528,   525,     0,     0,     0,   559,
     558,   427,     0,   556,     0,   654,   655,     0,     0,     0,
       0,     0,   795,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   660,     0,   203,   204,     0,     0,
       0,     0,     0,   208,   209,   785,   787,     0,     5,    24,
       0,    25,     0,     7,    29,     0,    15,     8,    30,     0,
      19,   919,    77,    16,    78,    20,   194,     0,   192,   214,
     215,     0,     0,     0,     0,   206,   235,   294,   355,   357,
     361,   367,   366,   365,     0,   362,   359,   360,     0,   371,
     378,   377,   375,   381,   382,   383,   380,   385,   386,   389,
     388,     0,     0,     0,     0,   410,   436,   437,     0,   475,
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
     700,   929,   809,     0,   818,  1025,   823,   822,   824,   391,
     580,   586,   587,   590,   635,   636,   591,   592,   595,   393,
     395,   398,   596,   397,   476,     0,   473,   503,   125,    56,
      57,    54,    55,   131,   130,     0,    90,     0,     0,   109,
     110,   115,    74,    75,    52,    53,    73,   738,     0,   741,
     768,     0,   731,   730,   735,   734,   766,     0,     0,   743,
       0,   739,   742,   721,     0,     0,     0,     0,     0,     0,
       0,   608,     0,     0,     0,   143,   146,   148,     0,     0,
       0,   113,   116,     0,     0,     0,   168,     0,     0,   632,
       0,     0,     0,   261,     0,   579,     0,   262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   240,     0,     0,
       0,     0,   288,     0,   285,   290,   243,   141,   136,   139,
       0,   190,     0,     0,    71,    65,    68,    67,     0,    63,
     279,     0,     0,   168,     0,   323,   327,     0,     0,     0,
     330,     0,     0,   336,     0,     0,   343,     0,   347,     0,
     422,   421,   168,     0,     0,   197,     0,   199,   324,     0,
       0,     0,     0,   529,     0,   519,     0,   552,   549,     0,
     553,   554,     0,     0,   548,     0,   523,   551,   550,     0,
       0,     0,     0,   647,   648,   644,     0,     0,   652,   653,
     649,   791,   792,   658,   796,   656,     0,     0,     0,     0,
     662,   810,   817,   816,   976,   202,     0,     0,     0,   663,
     664,     0,     0,   211,   794,    26,     0,    17,    21,    22,
     306,   318,     0,   319,     0,   310,   311,   312,   313,     0,
     496,     0,   303,     0,     0,     0,   682,   695,     0,   369,
     373,     0,   714,     0,     0,     0,     0,     0,     0,   670,
     672,   673,   709,   710,   711,   713,   712,     0,     0,   686,
     685,     0,   689,   693,   707,   705,   704,   697,   701,     0,
       0,     0,     0,     0,     0,     0,     0,   583,   585,   584,
     581,   399,   505,   507,   133,   132,    91,   105,   755,   736,
       0,   760,     0,   760,   749,   744,   147,   149,     0,     0,
       0,   117,   145,     0,    27,     0,   629,   630,   633,   626,
     627,   260,     0,     0,   274,   266,     0,   270,     0,   264,
       0,     0,     0,   283,     0,     0,     0,   242,   286,   289,
       0,   137,     0,     0,    70,     0,    64,   280,     0,     0,
     326,   328,   333,     0,   331,     0,     0,     0,     0,     0,
     337,     0,     0,   351,     0,     0,   344,     0,     0,   348,
     423,     0,   622,   620,   198,   790,     0,     0,   528,     0,
       0,   560,     0,   528,     0,   524,     0,    14,     0,     0,
       0,     0,     0,     0,     0,   661,     0,     0,     0,     0,
       0,     0,   665,   669,   322,   320,   321,   314,   315,   316,
     308,     0,     0,   304,   297,   699,   690,   696,     0,     0,
     769,   770,   780,   779,   778,     0,     0,     0,     0,   771,
     676,   777,     0,   674,   678,     0,     0,   683,   687,     0,
     708,   703,   706,   702,     0,     0,   593,     0,   588,   640,
     582,   800,   799,   798,   589,   756,     0,     0,   754,   761,
     762,   758,     0,   753,     0,   751,     0,     0,     0,     0,
       0,     0,   570,   263,     0,   272,     0,     0,   268,     0,
     271,   284,   292,   293,   287,   241,     0,     0,     0,    66,
     282,   576,     0,     0,   334,   338,   332,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   572,
       0,     0,   528,     0,   555,     0,   528,   578,   645,   646,
     650,   651,     0,   657,   797,   659,     0,     0,     0,     0,
     666,   317,   298,     0,   694,   781,     0,     0,   773,     0,
     719,   718,   717,   716,   715,   680,     0,   772,     0,   637,
       0,     0,   765,   764,   763,     0,   757,   750,   748,     0,
     745,   746,   740,   150,   152,   154,     0,     0,     0,     0,
       0,   267,   265,     0,   273,     0,   207,   353,    72,   329,
     335,     0,   349,   345,   352,     0,     0,     0,   339,     0,
       0,   341,     0,   538,   532,   527,     0,   528,   518,     0,
     793,     0,     0,     0,     0,   301,   299,   775,   774,     0,
       0,   638,   594,     0,   759,   752,     0,     0,   156,   155,
       0,     0,     0,     0,   151,   269,     0,     0,     0,     0,
       0,     0,   546,   540,     0,   539,   541,   547,   544,   534,
       0,   533,   535,   545,   520,     0,   521,     0,     0,   667,
     300,   776,   688,   639,   747,   153,   157,     0,     0,     0,
       0,   291,     0,     0,   342,   340,     0,     0,   531,   542,
     543,   530,   536,   537,   522,     0,   158,     0,     0,     0,
     350,   346,     0,     0,     0,     0,     0,     0,     0,     0,
     160,     0,     0,   159,     0,     0,     0,     0,     0,     0,
       0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1487, -1487,  -229,  -202, -1487,  1192,  1193, -1487,  1200,  -560,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1010, -1487, -1487, -1487, -1487,  -245,  -584, -1487,   713,  -140,
   -1487, -1487, -1487, -1487, -1487,   257,   484, -1487, -1487,    -5,
    -201,  1035, -1487,  1006, -1487, -1487,  -639, -1487,   420, -1487,
     222, -1487,  -244,  -290, -1487,  -536, -1487,    -4,    76,    35,
    -231,  -179,  1174,  -883, -1487, -1487,  -190, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487,   595, -1487,   -79,
    1575,     0, -1487, -1487, -1487, -1487,   435, -1487, -1487,  -306,
   -1487,    23, -1487,  1007,  -949,  -723,  -717, -1487, -1487,   680,
   -1487, -1487,    -3,   212, -1487, -1487, -1487,    95, -1236, -1487,
     353,   102, -1487, -1487,   106, -1328, -1487,   927,   200, -1487,
   -1487,   196, -1040, -1487, -1487,   194, -1487, -1487, -1274, -1256,
   -1487,   190, -1436, -1487, -1487,   833,   834, -1487,  -555,   816,
   -1487, -1487,  -661,   348,  -655,   343,   345, -1487, -1487, -1487,
     555, -1487, -1487,  1181, -1487, -1487, -1487, -1487, -1487,  -902,
    -330,  -681, -1487,  -117, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487,   -13,  -835, -1487,  -543,   632,   258, -1487,  -418, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487,   782, -1487, -1487, -1487,
   -1487, -1034, -1487,   180, -1487,   661,  -820, -1487, -1487, -1487,
   -1487, -1487,  -289,  -281, -1251,  -975, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487,  -771,  -874,  -194,
    -854, -1487, -1487, -1487,  -845, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487,  1040,  1042,  -230,   482,   315, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
     156, -1487, -1487,   147, -1487,   150, -1072, -1487, -1487, -1487,
     109,   103,   -66,   373, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487,   114, -1487, -1487,
   -1487,   -60,   366,   513, -1487, -1487, -1487, -1487, -1487,   306,
   -1487, -1487, -1486, -1487, -1487, -1487,  -557, -1487,    74, -1487,
     -81, -1487, -1487, -1487, -1487, -1334, -1487,   127, -1487, -1487,
   -1487, -1487, -1487,   930, -1487, -1487, -1487, -1487, -1487,  -930,
    -410,  1087,   261, -1487
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   258,   637,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
    1274,   788,   276,   277,   278,   279,   280,   281,   966,   967,
     968,   282,   283,   284,   972,   973,   974,   285,   449,   286,
     287,   716,   288,   451,   452,   453,   468,   778,   779,   289,
    1225,   290,  1703,  1704,   291,   292,   293,   560,   294,   295,
     296,   297,   298,   781,   299,   300,   542,   301,   302,   303,
     304,   305,   306,   647,   307,   308,   873,   874,   309,   310,
     311,   572,   313,   648,   466,  1033,  1034,   314,   649,   315,
     651,   573,   317,   768,   769,  1262,   475,   318,   476,   477,
     775,  1263,  1264,  1265,   652,   653,  1133,  1134,  1382,   654,
    1129,  1130,  1375,  1376,  1377,  1378,   319,   801,   802,   320,
    1289,  1290,  1495,   321,  1292,  1293,   322,   323,  1295,  1296,
    1297,  1298,  1502,   324,   325,   326,   327,   914,   328,   329,
    1389,   330,   331,   332,   333,   334,   335,   336,   337,   338,
    1170,   339,   340,   341,   342,   672,   673,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   708,   703,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   943,   370,   371,   372,
     373,   374,   375,  1325,   834,   835,   836,  1735,  1780,  1781,
    1774,  1775,  1782,  1776,  1326,  1327,   376,   377,  1328,   378,
     379,   380,   381,   382,   383,   384,   385,  1028,  1503,  1430,
    1160,  1587,  1161,  1171,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   808,  1238,   398,  1163,
    1164,  1165,  1166,   399,   400,   401,   402,   403,   404,   863,
     864,   405,  1359,  1360,  1670,  1115,  1141,  1399,  1400,  1142,
    1143,  1144,  1145,  1146,  1409,  1577,  1578,  1147,  1412,  1148,
    1558,  1149,  1150,  1417,  1418,  1583,  1581,  1401,  1402,  1403,
    1404,  1683,   745,   993,   994,   995,   996,   997,   998,  1211,
    1607,  1700,  1212,  1605,  1698,   999,  1443,  1602,  1598,  1599,
    1600,  1000,  1001,  1405,  1413,  1568,  1406,  1564,  1390,   406,
     407,   408,   409,   563,   410,   411,   412,   413,   414,  1167,
    1275,   415,   416,   417
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -867;
  const short int
  xquery_parser::yytable_[] =
  {
       312,   422,   425,   426,   609,   312,   312,   312,   312,   450,
     650,   717,   717,   935,  1084,   697,  1139,   922,   624,  1048,
     587,   720,  1291,   316,   923,   924,   925,   926,   316,   316,
     316,   316,  1060,   571,   575,   627,  1279,  1114,  1517,  1506,
     424,   424,   424,   428,   892,   894,  1074,  1026,  1548,  1549,
     629,   852,  1324,  1027,   616,   617,   859,  1159,  1169,   625,
     625,   785,   789,   538,   632,  1385,   884,   888,  1643,  1022,
    1184,  1647,  1243,  1227,  1525,    13,  1251,  1579,    11,    12,
    1030,   423,   423,   423,   427,   631,  1162,  1162,   953,  1214,
     886,   890,   893,   895,  1215,   759,    11,    12,   435,   625,
     625,   625,   910,  1216,   911,   912,   625,   913,   436,   915,
    1217,   312,  1218,   760,  1281,  1188,   435,   916,   917,   598,
    1701,  1219,  1706,   625,  1162,   625,   438,   822,  1023,   634,
    1024,   439,   625,   625,   316,   625,  1733,  1024,   625,   625,
     625,   625,   719,   625,   438,  1107,   561,   473,  1220,  1245,
     431,   432,   625,   433,   434,  1496,    82,  1644,  1226,   625,
     948,  1440,  1268,   440,   441,  1124,   636,   636,   611,   613,
      93,   437,   589,  1057,   625,   823,   948,   625,  1162,   625,
     625,  1025,   751,  1560,   494,  1372,  1208,   423,  1252,   625,
     839,  1162,   454,   632,  1288,   107,   729,   632,   621,  1136,
     625,   710,  1137,  1209,  1191,   759,  1374,  1493,   599,  -169,
     625,   635,   711,   636,   622,   495,   633,   719,   496,  1671,
    1561,  1442,   128,   760,  1645,  1734,   786,  1366,  1707,   730,
     982,   698,   983,  -170,   625,  1139,  1139,   625,  1100,   949,
    1497,  1031,   636,  1565,   474,   636,   636,   636,   636,   631,
     636,   625,  1499,  1058,   625,   950,   312,   312,  1256,   636,
     312,  1506,  1314,  1391,  1267,   625,   636,   650,  1486,  1525,
    1794,  1699,  1108,   787,   443,  1221,   984,   625,  1032,   316,
     316,   636,  1324,   316,   636,  1767,   636,   636,   626,   628,
     879,  1324,   832,  1461,   625,   312,   636,   892,   894,  1421,
    1101,   474,  1435,  1227,  1138,  1253,   474,   636,  1162,  1249,
    1708,  1254,   881,   474,  1121,  1557,  1185,   636,   316,   884,
     888,  1123,  1365,   625,  1040,  1062,  1063,  1111,   979,  1310,
     632,  1282,  1803,   444,  1806,  1392,   830,   539,   446,   625,
     704,   636,  1016,   706,   636,   633,   447,   761,   784,   633,
    1092,   539,   625,  1057,   448,   590,   752,   840,   636,  1135,
    1311,   636,  1248,  1312,   753,  1741,  1742,  1222,  1223,  1224,
     875,   876,   636,  1174,   445,   539,  1470,  1758,  1045,  1096,
     764,   885,   889,  1103,   636,   685,  1743,   539,  1226,   539,
     782,  1496,   600,  -169,   880,   882,  1481,   601,   676,   686,
     795,   636,  1566,  1567,   897,  1085,   488,   806,   807,  1288,
      11,    12,  1496,   878,   905,   677,   813,  -170,  1393,  1394,
    1052,  1395,  1498,  1391,   312,  1162,   985,   592,   312,   593,
     636,  1796,  1017,  1076,  1068,  1019,  1745,  1087,  1397,   986,
     896,   987,   429,   701,   898,   707,   636,   316,  1088,  1162,
    1398,   316,   988,   989,   990,   312,   991,   312,   992,   636,
    1089,  1451,   701,   639,   707,  1676,   595,   640,   596,  1788,
    1037,  1086,   641,  1093,  1094,  1772,  1633,  1113,   316,  1317,
     316,   602,   633,   489,   312,  1139,  1324,   474,  1095,   312,
     428,   642,   428,  1069,  1139,  1392,   630,  1638,   837,   838,
    1140,   474,  1097,  1098,   823,  1139,  1555,   316,  1680,   842,
    1790,  1018,   316,  1361,  1020,  1681,   594,  1099,  1071,   428,
    1317,  1463,  1789,  1114,   428,  1682,  1175,  1543,   869,   871,
    1178,   756,  1506,   758,  1175,  1792,  1471,   892,   894,   892,
    1778,   887,  1772,  1677,  1534,  1586,  1317,  1448,  1596,  1038,
     490,   491,  1023,  1690,   461,   597,   462,   457,  1023,   676,
     804,   312,  1695,  1347,  1315,   810,  1192,  1193,   312,  1362,
     483,  1196,  1070,  1120,  1162,  1732,   677,   679,  1393,  1394,
     824,  1395,   936,   937,   316,  1367,  1368,  1369,  1396,   643,
    1090,   316,   644,   735,  1320,   736,  1321,  1072,  1397,   776,
    1047,  1235,   492,   424,  1773,  1176,   680,   645,   312,  1552,
    1398,  1059,  1597,  1177,   539,   312,   450,   539,  1718,   681,
     463,  1669,   938,  1208,  1322,   464,   312,   312,   312,   312,
    1316,   316,  1691,   646,  1118,  1320,    13,  1321,   316,   632,
    1209,  1696,  1645,   870,   423,   312,  1779,   430,  1091,   316,
     316,   316,   316,   682,  1024,   738,  1122,  1427,    13,  1162,
     882,  1320,  1162,  1321,  1202,  1322,  1125,   777,   316,  1440,
    1023,  1809,   465,  1139,  1024,  1203,   735,  1362,   736,    11,
      12,  1504,   701,  1210,   707,   725,  1441,  1023,  1428,   431,
     432,  1322,   433,   434,  1505,   312,   727,   539,  1651,   435,
     539,   726,  1499,  1655,   539,  1462,  1429,   539,   539,   436,
     437,   737,  1317,  1318,   493,   539,   739,    82,   316,  1140,
    1140,   539,   539,  1255,   639,  1616,   539,   438,   640,  1442,
     424,    93,   439,   641,   539,  1073,   969,  1572,   738,    82,
    1023,   539,   539,   539,   539,  1617,  1079,  1080,  1081,   539,
     871,  1640,   642,    93,  1317,  1318,   107,   539,  1777,  1783,
    1136,   458,   887,  1137,   440,   441,   442,  1724,  1726,  1730,
    1179,   423,  1611,  1802,  1822,  1641,  1039,  1258,   107,   970,
     312,   892,  1259,   128,   971,  1317,  1180,  1237,  1551,  1240,
    1258,  1112,  1641,  1641,  1119,  1259,  1162,  1641,  1641,   739,
    1777,  1260,   539,   316,   721,  1778,  1783,  1319,   676,   697,
     622,   312,   312,   443,  1751,   424,  1752,   539,   722,  1023,
    1024,  1414,  1415,   467,  1181,   677,  1186,  1320,   539,  1321,
    1823,  1372,  1736,  1024,   316,   316,  1739,   723,  1186,  1303,
    1182,  1304,  1261,  1162,  1416,  1162,   428,   428,   678,  1319,
     643,   724,   695,   644,  1641,   853,   423,  1322,  1317,  1318,
     853,   114,   469,  1484,   539,  1183,   478,   676,   831,  1320,
     312,  1321,   444,  1317,  1318,   128,  1162,   126,  1680,  1793,
    1355,   780,   470,   897,   677,  1681,   450,  1066,  1067,   882,
     481,   471,  1387,   316,   646,  1682,  1507,   312,  1323,  1322,
    1320,  1371,  1321,   114,  1675,  1678,  1679,  1749,  1162,  1508,
    1434,  1812,  1372,   445,   482,   128,   153,  1785,   472,   126,
     316,  1204,  1373,  1162,   486,  1162,   780,  1705,  1562,  1504,
    1322,  1504,  1205,  1374,  1759,  1563,  1363,   639,   487,   446,
    1519,   640,  1650,   683,  1815,  1229,   641,   447,  1331,   540,
    1332,   749,   684,  1319,  1230,   448,   750,   541,   153,   970,
     939,   556,  1544,   939,   971,   642,   939,  1258,  1319,  1140,
     543,  1553,  1259,  1320,   455,  1321,   544,   456,  1140,  1197,
    1198,  1199,   557,   459,   702,  1200,   460,   705,  1320,  1140,
    1321,   479,   955,   484,   480,   539,   485,   558,   741,   742,
     743,   579,  1336,  1322,  1337,   699,   700,   114,   577,   539,
    1194,  1195,   578,   539,   539,  1747,  1748,   584,  1322,  1545,
    1546,   585,   114,   126,   920,   921,   927,   928,   586,  1705,
     929,   930,  1446,  1447,   588,   539,  -608,   539,   126,  1692,
    1693,  1482,   603,   591,  1524,   539,   606,   604,   539,   605,
     607,   650,   539,   608,   614,   618,   638,  1384,   655,  1653,
     656,   674,   153,   643,   312,   675,   644,   687,   688,   690,
     689,   701,   709,   712,   719,  1629,  1705,   153,   694,   731,
     713,  1540,   733,   734,   714,   715,   744,   316,  1791,   748,
     757,   771,   774,   772,   539,   657,   780,   783,   791,   428,
     792,   793,   811,   658,   659,   794,   660,   646,   805,   812,
     456,  1356,   820,   460,   661,   450,   480,   485,   662,   818,
     663,   312,   312,   312,   822,   664,   496,   825,   826,   827,
     833,   829,   841,   539,  1357,   844,   843,   861,   862,   866,
    1299,   665,   867,   883,   316,   316,   316,   872,  1833,   901,
    1834,   902,   903,   918,   904,   931,   932,  1140,   933,   934,
    1842,   944,   539,   945,   951,   666,   667,   668,   669,   670,
     671,   954,   976,   952,   980,   609,   977,   555,   956,   957,
     958,   959,   960,   961,   962,   963,   964,   965,  1003,  1002,
     981,  1004,   539,   539,   539,   539,  1006,  1008,  1012,  1011,
    1013,   576,  1021,  1036,  1042,  1014,  1015,  1043,  1046,  1053,
    1054,  1055,  1056,   580,  1064,   583,   455,  1061,  1065,  1102,
    1105,   459,   479,   484,   495,  1104,  1109,  1106,  1110,  1120,
     539,  1117,  1455,  1187,   971,  1206,   312,  1023,  1233,  1228,
    1207,  1127,  1236,  1234,   539,  1244,  1246,  1250,  1257,   776,
    1270,  1273,  1272,  1276,  1277,  1278,  1271,  1283,  1284,   316,
    1287,  1288,  1294,  1300,  1301,  1306,  1635,  1302,  1309,   539,
    1313,   424,   312,  1329,  1307,  1330,  1348,   737,   539,  1489,
     539,  1358,   539,   312,   539,  1379,  1381,  1407,  1383,  1388,
    1419,  1408,  1420,  1411,  1422,   316,  1431,   539,  1511,    13,
    1439,  1423,   312,  1444,  1424,  1425,   316,  1426,  1449,   905,
    1454,  1450,   423,  1438,  1458,  1456,  1453,  1468,   424,  1457,
    1466,  1459,   312,  1460,  1472,   316,  1474,  1475,  1476,   312,
     539,  1480,   539,  1485,  1488,  1504,  1510,   424,  1521,  1518,
    1512,  1513,  1528,  1516,  1532,   316,  1527,  1529,  1372,  1530,
    1536,  1537,   316,  1361,  1556,  1538,  1531,   428,  1539,   423,
    1559,  1356,  1533,  1575,   428,  1582,  1595,   853,  1576,  1588,
    1589,  1580,  1590,  1591,  1592,  1593,  1569,  1594,   423,  1601,
    1606,  1608,  1626,  1627,  1357,  1614,  1612,  1619,  1610,  1628,
    1632,  1631,   539,  1662,  1649,  1716,   870,  1673,  1522,  1637,
    1604,  1654,  1648,  1657,  1674,  1526,  1720,  1635,  1688,  1722,
    1689,  1686,  1697,  1208,   539,  1702,  1710,  1731,  1687,  1713,
    1715,  1721,  1753,  1738,  1754,  1756,  1757,  1761,  1755,  1766,
    1768,  1787,  1770,  1784,  1769,  1786,  1709,  1762,  1799,  1800,
    1808,  1814,  1811,  1819,  1807,  1437,  1832,  1824,  1835,  1838,
     978,  1839,   619,   620,  1189,  1452,   754,  1269,  1666,  1667,
    1668,  1825,  1836,   623,  1797,   718,  1764,  1795,  1116,  1266,
    1817,  1826,   773,  1051,  1479,  1624,  1829,  1831,  1554,  1841,
    1370,  1550,  1547,   819,  1490,  1494,  1500,  1509,   908,  1173,
     909,   919,  1813,   947,  1810,  1083,  1520,   312,   762,  1722,
     763,  1241,  1436,   539,  1535,  1570,  1542,   539,  1541,  1685,
    1574,  1386,  1684,  1410,  1573,  1213,  1445,  1603,  1694,   696,
     316,   693,   539,   728,  1571,     0,   732,   857,     0,     0,
     740,   539,     0,   746,   747,     0,     0,     0,  1804,     0,
    1356,   755,     0,     0,     0,   539,     0,   767,   770,     0,
       0,     0,   770,     0,     0,   539,  1482,     0,     0,     0,
     790,     0,     0,  1357,     0,     0,     0,   798,   799,   800,
     803,  1820,     0,     0,     0,   809,     0,     0,     0,     0,
       0,     0,     0,   816,   539,     0,     0,     0,     0,     0,
    1744,     0,  1820,     0,     0,     0,     0,     0,     0,     0,
       0,  1804,     0,     0,     0,     0,     0,  1750,     0,   539,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   539,
       0,     0,     0,   539,     0,     0,  1356,     0,   817,     0,
       0,     0,     0,     0,     0,     0,     0,  1356,  1356,     0,
     312,     0,     0,   803,     0,     0,     0,     0,  1356,  1357,
       0,     0,     0,     0,   828,     0,     0,     0,     0,     0,
    1357,  1357,     0,   316,     0,     0,     0,     0,     0,     0,
       0,  1357,     0,     0,     0,     0,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,   562,     0,     0,     0,
     865,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     539,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1356,     0,     0,     0,     0,     0,   539,   539,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1357,     0,     0,     0,     0,     0,     0,
       0,     0,   539,     0,     0,   539,     0,     0,   539,   312,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     539,     0,     0,     0,     0,   539,     0,  1356,     0,     0,
       0,     0,   316,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   312,     0,     0,     0,     0,     0,     0,     0,
    1357,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   975,     0,  1356,     0,   316,     0,     0,     0,     0,
       0,     0,  1356,     0,     0,  1005,     0,     0,     0,  1009,
    1010,     0,     0,     0,     0,     0,  1357,     0,     0,     0,
       0,     0,     0,     0,     0,  1357,     0,     0,     0,     0,
       0,  1029,     0,  1035,     0,     0,     0,     0,     0,     0,
       0,  1041,     0,     0,  1044,     0,     0,     0,  1049,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   539,   539,     0,   539,     0,   539,     0,     0,
       0,     0,     0,     0,   539,     0,     0,     0,     0,     0,
    1082,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   539,
       0,   539,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   539,     0,     0,
     539,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   539,     0,     0,     0,     0,     0,  1126,     0,
       0,     0,     0,   539,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   539,     0,     0,     0,  1168,  1168,
    1172,  1172,   539,     0,     0,     0,     0,   539,     0,   539,
       0,   539,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1168,     0,     0,     0,
     539,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1201,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     539,     0,     0,     0,     0,   539,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1232,     0,   539,     0,     0,
     539,     0,     0,     0,  1239,     0,  1239,     0,   770,     0,
    1168,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   562,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   809,     0,   809,     0,
       0,     0,     0,     0,     0,     0,     0,   845,   846,     0,
     854,   855,   856,   858,     0,   860,     0,     0,     0,     0,
       0,   868,     0,     0,     0,     0,     0,     0,     0,   877,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   899,   900,     0,     0,     0,     0,     0,  1380,     0,
     906,   907,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1168,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   942,     0,     0,     0,   942,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1007,     0,     0,     0,   770,
       0,     0,     0,  1464,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1478,     0,
       0,     0,     0,     0,     0,     0,     0,  1168,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1050,     0,     0,
       0,   803,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1075,     0,     0,     0,  1077,  1078,     0,
       0,     0,     0,     0,     0,     0,   906,     0,     0,     0,
    1523,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   865,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   900,     0,     0,     0,     0,     0,  1128,  1132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1609,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1622,  1623,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1231,     0,     0,     0,     0,     0,     0,  1639,     0,
       0,  1168,     0,     0,  1168,     0,     0,     0,     0,     0,
    1247,     0,     0,     0,     0,     0,  1652,     0,     0,     0,
       0,  1656,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1280,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1285,  1286,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1305,     0,
       0,  1308,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1333,  1334,
    1335,     0,  1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,
    1346,     0,     0,  1349,  1350,     0,     0,     0,     0,     0,
       0,     0,  1364,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1168,  1725,
       0,  1727,     0,  1729,     0,     0,     0,     0,     0,     0,
    1737,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1433,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1168,     0,  1168,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1760,     0,     0,  1763,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1771,
       0,     0,     0,  1465,     0,  1467,     0,  1469,     0,     0,
    1473,     0,     0,     0,     0,  1477,     0,     0,     0,     0,
    1168,     0,     0,     0,     0,     0,     0,  1483,  1798,     0,
       0,     0,     0,  1801,     0,  1168,  1487,  1168,     0,     0,
       0,     0,  1491,  1492,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1514,     0,     0,  1515,     0,  1818,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1827,     0,     0,     0,
       0,  1828,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1837,     0,     0,  1840,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1128,     0,     0,     0,  1132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1613,     0,     0,
       0,  1615,     0,     0,     0,  1618,     0,  1620,     0,  1621,
       0,     0,     0,     0,     0,  1625,     0,     0,     0,     0,
       0,     0,     0,  1630,     0,     0,     0,     0,     0,     0,
       0,  1634,  1636,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1483,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1658,  1659,  1660,  1661,     0,  1663,  1664,
       0,  1665,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1672,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1711,
       0,  1712,     0,     0,  1714,     0,     0,     0,     0,     0,
       0,     0,  1717,     0,     0,     0,     0,  1719,  1636,     0,
       0,     0,     0,     0,     0,  1723,     0,     0,     0,     0,
    1728,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1740,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1746,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1765,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1723,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1805,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1816,     0,     0,     0,     0,  1821,     0,     0,
       0,     0,  1805,  -165,   887,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     0,  1821,     0,     3,
       0,  1830,     0,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     0,    13,     0,     0,    14,   419,     0,    16,
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
     244,   245,   246,   247,     0,   248,     0,   249,   250,   251,
     252,   253,   254,   255,  -165,   887,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,   891,   419,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   420,    30,    31,    32,    33,    34,     0,
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
     132,     0,   133,   134,   135,   136,   137,     0,   138,     0,
     139,     0,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,   153,     0,   421,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   887,   248,     0,   249,   250,
     251,   252,   253,   254,   255,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,   418,   419,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   420,    30,    31,    32,    33,    34,     0,
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
     132,     0,   133,   134,   135,   136,   137,     0,   138,     0,
     139,     0,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,   153,     0,   421,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   887,   248,     0,   249,   250,
     251,   252,   253,   254,   255,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   418,   419,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   564,   420,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,   565,   566,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   514,    85,    86,
      87,    88,    89,   567,    91,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   568,   112,
       0,   113,   114,   115,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
     127,   128,     0,     0,   129,   130,   131,     0,     0,     0,
     132,     0,   133,   134,     0,   136,   137,     0,   138,     0,
     139,     0,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,   153,     0,   421,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   532,   533,   534,   180,   181,   535,   570,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     0,   248,     0,   249,   250,
     251,   252,   253,   254,   255,  -866,   461,     0,   462,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -866,     0,     0,
       0,  -866,     0,     0,     0,  -866,  -866,     0,     0,     0,
       0,  -866,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   463,     0,     0,  -866,     0,   464,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -866,     0,
    -866,  -866,  -866,     0,     0,  -866,  -866,  -866,  -866,     0,
       0,     0,  -866,  -866,     0,     0,     0,     0,     0,  -866,
       0,     0,  -866,  -866,   465,     0,     0,  -866,     0,     0,
       0,     0,  -866,  -866,     0,     0,     0,     0,  -866,     0,
       0,     0,  -866,     0,     0,     0,  -866,  -866,     0,  -866,
       0,  -866,  -866,     0,     0,     0,  -866,  -866,     0,     0,
    -866,  -866,  -866,  -866,  -866,  -866,     0,     0,  -866,     0,
       0,     0,  -866,  -866,     0,     0,  -866,     0,     0,     0,
       0,  -866,     0,     0,  -866,     0,     0,     0,     0,  -866,
    -866,  -866,  -866,  -866,     0,  -866,  -866,  -866,  -866,  -866,
       0,     0,     0,     0,  -866,  -866,  -866,     0,  -866,  -866,
    -866,  -866,  -866,  -866,     0,  -866,     0,  -866,     0,     0,
       0,     0,  -866,  -866,  -866,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -866,     0,
    -866,     0,  -866,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -866,     0,     0,     0,     0,  -866,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,  -866,    13,  -866,     0,
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
       0,     0,     0,   132,     0,   133,   134,   135,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,   256,   257,
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
     130,   131,     0,     0,     0,   132,     0,   133,   134,   135,
     136,   137,     0,   138,     0,   139,     0,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,     0,     0,
     151,   152,   153,     0,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,     0,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
       0,   248,     0,   249,   250,   251,   252,   253,   254,   255,
       0,   615,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
     420,    30,    31,    32,    33,    34,     0,    35,    36,    37,
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
       0,   129,   130,   131,     0,   559,     0,   132,     0,   133,
     134,   135,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
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
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
     420,    30,    31,    32,    33,    34,     0,    35,    36,    37,
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
       0,   129,   130,   131,     0,   821,     0,   132,     0,   133,
     134,   135,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
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
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,  1351,
     420,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,  1352,  1353,    53,    54,    55,    56,
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
       0,   129,   130,   131,     0,   559,     0,   132,     0,   133,
     134,   135,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,  1354,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     0,   249,   250,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
     420,    30,    31,    32,    33,    34,     0,    35,    36,    37,
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
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
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
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
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
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,    14,   419,     0,    16,    17,    18,
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
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
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
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   891,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
     420,    30,    31,    32,    33,    34,     0,    35,    36,    37,
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
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
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
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,    11,    12,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,  1351,
     420,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,  1352,  1353,    53,    54,    55,    56,
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
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,  1354,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     0,   249,   250,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   564,
     420,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   565,   566,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   514,    85,    86,    87,    88,    89,
     567,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,   940,     0,   104,   105,
     106,   107,   108,   109,   110,   568,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,   941,   133,
     134,     0,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   532,
     533,   534,   180,   181,   535,   570,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     0,   249,   250,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   564,
     420,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   565,   566,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   514,    85,    86,    87,    88,    89,
     567,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,   940,     0,   104,   105,
     106,   107,   108,   109,   110,   568,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,   946,   133,
     134,     0,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   532,
     533,   534,   180,   181,   535,   570,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     0,   249,   250,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   564,
     420,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   565,   566,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   514,    85,    86,    87,    88,    89,
     567,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   568,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,   569,   132,     0,   133,
     134,     0,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   532,
     533,   534,   180,   181,   535,   570,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     0,   249,   250,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   564,
     420,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   565,   566,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   514,    85,    86,    87,    88,    89,
     567,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   568,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,   574,   133,
     134,     0,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   532,
     533,   534,   180,   181,   535,   570,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     0,   249,   250,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   564,
     420,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   565,   566,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   514,    85,    86,    87,    88,    89,
     567,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   568,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   532,
     533,   534,   180,   181,   535,   570,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   610,   248,     0,   249,   250,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   564,
     420,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   565,   566,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   514,    85,    86,    87,    88,    89,
     567,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   568,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   532,
     533,   534,   180,   181,   535,   570,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,   612,   249,   250,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   564,
     420,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   565,   566,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   514,    85,    86,    87,    88,    89,
     567,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,  1432,     0,   104,   105,
     106,   107,   108,   109,   110,   568,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   532,
     533,   534,   180,   181,   535,   570,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     0,   249,   250,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   500,    27,   502,
     420,    30,   503,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   505,
       0,    48,    49,    50,   507,   508,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   514,    85,    86,    87,    88,    89,
     567,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   517,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   568,   112,     0,   113,   114,
     691,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   692,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   527,   164,   528,   166,   529,
     530,   169,   170,   171,   172,   173,   174,   531,   176,   532,
     533,   534,   180,   181,   535,   536,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     0,   249,   537,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   564,
     420,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   565,   566,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   514,    85,    86,    87,    88,    89,
     567,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   568,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   532,
     533,   534,   180,   181,   535,   570,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     0,   249,   250,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   500,    27,   502,
     420,    30,   503,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   505,
       0,    48,    49,    50,   507,   508,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   514,    85,    86,    87,    88,    89,
     567,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   517,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   568,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   527,   164,   528,   166,   529,
     530,   169,   170,   171,   172,   173,   174,   531,   176,   532,
     533,   534,   180,   181,   535,   536,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     0,   249,   537,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   564,
     420,    30,    31,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
       0,    48,    49,    50,   565,   566,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   514,    85,    86,    87,    88,    89,
    1131,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,    99,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   568,   112,     0,   113,   114,
     115,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,   127,   128,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   532,
     533,   534,   180,   181,   535,   570,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     0,   249,   250,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   500,    27,   502,
     420,    30,   503,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   505,
       0,    48,    49,    50,   507,   508,    53,   509,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   514,    85,    86,    87,    88,    89,
     567,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   517,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   568,   112,     0,   113,   114,
       0,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,     0,     0,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,   136,   137,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   527,   164,   528,   166,   529,
     530,   169,   170,   171,   172,   173,   174,   531,   176,   532,
     533,   534,   180,   181,   535,   536,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     0,   249,   537,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   500,    27,   502,
     420,    30,   503,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   505,
       0,    48,    49,    50,   507,   508,    53,   509,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   514,    85,    86,    87,    88,    89,
     567,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   517,   100,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,   108,   109,   110,   568,   112,     0,   113,   114,
       0,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,     0,     0,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,     0,     0,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   527,   164,   528,   166,   529,
     530,   169,   170,   171,   172,   173,   174,   531,   176,   532,
     533,   534,   180,   181,   535,   536,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     0,   249,   537,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     5,     6,     7,     8,     9,    10,     0,     0,
       0,    13,     0,     0,   418,   419,     0,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   500,    27,   502,
     420,    30,   503,    32,    33,    34,     0,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   505,
       0,    48,    49,    50,   507,   508,    53,   509,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,    72,    73,    74,    75,
      76,     0,    77,    78,    79,     0,     0,    80,    81,     0,
       0,     0,    82,    83,   514,    85,    86,    87,    88,    89,
     567,    91,    92,     0,     0,     0,    93,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   517,     0,   101,
     102,   103,     0,     0,     0,     0,     0,     0,   104,   105,
     106,   107,     0,   109,   110,   568,   112,     0,   113,   114,
       0,   116,   117,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,   125,     0,   126,     0,     0,     0,     0,
       0,   129,   130,   131,     0,     0,     0,   132,     0,   133,
     134,     0,     0,     0,     0,   138,     0,   139,     0,   140,
       0,   142,     0,   144,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,   153,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   527,   164,   528,   166,   529,
     530,   169,   170,   171,   172,   173,   174,   531,   176,   532,
     533,   534,   180,   181,   535,   536,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     0,   248,     0,   249,   537,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     0,     0,     0,     0,     9,    10,     0,     0,
       0,     0,     0,     0,   418,   419,     0,    16,    17,    18,
     497,    20,    21,    22,   498,    24,   499,   500,   501,   502,
     420,    30,   503,    32,    33,    34,     0,    35,    36,    37,
      38,   504,    40,    41,    42,    43,    44,    45,    46,   505,
       0,    48,   506,    50,   507,   508,    53,   509,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   510,   511,    71,     0,    72,    73,    74,   512,
       0,     0,    77,    78,    79,     0,     0,   513,    81,     0,
       0,     0,     0,    83,   514,    85,   515,   516,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   517,   100,   101,
     518,   519,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,   110,     0,     0,     0,     0,     0,
       0,   116,   520,     0,     0,     0,   118,   119,   120,   121,
     521,   123,   124,   522,     0,     0,     0,     0,     0,     0,
       0,   523,   524,   131,     0,     0,     0,   132,     0,   133,
     525,     0,     0,     0,     0,   138,     0,   139,     0,   140,
     141,   142,   143,   526,   145,   146,   147,   148,   149,   150,
       0,     0,   151,   152,     0,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   527,   164,   528,   166,   529,
     530,   169,   170,   171,   172,   173,   174,   531,   176,   532,
     533,   534,   180,   181,   535,   536,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,     0,     0,     0,     0,   249,   537,   251,   252,   253,
     254,   255,     1,     2,     0,     0,     0,     3,     0,     0,
       0,     4,     0,     0,     0,     0,     9,    10,     0,     0,
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
     525,     0,     0,     0,     0,   138,     0,   139,     0,   140,
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
     418,   419,     0,    16,    17,    18,   497,    20,    21,    22,
     498,    24,   499,   500,  1151,   502,   420,    30,   503,    32,
      33,    34,     0,    35,    36,    37,    38,   504,    40,    41,
      42,    43,    44,    45,    46,   505,     0,    48,   506,    50,
     507,   508,    53,   509,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,   510,   511,
      71,     0,    72,    73,    74,   512,     0,     0,    77,    78,
      79,     0,     0,   513,    81,     0,     0,     0,     0,    83,
     514,    85,   515,   516,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,   517,   100,   101,   518,   519,     0,     0,
       0,     0,     0,     0,   104,   105,   106,     0,   108,   109,
    1152,     0,     0,     0,  1153,     0,     0,   116,   520,     0,
       0,     0,   118,   119,   120,   121,   521,   123,   124,   522,
       0,     0,     0,     0,     0,     0,     0,   523,   524,   131,
       0,     0,     0,   132,  1584,   133,   525,     0,     0,     0,
       0,  1585,     0,   139,     0,   140,   141,   142,   143,   526,
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
     240,   241,   242,   243,   244,   245,   246,     0,     0,     0,
       0,   249,   537,   251,  1155,  1156,  1157,  1158,     3,     0,
     581,   582,     0,     0,     0,     0,     0,     9,    10,     0,
       0,     0,     0,     0,     0,   418,   419,     0,    16,    17,
      18,   545,    20,    21,    22,   498,   546,   547,   500,   501,
     502,   420,    30,   503,    32,   548,    34,     0,    35,    36,
      37,    38,   549,    40,   550,   551,    43,    44,    45,    46,
     505,     0,    48,   552,    50,   507,   508,    53,   509,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   510,   511,    71,     0,    72,    73,    74,
     553,     0,     0,    77,    78,    79,     0,     0,   513,    81,
       0,     0,     0,     0,    83,   514,    85,   515,   516,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   517,   100,
     101,   518,   519,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,   116,   520,     0,     0,     0,   118,   119,   120,
     121,   521,   123,   124,   522,     0,     0,     0,     0,     0,
       0,     0,   523,   524,   131,     0,     0,     0,   132,     0,
     133,   525,     0,     0,     0,     0,     0,     0,   139,     0,
     140,   141,   142,   143,   526,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,     0,     0,   421,   155,   156,
     157,   158,   159,   160,   161,   162,   527,   554,   528,   166,
     529,   530,   169,   170,   171,   172,   173,   174,   531,   176,
     532,   533,   534,   180,   181,   535,   536,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,     0,     3,     0,   249,   537,   251,   252,
     253,   254,   255,     9,    10,     0,     0,     0,     0,     0,
       0,   418,   419,     0,    16,    17,    18,   545,    20,    21,
      22,   498,   546,   547,   500,   501,   502,   420,    30,   503,
      32,   548,    34,     0,    35,    36,    37,    38,   549,    40,
     550,   551,    43,    44,    45,    46,   505,     0,    48,   552,
      50,   507,   508,    53,   509,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   510,
     511,    71,     0,    72,    73,    74,   553,     0,     0,    77,
      78,    79,     0,     0,   513,    81,     0,     0,     0,     0,
      83,   514,    85,   515,   516,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   517,   100,   101,   518,   519,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,   110,     0,     0,     0,     0,     0,     0,   116,   520,
       0,     0,     0,   118,   119,   120,   121,   521,   123,   124,
     522,     0,     0,     0,     0,     0,     0,     0,   523,   524,
     131,     0,     0,     0,   132,   765,   133,   525,     0,     0,
       0,     0,   766,     0,   139,     0,   140,   141,   142,   143,
     526,   145,   146,   147,   148,   149,   150,     0,     0,   151,
     152,     0,     0,   421,   155,   156,   157,   158,   159,   160,
     161,   162,   527,   554,   528,   166,   529,   530,   169,   170,
     171,   172,   173,   174,   531,   176,   532,   533,   534,   180,
     181,   535,   536,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,     0,
       3,     0,   249,   537,   251,   252,   253,   254,   255,     9,
      10,     0,     0,     0,   796,     0,     0,   418,   419,     0,
      16,    17,    18,   545,    20,    21,    22,   498,   546,   547,
     500,   501,   502,   420,    30,   503,    32,   548,    34,     0,
      35,    36,    37,    38,   549,    40,   550,   551,    43,    44,
      45,    46,   505,     0,    48,   552,    50,   507,   508,    53,
     509,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   510,   511,    71,     0,    72,
      73,    74,   553,     0,     0,    77,    78,    79,     0,     0,
     513,    81,     0,     0,     0,     0,    83,   514,    85,   515,
     516,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     517,   100,   101,   518,   519,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,   110,     0,     0,
       0,     0,     0,     0,   116,   520,     0,     0,     0,   118,
     119,   120,   121,   521,   123,   124,   522,     0,     0,     0,
       0,     0,     0,     0,   523,   524,   131,     0,     0,     0,
     132,   797,   133,   525,     0,     0,     0,     0,     0,     0,
     139,     0,   140,   141,   142,   143,   526,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,     0,     0,   421,
     155,   156,   157,   158,   159,   160,   161,   162,   527,   554,
     528,   166,   529,   530,   169,   170,   171,   172,   173,   174,
     531,   176,   532,   533,   534,   180,   181,   535,   536,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,     0,     3,     0,   249,   537,
     251,   252,   253,   254,   255,     9,    10,     0,     0,     0,
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
     523,   524,   131,     0,     0,     0,   132,   814,   133,   525,
       0,     0,     0,     0,   815,     0,   139,     0,   140,   141,
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
      85,   515,   516,    88,    89,  1501,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   517,   100,   101,   518,   519,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,  1152,
       0,     0,     0,  1153,     0,     0,   116,   520,     0,     0,
       0,   118,   119,   120,   121,   521,   123,   124,   522,     0,
       0,     0,     0,     0,     0,     0,   523,   524,   131,     0,
       0,     0,   132,     0,   133,   525,     0,     0,     0,     0,
       0,     0,   139,     0,   140,   141,   142,   143,   526,   145,
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
     241,   242,   243,   244,   245,   246,     0,     0,     3,     0,
     249,   537,   251,  1155,  1156,  1157,  1158,     9,    10,     0,
       0,     0,     0,     0,     0,   418,   419,     0,    16,    17,
      18,   497,    20,    21,    22,   498,    24,   499,   500,  1151,
     502,   420,    30,   503,    32,    33,    34,     0,    35,    36,
      37,    38,   504,    40,    41,    42,    43,    44,    45,    46,
     505,     0,    48,   506,    50,   507,   508,    53,   509,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   510,   511,    71,     0,    72,    73,    74,
     512,     0,     0,    77,    78,    79,     0,     0,   513,    81,
       0,     0,     0,     0,    83,   514,    85,   515,   516,    88,
      89,  1642,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   517,   100,
     101,   518,   519,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,  1152,     0,     0,     0,  1153,
       0,     0,   116,   520,     0,     0,     0,   118,   119,   120,
     121,   521,   123,   124,   522,     0,     0,     0,     0,     0,
       0,     0,   523,   524,   131,     0,     0,     0,   132,     0,
     133,   525,     0,     0,     0,     0,     0,     0,   139,     0,
     140,   141,   142,   143,   526,   145,   146,   147,   148,   149,
     150,     0,     0,  1154,   152,     0,     0,   421,   155,   156,
     157,   158,   159,   160,   161,   162,   527,   164,   528,   166,
     529,   530,   169,   170,   171,   172,   173,   174,   531,   176,
     532,   533,   534,   180,   181,   535,   536,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,     0,     3,     0,   249,   537,   251,  1155,
    1156,  1157,  1158,     9,    10,     0,     0,     0,     0,     0,
       0,   418,   419,     0,    16,    17,    18,   497,    20,    21,
      22,   498,    24,   499,   500,  1151,   502,   420,    30,   503,
      32,    33,    34,     0,    35,    36,    37,    38,   504,    40,
      41,    42,    43,    44,    45,    46,   505,     0,    48,   506,
      50,   507,   508,    53,   509,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   510,
     511,    71,     0,    72,    73,    74,   512,     0,     0,    77,
      78,    79,     0,     0,   513,    81,     0,     0,     0,     0,
      83,   514,    85,   515,   516,    88,    89,  1646,     0,     0,
       0,     0,     0,     0,     0,    94,    95,    96,    97,     0,
      98,     0,     0,     0,   517,   100,   101,   518,   519,     0,
       0,     0,     0,     0,     0,   104,   105,   106,     0,   108,
     109,  1152,     0,     0,     0,  1153,     0,     0,   116,   520,
       0,     0,     0,   118,   119,   120,   121,   521,   123,   124,
     522,     0,     0,     0,     0,     0,     0,     0,   523,   524,
     131,     0,     0,     0,   132,     0,   133,   525,     0,     0,
       0,     0,     0,     0,   139,     0,   140,   141,   142,   143,
     526,   145,   146,   147,   148,   149,   150,     0,     0,  1154,
     152,     0,     0,   421,   155,   156,   157,   158,   159,   160,
     161,   162,   527,   164,   528,   166,   529,   530,   169,   170,
     171,   172,   173,   174,   531,   176,   532,   533,   534,   180,
     181,   535,   536,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,     0,   197,   198,   199,
       0,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,     0,     0,
       3,     0,   249,   537,   251,  1155,  1156,  1157,  1158,     9,
      10,     0,     0,     0,     0,     0,     0,   418,   419,     0,
      16,    17,    18,   497,    20,    21,    22,   498,    24,   499,
     500,  1151,   502,   420,    30,   503,    32,    33,    34,     0,
      35,    36,    37,    38,   504,    40,    41,    42,    43,    44,
      45,    46,   505,     0,    48,   506,    50,   507,   508,    53,
     509,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   510,   511,    71,     0,    72,
      73,    74,   512,     0,     0,    77,    78,    79,     0,     0,
     513,    81,     0,     0,     0,     0,    83,   514,    85,   515,
     516,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     517,   100,   101,   518,   519,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,  1152,     0,     0,
       0,  1153,     0,     0,   116,   520,     0,     0,     0,   118,
     119,   120,   121,   521,   123,   124,   522,     0,     0,     0,
       0,     0,     0,     0,   523,   524,   131,     0,     0,     0,
     132,     0,   133,   525,     0,     0,     0,     0,     0,     0,
     139,     0,   140,   141,   142,   143,   526,   145,   146,   147,
     148,   149,   150,     0,     0,  1154,   152,     0,     0,   421,
     155,   156,   157,   158,   159,   160,   161,   162,   527,   164,
     528,   166,   529,   530,   169,   170,   171,   172,   173,   174,
     531,   176,   532,   533,   534,   180,   181,   535,   536,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,     0,     3,     0,   249,   537,
     251,  1155,  1156,  1157,  1158,     9,    10,     0,     0,     0,
       0,     0,     0,   418,   419,     0,    16,    17,    18,   497,
      20,    21,    22,   498,    24,   499,   500,  1151,   502,   420,
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
       0,   108,   109,  1152,     0,     0,     0,  1153,     0,     0,
     116,   520,     0,     0,     0,   118,   119,   120,   121,   521,
     123,   124,   522,     0,     0,     0,     0,     0,     0,     0,
     523,   524,   131,     0,     0,     0,   132,     0,   133,   525,
       0,     0,     0,     0,     0,     0,   139,     0,   140,   141,
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
       0,     0,     3,     0,   249,   537,   251,  1155,  1156,  1157,
    1158,     9,    10,     0,     0,     0,     0,     0,     0,   418,
     419,     0,    16,    17,    18,   545,    20,    21,    22,   498,
     546,   547,   500,   501,   502,   420,    30,   503,    32,   548,
      34,     0,    35,    36,    37,    38,   549,    40,   550,   551,
      43,    44,    45,    46,   505,     0,    48,   552,    50,   507,
     508,    53,   509,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,   510,   511,    71,
       0,    72,    73,    74,   553,     0,     0,    77,    78,    79,
       0,     0,   513,    81,     0,     0,     0,     0,    83,   514,
      85,   515,   516,    88,    89,  1242,     0,     0,     0,     0,
       0,     0,     0,    94,    95,    96,    97,     0,    98,     0,
       0,     0,   517,   100,   101,   518,   519,     0,     0,     0,
       0,     0,     0,   104,   105,   106,     0,   108,   109,   110,
       0,     0,     0,     0,     0,     0,   116,   520,     0,     0,
       0,   118,   119,   120,   121,   521,   123,   124,   522,     0,
       0,     0,     0,     0,     0,     0,   523,   524,   131,     0,
       0,     0,   132,     0,   133,   525,     0,     0,     0,     0,
       0,     0,   139,     0,   140,   141,   142,   143,   526,   145,
     146,   147,   148,   149,   150,     0,     0,   151,   152,     0,
       0,   421,   155,   156,   157,   158,   159,   160,   161,   162,
     527,   554,   528,   166,   529,   530,   169,   170,   171,   172,
     173,   174,   531,   176,   532,   533,   534,   180,   181,   535,
     536,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,     0,     0,     3,     0,
     249,   537,   251,   252,   253,   254,   255,     9,    10,     0,
       0,     0,     0,     0,     0,   418,   419,     0,    16,    17,
      18,   545,    20,    21,    22,   498,   546,   547,   500,   501,
     502,   420,    30,   503,    32,   548,    34,     0,    35,    36,
      37,    38,   549,    40,   550,   551,    43,    44,    45,    46,
     505,     0,    48,   552,    50,   507,   508,    53,   509,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   510,   511,    71,     0,    72,    73,    74,
     553,     0,     0,    77,    78,    79,     0,     0,   513,    81,
       0,     0,     0,     0,    83,   514,    85,   515,   516,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   517,   100,
     101,   518,   519,     0,     0,     0,     0,     0,     0,   104,
     105,   106,     0,   108,   109,   110,     0,     0,     0,     0,
       0,     0,   116,   520,     0,     0,     0,   118,   119,   120,
     121,   521,   123,   124,   522,     0,     0,     0,     0,     0,
       0,     0,   523,   524,   131,     0,     0,     0,   132,     0,
     133,   525,     0,     0,     0,     0,     0,     0,   139,     0,
     140,   141,   142,   143,   526,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,     0,     0,   421,   155,   156,
     157,   158,   159,   160,   161,   162,   527,   554,   528,   166,
     529,   530,   169,   170,   171,   172,   173,   174,   531,   176,
     532,   533,   534,   180,   181,   535,   536,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,     0,     0,     0,     0,   249,   537,   251,   252,
     253,   254,   255,     5,     6,     7,     8,     9,    10,     0,
       0,     0,    13,     0,     0,   418,   419,     0,    16,    17,
      18,   847,    20,    21,    22,    23,     0,   848,   500,    27,
       0,   420,    30,   503,    32,     0,    34,     0,    35,    36,
      37,    38,   849,    40,     0,     0,    43,    44,    45,    46,
     505,     0,    48,   850,    50,     0,     0,    53,   509,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,   510,   511,    71,     0,    72,    73,    74,
     851,     0,     0,    77,    78,    79,     0,     0,   513,    81,
       0,     0,     0,    82,    83,   514,    85,   515,   516,    88,
      89,   567,    91,     0,     0,     0,     0,    93,     0,    94,
      95,    96,    97,     0,    98,     0,     0,     0,   517,   100,
     101,   518,   519,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,     0,   568,   112,     0,   113,
     114,     0,   116,   117,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,   522,     0,   126,     0,     0,     0,
       0,     0,   523,   524,   131,     0,     0,     0,   132,     0,
     133,   525,     0,     0,     0,     0,     0,     0,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,     0,   152,   153,     0,   421,   155,   156,
     157,   158,   159,   160,   161,   162,   527,     0,   528,   166,
     529,   530,   169,   170,   171,   172,   173,   174,   531,   176,
     532,   533,   534,   180,   181,     0,   536,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
       0,   197,   198,   199,     0,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,     0,   248,     9,    10,     0,   251,   252,
       0,     0,     0,   418,   419,     0,    16,    17,    18,     0,
      20,    21,    22,   498,     0,     0,   500,   501,     0,   420,
      30,   503,    32,     0,    34,     0,    35,    36,    37,    38,
       0,    40,     0,     0,    43,    44,    45,    46,   505,     0,
      48,     0,    50,     0,     0,    53,   509,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,   510,   511,    71,     0,    72,    73,    74,     0,     0,
       0,    77,    78,    79,     0,     0,   513,    81,     0,     0,
       0,     0,    83,   514,    85,   515,   516,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    95,    96,
      97,     0,    98,     0,     0,     0,   517,   100,   101,   518,
     519,     0,     0,     0,     0,     0,     0,   104,   105,   106,
       0,   108,   109,     0,     0,     0,     0,     0,     0,     0,
     116,   520,     0,     0,     0,   118,   119,   120,   121,   521,
     123,   124,   522,     0,     0,     0,     0,     0,     0,     0,
     523,   524,   131,     0,     0,     0,   132,     0,   133,   525,
       0,     0,     0,     0,     0,     0,   139,     0,   140,   141,
     142,   143,   526,   145,   146,   147,   148,   149,   150,     0,
       0,     0,   152,     0,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   527,     0,   528,   166,   529,   530,
     169,   170,   171,   172,   173,   174,   531,   176,   532,   533,
     534,   180,   181,     0,   536,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,     0,     0,     0,     0,     0,   251,   252
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,     5,     6,     7,   183,     5,     6,     7,     8,    14,
     316,   429,   430,   694,   834,   345,   918,   678,   263,   790,
     137,   431,  1062,     0,   679,   680,   681,   682,     5,     6,
       7,     8,   803,   112,   113,   264,  1046,   872,  1312,  1295,
       5,     6,     7,     8,   628,   629,   817,   770,  1376,  1377,
     279,   594,  1086,   770,   256,   257,   599,   931,   932,     1,
       1,   471,   472,    76,   295,  1137,   626,   627,  1504,    36,
     953,  1507,  1021,  1003,  1325,    30,    36,  1411,    27,    28,
      56,     5,     6,     7,     8,   286,   931,   932,   727,    39,
     626,   627,   628,   629,    44,    45,    27,    28,    47,     1,
       1,     1,   657,    53,   659,   660,     1,   662,    57,   664,
      60,   111,    62,    63,   143,   969,    47,   672,   673,   225,
    1606,    71,   119,     1,   969,     1,    75,   122,    95,   108,
      97,    80,     1,     1,   111,     1,    94,    97,     1,     1,
       1,     1,    30,     1,    75,   108,   111,   119,    98,  1023,
      37,    38,     1,    40,    41,   101,   111,   119,  1003,     1,
     108,    97,  1036,   112,   113,   114,   108,   108,   247,   248,
     125,    58,    31,   108,     1,   108,   108,     1,  1023,     1,
       1,   148,   113,   217,   123,   107,    97,   111,   148,     1,
       8,  1036,   161,   424,   101,   150,   169,   428,    33,   154,
       1,   146,   157,   114,   975,    45,   128,   114,   314,     0,
       1,   190,   157,   108,    49,   154,   295,    30,   157,  1547,
     254,   157,   177,    63,   186,   183,   114,   114,   225,   202,
      55,   348,    57,     0,     1,  1137,  1138,     1,   233,   187,
     186,   217,   108,    97,   273,   108,   108,   108,   108,   450,
     108,     1,  1292,   188,     1,   187,   256,   257,  1029,   108,
     260,  1517,  1082,    97,  1035,     1,   108,   573,  1278,  1520,
    1756,  1605,   235,   161,   161,   225,   101,     1,   254,   256,
     257,   108,  1316,   260,   108,  1721,   108,   108,   190,   190,
     190,  1325,   187,  1242,     1,   295,   108,   881,   882,  1153,
     233,   273,  1185,  1233,   259,  1028,   273,   108,  1153,  1026,
     307,  1028,   190,   273,   190,  1387,   955,   108,   295,   879,
     880,   190,   190,     1,   187,   187,   187,   187,   738,   187,
     561,  1048,  1768,   220,  1770,   169,   185,    76,   287,     1,
     353,   108,   184,   356,   108,   424,   295,   187,   161,   428,
      95,    90,     1,   108,   303,   214,   287,   175,   108,   914,
     187,   108,   148,   187,   295,   187,   187,   317,   318,   319,
     311,   313,   108,   185,   261,   114,   148,  1705,   788,    95,
     459,   626,   627,    95,   108,   137,   187,   126,  1233,   128,
     469,   101,   225,   184,   623,   624,  1270,   230,   159,   151,
     479,   108,   256,   257,   633,   131,    77,   486,   487,   101,
      27,    28,   101,   615,   645,   176,   495,   184,   252,   253,
     184,   255,   114,    97,   424,  1270,   251,   225,   428,   227,
     108,  1759,   108,   188,   184,   108,  1672,   184,   272,   264,
     630,   266,   157,   155,   634,   157,   108,   424,   184,  1294,
     284,   428,   277,   278,   279,   455,   281,   457,   283,   108,
     184,  1232,   155,    42,   157,    52,   225,    46,   227,  1743,
     108,   197,    51,   218,   219,     5,   186,   184,   455,     9,
     457,   314,   561,   154,   484,  1387,  1520,   273,   233,   489,
     455,    70,   457,   108,  1396,   169,   113,   186,   577,   578,
     918,   273,   218,   219,   108,  1407,   184,   484,   269,   588,
    1746,   187,   489,   154,   187,   276,   314,   233,   108,   484,
       9,  1244,   184,  1358,   489,   286,   108,  1362,   607,   608,
     948,   455,  1788,   457,   108,   184,  1253,  1121,  1122,  1123,
      29,     1,     5,   130,   237,  1419,     9,  1228,   137,   187,
     221,   222,    95,   108,     1,   314,     3,   154,    95,   159,
     484,   561,   108,  1106,   131,   489,   976,   977,   568,   210,
     119,   981,   187,    33,  1419,   119,   176,   118,   252,   253,
     184,   255,   699,   700,   561,  1121,  1122,  1123,   262,   168,
     132,   568,   171,    45,   124,    47,   126,   187,   272,   119,
     143,  1011,   123,   568,   134,   187,   147,   186,   608,  1380,
     284,   148,   201,   187,   353,   615,   621,   356,  1628,   160,
      67,   154,   701,    97,   154,    72,   626,   627,   628,   629,
     197,   608,   187,   212,   879,   124,    30,   126,   615,   870,
     114,   187,   186,   608,   568,   645,   135,   157,   190,   626,
     627,   628,   629,   194,    97,   107,   885,   145,    30,  1504,
     889,   124,  1507,   126,   263,   154,   897,   187,   645,    97,
      95,   134,   119,  1575,    97,   274,    45,   210,    47,    27,
      28,   101,   155,   157,   157,   166,   114,    95,   176,    37,
      38,   154,    40,    41,   114,   695,   435,   436,  1518,    47,
     439,   182,  1742,  1523,   443,   148,   194,   446,   447,    57,
      58,    80,     9,    10,   123,   454,   168,   111,   695,  1137,
    1138,   460,   461,   148,    42,   148,   465,    75,    46,   157,
     695,   125,    80,    51,   473,   143,    95,  1398,   107,   111,
      95,   480,   481,   482,   483,  1468,   825,   826,   827,   488,
     829,   186,    70,   125,     9,    10,   150,   496,  1733,  1734,
     154,   157,     1,   157,   112,   113,   114,  1641,   186,   186,
     149,   695,  1453,   186,   186,   210,   780,    54,   150,   138,
     780,  1365,    59,   177,   143,     9,   165,  1017,   143,  1019,
      54,   870,   210,   210,    33,    59,  1641,   210,   210,   168,
    1775,    78,   541,   780,   182,    29,  1781,   104,   159,  1139,
      49,   811,   812,   161,  1688,   780,  1690,   556,   196,    95,
      97,   247,   248,   157,   149,   176,   966,   124,   567,   126,
     186,   107,  1652,    97,   811,   812,  1656,   182,   978,  1069,
     165,  1071,   119,  1688,   270,  1690,   811,   812,   199,   104,
     168,   196,   154,   171,   210,   594,   780,   154,     9,    10,
     599,   158,   157,  1273,   603,   138,   157,   159,   186,   124,
     870,   126,   220,     9,    10,   177,  1721,   174,   269,  1753,
    1111,   154,    25,  1112,   176,   276,   891,   811,   812,  1118,
     157,    34,   154,   870,   212,   286,   101,   897,   195,   154,
     124,    96,   126,   158,  1559,  1566,  1567,   199,  1753,   114,
     138,   135,   107,   261,   157,   177,   213,  1737,    61,   174,
     897,   263,   117,  1768,   157,  1770,   154,  1608,   268,   101,
     154,   101,   274,   128,  1705,   275,  1115,    42,   157,   287,
     195,    46,   114,   201,   114,   299,    51,   295,   232,   123,
     234,   138,   210,   104,   308,   303,   143,   119,   213,   138,
     702,   119,  1372,   705,   143,    70,   708,    54,   104,  1387,
     123,  1381,    59,   124,   154,   126,   123,   157,  1396,   277,
     278,   279,   123,   154,   352,   283,   157,   355,   124,  1407,
     126,   154,   731,   154,   157,   734,   157,   123,   221,   222,
     223,   123,   232,   154,   234,   191,   192,   158,   154,   748,
     129,   130,   154,   752,   753,  1676,  1677,   123,   154,   129,
     130,   123,   158,   174,   676,   677,   683,   684,   123,  1710,
     685,   686,  1226,  1227,   154,   774,   157,   776,   174,  1596,
    1597,  1272,   119,   216,   195,   784,   242,   241,   787,   241,
     157,  1357,   791,   154,   314,     0,   190,  1136,   167,   195,
      93,   249,   213,   168,  1064,   100,   171,    50,   200,   103,
     102,   155,   157,   184,    30,  1485,  1757,   213,   193,    47,
     184,   186,   153,   119,   184,   184,   246,  1064,  1749,   304,
     187,   284,   119,   284,   833,   133,   154,     1,   119,  1064,
     143,   108,   154,   141,   142,   187,   144,   212,   187,   154,
     157,  1111,   184,   157,   152,  1120,   157,   157,   156,   143,
     158,  1121,  1122,  1123,   122,   163,   157,   157,   157,   157,
      35,   154,    17,   872,  1111,    30,   214,   231,   230,   190,
    1064,   179,   190,     3,  1121,  1122,  1123,   245,  1829,   119,
    1831,   168,   170,    71,   170,   231,    95,  1575,    95,    95,
    1841,   187,   901,   150,   108,   203,   204,   205,   206,   207,
     208,    30,   161,   108,   128,  1354,   161,    90,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    95,   246,
     133,   299,   931,   932,   933,   934,   143,   119,   184,   133,
     184,   114,   108,    95,    97,   187,   187,    45,    97,   187,
     187,   187,   187,   126,   154,   128,   154,   184,   184,    95,
     225,   154,   154,   154,   154,   237,   143,   231,   190,    33,
     969,   233,  1236,   133,   143,    30,  1236,    95,    95,   227,
     286,   170,   154,   299,   983,   128,   119,   148,   254,   119,
      95,   133,   198,   161,   133,    97,   184,   154,   119,  1236,
     148,   101,   101,   184,   184,   143,  1497,   154,   122,  1008,
      35,  1236,  1272,   154,   190,    30,   119,    80,  1017,  1283,
    1019,   245,  1021,  1283,  1023,   108,   107,   258,   108,   285,
     157,   260,   157,   267,   157,  1272,   145,  1036,  1302,    30,
      30,   157,  1302,    30,   157,   157,  1283,   157,   287,  1540,
     190,   306,  1236,   286,   145,   187,   227,   128,  1283,   187,
     148,   187,  1322,   187,   148,  1302,   148,   119,   119,  1329,
    1069,    78,  1071,   108,   143,   101,   184,  1302,     7,   133,
     187,   187,   233,   198,    97,  1322,   190,   233,   107,   233,
     186,   157,  1329,   154,   187,   157,   233,  1322,   157,  1283,
     250,  1361,   237,   148,  1329,    79,    30,  1106,   282,   187,
     187,   286,   187,   187,   187,   187,   250,   187,  1302,    30,
     108,   170,   127,   127,  1361,   148,   184,   148,   257,    97,
     186,   184,  1131,   316,   184,  1626,  1361,   143,  1322,   186,
     271,   184,   186,   184,   184,  1329,  1637,  1638,    95,  1640,
     187,   154,    30,    97,  1153,   187,   170,  1648,   280,   148,
      54,    95,    95,   197,    30,   108,   108,   119,   265,   119,
      95,   198,    95,   197,   186,   197,   287,   225,   119,   225,
      94,   197,   183,   119,   186,  1188,   186,   119,   199,   225,
     737,   119,   260,   260,   970,  1233,   450,  1037,  1537,  1538,
    1539,   293,   287,   263,   305,   430,  1710,  1757,   873,  1034,
     305,   305,   465,   793,  1262,  1478,   306,   306,  1383,   306,
    1127,  1379,  1376,   556,  1284,  1289,  1292,  1297,   655,   934,
     656,   675,  1781,   711,  1775,   834,  1316,  1497,   458,  1730,
     458,  1019,  1187,  1242,  1348,  1396,  1359,  1246,  1358,  1575,
    1407,  1138,  1572,  1147,  1400,  1002,  1210,  1443,  1599,   345,
    1497,   340,  1261,   436,  1397,    -1,   439,   597,    -1,    -1,
     443,  1270,    -1,   446,   447,    -1,    -1,    -1,  1769,    -1,
    1540,   454,    -1,    -1,    -1,  1284,    -1,   460,   461,    -1,
      -1,    -1,   465,    -1,    -1,  1294,  1787,    -1,    -1,    -1,
     473,    -1,    -1,  1540,    -1,    -1,    -1,   480,   481,   482,
     483,  1802,    -1,    -1,    -1,   488,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   496,  1323,    -1,    -1,    -1,    -1,    -1,
    1669,    -1,  1823,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1832,    -1,    -1,    -1,    -1,    -1,  1686,    -1,  1348,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1358,
      -1,    -1,    -1,  1362,    -1,    -1,  1626,    -1,   541,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1637,  1638,    -1,
    1640,    -1,    -1,   556,    -1,    -1,    -1,    -1,  1648,  1626,
      -1,    -1,    -1,    -1,   567,    -1,    -1,    -1,    -1,    -1,
    1637,  1638,    -1,  1640,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1648,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1419,    -1,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
     603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1730,    -1,    -1,    -1,    -1,    -1,  1475,  1476,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1730,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1501,    -1,    -1,  1504,    -1,    -1,  1507,  1769,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1519,    -1,    -1,    -1,    -1,  1524,    -1,  1787,    -1,    -1,
      -1,    -1,  1769,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1802,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1787,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   734,    -1,  1823,    -1,  1802,    -1,    -1,    -1,    -1,
      -1,    -1,  1832,    -1,    -1,   748,    -1,    -1,    -1,   752,
     753,    -1,    -1,    -1,    -1,    -1,  1823,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1832,    -1,    -1,    -1,    -1,
      -1,   774,    -1,   776,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   784,    -1,    -1,   787,    -1,    -1,    -1,   791,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1641,  1642,    -1,  1644,    -1,  1646,    -1,    -1,
      -1,    -1,    -1,    -1,  1653,    -1,    -1,    -1,    -1,    -1,
     833,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1688,
      -1,  1690,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1706,    -1,    -1,
    1709,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1721,    -1,    -1,    -1,    -1,    -1,   901,    -1,
      -1,    -1,    -1,  1732,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1753,    -1,    -1,    -1,   931,   932,
     933,   934,  1761,    -1,    -1,    -1,    -1,  1766,    -1,  1768,
      -1,  1770,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   969,    -1,    -1,    -1,
    1799,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     983,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1819,    -1,    -1,    -1,    -1,  1824,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1008,    -1,  1836,    -1,    -1,
    1839,    -1,    -1,    -1,  1017,    -1,  1019,    -1,  1021,    -1,
    1023,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1036,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   568,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1069,    -1,  1071,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   592,   593,    -1,
     595,   596,   597,   598,    -1,   600,    -1,    -1,    -1,    -1,
      -1,   606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   614,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   636,   637,    -1,    -1,    -1,    -1,    -1,  1131,    -1,
     645,   646,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   707,    -1,    -1,    -1,   711,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   750,    -1,    -1,    -1,  1242,
      -1,    -1,    -1,  1246,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1261,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   792,    -1,    -1,
      -1,  1284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   818,    -1,    -1,    -1,   822,   823,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   831,    -1,    -1,    -1,
    1323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1348,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   897,    -1,    -1,    -1,    -1,    -1,   903,   904,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1419,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1449,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   971,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1475,  1476,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1006,    -1,    -1,    -1,    -1,    -1,    -1,  1501,    -1,
      -1,  1504,    -1,    -1,  1507,    -1,    -1,    -1,    -1,    -1,
    1025,    -1,    -1,    -1,    -1,    -1,  1519,    -1,    -1,    -1,
      -1,  1524,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1047,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1058,  1059,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1073,    -1,
      -1,  1076,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1093,  1094,
    1095,    -1,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,
    1105,    -1,    -1,  1108,  1109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1641,  1642,
      -1,  1644,    -1,  1646,    -1,    -1,    -1,    -1,    -1,    -1,
    1653,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1688,    -1,  1690,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1706,    -1,    -1,  1709,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1721,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1732,
      -1,    -1,    -1,  1248,    -1,  1250,    -1,  1252,    -1,    -1,
    1255,    -1,    -1,    -1,    -1,  1260,    -1,    -1,    -1,    -1,
    1753,    -1,    -1,    -1,    -1,    -1,    -1,  1272,  1761,    -1,
      -1,    -1,    -1,  1766,    -1,  1768,  1281,  1770,    -1,    -1,
      -1,    -1,  1287,  1288,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1306,    -1,    -1,  1309,    -1,  1799,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1819,    -1,    -1,    -1,
      -1,  1824,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1836,    -1,    -1,  1839,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1379,    -1,    -1,    -1,  1383,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1462,    -1,    -1,
      -1,  1466,    -1,    -1,    -1,  1470,    -1,  1472,    -1,  1474,
      -1,    -1,    -1,    -1,    -1,  1480,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1488,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1496,  1497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1516,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1528,  1529,  1530,  1531,    -1,  1533,  1534,
      -1,  1536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1551,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1614,
      -1,  1616,    -1,    -1,  1619,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1627,    -1,    -1,    -1,    -1,  1632,  1633,    -1,
      -1,    -1,    -1,    -1,    -1,  1640,    -1,    -1,    -1,    -1,
    1645,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1662,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1673,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1713,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1726,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1769,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1797,    -1,    -1,    -1,    -1,  1802,    -1,    -1,
      -1,    -1,  1807,     0,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    12,    -1,  1822,    -1,    16,
      -1,  1826,    -1,    20,    21,    22,    23,    24,    25,    26,
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
     186,    -1,   188,   189,   190,   191,   192,    -1,   194,    -1,
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
     186,    -1,   188,   189,   190,   191,   192,    -1,   194,    -1,
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
      -1,    -1,    -1,   186,    -1,   188,   189,   190,   191,   192,
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
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,   190,
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
     308,   309,   310,    -1,   312,    25,    26,    -1,   316,   317,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    -1,
      40,    41,    42,    43,    -1,    -1,    46,    47,    -1,    49,
      50,    51,    52,    -1,    54,    -1,    56,    57,    58,    59,
      -1,    61,    -1,    -1,    64,    65,    66,    67,    68,    -1,
      70,    -1,    72,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    -1,    -1,
      -1,   101,   102,   103,    -1,    -1,   106,   107,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,   129,
     130,    -1,   132,    -1,    -1,    -1,   136,   137,   138,   139,
     140,    -1,    -1,    -1,    -1,    -1,    -1,   147,   148,   149,
      -1,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
      -1,    -1,   212,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,    -1,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,    -1,    -1,    -1,    -1,    -1,   316,   317
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
     103,   159,   176,   487,   193,   154,   396,   494,   497,   191,
     192,   155,   509,   510,   505,   509,   505,   157,   509,   157,
     146,   157,   184,   184,   184,   184,   375,   512,   375,    30,
     654,   182,   196,   182,   196,   166,   182,   656,   655,   169,
     202,    47,   655,   153,   119,    45,    47,    80,   107,   168,
     655,   221,   222,   223,   246,   616,   655,   655,   304,   138,
     143,   113,   287,   295,   377,   655,   392,   187,   392,    45,
      63,   187,   568,   569,   413,   187,   194,   655,   427,   428,
     655,   284,   284,   427,   119,   434,   119,   187,   381,   382,
     154,   397,   413,     1,   161,   654,   114,   161,   355,   654,
     655,   119,   143,   108,   187,   413,    30,   187,   655,   655,
     655,   451,   452,   655,   392,   187,   413,   413,   570,   655,
     392,   154,   154,   413,   187,   194,   655,   655,   143,   451,
     184,   184,   122,   108,   184,   157,   157,   157,   655,   154,
     185,   186,   187,    35,   528,   529,   530,   413,   413,     8,
     175,    17,   413,   214,    30,   414,   414,    39,    45,    60,
      71,    98,   508,   656,   414,   414,   414,   647,   414,   508,
     414,   231,   230,   583,   584,   655,   190,   190,   414,   413,
     393,   413,   245,   410,   411,   311,   313,   414,   337,   190,
     336,   190,   336,     3,   343,   359,   389,     1,   343,   359,
     389,    33,   360,   389,   360,   389,   400,   336,   400,   414,
     414,   119,   168,   170,   170,   394,   414,   414,   469,   470,
     472,   472,   472,   472,   471,   472,   472,   472,    71,   473,
     477,   477,   476,   478,   478,   478,   478,   479,   479,   480,
     480,   231,    95,    95,    95,   495,   497,   497,   413,   510,
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
     484,   557,   655,   484,   185,   108,   187,   187,   512,   149,
     165,   149,   165,   138,   397,   380,   363,   133,   554,   370,
     414,   551,   654,   654,   129,   130,   654,   277,   278,   279,
     283,   655,   263,   274,   263,   274,    30,   286,    97,   114,
     157,   623,   626,   617,    39,    44,    53,    60,    62,    71,
      98,   225,   317,   318,   319,   384,   558,   653,   227,   299,
     308,   414,   655,    95,   299,   654,   154,   570,   571,   655,
     570,   571,   119,   428,   128,   552,   119,   414,   148,   430,
     148,    36,   148,   429,   430,   148,   551,   254,    54,    59,
      78,   119,   429,   435,   436,   437,   420,   551,   552,   382,
      95,   184,   198,   133,   354,   654,   161,   133,    97,   354,
     414,   143,   430,   154,   119,   414,   414,   148,   101,   454,
     455,   456,   458,   459,   101,   462,   463,   464,   465,   392,
     184,   184,   154,   570,   570,   414,   143,   190,   414,   122,
     187,   187,   187,    35,   530,   131,   197,     9,    10,   104,
     124,   126,   154,   195,   525,   527,   538,   539,   542,   154,
      30,   232,   234,   414,   414,   414,   232,   234,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   508,   119,   414,
     414,    48,    73,    74,   244,   394,   415,   425,   245,   586,
     587,   154,   210,   395,   414,   190,   114,   389,   389,   389,
     444,    96,   107,   117,   128,   446,   447,   448,   449,   108,
     655,   107,   442,   108,   413,   590,   597,   154,   285,   474,
     642,    97,   169,   252,   253,   255,   262,   272,   284,   591,
     592,   611,   612,   613,   614,   637,   640,   258,   260,   598,
     616,   267,   602,   638,   247,   248,   270,   607,   608,   157,
     157,   554,   157,   157,   157,   157,   157,   145,   176,   194,
     553,   145,   145,   414,   138,   397,   572,   369,   286,    30,
      97,   114,   157,   630,    30,   623,   553,   553,   495,   287,
     306,   551,   384,   227,   190,   391,   187,   187,   145,   187,
     187,   428,   148,   429,   655,   414,   148,   414,   128,   414,
     148,   430,   148,   414,   148,   119,   119,   414,   655,   437,
      78,   552,   394,   414,   654,   108,   354,   414,   143,   391,
     452,   414,   414,   114,   455,   456,   101,   186,   114,   456,
     459,   119,   466,   552,   101,   114,   463,   101,   114,   465,
     184,   391,   187,   187,   414,   414,   198,   462,   133,   195,
     527,     7,   392,   655,   195,   538,   392,   190,   233,   233,
     233,   233,    97,   237,   237,   584,   186,   157,   157,   157,
     186,   589,   587,   506,   654,   129,   130,   448,   449,   449,
     445,   143,   551,   654,   441,   184,   187,   590,   604,   250,
     217,   254,   268,   275,   641,    97,   256,   257,   639,   250,
     594,   641,   476,   611,   595,   148,   282,   599,   600,   639,
     286,   610,    79,   609,   187,   194,   552,   555,   187,   187,
     187,   187,   187,   187,   187,    30,   137,   201,   632,   633,
     634,    30,   631,   632,   271,   627,   108,   624,   170,   655,
     257,   495,   184,   414,   148,   414,   148,   429,   414,   148,
     414,   414,   655,   655,   436,   414,   127,   127,    97,   654,
     414,   184,   186,   186,   414,   394,   414,   186,   186,   655,
     186,   210,   119,   466,   119,   186,   119,   466,   186,   184,
     114,   530,   655,   195,   184,   530,   655,   184,   414,   414,
     414,   414,   316,   414,   414,   414,   413,   413,   413,   154,
     588,   449,   414,   143,   184,   478,    52,   130,   476,   476,
     269,   276,   286,   615,   615,   596,   154,   280,    95,   187,
     108,   187,   630,   630,   634,   108,   187,    30,   628,   639,
     625,   626,   187,   386,   387,   495,   119,   225,   307,   287,
     170,   414,   414,   148,   414,    54,   394,   414,   354,   414,
     394,    95,   394,   414,   552,   655,   186,   655,   414,   655,
     186,   394,   119,    94,   183,   531,   530,   655,   197,   530,
     414,   187,   187,   187,   413,   442,   414,   476,   476,   199,
     413,   552,   552,    95,    30,   265,   108,   108,   449,   551,
     655,   119,   225,   655,   386,   414,   119,   466,    95,   186,
      95,   655,     5,   134,   534,   535,   537,   539,    29,   135,
     532,   533,   536,   539,   197,   530,   197,   198,   462,   184,
     442,   476,   184,   552,   626,   387,   449,   305,   655,   119,
     225,   655,   186,   466,   394,   414,   466,   186,    94,   134,
     537,   183,   135,   536,   197,   114,   414,   305,   655,   119,
     394,   414,   186,   186,   119,   293,   305,   655,   655,   306,
     414,   306,   186,   495,   495,   199,   287,   655,   225,   119,
     655,   306,   495
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
       4,     5,     5,     6,     2,     1,     2,     3,     2,     2,
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
     184,    -1,   493,   396,    -1,   494,    -1,   493,   494,    -1,
     177,   655,    17,    -1,   177,    18,    -1,   177,    19,    -1,
     496,    -1,   496,   497,    -1,   192,   497,    -1,   497,    -1,
     191,    -1,   498,    -1,   498,   191,   497,    -1,   498,   192,
     497,    -1,   499,    -1,   508,    -1,   500,    -1,   500,   509,
      -1,   503,    -1,   503,   509,    -1,   501,   505,    -1,   502,
      -1,   106,   123,    -1,   115,   123,    -1,    98,   123,    -1,
     189,   123,    -1,   116,   123,    -1,   140,   123,    -1,   139,
     123,    -1,   505,    -1,    99,   505,    -1,   504,   505,    -1,
     121,    -1,   172,   123,    -1,    91,   123,    -1,   181,   123,
      -1,   180,   123,    -1,    92,   123,    -1,   558,    -1,   506,
      -1,   655,    -1,   507,    -1,   194,    -1,    11,    -1,    12,
      -1,    20,    -1,   511,    -1,   508,   509,    -1,   508,   157,
     187,    -1,   508,   157,   520,   187,    -1,   510,    -1,   509,
     510,    -1,   155,   413,   185,    -1,   512,    -1,   514,    -1,
     515,    -1,   516,    -1,   519,    -1,   524,    -1,   517,    -1,
     518,    -1,   521,    -1,   396,    -1,   646,    -1,   643,    -1,
     644,    -1,   645,    -1,   513,    -1,   572,    -1,   111,    -1,
     150,    -1,   125,    -1,   119,   655,    -1,   157,   187,    -1,
     157,   413,   187,    -1,   120,    -1,   169,   154,   413,   184,
      -1,   202,   154,   413,   184,    -1,   656,   157,   187,    -1,
     656,   157,   520,   187,    -1,   145,    -1,   520,   108,   145,
      -1,   414,    -1,   520,   108,   414,    -1,   522,    -1,   523,
      -1,   656,   146,   150,    -1,    47,   380,   397,    -1,   525,
      -1,   543,    -1,   526,    -1,   540,    -1,   541,    -1,   158,
     655,   530,   131,    -1,   158,   655,   530,   197,   195,   655,
     530,   197,    -1,   158,   655,   528,   530,   131,    -1,   158,
     655,   528,   530,   197,   195,   655,   530,   197,    -1,   158,
     655,   530,   197,   527,   195,   655,   530,   197,    -1,   158,
     655,   528,   530,   197,   527,   195,   655,   530,   197,    -1,
     538,    -1,   527,   538,    -1,   529,    -1,   528,   529,    -1,
      35,   655,   530,   133,   530,   531,    -1,    -1,    35,    -1,
     183,   532,   183,    -1,    94,   534,    94,    -1,    -1,   533,
      -1,   135,    -1,   536,    -1,   533,   135,    -1,   533,   536,
      -1,    -1,   535,    -1,   134,    -1,   537,    -1,   535,   134,
      -1,   535,   537,    -1,    29,    -1,   539,    -1,     5,    -1,
     539,    -1,   525,    -1,    10,    -1,   542,    -1,   539,    -1,
       9,    -1,   124,    -1,   126,    -1,   154,   392,   184,    -1,
     213,    31,   214,    -1,   213,   214,    -1,   174,   655,   175,
      -1,   174,   655,     8,    -1,   104,     7,    -1,   544,    -1,
     545,    -1,   546,    -1,   547,    -1,   548,    -1,   549,    -1,
     550,    -1,    43,   154,   392,   184,    -1,    21,   391,   184,
      -1,    45,   154,   413,   184,   154,   391,   184,    -1,    22,
     391,   184,    -1,    98,   154,   413,   184,   154,   391,   184,
      -1,    71,   154,   392,   184,    -1,    39,   154,   392,   184,
      -1,    23,   391,   184,    -1,    60,   154,   413,   184,   154,
     391,   184,    -1,    24,   392,   184,    -1,   161,   154,   413,
     184,   154,   392,   184,    -1,    95,   552,    -1,   554,    -1,
     554,   553,    -1,   211,   157,   187,    -1,   145,    -1,   194,
      -1,   176,    -1,   556,    -1,   558,    -1,   153,   157,   187,
      -1,   320,   157,   187,    -1,   573,    -1,   576,    -1,   653,
      -1,   552,    -1,   555,   108,   552,    -1,   655,    -1,   655,
      -1,   561,    -1,   568,    -1,   566,    -1,   569,    -1,   567,
      -1,   565,    -1,   564,    -1,   563,    -1,   562,    -1,   559,
      -1,   560,   157,   187,    -1,   225,    -1,    44,   157,   187,
      -1,    44,   157,   568,   187,    -1,    44,   157,   569,   187,
      -1,    53,   157,   187,    -1,    71,   157,   187,    -1,    39,
     157,   187,    -1,    60,   157,   187,    -1,    60,   157,   655,
     187,    -1,    60,   157,    30,   187,    -1,    98,   157,   187,
      -1,    98,   157,   655,   187,    -1,    98,   157,   655,   108,
     570,   187,    -1,    98,   157,   194,   187,    -1,    98,   157,
     194,   108,   570,   187,    -1,    62,   157,   655,   187,    -1,
      45,   157,   187,    -1,    45,   157,   655,   187,    -1,    45,
     157,   655,   108,   570,   187,    -1,    45,   157,   655,   108,
     571,   187,    -1,    45,   157,   194,   187,    -1,    45,   157,
     194,   108,   570,   187,    -1,    45,   157,   194,   108,   571,
     187,    -1,    63,   157,   655,   187,    -1,   655,    -1,   655,
     145,    -1,    30,    -1,   574,    -1,   575,    -1,    47,   157,
     194,   187,    -1,    47,   157,   187,    95,   552,    -1,    47,
     157,   555,   187,    95,   552,    -1,   157,   554,   187,    -1,
      33,   220,   221,    -1,    33,   220,   222,    -1,    33,   220,
     223,    -1,   226,   225,   414,   233,   414,    -1,   226,   225,
     414,    95,   232,   233,   414,    -1,   226,   225,   414,    95,
     234,   233,   414,    -1,   226,   225,   414,   218,   414,    -1,
     226,   225,   414,   219,   414,    -1,   226,   227,   414,   233,
     414,    -1,   226,   227,   414,    95,   232,   233,   414,    -1,
     226,   227,   414,    95,   234,   233,   414,    -1,   226,   227,
     414,   218,   414,    -1,   226,   227,   414,   219,   414,    -1,
     224,   225,   414,    -1,   224,   227,   414,    -1,   229,   225,
     414,   237,   414,    -1,   229,   230,   231,   225,   414,   237,
     414,    -1,   228,   225,   414,    95,   414,    -1,   236,   119,
     583,   235,   414,   186,   414,    -1,   584,    -1,   583,   108,
     119,   584,    -1,   655,   143,   414,    -1,   244,   154,   413,
     184,   586,    -1,   587,    -1,   586,   587,    -1,   245,   589,
     588,    -1,   154,   413,   184,    -1,   506,    -1,   589,   210,
     506,    -1,   593,   591,    -1,    -1,   592,    -1,   611,    -1,
     592,   611,    -1,   594,    -1,   593,   262,   594,    -1,   595,
      -1,   594,   258,   595,    -1,   596,    -1,   595,   260,   148,
     596,    -1,   597,    -1,   259,   597,    -1,   601,   598,   599,
      -1,    -1,   616,    -1,    -1,   600,    -1,   282,   154,   413,
     184,    -1,   605,   602,    -1,   157,   590,   187,    -1,   603,
      -1,    -1,   638,    -1,   493,   154,   604,   184,    -1,    -1,
     590,    -1,   606,   607,    -1,   512,    -1,   154,   413,   184,
      -1,    -1,   608,    -1,   248,   609,    -1,   247,   610,    -1,
     270,    -1,    -1,    79,    -1,    -1,   286,    -1,   612,    -1,
     613,    -1,   614,    -1,   640,    -1,   637,    -1,   169,    -1,
     284,   476,   615,    -1,   253,   639,   615,    -1,   286,    -1,
     276,    -1,   269,    -1,   246,   617,    -1,   616,   246,   617,
      -1,   618,    -1,   619,    -1,   620,    -1,   635,    -1,   621,
      -1,   629,    -1,   622,    -1,   636,    -1,   101,   274,    -1,
     101,   263,    -1,   266,    -1,   281,    -1,   251,   274,    -1,
     251,   263,    -1,    57,   655,    30,    -1,   277,    -1,    55,
     277,    -1,   279,   623,    -1,   279,   157,   623,   624,   187,
      -1,    55,   279,    -1,   626,    -1,   114,    -1,    -1,   108,
     625,    -1,   626,    -1,   625,   108,   626,    -1,    97,    30,
     627,   628,    -1,    -1,   271,    30,    -1,    -1,   639,   265,
      -1,   278,   286,   630,   632,    -1,   278,   286,   114,   632,
      -1,    55,   278,   286,    -1,    97,    30,    -1,   157,   631,
     187,    -1,    30,    -1,   631,   108,    30,    -1,    -1,   633,
      -1,   634,    -1,   633,   634,    -1,   201,   630,    -1,   137,
     630,    -1,   264,    30,    -1,   283,    -1,    55,   283,    -1,
      97,   217,    -1,    97,   254,    -1,   255,   250,    -1,   267,
     639,   280,    -1,   256,   476,    -1,    97,   130,   476,    -1,
      97,    52,   476,    -1,   257,   476,   199,   476,    -1,   272,
     641,    -1,   252,   641,    -1,   275,    -1,   268,    -1,   285,
     250,   478,    -1,   155,   185,    -1,   155,   413,   185,    -1,
     310,   311,    -1,   310,   413,   311,    -1,   312,   313,    -1,
     312,   413,   313,    -1,   154,   647,   184,    -1,   414,   122,
     414,    -1,   647,   108,   414,   122,   414,    -1,   226,   314,
     414,   233,   414,    -1,   226,   314,   647,   233,   414,    -1,
     226,   314,   414,   233,   414,    97,   316,   414,    -1,   315,
     314,   414,   233,   414,    -1,   224,   314,   508,    -1,   228,
     314,   508,    95,   414,    -1,   229,   314,   230,   231,   508,
     237,   414,    -1,   319,   157,   187,    -1,   318,   157,   187,
      -1,   317,   157,   187,    -1,    30,    -1,   656,    -1,    16,
      -1,    98,    -1,    39,    -1,    44,    -1,    53,    -1,    45,
      -1,   153,    -1,    48,    -1,   225,    -1,    60,    -1,    62,
      -1,    63,    -1,    71,    -1,    74,    -1,    73,    -1,   211,
      -1,   243,    -1,   314,    -1,   315,    -1,   319,    -1,   318,
      -1,   320,    -1,   657,    -1,    25,    -1,   215,    -1,   128,
      -1,    38,    -1,   261,    -1,    37,    -1,   222,    -1,   221,
      -1,   147,    -1,    43,    -1,   259,    -1,   260,    -1,   274,
      -1,   263,    -1,   251,    -1,   285,    -1,   277,    -1,   279,
      -1,   278,    -1,   283,    -1,   255,    -1,   250,    -1,    79,
      -1,   217,    -1,   254,    -1,    52,    -1,   223,    -1,   236,
      -1,   302,    -1,   230,    -1,   203,    -1,   208,    -1,   207,
      -1,   206,    -1,   205,    -1,   204,    -1,    97,    -1,   112,
      -1,   113,    -1,   186,    -1,    46,    -1,   257,    -1,    36,
      -1,    67,    -1,    72,    -1,    59,    -1,    54,    -1,    56,
      -1,    78,    -1,    42,    -1,   148,    -1,    51,    -1,   212,
      -1,   170,    -1,   171,    -1,   168,    -1,    70,    -1,    96,
      -1,   117,    -1,   129,    -1,   130,    -1,   107,    -1,    68,
      -1,   136,    -1,   188,    -1,   101,    -1,    95,    -1,   198,
      -1,   127,    -1,   167,    -1,    93,    -1,    50,    -1,   231,
      -1,   102,    -1,   199,    -1,   118,    -1,   160,    -1,   201,
      -1,   151,    -1,   137,    -1,    76,    -1,    77,    -1,   103,
      -1,   200,    -1,   152,    -1,   182,    -1,   196,    -1,   161,
      -1,   138,    -1,   132,    -1,   166,    -1,   149,    -1,   165,
      -1,    33,    -1,    40,    -1,    58,    -1,   114,    -1,    41,
      -1,    57,    -1,   216,    -1,    49,    -1,    61,    -1,    34,
      -1,    47,    -1,   273,    -1,   249,    -1,   282,    -1,   284,
      -1,   253,    -1,   267,    -1,   280,    -1,   272,    -1,   252,
      -1,   266,    -1,   281,    -1,   271,    -1,   265,    -1,   264,
      -1,   248,    -1,   247,    -1,   256,    -1,   286,    -1,   276,
      -1,   275,    -1,   270,    -1,   268,    -1,   269,    -1,   235,
      -1,   232,    -1,   229,    -1,   226,    -1,   228,    -1,   224,
      -1,   219,    -1,   218,    -1,   220,    -1,   237,    -1,   227,
      -1,   234,    -1,   233,    -1,    66,    -1,    64,    -1,    75,
      -1,   169,    -1,   202,    -1,   242,    -1,   240,    -1,   241,
      -1,   238,    -1,   239,    -1,   244,    -1,   245,    -1,   246,
      -1,    65,    -1,   295,    -1,   293,    -1,   294,    -1,   299,
      -1,   300,    -1,   301,    -1,   296,    -1,   297,    -1,   298,
      -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,    84,
      -1,    85,    -1,    86,    -1,    87,    -1,    88,    -1,    89,
      -1,    90,    -1,   287,    -1,   288,    -1,   289,    -1,   290,
      -1,   291,    -1,   292,    -1,   303,    -1,   304,    -1,   305,
      -1,   306,    -1,   307,    -1,   308,    -1,   309,    -1,    91,
      -1,   106,    -1,   115,    -1,   172,    -1,   180,    -1,   189,
      -1,   139,    -1,    92,    -1,   116,    -1,   140,    -1,   181,
      -1,   316,    -1,   317,    -1,    26,    -1
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
    1548,  1553,  1559,  1565,  1572,  1575,  1577,  1580,  1584,  1587,
    1590,  1592,  1595,  1598,  1600,  1602,  1604,  1608,  1612,  1614,
    1616,  1618,  1621,  1623,  1626,  1629,  1631,  1634,  1637,  1640,
    1643,  1646,  1649,  1652,  1654,  1657,  1660,  1662,  1665,  1668,
    1671,  1674,  1677,  1679,  1681,  1683,  1685,  1687,  1689,  1691,
    1693,  1695,  1698,  1702,  1707,  1709,  1712,  1716,  1718,  1720,
    1722,  1724,  1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,
    1742,  1744,  1746,  1748,  1750,  1752,  1754,  1757,  1760,  1764,
    1766,  1771,  1776,  1780,  1785,  1787,  1791,  1793,  1797,  1799,
    1801,  1805,  1809,  1811,  1813,  1815,  1817,  1819,  1824,  1833,
    1839,  1849,  1859,  1870,  1872,  1875,  1877,  1880,  1887,  1888,
    1890,  1894,  1898,  1899,  1901,  1903,  1905,  1908,  1911,  1912,
    1914,  1916,  1918,  1921,  1924,  1926,  1928,  1930,  1932,  1934,
    1936,  1938,  1940,  1942,  1944,  1946,  1950,  1954,  1957,  1961,
    1965,  1968,  1970,  1972,  1974,  1976,  1978,  1980,  1982,  1987,
    1991,  1999,  2003,  2011,  2016,  2021,  2025,  2033,  2037,  2045,
    2048,  2050,  2053,  2057,  2059,  2061,  2063,  2065,  2067,  2071,
    2075,  2077,  2079,  2081,  2083,  2087,  2089,  2091,  2093,  2095,
    2097,  2099,  2101,  2103,  2105,  2107,  2109,  2111,  2115,  2117,
    2121,  2126,  2131,  2135,  2139,  2143,  2147,  2152,  2157,  2161,
    2166,  2173,  2178,  2185,  2190,  2194,  2199,  2206,  2213,  2218,
    2225,  2232,  2237,  2239,  2242,  2244,  2246,  2248,  2253,  2259,
    2266,  2270,  2274,  2278,  2282,  2288,  2296,  2304,  2310,  2316,
    2322,  2330,  2338,  2344,  2350,  2354,  2358,  2364,  2372,  2378,
    2386,  2388,  2393,  2397,  2403,  2405,  2408,  2412,  2416,  2418,
    2422,  2425,  2426,  2428,  2430,  2433,  2435,  2439,  2441,  2445,
    2447,  2452,  2454,  2457,  2461,  2462,  2464,  2465,  2467,  2472,
    2475,  2479,  2481,  2482,  2484,  2489,  2490,  2492,  2495,  2497,
    2501,  2502,  2504,  2507,  2510,  2512,  2513,  2515,  2516,  2518,
    2520,  2522,  2524,  2526,  2528,  2530,  2534,  2538,  2540,  2542,
    2544,  2547,  2551,  2553,  2555,  2557,  2559,  2561,  2563,  2565,
    2567,  2570,  2573,  2575,  2577,  2580,  2583,  2587,  2589,  2592,
    2595,  2601,  2604,  2606,  2608,  2609,  2612,  2614,  2618,  2623,
    2624,  2627,  2628,  2631,  2636,  2641,  2645,  2648,  2652,  2654,
    2658,  2659,  2661,  2663,  2666,  2669,  2672,  2675,  2677,  2680,
    2683,  2686,  2689,  2693,  2696,  2700,  2704,  2709,  2712,  2715,
    2717,  2719,  2723,  2726,  2730,  2733,  2737,  2740,  2744,  2748,
    2752,  2758,  2764,  2770,  2779,  2785,  2789,  2795,  2803,  2807,
    2811,  2815,  2817,  2819,  2821,  2823,  2825,  2827,  2829,  2831,
    2833,  2835,  2837,  2839,  2841,  2843,  2845,  2847,  2849,  2851,
    2853,  2855,  2857,  2859,  2861,  2863,  2865,  2867,  2869,  2871,
    2873,  2875,  2877,  2879,  2881,  2883,  2885,  2887,  2889,  2891,
    2893,  2895,  2897,  2899,  2901,  2903,  2905,  2907,  2909,  2911,
    2913,  2915,  2917,  2919,  2921,  2923,  2925,  2927,  2929,  2931,
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
    3253,  3255,  3257,  3259,  3261,  3263,  3265
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
    1519,  1530,  1543,  1555,  1568,  1573,  1578,  1583,  1589,  1596,
    1604,  1609,  1617,  1625,  1633,  1641,  1651,  1655,  1661,  1665,
    1672,  1681,  1692,  1698,  1705,  1710,  1717,  1724,  1733,  1743,
    1753,  1763,  1778,  1794,  1798,  1803,  1808,  1812,  1817,  1822,
    1827,  1835,  1842,  1849,  1862,  1863,  1864,  1865,  1866,  1867,
    1868,  1869,  1870,  1871,  1872,  1873,  1874,  1877,  1882,  1889,
    1905,  1911,  1917,  1924,  1931,  1940,  1949,  1958,  1967,  1978,
    1984,  1990,  1996,  2008,  2013,  2019,  2031,  2044,  2064,  2070,
    2077,  2086,  2093,  2099,  2104,  2116,  2128,  2129,  2130,  2131,
    2132,  2133,  2136,  2137,  2138,  2139,  2140,  2141,  2142,  2143,
    2144,  2145,  2146,  2147,  2150,  2162,  2168,  2173,  2179,  2184,
    2189,  2195,  2204,  2214,  2226,  2238,  2244,  2245,  2246,  2249,
    2250,  2251,  2252,  2253,  2256,  2263,  2271,  2276,  2285,  2294,
    2301,  2308,  2318,  2328,  2338,  2348,  2358,  2368,  2378,  2388,
    2398,  2407,  2417,  2427,  2439,  2445,  2451,  2457,  2463,  2471,
    2479,  2487,  2495,  2505,  2511,  2520,  2521,  2525,  2532,  2536,
    2541,  2544,  2548,  2552,  2558,  2564,  2570,  2576,  2584,  2588,
    2596,  2604,  2612,  2620,  2630,  2636,  2642,  2650,  2656,  2664,
    2668,  2676,  2682,  2688,  2694,  2703,  2712,  2721,  2732,  2736,
    2742,  2748,  2756,  2762,  2771,  2782,  2788,  2796,  2800,  2809,
    2815,  2821,  2829,  2835,  2841,  2849,  2855,  2861,  2869,  2875,
    2882,  2892,  2899,  2909,  2915,  2923,  2929,  2938,  2944,  2952,
    2958,  2967,  2973,  2981,  2987,  2991,  2997,  3002,  3008,  3012,
    3021,  3027,  3036,  3046,  3045,  3058,  3067,  3076,  3087,  3091,
    3102,  3106,  3112,  3115,  3121,  3125,  3131,  3135,  3139,  3145,
    3149,  3155,  3161,  3167,  3175,  3179,  3183,  3189,  3193,  3199,
    3207,  3211,  3219,  3223,  3231,  3235,  3243,  3247,  3255,  3259,
    3265,  3269,  3275,  3279,  3283,  3287,  3295,  3296,  3297,  3300,
    3305,  3311,  3315,  3319,  3323,  3327,  3331,  3337,  3341,  3345,
    3351,  3355,  3359,  3363,  3372,  3380,  3386,  3394,  3398,  3402,
    3408,  3412,  3420,  3428,  3446,  3452,  3462,  3466,  3472,  3473,
    3476,  3482,  3490,  3496,  3506,  3512,  3520,  3524,  3528,  3532,
    3536,  3542,  3548,  3554,  3558,  3564,  3568,  3577,  3581,  3585,
    3591,  3595,  3603,  3604,  3607,  3611,  3617,  3621,  3625,  3629,
    3635,  3639,  3643,  3647,  3653,  3659,  3667,  3673,  3674,  3675,
    3676,  3677,  3678,  3679,  3680,  3681,  3682,  3683,  3684,  3685,
    3686,  3689,  3693,  3699,  3706,  3713,  3722,  3728,  3732,  3738,
    3745,  3751,  3757,  3761,  3779,  3785,  3791,  3797,  3805,  3809,
    3815,  3821,  3831,  3832,  3835,  3836,  3837,  3840,  3848,  3864,
    3872,  3888,  3906,  3926,  3932,  3941,  3947,  3956,  3963,  3964,
    3966,  3971,  3978,  3981,  3987,  3993,  3999,  4006,  4015,  4018,
    4024,  4030,  4036,  4043,  4052,  4056,  4062,  4066,  4072,  4076,
    4080,  4085,  4092,  4096,  4100,  4104,  4110,  4115,  4121,  4127,
    4134,  4140,  4145,  4150,  4155,  4160,  4165,  4170,  4173,  4179,
    4183,  4189,  4193,  4199,  4205,  4211,  4215,  4221,  4225,  4231,
    4237,  4241,  4245,  4251,  4257,  4263,  4271,  4284,  4288,  4292,
    4296,  4300,  4304,  4310,  4316,  4324,  4330,  4336,  4340,  4344,
    4348,  4352,  4356,  4360,  4364,  4368,  4372,  4378,  4384,  4390,
    4394,  4398,  4404,  4409,  4415,  4421,  4425,  4430,  4436,  4440,
    4446,  4452,  4456,  4464,  4470,  4474,  4480,  4489,  4498,  4504,
    4510,  4518,  4524,  4530,  4536,  4542,  4546,  4552,  4558,  4562,
    4570,  4576,  4582,  4588,  4596,  4600,  4606,  4612,  4616,  4622,
    4626,  4632,  4638,  4645,  4653,  4658,  4664,  4670,  4678,  4684,
    4691,  4697,  4706,  4712,  4718,  4724,  4733,  4740,  4746,  4752,
    4761,  4768,  4772,  4778,  4783,  4790,  4794,  4800,  4804,  4810,
    4814,  4820,  4824,  4832,  4843,  4846,  4852,  4855,  4861,  4867,
    4875,  4879,  4885,  4888,  4894,  4904,  4907,  4913,  4923,  4929,
    4937,  4940,  4946,  4950,  4954,  4960,  4963,  4969,  4972,  4978,
    4982,  4986,  4990,  4994,  5000,  5006,  5016,  5026,  5030,  5034,
    5040,  5046,  5054,  5058,  5062,  5066,  5070,  5074,  5078,  5082,
    5088,  5092,  5096,  5100,  5106,  5112,  5120,  5128,  5132,  5138,
    5148,  5159,  5165,  5169,  5175,  5178,  5184,  5189,  5196,  5204,
    5207,  5213,  5217,  5223,  5232,  5239,  5247,  5251,  5257,  5263,
    5271,  5274,  5280,  5285,  5295,  5303,  5313,  5319,  5323,  5329,
    5333,  5337,  5343,  5349,  5353,  5357,  5361,  5367,  5375,  5385,
    5389,  5395,  5401,  5405,  5411,  5415,  5421,  5425,  5431,  5438,
    5444,  5453,  5459,  5469,  5475,  5481,  5502,  5526,  5550,  5554,
    5558,  5564,  5567,  5568,  5569,  5570,  5571,  5572,  5573,  5574,
    5575,  5576,  5577,  5578,  5579,  5580,  5581,  5582,  5583,  5584,
    5585,  5586,  5587,  5588,  5589,  5592,  5593,  5594,  5595,  5596,
    5597,  5598,  5599,  5600,  5601,  5602,  5603,  5604,  5605,  5606,
    5607,  5608,  5609,  5610,  5611,  5612,  5613,  5614,  5615,  5616,
    5617,  5618,  5619,  5620,  5621,  5622,  5623,  5624,  5625,  5626,
    5627,  5628,  5629,  5630,  5631,  5632,  5633,  5634,  5635,  5636,
    5637,  5638,  5639,  5640,  5641,  5642,  5643,  5644,  5645,  5646,
    5647,  5648,  5649,  5650,  5651,  5652,  5653,  5654,  5655,  5656,
    5657,  5658,  5659,  5660,  5661,  5662,  5663,  5664,  5665,  5666,
    5667,  5668,  5669,  5670,  5671,  5672,  5673,  5674,  5675,  5676,
    5677,  5678,  5679,  5680,  5681,  5682,  5683,  5684,  5685,  5686,
    5687,  5688,  5689,  5690,  5691,  5692,  5693,  5694,  5695,  5696,
    5697,  5698,  5699,  5700,  5701,  5702,  5703,  5704,  5705,  5706,
    5707,  5708,  5709,  5710,  5711,  5712,  5713,  5714,  5715,  5716,
    5717,  5718,  5719,  5720,  5721,  5722,  5723,  5724,  5725,  5726,
    5727,  5728,  5729,  5730,  5731,  5732,  5733,  5734,  5735,  5736,
    5737,  5738,  5739,  5740,  5741,  5742,  5743,  5744,  5745,  5746,
    5747,  5748,  5749,  5750,  5751,  5752,  5753,  5754,  5755,  5756,
    5757,  5758,  5759,  5760,  5761,  5762,  5763,  5764,  5765,  5766,
    5767,  5768,  5769,  5770,  5771,  5772,  5773,  5774,  5775,  5776,
    5777,  5778,  5779,  5780,  5781,  5782,  5783,  5784,  5785,  5786,
    5787,  5788,  5789,  5790,  5791,  5792,  5795
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
  const int xquery_parser::yylast_ = 17457;
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
#line 17623 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 5797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"

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

