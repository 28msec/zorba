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
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 944 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 952 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 960 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
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
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
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
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
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
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
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
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3379 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3387 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3393 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 3401 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 3405 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 3409 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 3415 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 432:

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

  case 433:

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

  case 434:

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

  case 435:

/* Line 690 of lalr1.cc  */
#line 3453 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 436:

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

  case 437:

/* Line 690 of lalr1.cc  */
#line 3469 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 3473 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 3483 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 442:

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

  case 443:

/* Line 690 of lalr1.cc  */
#line 3497 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 444:

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

  case 445:

/* Line 690 of lalr1.cc  */
#line 3513 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 3519 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 3527 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 3531 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 3535 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 3539 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 3543 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 3549 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 3555 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 3561 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 3565 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 3571 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 3575 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 3584 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 3588 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 3592 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 3598 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 3602 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 3614 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 3618 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 3624 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 3628 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 3632 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 3636 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 3642 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 3646 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 3650 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 3654 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 3660 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      PredicateList* pl = new PredicateList( LOC((yyloc)) );
      pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.node) = pl;
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 3666 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if (PredicateList* pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)))
        pl->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 3674 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 3696 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 3700 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 3706 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 3713 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 3720 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 3729 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 3735 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 3739 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 3745 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            driver.addCommonLanguageWarning((yylocation_stack_[(1) - (1)]), ZED(ZWST0009_CONTEXT_ITEM_EXPR));
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 3752 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 3758 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 3764 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FunctionCall(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL);
    }
    break;

  case 504:

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

  case 505:

/* Line 690 of lalr1.cc  */
#line 3786 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList* al = new ArgList(LOC((yyloc)));
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 3792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if (ArgList* al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)))
        al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 3798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 3804 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 3812 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 3816 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 3822 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 512:

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

  case 518:

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

  case 519:

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

  case 520:

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

  case 521:

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

  case 522:

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

  case 523:

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

  case 524:

/* Line 690 of lalr1.cc  */
#line 3933 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 3939 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 3948 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 3954 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 3963 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 3973 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 3978 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 3984 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 3988 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 3994 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4000 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4006 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4013 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4021 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4025 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4031 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4037 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4043 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4050 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4059 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4063 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4069 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4073 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4079 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4083 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4087 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4092 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4099 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4103 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4107 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4111 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4117 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4122 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4128 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)) );
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4134 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(3) - (2)].expr), (yylocation_stack_[(3) - (2)]));
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4141 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4147 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4152 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 4157 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 4162 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 4167 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 4172 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 4180 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 4186 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 4190 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 4196 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 4200 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 4206 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 4212 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 4218 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 4222 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 4228 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 4232 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 4238 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 4244 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 4248 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 4252 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 4258 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 4264 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 4270 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 4278 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 588:

/* Line 690 of lalr1.cc  */
#line 4291 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 4295 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 4299 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 4303 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 4307 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 4311 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 4317 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 4323 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 4331 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 4337 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 4343 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 4347 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 4351 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 4355 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 4359 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 4363 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 4367 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 4371 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 4375 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 4379 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 4385 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 4391 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 4397 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 4401 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 4405 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 4411 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 4416 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 4422 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 4428 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 4432 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            ERROR_IF_QNAME_NOT_NCNAME((yysemantic_stack_[(4) - (3)].expr), (yylocation_stack_[(4) - (3)]));
            (yyval.node) = new PITest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 4437 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 4443 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 4447 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 4453 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 4459 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 4463 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 4471 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 4477 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 4481 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 4487 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 4496 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 4505 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 4511 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 4517 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 4525 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 4531 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 4537 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 4543 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 4549 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 4553 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 4559 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 4565 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 4569 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 4577 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 4583 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 4589 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 4595 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 4603 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 4607 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 4613 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 4619 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 4623 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 4629 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 4633 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 4639 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 4645 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 4652 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 4660 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 4665 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 4671 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 4677 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 4685 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 4691 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 4698 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 4704 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 4713 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 4719 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 4725 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 4731 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 4740 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 4747 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 4753 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 4759 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 4768 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 4775 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 4779 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 4785 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 4790 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 4797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 4801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 4807 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 4811 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 4817 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 4821 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 4827 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 4831 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 4839 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 4849 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 4853 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 4858 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 4862 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 4868 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 4874 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 4882 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 4886 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 4891 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 4895 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 4901 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 4910 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 4914 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 4920 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 4930 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 4936 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 4943 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 4947 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 4953 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 4957 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 4961 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 4966 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 4970 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 4975 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 4979 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 4985 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 4989 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 4993 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 4997 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 5001 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 5007 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 5013 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 5023 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 5033 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 5037 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 5041 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 5047 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 5053 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 5061 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 5065 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 5069 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 5073 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 5077 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 5081 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 5085 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 5089 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 5095 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 5099 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 5103 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 5107 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 5113 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 5119 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 5127 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 5135 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 5139 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 5145 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 741:

/* Line 690 of lalr1.cc  */
#line 5155 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 742:

/* Line 690 of lalr1.cc  */
#line 5166 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 5172 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 5176 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 5181 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 5185 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 5191 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 5196 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 5203 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 5210 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 5214 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 5220 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 5224 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 5230 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 5239 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 5246 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 5254 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 5258 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 5264 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 5270 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 5277 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 5281 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 5287 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 5292 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 5302 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 5310 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 5320 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 5326 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 5330 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 5336 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 5340 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 5344 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 5350 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 5356 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 5360 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 5364 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 5368 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 5374 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 5382 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 5392 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 5396 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 5402 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 5408 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 5412 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 5418 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 5422 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 5428 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 5432 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 5438 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 5445 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 5451 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 5460 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 5466 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 794:

/* Line 690 of lalr1.cc  */
#line 5476 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 5482 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 5488 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 797:

/* Line 690 of lalr1.cc  */
#line 5509 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 798:

/* Line 690 of lalr1.cc  */
#line 5533 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 799:

/* Line 690 of lalr1.cc  */
#line 5557 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 5561 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 5565 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 5574 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 5575 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 5576 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 5577 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 5578 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 5579 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 5580 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 5581 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 5582 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 5583 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 5584 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 5585 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 5586 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 5587 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 5588 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 5589 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 5590 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 5591 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 5592 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 5593 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 5594 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 5595 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 5599 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 5600 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 5601 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 5602 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 5603 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 5604 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 5605 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 5606 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 5607 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 5608 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 5609 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 5610 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 5611 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 5612 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 5613 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 5614 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 5615 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 5616 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 5617 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 5618 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 5619 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 5620 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 5621 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 5622 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 5623 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 5624 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 5625 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 5626 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 5627 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 5628 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 5629 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 5630 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 5631 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 5632 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 5633 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 5634 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 5635 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 5636 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 5637 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 5638 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 5639 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 5640 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 5641 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 5643 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 5644 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 5645 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 5646 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 5647 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 5648 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 5649 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 5650 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 5651 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 5652 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 5653 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 5654 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 5655 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 5656 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 5657 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 5658 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 5659 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 5660 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 5661 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 5662 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 5663 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 5664 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 5665 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 5666 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 5667 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 5668 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 5669 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 5670 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 5671 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 5672 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 5673 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 5674 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 5675 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 5676 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 5677 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 5678 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 5679 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 5680 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 5681 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 5682 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 5683 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 5684 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 5685 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 5686 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 5687 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 5688 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 5689 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 5690 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 5691 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 5692 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 5693 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 5694 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 5695 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 5696 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 5697 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 5698 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 5699 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 5700 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 5701 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 5702 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 5703 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 5704 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 5705 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 5706 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 5707 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 5708 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 5709 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 5710 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 5711 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 5712 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 5713 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 5714 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 5715 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 5716 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 5717 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 5718 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 5719 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 5720 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 5721 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 5722 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 5723 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 5724 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 5725 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 5726 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 5727 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 5728 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 5729 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 5730 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 5731 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 5732 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 5733 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 5734 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 5735 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 5736 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 5737 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 5738 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 5739 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 5740 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 5741 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 5742 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 5743 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 5744 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 5745 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 5746 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 5747 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 5748 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 5749 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 5750 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 5751 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 5752 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 5753 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 5754 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 5755 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 5756 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 5757 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 5758 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 5759 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 5760 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 5761 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 5762 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 5763 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 5764 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 5765 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 5766 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 5767 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 5768 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 5769 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 5770 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 5771 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 5772 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 5773 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 5774 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 5775 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 5776 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 5777 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 5778 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 5779 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 5780 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 5781 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 5782 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 5783 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 5784 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 5785 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 5786 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 5787 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 5788 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 5789 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 5790 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 5791 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 5792 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1021:

/* Line 690 of lalr1.cc  */
#line 5793 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1022:

/* Line 690 of lalr1.cc  */
#line 5794 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1023:

/* Line 690 of lalr1.cc  */
#line 5795 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1024:

/* Line 690 of lalr1.cc  */
#line 5796 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1025:

/* Line 690 of lalr1.cc  */
#line 5797 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1026:

/* Line 690 of lalr1.cc  */
#line 5798 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1027:

/* Line 690 of lalr1.cc  */
#line 5801 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12084 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1524;
  const short int
  xquery_parser::yypact_[] =
  {
      4600, -1524, -1524, -1524, -1524,  6154,  6154,  6154,  6154, -1524,
   -1524,   206,   318, -1524,   729,   230, -1524, -1524, -1524,   373,
   -1524, -1524, -1524,    16,   456,   843,  4318,   563,   616,   837,
   -1524,   -15, -1524,   661, -1524, -1524, -1524, -1524, -1524,   861,
   -1524,   711,   721, -1524, -1524, -1524, -1524,   383, -1524,   871,
   -1524,   780,   800, -1524,   377, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,   579,
     853, -1524, -1524, -1524, -1524,   552, 12664, -1524, -1524, -1524,
     890, -1524, -1524, -1524,   900, -1524,   907,   915, -1524, -1524,
   16535, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,   923,
   -1524, -1524,   927,   929, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524,  5224,  8634,  8944, 16535, -1524, -1524,   902, -1524, -1524,
   -1524, -1524,   906, -1524, -1524,   941, 16535, -1524, 13575,   947,
     948, -1524, -1524, -1524,   949, -1524, -1524, 12044, -1524, -1524,
   -1524, -1524, -1524, -1524,   919, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524,    68,   873, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524,   -87,   918,   148, -1524,   189,   339, -1524,
   -1524, -1524, -1524, -1524, -1524,   968, -1524,   850,   851,   852,
   -1524, -1524,   938,   942, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524,  9254,  9564, -1524,
     786, -1524, -1524, -1524, -1524, -1524,  4912,  6464,  1098, -1524,
    6774, -1524, -1524,   150,    72, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,    95,
   -1524, -1524, -1524, -1524, -1524, -1524,   421, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524,  6154, -1524, -1524, -1524, -1524,
      27, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
     116, -1524,   909, -1524, -1524, -1524,   502, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524,   934,  1009, -1524,   760,   854,
    1004,   624,   646,   497,   623, -1524,  1055,   908,  1005,  1003,
   10494, -1524,   916, -1524, -1524,   304, -1524, -1524, 12354, -1524,
     835, -1524,   955, 12664, -1524,   955, 12664, -1524, -1524, -1524,
     888, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,   954, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524,    35, -1524, -1524, -1524,
   -1524, -1524,   930, -1524,  6154,   931,   932,   936,  6154,   567,
     567,  1083,   684,   751,   474, 17123, 16535,   479,  1070, 16535,
     965,  1002,   466, 16535,   813,   879, 16535, 16535,   822,   856,
      40, -1524, -1524, -1524, 16535,  6154,   940,  6154,   152, 10804,
   13871, 16535, -1524,   844,   846, 16535,  1012,    24,   978, 10804,
    1132,   198,    76, 16535,  1015,   994,  1030, -1524,   952, 10804,
   14167, 16535, 16535, 16535,  6154,   956, 10804, 10804, 16535,  6154,
     986,   987, -1524, -1524, -1524, 10804, 14463,   985, -1524,   992,
   -1524, -1524, -1524, -1524,   995, -1524,   997, -1524, -1524, -1524,
   -1524, -1524,   998, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, 16535, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524,  1001, 16535, -1524, -1524, -1524,
     967,  5534,  1031,   292,   999,  1000,  1006, 16535,  6154, -1524,
    1007,   221, -1524,   591, -1524,    94,  1124, 10804, 10804, -1524,
     168, -1524, -1524,  1145, -1524, -1524, -1524, -1524, 10804,   950,
   -1524,  1135, 10804, 10804, 16835, 10804, 10804, 10804, 10804, 16835,
   10804,   937,   939, 16535,   977,   980, 10804, 10804,  5224,   926,
   -1524,    65, -1524,    57, 10804,  6464, -1524, -1524, -1524, -1524,
   -1524,   729,   837,    96,   104,  1169,  7084,  3056,  7394,  3377,
     900, -1524, -1524,   247,   900, -1524, 10804,  3997, -1524,  1054,
     781,   -15,  1008,  1010,  1011,  6154, 10804, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, 11114, 11114, 11114, -1524, 11114,
   11114, -1524, 11114, -1524, 11114, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, 11114, 11114,  1103, 11114, 11114, 11114, 11114, 11114,
   11114, 11114, 11114, 11114, 11114, 11114, 11114,   944,  1082,  1084,
    1088, -1524, -1524, -1524, 11734,  9874, -1524, -1524, 12044, 12044,
   10804,   955, -1524, -1524,   955, -1524,  8014,   955,   991,  1034,
    8324, -1524, -1524, -1524, -1524,    33, -1524,   274, -1524, -1524,
   -1524, -1524, -1524, -1524,  1077,  1078,   563,  1157, -1524, -1524,
   17123,   996,   658, 16535,  1032,  1033,   996,  1083,  1064,  1062,
   -1524, -1524, -1524,   139,   951,  1101,   899, 16535,  1056, 10804,
    1081, 16535, 16535, -1524,  1068,  1018, -1524,  1019,   992,   721,
   -1524,  1017,  1020,   241, -1524,   301,   384,  1097, -1524,    53,
   -1524, -1524,  1097, 16535,    34, 16535,  1111,   387, -1524,  6154,
   -1524,   102, -1524, 16535,  1112,  1165, 16535,  1083,  1114,   541,
   16535, 10804,   -15, -1524,   272,  1025, -1524,  1026,  1027,  1028,
      17, -1524,   351,  1035, -1524,   122,   141,  1063, -1524,  1036,
    6154,  6154,   355, -1524,   393,   437,   670, 10804,   271, -1524,
   -1524, 10804, 10804, -1524, 10804, 10804, 10804, -1524, 10804, -1524,
   10804, -1524, 16535,  1124, -1524,   313,   359,   366, -1524, -1524,
   -1524,   382, -1524,    28, -1524, -1524,  1067,  1069,  1071,  1072,
    1073,   888,    35,   250,   290,   252,    21,  1121,   500,   981,
    1014,   993,   136, -1524,  1079, -1524, -1524,  1039,   145,  5534,
     392, 12974,   926, -1524, -1524, -1524,  1013, -1524,   150,   779,
    1197,   176, -1524, -1524,   121, -1524, -1524, -1524,   127, -1524,
      74, -1524, -1524, -1524, -1524, -1524,  3687, -1524, -1524, -1524,
   16535,  1061, 10804, 11424, -1524, -1524, -1524,  1009, -1524, -1524,
   -1524, -1524, -1524, 11114, -1524, -1524, -1524,    82, -1524,   646,
     646,    36,   497,   497,   497,   497,   623,   623, -1524, -1524,
   15647, 15647, 16535, 16535, -1524, -1524,   397, -1524, -1524,   337,
   -1524, -1524, -1524, -1524,   443, -1524, -1524, -1524,   471,   567,
   -1524, -1524,   773,   785,   790, -1524,   563, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524,   996, -1524,  1099,
   15943,  1090, 10804, -1524, -1524, -1524,  1140,  1083,  1083,   996,
   -1524,    55,  1083,   725, 16535,   612,   708,  1206, -1524, -1524,
     957,   572, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524,   139,    47,  1021,   687, 10804, -1524, 16535,
    1142,   945,  1083, -1524, -1524, -1524, -1524,  1086, 16535, -1524,
   16535, -1524, 16239,  1113, 15647,  1126, 10804,   -12,  1102,    58,
     523,  1016, -1524, -1524,   671,    34,  1140, 15647,  1130,  1158,
    1074,  1057,  1119,  1083,  1093,  1123,  1160,  1083, 10804,   -35,
   -1524, -1524, -1524,  1105, -1524, -1524, -1524, -1524,  1141, 10804,
   10804,  1115, -1524,  1161,  1163,  6154, -1524,  1085,  1087,  1118,
   16535, -1524, 16535, -1524, 10804,  1122,  1076, 10804, -1524,  1146,
     207,   212,   232,  1238, -1524,   486, -1524,   117,  1125, -1524,
   -1524,  1245, -1524,   805, 10804, 10804, 10804,   817, 10804, 10804,
   10804, 10804, 10804, 10804, 10804, 10804, 10804, 16835,  1164, 10804,
   10804, -1524,  7704,   118,  1041, -1524,    -7, -1524, 10804,   129,
     131,    74,  7394,  3377,  7394,  1204, -1524, -1524, 10804,   777,
    1179, -1524, 16535,  1170,  1180, -1524, -1524, 10804,    82,   706,
     695, -1524,  1022,   181,  1038,  1029, -1524, -1524,   879, -1524,
    1023,   673,  1134,  1136, 15943,  1144,  1148,  1149,  1153,  1154,
   -1524,   514, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524,  1147, -1524, -1524, -1524, -1524, 10184, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524,   808, -1524,  1268,
     868, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
    1037, -1524, -1524,  1269, -1524, -1524, -1524, -1524, -1524,   701,
    1272, -1524,   811, -1524, -1524, -1524,   985,   456,   661,   995,
     711,   997,   998, -1524,  1148,  1149,  1153, -1524,   514,   514,
   11734,  1042,  1040, -1524,  1140,    47,  1089,  1127,  6154,  1116,
    1128,  1167,  1131,  1133, 16535, -1524,    83, -1524, 16535, -1524,
   10804,  1166, 10804,  1191, 10804,    52,  1173, 10804,  1174, -1524,
    1207,  1213, 10804, 16535,   953,  1247, -1524, -1524, -1524, -1524,
   -1524, -1524, 15647, -1524,  6154,  1083,  1226, -1524, -1524, -1524,
    1083,  1226, -1524, 10804,  1192,  6154, 16535, -1524, -1524, 10804,
   10804,   575, -1524,    43,   647, -1524, 14759,   855, -1524,   858,
   -1524,  1152, -1524, -1524,  6154,  1151,  1155, -1524, 10804, -1524,
   -1524, 10804,  1143,  1161,  1242, -1524,  1211, -1524,   428, -1524,
   -1524,  1332, -1524, -1524,  6154, 16535, -1524,   741, -1524, -1524,
   -1524,  6154,  1162,  1117,  1120, -1524, -1524, -1524,  1129,  1137,
   -1524, -1524, -1524,  1248, -1524, -1524, -1524, -1524,  1159,   510,
   16535,  1172, -1524,  1198,  1203,  1209,  1210, -1524,   909,   784,
   12974,  1041, -1524,  5844, 12974, -1524, -1524,  1197,   426, -1524,
   -1524, -1524,  1179, -1524,  1083, -1524,   709, -1524,   588,  1254,
   -1524, 10804,   686,  1083, -1524, 11424,   441,  1181, -1524,    82,
    1138, -1524, -1524,   -38, -1524,   639,   101,  1139,    82,   639,
   11114, -1524,   155, -1524, -1524, -1524, -1524, -1524, -1524,    82,
    1219,  1091,   951,   101, -1524, -1524,  1092,  1292, -1524, -1524,
   -1524, 13270,  1187,  1190,  1194,  1195,  1196,  1205,  1212, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524,  1354,   446,  1355,   446,  1156,  1283, -1524, -1524,
    1227, 16535,  1150, -1524, -1524, 11734, -1524,  1216, -1524, -1524,
   -1524, -1524, -1524, -1524, 10804,  1253, -1524, -1524, 10804, -1524,
     343, -1524, 10804,  1255, 10804, -1524, 10804, 16535, 16535, -1524,
     735, -1524, 10804, -1524,  1277,  1278,  1311,  1083,  1226, -1524,
   10804,  1225, -1524, -1524, -1524,  1224, -1524,   328, 10804,  6154,
    1231,   376, -1524, 16535,   585, -1524, 15055,    48, -1524, 15351,
    1232, -1524, -1524,  1235, -1524, -1524, -1524, -1524, 10804,   859,
    1238, 16535,   827, -1524,  1236,  1238, 16535, -1524,  1239, -1524,
   10804, 10804, 10804, 10804,  1095, 10804, 10804, -1524, 10804, 10804,
   10804, 10804,  7704,   545, -1524, -1524, -1524, -1524, -1524,  1254,
   -1524, -1524, -1524, 10804,  1279, -1524, -1524, -1524, -1524, -1524,
    1240, 11114, -1524, -1524, -1524, -1524, -1524,   300, 11114, 11114,
     672, -1524,  1038, -1524,   320, -1524,  1029,    82,  1271, -1524,
   -1524,  1171, -1524, -1524, -1524, -1524,  1331,  1241, -1524,   513,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,   515,   515,
   -1524,   446, -1524, -1524,   524, -1524,  1400,   101,  1334,  1249,
   11734,    -6,  1168,  1262, -1524, -1524, 10804, -1524, 10804,  1285,
   -1524, 10804, -1524, -1524, -1524,  1381, -1524, -1524,  7704, 10804,
    1083, -1524, -1524, -1524, 10804, 10804, -1524, -1524, -1524,  7704,
    7704,  1342,  6154, 15647, 16535,   606, 16535, 10804, 16535,   641,
    7704, -1524,   491,   410,  1238, 16535, -1524,  1243,  1238, -1524,
   -1524, -1524, -1524, -1524, 10804, -1524, -1524, -1524,   234,   245,
     254, 10804, -1524, -1524,  1170, 10804, -1524,   497, 11114, 11114,
      36,   688, -1524, -1524, -1524, -1524, -1524, -1524, 10804, -1524,
   15647, -1524, 15647,  1343, -1524, -1524, -1524,  1409, -1524, -1524,
   -1524,  1177,  1335, -1524, -1524,  1336, -1524,   882, 16535,  1326,
    1221, 16535, 11734, -1524, -1524, 10804, -1524,  1328, -1524, -1524,
    1226, -1524, -1524, 15647, -1524, -1524, -1524,  1357, 10804,  1267,
   -1524,  1359,  7704, -1524, 16535,   520,   556, -1524,  1259,  1238,
   -1524,  1260, -1524,  1261,  1161,  1163,   451, -1524,  1170,    36,
      36, 11114,   459, -1524, -1524, 15647, -1524, -1524,  1334, 11734,
   -1524,  1254,  1176, 16535,  1339,  1237,  1336, -1524, 16535,   693,
   15647,  6154, 15647,  1274, -1524, -1524,  1367,   598, -1524, -1524,
   -1524, -1524,  1280,   561, -1524, -1524, -1524,  1270, -1524,  7704,
     860, -1524, -1524,    36, -1524, -1524, -1524, -1524, -1524, 10804,
    1178, 16535,  1345, -1524,  6154,   703, -1524, -1524,   720, 10804,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524,  1346, -1524,  1175,
    1182, 16535, -1524, -1524, 10804,  7704, 16535,  1184, 10804,  1185,
    1284, 11734, -1524, 11734,  7704, -1524,  1273,  1186, 16535,  1244,
    1347, 16535,  1188, 11734, -1524
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       165,   468,   469,   804,   470,   168,   168,   168,     0,   827,
    1027,   120,   122,   635,   920,   929,   869,   832,   830,   806,
     921,   924,   876,   836,   807,   809,     0,   930,   811,   927,
     898,   878,   852,   808,   873,   874,   925,   922,   872,   813,
     928,   814,   815,   968,   980,   967,   870,   889,   883,   816,
     871,   818,   817,   969,   907,   908,   875,   849,   990,   991,
     992,   993,   994,   995,   996,   997,   998,   999,  1000,  1014,
    1021,   897,   893,   884,   863,   805,     0,   892,   900,   909,
    1015,   888,   494,   864,   865,   923,  1016,  1022,   885,   902,
       0,   500,   457,   496,   895,   829,   886,   887,   916,   890,
     906,   915,  1020,  1023,   835,   877,   918,   495,   905,   911,
     810,     0,     0,     0,     0,   403,   903,   914,   919,   917,
     896,   882,   970,   880,   881,  1017,     0,   402,     0,  1018,
    1024,   912,   866,   891,  1019,   212,   435,     0,   467,   913,
     894,   901,   910,   904,   971,   857,   862,   861,   860,   859,
     858,   819,   879,     0,   828,   926,   850,   961,   960,   962,
     834,   833,   853,   959,   812,   957,   964,   958,   956,   856,
     899,   955,   966,   965,   954,   854,   963,   975,   976,   973,
     974,   972,   820,   977,   978,   979,   946,   945,   932,   848,
     841,   939,   935,   851,   847,   947,   868,   837,   838,   831,
     840,   944,   943,   940,   936,   952,   953,   951,   942,   938,
     931,   839,   950,   949,   843,   845,   844,   937,   941,   933,
     846,   934,   842,   948,  1001,  1002,  1003,  1004,  1005,  1006,
     982,   983,   981,   987,   988,   989,   984,   985,   986,   855,
    1007,  1008,  1009,  1010,  1011,  1012,  1013,     0,     0,   821,
     822,  1025,  1026,   824,   823,   825,   165,   165,     0,     2,
     165,     9,    11,    23,     0,    28,    31,    36,    37,    38,
      39,    40,    41,    42,    32,    58,    59,    33,    34,     0,
      76,    79,    80,    35,    81,    82,     0,   118,    83,    84,
      85,    86,    18,   162,   163,   164,   171,   174,   487,   175,
       0,   176,   177,   178,   179,   180,   181,   182,   185,   186,
       0,   213,   221,   216,   248,   254,     0,   246,   247,   223,
     217,   184,   218,   183,   219,   222,   354,   356,   358,   368,
     370,   374,   376,   379,   384,   387,   390,   392,   394,   396,
       0,   400,   407,   406,   408,     0,   426,   409,   431,   434,
     436,   439,   441,     0,   446,   443,     0,   454,   464,   466,
     440,   471,   478,   492,   479,   480,   481,   484,   485,   482,
     486,   509,   510,   483,   513,   515,   516,   517,   514,   562,
     563,   564,   565,   566,   567,   568,   463,   607,     0,   598,
     606,   605,   604,   603,   600,   602,   599,   601,   493,    43,
     224,   225,   227,   226,   228,   220,   489,   490,   491,   488,
     230,   233,   229,   231,   232,   465,   803,   826,   920,   929,
     927,   828,     0,   166,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,   258,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   276,   277,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   459,   462,   449,     0,     0,   806,   836,   809,
     867,   930,   811,   878,   813,   889,   816,   818,   817,   907,
    1014,  1021,   805,  1015,   865,  1016,  1022,   890,  1020,  1023,
     914,   970,  1017,  1018,  1024,  1019,   971,   959,   957,   958,
     956,   854,   975,   976,   973,   820,   977,   822,   455,   803,
     447,     0,   193,   448,   451,   806,   807,   809,   808,   813,
     814,   815,   816,   805,   812,   497,     0,   453,   452,   188,
       0,     0,   213,     0,   811,   818,   817,     0,   168,   783,
     977,     0,   221,     0,   498,     0,   529,     0,     0,   458,
       0,   429,   430,     0,   461,   460,   450,   433,     0,     0,
     558,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     785,     0,   787,     0,     0,   165,     3,     4,     1,    10,
      12,     0,     0,     0,     0,     6,   165,     0,   165,     0,
       0,   119,   172,     0,     0,   191,     0,     0,   200,     0,
       0,     0,     0,     0,     0,     0,     0,   205,   234,   253,
     249,   255,   250,   252,   251,     0,     0,     0,   419,     0,
       0,   417,     0,   363,     0,   418,   411,   416,   415,   414,
     413,   412,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   405,   404,   401,     0,     0,   427,   432,     0,     0,
       0,   442,   475,   445,   444,   456,     0,   472,     0,     0,
       0,   570,   572,   576,   578,     0,   124,     0,   802,    47,
      44,    45,    48,    49,     0,     0,     0,     0,    50,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     642,   643,   644,     0,   103,   142,     0,     0,   112,     0,
       0,     0,     0,   127,     0,     0,   615,     0,     0,     0,
     610,     0,     0,     0,   625,     0,     0,   257,   259,     0,
     236,   237,   256,     0,     0,     0,   134,     0,   138,   168,
     512,     0,    60,     0,    69,     0,     0,     0,    61,     0,
       0,     0,     0,   613,     0,     0,   616,     0,     0,     0,
       0,   325,     0,     0,   614,     0,     0,     0,   633,     0,
       0,     0,     0,   619,     0,     0,   195,     0,     0,   189,
     187,     0,     0,   789,     0,     0,     0,   497,     0,   784,
       0,   499,   530,   529,   526,     0,     0,     0,   560,   559,
     428,     0,   557,     0,   655,   656,     0,     0,     0,     0,
       0,   796,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   661,     0,   203,   204,     0,     0,     0,
       0,     0,   208,   209,   786,   788,     0,     5,    24,     0,
      25,     0,     7,    29,     0,    15,     8,    30,     0,    19,
     920,    77,    16,    78,    20,   194,     0,   192,   214,   215,
       0,     0,     0,     0,   206,   235,   294,   355,   357,   361,
     367,   366,   365,     0,   362,   359,   360,     0,   371,   378,
     377,   375,   381,   382,   383,   380,   385,   386,   389,   388,
       0,     0,     0,     0,   410,   424,     0,   437,   438,     0,
     476,   505,   473,   507,     0,   608,   511,   503,     0,     0,
     121,   123,     0,     0,     0,   102,     0,    92,    94,    95,
      96,    97,    99,   100,   101,    93,    98,    88,    89,     0,
       0,   108,     0,   104,   106,   107,   114,     0,     0,    87,
      46,     0,     0,     0,     0,     0,     0,     0,   733,   738,
       0,     0,   734,   768,   721,   723,   724,   725,   727,   729,
     728,   726,   730,     0,     0,     0,     0,     0,   111,     0,
     144,     0,     0,   575,   569,   611,   612,     0,     0,   629,
       0,   626,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   238,   239,     0,   244,   140,     0,     0,   135,
       0,     0,     0,     0,     0,     0,    62,     0,     0,     0,
     275,   281,   278,     0,   618,   617,   624,   632,     0,     0,
       0,     0,   574,     0,     0,     0,   420,     0,     0,     0,
       0,   622,     0,   620,     0,   196,     0,     0,   790,     0,
       0,     0,     0,   529,   527,     0,   518,     0,     0,   501,
     502,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   201,     0,     0,     0,   669,     0,   210,     0,     0,
       0,     0,   165,     0,   165,     0,   173,   245,     0,   309,
     305,   307,     0,   302,   295,   296,   364,     0,     0,     0,
       0,   699,   372,   672,   676,   678,   680,   682,   685,   692,
     693,   701,   930,   810,     0,   819,  1026,   824,   823,   825,
     391,   581,   587,   588,   591,   636,   637,   592,   593,   596,
     393,   395,   398,   597,   397,   425,   477,     0,   474,   504,
     125,    56,    57,    54,    55,   131,   130,     0,    90,     0,
       0,   109,   110,   115,    74,    75,    52,    53,    73,   739,
       0,   742,   769,     0,   732,   731,   736,   735,   767,     0,
       0,   744,     0,   740,   743,   722,     0,     0,     0,     0,
       0,     0,     0,   609,     0,     0,     0,   143,   146,   148,
       0,     0,     0,   113,   116,     0,     0,     0,   168,     0,
       0,   633,     0,     0,     0,   261,     0,   580,     0,   262,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   240,
       0,     0,     0,     0,   288,     0,   285,   290,   243,   141,
     136,   139,     0,   190,     0,     0,    71,    65,    68,    67,
       0,    63,   279,     0,     0,   168,     0,   323,   327,     0,
       0,     0,   330,     0,     0,   336,     0,     0,   343,     0,
     347,     0,   422,   421,   168,     0,     0,   197,     0,   199,
     324,     0,     0,     0,     0,   530,     0,   520,     0,   553,
     550,     0,   554,   555,     0,     0,   549,     0,   524,   552,
     551,     0,     0,     0,     0,   648,   649,   645,     0,     0,
     653,   654,   650,   792,   793,   659,   797,   657,     0,     0,
       0,     0,   663,   811,   818,   817,   977,   202,     0,     0,
       0,   664,   665,     0,     0,   211,   795,    26,     0,    17,
      21,    22,   306,   318,     0,   319,     0,   310,   311,   312,
     313,     0,   497,     0,   303,     0,     0,     0,   683,   696,
       0,   369,   373,     0,   715,     0,     0,     0,     0,     0,
       0,   671,   673,   674,   710,   711,   712,   714,   713,     0,
       0,   687,   686,     0,   690,   694,   708,   706,   705,   698,
     702,     0,     0,     0,     0,     0,     0,     0,     0,   584,
     586,   585,   582,   399,   506,   508,   133,   132,    91,   105,
     756,   737,     0,   761,     0,   761,   750,   745,   147,   149,
       0,     0,     0,   117,   145,     0,    27,     0,   630,   631,
     634,   627,   628,   260,     0,     0,   274,   266,     0,   270,
       0,   264,     0,     0,     0,   283,     0,     0,     0,   242,
     286,   289,     0,   137,     0,     0,    70,     0,    64,   280,
       0,     0,   326,   328,   333,     0,   331,     0,     0,     0,
       0,     0,   337,     0,     0,   351,     0,     0,   344,     0,
       0,   348,   423,     0,   623,   621,   198,   791,     0,     0,
     529,     0,     0,   561,     0,   529,     0,   525,     0,    14,
       0,     0,     0,     0,     0,     0,     0,   662,     0,     0,
       0,     0,     0,     0,   666,   670,   322,   320,   321,   314,
     315,   316,   308,     0,     0,   304,   297,   700,   691,   697,
       0,     0,   770,   771,   781,   780,   779,     0,     0,     0,
       0,   772,   677,   778,     0,   675,   679,     0,     0,   684,
     688,     0,   709,   704,   707,   703,     0,     0,   594,     0,
     589,   641,   583,   801,   800,   799,   590,   757,     0,     0,
     755,   762,   763,   759,     0,   754,     0,   752,     0,     0,
       0,     0,     0,     0,   571,   263,     0,   272,     0,     0,
     268,     0,   271,   284,   292,   293,   287,   241,     0,     0,
       0,    66,   282,   577,     0,     0,   334,   338,   332,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   573,     0,     0,   529,     0,   556,     0,   529,   579,
     646,   647,   651,   652,     0,   658,   798,   660,     0,     0,
       0,     0,   667,   317,   298,     0,   695,   782,     0,     0,
     774,     0,   720,   719,   718,   717,   716,   681,     0,   773,
       0,   638,     0,     0,   766,   765,   764,     0,   758,   751,
     749,     0,   746,   747,   741,   150,   152,   154,     0,     0,
       0,     0,     0,   267,   265,     0,   273,     0,   207,   353,
      72,   329,   335,     0,   349,   345,   352,     0,     0,     0,
     339,     0,     0,   341,     0,   539,   533,   528,     0,   529,
     519,     0,   794,     0,     0,     0,     0,   301,   299,   776,
     775,     0,     0,   639,   595,     0,   760,   753,     0,     0,
     156,   155,     0,     0,     0,     0,   151,   269,     0,     0,
       0,     0,     0,     0,   547,   541,     0,   540,   542,   548,
     545,   535,     0,   534,   536,   546,   521,     0,   522,     0,
       0,   668,   300,   777,   689,   640,   748,   153,   157,     0,
       0,     0,     0,   291,     0,     0,   342,   340,     0,     0,
     532,   543,   544,   531,   537,   538,   523,     0,   158,     0,
       0,     0,   350,   346,     0,     0,     0,     0,     0,     0,
       0,     0,   160,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1524, -1524,  -222,  -192, -1524,  1215,  1217, -1524,  1208,  -557,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
   -1014, -1524, -1524, -1524, -1524,  -214,  -604, -1524,   740,    13,
   -1524, -1524, -1524, -1524, -1524,   288,   508, -1524, -1524,    -2,
    -154,  1052, -1524,  1043, -1524, -1524,  -651, -1524,   447, -1524,
     249, -1524,  -226,  -271, -1524,  -566, -1524,    -4,     9,    71,
    -291,  -174, -1524,  -880, -1524, -1524,   345, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524,   620, -1524,   -91,
    1246,     0, -1524, -1524, -1524, -1524,   460, -1524, -1524,  -306,
   -1524,    23, -1524,  1044,  -934,  -725,  -713, -1524, -1524,   704,
   -1524, -1524,    25,   233, -1524, -1524, -1524,   119, -1523, -1524,
     375,   120, -1524, -1524,   130, -1326, -1524,   958,   224, -1524,
   -1524,   216, -1031, -1524, -1524,   217, -1524, -1524, -1263, -1250,
   -1524,   213, -1426, -1524, -1524,   862,   863, -1524,  -498,   840,
   -1524, -1524,  -658,   378,  -644,   374,   381, -1524, -1524, -1524,
     583, -1524, -1524,  1183, -1524, -1524, -1524, -1524, -1524,  -874,
    -332,  -683, -1524,   -98, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524,   -50,  -823, -1524,  -544,   662,   228, -1524,  -411, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524,   810, -1524, -1524, -1524,
   -1524, -1028, -1524,   200, -1524,   691,  -799, -1524, -1524, -1524,
   -1524, -1524,  -258,  -251, -1229,  -992, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524,  -762,  -885,  -166,
    -856, -1524, -1524, -1524,  -846, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524,  1075,  1080,  -196,   507,   340, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524, -1524,
     178, -1524, -1524,   170, -1524,   172, -1066, -1524, -1524, -1524,
     137,   128,   -37,   400, -1524, -1524, -1524, -1524, -1524, -1524,
   -1524, -1524, -1524, -1524, -1524, -1524, -1524,   143, -1524, -1524,
   -1524,   -33,   398,   544, -1524, -1524, -1524, -1524, -1524,   336,
   -1524, -1524, -1445, -1524, -1524, -1524,  -530, -1524,   105, -1524,
     -52, -1524, -1524, -1524, -1524, -1320, -1524,   153, -1524, -1524,
   -1524, -1524, -1524,   959, -1524, -1524, -1524, -1524, -1524,  -933,
    -390,   933,   258, -1524
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   258,   637,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
    1276,   787,   276,   277,   278,   279,   280,   281,   967,   968,
     969,   282,   283,   284,   973,   974,   975,   285,   449,   286,
     287,   715,   288,   451,   452,   453,   468,   777,   778,   289,
    1227,   290,  1705,  1706,   291,   292,   293,   560,   294,   295,
     296,   297,   298,   780,   299,   300,   542,   301,   302,   303,
     304,   305,   306,   647,   307,   308,   872,   873,   309,   310,
     311,   572,   313,   648,   466,  1034,  1035,   314,   649,   315,
     651,   573,   317,   767,   768,  1264,   475,   318,   476,   477,
     774,  1265,  1266,  1267,   652,   653,  1134,  1135,  1384,   654,
    1130,  1131,  1377,  1378,  1379,  1380,   319,   800,   801,   320,
    1291,  1292,  1497,   321,  1294,  1295,   322,   323,  1297,  1298,
    1299,  1300,  1504,   324,   325,   326,   327,   913,   328,   329,
    1391,   330,   331,   332,   333,   334,   335,   336,   337,   338,
    1171,   339,   340,   341,   342,   672,   673,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   707,   702,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   944,   370,   371,   372,
     373,   374,   375,  1327,   833,   834,   835,  1737,  1782,  1783,
    1776,  1777,  1784,  1778,  1328,  1329,   376,   377,  1330,   378,
     379,   380,   381,   382,   383,   384,   385,  1029,  1505,  1432,
    1161,  1589,  1162,  1172,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   807,  1240,   398,  1164,
    1165,  1166,  1167,   399,   400,   401,   402,   403,   404,   862,
     863,   405,  1361,  1362,  1672,  1116,  1142,  1401,  1402,  1143,
    1144,  1145,  1146,  1147,  1411,  1579,  1580,  1148,  1414,  1149,
    1560,  1150,  1151,  1419,  1420,  1585,  1583,  1403,  1404,  1405,
    1406,  1685,   744,   994,   995,   996,   997,   998,   999,  1213,
    1609,  1702,  1214,  1607,  1700,  1000,  1445,  1604,  1600,  1601,
    1602,  1001,  1002,  1407,  1415,  1570,  1408,  1566,  1392,   406,
     407,   408,   409,   563,   410,   411,   412,   413,   414,  1168,
    1277,   415,   416,   417
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -868;
  const short int
  xquery_parser::yytable_[] =
  {
       312,   422,   425,   426,   632,   312,   312,   312,   312,   609,
     650,   934,   450,   696,   423,   423,   423,   427,   716,   716,
     921,   571,   575,   316,   891,   893,   538,  1049,   316,   316,
     316,   316,  1293,  1281,  1085,   922,   923,   924,   925,   587,
    1061,   719,   627,  1140,  1027,  1160,  1170,  1508,  1115,   624,
     851,  1519,  1550,  1551,  1075,   858,  1028,   629,   625,  1326,
     885,   889,   892,   894,   616,   617,   625,    11,    12,   883,
     887,  1229,  1387,   625,  1186,   954,   424,   424,   424,   428,
    1645,   784,   788,  1649,  1163,  1163,  1216,   435,  1245,  1023,
    1031,  1217,   758,  1581,  1253,   625,   625,   625,  1527,   589,
    1218,    11,    12,   625,   473,   625,   718,  1219,  1283,  1220,
     759,   312,    13,  1708,  1190,   438,  -169,   625,  1221,   625,
     423,   435,   625,   625,  1163,  1058,  1319,  1320,   625,   822,
     625,   436,   631,   632,   316,   634,  1250,   632,   592,  1247,
     593,   949,   625,   775,  1498,  1222,   625,  1363,  1024,   438,
    1025,  1747,  1270,   750,   439,  1025,   611,   613,  1228,   909,
    1091,   910,   911,  1703,   912,   636,   914,  1646,   431,   432,
     457,   433,   434,   636,   915,   916,   838,   886,  1163,  1562,
    1025,   709,   561,   621,  1196,  1197,   440,   441,  1125,   437,
     785,  1163,   710,    82,   983,   676,   984,   758,  1567,   622,
    1472,  1026,   636,  1364,   633,  1059,  1254,    93,   625,  1121,
     636,   776,   677,   625,  1193,   759,  1563,   635,  1092,  1709,
     950,  1321,   625,  1673,   636,  1792,   636,   594,   718,  1499,
     636,  1464,   107,   625,  1647,   625,  1137,   786,   474,  1138,
     985,  1322,   625,  1323,  1108,  1368,   625,  -170,   625,   636,
     697,  1032,  1393,   636,  1102,   625,   312,   312,   474,   128,
     312,   474,   626,  1501,  1140,  1140,  1488,   650,  1258,  1508,
     632,  1324,  1223,   625,  1269,   114,   891,   893,  1393,   316,
     316,   831,   590,   316,  1316,   628,   878,  1701,  1033,  1041,
    1326,   126,   443,  1527,   880,   312,   631,  1769,  1423,  1326,
    -169,  1710,  1229,   703,  1255,  1187,   705,  1437,  1163,  1063,
    1463,  1122,  1325,  1796,  1251,   636,  1256,  1124,   316,  1367,
     636,   883,   887,  1559,  1394,   474,   474,   751,  1064,   636,
     153,   474,  1112,   633,   539,   752,  1284,   633,   625,   760,
     636,  1139,   636,   839,  1805,  1093,  1808,   980,   539,   636,
    1394,   444,  1678,   636,   904,   636,   625,  1568,  1569,   783,
     625,   446,   636,   429,  1224,  1225,  1226,   625,   763,   447,
     875,  1109,   539,   595,   821,   596,   874,   448,   781,  1058,
     636,  1760,   949,   625,   539,  1097,   539,  1483,   794,  1228,
     986,   454,   445,   625,  1312,   805,   806,  1046,   625,  1313,
     822,   879,   881,   987,   812,   988,   829,  1395,  1396,  1018,
    1397,   896,   884,   888,   598,  1136,   989,   990,   991,  1314,
     992,  1743,   993,   877,   312,  1017,  1163,  1399,   312,  1498,
    1679,  -170,  1744,  1395,  1396,  1798,  1397,  1319,  1320,  1400,
    1025,  1745,   625,  1398,  1086,   636,  1024,   316,    11,    12,
    1163,   316,   625,  1399,   488,   312,  1053,   312,   695,  1077,
     625,   951,   597,   636,   755,  1400,   757,   636,  1094,  1095,
     633,   734,  1453,   735,   636,   430,   823,  1498,   316,   676,
     316,   128,  1790,  1096,   312,  1101,   836,   837,  1019,   312,
     636,  1618,  1020,   803,  1326,  1038,   677,   841,   809,  1060,
     636,  1070,   483,   599,  1735,   636,  1141,   316,  1098,  1099,
    1087,   734,   316,   735,  1635,  1140,   868,   870,   891,   893,
     891,  1465,  1176,  1100,  1140,  1774,   428,   455,   428,  1319,
     456,   489,  1321,   737,   630,  1140,  1588,  1115,  1180,  1069,
    1508,  1545,  1473,  1088,   639,  1072,   736,  1450,   640,   636,
    1089,  1177,  1322,   641,  1323,   428,  1369,  1370,  1371,   636,
     428,   312,  1640,  1349,   600,  1319,  1090,   636,   312,   601,
    1319,  1021,   642,   737,  1039,  1163,  1114,   423,   632,  1177,
    1071,  1175,  1324,  1598,   316,  1780,   114,  1194,  1195,  1682,
    1780,   316,  1198,  1736,   738,  1104,  1683,    13,   490,   491,
     937,   938,   126,  1774,   936,  1126,  1684,  1319,   312,   939,
    1734,   539,  1442,   458,   539,   312,  1720,  1317,  1024,   450,
    1554,  1692,  1237,  1521,  1073,  1557,   312,   312,   312,   312,
    1178,   316,  1697,   639,   738,  1791,  1024,   640,   316,   424,
     724,   153,   641,  1794,  1322,   312,  1323,  1599,   728,   316,
     316,   316,   316,   602,  1775,   700,   725,   706,  1179,  1429,
    1163,   642,  1123,  1163,  1119,   700,   881,   706,   316,  1210,
     643,  1257,  1444,   644,  1324,   494,  1290,  1647,    82,   869,
    1322,   729,  1323,  1318,  1048,  1322,  1211,  1323,   645,  1495,
    1430,  1781,    93,   726,   539,  1374,  1814,   539,   683,  1671,
    1693,   539,   492,  1140,   539,   539,   495,   684,  1431,   496,
    1324,  1698,   539,  1501,   646,  1324,  1376,   107,   539,   539,
     467,  1653,  1322,   539,  1323,  1260,  1657,  1141,  1141,  1212,
    1261,   539,  1811,  1080,  1081,  1082,    13,   870,   539,   539,
     539,   539,  1574,  1779,  1785,  1619,   539,  1536,  1290,  1262,
    1319,  1320,  1324,   970,   539,  1364,    11,    12,  1726,   643,
     685,  1500,   644,   891,   679,  1024,   431,   432,  1025,   433,
     434,  1642,  1613,   469,   686,  1040,   435,   830,  1113,   312,
     886,  1024,   461,   676,   462,  1779,   436,   437,   423,  1260,
    1263,  1785,  1728,   680,  1261,  1643,   971,  1163,  1442,   539,
     677,   972,   316,   646,   438,  1753,   681,  1754,   696,   439,
     312,   312,  1120,  1074,   539,  1443,  1643,    82,   478,  1067,
    1068,  1357,  1239,   678,  1242,   539,   639,  1732,   622,  1553,
     640,    93,  1025,   316,   316,   641,  1319,  1320,  1547,  1548,
     682,   440,   441,   442,  1163,  1321,  1163,   676,   463,  1389,
     424,  1643,   852,   464,   642,  1738,   107,   852,  1444,  1741,
    1137,   539,   470,  1138,   677,  1322,   720,  1323,   481,   312,
    1795,   471,   128,  1373,  1305,  1204,  1306,  1163,   482,  1804,
     721,   428,   428,   128,  1374,  1486,  1205,  1751,   450,  1824,
     443,   896,   316,   657,  1375,  1324,   312,   881,   472,   114,
     465,   658,   659,  1643,   660,  1376,  1825,  1564,  1210,  1163,
    1680,  1681,   661,  1643,  1565,   126,   662,  1677,   663,   316,
    1416,  1417,  1181,   664,  1163,  1211,  1163,  1707,  1185,   940,
    1643,  1321,   940,   722,  1183,   940,  1526,   486,  1182,   665,
    1787,  1682,  1365,  1418,   779,  1761,  1436,   723,  1683,   444,
    1184,  1322,   643,  1323,   153,   644,  1506,   487,  1684,  1509,
    1506,  1506,   779,   666,   667,   668,   669,   670,   671,  1507,
    1542,  1206,  1510,  1652,  1817,   895,   493,  1024,  1141,   897,
    1188,  1324,  1207,  1484,  1546,   114,  1231,  1141,   956,  1374,
     445,   539,  1188,  1555,   748,  1232,   646,   459,  1141,   749,
     460,   126,  1199,  1200,  1201,   539,   971,  1260,  1202,   539,
     539,   972,  1261,   540,   701,   479,   446,   704,   480,   541,
    1749,  1750,  1655,   555,   447,   484,   698,   699,   485,  1707,
     543,   539,   448,   539,   740,   741,   742,  1333,   544,  1334,
     153,   539,   556,   700,   539,   706,  1386,   576,   539,  1338,
     557,  1339,   558,   650,   919,   920,   577,   926,   927,   580,
     578,   583,  1448,  1449,   579,   312,   928,   929,  1694,  1695,
     584,   585,   586,   588,  1301,  -609,  1707,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   966,   603,   316,   591,
     539,   604,   605,  1793,   606,   607,   608,  1631,   618,   638,
     614,   655,   656,   674,   675,   687,   690,   689,   688,   694,
     700,   708,  1358,   718,   711,   712,   713,   730,   732,   450,
     714,   733,   312,   312,   312,   743,   747,   756,   770,   539,
     771,   773,   779,   782,   790,  1359,   428,   791,   792,   793,
     810,   811,   456,   804,   817,   316,   316,   316,  1835,   460,
    1836,   819,   480,   821,   485,   496,   824,   825,   539,   832,
    1844,   828,   840,   826,   842,   843,  1141,   865,   860,   861,
     866,   871,   882,   900,   917,   930,   901,   931,   945,   932,
     902,   903,   609,   933,   946,   952,   953,   955,   539,   539,
     539,   539,   981,   977,   978,   982,  1004,  1003,  1005,  1007,
    1009,  1012,  1013,  1014,  1015,  1022,  1037,  1016,  1637,  1043,
    1044,  1047,  1054,  1055,  1056,  1057,  1103,  1065,  1105,  1062,
    1066,   455,  1110,   459,  1107,   479,   484,   495,   539,  1111,
    1121,  1128,  1189,   972,  1457,  1024,  1208,  1235,   312,  1106,
    1238,  1246,   539,  1209,  1236,  1248,  1118,   423,  1230,   775,
    1252,   904,  1275,  1272,  1278,  1274,  1279,  1280,  1273,  1285,
    1286,   316,  1290,  1289,  1296,  1308,  1309,   539,  1311,  1302,
    1259,  1303,  1304,  1315,   312,  1332,   539,  1383,   539,  1331,
     539,  1491,   539,  1350,   736,   312,  1360,  1381,  1385,  1410,
    1413,  1421,  1433,  1422,   423,   539,  1409,   316,    13,  1441,
    1513,  1424,  1446,  1458,   312,  1425,  1426,  1390,   316,   424,
    1427,  1428,  1460,   423,  1468,  1459,  1455,  1456,  1461,  1470,
    1462,  1474,  1476,  1440,   312,  1482,  1477,   316,   539,  1451,
     539,   312,  1478,  1524,  1487,  1490,  1512,  1718,  1514,  1523,
    1528,  1518,  1515,  1506,  1520,  1534,  1452,   316,  1722,  1637,
    1530,  1724,  1529,  1531,   316,  1539,   424,   562,  1538,  1733,
    1540,  1374,  1532,  1358,  1363,   852,  1541,  1577,  1558,   727,
    1533,  1584,   731,  1578,  1590,   424,   739,  1591,  1582,   745,
     746,  1592,  1593,  1594,  1597,  1603,  1359,   754,  1561,  1571,
     539,  1608,  1595,   766,   769,   428,  1535,  1610,   769,  1596,
    1614,  1616,   428,  1621,  1628,  1629,   789,  1612,  1630,  1633,
    1634,  1664,   539,   797,   798,   799,   802,  1639,  1650,  1651,
    1656,   808,  1675,  1659,  1676,  1688,  1690,  1606,  1691,   815,
    1699,  1210,  1712,  1715,   869,  1717,  1704,  1723,  1755,  1756,
    1740,  1724,  1757,  1758,  1759,  1763,  1764,  1768,  1668,  1669,
    1670,  1689,  1770,  1771,  1772,  1711,  1786,  1788,  1801,  1789,
    1809,  1810,  1802,  1813,  1821,  1826,  1841,  1816,  1827,  1840,
    1834,   623,  1837,  1838,   816,   619,   979,   620,  1439,  1191,
    1806,  1799,   717,  1819,  1454,  1271,  1766,  1828,  1797,   802,
    1831,  1833,  1117,   753,  1843,  1268,  1052,  1481,  1484,   312,
     827,  1552,   539,  1372,  1556,  1626,   539,  1496,  1549,   772,
    1492,  1502,  1511,  1822,   818,   918,  1174,   907,  1522,   908,
     948,   539,   316,   693,  1084,  1815,  1812,  1243,  1537,  1438,
     539,  1544,  1543,   761,  1822,  1572,   864,  1576,   762,  1388,
    1687,  1686,  1358,  1806,   539,  1575,  1412,  1215,  1447,  1696,
    1605,     0,  1573,     0,   539,     0,   856,     0,     0,     0,
       0,     0,     0,     0,     0,  1359,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1746,     0,     0,   539,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1752,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   539,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   539,     0,
       0,     0,   539,     0,     0,     0,     0,     0,  1358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1358,
    1358,     0,   312,     0,     0,     0,     0,     0,     0,     0,
    1358,  1359,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1359,  1359,     0,   316,   976,     0,     0,     0,
       0,     0,     0,  1359,     0,     0,     0,     0,     0,   539,
    1006,     0,     0,     0,  1010,  1011,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1030,     0,  1036,   539,
       0,     0,     0,     0,     0,     0,  1042,     0,     0,  1045,
       0,     0,     0,  1050,     0,     0,     0,     0,     0,     0,
       0,     0,  1358,     0,     0,   539,   539,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1359,     0,     0,     0,     0,
       0,   539,     0,     0,   539,  1083,     0,   539,     0,     0,
       0,   312,     0,     0,     0,     0,     0,     0,     0,   539,
       0,     0,     0,     0,   539,     0,     0,     0,     0,  1358,
       0,     0,     0,     0,   316,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   312,     0,     0,     0,     0,     0,
       0,     0,  1359,     0,   562,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1358,     0,   316,     0,     0,
       0,     0,     0,  1127,  1358,     0,     0,     0,   844,   845,
       0,   853,   854,   855,   857,     0,   859,     0,  1359,     0,
       0,     0,   867,     0,     0,     0,     0,  1359,     0,     0,
     876,     0,     0,  1169,  1169,  1173,  1173,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   898,   899,     0,     0,     0,     0,     0,     0,
       0,   905,   906,     0,     0,     0,     0,     0,     0,     0,
       0,   539,   539,  1169,   539,     0,   539,     0,     0,     0,
       0,     0,     0,   539,     0,     0,     0,  1203,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1234,     0,     0,     0,     0,     0,   539,     0,
     539,  1241,   943,  1241,     0,   769,   943,  1169,     0,     0,
       0,     0,     0,     0,     0,     0,   539,     0,     0,   539,
    1169,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   539,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   539,     0,     0,  1008,     0,     0,     0,     0,
       0,     0,     0,   808,     0,   808,     0,     0,     0,     0,
       0,     0,     0,   539,     0,     0,     0,     0,     0,     0,
       0,   539,     0,     0,     0,     0,   539,     0,   539,     0,
     539,     0,     0,     0,     0,     0,     0,  1051,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   539,
       0,     0,     0,  1076,     0,  1382,     0,  1078,  1079,     0,
       0,     0,     0,     0,     0,     0,   905,     0,     0,   539,
       0,     0,     0,     0,   539,     0,     0,  1169,     0,     0,
       0,     0,     0,     0,     0,     0,   539,     0,     0,   539,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   899,     0,     0,     0,     0,     0,  1129,  1133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   769,     0,     0,
       0,  1466,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1480,     0,     0,     0,
       0,     0,     0,     0,     0,  1169,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1192,   802,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1169,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1233,     0,     0,     0,     0,  1525,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1249,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   864,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1282,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1287,  1288,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1307,     0,     0,  1310,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1335,  1336,  1337,     0,  1340,  1341,  1342,  1343,  1344,  1345,
    1346,  1347,  1348,     0,  1169,  1351,  1352,     0,     0,     0,
       0,     0,     0,     0,  1366,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1611,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1624,  1625,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1435,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1641,     0,     0,  1169,
       0,     0,  1169,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1654,     0,     0,     0,     0,  1658,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1467,     0,  1469,     0,
    1471,     0,     0,  1475,     0,     0,     0,     0,  1479,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1485,     0,     0,     0,     0,     0,     0,     0,     0,  1489,
       0,     0,     0,     0,     0,  1493,  1494,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1516,     0,     0,  1517,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1169,  1727,     0,  1729,
       0,  1731,     0,     0,     0,     0,     0,     0,  1739,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1169,     0,  1169,     0,  1129,     0,     0,
       0,  1133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1762,     0,     0,  1765,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1169,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1773,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1169,     0,
       0,     0,     0,     0,     0,     0,  1800,     0,     0,     0,
       0,  1803,     0,  1169,     0,  1169,     0,     0,     0,     0,
    1615,     0,     0,     0,  1617,     0,     0,     0,  1620,     0,
    1622,     0,  1623,     0,     0,     0,     0,     0,  1627,     0,
       0,     0,     0,     0,  1820,     0,  1632,     0,     0,     0,
       0,     0,     0,     0,  1636,  1638,     0,     0,     0,     0,
       0,     0,     0,     0,  1829,     0,     0,     0,     0,  1830,
       0,     0,     0,     0,  1485,     0,     0,     0,     0,     0,
       0,  1839,     0,     0,  1842,     0,  1660,  1661,  1662,  1663,
       0,  1665,  1666,     0,  1667,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1674,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1713,     0,  1714,     0,     0,  1716,     0,     0,
       0,     0,     0,     0,     0,  1719,     0,     0,     0,     0,
    1721,  1638,     0,     0,     0,     0,     0,     0,  1725,     0,
       0,     0,     0,  1730,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1742,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1748,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1767,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1725,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1807,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1818,     0,     0,     0,     0,
    1823,     0,     0,     0,     0,  1807,  -165,   886,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     0,
    1823,     0,     3,     0,  1832,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,    13,     0,     0,    14,
     419,     0,    16,    17,    18,    19,    20,    21,    22,    23,
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
       0,   421,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,     0,   197,   198,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,     0,   248,     0,
     249,   250,   251,   252,   253,   254,   255,  -165,   886,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     890,   419,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   420,    30,    31,    32,
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
     153,     0,   421,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   886,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,     0,     0,
     418,   419,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,   420,    30,    31,    32,
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
     153,     0,   421,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   886,   248,
       0,   249,   250,   251,   252,   253,   254,   255,     1,     2,
       0,     0,     0,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,    13,     0,     0,
     418,   419,     0,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   564,   420,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     0,    48,    49,    50,
     565,   566,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,    72,    73,    74,    75,    76,     0,    77,    78,
      79,     0,     0,    80,    81,     0,     0,     0,    82,    83,
     514,    85,    86,    87,    88,    89,   567,    91,    92,     0,
       0,     0,    93,     0,    94,    95,    96,    97,     0,    98,
       0,     0,     0,    99,   100,   101,   102,   103,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,   568,   112,     0,   113,   114,   115,   116,   117,     0,
       0,     0,   118,   119,   120,   121,   122,   123,   124,   125,
       0,   126,     0,   127,   128,     0,     0,   129,   130,   131,
       0,     0,     0,   132,     0,   133,   134,     0,   136,   137,
       0,   138,     0,   139,     0,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,     0,     0,   151,   152,
     153,     0,   421,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   532,   533,   534,   180,   181,
     535,   570,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,   197,   198,   199,     0,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,     0,   248,
       0,   249,   250,   251,   252,   253,   254,   255,  -867,   461,
       0,   462,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -867,     0,     0,     0,  -867,     0,     0,     0,  -867,  -867,
       0,     0,     0,     0,  -867,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   463,     0,     0,  -867,     0,
     464,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -867,     0,  -867,  -867,  -867,     0,     0,  -867,  -867,
    -867,  -867,     0,     0,     0,  -867,  -867,     0,     0,     0,
       0,     0,  -867,     0,     0,  -867,  -867,   465,     0,     0,
    -867,     0,     0,     0,     0,  -867,  -867,     0,     0,     0,
       0,  -867,     0,     0,     0,  -867,     0,     0,     0,  -867,
    -867,     0,  -867,     0,  -867,  -867,     0,     0,     0,  -867,
    -867,     0,     0,  -867,  -867,  -867,  -867,  -867,  -867,     0,
       0,  -867,     0,     0,     0,  -867,  -867,     0,     0,  -867,
       0,     0,     0,     0,  -867,     0,     0,  -867,     0,     0,
       0,     0,  -867,  -867,  -867,  -867,  -867,     0,  -867,  -867,
    -867,  -867,  -867,     0,     0,     0,     0,  -867,  -867,  -867,
       0,  -867,  -867,  -867,  -867,  -867,  -867,     0,  -867,     0,
    -867,     0,     0,     0,     0,  -867,  -867,  -867,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -867,     0,  -867,     0,  -867,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -867,     0,     0,
       0,     0,  -867,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     0,     0,     0,     3,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,  -867,
      13,  -867,     0,    14,    15,     0,    16,    17,    18,    19,
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
     255,   256,   257,     1,     2,     0,     0,     0,     3,     0,
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
     133,   134,   135,   136,   137,     0,   138,     0,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,     0,     0,   151,   152,   153,     0,   154,   155,   156,
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
     253,   254,   255,     0,   615,     1,     2,     0,     0,     0,
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
     127,   128,     0,     0,   129,   130,   131,     0,   559,     0,
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
     243,   244,   245,   246,   247,     0,   248,     0,   249,   250,
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
     127,   128,     0,     0,   129,   130,   131,     0,   820,     0,
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
     243,   244,   245,   246,   247,     0,   248,     0,   249,   250,
     251,   252,   253,   254,   255,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,   418,   419,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,  1353,   420,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,  1354,  1355,    53,
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
     127,   128,     0,     0,   129,   130,   131,     0,   559,     0,
     132,     0,   133,   134,   135,   136,   137,     0,   138,     0,
     139,     0,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,   153,     0,   421,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,  1356,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     0,   248,     0,   249,   250,
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
     243,   244,   245,   246,   247,     0,   248,     0,   249,   250,
     251,   252,   253,   254,   255,     1,     2,     0,     0,     0,
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
     132,     0,   133,   134,   135,   136,   137,     0,   138,     0,
     139,     0,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,   153,     0,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     0,   248,     0,   249,   250,
     251,   252,   253,   254,   255,     1,     2,     0,     0,     0,
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
     243,   244,   245,   246,   247,     0,   248,     0,   249,   250,
     251,   252,   253,   254,   255,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,    14,   419,     0,
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
     243,   244,   245,   246,   247,     0,   248,     0,   249,   250,
     251,   252,   253,   254,   255,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,   890,   419,     0,
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
     243,   244,   245,   246,   247,     0,   248,     0,   249,   250,
     251,   252,   253,   254,   255,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,     0,     0,   418,   419,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,  1353,   420,    30,    31,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     0,    48,    49,    50,  1354,  1355,    53,
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
     175,   176,   177,   178,   179,   180,   181,   182,  1356,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     0,   248,     0,   249,   250,
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
      99,   100,   101,   102,   103,     0,     0,     0,     0,   941,
       0,   104,   105,   106,   107,   108,   109,   110,   568,   112,
       0,   113,   114,   115,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
     127,   128,     0,     0,   129,   130,   131,     0,     0,     0,
     132,   942,   133,   134,     0,   136,   137,     0,   138,     0,
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
      99,   100,   101,   102,   103,     0,     0,     0,     0,   941,
       0,   104,   105,   106,   107,   108,   109,   110,   568,   112,
       0,   113,   114,   115,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
     127,   128,     0,     0,   129,   130,   131,     0,     0,     0,
     132,   947,   133,   134,     0,   136,   137,     0,   138,     0,
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
     127,   128,     0,     0,   129,   130,   131,     0,     0,   569,
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
     132,   574,   133,   134,     0,   136,   137,     0,   138,     0,
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
     243,   244,   245,   246,   247,   610,   248,     0,   249,   250,
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
     243,   244,   245,   246,   247,     0,   248,   612,   249,   250,
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
     127,   128,     0,     0,   129,   130,   131,     0,   935,     0,
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
      99,   100,   101,   102,   103,     0,     0,     0,     0,  1434,
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
     251,   252,   253,   254,   255,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   418,   419,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     500,    27,   502,   420,    30,   503,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   505,     0,    48,    49,    50,   507,   508,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   514,    85,    86,
      87,    88,    89,   567,    91,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     517,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   568,   112,
       0,   113,   114,   691,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
     692,   128,     0,     0,   129,   130,   131,     0,     0,     0,
     132,     0,   133,   134,     0,   136,   137,     0,   138,     0,
     139,     0,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,   153,     0,   421,
     155,   156,   157,   158,   159,   160,   161,   162,   527,   164,
     528,   166,   529,   530,   169,   170,   171,   172,   173,   174,
     531,   176,   532,   533,   534,   180,   181,   535,   536,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     0,   248,     0,   249,   537,
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
     251,   252,   253,   254,   255,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   418,   419,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     500,    27,   502,   420,    30,   503,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   505,     0,    48,    49,    50,   507,   508,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   514,    85,    86,
      87,    88,    89,   567,    91,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     517,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   568,   112,
       0,   113,   114,   115,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
     127,   128,     0,     0,   129,   130,   131,     0,     0,     0,
     132,     0,   133,   134,     0,   136,   137,     0,   138,     0,
     139,     0,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,   153,     0,   421,
     155,   156,   157,   158,   159,   160,   161,   162,   527,   164,
     528,   166,   529,   530,   169,   170,   171,   172,   173,   174,
     531,   176,   532,   533,   534,   180,   181,   535,   536,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     0,   248,     0,   249,   537,
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
      87,    88,    89,  1132,    91,    92,     0,     0,     0,    93,
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
     251,   252,   253,   254,   255,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   418,   419,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     500,    27,   502,   420,    30,   503,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   505,     0,    48,    49,    50,   507,   508,    53,
     509,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   514,    85,    86,
      87,    88,    89,   567,    91,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     517,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   568,   112,
       0,   113,   114,     0,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
       0,     0,     0,     0,   129,   130,   131,     0,     0,     0,
     132,     0,   133,   134,     0,   136,   137,     0,   138,     0,
     139,     0,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,   153,     0,   421,
     155,   156,   157,   158,   159,   160,   161,   162,   527,   164,
     528,   166,   529,   530,   169,   170,   171,   172,   173,   174,
     531,   176,   532,   533,   534,   180,   181,   535,   536,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     0,   248,     0,   249,   537,
     251,   252,   253,   254,   255,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   418,   419,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     500,    27,   502,   420,    30,   503,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   505,     0,    48,    49,    50,   507,   508,    53,
     509,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   514,    85,    86,
      87,    88,    89,   567,    91,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     517,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,   108,   109,   110,   568,   112,
       0,   113,   114,     0,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
       0,     0,     0,     0,   129,   130,   131,     0,     0,     0,
     132,     0,   133,   134,     0,     0,     0,     0,   138,     0,
     139,     0,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,   153,     0,   421,
     155,   156,   157,   158,   159,   160,   161,   162,   527,   164,
     528,   166,   529,   530,   169,   170,   171,   172,   173,   174,
     531,   176,   532,   533,   534,   180,   181,   535,   536,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     0,   248,     0,   249,   537,
     251,   252,   253,   254,   255,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,    13,     0,     0,   418,   419,     0,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     500,    27,   502,   420,    30,   503,    32,    33,    34,     0,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,   505,     0,    48,    49,    50,   507,   508,    53,
     509,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,    72,
      73,    74,    75,    76,     0,    77,    78,    79,     0,     0,
      80,    81,     0,     0,     0,    82,    83,   514,    85,    86,
      87,    88,    89,   567,    91,    92,     0,     0,     0,    93,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     517,     0,   101,   102,   103,     0,     0,     0,     0,     0,
       0,   104,   105,   106,   107,     0,   109,   110,   568,   112,
       0,   113,   114,     0,   116,   117,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,   125,     0,   126,     0,
       0,     0,     0,     0,   129,   130,   131,     0,     0,     0,
     132,     0,   133,   134,     0,     0,     0,     0,   138,     0,
     139,     0,   140,     0,   142,     0,   144,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,   153,     0,   421,
     155,   156,   157,   158,   159,   160,   161,   162,   527,   164,
     528,   166,   529,   530,   169,   170,   171,   172,   173,   174,
     531,   176,   532,   533,   534,   180,   181,   535,   536,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,     0,   248,     0,   249,   537,
     251,   252,   253,   254,   255,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     0,     0,     0,     0,     9,
      10,     0,     0,     0,     0,     0,     0,   418,   419,     0,
      16,    17,    18,   497,    20,    21,    22,   498,    24,   499,
     500,   501,   502,   420,    30,   503,    32,    33,    34,     0,
      35,    36,    37,    38,   504,    40,    41,    42,    43,    44,
      45,    46,   505,     0,    48,   506,    50,   507,   508,    53,
     509,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   510,   511,    71,     0,    72,
      73,    74,   512,     0,     0,    77,    78,    79,     0,     0,
     513,    81,     0,     0,     0,     0,    83,   514,    85,   515,
     516,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,     0,    98,     0,     0,     0,
     517,   100,   101,   518,   519,     0,     0,     0,     0,     0,
       0,   104,   105,   106,     0,   108,   109,   110,     0,     0,
       0,     0,     0,     0,   116,   520,     0,     0,     0,   118,
     119,   120,   121,   521,   123,   124,   522,     0,     0,     0,
       0,     0,     0,     0,   523,   524,   131,     0,     0,     0,
     132,     0,   133,   525,     0,     0,     0,     0,   138,     0,
     139,     0,   140,   141,   142,   143,   526,   145,   146,   147,
     148,   149,   150,     0,     0,   151,   152,     0,     0,   421,
     155,   156,   157,   158,   159,   160,   161,   162,   527,   164,
     528,   166,   529,   530,   169,   170,   171,   172,   173,   174,
     531,   176,   532,   533,   534,   180,   181,   535,   536,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,     0,   197,   198,   199,     0,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,     0,     0,     0,     0,   249,   537,
     251,   252,   253,   254,   255,     1,     2,     0,     0,     0,
       3,     0,     0,     0,     4,     0,     0,     0,     0,     9,
      10,     0,     0,     0,     0,     0,     0,   418,   419,     0,
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
     132,     0,   133,   525,     0,     0,     0,     0,   138,     0,
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
       0,     0,     0,   418,   419,     0,    16,    17,    18,   497,
      20,    21,    22,   498,    24,   499,   500,  1152,   502,   420,
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
       0,   108,   109,  1153,     0,     0,     0,  1154,     0,     0,
     116,   520,     0,     0,     0,   118,   119,   120,   121,   521,
     123,   124,   522,     0,     0,     0,     0,     0,     0,     0,
     523,   524,   131,     0,     0,     0,   132,  1586,   133,   525,
       0,     0,     0,     0,  1587,     0,   139,     0,   140,   141,
     142,   143,   526,   145,   146,   147,   148,   149,   150,     0,
       0,  1155,   152,     0,     0,   421,   155,   156,   157,   158,
     159,   160,   161,   162,   527,   164,   528,   166,   529,   530,
     169,   170,   171,   172,   173,   174,   531,   176,   532,   533,
     534,   180,   181,   535,   536,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,     0,   197,
     198,   199,     0,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
       0,     0,     0,     0,   249,   537,   251,  1156,  1157,  1158,
    1159,     3,     0,   581,   582,     0,     0,     0,     0,     0,
       9,    10,     0,     0,     0,     0,     0,     0,   418,   419,
       0,    16,    17,    18,   545,    20,    21,    22,   498,   546,
     547,   500,   501,   502,   420,    30,   503,    32,   548,    34,
       0,    35,    36,    37,    38,   549,    40,   550,   551,    43,
      44,    45,    46,   505,     0,    48,   552,    50,   507,   508,
      53,   509,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   510,   511,    71,     0,
      72,    73,    74,   553,     0,     0,    77,    78,    79,     0,
       0,   513,    81,     0,     0,     0,     0,    83,   514,    85,
     515,   516,    88,    89,     0,     0,     0,     0,     0,     0,
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
       0,   523,   524,   131,     0,     0,     0,   132,   764,   133,
     525,     0,     0,     0,     0,   765,     0,   139,     0,   140,
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
     254,   255,     9,    10,     0,     0,     0,   795,     0,     0,
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
       0,     0,     0,   132,   796,   133,   525,     0,     0,     0,
       0,     0,     0,   139,     0,   140,   141,   142,   143,   526,
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
       0,     0,     0,     0,     0,     0,   418,   419,     0,    16,
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
     813,   133,   525,     0,     0,     0,     0,   814,     0,   139,
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
       0,     0,   418,   419,     0,    16,    17,    18,   497,    20,
      21,    22,   498,    24,   499,   500,  1152,   502,   420,    30,
     503,    32,    33,    34,     0,    35,    36,    37,    38,   504,
      40,    41,    42,    43,    44,    45,    46,   505,     0,    48,
     506,    50,   507,   508,    53,   509,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     510,   511,    71,     0,    72,    73,    74,   512,     0,     0,
      77,    78,    79,     0,     0,   513,    81,     0,     0,     0,
       0,    83,   514,    85,   515,   516,    88,    89,  1503,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   517,   100,   101,   518,   519,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,  1153,     0,     0,     0,  1154,     0,     0,   116,
     520,     0,     0,     0,   118,   119,   120,   121,   521,   123,
     124,   522,     0,     0,     0,     0,     0,     0,     0,   523,
     524,   131,     0,     0,     0,   132,     0,   133,   525,     0,
       0,     0,     0,     0,     0,   139,     0,   140,   141,   142,
     143,   526,   145,   146,   147,   148,   149,   150,     0,     0,
    1155,   152,     0,     0,   421,   155,   156,   157,   158,   159,
     160,   161,   162,   527,   164,   528,   166,   529,   530,   169,
     170,   171,   172,   173,   174,   531,   176,   532,   533,   534,
     180,   181,   535,   536,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,     0,   197,   198,
     199,     0,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,     0,
       0,     3,     0,   249,   537,   251,  1156,  1157,  1158,  1159,
       9,    10,     0,     0,     0,     0,     0,     0,   418,   419,
       0,    16,    17,    18,   497,    20,    21,    22,   498,    24,
     499,   500,  1152,   502,   420,    30,   503,    32,    33,    34,
       0,    35,    36,    37,    38,   504,    40,    41,    42,    43,
      44,    45,    46,   505,     0,    48,   506,    50,   507,   508,
      53,   509,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   510,   511,    71,     0,
      72,    73,    74,   512,     0,     0,    77,    78,    79,     0,
       0,   513,    81,     0,     0,     0,     0,    83,   514,    85,
     515,   516,    88,    89,  1644,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   517,   100,   101,   518,   519,     0,     0,     0,     0,
       0,     0,   104,   105,   106,     0,   108,   109,  1153,     0,
       0,     0,  1154,     0,     0,   116,   520,     0,     0,     0,
     118,   119,   120,   121,   521,   123,   124,   522,     0,     0,
       0,     0,     0,     0,     0,   523,   524,   131,     0,     0,
       0,   132,     0,   133,   525,     0,     0,     0,     0,     0,
       0,   139,     0,   140,   141,   142,   143,   526,   145,   146,
     147,   148,   149,   150,     0,     0,  1155,   152,     0,     0,
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
     537,   251,  1156,  1157,  1158,  1159,     9,    10,     0,     0,
       0,     0,     0,     0,   418,   419,     0,    16,    17,    18,
     497,    20,    21,    22,   498,    24,   499,   500,  1152,   502,
     420,    30,   503,    32,    33,    34,     0,    35,    36,    37,
      38,   504,    40,    41,    42,    43,    44,    45,    46,   505,
       0,    48,   506,    50,   507,   508,    53,   509,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   510,   511,    71,     0,    72,    73,    74,   512,
       0,     0,    77,    78,    79,     0,     0,   513,    81,     0,
       0,     0,     0,    83,   514,    85,   515,   516,    88,    89,
    1648,     0,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,     0,    98,     0,     0,     0,   517,   100,   101,
     518,   519,     0,     0,     0,     0,     0,     0,   104,   105,
     106,     0,   108,   109,  1153,     0,     0,     0,  1154,     0,
       0,   116,   520,     0,     0,     0,   118,   119,   120,   121,
     521,   123,   124,   522,     0,     0,     0,     0,     0,     0,
       0,   523,   524,   131,     0,     0,     0,   132,     0,   133,
     525,     0,     0,     0,     0,     0,     0,   139,     0,   140,
     141,   142,   143,   526,   145,   146,   147,   148,   149,   150,
       0,     0,  1155,   152,     0,     0,   421,   155,   156,   157,
     158,   159,   160,   161,   162,   527,   164,   528,   166,   529,
     530,   169,   170,   171,   172,   173,   174,   531,   176,   532,
     533,   534,   180,   181,   535,   536,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,     0,
     197,   198,   199,     0,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,     0,     0,     3,     0,   249,   537,   251,  1156,  1157,
    1158,  1159,     9,    10,     0,     0,     0,     0,     0,     0,
     418,   419,     0,    16,    17,    18,   497,    20,    21,    22,
     498,    24,   499,   500,  1152,   502,   420,    30,   503,    32,
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
    1153,     0,     0,     0,  1154,     0,     0,   116,   520,     0,
       0,     0,   118,   119,   120,   121,   521,   123,   124,   522,
       0,     0,     0,     0,     0,     0,     0,   523,   524,   131,
       0,     0,     0,   132,     0,   133,   525,     0,     0,     0,
       0,     0,     0,   139,     0,   140,   141,   142,   143,   526,
     145,   146,   147,   148,   149,   150,     0,     0,  1155,   152,
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
       0,   249,   537,   251,  1156,  1157,  1158,  1159,     9,    10,
       0,     0,     0,     0,     0,     0,   418,   419,     0,    16,
      17,    18,   497,    20,    21,    22,   498,    24,   499,   500,
    1152,   502,   420,    30,   503,    32,    33,    34,     0,    35,
      36,    37,    38,   504,    40,    41,    42,    43,    44,    45,
      46,   505,     0,    48,   506,    50,   507,   508,    53,   509,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   510,   511,    71,     0,    72,    73,
      74,   512,     0,     0,    77,    78,    79,     0,     0,   513,
      81,     0,     0,     0,     0,    83,   514,    85,   515,   516,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   517,
     100,   101,   518,   519,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,  1153,     0,     0,     0,
    1154,     0,     0,   116,   520,     0,     0,     0,   118,   119,
     120,   121,   521,   123,   124,   522,     0,     0,     0,     0,
       0,     0,     0,   523,   524,   131,     0,     0,     0,   132,
       0,   133,   525,     0,     0,     0,     0,     0,     0,   139,
       0,   140,   141,   142,   143,   526,   145,   146,   147,   148,
     149,   150,     0,     0,   151,   152,     0,     0,   421,   155,
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
    1156,  1157,  1158,  1159,     9,    10,     0,     0,     0,     0,
       0,     0,   418,   419,     0,    16,    17,    18,   545,    20,
      21,    22,   498,   546,   547,   500,   501,   502,   420,    30,
     503,    32,   548,    34,     0,    35,    36,    37,    38,   549,
      40,   550,   551,    43,    44,    45,    46,   505,     0,    48,
     552,    50,   507,   508,    53,   509,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
     510,   511,    71,     0,    72,    73,    74,   553,     0,     0,
      77,    78,    79,     0,     0,   513,    81,     0,     0,     0,
       0,    83,   514,    85,   515,   516,    88,    89,  1244,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,    98,     0,     0,     0,   517,   100,   101,   518,   519,
       0,     0,     0,     0,     0,     0,   104,   105,   106,     0,
     108,   109,   110,     0,     0,     0,     0,     0,     0,   116,
     520,     0,     0,     0,   118,   119,   120,   121,   521,   123,
     124,   522,     0,     0,     0,     0,     0,     0,     0,   523,
     524,   131,     0,     0,     0,   132,     0,   133,   525,     0,
       0,     0,     0,     0,     0,   139,     0,   140,   141,   142,
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
       0,    16,    17,    18,   545,    20,    21,    22,   498,   546,
     547,   500,   501,   502,   420,    30,   503,    32,   548,    34,
       0,    35,    36,    37,    38,   549,    40,   550,   551,    43,
      44,    45,    46,   505,     0,    48,   552,    50,   507,   508,
      53,   509,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   510,   511,    71,     0,
      72,    73,    74,   553,     0,     0,    77,    78,    79,     0,
       0,   513,    81,     0,     0,     0,     0,    83,   514,    85,
     515,   516,    88,    89,     0,     0,     0,     0,     0,     0,
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
     242,   243,   244,   245,   246,     0,     0,     0,     0,   249,
     537,   251,   252,   253,   254,   255,     5,     6,     7,     8,
       9,    10,     0,     0,     0,    13,     0,     0,   418,   419,
       0,    16,    17,    18,   846,    20,    21,    22,    23,     0,
     847,   500,    27,     0,   420,    30,   503,    32,     0,    34,
       0,    35,    36,    37,    38,   848,    40,     0,     0,    43,
      44,    45,    46,   505,     0,    48,   849,    50,     0,     0,
      53,   509,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   510,   511,    71,     0,
      72,    73,    74,   850,     0,     0,    77,    78,    79,     0,
       0,   513,    81,     0,     0,     0,    82,    83,   514,    85,
     515,   516,    88,    89,   567,    91,     0,     0,     0,     0,
      93,     0,    94,    95,    96,    97,     0,    98,     0,     0,
       0,   517,   100,   101,   518,   519,     0,     0,     0,     0,
       0,     0,   104,   105,   106,   107,   108,   109,     0,   568,
     112,     0,   113,   114,     0,   116,   117,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   124,   522,     0,   126,
       0,     0,     0,     0,     0,   523,   524,   131,     0,     0,
       0,   132,     0,   133,   525,     0,     0,     0,     0,     0,
       0,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,     0,     0,     0,   152,   153,     0,
     421,   155,   156,   157,   158,   159,   160,   161,   162,   527,
       0,   528,   166,   529,   530,   169,   170,   171,   172,   173,
     174,   531,   176,   532,   533,   534,   180,   181,     0,   536,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     0,   197,   198,   199,     0,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,     0,   248,     9,    10,
       0,   251,   252,     0,     0,     0,   418,   419,     0,    16,
      17,    18,     0,    20,    21,    22,   498,     0,     0,   500,
     501,     0,   420,    30,   503,    32,     0,    34,     0,    35,
      36,    37,    38,     0,    40,     0,     0,    43,    44,    45,
      46,   505,     0,    48,     0,    50,     0,     0,    53,   509,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,   510,   511,    71,     0,    72,    73,
      74,     0,     0,     0,    77,    78,    79,     0,     0,   513,
      81,     0,     0,     0,     0,    83,   514,    85,   515,   516,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,    98,     0,     0,     0,   517,
     100,   101,   518,   519,     0,     0,     0,     0,     0,     0,
     104,   105,   106,     0,   108,   109,     0,     0,     0,     0,
       0,     0,     0,   116,   520,     0,     0,     0,   118,   119,
     120,   121,   521,   123,   124,   522,     0,     0,     0,     0,
       0,     0,     0,   523,   524,   131,     0,     0,     0,   132,
       0,   133,   525,     0,     0,     0,     0,     0,     0,   139,
       0,   140,   141,   142,   143,   526,   145,   146,   147,   148,
     149,   150,     0,     0,     0,   152,     0,     0,   421,   155,
     156,   157,   158,   159,   160,   161,   162,   527,     0,   528,
     166,   529,   530,   169,   170,   171,   172,   173,   174,   531,
     176,   532,   533,   534,   180,   181,     0,   536,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,     0,   197,   198,   199,     0,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,     0,     0,     0,     0,     0,     0,   251,
     252
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,     5,     6,     7,   295,     5,     6,     7,     8,   183,
     316,   694,    14,   345,     5,     6,     7,     8,   429,   430,
     678,   112,   113,     0,   628,   629,    76,   789,     5,     6,
       7,     8,  1063,  1047,   833,   679,   680,   681,   682,   137,
     802,   431,   264,   917,   769,   930,   931,  1297,   871,   263,
     594,  1314,  1378,  1379,   816,   599,   769,   279,     1,  1087,
     626,   627,   628,   629,   256,   257,     1,    27,    28,   626,
     627,  1004,  1138,     1,   954,   726,     5,     6,     7,     8,
    1506,   471,   472,  1509,   930,   931,    39,    47,  1022,    36,
      56,    44,    45,  1413,    36,     1,     1,     1,  1327,    31,
      53,    27,    28,     1,   119,     1,    30,    60,   143,    62,
      63,   111,    30,   119,   970,    75,     0,     1,    71,     1,
     111,    47,     1,     1,   970,   108,     9,    10,     1,   108,
       1,    57,   286,   424,   111,   108,   148,   428,   225,  1024,
     227,   108,     1,   119,   101,    98,     1,   154,    95,    75,
      97,  1674,  1037,   113,    80,    97,   247,   248,  1004,   657,
     132,   659,   660,  1608,   662,   108,   664,   119,    37,    38,
     154,    40,    41,   108,   672,   673,     8,     1,  1024,   217,
      97,   146,   111,    33,   129,   130,   112,   113,   114,    58,
     114,  1037,   157,   111,    55,   159,    57,    45,    97,    49,
     148,   148,   108,   210,   295,   188,   148,   125,     1,    33,
     108,   187,   176,     1,   976,    63,   254,   190,   190,   225,
     187,   104,     1,  1549,   108,  1748,   108,   314,    30,   186,
     108,   148,   150,     1,   186,     1,   154,   161,   273,   157,
     101,   124,     1,   126,   108,   114,     1,     0,     1,   108,
     348,   217,    97,   108,   233,     1,   256,   257,   273,   177,
     260,   273,   190,  1294,  1138,  1139,  1280,   573,  1030,  1519,
     561,   154,   225,     1,  1036,   158,   880,   881,    97,   256,
     257,   187,   214,   260,  1083,   190,   190,  1607,   254,   187,
    1318,   174,   161,  1522,   190,   295,   450,  1723,  1154,  1327,
     184,   307,  1235,   353,  1029,   956,   356,  1187,  1154,   187,
    1244,   190,   195,  1758,  1027,   108,  1029,   190,   295,   190,
     108,   878,   879,  1389,   169,   273,   273,   287,   187,   108,
     213,   273,   187,   424,    76,   295,  1049,   428,     1,   187,
     108,   259,   108,   175,  1770,    95,  1772,   737,    90,   108,
     169,   220,    52,   108,   645,   108,     1,   256,   257,   161,
       1,   287,   108,   157,   317,   318,   319,     1,   459,   295,
     313,   235,   114,   225,   122,   227,   311,   303,   469,   108,
     108,  1707,   108,     1,   126,    95,   128,  1272,   479,  1235,
     251,   161,   261,     1,   187,   486,   487,   787,     1,   187,
     108,   623,   624,   264,   495,   266,   185,   252,   253,   108,
     255,   633,   626,   627,   225,   913,   277,   278,   279,   187,
     281,   187,   283,   615,   424,   184,  1272,   272,   428,   101,
     130,   184,   187,   252,   253,  1761,   255,     9,    10,   284,
      97,   187,     1,   262,   131,   108,    95,   424,    27,    28,
    1296,   428,     1,   272,    77,   455,   184,   457,   154,   188,
       1,   187,   314,   108,   455,   284,   457,   108,   218,   219,
     561,    45,  1234,    47,   108,   157,   184,   101,   455,   159,
     457,   177,  1745,   233,   484,   233,   577,   578,   187,   489,
     108,   148,   108,   484,  1522,   108,   176,   588,   489,   148,
     108,   108,   119,   314,    94,   108,   917,   484,   218,   219,
     197,    45,   489,    47,   186,  1389,   607,   608,  1122,  1123,
    1124,  1246,   185,   233,  1398,     5,   455,   154,   457,     9,
     157,   154,   104,   107,   113,  1409,  1421,  1360,   949,   184,
    1790,  1364,  1255,   184,    42,   108,    80,  1230,    46,   108,
     184,   108,   124,    51,   126,   484,  1122,  1123,  1124,   108,
     489,   561,   186,  1107,   225,     9,   184,   108,   568,   230,
       9,   187,    70,   107,   187,  1421,   184,   568,   869,   108,
     187,   184,   154,   137,   561,    29,   158,   977,   978,   269,
      29,   568,   982,   183,   168,    95,   276,    30,   221,   222,
     698,   699,   174,     5,   695,   896,   286,     9,   608,   700,
     119,   353,    97,   157,   356,   615,  1630,   131,    95,   621,
    1382,   108,  1012,   195,   187,   184,   626,   627,   628,   629,
     187,   608,   108,    42,   168,   184,    95,    46,   615,   568,
     166,   213,    51,   184,   124,   645,   126,   201,   169,   626,
     627,   628,   629,   314,   134,   155,   182,   157,   187,   145,
    1506,    70,   884,  1509,   878,   155,   888,   157,   645,    97,
     168,   148,   157,   171,   154,   123,   101,   186,   111,   608,
     124,   202,   126,   197,   143,   124,   114,   126,   186,   114,
     176,   135,   125,   435,   436,   107,   135,   439,   201,   154,
     187,   443,   123,  1577,   446,   447,   154,   210,   194,   157,
     154,   187,   454,  1744,   212,   154,   128,   150,   460,   461,
     157,  1520,   124,   465,   126,    54,  1525,  1138,  1139,   157,
      59,   473,   134,   824,   825,   826,    30,   828,   480,   481,
     482,   483,  1400,  1735,  1736,  1470,   488,   237,   101,    78,
       9,    10,   154,    95,   496,   210,    27,    28,  1643,   168,
     137,   114,   171,  1367,   118,    95,    37,    38,    97,    40,
      41,   186,  1455,   157,   151,   779,    47,   186,   869,   779,
       1,    95,     1,   159,     3,  1777,    57,    58,   779,    54,
     119,  1783,   186,   147,    59,   210,   138,  1643,    97,   541,
     176,   143,   779,   212,    75,  1690,   160,  1692,  1140,    80,
     810,   811,    33,   143,   556,   114,   210,   111,   157,   810,
     811,  1112,  1018,   199,  1020,   567,    42,   186,    49,   143,
      46,   125,    97,   810,   811,    51,     9,    10,   129,   130,
     194,   112,   113,   114,  1690,   104,  1692,   159,    67,   154,
     779,   210,   594,    72,    70,  1654,   150,   599,   157,  1658,
     154,   603,    25,   157,   176,   124,   182,   126,   157,   869,
    1755,    34,   177,    96,  1070,   263,  1072,  1723,   157,   186,
     196,   810,   811,   177,   107,  1275,   274,   199,   890,   186,
     161,  1113,   869,   133,   117,   154,   896,  1119,    61,   158,
     119,   141,   142,   210,   144,   128,   186,   268,    97,  1755,
    1568,  1569,   152,   210,   275,   174,   156,  1561,   158,   896,
     247,   248,   149,   163,  1770,   114,  1772,  1610,   138,   701,
     210,   104,   704,   182,   149,   707,   195,   157,   165,   179,
    1739,   269,  1116,   270,   154,  1707,   138,   196,   276,   220,
     165,   124,   168,   126,   213,   171,   101,   157,   286,   101,
     101,   101,   154,   203,   204,   205,   206,   207,   208,   114,
     186,   263,   114,   114,   114,   630,   123,    95,  1389,   634,
     967,   154,   274,  1274,  1374,   158,   299,  1398,   730,   107,
     261,   733,   979,  1383,   138,   308,   212,   154,  1409,   143,
     157,   174,   277,   278,   279,   747,   138,    54,   283,   751,
     752,   143,    59,   123,   352,   154,   287,   355,   157,   119,
    1678,  1679,   195,    90,   295,   154,   191,   192,   157,  1712,
     123,   773,   303,   775,   221,   222,   223,   232,   123,   234,
     213,   783,   119,   155,   786,   157,  1137,   114,   790,   232,
     123,   234,   123,  1359,   676,   677,   154,   683,   684,   126,
     154,   128,  1228,  1229,   123,  1065,   685,   686,  1598,  1599,
     123,   123,   123,   154,  1065,   157,  1759,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,   119,  1065,   216,
     832,   241,   241,  1751,   242,   157,   154,  1487,     0,   190,
     314,   167,    93,   249,   100,    50,   103,   102,   200,   193,
     155,   157,  1112,    30,   184,   184,   184,    47,   153,  1121,
     184,   119,  1122,  1123,  1124,   246,   304,   187,   284,   871,
     284,   119,   154,     1,   119,  1112,  1065,   143,   108,   187,
     154,   154,   157,   187,   143,  1122,  1123,  1124,  1831,   157,
    1833,   184,   157,   122,   157,   157,   157,   157,   900,    35,
    1843,   154,    17,   157,   214,    30,  1577,   190,   231,   230,
     190,   245,     3,   119,    71,   231,   168,    95,   187,    95,
     170,   170,  1356,    95,   150,   108,   108,    30,   930,   931,
     932,   933,   128,   161,   161,   133,    95,   246,   299,   143,
     119,   133,   184,   184,   187,   108,    95,   187,  1499,    97,
      45,    97,   187,   187,   187,   187,    95,   154,   237,   184,
     184,   154,   143,   154,   231,   154,   154,   154,   970,   190,
      33,   170,   133,   143,  1238,    95,    30,    95,  1238,   225,
     154,   128,   984,   286,   299,   119,   233,  1238,   227,   119,
     148,  1542,   133,    95,   161,   198,   133,    97,   184,   154,
     119,  1238,   101,   148,   101,   143,   190,  1009,   122,   184,
     254,   184,   154,    35,  1274,    30,  1018,   107,  1020,   154,
    1022,  1285,  1024,   119,    80,  1285,   245,   108,   108,   260,
     267,   157,   145,   157,  1285,  1037,   258,  1274,    30,    30,
    1304,   157,    30,   187,  1304,   157,   157,   285,  1285,  1238,
     157,   157,   145,  1304,   148,   187,   227,   190,   187,   128,
     187,   148,   148,   286,  1324,    78,   119,  1304,  1070,   287,
    1072,  1331,   119,  1324,   108,   143,   184,  1628,   187,     7,
    1331,   198,   187,   101,   133,    97,   306,  1324,  1639,  1640,
     233,  1642,   190,   233,  1331,   157,  1285,   111,   186,  1650,
     157,   107,   233,  1363,   154,  1107,   157,   148,   187,   436,
     233,    79,   439,   282,   187,  1304,   443,   187,   286,   446,
     447,   187,   187,   187,    30,    30,  1363,   454,   250,   250,
    1132,   108,   187,   460,   461,  1324,   237,   170,   465,   187,
     184,   148,  1331,   148,   127,   127,   473,   257,    97,   184,
     186,   316,  1154,   480,   481,   482,   483,   186,   186,   184,
     184,   488,   143,   184,   184,   154,    95,   271,   187,   496,
      30,    97,   170,   148,  1363,    54,   187,    95,    95,    30,
     197,  1732,   265,   108,   108,   119,   225,   119,  1539,  1540,
    1541,   280,    95,   186,    95,   287,   197,   197,   119,   198,
     186,    94,   225,   183,   119,   119,   119,   197,   293,   225,
     186,   263,   199,   287,   541,   260,   736,   260,  1190,   971,
    1771,   305,   430,   305,  1235,  1038,  1712,   305,  1759,   556,
     306,   306,   872,   450,   306,  1035,   792,  1264,  1789,  1499,
     567,  1381,  1244,  1128,  1385,  1480,  1248,  1291,  1378,   465,
    1286,  1294,  1299,  1804,   556,   675,   933,   655,  1318,   656,
     710,  1263,  1499,   340,   833,  1783,  1777,  1020,  1350,  1189,
    1272,  1361,  1360,   458,  1825,  1398,   603,  1409,   458,  1139,
    1577,  1574,  1542,  1834,  1286,  1402,  1148,  1003,  1212,  1601,
    1445,    -1,  1399,    -1,  1296,    -1,   597,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1542,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1671,    -1,    -1,  1325,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1688,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1350,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1360,    -1,
      -1,    -1,  1364,    -1,    -1,    -1,    -1,    -1,  1628,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1639,
    1640,    -1,  1642,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1650,  1628,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1639,  1640,    -1,  1642,   733,    -1,    -1,    -1,
      -1,    -1,    -1,  1650,    -1,    -1,    -1,    -1,    -1,  1421,
     747,    -1,    -1,    -1,   751,   752,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   773,    -1,   775,  1451,
      -1,    -1,    -1,    -1,    -1,    -1,   783,    -1,    -1,   786,
      -1,    -1,    -1,   790,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1732,    -1,    -1,  1477,  1478,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1732,    -1,    -1,    -1,    -1,
      -1,  1503,    -1,    -1,  1506,   832,    -1,  1509,    -1,    -1,
      -1,  1771,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1521,
      -1,    -1,    -1,    -1,  1526,    -1,    -1,    -1,    -1,  1789,
      -1,    -1,    -1,    -1,  1771,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1804,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1789,    -1,   568,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1825,    -1,  1804,    -1,    -1,
      -1,    -1,    -1,   900,  1834,    -1,    -1,    -1,   592,   593,
      -1,   595,   596,   597,   598,    -1,   600,    -1,  1825,    -1,
      -1,    -1,   606,    -1,    -1,    -1,    -1,  1834,    -1,    -1,
     614,    -1,    -1,   930,   931,   932,   933,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   636,   637,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   645,   646,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1643,  1644,   970,  1646,    -1,  1648,    -1,    -1,    -1,
      -1,    -1,    -1,  1655,    -1,    -1,    -1,   984,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1009,    -1,    -1,    -1,    -1,    -1,  1690,    -1,
    1692,  1018,   706,  1020,    -1,  1022,   710,  1024,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1708,    -1,    -1,  1711,
    1037,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1723,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1734,    -1,    -1,   749,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1070,    -1,  1072,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1755,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1763,    -1,    -1,    -1,    -1,  1768,    -1,  1770,    -1,
    1772,    -1,    -1,    -1,    -1,    -1,    -1,   791,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1801,
      -1,    -1,    -1,   817,    -1,  1132,    -1,   821,   822,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   830,    -1,    -1,  1821,
      -1,    -1,    -1,    -1,  1826,    -1,    -1,  1154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1838,    -1,    -1,  1841,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   896,    -1,    -1,    -1,    -1,    -1,   902,   903,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1244,    -1,    -1,
      -1,  1248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1272,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   972,  1286,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1296,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1007,    -1,    -1,    -1,    -1,  1325,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1026,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1350,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1048,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1059,  1060,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1074,    -1,    -1,  1077,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1094,  1095,  1096,    -1,  1098,  1099,  1100,  1101,  1102,  1103,
    1104,  1105,  1106,    -1,  1421,  1109,  1110,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1451,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1477,  1478,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1503,    -1,    -1,  1506,
      -1,    -1,  1509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1521,    -1,    -1,    -1,    -1,  1526,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1250,    -1,  1252,    -1,
    1254,    -1,    -1,  1257,    -1,    -1,    -1,    -1,  1262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1283,
      -1,    -1,    -1,    -1,    -1,  1289,  1290,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1308,    -1,    -1,  1311,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1643,  1644,    -1,  1646,
      -1,  1648,    -1,    -1,    -1,    -1,    -1,    -1,  1655,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1690,    -1,  1692,    -1,  1381,    -1,    -1,
      -1,  1385,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1708,    -1,    -1,  1711,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1723,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1734,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1755,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1763,    -1,    -1,    -1,
      -1,  1768,    -1,  1770,    -1,  1772,    -1,    -1,    -1,    -1,
    1464,    -1,    -1,    -1,  1468,    -1,    -1,    -1,  1472,    -1,
    1474,    -1,  1476,    -1,    -1,    -1,    -1,    -1,  1482,    -1,
      -1,    -1,    -1,    -1,  1801,    -1,  1490,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1498,  1499,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1821,    -1,    -1,    -1,    -1,  1826,
      -1,    -1,    -1,    -1,  1518,    -1,    -1,    -1,    -1,    -1,
      -1,  1838,    -1,    -1,  1841,    -1,  1530,  1531,  1532,  1533,
      -1,  1535,  1536,    -1,  1538,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1553,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1616,    -1,  1618,    -1,    -1,  1621,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1629,    -1,    -1,    -1,    -1,
    1634,  1635,    -1,    -1,    -1,    -1,    -1,    -1,  1642,    -1,
      -1,    -1,    -1,  1647,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1664,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1675,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1715,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1728,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1771,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1799,    -1,    -1,    -1,    -1,
    1804,    -1,    -1,    -1,    -1,  1809,     0,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    -1,
    1824,    -1,    16,    -1,  1828,    -1,    20,    21,    22,    23,
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
     314,   315,   316,   317,   318,   319,   320,     0,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
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
     303,   304,   305,   306,   307,   308,   309,   310,     1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
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
     303,   304,   305,   306,   307,   308,   309,   310,     1,   312,
      -1,   314,   315,   316,   317,   318,   319,   320,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
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
      -1,   314,   315,   316,   317,   318,   319,   320,     0,     1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    70,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    95,    96,    97,    -1,    -1,   100,   101,
     102,   103,    -1,    -1,    -1,   107,   108,    -1,    -1,    -1,
      -1,    -1,   114,    -1,    -1,   117,   118,   119,    -1,    -1,
     122,    -1,    -1,    -1,    -1,   127,   128,    -1,    -1,    -1,
      -1,   133,    -1,    -1,    -1,   137,    -1,    -1,    -1,   141,
     142,    -1,   144,    -1,   146,   147,    -1,    -1,    -1,   151,
     152,    -1,    -1,   155,   156,   157,   158,   159,   160,    -1,
      -1,   163,    -1,    -1,    -1,   167,   168,    -1,    -1,   171,
      -1,    -1,    -1,    -1,   176,    -1,    -1,   179,    -1,    -1,
      -1,    -1,   184,   185,   186,   187,   188,    -1,   190,   191,
     192,   193,   194,    -1,    -1,    -1,    -1,   199,   200,   201,
      -1,   203,   204,   205,   206,   207,   208,    -1,   210,    -1,
     212,    -1,    -1,    -1,    -1,   217,   218,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   233,    -1,   235,    -1,   237,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,   311,
      30,   313,    -1,    33,    34,    -1,    36,    37,    38,    39,
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
     320,   321,   322,    11,    12,    -1,    -1,    -1,    16,    -1,
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
     318,   319,   320,    -1,   322,    11,    12,    -1,    -1,    -1,
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
     176,   177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,
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
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
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
     176,   177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,
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
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
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
     176,   177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,
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
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
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
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
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
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
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
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
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
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
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
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
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
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
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
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,   187,   188,   189,    -1,   191,   192,    -1,   194,    -1,
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
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,   145,
      -1,   147,   148,   149,   150,   151,   152,   153,   154,   155,
      -1,   157,   158,   159,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,   187,   188,   189,    -1,   191,   192,    -1,   194,    -1,
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
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,   185,
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
     186,   187,   188,   189,    -1,   191,   192,    -1,   194,    -1,
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
     306,   307,   308,   309,   310,   311,   312,    -1,   314,   315,
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
     306,   307,   308,   309,   310,    -1,   312,   313,   314,   315,
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
     176,   177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,
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
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,   145,
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
      -1,   157,   158,    -1,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
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
      -1,   157,   158,    -1,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,
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
     136,    -1,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,   150,    -1,   152,   153,   154,   155,
      -1,   157,   158,    -1,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,
     196,    -1,   198,    -1,   200,    -1,   202,   203,   204,   205,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
      -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,   151,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,
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
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
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
      -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,    -1,
     136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,   151,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,   160,   161,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,
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
      -1,    -1,    -1,    -1,   314,   315,   316,   317,   318,   319,
     320,    16,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,
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
     309,    -1,    -1,    16,    -1,   314,   315,   316,   317,   318,
     319,   320,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
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
      -1,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
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
     305,   306,   307,   308,   309,    -1,    -1,    -1,    -1,   314,
     315,   316,   317,   318,   319,   320,    21,    22,    23,    24,
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
     125,    -1,   127,   128,   129,   130,    -1,   132,    -1,    -1,
      -1,   136,   137,   138,   139,   140,    -1,    -1,    -1,    -1,
      -1,    -1,   147,   148,   149,   150,   151,   152,    -1,   154,
     155,    -1,   157,   158,    -1,   160,   161,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,    -1,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
      -1,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,    -1,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    25,    26,
      -1,   316,   317,    -1,    -1,    -1,    33,    34,    -1,    36,
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
     307,   308,   309,    -1,    -1,    -1,    -1,    -1,    -1,   316,
     317
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
     231,    95,    95,    95,   495,   184,   413,   497,   497,   413,
     510,   145,   187,   414,   520,   187,   150,   187,   520,   108,
     187,   187,   108,   108,   380,    30,   656,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,   362,   363,   364,
      95,   138,   143,   368,   369,   370,   655,   161,   161,   362,
     654,   128,   133,    55,    57,   101,   251,   264,   266,   277,
     278,   279,   281,   283,   617,   618,   619,   620,   621,   622,
     629,   635,   636,   246,    95,   299,   655,   143,   414,   119,
     655,   655,   133,   184,   184,   187,   187,   184,   108,   187,
     108,   187,   108,    36,    95,    97,   148,   429,   430,   551,
     655,    56,   217,   254,   419,   420,   655,    95,   108,   187,
     391,   187,   655,    97,    45,   655,   654,    97,   143,   551,
     655,   414,   433,   184,   187,   187,   187,   187,   108,   188,
     148,   551,   184,   187,   187,   154,   184,   392,   392,   184,
     108,   187,   108,   187,   143,   551,   414,   188,   414,   414,
     413,   413,   413,   655,   529,   530,   131,   197,   184,   184,
     184,   132,   190,    95,   218,   219,   233,    95,   218,   219,
     233,   233,   233,    95,    95,   237,   225,   231,   108,   235,
     143,   190,   187,   413,   184,   506,   589,   411,   233,   359,
      33,    33,   190,   336,   190,   114,   394,   655,   170,   414,
     444,   445,   119,   414,   440,   441,   472,   154,   157,   259,
     493,   512,   590,   593,   594,   595,   596,   597,   601,   603,
     605,   606,    47,   153,   157,   211,   317,   318,   319,   320,
     552,   554,   556,   558,   573,   574,   575,   576,   653,   655,
     552,   484,   557,   655,   484,   184,   185,   108,   187,   187,
     512,   149,   165,   149,   165,   138,   397,   380,   363,   133,
     554,   370,   414,   551,   654,   654,   129,   130,   654,   277,
     278,   279,   283,   655,   263,   274,   263,   274,    30,   286,
      97,   114,   157,   623,   626,   617,    39,    44,    53,    60,
      62,    71,    98,   225,   317,   318,   319,   384,   558,   653,
     227,   299,   308,   414,   655,    95,   299,   654,   154,   570,
     571,   655,   570,   571,   119,   428,   128,   552,   119,   414,
     148,   430,   148,    36,   148,   429,   430,   148,   551,   254,
      54,    59,    78,   119,   429,   435,   436,   437,   420,   551,
     552,   382,    95,   184,   198,   133,   354,   654,   161,   133,
      97,   354,   414,   143,   430,   154,   119,   414,   414,   148,
     101,   454,   455,   456,   458,   459,   101,   462,   463,   464,
     465,   392,   184,   184,   154,   570,   570,   414,   143,   190,
     414,   122,   187,   187,   187,    35,   530,   131,   197,     9,
      10,   104,   124,   126,   154,   195,   525,   527,   538,   539,
     542,   154,    30,   232,   234,   414,   414,   414,   232,   234,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   508,
     119,   414,   414,    48,    73,    74,   244,   394,   415,   425,
     245,   586,   587,   154,   210,   395,   414,   190,   114,   389,
     389,   389,   444,    96,   107,   117,   128,   446,   447,   448,
     449,   108,   655,   107,   442,   108,   413,   590,   597,   154,
     285,   474,   642,    97,   169,   252,   253,   255,   262,   272,
     284,   591,   592,   611,   612,   613,   614,   637,   640,   258,
     260,   598,   616,   267,   602,   638,   247,   248,   270,   607,
     608,   157,   157,   554,   157,   157,   157,   157,   157,   145,
     176,   194,   553,   145,   145,   414,   138,   397,   572,   369,
     286,    30,    97,   114,   157,   630,    30,   623,   553,   553,
     495,   287,   306,   551,   384,   227,   190,   391,   187,   187,
     145,   187,   187,   428,   148,   429,   655,   414,   148,   414,
     128,   414,   148,   430,   148,   414,   148,   119,   119,   414,
     655,   437,    78,   552,   394,   414,   654,   108,   354,   414,
     143,   391,   452,   414,   414,   114,   455,   456,   101,   186,
     114,   456,   459,   119,   466,   552,   101,   114,   463,   101,
     114,   465,   184,   391,   187,   187,   414,   414,   198,   462,
     133,   195,   527,     7,   392,   655,   195,   538,   392,   190,
     233,   233,   233,   233,    97,   237,   237,   584,   186,   157,
     157,   157,   186,   589,   587,   506,   654,   129,   130,   448,
     449,   449,   445,   143,   551,   654,   441,   184,   187,   590,
     604,   250,   217,   254,   268,   275,   641,    97,   256,   257,
     639,   250,   594,   641,   476,   611,   595,   148,   282,   599,
     600,   639,   286,   610,    79,   609,   187,   194,   552,   555,
     187,   187,   187,   187,   187,   187,   187,    30,   137,   201,
     632,   633,   634,    30,   631,   632,   271,   627,   108,   624,
     170,   655,   257,   495,   184,   414,   148,   414,   148,   429,
     414,   148,   414,   414,   655,   655,   436,   414,   127,   127,
      97,   654,   414,   184,   186,   186,   414,   394,   414,   186,
     186,   655,   186,   210,   119,   466,   119,   186,   119,   466,
     186,   184,   114,   530,   655,   195,   184,   530,   655,   184,
     414,   414,   414,   414,   316,   414,   414,   414,   413,   413,
     413,   154,   588,   449,   414,   143,   184,   478,    52,   130,
     476,   476,   269,   276,   286,   615,   615,   596,   154,   280,
      95,   187,   108,   187,   630,   630,   634,   108,   187,    30,
     628,   639,   625,   626,   187,   386,   387,   495,   119,   225,
     307,   287,   170,   414,   414,   148,   414,    54,   394,   414,
     354,   414,   394,    95,   394,   414,   552,   655,   186,   655,
     414,   655,   186,   394,   119,    94,   183,   531,   530,   655,
     197,   530,   414,   187,   187,   187,   413,   442,   414,   476,
     476,   199,   413,   552,   552,    95,    30,   265,   108,   108,
     449,   551,   655,   119,   225,   655,   386,   414,   119,   466,
      95,   186,    95,   655,     5,   134,   534,   535,   537,   539,
      29,   135,   532,   533,   536,   539,   197,   530,   197,   198,
     462,   184,   442,   476,   184,   552,   626,   387,   449,   305,
     655,   119,   225,   655,   186,   466,   394,   414,   466,   186,
      94,   134,   537,   183,   135,   536,   197,   114,   414,   305,
     655,   119,   394,   414,   186,   186,   119,   293,   305,   655,
     655,   306,   414,   306,   186,   495,   495,   199,   287,   655,
     225,   119,   655,   306,   495
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
     491,   491,   491,   491,   492,   492,   493,   493,   494,   494,
     494,   495,   495,   495,   495,   496,   497,   497,   497,   498,
     498,   499,   499,   499,   499,   500,   500,   501,   501,   501,
     501,   501,   501,   501,   502,   502,   503,   503,   504,   504,
     504,   504,   504,   505,   505,   506,   506,   507,   507,   507,
     507,   508,   508,   508,   508,   509,   509,   510,   511,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   511,
     511,   511,   512,   512,   513,   513,   513,   514,   515,   515,
     516,   517,   518,   519,   519,   520,   520,   520,   520,   521,
     521,   522,   523,   524,   524,   525,   525,   525,   526,   526,
     526,   526,   526,   526,   527,   527,   528,   528,   529,   530,
     530,   531,   531,   532,   532,   533,   533,   533,   533,   534,
     534,   535,   535,   535,   535,   536,   536,   537,   537,   538,
     538,   538,   538,   539,   539,   539,   539,   540,   540,   541,
     541,   542,   543,   543,   543,   543,   543,   543,   543,   544,
     545,   545,   546,   546,   547,   548,   549,   549,   550,   550,
     551,   552,   552,   552,   553,   553,   553,   554,   554,   554,
     554,   554,   554,   554,   555,   555,   556,   557,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   559,   560,
     561,   561,   561,   562,   563,   564,   565,   565,   565,   566,
     566,   566,   566,   566,   567,   568,   568,   568,   568,   568,
     568,   568,   569,   570,   571,   572,   573,   573,   574,   575,
     575,   576,   577,   577,   577,   578,   578,   578,   578,   578,
     578,   578,   578,   578,   578,   579,   579,   580,   580,   581,
     582,   583,   583,   584,   585,   586,   586,   587,   588,   589,
     589,   590,   591,   591,   592,   592,   593,   593,   594,   594,
     595,   595,   596,   596,   597,   598,   598,   599,   599,   600,
     601,   601,   601,   602,   602,   603,   604,   604,   605,   606,
     606,   607,   607,   608,   608,   608,   609,   609,   610,   610,
     611,   611,   611,   611,   611,   612,   613,   614,   615,   615,
     615,   616,   616,   617,   617,   617,   617,   617,   617,   617,
     617,   618,   618,   618,   618,   619,   619,   620,   621,   621,
     622,   622,   622,   623,   623,   624,   624,   625,   625,   626,
     627,   627,   628,   628,   629,   629,   629,   630,   630,   631,
     631,   632,   632,   633,   633,   634,   634,   635,   636,   636,
     637,   637,   637,   638,   639,   639,   639,   639,   640,   640,
     641,   641,   642,   643,   643,   644,   644,   645,   645,   646,
     647,   647,   648,   648,   648,   649,   650,   651,   652,   653,
     653,   653,   654,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   656,   656,   656,   656,
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
     656,   656,   656,   656,   656,   656,   656,   657
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
       4,     5,     5,     6,     3,     4,     1,     2,     3,     2,
       2,     1,     2,     2,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     1,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     4,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     4,     4,     3,     4,     1,     3,     1,     3,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     4,     8,
       5,     9,     9,    10,     1,     2,     1,     2,     6,     0,
       1,     3,     3,     0,     1,     1,     1,     2,     2,     0,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     3,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     7,     3,     7,     4,     4,     3,     7,     3,     7,
       2,     1,     2,     3,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     4,     4,     3,     3,     3,     3,     4,     4,     3,
       4,     6,     4,     6,     4,     3,     4,     6,     6,     4,
       6,     6,     4,     1,     2,     1,     1,     1,     4,     5,
       6,     3,     3,     3,     3,     5,     7,     7,     5,     5,
       5,     7,     7,     5,     5,     3,     3,     5,     7,     5,
       7,     1,     4,     3,     5,     1,     2,     3,     3,     1,
       3,     2,     0,     1,     1,     2,     1,     3,     1,     3,
       1,     4,     1,     2,     3,     0,     1,     0,     1,     4,
       2,     3,     1,     0,     1,     4,     0,     1,     2,     1,
       3,     0,     1,     2,     2,     1,     0,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     2,     2,     3,     1,     2,
       2,     5,     2,     1,     1,     0,     2,     1,     3,     4,
       0,     2,     0,     2,     4,     4,     3,     2,     3,     1,
       3,     0,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     3,     2,     3,     3,     4,     2,     2,
       1,     1,     3,     2,     3,     2,     3,     2,     3,     3,
       3,     5,     5,     5,     8,     5,     3,     5,     7,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1
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
     184,    -1,   493,   154,   184,    -1,   493,   154,   413,   184,
      -1,   494,    -1,   493,   494,    -1,   177,   655,    17,    -1,
     177,    18,    -1,   177,    19,    -1,   496,    -1,   496,   497,
      -1,   192,   497,    -1,   497,    -1,   191,    -1,   498,    -1,
     498,   191,   497,    -1,   498,   192,   497,    -1,   499,    -1,
     508,    -1,   500,    -1,   500,   509,    -1,   503,    -1,   503,
     509,    -1,   501,   505,    -1,   502,    -1,   106,   123,    -1,
     115,   123,    -1,    98,   123,    -1,   189,   123,    -1,   116,
     123,    -1,   140,   123,    -1,   139,   123,    -1,   505,    -1,
      99,   505,    -1,   504,   505,    -1,   121,    -1,   172,   123,
      -1,    91,   123,    -1,   181,   123,    -1,   180,   123,    -1,
      92,   123,    -1,   558,    -1,   506,    -1,   655,    -1,   507,
      -1,   194,    -1,    11,    -1,    12,    -1,    20,    -1,   511,
      -1,   508,   509,    -1,   508,   157,   187,    -1,   508,   157,
     520,   187,    -1,   510,    -1,   509,   510,    -1,   155,   413,
     185,    -1,   512,    -1,   514,    -1,   515,    -1,   516,    -1,
     519,    -1,   524,    -1,   517,    -1,   518,    -1,   521,    -1,
     396,    -1,   646,    -1,   643,    -1,   644,    -1,   645,    -1,
     513,    -1,   572,    -1,   111,    -1,   150,    -1,   125,    -1,
     119,   655,    -1,   157,   187,    -1,   157,   413,   187,    -1,
     120,    -1,   169,   154,   413,   184,    -1,   202,   154,   413,
     184,    -1,   656,   157,   187,    -1,   656,   157,   520,   187,
      -1,   145,    -1,   520,   108,   145,    -1,   414,    -1,   520,
     108,   414,    -1,   522,    -1,   523,    -1,   656,   146,   150,
      -1,    47,   380,   397,    -1,   525,    -1,   543,    -1,   526,
      -1,   540,    -1,   541,    -1,   158,   655,   530,   131,    -1,
     158,   655,   530,   197,   195,   655,   530,   197,    -1,   158,
     655,   528,   530,   131,    -1,   158,   655,   528,   530,   197,
     195,   655,   530,   197,    -1,   158,   655,   530,   197,   527,
     195,   655,   530,   197,    -1,   158,   655,   528,   530,   197,
     527,   195,   655,   530,   197,    -1,   538,    -1,   527,   538,
      -1,   529,    -1,   528,   529,    -1,    35,   655,   530,   133,
     530,   531,    -1,    -1,    35,    -1,   183,   532,   183,    -1,
      94,   534,    94,    -1,    -1,   533,    -1,   135,    -1,   536,
      -1,   533,   135,    -1,   533,   536,    -1,    -1,   535,    -1,
     134,    -1,   537,    -1,   535,   134,    -1,   535,   537,    -1,
      29,    -1,   539,    -1,     5,    -1,   539,    -1,   525,    -1,
      10,    -1,   542,    -1,   539,    -1,     9,    -1,   124,    -1,
     126,    -1,   154,   392,   184,    -1,   213,    31,   214,    -1,
     213,   214,    -1,   174,   655,   175,    -1,   174,   655,     8,
      -1,   104,     7,    -1,   544,    -1,   545,    -1,   546,    -1,
     547,    -1,   548,    -1,   549,    -1,   550,    -1,    43,   154,
     392,   184,    -1,    21,   391,   184,    -1,    45,   154,   413,
     184,   154,   391,   184,    -1,    22,   391,   184,    -1,    98,
     154,   413,   184,   154,   391,   184,    -1,    71,   154,   392,
     184,    -1,    39,   154,   392,   184,    -1,    23,   391,   184,
      -1,    60,   154,   413,   184,   154,   391,   184,    -1,    24,
     392,   184,    -1,   161,   154,   413,   184,   154,   392,   184,
      -1,    95,   552,    -1,   554,    -1,   554,   553,    -1,   211,
     157,   187,    -1,   145,    -1,   194,    -1,   176,    -1,   556,
      -1,   558,    -1,   153,   157,   187,    -1,   320,   157,   187,
      -1,   573,    -1,   576,    -1,   653,    -1,   552,    -1,   555,
     108,   552,    -1,   655,    -1,   655,    -1,   561,    -1,   568,
      -1,   566,    -1,   569,    -1,   567,    -1,   565,    -1,   564,
      -1,   563,    -1,   562,    -1,   559,    -1,   560,   157,   187,
      -1,   225,    -1,    44,   157,   187,    -1,    44,   157,   568,
     187,    -1,    44,   157,   569,   187,    -1,    53,   157,   187,
      -1,    71,   157,   187,    -1,    39,   157,   187,    -1,    60,
     157,   187,    -1,    60,   157,   655,   187,    -1,    60,   157,
      30,   187,    -1,    98,   157,   187,    -1,    98,   157,   655,
     187,    -1,    98,   157,   655,   108,   570,   187,    -1,    98,
     157,   194,   187,    -1,    98,   157,   194,   108,   570,   187,
      -1,    62,   157,   655,   187,    -1,    45,   157,   187,    -1,
      45,   157,   655,   187,    -1,    45,   157,   655,   108,   570,
     187,    -1,    45,   157,   655,   108,   571,   187,    -1,    45,
     157,   194,   187,    -1,    45,   157,   194,   108,   570,   187,
      -1,    45,   157,   194,   108,   571,   187,    -1,    63,   157,
     655,   187,    -1,   655,    -1,   655,   145,    -1,    30,    -1,
     574,    -1,   575,    -1,    47,   157,   194,   187,    -1,    47,
     157,   187,    95,   552,    -1,    47,   157,   555,   187,    95,
     552,    -1,   157,   554,   187,    -1,    33,   220,   221,    -1,
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
     414,    95,   414,    -1,   236,   119,   583,   235,   414,   186,
     414,    -1,   584,    -1,   583,   108,   119,   584,    -1,   655,
     143,   414,    -1,   244,   154,   413,   184,   586,    -1,   587,
      -1,   586,   587,    -1,   245,   589,   588,    -1,   154,   413,
     184,    -1,   506,    -1,   589,   210,   506,    -1,   593,   591,
      -1,    -1,   592,    -1,   611,    -1,   592,   611,    -1,   594,
      -1,   593,   262,   594,    -1,   595,    -1,   594,   258,   595,
      -1,   596,    -1,   595,   260,   148,   596,    -1,   597,    -1,
     259,   597,    -1,   601,   598,   599,    -1,    -1,   616,    -1,
      -1,   600,    -1,   282,   154,   413,   184,    -1,   605,   602,
      -1,   157,   590,   187,    -1,   603,    -1,    -1,   638,    -1,
     493,   154,   604,   184,    -1,    -1,   590,    -1,   606,   607,
      -1,   512,    -1,   154,   413,   184,    -1,    -1,   608,    -1,
     248,   609,    -1,   247,   610,    -1,   270,    -1,    -1,    79,
      -1,    -1,   286,    -1,   612,    -1,   613,    -1,   614,    -1,
     640,    -1,   637,    -1,   169,    -1,   284,   476,   615,    -1,
     253,   639,   615,    -1,   286,    -1,   276,    -1,   269,    -1,
     246,   617,    -1,   616,   246,   617,    -1,   618,    -1,   619,
      -1,   620,    -1,   635,    -1,   621,    -1,   629,    -1,   622,
      -1,   636,    -1,   101,   274,    -1,   101,   263,    -1,   266,
      -1,   281,    -1,   251,   274,    -1,   251,   263,    -1,    57,
     655,    30,    -1,   277,    -1,    55,   277,    -1,   279,   623,
      -1,   279,   157,   623,   624,   187,    -1,    55,   279,    -1,
     626,    -1,   114,    -1,    -1,   108,   625,    -1,   626,    -1,
     625,   108,   626,    -1,    97,    30,   627,   628,    -1,    -1,
     271,    30,    -1,    -1,   639,   265,    -1,   278,   286,   630,
     632,    -1,   278,   286,   114,   632,    -1,    55,   278,   286,
      -1,    97,    30,    -1,   157,   631,   187,    -1,    30,    -1,
     631,   108,    30,    -1,    -1,   633,    -1,   634,    -1,   633,
     634,    -1,   201,   630,    -1,   137,   630,    -1,   264,    30,
      -1,   283,    -1,    55,   283,    -1,    97,   217,    -1,    97,
     254,    -1,   255,   250,    -1,   267,   639,   280,    -1,   256,
     476,    -1,    97,   130,   476,    -1,    97,    52,   476,    -1,
     257,   476,   199,   476,    -1,   272,   641,    -1,   252,   641,
      -1,   275,    -1,   268,    -1,   285,   250,   478,    -1,   155,
     185,    -1,   155,   413,   185,    -1,   310,   311,    -1,   310,
     413,   311,    -1,   312,   313,    -1,   312,   413,   313,    -1,
     154,   647,   184,    -1,   414,   122,   414,    -1,   647,   108,
     414,   122,   414,    -1,   226,   314,   414,   233,   414,    -1,
     226,   314,   647,   233,   414,    -1,   226,   314,   414,   233,
     414,    97,   316,   414,    -1,   315,   314,   414,   233,   414,
      -1,   224,   314,   508,    -1,   228,   314,   508,    95,   414,
      -1,   229,   314,   230,   231,   508,   237,   414,    -1,   319,
     157,   187,    -1,   318,   157,   187,    -1,   317,   157,   187,
      -1,    30,    -1,   656,    -1,    16,    -1,    98,    -1,    39,
      -1,    44,    -1,    53,    -1,    45,    -1,   153,    -1,    48,
      -1,   225,    -1,    60,    -1,    62,    -1,    63,    -1,    71,
      -1,    74,    -1,    73,    -1,   211,    -1,   243,    -1,   314,
      -1,   315,    -1,   319,    -1,   318,    -1,   320,    -1,   657,
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
      -1,   268,    -1,   269,    -1,   235,    -1,   232,    -1,   229,
      -1,   226,    -1,   228,    -1,   224,    -1,   219,    -1,   218,
      -1,   220,    -1,   237,    -1,   227,    -1,   234,    -1,   233,
      -1,    66,    -1,    64,    -1,    75,    -1,   169,    -1,   202,
      -1,   242,    -1,   240,    -1,   241,    -1,   238,    -1,   239,
      -1,   244,    -1,   245,    -1,   246,    -1,    65,    -1,   295,
      -1,   293,    -1,   294,    -1,   299,    -1,   300,    -1,   301,
      -1,   296,    -1,   297,    -1,   298,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,   287,
      -1,   288,    -1,   289,    -1,   290,    -1,   291,    -1,   292,
      -1,   303,    -1,   304,    -1,   305,    -1,   306,    -1,   307,
      -1,   308,    -1,   309,    -1,    91,    -1,   106,    -1,   115,
      -1,   172,    -1,   180,    -1,   189,    -1,   139,    -1,    92,
      -1,   116,    -1,   140,    -1,   181,    -1,   316,    -1,   317,
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
    1548,  1553,  1559,  1565,  1572,  1576,  1581,  1583,  1586,  1590,
    1593,  1596,  1598,  1601,  1604,  1606,  1608,  1610,  1614,  1618,
    1620,  1622,  1624,  1627,  1629,  1632,  1635,  1637,  1640,  1643,
    1646,  1649,  1652,  1655,  1658,  1660,  1663,  1666,  1668,  1671,
    1674,  1677,  1680,  1683,  1685,  1687,  1689,  1691,  1693,  1695,
    1697,  1699,  1701,  1704,  1708,  1713,  1715,  1718,  1722,  1724,
    1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,  1744,
    1746,  1748,  1750,  1752,  1754,  1756,  1758,  1760,  1763,  1766,
    1770,  1772,  1777,  1782,  1786,  1791,  1793,  1797,  1799,  1803,
    1805,  1807,  1811,  1815,  1817,  1819,  1821,  1823,  1825,  1830,
    1839,  1845,  1855,  1865,  1876,  1878,  1881,  1883,  1886,  1893,
    1894,  1896,  1900,  1904,  1905,  1907,  1909,  1911,  1914,  1917,
    1918,  1920,  1922,  1924,  1927,  1930,  1932,  1934,  1936,  1938,
    1940,  1942,  1944,  1946,  1948,  1950,  1952,  1956,  1960,  1963,
    1967,  1971,  1974,  1976,  1978,  1980,  1982,  1984,  1986,  1988,
    1993,  1997,  2005,  2009,  2017,  2022,  2027,  2031,  2039,  2043,
    2051,  2054,  2056,  2059,  2063,  2065,  2067,  2069,  2071,  2073,
    2077,  2081,  2083,  2085,  2087,  2089,  2093,  2095,  2097,  2099,
    2101,  2103,  2105,  2107,  2109,  2111,  2113,  2115,  2117,  2121,
    2123,  2127,  2132,  2137,  2141,  2145,  2149,  2153,  2158,  2163,
    2167,  2172,  2179,  2184,  2191,  2196,  2200,  2205,  2212,  2219,
    2224,  2231,  2238,  2243,  2245,  2248,  2250,  2252,  2254,  2259,
    2265,  2272,  2276,  2280,  2284,  2288,  2294,  2302,  2310,  2316,
    2322,  2328,  2336,  2344,  2350,  2356,  2360,  2364,  2370,  2378,
    2384,  2392,  2394,  2399,  2403,  2409,  2411,  2414,  2418,  2422,
    2424,  2428,  2431,  2432,  2434,  2436,  2439,  2441,  2445,  2447,
    2451,  2453,  2458,  2460,  2463,  2467,  2468,  2470,  2471,  2473,
    2478,  2481,  2485,  2487,  2488,  2490,  2495,  2496,  2498,  2501,
    2503,  2507,  2508,  2510,  2513,  2516,  2518,  2519,  2521,  2522,
    2524,  2526,  2528,  2530,  2532,  2534,  2536,  2540,  2544,  2546,
    2548,  2550,  2553,  2557,  2559,  2561,  2563,  2565,  2567,  2569,
    2571,  2573,  2576,  2579,  2581,  2583,  2586,  2589,  2593,  2595,
    2598,  2601,  2607,  2610,  2612,  2614,  2615,  2618,  2620,  2624,
    2629,  2630,  2633,  2634,  2637,  2642,  2647,  2651,  2654,  2658,
    2660,  2664,  2665,  2667,  2669,  2672,  2675,  2678,  2681,  2683,
    2686,  2689,  2692,  2695,  2699,  2702,  2706,  2710,  2715,  2718,
    2721,  2723,  2725,  2729,  2732,  2736,  2739,  2743,  2746,  2750,
    2754,  2758,  2764,  2770,  2776,  2785,  2791,  2795,  2801,  2809,
    2813,  2817,  2821,  2823,  2825,  2827,  2829,  2831,  2833,  2835,
    2837,  2839,  2841,  2843,  2845,  2847,  2849,  2851,  2853,  2855,
    2857,  2859,  2861,  2863,  2865,  2867,  2869,  2871,  2873,  2875,
    2877,  2879,  2881,  2883,  2885,  2887,  2889,  2891,  2893,  2895,
    2897,  2899,  2901,  2903,  2905,  2907,  2909,  2911,  2913,  2915,
    2917,  2919,  2921,  2923,  2925,  2927,  2929,  2931,  2933,  2935,
    2937,  2939,  2941,  2943,  2945,  2947,  2949,  2951,  2953,  2955,
    2957,  2959,  2961,  2963,  2965,  2967,  2969,  2971,  2973,  2975,
    2977,  2979,  2981,  2983,  2985,  2987,  2989,  2991,  2993,  2995,
    2997,  2999,  3001,  3003,  3005,  3007,  3009,  3011,  3013,  3015,
    3017,  3019,  3021,  3023,  3025,  3027,  3029,  3031,  3033,  3035,
    3037,  3039,  3041,  3043,  3045,  3047,  3049,  3051,  3053,  3055,
    3057,  3059,  3061,  3063,  3065,  3067,  3069,  3071,  3073,  3075,
    3077,  3079,  3081,  3083,  3085,  3087,  3089,  3091,  3093,  3095,
    3097,  3099,  3101,  3103,  3105,  3107,  3109,  3111,  3113,  3115,
    3117,  3119,  3121,  3123,  3125,  3127,  3129,  3131,  3133,  3135,
    3137,  3139,  3141,  3143,  3145,  3147,  3149,  3151,  3153,  3155,
    3157,  3159,  3161,  3163,  3165,  3167,  3169,  3171,  3173,  3175,
    3177,  3179,  3181,  3183,  3185,  3187,  3189,  3191,  3193,  3195,
    3197,  3199,  3201,  3203,  3205,  3207,  3209,  3211,  3213,  3215,
    3217,  3219,  3221,  3223,  3225,  3227,  3229,  3231,  3233,  3235,
    3237,  3239,  3241,  3243,  3245,  3247,  3249,  3251,  3253,  3255,
    3257,  3259,  3261,  3263,  3265,  3267,  3269,  3271
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
    3351,  3355,  3359,  3363,  3372,  3378,  3386,  3392,  3400,  3404,
    3408,  3414,  3418,  3426,  3434,  3452,  3458,  3468,  3472,  3478,
    3479,  3482,  3488,  3496,  3502,  3512,  3518,  3526,  3530,  3534,
    3538,  3542,  3548,  3554,  3560,  3564,  3570,  3574,  3583,  3587,
    3591,  3597,  3601,  3609,  3610,  3613,  3617,  3623,  3627,  3631,
    3635,  3641,  3645,  3649,  3653,  3659,  3665,  3673,  3679,  3680,
    3681,  3682,  3683,  3684,  3685,  3686,  3687,  3688,  3689,  3690,
    3691,  3692,  3695,  3699,  3705,  3712,  3719,  3728,  3734,  3738,
    3744,  3751,  3757,  3763,  3767,  3785,  3791,  3797,  3803,  3811,
    3815,  3821,  3827,  3837,  3838,  3841,  3842,  3843,  3846,  3854,
    3870,  3878,  3894,  3912,  3932,  3938,  3947,  3953,  3962,  3969,
    3970,  3972,  3977,  3984,  3987,  3993,  3999,  4005,  4012,  4021,
    4024,  4030,  4036,  4042,  4049,  4058,  4062,  4068,  4072,  4078,
    4082,  4086,  4091,  4098,  4102,  4106,  4110,  4116,  4121,  4127,
    4133,  4140,  4146,  4151,  4156,  4161,  4166,  4171,  4176,  4179,
    4185,  4189,  4195,  4199,  4205,  4211,  4217,  4221,  4227,  4231,
    4237,  4243,  4247,  4251,  4257,  4263,  4269,  4277,  4290,  4294,
    4298,  4302,  4306,  4310,  4316,  4322,  4330,  4336,  4342,  4346,
    4350,  4354,  4358,  4362,  4366,  4370,  4374,  4378,  4384,  4390,
    4396,  4400,  4404,  4410,  4415,  4421,  4427,  4431,  4436,  4442,
    4446,  4452,  4458,  4462,  4470,  4476,  4480,  4486,  4495,  4504,
    4510,  4516,  4524,  4530,  4536,  4542,  4548,  4552,  4558,  4564,
    4568,  4576,  4582,  4588,  4594,  4602,  4606,  4612,  4618,  4622,
    4628,  4632,  4638,  4644,  4651,  4659,  4664,  4670,  4676,  4684,
    4690,  4697,  4703,  4712,  4718,  4724,  4730,  4739,  4746,  4752,
    4758,  4767,  4774,  4778,  4784,  4789,  4796,  4800,  4806,  4810,
    4816,  4820,  4826,  4830,  4838,  4849,  4852,  4858,  4861,  4867,
    4873,  4881,  4885,  4891,  4894,  4900,  4910,  4913,  4919,  4929,
    4935,  4943,  4946,  4952,  4956,  4960,  4966,  4969,  4975,  4978,
    4984,  4988,  4992,  4996,  5000,  5006,  5012,  5022,  5032,  5036,
    5040,  5046,  5052,  5060,  5064,  5068,  5072,  5076,  5080,  5084,
    5088,  5094,  5098,  5102,  5106,  5112,  5118,  5126,  5134,  5138,
    5144,  5154,  5165,  5171,  5175,  5181,  5184,  5190,  5195,  5202,
    5210,  5213,  5219,  5223,  5229,  5238,  5245,  5253,  5257,  5263,
    5269,  5277,  5280,  5286,  5291,  5301,  5309,  5319,  5325,  5329,
    5335,  5339,  5343,  5349,  5355,  5359,  5363,  5367,  5373,  5381,
    5391,  5395,  5401,  5407,  5411,  5417,  5421,  5427,  5431,  5437,
    5444,  5450,  5459,  5465,  5475,  5481,  5487,  5508,  5532,  5556,
    5560,  5564,  5570,  5573,  5574,  5575,  5576,  5577,  5578,  5579,
    5580,  5581,  5582,  5583,  5584,  5585,  5586,  5587,  5588,  5589,
    5590,  5591,  5592,  5593,  5594,  5595,  5598,  5599,  5600,  5601,
    5602,  5603,  5604,  5605,  5606,  5607,  5608,  5609,  5610,  5611,
    5612,  5613,  5614,  5615,  5616,  5617,  5618,  5619,  5620,  5621,
    5622,  5623,  5624,  5625,  5626,  5627,  5628,  5629,  5630,  5631,
    5632,  5633,  5634,  5635,  5636,  5637,  5638,  5639,  5640,  5641,
    5642,  5643,  5644,  5645,  5646,  5647,  5648,  5649,  5650,  5651,
    5652,  5653,  5654,  5655,  5656,  5657,  5658,  5659,  5660,  5661,
    5662,  5663,  5664,  5665,  5666,  5667,  5668,  5669,  5670,  5671,
    5672,  5673,  5674,  5675,  5676,  5677,  5678,  5679,  5680,  5681,
    5682,  5683,  5684,  5685,  5686,  5687,  5688,  5689,  5690,  5691,
    5692,  5693,  5694,  5695,  5696,  5697,  5698,  5699,  5700,  5701,
    5702,  5703,  5704,  5705,  5706,  5707,  5708,  5709,  5710,  5711,
    5712,  5713,  5714,  5715,  5716,  5717,  5718,  5719,  5720,  5721,
    5722,  5723,  5724,  5725,  5726,  5727,  5728,  5729,  5730,  5731,
    5732,  5733,  5734,  5735,  5736,  5737,  5738,  5739,  5740,  5741,
    5742,  5743,  5744,  5745,  5746,  5747,  5748,  5749,  5750,  5751,
    5752,  5753,  5754,  5755,  5756,  5757,  5758,  5759,  5760,  5761,
    5762,  5763,  5764,  5765,  5766,  5767,  5768,  5769,  5770,  5771,
    5772,  5773,  5774,  5775,  5776,  5777,  5778,  5779,  5780,  5781,
    5782,  5783,  5784,  5785,  5786,  5787,  5788,  5789,  5790,  5791,
    5792,  5793,  5794,  5795,  5796,  5797,  5798,  5801
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
  const int xquery_parser::yylast_ = 17440;
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
#line 17633 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 5803 "/home/colea/work/new-jsoniq/build/src/compiler/parser/xquery_parser.y"

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

