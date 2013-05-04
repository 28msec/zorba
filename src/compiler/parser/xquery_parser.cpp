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
#line 1 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"

#define XQUERY_PARSER

/* Line 293 of lalr1.cc  */
#line 58 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"


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


#define YYDEBUG 1

using namespace std;
using namespace zorba;


/* Line 293 of lalr1.cc  */
#line 93 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"


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
#line 94 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 778 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"

template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}


/* Line 299 of lalr1.cc  */
#line 113 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 199 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
        case 112: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 777 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 304 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 776 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 313 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 775 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 322 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 331 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 791 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 340 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 791 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 349 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 791 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 358 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 367 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 376 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 385 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 788 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 394 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 789 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 403 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 788 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 412 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 788 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 421 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 430 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 790 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 439 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 789 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 448 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 790 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 457 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 466 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 475 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 484 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 791 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 493 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 791 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 502 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 789 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 511 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 520 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 529 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 538 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 547 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 556 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 565 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 574 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 583 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 592 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 601 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 610 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 619 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 628 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 787 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 637 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 787 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 646 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 787 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 655 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 790 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 664 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 790 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 673 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 790 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 682 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 790 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 691 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 700 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 709 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 718 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 727 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 736 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 745 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 754 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 763 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 772 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 781 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 790 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 826 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 835 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 844 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 853 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 862 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 871 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 898 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 916 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 952 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 961 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 970 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 979 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 988 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 997 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1006 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 790 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1015 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1024 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 790 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1033 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 790 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1042 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 790 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1051 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1060 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1069 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1078 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1087 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 791 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1096 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1105 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1114 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1123 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1132 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1141 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 797 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1150 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1159 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1168 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1177 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1186 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1195 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1204 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1213 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1222 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1231 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1240 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1249 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1258 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1267 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1276 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1285 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1294 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1303 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1312 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1321 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1330 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1339 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1348 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 788 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1357 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 788 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1366 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1375 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1384 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1393 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1402 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1411 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1420 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1429 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1438 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1447 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1456 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1465 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1474 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1483 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1492 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1501 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1510 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1519 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1528 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1537 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1546 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1555 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1564 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 796 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1573 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1582 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1591 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1600 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1609 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1618 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1627 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1636 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1645 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1654 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 786 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1663 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 786 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1672 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 786 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1681 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 786 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1690 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 786 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1699 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 786 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1708 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 791 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1717 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1726 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1735 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1744 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1753 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1762 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1771 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1780 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1789 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1798 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1807 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1825 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1834 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 787 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1843 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1852 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1861 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1870 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 789 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1879 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 789 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1888 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 789 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1897 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 789 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1906 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1915 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1924 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 787 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1933 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 787 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1942 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1951 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 787 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1960 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1969 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1978 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1987 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1996 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2005 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2014 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2023 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2032 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2041 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2050 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2059 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2068 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2077 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2086 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2095 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 791 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2104 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 791 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2113 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2122 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 788 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2131 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 788 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2140 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 791 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2149 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 787 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2158 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 789 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2167 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2176 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2185 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 788 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2194 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2203 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 788 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2212 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2221 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 789 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2230 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2239 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2248 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 795 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2257 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2266 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2275 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 798 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2284 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2293 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2302 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2311 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2320 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2329 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2338 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2347 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2356 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2365 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2374 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2383 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2392 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2401 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2410 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2419 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2428 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2437 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2446 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2455 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2464 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2473 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2482 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2491 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2500 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2509 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2518 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2527 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2536 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2545 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2554 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2563 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2572 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2581 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2590 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2599 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2608 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2617 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2626 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2635 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2644 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2653 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2662 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2671 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2680 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2689 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2698 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2707 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2716 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2725 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2734 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2743 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2752 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2761 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2770 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 646: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2779 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 647: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2788 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 648: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2797 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 649: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2806 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2815 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2824 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 658: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2833 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 659: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2842 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 660: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2851 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
#line 120 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2948 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 838 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 842 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 846 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 852 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 856 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 860 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 866 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 872 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 880 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 886 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 895 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 900 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 906 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 912 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 918 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));
      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 926 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 931 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 939 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 947 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 955 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 964 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 969 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 975 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 981 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 990 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 997 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1004 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1010 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 1036 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1041 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1047 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1053 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1059 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1064 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1070 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1075 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1081 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1086 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1092 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1097 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1102 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1107 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1117 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1125 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1130 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1138 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1146 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1155 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1162 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1170 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1175 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1181 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1187 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1193 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1201 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1211 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1217 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1224 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1232 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1239 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1245 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1264 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1270 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1277 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1284 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1292 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1299 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1300 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1301 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1302 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinity"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1303 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1304 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1305 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1306 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1307 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1308 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1312 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1318 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1324 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1330 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1337 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1343 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1350 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1355 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1361 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1367 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1379 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1391 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1404 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1409 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1417 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1425 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1434 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1439 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1446 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1451 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1458 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1463 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1471 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1476 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1483 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1489 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));
      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1498 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1503 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1509 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1520 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1533 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1545 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1558 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1563 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1568 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1573 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1579 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1586 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1594 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1599 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1607 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1615 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1623 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1631 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1641 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1645 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1651 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 1655 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 1662 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1671 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1682 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 1688 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 1695 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 1700 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 1707 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 1714 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 1724 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1734 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1744 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1755 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1768 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1784 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 1788 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 1792 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 1798 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 1802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 1806 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 1812 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 1817 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 1825 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 1832 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));
      blk->add((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 1839 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1866 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 1871 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 1877 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1893 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 1899 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 1905 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 1912 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 1919 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 1928 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1937 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1946 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1955 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1966 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 1972 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 1978 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 1984 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 1996 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2001 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2007 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2019 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2032 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2052 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2058 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2065 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2074 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2081 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2086 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2098 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2132 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2144 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2150 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2155 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2161 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2166 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2171 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2177 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2186 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2197 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2209 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2220 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2238 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2245 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2254 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2260 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2270 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2278 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2285 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2292 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2302 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2312 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2322 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2332 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2342 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2352 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2362 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2372 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2382 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2391 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2401 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2411 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2423 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2429 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2435 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2441 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2447 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2455 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2463 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2471 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2479 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2489 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2495 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2505 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2509 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2516 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2520 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2528 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2532 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 2536 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 2542 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 2548 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 2554 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 2560 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 2568 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 2572 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 2576 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2584 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2592 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2600 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2610 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 2616 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 2622 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 2630 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 2636 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 2644 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 2648 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 2656 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 2662 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 2668 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 2674 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2683 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2692 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2701 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2712 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 2716 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 2722 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 2728 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 2736 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 2742 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2751 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2762 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 2768 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 2776 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 2780 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 2789 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 2795 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 2801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 2809 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 2815 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 2821 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 2829 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 2835 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 2841 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 2849 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 2855 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 2862 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2872 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 2879 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 2889 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 2895 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 2903 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 2909 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 2918 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 2924 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 2932 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 2938 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 2947 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 2953 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 2961 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 2967 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 2971 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 2977 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 2982 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 2988 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 2992 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3001 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3007 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3016 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3025 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            driver.getXqueryLexer()->interpretAsLessThan();
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3029 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3038 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3047 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3056 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3067 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3071 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3082 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3086 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3091 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3095 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3101 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3105 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3111 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3115 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3119 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3125 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3129 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3135 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3141 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3147 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3155 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3159 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3163 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3169 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3173 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3179 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3187 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3191 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3199 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3203 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3211 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3215 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3223 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3227 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3235 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3239 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3245 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3249 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3255 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3259 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3263 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3267 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3275 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3279 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3283 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3289 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3294 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3300 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3304 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3308 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3312 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3316 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3320 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3326 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3330 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3334 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3340 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3344 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3348 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3352 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3361 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3367 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3375 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3381 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3389 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3393 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 3397 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 3403 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 3407 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3415 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3424 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 3433 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 3439 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3449 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 3453 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 3459 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 3464 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 3470 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 3476 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3484 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 3490 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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
#line 3500 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 3506 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 3514 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 3518 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 3522 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 3526 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 3530 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 3536 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 3542 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 3548 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 3552 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 3558 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 3562 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 3571 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 3575 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 3579 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 3585 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 3589 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 3597 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 3601 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 3607 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 3611 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 3617 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 3621 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 3625 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 3629 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 3635 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 3639 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 3643 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 3647 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 3653 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 3659 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 3667 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 3673 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 3677 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 3681 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 3685 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 3689 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 3693 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 3697 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 3701 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 3705 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 3709 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 3713 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 3717 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 3721 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 3725 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 3731 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 3735 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 3741 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 3748 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 3755 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 3764 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 3770 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 3774 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 3780 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 3786 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 3792 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 3798 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 3802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 503:

/* Line 690 of lalr1.cc  */
#line 3820 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 3826 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 3832 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 3838 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 3846 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 3850 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 3856 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 3862 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 3872 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 3876 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 3882 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 3886 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 3890 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 3896 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 3904 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 518:

/* Line 690 of lalr1.cc  */
#line 3920 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 3928 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 520:

/* Line 690 of lalr1.cc  */
#line 3946 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 521:

/* Line 690 of lalr1.cc  */
#line 3964 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 522:

/* Line 690 of lalr1.cc  */
#line 3982 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 3988 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 3997 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4003 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4012 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4022 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4027 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4033 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4037 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4043 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4049 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4055 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4062 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4070 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4074 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4080 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4086 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4092 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4099 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4108 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4112 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4118 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4122 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4128 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4132 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4136 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4141 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4148 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4152 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4156 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4160 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4166 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4171 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4177 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4182 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4188 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4194 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4199 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4204 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4209 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 4214 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 4219 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 4227 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 4233 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 4237 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 4243 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 4247 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 4253 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 4259 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 4265 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 4269 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 4275 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 4279 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 4285 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 4291 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 4295 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 4299 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 4305 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 4311 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 4317 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 4325 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 4329 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 4333 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 4337 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 4341 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 4345 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 4349 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 4355 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 4361 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 4369 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 4375 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 4381 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 4385 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 4389 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 4393 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 4397 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 4401 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 4405 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 4409 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 4413 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 4417 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 4423 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 4429 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 4433 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 4437 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 4443 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 4448 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 4454 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 4460 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 4464 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 4468 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 4474 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 4478 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 4484 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 4490 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 4494 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 4502 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 4508 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 4512 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 4518 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 4527 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 4536 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 4542 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 4548 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 4556 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 4562 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 4568 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 4574 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 4580 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 4584 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 4590 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 4596 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 4600 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 4608 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 4614 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 4620 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 4626 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 4634 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 4638 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 4644 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 4650 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 4654 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 4660 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 4664 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 4670 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 4676 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 4683 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 4691 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 4696 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 4702 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 4708 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 4716 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 4722 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 4729 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 4735 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 4744 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 4750 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 4756 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 4762 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 4771 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 4778 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 4784 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 4790 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 4799 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 4806 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 4810 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 4816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 4821 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 4828 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 4832 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 4838 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 4842 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 4848 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 4852 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 4858 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 4862 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 4870 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 4880 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 4884 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 4889 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 4893 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 4899 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 4905 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 4913 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 4917 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 4922 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 4926 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 4932 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 4941 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 4945 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 4951 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 4961 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 4967 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 4974 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 4978 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 4984 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 4988 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 4992 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 4997 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 5001 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 5006 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 5010 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 5016 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 5020 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 5024 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 5028 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 5032 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 5038 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 5044 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 5054 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 5064 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 5068 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 5072 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 5078 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 5084 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 5092 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 5096 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 5100 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 5104 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 5108 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 5112 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 5116 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 5120 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 5126 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 5130 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 5134 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 5138 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 5144 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 5150 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 5158 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 5166 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 5170 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 5176 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 738:

/* Line 690 of lalr1.cc  */
#line 5186 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 739:

/* Line 690 of lalr1.cc  */
#line 5197 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 5203 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 5207 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 5212 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 5216 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 5222 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 5227 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 5234 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 5241 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 5245 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 5251 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 5255 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 5261 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 5270 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 5277 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 5285 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 5289 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 5295 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 5301 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 5308 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 5312 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 5318 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 5323 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 5333 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 5341 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 5351 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 5357 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 5361 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 5367 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 5371 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 5375 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 5381 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 5387 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 5391 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 5395 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 5399 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 5405 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 5413 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 5423 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 5427 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 5433 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 5439 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 5443 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 5449 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 5453 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 5459 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 5463 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 5469 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 5476 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 5482 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 5491 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 5497 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 791:

/* Line 690 of lalr1.cc  */
#line 5507 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 5513 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 5519 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 794:

/* Line 690 of lalr1.cc  */
#line 5540 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 795:

/* Line 690 of lalr1.cc  */
#line 5564 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
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

  case 796:

/* Line 690 of lalr1.cc  */
#line 5588 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 5592 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 5596 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 5602 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 5608 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 5614 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 5624 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    {
          auto_ptr<QName> lQName( static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
          zstring const &tmp = lQName->get_qname();
          if ( tmp.find (':') != string::npos ) {
            error((yylocation_stack_[(1) - (1)]), "A NCName is expected, found a QName");
            YYERROR;
          }
          (yyval.sval) = SYMTAB_PUT(tmp.c_str());
        }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 5636 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 5637 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 5638 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 5639 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 5640 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 5641 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 5643 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 5644 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 5645 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 5646 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 5647 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 5648 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 5649 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 5650 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 5651 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 5655 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 5656 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 5657 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 5658 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 5659 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 5660 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 5661 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 5662 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 5663 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 5664 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 5665 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 5666 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 5667 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 5668 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 5669 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 5670 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 5671 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 5672 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 5673 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 5674 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 5675 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 5676 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 5677 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 5678 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 5679 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 5680 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 5681 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 5682 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 5683 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 5684 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 5685 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 5686 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 5687 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 5688 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 5689 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 5690 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 5691 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 5692 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 5693 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 5694 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 5695 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 5696 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 5697 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 5698 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 5699 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 5700 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 5701 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 5702 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 5703 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 5704 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 5705 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 5706 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 5707 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 5708 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 5709 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 5710 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 5711 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 5712 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 5713 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 5714 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 5715 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 5716 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 5717 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 5718 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 5719 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 5720 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 5721 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 5722 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 5723 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 5724 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 5725 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 5726 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 5727 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 5728 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 5729 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 5730 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 5731 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 5732 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 5733 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 5734 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 5735 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 5736 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 5737 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 5738 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 5739 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 5740 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 5741 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 5742 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 5743 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 5744 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 5745 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 5746 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 5747 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 5748 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 5749 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 5750 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 5751 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 5752 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 5753 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 5754 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 5755 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 5756 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 5757 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 5758 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 5759 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 5760 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 5761 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 5762 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 5763 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 5764 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 5765 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 5766 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 5767 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 5768 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 5769 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 5770 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 5771 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 5772 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 5773 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 5774 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 5775 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 5776 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 5777 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 5778 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 5779 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 5780 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 5781 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 5782 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 5783 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 5784 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 5785 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 5786 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 5787 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 5788 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 5789 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 5790 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 5791 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 5792 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 5793 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 5794 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 5795 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 5796 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 5797 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 5798 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 5799 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 5800 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 5801 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 5802 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 5803 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 5804 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 5805 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 5806 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 5807 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 5808 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 5809 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 5810 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 5811 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 5812 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 5813 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 5814 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 5815 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 5816 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 5817 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 5818 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 5819 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 5820 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 5821 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 5822 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 5823 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 5824 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 5825 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 5826 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 5827 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 5828 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 5829 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 5830 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 5831 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 5832 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 5833 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 5834 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 5835 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 5836 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 5837 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 5838 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 5839 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 5840 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 5841 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 5842 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 5843 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 5844 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 5845 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 5846 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 5847 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 5848 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 5849 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 5850 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 5851 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 5852 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1021:

/* Line 690 of lalr1.cc  */
#line 5853 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1022:

/* Line 690 of lalr1.cc  */
#line 5854 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1023:

/* Line 690 of lalr1.cc  */
#line 5855 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1024:

/* Line 690 of lalr1.cc  */
#line 5856 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1025:

/* Line 690 of lalr1.cc  */
#line 5857 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1026:

/* Line 690 of lalr1.cc  */
#line 5858 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1027:

/* Line 690 of lalr1.cc  */
#line 5859 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1028:

/* Line 690 of lalr1.cc  */
#line 5862 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12296 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1421;
  const short int
  xquery_parser::yypact_[] =
  {
      4817, -1421, -1421, -1421,  6376,  6376,  6376,  6376, -1421, -1421,
      58,   381, -1421,   710,   459, -1421, -1421, -1421,   271, -1421,
   -1421, -1421,   439,   488,   827,  4536,   564,   617,   719, -1421,
      72, -1421,   647, -1421, -1421, -1421, -1421, -1421,   853, -1421,
     686,   692, -1421, -1421, -1421, -1421,   584, -1421,   854, -1421,
     748,   775, -1421,   283, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,   831,   860,
   -1421, -1421, -1421, -1421,   629, 12596, -1421, -1421, -1421,   891,
   -1421, -1421, -1421,   907, -1421,   895,   911, -1421, -1421, 16986,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,   922, -1421,
   -1421,   930,   938, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
    5443,  8864,  9175, 16986, -1421, -1421,   909, -1421, -1421, -1421,
   -1421,   912, -1421, -1421,   942, 13492, -1421, 13796,   944,   946,
   -1421, -1421, -1421,   947, -1421, 11974, -1421, -1421, -1421, -1421,
   -1421, -1421,   917, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421,   133,   856, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421,   270,   916,   317, -1421,   -56,   182, -1421, -1421, -1421,
   -1421, -1421, -1421,   955, -1421,   834,   836,   837, -1421, -1421,
     923,   927, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421,  9486,  9797, -1421,   768, -1421,
   -1421, -1421, -1421, -1421,  5130,  6687,  1087, -1421,  6998, -1421,
   -1421,   871,    94, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421,    95, -1421, -1421,
   -1421, -1421, -1421, -1421,   127, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421,  6376, -1421, -1421, -1421, -1421,   272, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421,   162, -1421,   897,
   -1421, -1421, -1421,   632, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421,   921,   996, -1421,   973,   844,   991,   688,   598,
     766,    66, -1421,  1044,   896,   993,   994, 10730, -1421,   905,
   -1421, -1421,    53, -1421, -1421, 12285, -1421,   801, -1421,   945,
   12596, -1421,   945, 12596, -1421, -1421, -1421,   866, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421,   793, -1421, -1421, -1421, -1421, -1421,   915, -1421,
    6376,   918,   919,   920,  6376,   409,   409,  1072,   249,   532,
     749, 17274, 16986,    18,  1058, 16986,   954,   989,   385, 13492,
     794,   864, 16986, 16986,   807,   725,    44, -1421, -1421, -1421,
   13492,  6376,   925,  6376,    79, 11041, 14682, 16986, -1421,   832,
     839, 16986,   999,   321,   972, 11041,  1127,    81,   236, 16986,
    1009,   987,  1025, -1421,   948, 11041, 13195, 16986, 16986, 16986,
    6376,   950, 11041, 11041, 16986,  6376,   980,   984, -1421, -1421,
   -1421, 11041, 14970,   982, -1421,   983, -1421, -1421, -1421, -1421,
     988, -1421,   990, -1421, -1421, -1421, -1421, -1421,   992, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, 16986, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421,   998, 16986, -1421, -1421, -1421,   964,  5754,  1024,   309,
     997,  1001,  1002, 16986,  6376, -1421,  1006,    93, -1421,   648,
   -1421,   102,  1115, 11041, 11041, -1421, -1421,   169, -1421, -1421,
   -1421,  1135, -1421, -1421, -1421, -1421, 11041,   949, -1421,  1132,
   11041, 11041, 14097,   975, 11041, 11041, 11041, 11041, 14097, 11041,
     933,   935, 16986,   976,   978, 11041, 11041,  5443,   924, -1421,
      64, -1421,    42, 11041,  6687, -1421, -1421, -1421, -1421, -1421,
     710,   719,   104,   122,  1168,  7309,  3270,  7620,  3592,   907,
   -1421, -1421,   199,   907, -1421, 11041,  4214, -1421,  1052,   527,
      72,  1004,  1003,  1017,  6376, 11041, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, 11352, 11352, 11352, -1421, 11352, 11352,
   -1421, 11352, -1421, 11352, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, 11352, 11352,  1103, 11352, 11352, 11352, 11352, 11352, 11352,
   11352, 11352, 11352, 11352, 11352, 11352,   957,  1094,  1095,  1096,
   -1421, -1421, -1421, 11663, 10108, -1421, -1421, 11974, 11974, 11041,
     945, -1421, -1421,   945, -1421,  7931,   945,  1042,  8242, -1421,
   -1421, -1421, -1421,    35, -1421,   319, -1421, -1421, -1421, -1421,
   -1421, -1421,  1085,  1086,   564,  1166, -1421, -1421, 17274,   962,
     694, 16986,  1035,  1036,   962,  1072,  1070,  1066, -1421, -1421,
   -1421,   170,   956,  1105,   902, 16986,  1060, 11041,  1088, 16986,
   16986, -1421,  1071,  1021, -1421,  1022,   983,   692, -1421,  1023,
    1026,   245, -1421,   331,   431,  1100, -1421,    38, -1421, -1421,
    1100, 16986,    34, 16986,  1114,   452, -1421,  6376, -1421,   106,
   -1421, 13492,  1117,  1167, 13492,  1072,  1118,   281, 16986, 11041,
      72, -1421,   310,  1029, -1421,  1030,  1031,  1032,    48, -1421,
     293,  1027, -1421,   151,   167,  1067, -1421,  1039,  6376,  6376,
     359, -1421,   475,   484,   516, 11041,    86, -1421, -1421, 11041,
   11041, -1421, 11041, 11041, 11041, -1421, 11041, -1421, 11041, -1421,
   16986,  1115, -1421,   285,   373,   391, -1421, -1421, -1421,   392,
   -1421,   432, -1421, -1421,  1073,  1074,  1075,  1076,  1077,   866,
     793, -1421,     5,   144,   124,   141,  1125,   506,   995,  1000,
    1007,    37, -1421,  1081, -1421, -1421,  1043,   183,  5754,   406,
   12898,   924, -1421, -1421, -1421,  1008, -1421,   871,   787,  1193,
     675, -1421, -1421,   126, -1421, -1421, -1421,   131, -1421,    61,
   -1421, -1421, -1421, -1421, -1421,  3903, -1421, -1421, -1421, 16986,
    1065, 11041,  1120, -1421, -1421, -1421,   996, -1421, -1421, -1421,
   -1421, -1421, 11352, -1421, -1421, -1421,    55, -1421,   598,   598,
      43,   766,   766,   766,   766,    66,    66, -1421, -1421, 16122,
   16122, 16986, 16986, -1421, -1421,   444, -1421, -1421,   139, -1421,
   -1421, -1421, -1421,   490, -1421, -1421,   500,   409, -1421, -1421,
     779,   780,   797, -1421,   564, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421,   962, -1421,  1107, 16410,  1099,
   11041, -1421, -1421, -1421,  1149,  1072,  1072,   962, -1421,   899,
    1072,   711, 16986,   695,   701,  1216, -1421, -1421,   960,   645,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421,   170,    84,  1020,   473, 11041, -1421, 16986,  1153,   951,
    1072, -1421, -1421, -1421, -1421,  1097, 16986, -1421, 16986, -1421,
   16698,  1121, 16122,  1133, 11041,   -21,  1106,    33,   493,  1005,
   -1421, -1421,   819,    34,  1149, 16122,  1134,  1160,  1079,  1059,
    1123,  1072,  1104,  1131,  1161,  1072, 11041,   -18, -1421, -1421,
   -1421,  1112, -1421, -1421, -1421, -1421,  1148, 11041, 11041,  1129,
   -1421,  1170,  1174,  6376, -1421,  1084,  1098,  1124, 16986, -1421,
   16986, -1421, 11041,  1126,  1089, 11041, -1421,  1158,   195,   197,
     200,  1248, -1421,   443, -1421,   387,  1137, -1421, -1421,  1256,
   -1421,   738, 11041, 11041, 11041,   790, 11041, 11041, 11041, 11041,
   11041, 11041, 11041, 11041, 11041, 14097,  1173, 11041, 11041, -1421,
    8553,   165,  1041, -1421,    24, -1421, 11041,   140,    76,    61,
    7620,  3592,  7620,  1207, -1421, -1421, 11041,   806,  1185, -1421,
   16986,  1186, -1421, -1421, 11041,    55,   644,   396, -1421,  1010,
     202,  1040,  1037, -1421, -1421,   864, -1421,  1034,   606,  1142,
    1145, 16410,  1147,  1151,  1154,  1155,  1156, -1421,   546, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421,  1165, -1421, -1421, -1421, -1421, 10419, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421,   798, -1421,  1277,
     835, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
    1028, -1421, -1421,  1286, -1421, -1421, -1421, -1421, -1421,   652,
    1287, -1421,   696, -1421, -1421, -1421,   982,   488,   647,   988,
     686,   990,   992,   916,  1151,  1154,  1155, -1421,   546,   546,
   11663,  1033,  1011, -1421,  1149,    84,  1091,  1138,  6376,  1140,
    1144,  1176,  1146,  1150, 16986, -1421,   471, -1421, 16986, -1421,
   11041,  1171, 11041,  1197, 11041,   186,  1184, 11041,  1190, -1421,
    1215,  1220, 11041, 16986,   937,  1262, -1421, -1421, -1421, -1421,
   -1421, -1421, 16122, -1421,  6376,  1072,  1233, -1421, -1421, -1421,
    1072,  1233, -1421, 11041,  1199,  6376, 16986, -1421, -1421, 11041,
   11041,   640, -1421,   115,   823, -1421, 15258,   841, -1421,   842,
   -1421,  1159, -1421, -1421,  6376,  1157,  1162, -1421, 11041, -1421,
   -1421, 11041,  1152,  1170,  1244, -1421,  1214, -1421,   463, -1421,
   -1421,  1342, -1421, -1421,  6376, 16986, -1421,   671, -1421, -1421,
   -1421,  6376,  1175,  1119,  1122, -1421, -1421, -1421,  1128,  1130,
   -1421, -1421, -1421,  1254, -1421, -1421, -1421, -1421,  1136,    13,
   16986,  1172, -1421,  1200,  1203,  1209,  1202, -1421,   897,   714,
   12898,  1041, -1421,  6065, 12898, -1421, -1421,  1193,   502, -1421,
   -1421, -1421,  1185, -1421,  1072, -1421,   901, -1421,   528,  1257,
   -1421, 11041,   743,  1120,   469,  1180, -1421,    55,  1139, -1421,
   -1421,   -33, -1421,   635,   109,  1141,    55,   635, 11352, -1421,
     264, -1421, -1421, -1421, -1421, -1421, -1421,    55,  1221,  1090,
     956,   109, -1421, -1421,  1092,  1291, -1421, -1421, -1421, 14394,
    1188,  1189,  1192,  1195,  1201,  1208,  1210, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
    1348,    40,  1351,    40,  1116,  1263, -1421, -1421,  1226, 16986,
    1143, -1421, -1421, 11663, -1421,  1218, -1421, -1421, -1421, -1421,
   -1421, -1421, 11041,  1250, -1421, -1421, 11041, -1421,   571, -1421,
   11041,  1251, 11041, -1421, 11041, 16986, 16986, -1421,   815, -1421,
   11041, -1421,  1282,  1283,  1314,  1072,  1233, -1421, 11041,  1229,
   -1421, -1421, -1421,  1230, -1421,   292, 11041,  6376,  1231,   365,
   -1421, 16986,   225, -1421, 15546,    45, -1421, 15834,  1232, -1421,
   -1421,  1235, -1421, -1421, -1421, -1421, 11041,   846,  1248, 16986,
     753, -1421,  1237,  1248, 16986, -1421,  1238, -1421, 11041, 11041,
   11041, 11041,  1108, 11041, 11041, -1421, 11041, 11041, 11041, 11041,
    8553,    25, -1421, -1421, -1421, -1421, -1421,  1257, -1421, -1421,
   -1421,  1072, 11041, -1421,  1272, -1421, -1421, -1421, -1421,  1239,
   11352, -1421, -1421, -1421, -1421, -1421,   551, 11352, 11352,   586,
   -1421,  1040, -1421,   620, -1421,  1037,    55,  1271, -1421, -1421,
    1164, -1421, -1421, -1421, -1421,  1331,  1245, -1421,   526, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421,    91,    91, -1421,
      40, -1421, -1421,   530, -1421,  1402,   109,  1336,  1247, 11663,
      19,  1163,  1266, -1421, -1421, 11041, -1421, 11041,  1289, -1421,
   11041, -1421, -1421, -1421,  1384, -1421, -1421,  8553, 11041,  1072,
   -1421, -1421, -1421, 11041, 11041, -1421, -1421, -1421,  8553,  8553,
    1344,  6376, 16122, 16986,   478, 16986, 11041, 16986,   602,  8553,
   -1421,   446,   278,  1248, 16986, -1421,  1249,  1248, -1421, -1421,
   -1421, -1421, -1421, 11041, -1421, -1421, -1421,   211,   228,   233,
   11041, -1421, -1421, -1421,  1338, 11041, -1421,   766, 11352, 11352,
      43,   689, -1421, -1421, -1421, -1421, -1421, -1421, 11041, -1421,
   16122, -1421, 16122,  1352, -1421, -1421, -1421,  1419, -1421, -1421,
   -1421,  1187,  1341, -1421, -1421,  1343, -1421,    97, 16986,  1334,
    1234, 16986, 11663, -1421, -1421, 11041, -1421,  1335, -1421, -1421,
    1233, -1421, -1421, 16122, -1421, -1421, -1421,  1360, 11041,  1270,
   -1421,  1362,  8553, -1421, 16986,   518,   716, -1421,  1261,  1248,
   -1421,  1264, -1421,  1265,  1170,  1174,   470, -1421,  1338,    43,
      43, 11352,   483, -1421, -1421, 16122, -1421, -1421,  1336, 11663,
   -1421,  1257,  1169, 16986,  1345,  1240,  1343, -1421, 16986,   709,
   16122,  6376, 16122,  1274, -1421, -1421,  1368,   558, -1421, -1421,
   -1421, -1421,  1284,   833, -1421, -1421, -1421,  1269, -1421,  8553,
     848, -1421, -1421,    43, -1421, -1421, -1421, -1421, -1421, 11041,
    1177, 16986,  1349, -1421,  6376,   712, -1421, -1421,   715, 11041,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421,  1350, -1421,  1178,
    1179, 16986, -1421, -1421, 11041,  8553, 16986,  1181, 11041,  1183,
    1290, 11663, -1421, 11663,  8553, -1421,  1273,  1191, 16986,  1252,
    1354, 16986,  1194, 11663, -1421
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       165,   466,   467,   468,   168,   168,   168,     0,   823,  1028,
     120,   122,   632,   915,   924,   864,   828,   826,   807,   916,
     919,   871,   832,   808,   810,     0,   925,   812,   922,   893,
     873,   848,   809,   868,   869,   920,   917,   867,   814,   923,
     815,   816,   964,   976,   963,   865,   884,   878,   817,   866,
     819,   818,   965,   902,   903,   870,   845,   986,   987,   988,
     989,   990,   991,   992,   993,   994,   995,   996,  1010,  1017,
     892,   888,   879,   859,   806,     0,   887,   895,   904,  1011,
     883,   492,   860,   861,   918,  1012,  1018,   880,   897,     0,
     498,   455,   494,   890,   825,   881,   882,   911,   885,   901,
     910,  1016,  1019,   831,   872,   913,   493,   900,   906,   811,
       0,     0,     0,     0,   401,   898,   909,   914,   912,   891,
     877,   966,   875,   876,  1013,     0,   400,     0,  1014,  1020,
     907,   862,   886,  1015,   433,     0,   465,   908,   889,   896,
     905,   899,   967,   853,   858,   857,   856,   855,   854,   820,
     874,     0,   824,   921,   846,   957,   956,   958,   830,   829,
     849,   955,   813,   953,   960,   954,   952,   852,   894,   951,
     962,   961,   950,   850,   959,   971,   972,   969,   970,   968,
     821,   973,   974,   975,   941,   940,   927,   844,   837,   934,
     930,   847,   843,   942,   943,   833,   834,   827,   836,   939,
     938,   935,   931,   948,   949,   947,   937,   933,   926,   835,
     946,   945,   839,   841,   840,   932,   936,   928,   842,   929,
     838,   944,   997,   998,   999,  1000,  1001,  1002,   978,   979,
     977,   983,   984,   985,   980,   981,   982,   851,  1003,  1004,
    1005,  1006,  1007,  1008,  1009,     0,     0,  1022,  1023,  1021,
    1026,  1025,  1024,  1027,   165,   165,     0,     2,   165,     9,
      11,    23,     0,    28,    31,    36,    37,    38,    39,    40,
      41,    42,    32,    58,    59,    33,    34,     0,    76,    79,
      80,    35,    81,    82,     0,   118,    83,    84,    85,    86,
      18,   162,   163,   164,   171,   174,   485,   175,     0,   176,
     177,   178,   179,   180,   181,   182,   185,     0,   211,   219,
     214,   246,   252,     0,   244,   245,   221,   215,   184,   216,
     183,   217,   220,   352,   354,   356,   366,   368,   372,   374,
     377,   382,   385,   388,   390,   392,   394,     0,   398,   405,
     404,   406,     0,   424,   407,   429,   432,   434,   437,   439,
       0,   444,   441,     0,   452,   462,   464,   438,   469,   476,
     490,   477,   478,   479,   482,   483,   480,   484,   507,   508,
     481,   511,   513,   514,   515,   512,   560,   561,   562,   563,
     564,   565,   566,   461,   605,   596,   604,   603,   602,   601,
     598,   600,   597,   599,   491,    43,   222,   223,   225,   224,
     226,   218,   487,   488,   489,   486,   228,   231,   227,   229,
     230,   463,   805,   822,   915,   924,   922,   824,     0,   166,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,   256,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   274,   275,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   457,   460,
     447,     0,     0,   807,   832,   810,   863,   925,   812,   873,
     814,   884,   817,   819,   818,   902,  1010,  1017,   806,  1011,
     861,  1012,  1018,   885,  1016,  1019,   909,   966,  1013,  1014,
    1020,  1015,   967,   955,   953,   954,   952,   850,   971,   972,
     969,   821,   973,  1023,   453,   805,   445,     0,   192,   446,
     449,   807,   808,   810,   809,   814,   815,   816,   817,   806,
     813,   495,     0,   451,   450,   187,     0,     0,   211,     0,
     812,   819,   818,     0,   168,   780,   973,     0,   219,     0,
     496,     0,   527,     0,     0,   456,   803,     0,   804,   427,
     428,     0,   459,   458,   448,   431,     0,     0,   556,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   782,
       0,   784,     0,     0,   165,     3,     4,     1,    10,    12,
       0,     0,     0,     0,     6,   165,     0,   165,     0,     0,
     119,   172,     0,     0,   190,     0,     0,   199,     0,     0,
       0,     0,     0,     0,     0,     0,   204,   232,   251,   247,
     253,   248,   250,   249,     0,     0,     0,   417,     0,     0,
     415,     0,   361,     0,   416,   409,   414,   413,   412,   411,
     410,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     403,   402,   399,     0,     0,   425,   430,     0,     0,     0,
     440,   473,   443,   442,   454,     0,   470,     0,     0,   568,
     570,   574,   576,     0,   124,     0,   802,    47,    44,    45,
      48,    49,     0,     0,     0,     0,    50,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   639,   640,
     641,     0,   103,   142,     0,     0,   112,     0,     0,     0,
       0,   127,     0,     0,   612,     0,     0,     0,   607,     0,
       0,     0,   622,     0,     0,   255,   257,     0,   234,   235,
     254,     0,     0,     0,   134,     0,   138,   168,   510,     0,
      60,     0,    69,     0,     0,     0,    61,     0,     0,     0,
       0,   610,     0,     0,   613,     0,     0,     0,     0,   323,
       0,     0,   611,     0,     0,     0,   630,     0,     0,     0,
       0,   616,     0,     0,   194,     0,     0,   188,   186,     0,
       0,   786,     0,     0,     0,   495,     0,   781,     0,   497,
     528,   527,   524,     0,     0,     0,   558,   557,   426,     0,
     555,     0,   652,   653,     0,     0,     0,     0,     0,   793,
       0,   606,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   658,     0,   202,   203,     0,     0,     0,     0,
       0,   207,   208,   783,   785,     0,     5,    24,     0,    25,
       0,     7,    29,     0,    15,     8,    30,     0,    19,   915,
      77,    16,    78,    20,   193,     0,   191,   212,   213,     0,
       0,     0,     0,   205,   233,   292,   353,   355,   359,   365,
     364,   363,     0,   360,   357,   358,     0,   369,   376,   375,
     373,   379,   380,   381,   378,   383,   384,   387,   386,     0,
       0,     0,     0,   408,   422,     0,   435,   436,     0,   474,
     503,   471,   505,     0,   509,   501,     0,     0,   121,   123,
       0,     0,     0,   102,     0,    92,    94,    95,    96,    97,
      99,   100,   101,    93,    98,    88,    89,     0,     0,   108,
       0,   104,   106,   107,   114,     0,     0,    87,    46,     0,
       0,     0,     0,     0,     0,     0,   730,   735,     0,     0,
     731,   765,   718,   720,   721,   722,   724,   726,   725,   723,
     727,     0,     0,     0,     0,     0,   111,     0,   144,     0,
       0,   573,   567,   608,   609,     0,     0,   626,     0,   623,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,   237,     0,   242,   140,     0,     0,   135,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,   273,   279,
     276,     0,   615,   614,   621,   629,     0,     0,     0,     0,
     572,     0,     0,     0,   418,     0,     0,     0,     0,   619,
       0,   617,     0,   195,     0,     0,   787,     0,     0,     0,
       0,   527,   525,     0,   516,     0,     0,   499,   500,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
       0,     0,     0,   666,     0,   209,     0,     0,     0,     0,
     165,     0,   165,     0,   173,   243,     0,   307,   303,   305,
       0,   293,   294,   362,     0,     0,     0,     0,   696,   370,
     669,   673,   675,   677,   679,   682,   689,   690,   698,   925,
     811,     0,   820,  1026,  1025,  1024,  1027,   389,   579,   585,
     586,   589,   633,   634,   590,   591,   796,   797,   798,   594,
     391,   393,   396,   595,   395,   423,   475,     0,   472,   502,
     125,    56,    57,    54,    55,   131,   130,     0,    90,     0,
       0,   109,   110,   115,    74,    75,    52,    53,    73,   736,
       0,   739,   766,     0,   729,   728,   733,   732,   764,     0,
       0,   741,     0,   737,   740,   719,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   146,   148,
       0,     0,     0,   113,   116,     0,     0,     0,   168,     0,
       0,   630,     0,     0,     0,   259,     0,   578,     0,   260,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,     0,     0,     0,   286,     0,   283,   288,   241,   141,
     136,   139,     0,   189,     0,     0,    71,    65,    68,    67,
       0,    63,   277,     0,     0,   168,     0,   321,   325,     0,
       0,     0,   328,     0,     0,   334,     0,     0,   341,     0,
     345,     0,   420,   419,   168,     0,     0,   196,     0,   198,
     322,     0,     0,     0,     0,   528,     0,   518,     0,   551,
     548,     0,   552,   553,     0,     0,   547,     0,   522,   550,
     549,     0,     0,     0,     0,   645,   646,   642,     0,     0,
     650,   651,   647,   789,   790,   656,   794,   654,     0,     0,
       0,     0,   660,   812,   819,   818,   973,   201,     0,     0,
       0,   661,   662,     0,     0,   210,   792,    26,     0,    17,
      21,    22,   304,   316,     0,   317,     0,   308,   309,   310,
     311,     0,   296,     0,     0,     0,   680,   693,     0,   367,
     371,     0,   712,     0,     0,     0,     0,     0,     0,   668,
     670,   671,   707,   708,   709,   711,   710,     0,     0,   684,
     683,     0,   687,   691,   705,   703,   702,   695,   699,     0,
       0,     0,     0,     0,     0,     0,     0,   582,   584,   583,
     580,   397,   504,   506,   133,   132,    91,   105,   753,   734,
       0,   758,     0,   758,   747,   742,   147,   149,     0,     0,
       0,   117,   145,     0,    27,     0,   627,   628,   631,   624,
     625,   258,     0,     0,   272,   264,     0,   268,     0,   262,
       0,     0,     0,   281,     0,     0,     0,   240,   284,   287,
       0,   137,     0,     0,    70,     0,    64,   278,     0,     0,
     324,   326,   331,     0,   329,     0,     0,     0,     0,     0,
     335,     0,     0,   349,     0,     0,   342,     0,     0,   346,
     421,     0,   620,   618,   197,   788,     0,     0,   527,     0,
       0,   559,     0,   527,     0,   523,     0,    14,     0,     0,
       0,     0,     0,     0,     0,   659,     0,     0,     0,     0,
       0,     0,   663,   667,   320,   318,   319,   312,   313,   314,
     306,     0,     0,   301,     0,   295,   697,   688,   694,     0,
       0,   767,   768,   778,   777,   776,     0,     0,     0,     0,
     769,   674,   775,     0,   672,   676,     0,     0,   681,   685,
       0,   706,   701,   704,   700,     0,     0,   592,     0,   587,
     638,   581,   800,   801,   799,   588,   754,     0,     0,   752,
     759,   760,   756,     0,   751,     0,   749,     0,     0,     0,
       0,     0,     0,   569,   261,     0,   270,     0,     0,   266,
       0,   269,   282,   290,   291,   285,   239,     0,     0,     0,
      66,   280,   575,     0,     0,   332,   336,   330,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     571,     0,     0,   527,     0,   554,     0,   527,   577,   643,
     644,   648,   649,     0,   655,   795,   657,     0,     0,     0,
       0,   664,   315,   302,   297,     0,   692,   779,     0,     0,
     771,     0,   717,   716,   715,   714,   713,   678,     0,   770,
       0,   635,     0,     0,   763,   762,   761,     0,   755,   748,
     746,     0,   743,   744,   738,   150,   152,   154,     0,     0,
       0,     0,     0,   265,   263,     0,   271,     0,   206,   351,
      72,   327,   333,     0,   347,   343,   350,     0,     0,     0,
     337,     0,     0,   339,     0,   537,   531,   526,     0,   527,
     517,     0,   791,     0,     0,     0,     0,   300,   298,   773,
     772,     0,     0,   636,   593,     0,   757,   750,     0,     0,
     156,   155,     0,     0,     0,     0,   151,   267,     0,     0,
       0,     0,     0,     0,   545,   539,     0,   538,   540,   546,
     543,   533,     0,   532,   534,   544,   519,     0,   520,     0,
       0,   665,   299,   774,   686,   637,   745,   153,   157,     0,
       0,     0,     0,   289,     0,     0,   340,   338,     0,     0,
     530,   541,   542,   529,   535,   536,   521,     0,   158,     0,
       0,     0,   348,   344,     0,     0,     0,     0,     0,     0,
       0,     0,   160,     0,     0,   159,     0,     0,     0,     0,
       0,     0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1421, -1421,  -217,  -191, -1421,  1213,  1222, -1421,  1223,  -544,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
    -998, -1421, -1421, -1421, -1421,  -225,  -596, -1421,   742,   -11,
   -1421, -1421, -1421, -1421, -1421,   291,   513, -1421, -1421,     4,
    -176,  1061, -1421,  1045, -1421, -1421,  -656, -1421,   450, -1421,
     257, -1421,  -219,  -265, -1421,  -549, -1421,    -3,    51,     6,
    -234,  -173, -1421,  -869, -1421, -1421,   370, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421,   624,   -96,  1475,
       0, -1421, -1421, -1421, -1421,   467, -1421, -1421,  -304, -1421,
      23, -1421,  1046,  -930,  -747,  -726, -1421, -1421,   706, -1421,
   -1421,    27,   238, -1421, -1421, -1421,   123, -1142, -1421,   382,
     128, -1421, -1421,   132, -1317, -1421,   959,   226, -1421, -1421,
     222, -1037, -1421, -1421,   220, -1421, -1421, -1264, -1249, -1421,
     217, -1420, -1421, -1421,   863,   867, -1421,  -559,   845, -1421,
   -1421,  -658,   326,  -641,   351,   372, -1421, -1421, -1421,   589,
   -1421, -1421,  1196, -1421, -1421, -1421, -1421, -1421,  -874,  -321,
    -675, -1421,  -101, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
     -24,  -826, -1421,  -546,   661,   275, -1421,  -400, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421,   816, -1421, -1421, -1421, -1421,
   -1031, -1421,   205, -1421,   697,  -817, -1421, -1421, -1421, -1421,
   -1421,  -258,  -251, -1229,  -971, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421,  -765,  -863,  -170,  -815,
   -1421, -1421, -1421,  -808, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421,  1078,  1080,  -360,   511,   341, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,   181, -1421,
   -1421,   174, -1421,   176, -1082, -1421, -1421, -1421,   142,   135,
     -37,   407, -1421, -1421, -1421, -1421, -1421, -1421, -1421, -1421,
   -1421, -1421, -1421, -1421, -1421,   145, -1421, -1421, -1421,   -29,
     401,   547, -1421, -1421, -1421, -1421, -1421,   335, -1421, -1421,
   -1388, -1421, -1421, -1421,  -537, -1421,   107, -1421,   -51, -1421,
   -1421, -1421, -1421, -1318, -1421,   155, -1421, -1421, -1421, -1421,
   -1421,   961, -1421, -1421, -1421, -1421, -1421,  -916, -1421, -1421,
   -1421,  -394,  -370,   952,   255, -1421
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   256,   636,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
    1276,   785,   274,   275,   276,   277,   278,   279,   965,   966,
     967,   280,   281,   282,   971,   972,   973,   283,   445,   284,
     285,   713,   286,   447,   448,   449,   464,   775,   776,   287,
    1227,   288,  1705,  1706,   289,   290,   291,   556,   292,   293,
     294,   295,   296,   778,   297,   298,   538,   299,   300,   301,
     302,   303,   304,   646,   305,   306,   871,   872,   307,   308,
     568,   310,   647,   462,  1032,  1033,   311,   648,   312,   650,
     569,   314,   765,   766,  1264,   471,   315,   472,   473,   772,
    1265,  1266,  1267,   651,   652,  1131,  1132,  1553,   653,  1128,
    1129,  1377,  1378,  1379,  1380,   316,   798,   799,   317,  1291,
    1292,  1495,   318,  1294,  1295,   319,   320,  1297,  1298,  1299,
    1300,  1502,   321,   322,   323,   324,   912,   325,   326,  1389,
     327,   328,   329,   330,   331,   332,   333,   334,   335,  1171,
     336,   337,   338,   339,   671,   672,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   706,   701,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   943,   367,   368,   369,   370,
     371,   372,  1327,   831,   832,   833,  1737,  1782,  1783,  1776,
    1777,  1784,  1778,  1328,  1329,   373,   374,  1330,   375,   376,
     377,   378,   379,   380,   381,   382,  1027,  1503,  1430,  1158,
    1588,  1159,  1172,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   805,  1240,   394,  1161,  1162,  1163,
    1164,   395,   396,   397,   398,   399,   400,   861,   862,   401,
    1361,  1362,  1671,  1114,  1139,  1399,  1400,  1140,  1141,  1142,
    1143,  1144,  1409,  1578,  1579,  1145,  1412,  1146,  1559,  1147,
    1148,  1417,  1418,  1584,  1582,  1401,  1402,  1403,  1404,  1685,
     742,   992,   993,   994,   995,   996,   997,  1213,  1608,  1702,
    1214,  1606,  1700,   998,  1443,  1603,  1599,  1600,  1601,   999,
    1000,  1405,  1413,  1569,  1406,  1565,  1390,   402,   403,   404,
     405,   559,   406,   407,   408,   409,   410,  1165,  1166,  1167,
    1168,  1277,   577,   411,   412,   413
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -864;
  const short int
  xquery_parser::yytable_[] =
  {
       309,   418,   421,   422,   309,   309,   309,   309,   608,   649,
     420,   420,   420,   424,  1083,   567,   571,   446,   933,   920,
    1025,   695,  1047,   313,  1293,   714,   714,   313,   313,   313,
     313,   890,   892,   717,   585,  1059,   623,   921,   922,   923,
     924,  1026,  1137,   624,  1113,   626,   849,  1281,  1506,  1073,
    1517,   534,   857,  1385,  1326,   419,   419,   419,   423,   631,
     628,  1548,  1549,   615,   616,   624,  1157,  1170,   952,   737,
    1253,    10,    11,   782,   786,  1021,   884,   888,   891,   893,
     752,   882,   886,  1186,  1644,    12,  1229,  1648,    10,    11,
    1245,  1029,   431,  1580,   624,   624,   624,   908,  1525,   909,
     910,  1091,   911,   624,   913,   624,   795,   624,   630,   431,
     309,   716,   914,   915,   427,   428,   557,   429,   430,   432,
     434,  1160,  1160,   624,  1216,   756,  1283,   624,  1250,  1217,
     756,  1023,   624,   313,  1022,   433,  1023,   434,  1218,  1708,
     624,   624,   435,   757,   947,  1219,  1106,  1220,   757,   610,
     612,   635,   624,  1190,    10,    11,  1221,  1056,   748,  1247,
    1160,   419,  -169,   624,   587,  1645,   624,    81,   624,   699,
     597,   705,  1270,   635,   436,   437,  1123,   836,  1597,  1363,
    1670,    92,  1254,  1222,   624,  1561,   631,  1024,   726,  1440,
     631,  1368,   469,  1022,  1228,  1056,   624,   632,   624,  -170,
     624,   624,   635,   675,   684,  1374,   106,  1566,   694,  1193,
    1134,   635,   624,  1135,  1160,   635,   425,  1496,   685,  1703,
     676,   727,  1562,   948,  1092,  1093,   981,  1160,   982,   624,
    1672,   127,  1646,   127,   624,  1364,  1364,  1057,   439,  1094,
    1095,   629,  1598,   781,   696,  1709,   624,   819,   635,  1442,
     820,  1534,  1030,   470,   309,   309,   470,  1499,   309,   598,
     635,  1137,  1137,  1258,  1316,   649,   716,   758,  1506,  1269,
     630,   635,   983,  1107,   635,  1075,   635,   313,   313,   827,
    1255,   313,  1486,   890,   892,   625,   627,  1326,  1701,  1031,
     829,  1525,   635,   309,  1039,   877,  1326,   440,  1187,  1251,
    1391,  1256,  1497,  1769,   635,  1558,   635,   470,   635,   635,
    1223,   624,   470,   879,  1461,  1136,   313,  1120,  1435,  1229,
     635,  1284,  1122,   631,   632,  1176,   702,  1710,   632,   704,
     535,  1367,   749,   882,   886,  1470,  1421,   635,   441,  1061,
     750,   978,   635,  1160,   535,   837,   470,  -169,   588,   442,
    1805,   783,  1808,  1133,   635,  1062,   874,   443,  1099,   761,
     624,   484,  1391,  1096,  1097,   444,  1567,  1568,   535,   779,
    1796,  1110,  1392,  1735,   624,  1100,   873,  1022,  1098,   792,
     535,   633,   535,  1312,  -170,  1313,   803,   804,  1314,  1022,
    1760,  1044,   624,   624,  1496,   810,  1319,  1320,   784,  1743,
     883,   887,  1224,  1225,  1226,   878,   880,   624,   599,  1481,
     903,  1040,  1641,   600,  1043,   895,  1744,  1084,   820,   635,
     309,  1745,   984,   876,   309,  1046,   451,  1228,   947,   452,
    1015,   732,   718,   733,  1392,   985,  1642,   986,   485,    12,
    1016,   773,  1058,   313,  1798,   624,   719,   313,   987,   988,
     989,   309,   990,   309,   991,  1393,  1394,   424,  1395,   424,
     470,   632,  1736,   634,  1160,  1396,   734,  1496,   635,  1451,
     624,   624,  1319,  1320,   313,  1397,   313,   834,   835,  1634,
     309,  1790,   635,  1085,   624,   309,   424,  1398,  1160,  1326,
     839,   424,  1321,   735,   821,  1051,   590,   601,   591,  1463,
     635,   635,   753,   313,   755,   486,   487,   949,   313,   774,
     867,   869,  1322,  1137,  1323,   635,  1138,  1393,  1394,  1017,
    1395,    81,  1137,  1774,   890,   892,   890,  1319,   457,  1471,
     458,   801,  1747,  1137,  1113,    92,   807,  1397,  1543,   426,
    1018,  1506,  1324,   594,  1067,   595,   113,  1180,   732,  1398,
     733,  1387,  1639,   635,   736,  1448,  1587,   309,  1086,  1349,
     106,  1036,   125,  1774,   309,  1089,  1734,  1319,  1321,  1023,
     420,  1369,  1370,  1371,   127,  1317,  1087,  1088,   635,   635,
     313,  1194,  1195,  1325,  1068,   592,  1198,   313,  1322,  1022,
    1323,  1112,   635,  1070,   453,   459,   936,   937,   935,  1177,
     460,   151,  1102,   938,  1678,   535,  1792,   309,   535,  1177,
     735,  1160,  1022,   868,   309,   419,  1237,  1554,  1324,  1019,
    1462,   450,   113,  1090,   446,   309,   309,   309,   309,  1175,
     313,  1720,   596,  1646,   631,  1692,  1374,   313,   125,  1697,
    1037,  1318,  1257,  1322,   309,  1323,   454,   461,   313,   313,
     313,   313,  1117,  1775,  1556,  1791,  1239,  1376,  1242,  1519,
    1072,  1124,   699,  1069,   705,  1728,  1121,   313,  1794,  1023,
     880,   736,  1071,  1324,    12,   638,   885,   151,  1178,   639,
    1319,  1320,  1679,  1322,   640,  1323,   724,   535,  1179,  1642,
     535,   638,  1427,  1811,   535,   639,  1160,   535,   535,  1160,
     640,  1652,  1137,   641,   479,   535,  1656,  1499,  1305,  1119,
    1306,   535,   535,  1324,  1693,   720,   535,   678,  1698,   641,
    1617,  1618,   463,  1428,   535,  1319,  1078,  1079,  1080,   721,
     869,   535,   535,   535,   535,  1138,  1138,    10,    11,   535,
    1573,  1429,  1290,  1210,   466,  1780,   679,   535,   427,   428,
    1440,   429,   430,   490,   467,  1493,    81,   638,   431,   680,
    1211,   639,  1319,  1320,  1779,  1785,   640,  1441,   432,   433,
      92,   890,  1111,  1231,  1038,   465,  1321,   309,  1612,  1726,
     675,   468,  1232,   420,   491,   641,   434,   492,   885,  1732,
     968,   435,   535,   681,  1210,   106,  1322,   676,  1323,  1134,
     313,   642,  1135,  1212,   643,   474,  1779,   535,   309,   309,
    1442,  1211,  1785,  1642,   424,   424,   695,   642,   535,   644,
     643,  1118,   127,   436,   437,   438,  1324,  1753,   419,  1754,
     113,   313,   313,   969,  1160,   828,  1738,   621,   970,  1022,
    1741,  1322,  1319,  1323,   477,   645,   125,   850,   675,   675,
     478,  1551,  1781,   850,  1414,  1415,  1682,   535,  1321,  1065,
    1066,   645,  1780,  1683,   746,   676,   676,  1524,   309,   747,
    1260,  1324,   439,  1684,  1260,  1261,  1357,  1416,  1322,  1261,
    1323,  1484,  1160,   642,  1160,   151,   643,  1552,   677,  1751,
    1682,   313,  1795,   446,   895,   309,  1804,  1683,  1262,  1824,
     880,  1540,  1825,  1373,  1563,   620,   482,  1684,  1324,  1680,
    1681,  1564,   113,  1023,  1374,  1160,   722,  1023,   313,  1677,
    1642,   621,  1787,  1642,  1375,  1290,  1642,   645,   125,  1181,
    1183,   440,   723,   483,  1707,  1376,  1185,  1434,  1498,  1263,
     707,  1365,  1761,  1504,  1507,  1182,  1184,  1160,  1504,  1654,
    1504,   708,   777,   777,  1188,   488,  1505,  1508,  1322,  1204,
    1323,  1651,  1160,  1817,  1160,  1206,  1188,   151,   682,  1814,
    1205,  1333,   441,  1334,   969,   939,  1207,   683,   939,   970,
    1544,   939,   455,   954,   489,   456,   535,  1138,  1324,  1199,
    1200,  1201,  1260,   697,   698,  1202,  1138,  1261,   442,   894,
     535,   918,   919,   896,   535,   535,   443,  1138,   475,   480,
     700,   476,   481,   703,   444,   536,   738,   739,   740,   539,
    1749,  1750,   699,  1338,   705,  1339,   535,   537,   535,  1196,
    1197,  1545,  1546,   925,   926,   540,   535,  1707,  1384,   535,
    1482,   551,   552,   535,   955,   956,   957,   958,   959,   960,
     961,   962,   963,   964,   553,   649,   927,   928,  1446,  1447,
    1694,  1695,   554,   309,   573,   572,   575,   574,   582,   424,
     583,   584,   586,   589,   593,   602,   603,   578,   604,   581,
     605,   606,   607,   613,  1707,   535,   313,   617,   637,   654,
     655,  1630,   674,  1793,   673,   686,   688,   687,   689,   693,
     709,   699,   716,   710,   711,   712,   728,   656,   730,   731,
    1358,   741,   745,   754,  1301,   657,   658,   768,   659,   771,
     309,   309,   309,   446,   769,   535,   660,   777,   780,   788,
     661,   789,   662,  1359,   790,   808,   791,   663,   802,   809,
     452,   456,   815,   313,   313,   313,   476,   819,   481,   817,
     492,   830,   838,   664,   535,   822,  1835,  1673,  1836,   823,
     824,   826,   841,   851,   840,   859,   860,   864,  1844,   865,
     870,   881,   899,   900,   901,   916,  1138,   665,   666,   667,
     668,   669,   670,   608,   535,   535,   535,   535,   902,   929,
     930,   931,   932,   944,   950,   951,   953,   975,   976,   979,
     980,  1002,  1003,  1001,  1005,  1010,  1011,  1012,  1007,  1020,
    1035,  1013,  1060,  1042,  1014,  1041,  1045,  1052,  1053,  1054,
    1055,  1101,  1063,   535,  1064,  1108,  1104,  1119,   451,   455,
     475,   480,   491,  1103,  1109,  1455,  1126,   535,   309,  1105,
    1130,  1189,  1116,   970,   420,  1022,  1208,  1209,  1230,  1235,
    1246,  1236,  1238,  1248,   773,  1252,  1272,  1275,  1274,  1280,
    1259,   313,   535,  1636,  1273,  1279,  1278,  1285,  1286,  1302,
    1308,   535,  1290,   535,   309,   535,  1296,   535,  1289,  1304,
    1309,  1311,  1489,  1303,  1315,   309,  1332,  1360,   734,   419,
     535,   420,  1331,  1350,  1381,  1383,  1388,   313,  1408,  1407,
    1419,  1511,  1411,  1420,   309,  1422,   903,    12,   313,  1423,
     420,  1431,  1424,  1425,  1426,  1438,  1439,  1444,  1450,  1453,
    1466,  1449,  1458,   535,   309,   535,  1468,   313,  1456,  1454,
     424,   309,  1457,  1472,  1459,  1475,   419,   424,  1460,  1474,
    1476,  1480,  1485,  1488,  1510,  1512,  1504,   313,  1518,  1521,
    1513,  1516,  1532,  1528,   313,   419,  1529,  1363,  1537,  1536,
     850,  1538,  1530,  1358,  1531,  1374,  1527,  1539,  1557,   868,
    1576,  1583,  1607,  1577,  1533,  1522,  1589,  1590,  1596,  1581,
    1591,  1602,  1526,  1592,   725,   535,  1359,   729,  1605,  1593,
    1560,   578,  1570,  1718,   743,   744,  1594,  1609,  1595,  1615,
    1620,  1611,   578,  1613,  1722,  1636,   535,  1724,   764,   767,
    1627,  1628,  1629,   767,  1632,  1733,  1675,  1633,  1638,  1649,
    1650,   787,  1655,  1658,  1676,  1663,  1688,  1690,   578,   796,
     797,   800,  1699,  1691,  1210,  1704,   806,  1712,  1715,  1717,
    1723,  1667,  1668,  1669,   813,  1689,  1551,  1740,  1755,  1756,
    1758,  1711,  1759,  1757,  1763,  1768,  1770,  1771,  1772,  1786,
    1764,  1809,  1788,  1810,  1789,  1801,  1802,  1816,  1813,  1821,
    1826,   618,  1827,  1837,  1841,  1799,   977,  1834,  1840,  1838,
     619,  1437,  1191,  1819,   622,  1828,  1271,   715,  1831,   814,
    1833,   751,  1452,  1766,  1797,  1115,  1050,   309,  1724,   535,
    1268,  1843,  1479,   535,   800,  1625,  1555,   770,  1372,  1550,
    1547,   816,  1490,  1494,  1500,   825,  1509,   906,   535,   917,
     313,  1174,   907,  1520,   946,  1815,  1812,   535,  1082,  1243,
    1436,  1535,   759,   692,   760,  1542,  1541,  1806,  1571,  1687,
    1358,   535,  1575,  1386,  1686,  1574,  1410,  1445,  1215,  1696,
    1604,   535,  1572,     0,   863,  1482,     0,   855,     0,     0,
       0,     0,     0,  1359,     0,     0,     0,     0,     0,     0,
    1822,     0,     0,     0,  1746,     0,     0,     0,     0,     0,
     535,     0,     0,     0,     0,   558,     0,     0,     0,     0,
       0,  1822,  1752,     0,     0,     0,     0,     0,     0,     0,
    1806,     0,     0,     0,     0,   535,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   535,     0,     0,     0,   535,
       0,     0,     0,     0,     0,     0,     0,  1358,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1358,  1358,
       0,   309,     0,     0,     0,     0,     0,     0,     0,  1358,
    1359,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1359,  1359,     0,   313,     0,     0,     0,     0,     0,
       0,     0,  1359,     0,   535,     0,     0,     0,     0,     0,
       0,     0,     0,   974,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1004,     0,     0,
       0,  1008,  1009,     0,   535,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1028,     0,  1034,     0,     0,     0,     0,
     535,   535,  1358,   578,     0,     0,   578,     0,     0,     0,
    1048,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1359,   535,     0,     0,   535,
       0,     0,   535,     0,     0,     0,     0,     0,     0,     0,
       0,   309,     0,     0,   535,     0,     0,     0,     0,   535,
       0,     0,  1081,     0,     0,     0,     0,     0,     0,  1358,
       0,     0,     0,     0,   313,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   309,     0,     0,     0,     0,     0,
       0,     0,  1359,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1358,     0,   313,     0,     0,
       0,     0,     0,     0,  1358,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1359,     0,
       0,  1125,     0,     0,     0,     0,     0,  1359,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1169,  1169,  1173,  1173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   535,   535,     0,
     535,     0,   535,     0,     0,     0,     0,     0,     0,   535,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1169,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   535,     0,   535,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1234,
       0,     0,     0,   535,     0,     0,   535,     0,  1241,     0,
    1241,     0,   767,     0,  1169,     0,     0,     0,   535,     0,
       0,     0,     0,     0,     0,     0,     0,  1169,     0,   535,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     535,     0,     0,     0,     0,     0,     0,     0,   535,     0,
     806,     0,   806,   535,     0,   535,     0,   535,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   558,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   535,     0,     0,     0,
       0,     0,     0,     0,     0,   842,   843,     0,     0,   852,
     853,   854,   856,     0,   858,     0,   535,     0,     0,     0,
     866,   535,  1382,     0,     0,     0,     0,     0,   875,     0,
       0,     0,     0,   535,     0,     0,   535,     0,     0,     0,
       0,     0,     0,  1169,     0,     0,     0,     0,     0,     0,
     897,   898,     0,     0,     0,     0,     0,     0,     0,   904,
     905,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     942,     0,     0,   942,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   767,     0,     0,     0,
    1464,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1478,     0,     0,     0,     0,
       0,     0,  1006,     0,  1169,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   800,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1169,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1049,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1523,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1074,     0,     0,     0,  1076,  1077,     0,     0,     0,     0,
       0,     0,   863,   904,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     898,  1169,     0,     0,     0,     0,  1127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1610,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1623,  1624,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1192,     0,     0,     0,     0,
       0,     0,     0,  1640,     0,     0,  1169,     0,     0,  1169,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1653,     0,     0,     0,     0,  1657,     0,     0,     0,
    1233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1249,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1282,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1287,  1288,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1307,     0,     0,
    1310,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1335,  1336,  1337,
       0,  1340,  1341,  1342,  1343,  1344,  1345,  1346,  1347,  1348,
       0,     0,  1351,  1352,     0,     0,     0,     0,     0,     0,
       0,  1366,     0,     0,  1169,  1727,     0,  1729,     0,  1731,
       0,  1127,     0,     0,     0,     0,  1739,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1169,     0,  1169,     0,     0,     0,     0,     0,
       0,     0,  1433,     0,     0,     0,     0,     0,     0,     0,
    1762,     0,     0,  1765,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1169,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1773,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1169,     0,     0,
       0,     0,     0,     0,     0,  1800,     0,     0,     0,     0,
    1803,     0,  1169,     0,  1169,  1465,     0,  1467,     0,  1469,
       0,     0,  1473,     0,     0,     0,     0,  1477,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1483,
       0,     0,     0,  1820,     0,     0,     0,     0,  1487,     0,
       0,     0,     0,     0,  1491,  1492,     0,     0,     0,     0,
       0,     0,     0,  1829,     0,     0,     0,     0,  1830,     0,
       0,     0,     0,  1514,     0,     0,  1515,     0,     0,     0,
    1839,     0,     0,  1842,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1614,     0,     0,
       0,  1616,     0,     0,     0,  1619,     0,  1621,     0,  1622,
       0,     0,     0,     0,     0,  1626,     0,     0,     0,     0,
       0,     0,     0,  1631,     0,     0,     0,     0,     0,     0,
       0,  1635,  1637,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1483,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1659,  1660,  1661,  1662,     0,  1664,  1665,
       0,  1666,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1674,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1713,     0,  1714,     0,     0,  1716,     0,     0,     0,     0,
       0,     0,     0,  1719,     0,     0,     0,     0,  1721,  1637,
       0,     0,     0,     0,     0,     0,  1725,     0,     0,     0,
       0,  1730,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1742,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1748,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1767,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1725,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1807,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -165,   885,     0,     0,  1818,     0,     0,     0,     0,  1823,
       0,     1,     2,     0,  1807,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,  1823,
      12,     0,     0,  1832,    13,   415,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,    71,    72,    73,    74,
      75,     0,    76,    77,    78,     0,     0,    79,    80,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,    92,     0,    93,    94,
      95,    96,     0,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     0,   112,   113,
     114,   115,   116,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,   126,   127,     0,
       0,   128,   129,   130,     0,     0,     0,   131,     0,   132,
     133,     0,   134,   135,     0,   136,     0,   137,     0,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,     0,   149,   150,   151,     0,   417,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     0,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     0,   246,     0,   247,   248,   249,   250,   251,
     252,   253,  -165,   885,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    12,     0,     0,     0,   889,   415,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,   416,    29,    30,    31,    32,    33,     0,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,     0,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,    71,    72,
      73,    74,    75,     0,    76,    77,    78,     0,     0,    79,
      80,     0,     0,     0,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,    92,     0,
      93,    94,    95,    96,     0,    97,     0,     0,     0,    98,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     103,   104,   105,   106,   107,   108,   109,   110,   111,     0,
     112,   113,   114,   115,   116,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,     0,   126,
     127,     0,     0,   128,   129,   130,     0,     0,     0,   131,
       0,   132,   133,     0,   134,   135,     0,   136,     0,   137,
       0,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,     0,     0,   149,   150,   151,     0,   417,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,     0,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   885,   246,     0,   247,   248,   249,
     250,   251,   252,   253,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,    12,     0,     0,     0,   414,   415,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   416,    29,    30,    31,    32,    33,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    71,
      72,    73,    74,    75,     0,    76,    77,    78,     0,     0,
      79,    80,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,     0,    92,
       0,    93,    94,    95,    96,     0,    97,     0,     0,     0,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   110,   111,
       0,   112,   113,   114,   115,   116,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,     0,
     126,   127,     0,     0,   128,   129,   130,     0,     0,     0,
     131,     0,   132,   133,     0,   134,   135,     0,   136,     0,
     137,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,     0,     0,   149,   150,   151,     0,   417,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,     0,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   885,   246,     0,   247,   248,
     249,   250,   251,   252,   253,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,     0,     0,     0,    12,     0,     0,     0,   414,   415,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   560,   416,    29,    30,    31,    32,    33,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,     0,    47,    48,    49,   561,   562,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,    72,    73,    74,    75,     0,    76,    77,    78,     0,
       0,    79,    80,     0,     0,     0,    81,    82,   510,    84,
      85,    86,    87,    88,   563,    90,    91,     0,     0,     0,
      92,     0,    93,    94,    95,    96,     0,    97,     0,     0,
       0,    98,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   564,
     111,     0,   112,   113,   114,   115,   116,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
       0,   126,   127,     0,     0,   128,   129,   130,     0,     0,
       0,   131,     0,   132,   133,     0,   134,   135,     0,   136,
       0,   137,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,     0,   149,   150,   151,     0,
     417,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   528,   529,   530,   178,   179,   531,   566,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,     0,   246,     0,   247,
     248,   249,   250,   251,   252,   253,  -863,   457,     0,   458,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -863,
       0,     0,     0,  -863,     0,     0,     0,  -863,  -863,     0,
       0,     0,     0,  -863,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   459,     0,     0,  -863,     0,   460,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -863,     0,  -863,  -863,  -863,     0,     0,  -863,  -863,  -863,
    -863,     0,     0,     0,  -863,  -863,     0,     0,     0,     0,
       0,  -863,     0,     0,  -863,  -863,   461,     0,     0,  -863,
       0,     0,     0,     0,  -863,  -863,     0,     0,     0,     0,
    -863,     0,     0,     0,  -863,     0,     0,     0,  -863,  -863,
       0,  -863,     0,  -863,  -863,     0,     0,     0,  -863,  -863,
       0,     0,  -863,  -863,  -863,  -863,  -863,  -863,     0,     0,
    -863,     0,     0,     0,  -863,  -863,     0,     0,  -863,     0,
       0,     0,     0,  -863,     0,     0,  -863,     0,     0,     0,
       0,  -863,  -863,  -863,  -863,  -863,     0,  -863,  -863,  -863,
    -863,  -863,     0,     0,     0,     0,  -863,  -863,  -863,     0,
    -863,  -863,  -863,  -863,  -863,  -863,     0,  -863,     0,  -863,
       0,     0,     0,     0,  -863,  -863,  -863,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -863,     0,  -863,     0,  -863,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -863,     0,     0,     0,
       0,  -863,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    12,  -863,     0,
    -863,    13,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     0,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,    72,    73,    74,    75,     0,    76,
      77,    78,     0,     0,    79,    80,     0,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,    92,     0,    93,    94,    95,    96,     0,
      97,     0,     0,     0,    98,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,     0,   112,   113,   114,   115,   116,
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,     0,   126,   127,     0,     0,   128,   129,
     130,     0,     0,     0,   131,     0,   132,   133,     0,   134,
     135,     0,   136,     0,   137,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,     0,     0,   149,
     150,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     0,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,     0,
     246,     0,   247,   248,   249,   250,   251,   252,   253,   254,
     255,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
      12,     0,     0,     0,    13,    14,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,    71,    72,    73,    74,
      75,     0,    76,    77,    78,     0,     0,    79,    80,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,    92,     0,    93,    94,
      95,    96,     0,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     0,   112,   113,
     114,   115,   116,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,   126,   127,     0,
       0,   128,   129,   130,     0,     0,     0,   131,     0,   132,
     133,     0,   134,   135,     0,   136,     0,   137,     0,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,     0,   149,   150,   151,     0,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     0,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     0,   246,     0,   247,   248,   249,   250,   251,
     252,   253,     0,   614,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,    12,     0,     0,     0,   414,   415,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   416,    29,    30,    31,    32,    33,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    71,
      72,    73,    74,    75,     0,    76,    77,    78,     0,     0,
      79,    80,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,     0,    92,
       0,    93,    94,    95,    96,     0,    97,     0,     0,     0,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   110,   111,
       0,   112,   113,   114,   115,   116,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,     0,
     126,   127,     0,     0,   128,   129,   130,     0,   555,     0,
     131,     0,   132,   133,     0,   134,   135,     0,   136,     0,
     137,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,     0,     0,   149,   150,   151,     0,   417,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,     0,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,     0,   246,     0,   247,   248,
     249,   250,   251,   252,   253,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,     0,    12,     0,     0,     0,   414,   415,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   416,    29,    30,    31,    32,    33,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,     0,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,    72,    73,    74,    75,     0,    76,    77,    78,     0,
       0,    79,    80,     0,     0,     0,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
      92,     0,    93,    94,    95,    96,     0,    97,     0,     0,
       0,    98,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   110,
     111,     0,   112,   113,   114,   115,   116,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
       0,   126,   127,     0,     0,   128,   129,   130,     0,   818,
       0,   131,     0,   132,   133,     0,   134,   135,     0,   136,
       0,   137,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,     0,   149,   150,   151,     0,
     417,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,     0,   246,     0,   247,
     248,   249,   250,   251,   252,   253,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,    12,     0,     0,     0,   414,
     415,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,  1353,   416,    29,    30,    31,    32,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     0,    47,    48,    49,  1354,
    1355,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    71,    72,    73,    74,    75,     0,    76,    77,    78,
       0,     0,    79,    80,     0,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     0,     0,
       0,    92,     0,    93,    94,    95,    96,     0,    97,     0,
       0,     0,    98,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,     0,   112,   113,   114,   115,   116,     0,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,     0,   126,   127,     0,     0,   128,   129,   130,     0,
     555,     0,   131,     0,   132,   133,     0,   134,   135,     0,
     136,     0,   137,     0,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,     0,     0,   149,   150,   151,
       0,   417,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
    1356,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,     0,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,     0,   246,     0,
     247,   248,   249,   250,   251,   252,   253,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,    12,     0,     0,     0,
     414,   415,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   416,    29,    30,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     0,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,    71,    72,    73,    74,    75,     0,    76,    77,
      78,     0,     0,    79,    80,     0,     0,     0,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,     0,    92,     0,    93,    94,    95,    96,     0,    97,
       0,     0,     0,    98,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   103,   104,   105,   106,   107,   108,
     109,   110,   111,     0,   112,   113,   114,   115,   116,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,     0,   126,   127,     0,     0,   128,   129,   130,
       0,     0,     0,   131,     0,   132,   133,     0,   134,   135,
       0,   136,     0,   137,     0,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,     0,     0,   149,   150,
     151,     0,   417,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     0,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,     0,   246,
       0,   247,   248,   249,   250,   251,   252,   253,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    12,     0,     0,
       0,    13,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     0,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,    72,    73,    74,    75,     0,    76,
      77,    78,     0,     0,    79,    80,     0,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,    92,     0,    93,    94,    95,    96,     0,
      97,     0,     0,     0,    98,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,     0,   112,   113,   114,   115,   116,
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,     0,   126,   127,     0,     0,   128,   129,
     130,     0,     0,     0,   131,     0,   132,   133,     0,   134,
     135,     0,   136,     0,   137,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,     0,     0,   149,
     150,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     0,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,     0,
     246,     0,   247,   248,   249,   250,   251,   252,   253,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,     0,    12,     0,
       0,     0,    13,    14,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,     0,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,    71,    72,    73,    74,    75,     0,
      76,    77,    78,     0,     0,    79,    80,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,    92,     0,    93,    94,    95,    96,
       0,    97,     0,     0,     0,    98,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   112,   113,   114,   115,
     116,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,     0,   126,   127,     0,     0,   128,
     129,   130,     0,     0,     0,   131,     0,   132,   133,     0,
     134,   135,     0,   136,     0,   137,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,     0,     0,
     149,   150,   151,     0,   417,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     0,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
       0,   246,     0,   247,   248,   249,   250,   251,   252,   253,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     0,    12,
       0,     0,     0,    13,   415,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,     0,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,    71,    72,    73,    74,    75,
       0,    76,    77,    78,     0,     0,    79,    80,     0,     0,
       0,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,     0,     0,    92,     0,    93,    94,    95,
      96,     0,    97,     0,     0,     0,    98,    99,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     0,   112,   113,   114,
     115,   116,     0,     0,     0,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,     0,   126,   127,     0,     0,
     128,   129,   130,     0,     0,     0,   131,     0,   132,   133,
       0,   134,   135,     0,   136,     0,   137,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,     0,
       0,   149,   150,   151,     0,   417,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,     0,   195,
     196,   197,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,     0,   246,     0,   247,   248,   249,   250,   251,   252,
     253,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
      12,     0,     0,     0,   889,   415,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     416,    29,    30,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,    71,    72,    73,    74,
      75,     0,    76,    77,    78,     0,     0,    79,    80,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,    92,     0,    93,    94,
      95,    96,     0,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     0,   112,   113,
     114,   115,   116,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,   126,   127,     0,
       0,   128,   129,   130,     0,     0,     0,   131,     0,   132,
     133,     0,   134,   135,     0,   136,     0,   137,     0,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,     0,   149,   150,   151,     0,   417,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     0,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     0,   246,     0,   247,   248,   249,   250,   251,
     252,   253,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,     0,     0,
       0,    12,     0,     0,     0,   414,   415,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     560,   416,    29,    30,    31,    32,    33,     0,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     0,    47,    48,    49,   561,   562,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    71,    72,    73,
      74,    75,     0,    76,    77,    78,     0,     0,    79,    80,
       0,     0,     0,    81,    82,   510,    84,    85,    86,    87,
      88,   563,    90,    91,     0,     0,     0,    92,     0,    93,
      94,    95,    96,     0,    97,     0,     0,     0,    98,    99,
     100,   101,   102,     0,     0,     0,     0,   940,     0,   103,
     104,   105,   106,   107,   108,   109,   564,   111,     0,   112,
     113,   114,   115,   116,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,     0,   126,   127,
       0,     0,   128,   129,   130,     0,     0,     0,   131,   941,
     132,   133,     0,   134,   135,     0,   136,     0,   137,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,     0,     0,   149,   150,   151,     0,   417,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     528,   529,   530,   178,   179,   531,   566,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,     0,   246,     0,   247,   248,   249,   250,
     251,   252,   253,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,     0,
       0,     0,    12,     0,     0,     0,   414,   415,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   560,   416,    29,    30,    31,    32,    33,     0,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,     0,    47,    48,    49,   561,   562,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,    71,    72,
      73,    74,    75,     0,    76,    77,    78,     0,     0,    79,
      80,     0,     0,     0,    81,    82,   510,    84,    85,    86,
      87,    88,   563,    90,    91,     0,     0,     0,    92,     0,
      93,    94,    95,    96,     0,    97,     0,     0,     0,    98,
      99,   100,   101,   102,     0,     0,     0,     0,   940,     0,
     103,   104,   105,   106,   107,   108,   109,   564,   111,     0,
     112,   113,   114,   115,   116,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,     0,   126,
     127,     0,     0,   128,   129,   130,     0,     0,     0,   131,
     945,   132,   133,     0,   134,   135,     0,   136,     0,   137,
       0,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,     0,     0,   149,   150,   151,     0,   417,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   528,   529,   530,   178,   179,   531,   566,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,     0,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,     0,   246,     0,   247,   248,   249,
     250,   251,   252,   253,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,    12,     0,     0,     0,   414,   415,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,  1353,   416,    29,    30,    31,    32,    33,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     0,    47,    48,    49,  1354,  1355,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    71,
      72,    73,    74,    75,     0,    76,    77,    78,     0,     0,
      79,    80,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,     0,    92,
       0,    93,    94,    95,    96,     0,    97,     0,     0,     0,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   110,   111,
       0,   112,   113,   114,   115,   116,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,     0,
     126,   127,     0,     0,   128,   129,   130,     0,     0,     0,
     131,     0,   132,   133,     0,   134,   135,     0,   136,     0,
     137,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,     0,     0,   149,   150,   151,     0,   417,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,  1356,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,     0,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,     0,   246,     0,   247,   248,
     249,   250,   251,   252,   253,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,     0,     0,     0,    12,     0,     0,     0,   414,   415,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   560,   416,    29,    30,    31,    32,    33,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,     0,    47,    48,    49,   561,   562,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,    72,    73,    74,    75,     0,    76,    77,    78,     0,
       0,    79,    80,     0,     0,     0,    81,    82,   510,    84,
      85,    86,    87,    88,   563,    90,    91,     0,     0,     0,
      92,     0,    93,    94,    95,    96,     0,    97,     0,     0,
       0,    98,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   564,
     111,     0,   112,   113,   114,   115,   116,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
       0,   126,   127,     0,     0,   128,   129,   130,     0,     0,
     565,   131,     0,   132,   133,     0,   134,   135,     0,   136,
       0,   137,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,     0,   149,   150,   151,     0,
     417,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   528,   529,   530,   178,   179,   531,   566,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,     0,   246,     0,   247,
     248,   249,   250,   251,   252,   253,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,     0,     0,     0,    12,     0,     0,     0,   414,
     415,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   560,   416,    29,    30,    31,    32,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     0,    47,    48,    49,   561,
     562,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    71,    72,    73,    74,    75,     0,    76,    77,    78,
       0,     0,    79,    80,     0,     0,     0,    81,    82,   510,
      84,    85,    86,    87,    88,   563,    90,    91,     0,     0,
       0,    92,     0,    93,    94,    95,    96,     0,    97,     0,
       0,     0,    98,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     564,   111,     0,   112,   113,   114,   115,   116,     0,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,     0,   126,   127,     0,     0,   128,   129,   130,     0,
       0,     0,   131,   570,   132,   133,     0,   134,   135,     0,
     136,     0,   137,     0,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,     0,     0,   149,   150,   151,
       0,   417,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   528,   529,   530,   178,   179,   531,
     566,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,     0,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,     0,   246,     0,
     247,   248,   249,   250,   251,   252,   253,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,     0,     0,     0,    12,     0,     0,     0,
     414,   415,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   560,   416,    29,    30,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     0,    47,    48,    49,
     561,   562,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,    71,    72,    73,    74,    75,     0,    76,    77,
      78,     0,     0,    79,    80,     0,     0,     0,    81,    82,
     510,    84,    85,    86,    87,    88,   563,    90,    91,     0,
       0,     0,    92,     0,    93,    94,    95,    96,     0,    97,
       0,     0,     0,    98,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   103,   104,   105,   106,   107,   108,
     109,   564,   111,     0,   112,   113,   114,   115,   116,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,     0,   126,   127,     0,     0,   128,   129,   130,
       0,     0,     0,   131,     0,   132,   133,     0,   134,   135,
       0,   136,     0,   137,     0,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,     0,     0,   149,   150,
     151,     0,   417,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   528,   529,   530,   178,   179,
     531,   566,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     0,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   609,   246,
       0,   247,   248,   249,   250,   251,   252,   253,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,     0,     0,     0,    12,     0,     0,
       0,   414,   415,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   560,   416,    29,    30,
      31,    32,    33,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     0,    47,    48,
      49,   561,   562,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,    72,    73,    74,    75,     0,    76,
      77,    78,     0,     0,    79,    80,     0,     0,     0,    81,
      82,   510,    84,    85,    86,    87,    88,   563,    90,    91,
       0,     0,     0,    92,     0,    93,    94,    95,    96,     0,
      97,     0,     0,     0,    98,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   564,   111,     0,   112,   113,   114,   115,   116,
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,     0,   126,   127,     0,     0,   128,   129,
     130,     0,     0,     0,   131,     0,   132,   133,     0,   134,
     135,     0,   136,     0,   137,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,     0,     0,   149,
     150,   151,     0,   417,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   528,   529,   530,   178,
     179,   531,   566,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     0,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,     0,
     246,   611,   247,   248,   249,   250,   251,   252,   253,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,     0,     0,     0,    12,     0,
       0,     0,   414,   415,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   560,   416,    29,
      30,    31,    32,    33,     0,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,     0,    47,
      48,    49,   561,   562,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,    71,    72,    73,    74,    75,     0,
      76,    77,    78,     0,     0,    79,    80,     0,     0,     0,
      81,    82,   510,    84,    85,    86,    87,    88,   563,    90,
      91,     0,     0,     0,    92,     0,    93,    94,    95,    96,
       0,    97,     0,     0,     0,    98,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   564,   111,     0,   112,   113,   114,   115,
     116,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,     0,   126,   127,     0,     0,   128,
     129,   130,     0,   934,     0,   131,     0,   132,   133,     0,
     134,   135,     0,   136,     0,   137,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,     0,     0,
     149,   150,   151,     0,   417,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   528,   529,   530,
     178,   179,   531,   566,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     0,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
       0,   246,     0,   247,   248,   249,   250,   251,   252,   253,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,     0,     0,     0,    12,
       0,     0,     0,   414,   415,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   560,   416,
      29,    30,    31,    32,    33,     0,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
      47,    48,    49,   561,   562,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,    71,    72,    73,    74,    75,
       0,    76,    77,    78,     0,     0,    79,    80,     0,     0,
       0,    81,    82,   510,    84,    85,    86,    87,    88,   563,
      90,    91,     0,     0,     0,    92,     0,    93,    94,    95,
      96,     0,    97,     0,     0,     0,    98,    99,   100,   101,
     102,     0,     0,     0,     0,  1432,     0,   103,   104,   105,
     106,   107,   108,   109,   564,   111,     0,   112,   113,   114,
     115,   116,     0,     0,     0,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,     0,   126,   127,     0,     0,
     128,   129,   130,     0,     0,     0,   131,     0,   132,   133,
       0,   134,   135,     0,   136,     0,   137,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,     0,
       0,   149,   150,   151,     0,   417,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   528,   529,
     530,   178,   179,   531,   566,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,     0,   195,
     196,   197,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,     0,   246,     0,   247,   248,   249,   250,   251,   252,
     253,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,     0,     0,     0,
      12,     0,     0,     0,   414,   415,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   496,    26,   498,
     416,    29,   499,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,   501,
       0,    47,    48,    49,   503,   504,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,    71,    72,    73,    74,
      75,     0,    76,    77,    78,     0,     0,    79,    80,     0,
       0,     0,    81,    82,   510,    84,    85,    86,    87,    88,
     563,    90,    91,     0,     0,     0,    92,     0,    93,    94,
      95,    96,     0,    97,     0,     0,     0,   513,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   564,   111,     0,   112,   113,
     690,   115,   116,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,   691,   127,     0,
       0,   128,   129,   130,     0,     0,     0,   131,     0,   132,
     133,     0,   134,   135,     0,   136,     0,   137,     0,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,     0,   149,   150,   151,     0,   417,   153,   154,   155,
     156,   157,   158,   159,   160,   523,   162,   524,   164,   525,
     526,   167,   168,   169,   170,   171,   172,   527,   174,   528,
     529,   530,   178,   179,   531,   532,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     0,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     0,   246,     0,   247,   533,   249,   250,   251,
     252,   253,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,     0,     0,
       0,    12,     0,     0,     0,   414,   415,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     560,   416,    29,    30,    31,    32,    33,     0,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     0,    47,    48,    49,   561,   562,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    71,    72,    73,
      74,    75,     0,    76,    77,    78,     0,     0,    79,    80,
       0,     0,     0,    81,    82,   510,    84,    85,    86,    87,
      88,   563,    90,    91,     0,     0,     0,    92,     0,    93,
      94,    95,    96,     0,    97,     0,     0,     0,    98,    99,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   564,   111,     0,   112,
     113,   114,   115,   116,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,     0,   126,   127,
       0,     0,   128,   129,   130,     0,     0,     0,   131,     0,
     132,   133,     0,   134,   135,     0,   136,     0,   137,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,     0,     0,   149,   150,   151,     0,   417,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     528,   529,   530,   178,   179,   531,   566,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,     0,   246,     0,   247,   248,   249,   250,
     251,   252,   253,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,     0,
       0,     0,    12,     0,     0,     0,   414,   415,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   496,
      26,   498,   416,    29,   499,    31,    32,    33,     0,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,   501,     0,    47,    48,    49,   503,   504,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,    71,    72,
      73,    74,    75,     0,    76,    77,    78,     0,     0,    79,
      80,     0,     0,     0,    81,    82,   510,    84,    85,    86,
      87,    88,   563,    90,    91,     0,     0,     0,    92,     0,
      93,    94,    95,    96,     0,    97,     0,     0,     0,   513,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     103,   104,   105,   106,   107,   108,   109,   564,   111,     0,
     112,   113,   114,   115,   116,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,     0,   126,
     127,     0,     0,   128,   129,   130,     0,     0,     0,   131,
       0,   132,   133,     0,   134,   135,     0,   136,     0,   137,
       0,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,     0,     0,   149,   150,   151,     0,   417,   153,
     154,   155,   156,   157,   158,   159,   160,   523,   162,   524,
     164,   525,   526,   167,   168,   169,   170,   171,   172,   527,
     174,   528,   529,   530,   178,   179,   531,   532,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,     0,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,     0,   246,     0,   247,   533,   249,
     250,   251,   252,   253,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
       0,     0,     0,    12,     0,     0,     0,   414,   415,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     496,    26,   498,   416,    29,   499,    31,    32,    33,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,   501,     0,    47,    48,    49,   503,   504,    52,
     505,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    71,
      72,    73,    74,    75,     0,    76,    77,    78,     0,     0,
      79,    80,     0,     0,     0,    81,    82,   510,    84,    85,
      86,    87,    88,   563,    90,    91,     0,     0,     0,    92,
       0,    93,    94,    95,    96,     0,    97,     0,     0,     0,
     513,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   564,   111,
       0,   112,   113,     0,   115,   116,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,     0,
       0,     0,     0,     0,   128,   129,   130,     0,     0,     0,
     131,     0,   132,   133,     0,   134,   135,     0,   136,     0,
     137,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,     0,     0,   149,   150,   151,     0,   417,
     153,   154,   155,   156,   157,   158,   159,   160,   523,   162,
     524,   164,   525,   526,   167,   168,   169,   170,   171,   172,
     527,   174,   528,   529,   530,   178,   179,   531,   532,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,     0,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,     0,   246,     0,   247,   533,
     249,   250,   251,   252,   253,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,     0,     0,     0,    12,     0,     0,     0,   414,   415,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   496,    26,   498,   416,    29,   499,    31,    32,    33,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,   501,     0,    47,    48,    49,   503,   504,
      52,   505,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,    72,    73,    74,    75,     0,    76,    77,    78,     0,
       0,    79,    80,     0,     0,     0,    81,    82,   510,    84,
      85,    86,    87,    88,   563,    90,    91,     0,     0,     0,
      92,     0,    93,    94,    95,    96,     0,    97,     0,     0,
       0,   513,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   564,
     111,     0,   112,   113,     0,   115,   116,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
       0,     0,     0,     0,     0,   128,   129,   130,     0,     0,
       0,   131,     0,   132,   133,     0,     0,     0,     0,   136,
       0,   137,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,     0,   149,   150,   151,     0,
     417,   153,   154,   155,   156,   157,   158,   159,   160,   523,
     162,   524,   164,   525,   526,   167,   168,   169,   170,   171,
     172,   527,   174,   528,   529,   530,   178,   179,   531,   532,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,     0,   246,     0,   247,
     533,   249,   250,   251,   252,   253,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,     0,     0,     0,    12,     0,     0,     0,   414,
     415,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   496,    26,   498,   416,    29,   499,    31,    32,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,   501,     0,    47,    48,    49,   503,
     504,    52,   505,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    71,    72,    73,    74,    75,     0,    76,    77,    78,
       0,     0,    79,    80,     0,     0,     0,    81,    82,   510,
      84,    85,    86,    87,    88,   563,    90,    91,     0,     0,
       0,    92,     0,    93,    94,    95,    96,     0,    97,     0,
       0,     0,   513,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,     0,   108,   109,
     564,   111,     0,   112,   113,     0,   115,   116,     0,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,     0,     0,     0,     0,     0,   128,   129,   130,     0,
       0,     0,   131,     0,   132,   133,     0,     0,     0,     0,
     136,     0,   137,     0,   138,     0,   140,     0,   142,   143,
     144,   145,   146,   147,   148,     0,     0,   149,   150,   151,
       0,   417,   153,   154,   155,   156,   157,   158,   159,   160,
     523,   162,   524,   164,   525,   526,   167,   168,   169,   170,
     171,   172,   527,   174,   528,   529,   530,   178,   179,   531,
     532,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,     0,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,     0,   246,     0,
     247,   533,   249,   250,   251,   252,   253,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     0,     0,     0,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
     414,   415,     0,    15,    16,    17,   493,    19,    20,    21,
     494,    23,   495,   496,   497,   498,   416,    29,   499,    31,
      32,    33,     0,    34,    35,    36,    37,   500,    39,    40,
      41,    42,    43,    44,    45,   501,     0,    47,   502,    49,
     503,   504,    52,   505,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,   506,   507,
      70,     0,    71,    72,    73,   508,     0,     0,    76,    77,
      78,     0,     0,   509,    80,     0,     0,     0,     0,    82,
     510,    84,   511,   512,    87,    88,     0,     0,     0,     0,
       0,     0,     0,     0,    93,    94,    95,    96,     0,    97,
       0,     0,     0,   513,    99,   100,   514,   515,     0,     0,
       0,     0,     0,     0,   103,   104,   105,     0,   107,   108,
     109,     0,     0,     0,     0,     0,     0,   115,   516,     0,
       0,     0,   117,   118,   119,   120,   517,   122,   123,   518,
       0,     0,     0,     0,     0,     0,     0,   519,   520,   130,
       0,     0,     0,   131,     0,   132,   521,     0,     0,     0,
       0,   136,     0,   137,     0,   138,   139,   140,   141,   522,
     143,   144,   145,   146,   147,   148,     0,     0,   149,   150,
       0,     0,   417,   153,   154,   155,   156,   157,   158,   159,
     160,   523,   162,   524,   164,   525,   526,   167,   168,   169,
     170,   171,   172,   527,   174,   528,   529,   530,   178,   179,
     531,   532,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     0,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     0,     0,     1,
       2,   247,   533,   249,   250,   251,   252,   253,     3,     0,
       0,     0,     0,     8,     9,     0,     0,     0,     0,     0,
       0,     0,   414,   415,     0,    15,    16,    17,   541,    19,
      20,    21,   494,   542,   543,   496,   497,   498,   416,    29,
     499,    31,   544,    33,     0,    34,    35,    36,    37,   545,
      39,   546,   547,    42,    43,    44,    45,   501,     0,    47,
     548,    49,   503,   504,    52,   505,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
     506,   507,    70,     0,    71,    72,    73,   549,     0,     0,
      76,    77,    78,     0,     0,   509,    80,     0,     0,     0,
       0,    82,   510,    84,   511,   512,    87,    88,     0,     0,
       0,     0,     0,     0,     0,     0,    93,    94,    95,    96,
       0,    97,     0,     0,     0,   513,    99,   100,   514,   515,
       0,     0,     0,     0,     0,     0,   103,   104,   105,     0,
     107,   108,   109,     0,     0,     0,     0,     0,     0,   115,
     516,     0,     0,     0,   117,   118,   119,   120,   517,   122,
     123,   518,     0,     0,     0,     0,     0,     0,     0,   519,
     520,   130,     0,     0,     0,   131,     0,   132,   521,     0,
       0,     0,     0,   136,     0,   137,     0,   138,   139,   140,
     141,   522,   143,   144,   145,   146,   147,   148,     0,     0,
     149,   150,     0,     0,   417,   153,   154,   155,   156,   157,
     158,   159,   160,   523,   550,   524,   164,   525,   526,   167,
     168,   169,   170,   171,   172,   527,   174,   528,   529,   530,
     178,   179,   531,   532,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     0,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,     0,
       0,   576,     0,   247,   533,   249,   250,   251,   252,   253,
       8,     9,     0,     0,     0,   793,     0,     0,     0,   414,
     415,     0,    15,    16,    17,   541,    19,    20,    21,   494,
     542,   543,   496,   497,   498,   416,    29,   499,    31,   544,
      33,     0,    34,    35,    36,    37,   545,    39,   546,   547,
      42,    43,    44,    45,   501,     0,    47,   548,    49,   503,
     504,    52,   505,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,   506,   507,    70,
       0,    71,    72,    73,   549,     0,     0,    76,    77,    78,
       0,     0,   509,    80,     0,     0,     0,     0,    82,   510,
      84,   511,   512,    87,    88,     0,     0,     0,     0,     0,
       0,     0,     0,    93,    94,    95,    96,     0,    97,     0,
       0,     0,   513,    99,   100,   514,   515,     0,     0,     0,
       0,     0,     0,   103,   104,   105,     0,   107,   108,   109,
       0,     0,     0,     0,     0,     0,   115,   516,     0,     0,
       0,   117,   118,   119,   120,   517,   122,   123,   518,     0,
       0,     0,     0,     0,     0,     0,   519,   520,   130,     0,
       0,     0,   131,   794,   132,   521,     0,     0,     0,     0,
       0,     0,   137,     0,   138,   139,   140,   141,   522,   143,
     144,   145,   146,   147,   148,     0,     0,   149,   150,     0,
       0,   417,   153,   154,   155,   156,   157,   158,   159,   160,
     523,   550,   524,   164,   525,   526,   167,   168,   169,   170,
     171,   172,   527,   174,   528,   529,   530,   178,   179,   531,
     532,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,     0,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,     0,     0,   576,     0,
     247,   533,   249,   250,   251,   252,   253,     8,     9,     0,
       0,     0,     0,     0,     0,     0,   414,   415,     0,    15,
      16,    17,   541,    19,    20,    21,   494,   542,   543,   496,
     497,   498,   416,    29,   499,    31,   544,    33,     0,    34,
      35,    36,    37,   545,    39,   546,   547,    42,    43,    44,
      45,   501,     0,    47,   548,    49,   503,   504,    52,   505,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,   506,   507,    70,     0,    71,    72,
      73,   549,     0,     0,    76,    77,    78,     0,     0,   509,
      80,     0,     0,     0,     0,    82,   510,    84,   511,   512,
      87,    88,     0,     0,     0,     0,     0,     0,     0,     0,
      93,    94,    95,    96,     0,    97,     0,     0,     0,   513,
      99,   100,   514,   515,     0,     0,     0,     0,     0,     0,
     103,   104,   105,     0,   107,   108,   109,     0,     0,     0,
       0,     0,     0,   115,   516,     0,     0,     0,   117,   118,
     119,   120,   517,   122,   123,   518,     0,     0,     0,     0,
       0,     0,     0,   519,   520,   130,     0,     0,     0,   131,
       0,   132,   521,     0,     0,     0,     0,     0,     0,   137,
       0,   138,   139,   140,   141,   522,   143,   144,   145,   146,
     147,   148,     0,     0,   149,   150,     0,     0,   417,   153,
     154,   155,   156,   157,   158,   159,   160,   523,   550,   524,
     164,   525,   526,   167,   168,   169,   170,   171,   172,   527,
     174,   528,   529,   530,   178,   179,   531,   532,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,     0,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,     0,     0,     0,     0,   247,   533,   249,
     250,   251,   252,   253,   579,   580,     0,     0,     0,     0,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
     414,   415,     0,    15,    16,    17,   541,    19,    20,    21,
     494,   542,   543,   496,   497,   498,   416,    29,   499,    31,
     544,    33,     0,    34,    35,    36,    37,   545,    39,   546,
     547,    42,    43,    44,    45,   501,     0,    47,   548,    49,
     503,   504,    52,   505,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,   506,   507,
      70,     0,    71,    72,    73,   549,     0,     0,    76,    77,
      78,     0,     0,   509,    80,     0,     0,     0,     0,    82,
     510,    84,   511,   512,    87,    88,     0,     0,     0,     0,
       0,     0,     0,     0,    93,    94,    95,    96,     0,    97,
       0,     0,     0,   513,    99,   100,   514,   515,     0,     0,
       0,     0,     0,     0,   103,   104,   105,     0,   107,   108,
     109,     0,     0,     0,     0,     0,     0,   115,   516,     0,
       0,     0,   117,   118,   119,   120,   517,   122,   123,   518,
       0,     0,     0,     0,     0,     0,     0,   519,   520,   130,
       0,     0,     0,   131,     0,   132,   521,     0,     0,     0,
       0,     0,     0,   137,     0,   138,   139,   140,   141,   522,
     143,   144,   145,   146,   147,   148,     0,     0,   149,   150,
       0,     0,   417,   153,   154,   155,   156,   157,   158,   159,
     160,   523,   550,   524,   164,   525,   526,   167,   168,   169,
     170,   171,   172,   527,   174,   528,   529,   530,   178,   179,
     531,   532,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     0,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     0,     0,     0,
       0,   247,   533,   249,   250,   251,   252,   253,     4,     5,
       6,     7,     8,     9,     0,     0,     0,    12,     0,     0,
       0,   414,   415,     0,    15,    16,    17,   844,    19,    20,
      21,    22,     0,   845,   496,    26,     0,   416,    29,   499,
      31,     0,    33,     0,    34,    35,    36,    37,   846,    39,
       0,     0,    42,    43,    44,    45,   501,     0,    47,   847,
      49,     0,     0,    52,   505,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,   506,
     507,    70,     0,    71,    72,    73,   848,     0,     0,    76,
      77,    78,     0,     0,   509,    80,     0,     0,     0,    81,
      82,   510,    84,   511,   512,    87,    88,   563,    90,     0,
       0,     0,     0,    92,     0,    93,    94,    95,    96,     0,
      97,     0,     0,     0,   513,    99,   100,   514,   515,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,     0,   564,   111,     0,   112,   113,     0,   115,   116,
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     518,     0,   125,     0,     0,     0,     0,     0,   519,   520,
     130,     0,     0,     0,   131,     0,   132,   521,     0,     0,
       0,     0,     0,     0,   137,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,     0,     0,     0,
     150,   151,     0,   417,   153,   154,   155,   156,   157,   158,
     159,   160,   523,     0,   524,   164,   525,   526,   167,   168,
     169,   170,   171,   172,   527,   174,   528,   529,   530,   178,
     179,     0,   532,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     0,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,     0,
     246,     0,   247,   533,   249,   250,   251,   252,   253,     8,
       9,     0,     0,     0,     0,     0,     0,     0,   414,   415,
       0,    15,    16,    17,   493,    19,    20,    21,   494,    23,
     495,   496,  1149,   498,   416,    29,   499,    31,    32,    33,
       0,    34,    35,    36,    37,   500,    39,    40,    41,    42,
      43,    44,    45,   501,     0,    47,   502,    49,   503,   504,
      52,   505,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,   506,   507,    70,     0,
      71,    72,    73,   508,     0,     0,    76,    77,    78,     0,
       0,   509,    80,     0,     0,     0,     0,    82,   510,    84,
     511,   512,    87,    88,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,     0,    97,     0,     0,
       0,   513,    99,   100,   514,   515,     0,     0,     0,     0,
       0,     0,   103,   104,   105,     0,   107,   108,  1150,     0,
       0,     0,  1151,     0,     0,   115,   516,     0,     0,     0,
     117,   118,   119,   120,   517,   122,   123,   518,     0,     0,
       0,     0,     0,     0,     0,   519,   520,   130,     0,     0,
       0,   131,  1585,   132,   521,     0,     0,     0,     0,  1586,
       0,   137,     0,   138,   139,   140,   141,   522,   143,   144,
     145,   146,   147,   148,     0,     0,  1152,   150,     0,     0,
     417,   153,   154,   155,   156,   157,   158,   159,   160,   523,
     162,   524,   164,   525,   526,   167,   168,   169,   170,   171,
     172,   527,   174,   528,   529,   530,   178,   179,   531,   532,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,     0,     8,     9,   247,
     533,   249,  1153,  1154,  1155,  1156,   414,   415,     0,    15,
      16,    17,   541,    19,    20,    21,   494,   542,   543,   496,
     497,   498,   416,    29,   499,    31,   544,    33,     0,    34,
      35,    36,    37,   545,    39,   546,   547,    42,    43,    44,
      45,   501,     0,    47,   548,    49,   503,   504,    52,   505,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,   506,   507,    70,     0,    71,    72,
      73,   549,     0,     0,    76,    77,    78,     0,     0,   509,
      80,     0,     0,     0,     0,    82,   510,    84,   511,   512,
      87,    88,     0,     0,     0,     0,     0,     0,     0,     0,
      93,    94,    95,    96,     0,    97,     0,     0,     0,   513,
      99,   100,   514,   515,     0,     0,     0,     0,     0,     0,
     103,   104,   105,     0,   107,   108,   109,     0,     0,     0,
       0,     0,     0,   115,   516,     0,     0,     0,   117,   118,
     119,   120,   517,   122,   123,   518,     0,     0,     0,     0,
       0,     0,     0,   519,   520,   130,     0,     0,     0,   131,
     762,   132,   521,     0,     0,     0,     0,   763,     0,   137,
       0,   138,   139,   140,   141,   522,   143,   144,   145,   146,
     147,   148,     0,     0,   149,   150,     0,     0,   417,   153,
     154,   155,   156,   157,   158,   159,   160,   523,   550,   524,
     164,   525,   526,   167,   168,   169,   170,   171,   172,   527,
     174,   528,   529,   530,   178,   179,   531,   532,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,     0,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,     0,     0,     8,     9,   247,   533,   249,
     250,   251,   252,   253,   414,   415,     0,    15,    16,    17,
     541,    19,    20,    21,   494,   542,   543,   496,   497,   498,
     416,    29,   499,    31,   544,    33,     0,    34,    35,    36,
      37,   545,    39,   546,   547,    42,    43,    44,    45,   501,
       0,    47,   548,    49,   503,   504,    52,   505,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,   506,   507,    70,     0,    71,    72,    73,   549,
       0,     0,    76,    77,    78,     0,     0,   509,    80,     0,
       0,     0,     0,    82,   510,    84,   511,   512,    87,    88,
       0,     0,     0,     0,     0,     0,     0,     0,    93,    94,
      95,    96,     0,    97,     0,     0,     0,   513,    99,   100,
     514,   515,     0,     0,     0,     0,     0,     0,   103,   104,
     105,     0,   107,   108,   109,     0,     0,     0,     0,     0,
       0,   115,   516,     0,     0,     0,   117,   118,   119,   120,
     517,   122,   123,   518,     0,     0,     0,     0,     0,     0,
       0,   519,   520,   130,     0,     0,     0,   131,   811,   132,
     521,     0,     0,     0,     0,   812,     0,   137,     0,   138,
     139,   140,   141,   522,   143,   144,   145,   146,   147,   148,
       0,     0,   149,   150,     0,     0,   417,   153,   154,   155,
     156,   157,   158,   159,   160,   523,   550,   524,   164,   525,
     526,   167,   168,   169,   170,   171,   172,   527,   174,   528,
     529,   530,   178,   179,   531,   532,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     0,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,     0,     0,     8,     9,   247,   533,   249,   250,   251,
     252,   253,   414,   415,     0,    15,    16,    17,   493,    19,
      20,    21,   494,    23,   495,   496,  1149,   498,   416,    29,
     499,    31,    32,    33,     0,    34,    35,    36,    37,   500,
      39,    40,    41,    42,    43,    44,    45,   501,     0,    47,
     502,    49,   503,   504,    52,   505,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
     506,   507,    70,     0,    71,    72,    73,   508,     0,     0,
      76,    77,    78,     0,     0,   509,    80,     0,     0,     0,
       0,    82,   510,    84,   511,   512,    87,    88,  1501,     0,
       0,     0,     0,     0,     0,     0,    93,    94,    95,    96,
       0,    97,     0,     0,     0,   513,    99,   100,   514,   515,
       0,     0,     0,     0,     0,     0,   103,   104,   105,     0,
     107,   108,  1150,     0,     0,     0,  1151,     0,     0,   115,
     516,     0,     0,     0,   117,   118,   119,   120,   517,   122,
     123,   518,     0,     0,     0,     0,     0,     0,     0,   519,
     520,   130,     0,     0,     0,   131,     0,   132,   521,     0,
       0,     0,     0,     0,     0,   137,     0,   138,   139,   140,
     141,   522,   143,   144,   145,   146,   147,   148,     0,     0,
    1152,   150,     0,     0,   417,   153,   154,   155,   156,   157,
     158,   159,   160,   523,   162,   524,   164,   525,   526,   167,
     168,   169,   170,   171,   172,   527,   174,   528,   529,   530,
     178,   179,   531,   532,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     0,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,     0,
       0,     8,     9,   247,   533,   249,  1153,  1154,  1155,  1156,
     414,   415,     0,    15,    16,    17,   493,    19,    20,    21,
     494,    23,   495,   496,  1149,   498,   416,    29,   499,    31,
      32,    33,     0,    34,    35,    36,    37,   500,    39,    40,
      41,    42,    43,    44,    45,   501,     0,    47,   502,    49,
     503,   504,    52,   505,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,   506,   507,
      70,     0,    71,    72,    73,   508,     0,     0,    76,    77,
      78,     0,     0,   509,    80,     0,     0,     0,     0,    82,
     510,    84,   511,   512,    87,    88,  1643,     0,     0,     0,
       0,     0,     0,     0,    93,    94,    95,    96,     0,    97,
       0,     0,     0,   513,    99,   100,   514,   515,     0,     0,
       0,     0,     0,     0,   103,   104,   105,     0,   107,   108,
    1150,     0,     0,     0,  1151,     0,     0,   115,   516,     0,
       0,     0,   117,   118,   119,   120,   517,   122,   123,   518,
       0,     0,     0,     0,     0,     0,     0,   519,   520,   130,
       0,     0,     0,   131,     0,   132,   521,     0,     0,     0,
       0,     0,     0,   137,     0,   138,   139,   140,   141,   522,
     143,   144,   145,   146,   147,   148,     0,     0,  1152,   150,
       0,     0,   417,   153,   154,   155,   156,   157,   158,   159,
     160,   523,   162,   524,   164,   525,   526,   167,   168,   169,
     170,   171,   172,   527,   174,   528,   529,   530,   178,   179,
     531,   532,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     0,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     0,     0,     8,
       9,   247,   533,   249,  1153,  1154,  1155,  1156,   414,   415,
       0,    15,    16,    17,   493,    19,    20,    21,   494,    23,
     495,   496,  1149,   498,   416,    29,   499,    31,    32,    33,
       0,    34,    35,    36,    37,   500,    39,    40,    41,    42,
      43,    44,    45,   501,     0,    47,   502,    49,   503,   504,
      52,   505,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,   506,   507,    70,     0,
      71,    72,    73,   508,     0,     0,    76,    77,    78,     0,
       0,   509,    80,     0,     0,     0,     0,    82,   510,    84,
     511,   512,    87,    88,  1647,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,     0,    97,     0,     0,
       0,   513,    99,   100,   514,   515,     0,     0,     0,     0,
       0,     0,   103,   104,   105,     0,   107,   108,  1150,     0,
       0,     0,  1151,     0,     0,   115,   516,     0,     0,     0,
     117,   118,   119,   120,   517,   122,   123,   518,     0,     0,
       0,     0,     0,     0,     0,   519,   520,   130,     0,     0,
       0,   131,     0,   132,   521,     0,     0,     0,     0,     0,
       0,   137,     0,   138,   139,   140,   141,   522,   143,   144,
     145,   146,   147,   148,     0,     0,  1152,   150,     0,     0,
     417,   153,   154,   155,   156,   157,   158,   159,   160,   523,
     162,   524,   164,   525,   526,   167,   168,   169,   170,   171,
     172,   527,   174,   528,   529,   530,   178,   179,   531,   532,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,     0,     8,     9,   247,
     533,   249,  1153,  1154,  1155,  1156,   414,   415,     0,    15,
      16,    17,   493,    19,    20,    21,   494,    23,   495,   496,
    1149,   498,   416,    29,   499,    31,    32,    33,     0,    34,
      35,    36,    37,   500,    39,    40,    41,    42,    43,    44,
      45,   501,     0,    47,   502,    49,   503,   504,    52,   505,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,   506,   507,    70,     0,    71,    72,
      73,   508,     0,     0,    76,    77,    78,     0,     0,   509,
      80,     0,     0,     0,     0,    82,   510,    84,   511,   512,
      87,    88,     0,     0,     0,     0,     0,     0,     0,     0,
      93,    94,    95,    96,     0,    97,     0,     0,     0,   513,
      99,   100,   514,   515,     0,     0,     0,     0,     0,     0,
     103,   104,   105,     0,   107,   108,  1150,     0,     0,     0,
    1151,     0,     0,   115,   516,     0,     0,     0,   117,   118,
     119,   120,   517,   122,   123,   518,     0,     0,     0,     0,
       0,     0,     0,   519,   520,   130,     0,     0,     0,   131,
       0,   132,   521,     0,     0,     0,     0,     0,     0,   137,
       0,   138,   139,   140,   141,   522,   143,   144,   145,   146,
     147,   148,     0,     0,  1152,   150,     0,     0,   417,   153,
     154,   155,   156,   157,   158,   159,   160,   523,   162,   524,
     164,   525,   526,   167,   168,   169,   170,   171,   172,   527,
     174,   528,   529,   530,   178,   179,   531,   532,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,     0,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,     0,     0,     8,     9,   247,   533,   249,
    1153,  1154,  1155,  1156,   414,   415,     0,    15,    16,    17,
     493,    19,    20,    21,   494,    23,   495,   496,  1149,   498,
     416,    29,   499,    31,    32,    33,     0,    34,    35,    36,
      37,   500,    39,    40,    41,    42,    43,    44,    45,   501,
       0,    47,   502,    49,   503,   504,    52,   505,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,   506,   507,    70,     0,    71,    72,    73,   508,
       0,     0,    76,    77,    78,     0,     0,   509,    80,     0,
       0,     0,     0,    82,   510,    84,   511,   512,    87,    88,
       0,     0,     0,     0,     0,     0,     0,     0,    93,    94,
      95,    96,     0,    97,     0,     0,     0,   513,    99,   100,
     514,   515,     0,     0,     0,     0,     0,     0,   103,   104,
     105,     0,   107,   108,  1150,     0,     0,     0,  1151,     0,
       0,   115,   516,     0,     0,     0,   117,   118,   119,   120,
     517,   122,   123,   518,     0,     0,     0,     0,     0,     0,
       0,   519,   520,   130,     0,     0,     0,   131,     0,   132,
     521,     0,     0,     0,     0,     0,     0,   137,     0,   138,
     139,   140,   141,   522,   143,   144,   145,   146,   147,   148,
       0,     0,   149,   150,     0,     0,   417,   153,   154,   155,
     156,   157,   158,   159,   160,   523,   162,   524,   164,   525,
     526,   167,   168,   169,   170,   171,   172,   527,   174,   528,
     529,   530,   178,   179,   531,   532,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     0,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,     0,     0,     8,     9,   247,   533,   249,  1153,  1154,
    1155,  1156,   414,   415,     0,    15,    16,    17,   541,    19,
      20,    21,   494,   542,   543,   496,   497,   498,   416,    29,
     499,    31,   544,    33,     0,    34,    35,    36,    37,   545,
      39,   546,   547,    42,    43,    44,    45,   501,     0,    47,
     548,    49,   503,   504,    52,   505,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
     506,   507,    70,     0,    71,    72,    73,   549,     0,     0,
      76,    77,    78,     0,     0,   509,    80,     0,     0,     0,
       0,    82,   510,    84,   511,   512,    87,    88,  1244,     0,
       0,     0,     0,     0,     0,     0,    93,    94,    95,    96,
       0,    97,     0,     0,     0,   513,    99,   100,   514,   515,
       0,     0,     0,     0,     0,     0,   103,   104,   105,     0,
     107,   108,   109,     0,     0,     0,     0,     0,     0,   115,
     516,     0,     0,     0,   117,   118,   119,   120,   517,   122,
     123,   518,     0,     0,     0,     0,     0,     0,     0,   519,
     520,   130,     0,     0,     0,   131,     0,   132,   521,     0,
       0,     0,     0,     0,     0,   137,     0,   138,   139,   140,
     141,   522,   143,   144,   145,   146,   147,   148,     0,     0,
     149,   150,     0,     0,   417,   153,   154,   155,   156,   157,
     158,   159,   160,   523,   550,   524,   164,   525,   526,   167,
     168,   169,   170,   171,   172,   527,   174,   528,   529,   530,
     178,   179,   531,   532,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     0,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,     0,
       0,     8,     9,   247,   533,   249,   250,   251,   252,   253,
     414,   415,     0,    15,    16,    17,   541,    19,    20,    21,
     494,   542,   543,   496,   497,   498,   416,    29,   499,    31,
     544,    33,     0,    34,    35,    36,    37,   545,    39,   546,
     547,    42,    43,    44,    45,   501,     0,    47,   548,    49,
     503,   504,    52,   505,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,   506,   507,
      70,     0,    71,    72,    73,   549,     0,     0,    76,    77,
      78,     0,     0,   509,    80,     0,     0,     0,     0,    82,
     510,    84,   511,   512,    87,    88,     0,     0,     0,     0,
       0,     0,     0,     0,    93,    94,    95,    96,     0,    97,
       0,     0,     0,   513,    99,   100,   514,   515,     0,     0,
       0,     0,     0,     0,   103,   104,   105,     0,   107,   108,
     109,     0,     0,     0,     0,     0,     0,   115,   516,     0,
       0,     0,   117,   118,   119,   120,   517,   122,   123,   518,
       0,     0,     0,     0,     0,     0,     0,   519,   520,   130,
       0,     0,     0,   131,     0,   132,   521,     0,     0,     0,
       0,     0,     0,   137,     0,   138,   139,   140,   141,   522,
     143,   144,   145,   146,   147,   148,     0,     0,   149,   150,
       0,     0,   417,   153,   154,   155,   156,   157,   158,   159,
     160,   523,   550,   524,   164,   525,   526,   167,   168,   169,
     170,   171,   172,   527,   174,   528,   529,   530,   178,   179,
     531,   532,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     0,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     0,     0,     8,
       9,   247,   533,   249,   250,   251,   252,   253,   414,   415,
       0,    15,    16,    17,     0,    19,    20,    21,   494,     0,
       0,   496,   497,     0,   416,    29,   499,    31,     0,    33,
       0,    34,    35,    36,    37,     0,    39,     0,     0,    42,
      43,    44,    45,   501,     0,    47,     0,    49,     0,     0,
      52,   505,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,   506,   507,    70,     0,
      71,    72,    73,     0,     0,     0,    76,    77,    78,     0,
       0,   509,    80,     0,     0,     0,     0,    82,   510,    84,
     511,   512,    87,    88,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,     0,    97,     0,     0,
       0,   513,    99,   100,   514,   515,     0,     0,     0,     0,
       0,     0,   103,   104,   105,     0,   107,   108,     0,     0,
       0,     0,     0,     0,     0,   115,   516,     0,     0,     0,
     117,   118,   119,   120,   517,   122,   123,   518,     0,     0,
       0,     0,     0,     0,     0,   519,   520,   130,     0,     0,
       0,   131,     0,   132,   521,     0,     0,     0,     0,     0,
       0,   137,     0,   138,   139,   140,   141,   522,   143,   144,
     145,   146,   147,   148,     0,     0,     0,   150,     0,     0,
     417,   153,   154,   155,   156,   157,   158,   159,   160,   523,
       0,   524,   164,   525,   526,   167,   168,   169,   170,   171,
     172,   527,   174,   528,   529,   530,   178,   179,     0,   532,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,     0,     0,     0,   247,
     533,   249,   250,   251,   252,   253
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,     4,     5,     6,     4,     5,     6,     7,   181,   313,
       4,     5,     6,     7,   831,   111,   112,    13,   693,   677,
     767,   342,   787,     0,  1061,   425,   426,     4,     5,     6,
       7,   627,   628,   427,   135,   800,   261,   678,   679,   680,
     681,   767,   916,     1,   870,   262,   592,  1045,  1297,   814,
    1314,    75,   598,  1135,  1085,     4,     5,     6,     7,   293,
     277,  1378,  1379,   254,   255,     1,   929,   930,   724,   439,
      37,    27,    28,   467,   468,    37,   625,   626,   627,   628,
     450,   625,   626,   952,  1504,    30,  1002,  1507,    27,    28,
    1020,    57,    48,  1411,     1,     1,     1,   656,  1327,   658,
     659,    96,   661,     1,   663,     1,   476,     1,   284,    48,
     110,    30,   671,   672,    38,    39,   110,    41,    42,    58,
      76,   929,   930,     1,    40,    46,   144,     1,   149,    45,
      46,    98,     1,   110,    96,    59,    98,    76,    54,   120,
       1,     1,    81,    64,   109,    61,   109,    63,    64,   245,
     246,   109,     1,   968,    27,    28,    72,   109,   114,  1022,
     968,   110,     0,     1,    31,   120,     1,   112,     1,   156,
     226,   158,  1035,   109,   113,   114,   115,     8,   138,   155,
     155,   126,   149,    99,     1,   218,   420,   149,   170,    98,
     424,   115,   120,    96,  1002,   109,     1,   293,     1,     0,
       1,     1,   109,   160,   138,   108,   151,    98,   155,   974,
     155,   109,     1,   158,  1022,   109,   158,   102,   152,  1607,
     177,   203,   255,   188,   219,   220,    56,  1035,    58,     1,
    1547,   178,   187,   178,     1,   211,   211,   189,   162,   234,
      96,   114,   202,   162,   345,   226,     1,   123,   109,   158,
     109,   238,   218,   274,   254,   255,   274,  1294,   258,   315,
     109,  1135,  1136,  1028,  1081,   569,    30,   188,  1517,  1034,
     446,   109,   102,   236,   109,   189,   109,   254,   255,   186,
    1027,   258,  1280,   879,   880,   191,   191,  1318,  1606,   255,
     188,  1520,   109,   293,   188,   191,  1327,   221,   954,  1025,
      98,  1027,   187,  1723,   109,  1387,   109,   274,   109,   109,
     226,     1,   274,   191,  1244,   260,   293,   191,  1187,  1235,
     109,  1047,   191,   557,   420,   186,   350,   308,   424,   353,
      75,   191,   288,   877,   878,   149,  1151,   109,   262,   188,
     296,   735,   109,  1151,    89,   176,   274,   185,   215,   288,
    1770,   115,  1772,   912,   109,   188,   314,   296,   234,   455,
       1,    78,    98,   219,   220,   304,   257,   258,   113,   465,
    1758,   188,   170,    95,     1,   234,   312,    96,   234,   475,
     125,   109,   127,   188,   185,   188,   482,   483,   188,    96,
    1707,   785,     1,     1,   102,   491,     9,    10,   162,   188,
     625,   626,   318,   319,   320,   622,   623,     1,   226,  1272,
     644,   781,   187,   231,   784,   632,   188,   132,   109,   109,
     420,   188,   252,   614,   424,   144,   155,  1235,   109,   158,
     185,    46,   183,    48,   170,   265,   211,   267,   155,    30,
     109,   120,   149,   420,  1761,     1,   197,   424,   278,   279,
     280,   451,   282,   453,   284,   253,   254,   451,   256,   453,
     274,   557,   184,   191,  1272,   263,    81,   102,   109,  1234,
       1,     1,     9,    10,   451,   273,   453,   573,   574,   187,
     480,  1745,   109,   198,     1,   485,   480,   285,  1296,  1520,
     586,   485,   105,   108,   185,   185,   226,   315,   228,  1246,
     109,   109,   451,   480,   453,   222,   223,   188,   485,   188,
     606,   607,   125,  1387,   127,   109,   916,   253,   254,   188,
     256,   112,  1396,     5,  1120,  1121,  1122,     9,     1,  1255,
       3,   480,  1674,  1407,  1360,   126,   485,   273,  1364,   158,
     109,  1790,   155,   226,   185,   228,   159,   947,    46,   285,
      48,   155,   187,   109,   169,  1230,  1419,   557,   185,  1105,
     151,   109,   175,     5,   564,   133,   120,     9,   105,    98,
     564,  1120,  1121,  1122,   178,   132,   185,   185,   109,   109,
     557,   975,   976,   196,   109,   315,   980,   564,   125,    96,
     127,   185,   109,   109,   155,    68,   697,   698,   694,   109,
      73,   214,    96,   699,    53,   350,  1748,   607,   353,   109,
     108,  1419,    96,   607,   614,   564,  1010,  1382,   155,   188,
     149,   162,   159,   191,   620,   625,   626,   627,   628,   185,
     607,  1629,   315,   187,   868,   109,   108,   614,   175,   109,
     188,   198,   149,   125,   644,   127,   158,   120,   625,   626,
     627,   628,   877,   135,   185,   185,  1016,   129,  1018,   196,
     144,   895,   156,   188,   158,   187,   883,   644,   185,    98,
     887,   169,   188,   155,    30,    43,     1,   214,   188,    47,
       9,    10,   131,   125,    52,   127,   431,   432,   188,   211,
     435,    43,   146,   135,   439,    47,  1504,   442,   443,  1507,
      52,  1518,  1576,    71,   120,   450,  1523,  1744,  1068,    34,
    1070,   456,   457,   155,   188,   183,   461,   119,   188,    71,
     149,  1468,   158,   177,   469,     9,   822,   823,   824,   197,
     826,   476,   477,   478,   479,  1135,  1136,    27,    28,   484,
    1398,   195,   102,    98,    25,    29,   148,   492,    38,    39,
      98,    41,    42,   124,    35,   115,   112,    43,    48,   161,
     115,    47,     9,    10,  1735,  1736,    52,   115,    58,    59,
     126,  1367,   868,   300,   777,   158,   105,   777,  1453,  1642,
     160,    62,   309,   777,   155,    71,    76,   158,     1,   187,
      96,    81,   537,   195,    98,   151,   125,   177,   127,   155,
     777,   169,   158,   158,   172,   158,  1777,   552,   808,   809,
     158,   115,  1783,   211,   808,   809,  1137,   169,   563,   187,
     172,    34,   178,   113,   114,   115,   155,  1690,   777,  1692,
     159,   808,   809,   139,  1642,   187,  1653,    50,   144,    96,
    1657,   125,     9,   127,   158,   213,   175,   592,   160,   160,
     158,   108,   136,   598,   248,   249,   270,   602,   105,   808,
     809,   213,    29,   277,   139,   177,   177,   196,   868,   144,
      55,   155,   162,   287,    55,    60,  1110,   271,   125,    60,
     127,  1275,  1690,   169,  1692,   214,   172,   144,   200,   200,
     270,   868,  1755,   889,  1111,   895,   187,   277,    79,   187,
    1117,   187,   187,    97,   269,    34,   158,   287,   155,  1567,
    1568,   276,   159,    98,   108,  1723,   167,    98,   895,  1560,
     211,    50,  1739,   211,   118,   102,   211,   213,   175,   150,
     150,   221,   183,   158,  1609,   129,   139,   139,   115,   120,
     147,  1114,  1707,   102,   102,   166,   166,  1755,   102,   196,
     102,   158,   155,   155,   965,   124,   115,   115,   125,   264,
     127,   115,  1770,   115,  1772,   264,   977,   214,   202,   136,
     275,   233,   262,   235,   139,   700,   275,   211,   703,   144,
    1374,   706,   155,   728,   124,   158,   731,  1387,   155,   278,
     279,   280,    55,   192,   193,   284,  1396,    60,   288,   629,
     745,   675,   676,   633,   749,   750,   296,  1407,   155,   155,
     349,   158,   158,   352,   304,   124,   222,   223,   224,   124,
    1678,  1679,   156,   233,   158,   235,   771,   120,   773,   130,
     131,   130,   131,   682,   683,   124,   781,  1712,  1134,   784,
    1274,    89,   120,   788,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,   124,  1359,   684,   685,  1228,  1229,
    1597,  1598,   124,  1063,   155,   113,   124,   155,   124,  1063,
     124,   124,   155,   217,   158,   120,   242,   125,   242,   127,
     243,   158,   155,   315,  1759,   830,  1063,     0,   191,   168,
      94,  1485,   101,  1751,   250,    51,   103,   201,   104,   194,
     185,   156,    30,   185,   185,   185,    48,   134,   154,   120,
    1110,   247,   305,   188,  1063,   142,   143,   285,   145,   120,
    1120,  1121,  1122,  1119,   285,   870,   153,   155,     1,   120,
     157,   144,   159,  1110,   109,   155,   188,   164,   188,   155,
     158,   158,   144,  1120,  1121,  1122,   158,   123,   158,   185,
     158,    36,    17,   180,   899,   158,  1831,  1551,  1833,   158,
     158,   155,    30,   188,   215,   232,   231,   191,  1843,   191,
     246,     3,   120,   169,   171,    72,  1576,   204,   205,   206,
     207,   208,   209,  1356,   929,   930,   931,   932,   171,   232,
      96,    96,    96,   151,   109,   109,    30,   162,   162,   129,
     134,    96,   300,   247,   144,   134,   185,   185,   120,   109,
      96,   188,   185,    46,   188,    98,    98,   188,   188,   188,
     188,    96,   155,   968,   185,   144,   226,    34,   155,   155,
     155,   155,   155,   238,   191,  1238,   171,   982,  1238,   232,
     120,   134,   234,   144,  1238,    96,    30,   287,   228,    96,
     129,   300,   155,   120,   120,   149,    96,   134,   199,    98,
     255,  1238,  1007,  1497,   185,   134,   162,   155,   120,   185,
     144,  1016,   102,  1018,  1274,  1020,   102,  1022,   149,   155,
     191,   123,  1285,   185,    36,  1285,    30,   246,    81,  1238,
    1035,  1285,   155,   120,   109,   109,   286,  1274,   261,   259,
     158,  1304,   268,   158,  1304,   158,  1540,    30,  1285,   158,
    1304,   146,   158,   158,   158,   287,    30,    30,   307,   228,
     149,   288,   146,  1068,  1324,  1070,   129,  1304,   188,   191,
    1324,  1331,   188,   149,   188,   120,  1285,  1331,   188,   149,
     120,    79,   109,   144,   185,   188,   102,  1324,   134,     7,
     188,   199,    98,   234,  1331,  1304,   234,   155,   158,   187,
    1105,   158,   234,  1363,   234,   108,   191,   158,   188,  1363,
     149,    80,   109,   283,   238,  1324,   188,   188,    30,   287,
     188,    30,  1331,   188,   432,  1130,  1363,   435,   272,   188,
     251,   439,   251,  1627,   442,   443,   188,   171,   188,   149,
     149,   258,   450,   185,  1638,  1639,  1151,  1641,   456,   457,
     128,   128,    98,   461,   185,  1649,   144,   187,   187,   187,
     185,   469,   185,   185,   185,   317,   155,    96,   476,   477,
     478,   479,    30,   188,    98,   188,   484,   171,   149,    55,
      96,  1537,  1538,  1539,   492,   281,   108,   198,    96,    30,
     109,   288,   109,   266,   120,   120,    96,   187,    96,   198,
     226,   187,   198,    95,   199,   120,   226,   198,   184,   120,
     120,   258,   294,   200,   120,   306,   734,   187,   226,   288,
     258,  1190,   969,   306,   261,   306,  1036,   426,   307,   537,
     307,   446,  1235,  1712,  1759,   871,   790,  1497,  1732,  1244,
    1033,   307,  1264,  1248,   552,  1478,  1383,   461,  1126,  1381,
    1378,   552,  1286,  1291,  1294,   563,  1299,   654,  1263,   674,
    1497,   932,   655,  1318,   708,  1783,  1777,  1272,   831,  1018,
    1189,  1350,   454,   337,   454,  1361,  1360,  1771,  1396,  1576,
    1540,  1286,  1407,  1136,  1573,  1400,  1145,  1212,  1001,  1600,
    1443,  1296,  1397,    -1,   602,  1789,    -1,   596,    -1,    -1,
      -1,    -1,    -1,  1540,    -1,    -1,    -1,    -1,    -1,    -1,
    1804,    -1,    -1,    -1,  1670,    -1,    -1,    -1,    -1,    -1,
    1325,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,  1825,  1688,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1834,    -1,    -1,    -1,    -1,  1350,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1360,    -1,    -1,    -1,  1364,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1627,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1638,  1639,
      -1,  1641,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1649,
    1627,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1638,  1639,    -1,  1641,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1649,    -1,  1419,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   731,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   745,    -1,    -1,
      -1,   749,   750,    -1,  1449,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   771,    -1,   773,    -1,    -1,    -1,    -1,
    1475,  1476,  1732,   781,    -1,    -1,   784,    -1,    -1,    -1,
     788,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1732,  1501,    -1,    -1,  1504,
      -1,    -1,  1507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1771,    -1,    -1,  1519,    -1,    -1,    -1,    -1,  1524,
      -1,    -1,   830,    -1,    -1,    -1,    -1,    -1,    -1,  1789,
      -1,    -1,    -1,    -1,  1771,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1804,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1789,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1825,    -1,  1804,    -1,    -1,
      -1,    -1,    -1,    -1,  1834,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1825,    -1,
      -1,   899,    -1,    -1,    -1,    -1,    -1,  1834,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   929,   930,   931,   932,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1642,  1643,    -1,
    1645,    -1,  1647,    -1,    -1,    -1,    -1,    -1,    -1,  1654,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     968,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   982,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1690,    -1,  1692,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1007,
      -1,    -1,    -1,  1708,    -1,    -1,  1711,    -1,  1016,    -1,
    1018,    -1,  1020,    -1,  1022,    -1,    -1,    -1,  1723,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1035,    -1,  1734,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1755,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1763,    -1,
    1068,    -1,  1070,  1768,    -1,  1770,    -1,  1772,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   564,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1801,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   590,   591,    -1,    -1,   594,
     595,   596,   597,    -1,   599,    -1,  1821,    -1,    -1,    -1,
     605,  1826,  1130,    -1,    -1,    -1,    -1,    -1,   613,    -1,
      -1,    -1,    -1,  1838,    -1,    -1,  1841,    -1,    -1,    -1,
      -1,    -1,    -1,  1151,    -1,    -1,    -1,    -1,    -1,    -1,
     635,   636,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   644,
     645,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     705,    -1,    -1,   708,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1244,    -1,    -1,    -1,
    1248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1263,    -1,    -1,    -1,    -1,
      -1,    -1,   747,    -1,  1272,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1286,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1296,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   789,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1325,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     815,    -1,    -1,    -1,   819,   820,    -1,    -1,    -1,    -1,
      -1,    -1,  1350,   828,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     895,  1419,    -1,    -1,    -1,    -1,   901,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1475,  1476,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   970,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1501,    -1,    -1,  1504,    -1,    -1,  1507,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1519,    -1,    -1,    -1,    -1,  1524,    -1,    -1,    -1,
    1005,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1024,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1046,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1057,  1058,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1072,    -1,    -1,
    1075,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1092,  1093,  1094,
      -1,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,
      -1,    -1,  1107,  1108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1116,    -1,    -1,  1642,  1643,    -1,  1645,    -1,  1647,
      -1,  1126,    -1,    -1,    -1,    -1,  1654,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1690,    -1,  1692,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1708,    -1,    -1,  1711,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1723,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1734,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1755,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1763,    -1,    -1,    -1,    -1,
    1768,    -1,  1770,    -1,  1772,  1250,    -1,  1252,    -1,  1254,
      -1,    -1,  1257,    -1,    -1,    -1,    -1,  1262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1274,
      -1,    -1,    -1,  1801,    -1,    -1,    -1,    -1,  1283,    -1,
      -1,    -1,    -1,    -1,  1289,  1290,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1821,    -1,    -1,    -1,    -1,  1826,    -1,
      -1,    -1,    -1,  1308,    -1,    -1,  1311,    -1,    -1,    -1,
    1838,    -1,    -1,  1841,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1381,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1552,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1615,    -1,  1617,    -1,    -1,  1620,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1628,    -1,    -1,    -1,    -1,  1633,  1634,
      -1,    -1,    -1,    -1,    -1,    -1,  1641,    -1,    -1,    -1,
      -1,  1646,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1663,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1675,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1715,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1728,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1771,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,    -1,  1799,    -1,    -1,    -1,    -1,  1804,
      -1,    11,    12,    -1,  1809,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,  1824,
      30,    -1,    -1,  1828,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
     100,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,   214,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,    -1,   313,    -1,   315,   316,   317,   318,   319,
     320,   321,     0,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,   100,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,    -1,   192,   193,    -1,   195,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,   214,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,     1,   313,    -1,   315,   316,   317,
     318,   319,   320,   321,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,   100,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
     177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,    -1,   192,   193,    -1,   195,    -1,
     197,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,    -1,   212,   213,   214,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,   260,   261,   262,    -1,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,     1,   313,    -1,   315,   316,
     317,   318,   319,   320,   321,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,   100,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,    -1,   192,   193,    -1,   195,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,   214,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,    -1,   313,    -1,   315,
     316,   317,   318,   319,   320,   321,     0,     1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    96,    97,    98,    -1,    -1,   101,   102,   103,
     104,    -1,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,   118,   119,   120,    -1,    -1,   123,
      -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,
     134,    -1,    -1,    -1,   138,    -1,    -1,    -1,   142,   143,
      -1,   145,    -1,   147,   148,    -1,    -1,    -1,   152,   153,
      -1,    -1,   156,   157,   158,   159,   160,   161,    -1,    -1,
     164,    -1,    -1,    -1,   168,   169,    -1,    -1,   172,    -1,
      -1,    -1,    -1,   177,    -1,    -1,   180,    -1,    -1,    -1,
      -1,   185,   186,   187,   188,   189,    -1,   191,   192,   193,
     194,   195,    -1,    -1,    -1,    -1,   200,   201,   202,    -1,
     204,   205,   206,   207,   208,   209,    -1,   211,    -1,   213,
      -1,    -1,    -1,    -1,   218,   219,   220,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,    -1,   236,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,    -1,
      -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,   312,    -1,
     314,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,   100,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,
     193,    -1,   195,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,   214,    -1,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,   260,   261,   262,
      -1,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
     313,    -1,   315,   316,   317,   318,   319,   320,   321,   322,
     323,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
     100,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,   214,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,    -1,   313,    -1,   315,   316,   317,   318,   319,
     320,   321,    -1,   323,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,   100,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
     177,   178,    -1,    -1,   181,   182,   183,    -1,   185,    -1,
     187,    -1,   189,   190,    -1,   192,   193,    -1,   195,    -1,
     197,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,    -1,   212,   213,   214,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,   260,   261,   262,    -1,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,    -1,   313,    -1,   315,   316,
     317,   318,   319,   320,   321,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,   100,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,   185,
      -1,   187,    -1,   189,   190,    -1,   192,   193,    -1,   195,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,   214,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,    -1,   313,    -1,   315,
     316,   317,   318,   319,   320,   321,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,
     185,    -1,   187,    -1,   189,   190,    -1,   192,   193,    -1,
     195,    -1,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,    -1,   212,   213,   214,
      -1,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,   260,   261,   262,    -1,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    -1,   313,    -1,
     315,   316,   317,   318,   319,   320,   321,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,   100,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,   193,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,    -1,   313,
      -1,   315,   316,   317,   318,   319,   320,   321,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,   100,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,
     193,    -1,   195,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,   214,    -1,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,   260,   261,   262,
      -1,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
     313,    -1,   315,   316,   317,   318,   319,   320,   321,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,   100,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,
     192,   193,    -1,   195,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,   214,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
      -1,   313,    -1,   315,   316,   317,   318,   319,   320,   321,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,   100,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,
      -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,   212,   213,   214,    -1,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    -1,   260,
     261,   262,    -1,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,    -1,   313,    -1,   315,   316,   317,   318,   319,   320,
     321,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
     100,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,   214,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,    -1,   313,    -1,   315,   316,   317,   318,   319,
     320,   321,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,   100,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,   146,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,
     189,   190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,   260,   261,   262,    -1,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,    -1,   313,    -1,   315,   316,   317,   318,
     319,   320,   321,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,   100,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,   146,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,   192,   193,    -1,   195,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,   214,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,    -1,   313,    -1,   315,   316,   317,
     318,   319,   320,   321,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,   100,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
     177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,    -1,   192,   193,    -1,   195,    -1,
     197,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,    -1,   212,   213,   214,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,   260,   261,   262,    -1,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,    -1,   313,    -1,   315,   316,
     317,   318,   319,   320,   321,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,   100,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,    -1,
     186,   187,    -1,   189,   190,    -1,   192,   193,    -1,   195,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,   214,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,    -1,   313,    -1,   315,
     316,   317,   318,   319,   320,   321,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,   177,   178,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,   188,   189,   190,    -1,   192,   193,    -1,
     195,    -1,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,    -1,   212,   213,   214,
      -1,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,   260,   261,   262,    -1,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    -1,   313,    -1,
     315,   316,   317,   318,   319,   320,   321,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,   100,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,   193,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
     214,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
      -1,   315,   316,   317,   318,   319,   320,   321,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,   100,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,   192,
     193,    -1,   195,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,   212,
     213,   214,    -1,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,   260,   261,   262,
      -1,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
     313,   314,   315,   316,   317,   318,   319,   320,   321,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,   100,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,   181,
     182,   183,    -1,   185,    -1,   187,    -1,   189,   190,    -1,
     192,   193,    -1,   195,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,   214,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
      -1,   313,    -1,   315,   316,   317,   318,   319,   320,   321,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,   100,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,   146,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,   175,    -1,   177,   178,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,
      -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,   212,   213,   214,    -1,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,    -1,   260,
     261,   262,    -1,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,    -1,   313,    -1,   315,   316,   317,   318,   319,   320,
     321,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
     100,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,   175,    -1,   177,   178,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,   214,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,    -1,   313,    -1,   315,   316,   317,   318,   319,
     320,   321,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,   100,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,
     189,   190,    -1,   192,   193,    -1,   195,    -1,   197,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,    -1,   212,   213,   214,    -1,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
      -1,   260,   261,   262,    -1,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,    -1,   313,    -1,   315,   316,   317,   318,
     319,   320,   321,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,   100,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,   175,    -1,   177,
     178,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,    -1,   192,   193,    -1,   195,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,   214,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,    -1,   313,    -1,   315,   316,   317,
     318,   319,   320,   321,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,   100,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,    -1,   175,    -1,
      -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,
     187,    -1,   189,   190,    -1,   192,   193,    -1,   195,    -1,
     197,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,    -1,   212,   213,   214,    -1,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,    -1,   260,   261,   262,    -1,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,    -1,   313,    -1,   315,   316,
     317,   318,   319,   320,   321,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,   100,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,   175,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,   214,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,    -1,   313,    -1,   315,
     316,   317,   318,   319,   320,   321,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,   100,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,    -1,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,    -1,   153,   154,
     155,   156,    -1,   158,   159,    -1,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
     175,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,    -1,
     195,    -1,   197,    -1,   199,    -1,   201,    -1,   203,   204,
     205,   206,   207,   208,   209,    -1,    -1,   212,   213,   214,
      -1,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,   260,   261,   262,    -1,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    -1,   313,    -1,
     315,   316,   317,   318,   319,   320,   321,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,
      -1,   195,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
      -1,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,    -1,    -1,    11,
      12,   315,   316,   317,   318,   319,   320,   321,    20,    -1,
      -1,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
     152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,
      -1,    -1,    -1,   195,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,    -1,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
      -1,    16,    -1,   315,   316,   317,   318,   319,   320,   321,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,
     115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,   154,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,
      -1,    -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,
      -1,    -1,   197,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,    -1,   212,   213,    -1,
      -1,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,    -1,   260,   261,   262,    -1,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,    -1,    16,    -1,
     315,   316,   317,   318,   319,   320,   321,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,    -1,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,    -1,    -1,    -1,    -1,   315,   316,   317,
     318,   319,   320,   321,    18,    19,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
      -1,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,    -1,    -1,    -1,
      -1,   315,   316,   317,   318,   319,   320,   321,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    46,    47,    48,    -1,    50,    51,    52,
      53,    -1,    55,    -1,    57,    58,    59,    60,    61,    62,
      -1,    -1,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    -1,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,    -1,   155,   156,    -1,   158,   159,    -1,   161,   162,
      -1,    -1,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,    -1,   175,    -1,    -1,    -1,    -1,    -1,   181,   182,
     183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,
      -1,    -1,    -1,    -1,   197,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,    -1,    -1,
     213,   214,    -1,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,    -1,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,    -1,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,    -1,   260,   261,   262,
      -1,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
     313,    -1,   315,   316,   317,   318,   319,   320,   321,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,    -1,   152,   153,   154,    -1,
      -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,   188,   189,   190,    -1,    -1,    -1,    -1,   195,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,    -1,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,    -1,    25,    26,   315,
     316,   317,   318,   319,   320,   321,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
     188,   189,   190,    -1,    -1,    -1,    -1,   195,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,    -1,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,    -1,    -1,    25,    26,   315,   316,   317,
     318,   319,   320,   321,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,    -1,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,   188,   189,
     190,    -1,    -1,    -1,    -1,   195,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,    -1,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,    -1,    -1,    25,    26,   315,   316,   317,   318,   319,
     320,   321,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
     152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,    -1,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
      -1,    25,    26,   315,   316,   317,   318,   319,   320,   321,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,
     154,    -1,    -1,    -1,   158,    -1,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
      -1,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,    -1,    -1,    25,
      26,   315,   316,   317,   318,   319,   320,   321,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,    -1,   152,   153,   154,    -1,
      -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,   212,   213,    -1,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,    -1,    25,    26,   315,
     316,   317,   318,   319,   320,   321,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,
     158,    -1,    -1,   161,   162,    -1,    -1,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,   182,   183,    -1,    -1,    -1,   187,
      -1,   189,   190,    -1,    -1,    -1,    -1,    -1,    -1,   197,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,   212,   213,    -1,    -1,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,    -1,   260,   261,   262,    -1,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,    -1,    -1,    25,    26,   315,   316,   317,
     318,   319,   320,   321,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
      -1,   161,   162,    -1,    -1,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,
     190,    -1,    -1,    -1,    -1,    -1,    -1,   197,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,   212,   213,    -1,    -1,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,    -1,
     260,   261,   262,    -1,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,    -1,    -1,    25,    26,   315,   316,   317,   318,   319,
     320,   321,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
     152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,    -1,    -1,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   197,    -1,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,    -1,    -1,
     212,   213,    -1,    -1,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,    -1,   260,   261,
     262,    -1,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
      -1,    25,    26,   315,   316,   317,   318,   319,   320,   321,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,
      -1,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,    -1,    -1,   187,    -1,   189,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   197,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,   212,   213,
      -1,    -1,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,    -1,   260,   261,   262,    -1,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,    -1,    -1,    25,
      26,   315,   316,   317,   318,   319,   320,   321,    34,    35,
      -1,    37,    38,    39,    -1,    41,    42,    43,    44,    -1,
      -1,    47,    48,    -1,    50,    51,    52,    53,    -1,    55,
      -1,    57,    58,    59,    60,    -1,    62,    -1,    -1,    65,
      66,    67,    68,    69,    -1,    71,    -1,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    -1,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   181,   182,   183,    -1,    -1,
      -1,   187,    -1,   189,   190,    -1,    -1,    -1,    -1,    -1,
      -1,   197,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    -1,    -1,    -1,   213,    -1,    -1,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,    -1,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,    -1,   260,   261,   262,    -1,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,    -1,    -1,    -1,   315,
     316,   317,   318,   319,   320,   321
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    12,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    30,    34,    35,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    96,    97,    98,    99,   100,   102,   103,   104,   107,
     108,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   126,   128,   129,   130,   131,   133,   137,   138,
     139,   140,   141,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   158,   159,   160,   161,   162,   166,   167,   168,
     169,   170,   171,   172,   173,   175,   177,   178,   181,   182,
     183,   187,   189,   190,   192,   193,   195,   197,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   212,
     213,   214,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   260,   261,   262,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   313,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   336,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   357,   358,   359,   360,   361,   362,
     366,   367,   368,   372,   374,   375,   377,   384,   386,   389,
     390,   391,   393,   394,   395,   396,   397,   399,   400,   402,
     403,   404,   405,   406,   407,   409,   410,   413,   414,   415,
     416,   421,   423,   425,   426,   431,   450,   453,   457,   460,
     461,   467,   468,   469,   470,   472,   473,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   485,   486,   487,   488,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   521,   522,   523,
     524,   525,   526,   540,   541,   543,   544,   545,   546,   547,
     548,   549,   550,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   571,   576,   577,   578,   579,   580,
     581,   584,   642,   643,   644,   645,   647,   648,   649,   650,
     651,   658,   659,   660,    34,    35,    50,   216,   392,   393,
     394,   392,   392,   393,   394,   158,   158,    38,    39,    41,
      42,    48,    58,    59,    76,    81,   113,   114,   115,   162,
     221,   262,   288,   296,   304,   373,   374,   378,   379,   380,
     162,   155,   158,   155,   158,   155,   158,     1,     3,    68,
      73,   120,   418,   158,   381,   158,    25,    35,    62,   120,
     274,   430,   432,   433,   158,   155,   158,   158,   158,   120,
     155,   158,   158,   158,    78,   155,   222,   223,   124,   124,
     124,   155,   158,    40,    44,    46,    47,    48,    49,    52,
      61,    69,    72,    74,    75,    77,    92,    93,    99,   107,
     114,   116,   117,   137,   140,   141,   162,   170,   173,   181,
     182,   190,   203,   225,   227,   229,   230,   237,   239,   240,
     241,   244,   245,   316,   505,   659,   124,   120,   401,   124,
     124,    40,    45,    46,    54,    61,    63,    64,    72,    99,
     226,   658,   120,   124,   124,   185,   392,   394,   414,   646,
      49,    74,    75,   120,   155,   186,   245,   413,   415,   425,
     188,   413,   658,   155,   155,   124,    16,   657,   658,    18,
      19,   658,   124,   124,   124,   497,   155,    31,   215,   217,
     226,   228,   315,   158,   226,   228,   315,   226,   315,   226,
     231,   315,   120,   242,   242,   243,   158,   155,   396,   312,
     413,   314,   413,   315,   323,   338,   338,     0,   340,   341,
      34,    50,   343,   360,     1,   191,   337,   191,   337,   114,
     375,   395,   413,   109,   191,   109,   337,   191,    43,    47,
      52,    71,   169,   172,   187,   213,   408,   417,   422,   423,
     424,   438,   439,   443,   168,    94,   134,   142,   143,   145,
     153,   157,   159,   164,   180,   204,   205,   206,   207,   208,
     209,   489,   490,   250,   101,   160,   177,   200,   119,   148,
     161,   195,   202,   211,   138,   152,    51,   201,   103,   104,
     160,   177,   487,   194,   155,   494,   497,   192,   193,   156,
     509,   510,   505,   509,   505,   158,   509,   147,   158,   185,
     185,   185,   185,   376,   512,   376,    30,   656,   183,   197,
     183,   197,   167,   183,   659,   658,   170,   203,    48,   658,
     154,   120,    46,    48,    81,   108,   169,   657,   222,   223,
     224,   247,   615,   658,   658,   305,   139,   144,   114,   288,
     296,   378,   657,   393,   188,   393,    46,    64,   188,   567,
     568,   413,   188,   195,   658,   427,   428,   658,   285,   285,
     427,   120,   434,   120,   188,   382,   383,   155,   398,   413,
       1,   162,   656,   115,   162,   356,   656,   658,   120,   144,
     109,   188,   413,    30,   188,   657,   658,   658,   451,   452,
     658,   393,   188,   413,   413,   569,   658,   393,   155,   155,
     413,   188,   195,   658,   658,   144,   451,   185,   185,   123,
     109,   185,   158,   158,   158,   658,   155,   186,   187,   188,
      36,   528,   529,   530,   413,   413,     8,   176,    17,   413,
     215,    30,   414,   414,    40,    46,    61,    72,    99,   508,
     659,   188,   414,   414,   414,   646,   414,   508,   414,   232,
     231,   582,   583,   658,   191,   191,   414,   413,   394,   413,
     246,   411,   412,   312,   314,   414,   338,   191,   337,   191,
     337,     3,   344,   360,   390,     1,   344,   360,   390,    34,
     361,   390,   361,   390,   401,   337,   401,   414,   414,   120,
     169,   171,   171,   395,   414,   414,   469,   470,   472,   472,
     472,   472,   471,   472,   472,   472,    72,   473,   477,   477,
     476,   478,   478,   478,   478,   479,   479,   480,   480,   232,
      96,    96,    96,   495,   185,   413,   497,   497,   413,   510,
     146,   188,   414,   520,   151,   188,   520,   109,   188,   188,
     109,   109,   381,    30,   659,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,   363,   364,   365,    96,   139,
     144,   369,   370,   371,   658,   162,   162,   363,   656,   129,
     134,    56,    58,   102,   252,   265,   267,   278,   279,   280,
     282,   284,   616,   617,   618,   619,   620,   621,   628,   634,
     635,   247,    96,   300,   658,   144,   414,   120,   658,   658,
     134,   185,   185,   188,   188,   185,   109,   188,   109,   188,
     109,    37,    96,    98,   149,   429,   430,   551,   658,    57,
     218,   255,   419,   420,   658,    96,   109,   188,   392,   188,
     657,    98,    46,   657,   656,    98,   144,   551,   658,   414,
     433,   185,   188,   188,   188,   188,   109,   189,   149,   551,
     185,   188,   188,   155,   185,   393,   393,   185,   109,   188,
     109,   188,   144,   551,   414,   189,   414,   414,   413,   413,
     413,   658,   529,   530,   132,   198,   185,   185,   185,   133,
     191,    96,   219,   220,   234,    96,   219,   220,   234,   234,
     234,    96,    96,   238,   226,   232,   109,   236,   144,   191,
     188,   413,   185,   506,   588,   412,   234,   360,    34,    34,
     191,   337,   191,   115,   395,   658,   171,   414,   444,   445,
     120,   440,   441,   472,   155,   158,   260,   493,   512,   589,
     592,   593,   594,   595,   596,   600,   602,   604,   605,    48,
     154,   158,   212,   318,   319,   320,   321,   552,   554,   556,
     558,   572,   573,   574,   575,   652,   653,   654,   655,   658,
     552,   484,   557,   658,   484,   185,   186,   109,   188,   188,
     512,   150,   166,   150,   166,   139,   398,   381,   364,   134,
     554,   371,   414,   551,   656,   656,   130,   131,   656,   278,
     279,   280,   284,   658,   264,   275,   264,   275,    30,   287,
      98,   115,   158,   622,   625,   616,    40,    45,    54,    61,
      63,    72,    99,   226,   318,   319,   320,   385,   558,   652,
     228,   300,   309,   414,   658,    96,   300,   656,   155,   569,
     570,   658,   569,   570,   120,   428,   129,   552,   120,   414,
     149,   430,   149,    37,   149,   429,   430,   149,   551,   255,
      55,    60,    79,   120,   429,   435,   436,   437,   420,   551,
     552,   383,    96,   185,   199,   134,   355,   656,   162,   134,
      98,   355,   414,   144,   430,   155,   120,   414,   414,   149,
     102,   454,   455,   456,   458,   459,   102,   462,   463,   464,
     465,   393,   185,   185,   155,   569,   569,   414,   144,   191,
     414,   123,   188,   188,   188,    36,   530,   132,   198,     9,
      10,   105,   125,   127,   155,   196,   525,   527,   538,   539,
     542,   155,    30,   233,   235,   414,   414,   414,   233,   235,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   508,
     120,   414,   414,    49,    74,    75,   245,   395,   415,   425,
     246,   585,   586,   155,   211,   396,   414,   191,   115,   390,
     390,   390,   444,    97,   108,   118,   129,   446,   447,   448,
     449,   109,   658,   109,   413,   589,   596,   155,   286,   474,
     641,    98,   170,   253,   254,   256,   263,   273,   285,   590,
     591,   610,   611,   612,   613,   636,   639,   259,   261,   597,
     615,   268,   601,   637,   248,   249,   271,   606,   607,   158,
     158,   554,   158,   158,   158,   158,   158,   146,   177,   195,
     553,   146,   146,   414,   139,   398,   571,   370,   287,    30,
      98,   115,   158,   629,    30,   622,   553,   553,   495,   288,
     307,   551,   385,   228,   191,   392,   188,   188,   146,   188,
     188,   428,   149,   429,   658,   414,   149,   414,   129,   414,
     149,   430,   149,   414,   149,   120,   120,   414,   658,   437,
      79,   552,   395,   414,   656,   109,   355,   414,   144,   392,
     452,   414,   414,   115,   455,   456,   102,   187,   115,   456,
     459,   120,   466,   552,   102,   115,   463,   102,   115,   465,
     185,   392,   188,   188,   414,   414,   199,   462,   134,   196,
     527,     7,   393,   658,   196,   538,   393,   191,   234,   234,
     234,   234,    98,   238,   238,   583,   187,   158,   158,   158,
     187,   588,   586,   506,   656,   130,   131,   448,   449,   449,
     445,   108,   144,   442,   551,   441,   185,   188,   589,   603,
     251,   218,   255,   269,   276,   640,    98,   257,   258,   638,
     251,   593,   640,   476,   610,   594,   149,   283,   598,   599,
     638,   287,   609,    80,   608,   188,   195,   552,   555,   188,
     188,   188,   188,   188,   188,   188,    30,   138,   202,   631,
     632,   633,    30,   630,   631,   272,   626,   109,   623,   171,
     658,   258,   495,   185,   414,   149,   414,   149,   429,   414,
     149,   414,   414,   658,   658,   436,   414,   128,   128,    98,
     656,   414,   185,   187,   187,   414,   395,   414,   187,   187,
     658,   187,   211,   120,   466,   120,   187,   120,   466,   187,
     185,   115,   530,   658,   196,   185,   530,   658,   185,   414,
     414,   414,   414,   317,   414,   414,   414,   413,   413,   413,
     155,   587,   449,   656,   414,   144,   185,   478,    53,   131,
     476,   476,   270,   277,   287,   614,   614,   595,   155,   281,
      96,   188,   109,   188,   629,   629,   633,   109,   188,    30,
     627,   638,   624,   625,   188,   387,   388,   495,   120,   226,
     308,   288,   171,   414,   414,   149,   414,    55,   395,   414,
     355,   414,   395,    96,   395,   414,   552,   658,   187,   658,
     414,   658,   187,   395,   120,    95,   184,   531,   530,   658,
     198,   530,   414,   188,   188,   188,   413,   442,   414,   476,
     476,   200,   413,   552,   552,    96,    30,   266,   109,   109,
     449,   551,   658,   120,   226,   658,   387,   414,   120,   466,
      96,   187,    96,   658,     5,   135,   534,   535,   537,   539,
      29,   136,   532,   533,   536,   539,   198,   530,   198,   199,
     462,   185,   442,   476,   185,   552,   625,   388,   449,   306,
     658,   120,   226,   658,   187,   466,   395,   414,   466,   187,
      95,   135,   537,   184,   136,   536,   198,   115,   414,   306,
     658,   120,   395,   414,   187,   187,   120,   294,   306,   658,
     658,   307,   414,   307,   187,   495,   495,   200,   288,   658,
     226,   120,   658,   307,   495
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
     585,   586,   587,   588,   589
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   335,   336,   336,   336,   336,   337,   337,   337,   338,
     338,   338,   338,   339,   339,   340,   340,   340,   340,   340,
     340,   340,   340,   341,   341,   341,   341,   342,   343,   343,
     343,   344,   344,   344,   344,   344,   345,   345,   345,   345,
     345,   345,   345,   345,   346,   346,   347,   348,   349,   349,
     350,   350,   351,   351,   352,   352,   352,   352,   353,   353,
     353,   354,   354,   354,   354,   355,   355,   356,   356,   357,
     357,   357,   357,   358,   359,   359,   360,   360,   360,   361,
     361,   361,   361,   361,   361,   361,   361,   362,   362,   363,
     363,   364,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   366,   367,   368,   369,   369,   370,   370,   370,
     371,   372,   372,   372,   373,   373,   373,   373,   374,   374,
     375,   375,   375,   375,   376,   376,   377,   377,   378,   378,
     379,   379,   380,   380,   381,   381,   381,   381,   382,   382,
     383,   383,   384,   384,   384,   384,   385,   385,   385,   385,
     386,   386,   387,   387,   388,   388,   388,   388,   389,   389,
     389,   389,   390,   391,   391,   391,   392,   392,   392,   393,
     393,   394,   394,   394,   395,   395,   395,   395,   395,   395,
     395,   395,   395,   395,   395,   395,   396,   396,   397,   398,
     399,   400,   400,   400,   401,   401,   401,   401,   402,   403,
     404,   405,   406,   406,   407,   408,   409,   410,   411,   411,
     412,   413,   413,   413,   414,   414,   414,   414,   414,   414,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     415,   415,   416,   417,   418,   418,   419,   419,   419,   420,
     420,   421,   421,   422,   423,   423,   423,   424,   424,   424,
     424,   424,   425,   425,   426,   426,   426,   427,   427,   427,
     428,   428,   428,   428,   428,   428,   428,   428,   428,   428,
     428,   428,   429,   430,   431,   432,   432,   433,   433,   433,
     433,   434,   434,   435,   435,   435,   436,   436,   436,   437,
     437,   437,   438,   439,   440,   440,   441,   441,   441,   441,
     441,   441,   442,   443,   443,   444,   444,   445,   445,   446,
     446,   446,   446,   446,   446,   446,   447,   447,   448,   448,
     449,   450,   450,   451,   451,   452,   452,   453,   454,   454,
     455,   456,   456,   457,   458,   458,   459,   460,   460,   461,
     461,   462,   462,   463,   463,   464,   464,   465,   465,   466,
     466,   467,   468,   468,   469,   469,   470,   470,   470,   470,
     470,   471,   470,   470,   470,   470,   472,   472,   473,   473,
     474,   474,   475,   475,   476,   476,   476,   477,   477,   477,
     477,   477,   478,   478,   478,   479,   479,   479,   480,   480,
     481,   481,   482,   482,   483,   483,   484,   484,   485,   485,
     486,   486,   486,   486,   487,   487,   487,   488,   488,   489,
     489,   489,   489,   489,   489,   490,   490,   490,   491,   491,
     491,   491,   492,   492,   493,   493,   494,   494,   494,   495,
     495,   495,   495,   496,   497,   497,   497,   498,   498,   499,
     499,   499,   499,   500,   500,   501,   501,   501,   501,   501,
     501,   501,   502,   502,   503,   503,   504,   504,   504,   504,
     504,   505,   505,   506,   506,   507,   507,   507,   507,   508,
     508,   508,   508,   509,   509,   510,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   511,
     512,   512,   513,   513,   513,   514,   515,   515,   516,   517,
     518,   519,   519,   520,   520,   520,   520,   521,   521,   522,
     523,   524,   524,   525,   525,   525,   526,   526,   526,   526,
     526,   526,   527,   527,   528,   528,   529,   530,   530,   531,
     531,   532,   532,   533,   533,   533,   533,   534,   534,   535,
     535,   535,   535,   536,   536,   537,   537,   538,   538,   538,
     538,   539,   539,   539,   539,   540,   540,   541,   541,   542,
     543,   543,   543,   543,   543,   543,   543,   544,   545,   545,
     546,   546,   547,   548,   549,   549,   550,   550,   551,   552,
     552,   552,   553,   553,   553,   554,   554,   554,   554,   554,
     554,   554,   555,   555,   556,   557,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   559,   560,   560,   560,
     561,   562,   563,   564,   564,   564,   565,   565,   565,   565,
     565,   566,   567,   567,   567,   567,   567,   567,   567,   568,
     569,   570,   571,   572,   572,   573,   574,   574,   575,   576,
     576,   576,   577,   577,   577,   577,   577,   577,   577,   577,
     577,   577,   578,   578,   579,   579,   580,   581,   582,   582,
     583,   584,   585,   585,   586,   587,   588,   588,   589,   590,
     590,   591,   591,   592,   592,   593,   593,   594,   594,   595,
     595,   596,   597,   597,   598,   598,   599,   600,   600,   600,
     601,   601,   602,   603,   603,   604,   605,   605,   606,   606,
     607,   607,   607,   608,   608,   609,   609,   610,   610,   610,
     610,   610,   611,   612,   613,   614,   614,   614,   615,   615,
     616,   616,   616,   616,   616,   616,   616,   616,   617,   617,
     617,   617,   618,   618,   619,   620,   620,   621,   621,   621,
     622,   622,   623,   623,   624,   624,   625,   626,   626,   627,
     627,   628,   628,   628,   629,   629,   630,   630,   631,   631,
     632,   632,   633,   633,   634,   635,   635,   636,   636,   636,
     637,   638,   638,   638,   638,   639,   639,   640,   640,   641,
     642,   642,   643,   643,   644,   644,   645,   646,   646,   647,
     647,   647,   648,   649,   650,   651,   652,   652,   652,   653,
     654,   655,   656,   657,   657,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   660
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
       2,     3,     4,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     1,     4,
       4,     3,     4,     1,     3,     1,     3,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     4,     8,     5,     9,
       9,    10,     1,     2,     1,     2,     6,     0,     1,     3,
       3,     0,     1,     1,     1,     2,     2,     0,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     2,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     7,
       3,     7,     4,     4,     3,     7,     3,     7,     2,     1,
       2,     3,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     4,
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
       2,     3,     2,     3,     2,     3,     3,     3,     5,     5,
       5,     8,     5,     3,     5,     7,     1,     1,     1,     3,
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
  "\"'URI'\"", "\"'NCName'\"", "\"'declare'\"", "\"'module'\"",
  "\"'<blank>'\"", "\"'allowing'\"", "\"'base-uri'\"",
  "\"'boundary-space'\"", "\"'comment'\"", "\"'construction'\"",
  "\"'copy-namespaces'\"", "\"'count'\"", "\"'document'\"",
  "\"'document-node'\"", "\"'element'\"", "\"'for'\"", "\"'function'\"",
  "\"'if'\"", "\"'import'\"", "\"'instance'\"", "\"'let'\"", "\"'most'\"",
  "\"'namespace-node'\"", "\"'next'\"", "\"'no'\"", "\"'only'\"",
  "\"'option'\"", "\"'ordering'\"", "\"'previous'\"",
  "\"'processing-instruction'\"", "\"'schema'\"", "\"'schema-attribute'\"",
  "\"'schema-element'\"", "\"'sequential'\"", "\"'set'\"", "\"'simple'\"",
  "\"'sliding'\"", "\"'some'\"", "\"'space'\"", "\"'stable'\"",
  "\"'text'\"", "\"'tumbling'\"", "\"'switch'\"", "\"'typeswitch'\"",
  "\"'updating'\"", "\"'validate'\"", "\"'type'\"", "\"'when'\"",
  "\"'word'\"", "\"'decimal-format'\"", "\"'decimal-separator'\"",
  "\"'grouping-separator'\"", "\"'infinity'\"", "\"'minus-sign'\"",
  "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"", "\"'zero-digit'\"",
  "\"'digit'\"", "\"'pattern-separator'\"", "\"'ancestor'\"",
  "\"'ancestor-or-self'\"", "\"'and'\"", "\"'''\"", "\"'as'\"",
  "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'@'\"", "\"'||'\"",
  "\"'case'\"", "\"'castable'\"", "\"'cast'\"", "\"'CDATA[['\"",
  "\"']]'\"", "\"'child'\"", "\"'collation'\"", "\"','\"", "\"'(:'\"",
  "\"':)'\"", "\"'DECIMAL'\"", "\"'context'\"", "\"'variable'\"",
  "\"'default'\"", "\"'descendant'\"", "\"'descendant-or-self'\"",
  "\"'descending'\"", "\"'div'\"", "\"'$'\"", "\"'.'\"", "\"'..'\"",
  "\"':'\"", "\"'::'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"",
  "\"'else'\"", "\"'empty'\"", "\"'greatest'\"", "\"'least'\"", "\"'/>'\"",
  "\"'encoding'\"", "\"'='\"", "\"''''\"", "\"'\\\"\\\"'\"", "\"'every'\"",
  "\"'except'\"", "\"'external'\"", "\"'following'\"",
  "\"'following-sibling'\"", "\"'follows'\"", "\"'>='\"", "\"':='\"",
  "\"'>'\"", "\"'?'\"", "\"'#'\"", "\"'idiv'\"", "\"'in'\"",
  "\"'inherit'\"", "\"'INTEGER'\"", "\"'intersect'\"", "\"'is'\"",
  "\"'item'\"", "\"'{'\"", "\"'['\"", "\"'<='\"", "\"'('\"", "\"'<'\"",
  "\"'-'\"", "\"'mod'\"", "\"'namespace'\"", "\"'nan'\"", "\"'!='\"",
  "\"'nodecomp'\"", "\"'<no inherit>'\"", "\"'<no preserve>'\"",
  "\"'or'\"", "\"'order'\"", "\"'ordered'\"", "\"'by'\"", "\"'group'\"",
  "\"'parent'\"", "\"'%'\"", "\"'<?'\"", "\"'?>'\"", "\"'+'\"", "\"'(#'\"",
  "\"'#)'\"", "\"'<<'\"", "\"'preceding'\"", "\"'preceding-sibling'\"",
  "\"'preserve'\"", "\"'\\\"'\"", "\"'}'\"", "\"']'\"", "\"'return'\"",
  "\"')'\"", "\"'satisfies'\"", "\"'self'\"", "\"';'\"", "\"'/'\"",
  "\"'//'\"", "\"'!'\"", "\"'*'\"", "\"'</ (start tag end)'\"",
  "\"'strip'\"", "\"'> (tag end)'\"", "\"'then'\"", "\"'to'\"",
  "\"'treat'\"", "\"'union'\"", "\"'unordered'\"", "\"'eq'\"", "\"'ge'\"",
  "\"'gt'\"", "\"'le'\"", "\"'lt'\"", "\"'ne'\"", "\"'VALUECOMP'\"",
  "\"'|'\"", "\"'empty-sequence'\"", "\"'where'\"", "\"'<!--'\"",
  "\"'-->'\"", "\"'xquery'\"", "\"'version'\"", "\"'start'\"",
  "\"'after'\"", "\"'before'\"", "\"'revalidation'\"", "\"'strict'\"",
  "\"'lax'\"", "\"'skip'\"", "\"'delete'\"", "\"'node'\"", "\"'insert'\"",
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
  "SimpleType", "KindTest", "AnyKindTest", "DocumentTest", "NamespaceTest",
  "TextTest", "CommentTest", "PITest", "AttributeTest",
  "SchemaAttributeTest", "ElementTest", "SchemaElementTest", "TypeName",
  "TypeName_WITH_HOOK", "StringLiteral", "FunctionTest", "AnyFunctionTest",
  "TypedFunctionTest", "ParenthesizedItemType", "RevalidationDecl",
  "InsertExpr", "DeleteExpr", "ReplaceExpr", "RenameExpr", "TransformExpr",
  "VarNameList", "VarNameDecl", "TryExpr", "CatchListExpr", "CatchExpr",
  "BracedExpr", "NameTestList", "FTSelection", "opt_FTPosFilter_list",
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
  "URI_LITERAL", "NCNAME", "QNAME", "FUNCTION_NAME", "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       336,     0,    -1,   338,    -1,   322,   338,    -1,   323,   338,
      -1,   322,   323,   338,    -1,     1,    -1,     1,     3,    -1,
     337,     1,    -1,   340,    -1,   339,   340,    -1,   341,    -1,
     339,   341,    -1,   216,   217,    30,   191,    -1,   216,   217,
      30,   133,    30,   191,    -1,   343,   191,   390,    -1,   360,
     191,   390,    -1,   343,   191,   360,   191,   390,    -1,   390,
      -1,   343,   337,   390,    -1,   360,   337,   390,    -1,   343,
     191,   360,   337,   390,    -1,   343,   337,   360,   191,   390,
      -1,   342,    -1,   342,   343,   191,    -1,   342,   360,   191,
      -1,   342,   343,   191,   360,   191,    -1,    35,   162,   657,
     134,   656,   191,    -1,   344,    -1,   343,   191,   344,    -1,
     343,   337,   344,    -1,   345,    -1,   353,    -1,   358,    -1,
     359,    -1,   367,    -1,   346,    -1,   347,    -1,   348,    -1,
     349,    -1,   350,    -1,   351,    -1,   352,    -1,   576,    -1,
      34,    39,   183,    -1,    34,    39,   197,    -1,    34,   115,
     108,   656,    -1,    34,    38,   656,    -1,    34,    41,   183,
      -1,    34,    41,   197,    -1,    34,    59,   170,    -1,    34,
      59,   203,    -1,    34,   115,   169,   129,   130,    -1,    34,
     115,   169,   129,   131,    -1,    34,    42,   183,   109,   150,
      -1,    34,    42,   183,   109,   166,    -1,    34,    42,   167,
     109,   150,    -1,    34,    42,   167,   109,   166,    -1,   354,
      -1,   357,    -1,    50,    25,     1,    -1,    50,    62,   656,
      -1,    50,    62,   356,   656,    -1,    50,    62,   656,    98,
     355,    -1,    50,    62,   356,   656,    98,   355,    -1,   656,
      -1,   355,   109,   656,    -1,   162,   657,   134,    -1,   115,
      46,   162,    -1,    50,    35,   656,    -1,    50,    35,   162,
     657,   134,   656,    -1,    50,    35,   656,    98,   355,    -1,
      50,    35,   162,   657,   134,   656,    98,   355,    -1,    34,
     162,   657,   134,   656,    -1,    34,   115,    46,   162,   656,
      -1,    34,   115,    48,   162,   656,    -1,   361,    -1,   360,
     191,   361,    -1,   360,   337,   361,    -1,   362,    -1,   366,
      -1,   368,    -1,   372,    -1,   377,    -1,   384,    -1,   386,
      -1,   389,    -1,    34,   115,    81,   363,    -1,    34,    81,
     658,   363,    -1,   364,    -1,   363,   364,    -1,   365,   134,
     571,    -1,    82,    -1,    90,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    91,    -1,    87,    -1,    88,    -1,
      89,    -1,    34,    58,   658,    30,    -1,    34,   262,   615,
      -1,    34,   113,   154,   369,    -1,    96,   554,   370,    -1,
     370,    -1,   371,    -1,   139,    -1,   139,   371,    -1,   144,
     414,    -1,    34,   373,   144,   414,    -1,    34,   373,   139,
      -1,    34,   373,   139,   144,   414,    -1,   114,   120,   658,
      -1,   114,   120,   658,   551,    -1,   374,   114,   120,   658,
      -1,   374,   114,   120,   658,   551,    -1,   375,    -1,   374,
     375,    -1,    27,    -1,    27,   158,   376,   188,    -1,    28,
      -1,    28,   158,   376,   188,    -1,   512,    -1,   376,   109,
     512,    -1,    34,   378,    -1,    34,   374,   378,    -1,   379,
      -1,   380,    -1,    48,   659,   381,   398,    -1,    48,   659,
     381,   139,    -1,    76,    48,   659,   381,   398,    -1,    76,
      48,   659,   381,   139,    -1,   158,   188,    -1,   158,   382,
     188,    -1,   158,   188,    96,   552,    -1,   158,   382,   188,
      96,   552,    -1,   383,    -1,   382,   109,   383,    -1,   120,
     658,    -1,   120,   658,   551,    -1,    34,   288,   658,    -1,
      34,   288,   658,    96,   385,    -1,    34,   374,   288,   658,
      -1,    34,   374,   288,   658,    96,   385,    -1,   558,    -1,
     558,   553,    -1,   652,    -1,   652,   553,    -1,    34,   296,
     658,   300,   228,   495,   171,   387,    -1,    34,   374,   296,
     658,   300,   228,   495,   171,   387,    -1,   388,    -1,   387,
     109,   388,    -1,   495,    -1,   495,   551,    -1,   495,   449,
      -1,   495,   551,   449,    -1,    34,   304,   305,   658,   300,
     288,   658,   120,   658,   306,   414,    -1,    34,   304,   305,
     658,   300,   288,   658,   226,   120,   658,   306,   294,   307,
     495,    -1,    34,   304,   305,   658,   300,   288,   658,   308,
     226,   120,   658,   306,   414,    -1,    34,   304,   305,   658,
     309,   307,   258,   288,   658,   226,   120,   658,   307,   495,
     200,   288,   658,   226,   120,   658,   307,   495,    -1,   391,
      -1,   393,    -1,   394,    -1,    -1,   393,    -1,   394,    -1,
      -1,   413,    -1,   394,   413,    -1,   395,    -1,   394,   395,
      -1,   394,   413,   337,   395,    -1,   396,    -1,   399,    -1,
     402,    -1,   403,    -1,   404,    -1,   405,    -1,   406,    -1,
     407,    -1,   409,    -1,   461,    -1,   457,    -1,   410,    -1,
     155,   394,   185,    -1,   155,   185,    -1,   155,   392,   185,
      -1,   155,   392,   185,    -1,   400,   191,    -1,   400,   109,
     401,    -1,   114,   401,    -1,   374,   114,   401,    -1,   120,
     658,    -1,   120,   658,   551,    -1,   120,   658,   144,   414,
      -1,   120,   658,   551,   144,   414,    -1,   120,   658,   144,
     414,   191,    -1,   415,   191,    -1,   241,   243,   414,   191,
      -1,   244,   158,   413,   188,   395,    -1,   239,   242,   191,
      -1,   240,   242,   191,    -1,   425,   408,    -1,   187,   395,
      -1,    49,   158,   413,   188,   199,   395,   128,   395,    -1,
     245,   396,   411,    -1,   412,    -1,   411,   412,    -1,   246,
     588,   396,    -1,   414,    -1,   413,   109,   414,    -1,   413,
     337,   414,    -1,   416,    -1,   453,    -1,   460,    -1,   467,
      -1,   584,    -1,   415,    -1,   468,    -1,   450,    -1,   577,
      -1,   578,    -1,   580,    -1,   579,    -1,   581,    -1,   649,
      -1,   647,    -1,   650,    -1,   651,    -1,   648,    -1,   425,
     417,    -1,   187,   414,    -1,    68,   285,    -1,    73,   285,
      -1,   218,    -1,   255,    -1,    57,   255,    -1,   419,   435,
      79,   414,    -1,   419,    79,   414,    -1,    47,   418,   434,
     420,   420,    -1,    47,   418,   434,   420,    -1,    43,   120,
     658,    -1,   426,    -1,   431,    -1,   421,    -1,   423,    -1,
     438,    -1,   443,    -1,   439,    -1,   422,    -1,   423,    -1,
     425,   424,    -1,    47,   120,   427,    -1,    47,     1,   427,
      -1,    47,     3,    -1,   428,    -1,   427,   109,   120,   428,
      -1,   427,   109,   428,    -1,   658,   149,   414,    -1,   658,
      37,   129,   149,   414,    -1,   658,   551,   149,   414,    -1,
     658,   551,    37,   129,   149,   414,    -1,   658,   429,   149,
     414,    -1,   658,    37,   129,   429,   149,   414,    -1,   658,
     551,   429,   149,   414,    -1,   658,   551,    37,   129,   429,
     149,   414,    -1,   658,   430,   149,   414,    -1,   658,   551,
     430,   149,   414,    -1,   658,   429,   430,   149,   414,    -1,
     658,   551,   429,   430,   149,   414,    -1,    98,   120,   658,
      -1,   274,   120,   658,    -1,    52,   432,    -1,   433,    -1,
     432,   109,   433,    -1,   120,   658,   144,   414,    -1,   120,
     658,   551,   144,   414,    -1,   430,   144,   414,    -1,   120,
     658,   551,   430,   144,   414,    -1,   120,   658,   149,   414,
      -1,   120,   658,   551,   149,   414,    -1,   436,    -1,   120,
     658,    -1,   120,   658,   436,    -1,   429,    -1,   429,   437,
      -1,   437,    -1,    60,   120,   658,    55,   120,   658,    -1,
      55,   120,   658,    -1,    60,   120,   658,    -1,   213,   414,
      -1,   172,   171,   440,    -1,   441,    -1,   440,   109,   441,
      -1,   120,   658,    -1,   120,   658,   144,   414,    -1,   120,
     658,   551,   144,   414,    -1,   120,   658,   551,   144,   414,
     442,    -1,   120,   658,   144,   414,   442,    -1,   120,   658,
     442,    -1,   108,   656,    -1,   169,   171,   444,    -1,    71,
     169,   171,   444,    -1,   445,    -1,   444,   109,   445,    -1,
     414,    -1,   414,   446,    -1,   447,    -1,   448,    -1,   449,
      -1,   447,   448,    -1,   447,   449,    -1,   448,   449,    -1,
     447,   448,   449,    -1,    97,    -1,   118,    -1,   129,   130,
      -1,   129,   131,    -1,   108,   656,    -1,    69,   120,   451,
     189,   414,    -1,   137,   120,   451,   189,   414,    -1,   452,
      -1,   451,   109,   120,   452,    -1,   658,   149,   414,    -1,
     658,   551,   149,   414,    -1,    74,   158,   413,   188,   454,
     115,   187,   414,    -1,   455,    -1,   454,   455,    -1,   456,
     187,   414,    -1,   102,   414,    -1,   456,   102,   414,    -1,
      74,   158,   413,   188,   458,   115,   187,   395,    -1,   459,
      -1,   458,   459,    -1,   456,   187,   395,    -1,    75,   158,
     413,   188,   462,   115,   187,   414,    -1,    75,   158,   413,
     188,   462,   115,   120,   658,   187,   414,    -1,    75,   158,
     413,   188,   464,   115,   187,   395,    -1,    75,   158,   413,
     188,   462,   115,   120,   658,   187,   395,    -1,   463,    -1,
     462,   463,    -1,   102,   466,   187,   414,    -1,   102,   120,
     658,    96,   466,   187,   414,    -1,   465,    -1,   464,   465,
      -1,   102,   466,   187,   395,    -1,   102,   120,   658,    96,
     466,   187,   395,    -1,   552,    -1,   466,   211,   552,    -1,
      49,   158,   413,   188,   199,   414,   128,   414,    -1,   469,
      -1,   468,   168,   469,    -1,   470,    -1,   469,    94,   470,
      -1,   472,    -1,   472,   489,   472,    -1,   472,   490,   472,
      -1,   472,   134,   472,    -1,   472,   164,   472,    -1,    -1,
     472,   159,   471,   472,    -1,   472,   157,   472,    -1,   472,
     145,   472,    -1,   472,   143,   472,    -1,   473,    -1,   473,
     250,    72,   589,   474,    -1,   475,    -1,   475,   101,   473,
      -1,    -1,   641,    -1,   476,    -1,   476,   200,   476,    -1,
     477,    -1,   476,   177,   477,    -1,   476,   160,   477,    -1,
     478,    -1,   477,   195,   478,    -1,   477,   119,   478,    -1,
     477,   148,   478,    -1,   477,   161,   478,    -1,   479,    -1,
     478,   202,   479,    -1,   478,   211,   479,    -1,   480,    -1,
     479,   152,   480,    -1,   479,   138,   480,    -1,   481,    -1,
     481,    51,   232,   552,    -1,   482,    -1,   482,   201,    96,
     552,    -1,   483,    -1,   483,   103,    96,   484,    -1,   485,
      -1,   485,   104,    96,   484,    -1,   557,    -1,   557,   146,
      -1,   487,    -1,   486,   487,    -1,   177,    -1,   160,    -1,
     486,   177,    -1,   486,   160,    -1,   491,    -1,   488,    -1,
     492,    -1,   495,    -1,   488,   194,   495,    -1,   204,    -1,
     209,    -1,   208,    -1,   207,    -1,   206,    -1,   205,    -1,
     153,    -1,   180,    -1,   142,    -1,    77,   155,   393,   185,
      -1,    77,   223,   155,   393,   185,    -1,    77,   222,   155,
     393,   185,    -1,    77,    78,   569,   155,   393,   185,    -1,
     493,   155,   185,    -1,   493,   155,   413,   185,    -1,   494,
      -1,   493,   494,    -1,   178,   658,    17,    -1,   178,    18,
      -1,   178,    19,    -1,   496,    -1,   496,   497,    -1,   193,
     497,    -1,   497,    -1,   192,    -1,   498,    -1,   498,   192,
     497,    -1,   498,   193,   497,    -1,   499,    -1,   508,    -1,
     500,    -1,   500,   509,    -1,   503,    -1,   503,   509,    -1,
     501,   505,    -1,   502,    -1,   107,   124,    -1,   116,   124,
      -1,    99,   124,    -1,   190,   124,    -1,   117,   124,    -1,
     141,   124,    -1,   140,   124,    -1,   505,    -1,   100,   505,
      -1,   504,   505,    -1,   122,    -1,   173,   124,    -1,    92,
     124,    -1,   182,   124,    -1,   181,   124,    -1,    93,   124,
      -1,   558,    -1,   506,    -1,   658,    -1,   507,    -1,   195,
      -1,    11,    -1,    12,    -1,    20,    -1,   511,    -1,   508,
     509,    -1,   508,   158,   188,    -1,   508,   158,   520,   188,
      -1,   510,    -1,   509,   510,    -1,   156,   413,   186,    -1,
     512,    -1,   514,    -1,   515,    -1,   516,    -1,   519,    -1,
     524,    -1,   517,    -1,   518,    -1,   521,    -1,   397,    -1,
     645,    -1,   642,    -1,   643,    -1,   644,    -1,   513,    -1,
     571,    -1,   112,    -1,   151,    -1,   126,    -1,   120,   658,
      -1,   158,   188,    -1,   158,   413,   188,    -1,   121,    -1,
     170,   155,   413,   185,    -1,   203,   155,   413,   185,    -1,
     659,   158,   188,    -1,   659,   158,   520,   188,    -1,   146,
      -1,   520,   109,   146,    -1,   414,    -1,   520,   109,   414,
      -1,   522,    -1,   523,    -1,   659,   147,   151,    -1,    48,
     381,   398,    -1,   525,    -1,   543,    -1,   526,    -1,   540,
      -1,   541,    -1,   159,   658,   530,   132,    -1,   159,   658,
     530,   198,   196,   658,   530,   198,    -1,   159,   658,   528,
     530,   132,    -1,   159,   658,   528,   530,   198,   196,   658,
     530,   198,    -1,   159,   658,   530,   198,   527,   196,   658,
     530,   198,    -1,   159,   658,   528,   530,   198,   527,   196,
     658,   530,   198,    -1,   538,    -1,   527,   538,    -1,   529,
      -1,   528,   529,    -1,    36,   658,   530,   134,   530,   531,
      -1,    -1,    36,    -1,   184,   532,   184,    -1,    95,   534,
      95,    -1,    -1,   533,    -1,   136,    -1,   536,    -1,   533,
     136,    -1,   533,   536,    -1,    -1,   535,    -1,   135,    -1,
     537,    -1,   535,   135,    -1,   535,   537,    -1,    29,    -1,
     539,    -1,     5,    -1,   539,    -1,   525,    -1,    10,    -1,
     542,    -1,   539,    -1,     9,    -1,   125,    -1,   127,    -1,
     155,   393,   185,    -1,   214,    31,   215,    -1,   214,   215,
      -1,   175,   657,   176,    -1,   175,   657,     8,    -1,   105,
       7,    -1,   544,    -1,   545,    -1,   546,    -1,   547,    -1,
     548,    -1,   549,    -1,   550,    -1,    44,   155,   393,   185,
      -1,    21,   392,   185,    -1,    46,   155,   413,   185,   155,
     392,   185,    -1,    22,   392,   185,    -1,    99,   155,   413,
     185,   155,   392,   185,    -1,    72,   155,   393,   185,    -1,
      40,   155,   393,   185,    -1,    23,   392,   185,    -1,    61,
     155,   413,   185,   155,   392,   185,    -1,    24,   393,   185,
      -1,   162,   155,   413,   185,   155,   393,   185,    -1,    96,
     552,    -1,   554,    -1,   554,   553,    -1,   212,   158,   188,
      -1,   146,    -1,   195,    -1,   177,    -1,   556,    -1,   558,
      -1,   154,   158,   188,    -1,   321,   158,   188,    -1,   572,
      -1,   575,    -1,   652,    -1,   552,    -1,   555,   109,   552,
      -1,   658,    -1,   658,    -1,   560,    -1,   567,    -1,   565,
      -1,   568,    -1,   566,    -1,   564,    -1,   563,    -1,   562,
      -1,   561,    -1,   559,    -1,   226,   158,   188,    -1,    45,
     158,   188,    -1,    45,   158,   567,   188,    -1,    45,   158,
     568,   188,    -1,    54,   158,   188,    -1,    72,   158,   188,
      -1,    40,   158,   188,    -1,    61,   158,   188,    -1,    61,
     158,   657,   188,    -1,    61,   158,    30,   188,    -1,    99,
     158,   188,    -1,    99,   158,   658,   188,    -1,    99,   158,
     658,   109,   569,   188,    -1,    99,   158,   195,   188,    -1,
      99,   158,   195,   109,   569,   188,    -1,    63,   158,   658,
     188,    -1,    46,   158,   188,    -1,    46,   158,   658,   188,
      -1,    46,   158,   658,   109,   569,   188,    -1,    46,   158,
     658,   109,   570,   188,    -1,    46,   158,   195,   188,    -1,
      46,   158,   195,   109,   569,   188,    -1,    46,   158,   195,
     109,   570,   188,    -1,    64,   158,   658,   188,    -1,   658,
      -1,   658,   146,    -1,    30,    -1,   573,    -1,   574,    -1,
      48,   158,   195,   188,    -1,    48,   158,   188,    96,   552,
      -1,    48,   158,   555,   188,    96,   552,    -1,   158,   554,
     188,    -1,    34,   221,   222,    -1,    34,   221,   223,    -1,
      34,   221,   224,    -1,   227,   226,   414,   234,   414,    -1,
     227,   226,   414,    96,   233,   234,   414,    -1,   227,   226,
     414,    96,   235,   234,   414,    -1,   227,   226,   414,   219,
     414,    -1,   227,   226,   414,   220,   414,    -1,   227,   228,
     414,   234,   414,    -1,   227,   228,   414,    96,   233,   234,
     414,    -1,   227,   228,   414,    96,   235,   234,   414,    -1,
     227,   228,   414,   219,   414,    -1,   227,   228,   414,   220,
     414,    -1,   225,   226,   414,    -1,   225,   228,   414,    -1,
     230,   226,   414,   238,   414,    -1,   230,   231,   232,   226,
     414,   238,   414,    -1,   229,   226,   414,    96,   414,    -1,
     237,   120,   582,   236,   414,   187,   414,    -1,   583,    -1,
     582,   109,   120,   583,    -1,   658,   144,   414,    -1,   245,
     155,   413,   185,   585,    -1,   586,    -1,   585,   586,    -1,
     246,   588,   587,    -1,   155,   413,   185,    -1,   506,    -1,
     588,   211,   506,    -1,   592,   590,    -1,    -1,   591,    -1,
     610,    -1,   591,   610,    -1,   593,    -1,   592,   263,   593,
      -1,   594,    -1,   593,   259,   594,    -1,   595,    -1,   594,
     261,   149,   595,    -1,   596,    -1,   260,   596,    -1,   600,
     597,   598,    -1,    -1,   615,    -1,    -1,   599,    -1,   283,
     155,   413,   185,    -1,   604,   601,    -1,   158,   589,   188,
      -1,   602,    -1,    -1,   637,    -1,   493,   155,   603,   185,
      -1,    -1,   589,    -1,   605,   606,    -1,   512,    -1,   155,
     413,   185,    -1,    -1,   607,    -1,   249,   608,    -1,   248,
     609,    -1,   271,    -1,    -1,    80,    -1,    -1,   287,    -1,
     611,    -1,   612,    -1,   613,    -1,   639,    -1,   636,    -1,
     170,    -1,   285,   476,   614,    -1,   254,   638,   614,    -1,
     287,    -1,   277,    -1,   270,    -1,   247,   616,    -1,   615,
     247,   616,    -1,   617,    -1,   618,    -1,   619,    -1,   634,
      -1,   620,    -1,   628,    -1,   621,    -1,   635,    -1,   102,
     275,    -1,   102,   264,    -1,   267,    -1,   282,    -1,   252,
     275,    -1,   252,   264,    -1,    58,   658,    30,    -1,   278,
      -1,    56,   278,    -1,   280,   622,    -1,   280,   158,   622,
     623,   188,    -1,    56,   280,    -1,   625,    -1,   115,    -1,
      -1,   109,   624,    -1,   625,    -1,   624,   109,   625,    -1,
      98,    30,   626,   627,    -1,    -1,   272,    30,    -1,    -1,
     638,   266,    -1,   279,   287,   629,   631,    -1,   279,   287,
     115,   631,    -1,    56,   279,   287,    -1,    98,    30,    -1,
     158,   630,   188,    -1,    30,    -1,   630,   109,    30,    -1,
      -1,   632,    -1,   633,    -1,   632,   633,    -1,   202,   629,
      -1,   138,   629,    -1,   265,    30,    -1,   284,    -1,    56,
     284,    -1,    98,   218,    -1,    98,   255,    -1,   256,   251,
      -1,   268,   638,   281,    -1,   257,   476,    -1,    98,   131,
     476,    -1,    98,    53,   476,    -1,   258,   476,   200,   476,
      -1,   273,   640,    -1,   253,   640,    -1,   276,    -1,   269,
      -1,   286,   251,   478,    -1,   156,   186,    -1,   156,   413,
     186,    -1,   311,   312,    -1,   311,   413,   312,    -1,   313,
     314,    -1,   313,   413,   314,    -1,   155,   646,   185,    -1,
     414,   123,   414,    -1,   646,   109,   414,   123,   414,    -1,
     227,   315,   414,   234,   414,    -1,   227,   315,   646,   234,
     414,    -1,   227,   315,   414,   234,   414,    98,   317,   414,
      -1,   316,   315,   414,   234,   414,    -1,   225,   315,   508,
      -1,   229,   315,   508,    96,   414,    -1,   230,   315,   231,
     232,   508,   238,   414,    -1,   653,    -1,   654,    -1,   655,
      -1,   320,   158,   188,    -1,   318,   158,   188,    -1,   319,
     158,   188,    -1,    30,    -1,    16,    -1,   658,    -1,   659,
      -1,    99,    -1,    40,    -1,    45,    -1,    54,    -1,    46,
      -1,   154,    -1,    49,    -1,   226,    -1,    61,    -1,    63,
      -1,    64,    -1,    72,    -1,    75,    -1,    74,    -1,   212,
      -1,   244,    -1,   660,    -1,    25,    -1,   216,    -1,   129,
      -1,    39,    -1,   262,    -1,    38,    -1,   223,    -1,   222,
      -1,   148,    -1,    44,    -1,   260,    -1,   261,    -1,   275,
      -1,   264,    -1,   252,    -1,   286,    -1,   278,    -1,   280,
      -1,   279,    -1,   284,    -1,   256,    -1,   251,    -1,    80,
      -1,   218,    -1,   255,    -1,    53,    -1,   224,    -1,   237,
      -1,   303,    -1,   231,    -1,   204,    -1,   209,    -1,   208,
      -1,   207,    -1,   206,    -1,   205,    -1,    98,    -1,   113,
      -1,   114,    -1,   187,    -1,    47,    -1,    37,    -1,    68,
      -1,    73,    -1,    60,    -1,    55,    -1,    57,    -1,    79,
      -1,    43,    -1,   149,    -1,    52,    -1,   213,    -1,   171,
      -1,   172,    -1,   169,    -1,    71,    -1,    97,    -1,   118,
      -1,   130,    -1,   131,    -1,   108,    -1,    69,    -1,   137,
      -1,   189,    -1,   102,    -1,    96,    -1,   199,    -1,   128,
      -1,   168,    -1,    94,    -1,    51,    -1,   232,    -1,   103,
      -1,   200,    -1,   119,    -1,   161,    -1,   202,    -1,   152,
      -1,   138,    -1,    77,    -1,    78,    -1,   104,    -1,   201,
      -1,   153,    -1,   183,    -1,   197,    -1,   162,    -1,   139,
      -1,   133,    -1,   167,    -1,   150,    -1,   166,    -1,    34,
      -1,    41,    -1,    59,    -1,   115,    -1,    42,    -1,    58,
      -1,   217,    -1,    50,    -1,    62,    -1,    35,    -1,    48,
      -1,   274,    -1,   250,    -1,   283,    -1,   285,    -1,   254,
      -1,   268,    -1,   281,    -1,   273,    -1,   253,    -1,   267,
      -1,   282,    -1,   272,    -1,   266,    -1,   265,    -1,   249,
      -1,   248,    -1,   257,    -1,   258,    -1,   287,    -1,   277,
      -1,   276,    -1,   271,    -1,   269,    -1,   270,    -1,   236,
      -1,   233,    -1,   230,    -1,   227,    -1,   229,    -1,   225,
      -1,   220,    -1,   219,    -1,   221,    -1,   238,    -1,   228,
      -1,   235,    -1,   234,    -1,    67,    -1,    65,    -1,    76,
      -1,   170,    -1,   203,    -1,   243,    -1,   241,    -1,   242,
      -1,   239,    -1,   240,    -1,   245,    -1,   246,    -1,   247,
      -1,    66,    -1,   296,    -1,   294,    -1,   295,    -1,   300,
      -1,   301,    -1,   302,    -1,   297,    -1,   298,    -1,   299,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,
      -1,    91,    -1,   288,    -1,   289,    -1,   290,    -1,   291,
      -1,   292,    -1,   293,    -1,   304,    -1,   305,    -1,   306,
      -1,   307,    -1,   308,    -1,   309,    -1,   310,    -1,    92,
      -1,   107,    -1,   116,    -1,   173,    -1,   181,    -1,   190,
      -1,   140,    -1,    93,    -1,   117,    -1,   141,    -1,   182,
      -1,   317,    -1,   315,    -1,   316,    -1,   320,    -1,   319,
      -1,   318,    -1,   321,    -1,    26,    -1
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
    1699,  1702,  1706,  1711,  1713,  1716,  1720,  1722,  1724,  1726,
    1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,  1744,  1746,
    1748,  1750,  1752,  1754,  1756,  1758,  1761,  1764,  1768,  1770,
    1775,  1780,  1784,  1789,  1791,  1795,  1797,  1801,  1803,  1805,
    1809,  1813,  1815,  1817,  1819,  1821,  1823,  1828,  1837,  1843,
    1853,  1863,  1874,  1876,  1879,  1881,  1884,  1891,  1892,  1894,
    1898,  1902,  1903,  1905,  1907,  1909,  1912,  1915,  1916,  1918,
    1920,  1922,  1925,  1928,  1930,  1932,  1934,  1936,  1938,  1940,
    1942,  1944,  1946,  1948,  1950,  1954,  1958,  1961,  1965,  1969,
    1972,  1974,  1976,  1978,  1980,  1982,  1984,  1986,  1991,  1995,
    2003,  2007,  2015,  2020,  2025,  2029,  2037,  2041,  2049,  2052,
    2054,  2057,  2061,  2063,  2065,  2067,  2069,  2071,  2075,  2079,
    2081,  2083,  2085,  2087,  2091,  2093,  2095,  2097,  2099,  2101,
    2103,  2105,  2107,  2109,  2111,  2113,  2115,  2119,  2123,  2128,
    2133,  2137,  2141,  2145,  2149,  2154,  2159,  2163,  2168,  2175,
    2180,  2187,  2192,  2196,  2201,  2208,  2215,  2220,  2227,  2234,
    2239,  2241,  2244,  2246,  2248,  2250,  2255,  2261,  2268,  2272,
    2276,  2280,  2284,  2290,  2298,  2306,  2312,  2318,  2324,  2332,
    2340,  2346,  2352,  2356,  2360,  2366,  2374,  2380,  2388,  2390,
    2395,  2399,  2405,  2407,  2410,  2414,  2418,  2420,  2424,  2427,
    2428,  2430,  2432,  2435,  2437,  2441,  2443,  2447,  2449,  2454,
    2456,  2459,  2463,  2464,  2466,  2467,  2469,  2474,  2477,  2481,
    2483,  2484,  2486,  2491,  2492,  2494,  2497,  2499,  2503,  2504,
    2506,  2509,  2512,  2514,  2515,  2517,  2518,  2520,  2522,  2524,
    2526,  2528,  2530,  2532,  2536,  2540,  2542,  2544,  2546,  2549,
    2553,  2555,  2557,  2559,  2561,  2563,  2565,  2567,  2569,  2572,
    2575,  2577,  2579,  2582,  2585,  2589,  2591,  2594,  2597,  2603,
    2606,  2608,  2610,  2611,  2614,  2616,  2620,  2625,  2626,  2629,
    2630,  2633,  2638,  2643,  2647,  2650,  2654,  2656,  2660,  2661,
    2663,  2665,  2668,  2671,  2674,  2677,  2679,  2682,  2685,  2688,
    2691,  2695,  2698,  2702,  2706,  2711,  2714,  2717,  2719,  2721,
    2725,  2728,  2732,  2735,  2739,  2742,  2746,  2750,  2754,  2760,
    2766,  2772,  2781,  2787,  2791,  2797,  2805,  2807,  2809,  2811,
    2815,  2819,  2823,  2825,  2827,  2829,  2831,  2833,  2835,  2837,
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
    3259,  3261,  3263,  3265,  3267,  3269,  3271,  3273,  3275
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   836,   836,   837,   841,   845,   851,   855,   859,   865,
     871,   879,   885,   894,   899,   905,   911,   917,   925,   930,
     938,   946,   954,   963,   968,   974,   980,   989,   996,  1003,
    1009,  1018,  1019,  1020,  1021,  1022,  1025,  1026,  1027,  1028,
    1029,  1030,  1031,  1032,  1035,  1040,  1046,  1052,  1058,  1063,
    1069,  1074,  1080,  1085,  1091,  1096,  1101,  1106,  1112,  1114,
    1116,  1124,  1129,  1137,  1145,  1154,  1161,  1169,  1174,  1180,
    1186,  1192,  1200,  1210,  1216,  1223,  1231,  1238,  1244,  1253,
    1254,  1255,  1256,  1257,  1258,  1259,  1260,  1263,  1269,  1276,
    1283,  1291,  1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,
    1307,  1308,  1311,  1317,  1323,  1329,  1336,  1342,  1349,  1354,
    1360,  1366,  1378,  1390,  1403,  1408,  1416,  1424,  1433,  1438,
    1445,  1450,  1457,  1462,  1470,  1475,  1482,  1488,  1497,  1502,
    1508,  1519,  1532,  1544,  1557,  1562,  1567,  1572,  1578,  1585,
    1593,  1598,  1606,  1614,  1622,  1630,  1640,  1644,  1650,  1654,
    1661,  1670,  1681,  1687,  1694,  1699,  1706,  1713,  1722,  1732,
    1742,  1752,  1767,  1783,  1787,  1792,  1797,  1801,  1806,  1811,
    1816,  1824,  1831,  1838,  1851,  1852,  1853,  1854,  1855,  1856,
    1857,  1858,  1859,  1860,  1861,  1862,  1865,  1870,  1876,  1892,
    1898,  1904,  1911,  1918,  1927,  1936,  1945,  1954,  1965,  1971,
    1977,  1983,  1995,  2000,  2006,  2018,  2031,  2051,  2057,  2064,
    2073,  2080,  2085,  2097,  2109,  2110,  2111,  2112,  2113,  2114,
    2117,  2118,  2119,  2120,  2121,  2122,  2123,  2124,  2125,  2126,
    2127,  2128,  2131,  2143,  2149,  2154,  2160,  2165,  2170,  2176,
    2185,  2195,  2207,  2219,  2225,  2226,  2227,  2230,  2231,  2232,
    2233,  2234,  2237,  2244,  2252,  2258,  2268,  2277,  2284,  2291,
    2301,  2311,  2321,  2331,  2341,  2351,  2361,  2371,  2381,  2390,
    2400,  2410,  2422,  2428,  2434,  2440,  2446,  2454,  2462,  2470,
    2478,  2488,  2494,  2503,  2504,  2508,  2515,  2519,  2524,  2527,
    2531,  2535,  2541,  2547,  2553,  2559,  2567,  2571,  2575,  2583,
    2591,  2599,  2609,  2615,  2621,  2629,  2635,  2643,  2647,  2655,
    2661,  2667,  2673,  2682,  2691,  2700,  2711,  2715,  2721,  2727,
    2735,  2741,  2750,  2761,  2767,  2775,  2779,  2788,  2794,  2800,
    2808,  2814,  2820,  2828,  2834,  2840,  2848,  2854,  2861,  2871,
    2878,  2888,  2894,  2902,  2908,  2917,  2923,  2931,  2937,  2946,
    2952,  2960,  2966,  2970,  2976,  2981,  2987,  2991,  3000,  3006,
    3015,  3025,  3024,  3037,  3046,  3055,  3066,  3070,  3081,  3085,
    3091,  3094,  3100,  3104,  3110,  3114,  3118,  3124,  3128,  3134,
    3140,  3146,  3154,  3158,  3162,  3168,  3172,  3178,  3186,  3190,
    3198,  3202,  3210,  3214,  3222,  3226,  3234,  3238,  3244,  3248,
    3254,  3258,  3262,  3266,  3274,  3278,  3282,  3288,  3293,  3299,
    3303,  3307,  3311,  3315,  3319,  3325,  3329,  3333,  3339,  3343,
    3347,  3351,  3360,  3366,  3374,  3380,  3388,  3392,  3396,  3402,
    3406,  3414,  3423,  3432,  3438,  3448,  3452,  3458,  3463,  3469,
    3475,  3483,  3489,  3499,  3505,  3513,  3517,  3521,  3525,  3529,
    3535,  3541,  3547,  3551,  3557,  3561,  3570,  3574,  3578,  3584,
    3588,  3596,  3600,  3606,  3610,  3616,  3620,  3624,  3628,  3634,
    3638,  3642,  3646,  3652,  3658,  3666,  3672,  3676,  3680,  3684,
    3688,  3692,  3696,  3700,  3704,  3708,  3712,  3716,  3720,  3724,
    3730,  3734,  3740,  3747,  3754,  3763,  3769,  3773,  3779,  3785,
    3791,  3797,  3801,  3819,  3825,  3831,  3837,  3845,  3849,  3855,
    3861,  3871,  3875,  3881,  3885,  3889,  3895,  3903,  3919,  3927,
    3943,  3961,  3981,  3987,  3996,  4002,  4011,  4018,  4019,  4021,
    4026,  4033,  4036,  4042,  4048,  4054,  4061,  4070,  4073,  4079,
    4085,  4091,  4098,  4107,  4111,  4117,  4121,  4127,  4131,  4135,
    4140,  4147,  4151,  4155,  4159,  4165,  4170,  4176,  4181,  4187,
    4193,  4198,  4203,  4208,  4213,  4218,  4223,  4226,  4232,  4236,
    4242,  4246,  4252,  4258,  4264,  4268,  4274,  4278,  4284,  4290,
    4294,  4298,  4304,  4310,  4316,  4324,  4328,  4332,  4336,  4340,
    4344,  4348,  4354,  4360,  4368,  4374,  4380,  4384,  4388,  4392,
    4396,  4400,  4404,  4408,  4412,  4416,  4422,  4428,  4432,  4436,
    4442,  4447,  4453,  4459,  4463,  4467,  4473,  4477,  4483,  4489,
    4493,  4501,  4507,  4511,  4517,  4526,  4535,  4541,  4547,  4555,
    4561,  4567,  4573,  4579,  4583,  4589,  4595,  4599,  4607,  4613,
    4619,  4625,  4633,  4637,  4643,  4649,  4653,  4659,  4663,  4669,
    4675,  4682,  4690,  4695,  4701,  4707,  4715,  4721,  4728,  4734,
    4743,  4749,  4755,  4761,  4770,  4777,  4783,  4789,  4798,  4805,
    4809,  4815,  4820,  4827,  4831,  4837,  4841,  4847,  4851,  4857,
    4861,  4869,  4880,  4883,  4889,  4892,  4898,  4904,  4912,  4916,
    4922,  4925,  4931,  4941,  4944,  4950,  4960,  4966,  4974,  4977,
    4983,  4987,  4991,  4997,  5000,  5006,  5009,  5015,  5019,  5023,
    5027,  5031,  5037,  5043,  5053,  5063,  5067,  5071,  5077,  5083,
    5091,  5095,  5099,  5103,  5107,  5111,  5115,  5119,  5125,  5129,
    5133,  5137,  5143,  5149,  5157,  5165,  5169,  5175,  5185,  5196,
    5202,  5206,  5212,  5215,  5221,  5226,  5233,  5241,  5244,  5250,
    5254,  5260,  5269,  5276,  5284,  5288,  5294,  5300,  5308,  5311,
    5317,  5322,  5332,  5340,  5350,  5356,  5360,  5366,  5370,  5374,
    5380,  5386,  5390,  5394,  5398,  5404,  5412,  5422,  5426,  5432,
    5438,  5442,  5448,  5452,  5458,  5462,  5468,  5475,  5481,  5490,
    5496,  5506,  5512,  5518,  5539,  5563,  5587,  5591,  5595,  5601,
    5607,  5613,  5619,  5622,  5623,  5635,  5636,  5637,  5638,  5639,
    5640,  5641,  5642,  5643,  5644,  5645,  5646,  5647,  5648,  5649,
    5650,  5651,  5654,  5655,  5656,  5657,  5658,  5659,  5660,  5661,
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
    5792,  5793,  5794,  5795,  5796,  5797,  5798,  5799,  5800,  5801,
    5802,  5803,  5804,  5805,  5806,  5807,  5808,  5809,  5810,  5811,
    5812,  5813,  5814,  5815,  5816,  5817,  5818,  5819,  5820,  5821,
    5822,  5823,  5824,  5825,  5826,  5827,  5828,  5829,  5830,  5831,
    5832,  5833,  5834,  5835,  5836,  5837,  5838,  5839,  5840,  5841,
    5842,  5843,  5844,  5845,  5846,  5847,  5848,  5849,  5850,  5851,
    5852,  5853,  5854,  5855,  5856,  5857,  5858,  5859,  5862
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
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 17595;
  const int xquery_parser::yynnts_ = 326;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 617;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 335;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 589;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17875 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 5864 "/home/colea/xquery/new-jsoniq/build/src/compiler/parser/xquery_parser.y"

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

