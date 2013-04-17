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
#line 88 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"


#include "common/common.h"

#ifdef WIN32
#pragma warning(disable: 4786)
#endif

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/api/compilercb.h"
#include "store/api/update_consts.h"
#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/parser_helpers.h"

#define SYMTAB( n ) driver.symtab.get( (off_t)n )
#define SYMTAB_PUT( s ) driver.symtab.put( s )
#define LOC( p ) driver.createQueryLoc( p )


#define YYDEBUG 1

using namespace std;
using namespace zorba;



/* Line 293 of lalr1.cc  */
#line 69 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 908 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1039 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 99 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"

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
#line 185 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"

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
            case '"':
              return yyr;
            default:
              yyr += *yyp;
              break;

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
    /*
    switch (yytype)
      {
         default:
	  break;
      }
      */
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
#line 906 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 290 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 905 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 299 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 308 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 317 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 326 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 335 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 344 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 353 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 362 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 371 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 380 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 389 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 398 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 407 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 416 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 425 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 434 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 443 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 452 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 461 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 470 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 479 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 488 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 497 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 506 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 515 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 524 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 533 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 542 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 551 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 560 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 569 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 578 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 587 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 596 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 605 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 614 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 623 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 632 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 641 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 650 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 659 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 668 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 677 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 686 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 695 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 704 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 713 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 722 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 731 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 740 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 749 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 758 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 767 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 776 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 785 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 821 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 830 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 839 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 848 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 857 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 866 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 875 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 884 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 902 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 911 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 938 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 947 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 956 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 965 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 974 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 983 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 992 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1001 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1010 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1019 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1028 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1037 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1046 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1055 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1064 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1073 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1082 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1091 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1100 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1109 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1118 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1127 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1136 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1145 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1154 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1163 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1172 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1181 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1190 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1199 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1208 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1217 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1226 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1235 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1244 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1253 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1262 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1271 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1280 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1289 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1298 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1307 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1316 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1325 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1334 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1343 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1352 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1361 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1370 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1379 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1388 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1397 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1406 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1415 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1424 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1433 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1442 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1451 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1460 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1469 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1478 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1487 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1496 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1505 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1514 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1523 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1532 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1541 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1550 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1559 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1568 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1577 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1586 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1595 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1604 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1613 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1622 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1631 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1640 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1649 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1658 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1667 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1676 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1685 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1694 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1703 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1712 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1721 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1730 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1739 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1748 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1757 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1766 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1775 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1784 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1793 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1802 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1811 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1820 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1829 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1838 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1847 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1856 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1865 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1874 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1883 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1892 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1901 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1910 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1919 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1928 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1937 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1946 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1955 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1964 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1973 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1982 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1991 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2000 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2009 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2018 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2027 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2036 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2045 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2054 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2063 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2072 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2081 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2090 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2099 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2108 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2117 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2126 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2135 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2144 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2153 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2162 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2171 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2180 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2189 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2198 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2207 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2216 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2225 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2234 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2243 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2252 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2261 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2270 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2279 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2288 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2297 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2306 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2315 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2324 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2333 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2342 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2351 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2360 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2369 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2378 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2387 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2396 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2405 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2414 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2423 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2432 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2441 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2450 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2459 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2468 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2477 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2486 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2495 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2504 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2513 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2522 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2531 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2540 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2549 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2558 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2567 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2576 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2585 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2594 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2603 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2612 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2621 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2630 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2639 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2648 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2657 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2666 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2675 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2684 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2693 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2702 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2711 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2720 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2729 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2738 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2747 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 646: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2756 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 647: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2765 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 648: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2774 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 649: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2783 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2792 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2801 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 652: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2810 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 659: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2819 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 660: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2828 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 661: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2837 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
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
#line 133 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2934 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1057 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1061 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1065 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1073 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1079 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1083 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1092 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1098 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1106 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1112 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1123 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1128 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1136 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1143 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1150 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1159 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1166 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1174 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1182 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1190 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1201 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1206 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1213 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1220 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1232 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1242 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1249 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1256 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      // error
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 1291 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1296 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1304 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1312 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1320 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1325 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1333 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1338 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1346 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1351 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1359 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1364 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1369 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1374 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1387 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1397 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1402 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1410 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1418 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1429 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1436 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1447 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1452 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1460 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1467 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1474 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1483 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 1496 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1504 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1511 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1521 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1528 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1535 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1558 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1564 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1573 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1580 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1590 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1599 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1600 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1601 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1602 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinity"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1603 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1604 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1605 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1606 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1607 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1608 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1614 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1622 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1630 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1638 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1645 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1653 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1660 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1665 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1673 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1681 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(4) - (4)].expr),
                             nt->get_annotations(),
                             false);  // not external

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1695 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             NULL,   // no init expr
                             nt->get_annotations(),
                             true);  // external

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1709 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(5) - (5)].expr),     // init expr
                             nt->get_annotations(),
                             true);  // external

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1726 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1731 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1739 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1747 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1758 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1763 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1772 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1777 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1784 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1789 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1799 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1804 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1813 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1819 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1832 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1837 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1845 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theParams,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType,
                            (yysemantic_stack_[(4) - (4)].expr),      // body
                            false,   // not explicitly updating
                            false);  // not external
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1856 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType.getp(),
                            NULL,   // no body
                            false,   // not explicitly updating
                            true);  // external
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1871 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            (yysemantic_stack_[(5) - (5)].expr),    // body
                            true,  // updating
                            false);// not external
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1883 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            NULL,  // no body
                            true,  // updating
                            true); // external
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1898 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1903 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1908 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1913 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1921 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1928 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1939 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1944 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1954 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 1963 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 1972 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 1981 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 1993 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1997 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 2003 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2007 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2017 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2027 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2040 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 2046 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 2055 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2060 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2067 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2074 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2086 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2096 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2106 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2117 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2133 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2153 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2157 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2161 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2169 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2173 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2177 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2185 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2190 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2202 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 2209 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 2219 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(4) - (1)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(4) - (2)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(4) - (4)].expr); // to prevent the Bison warning
      error((yylocation_stack_[(4) - (3)]), "syntax error, unexpected statement (missing semicolon \";\" between statements?)");
      delete (yysemantic_stack_[(4) - (1)].expr); // these need to be deleted here because the parser deallocator will skip them
      delete (yysemantic_stack_[(4) - (2)].expr);
      delete (yysemantic_stack_[(4) - (4)].expr);
      YYERROR;
    }
    break;

  case 186:

/* Line 690 of lalr1.cc  */
#line 2251 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2256 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 2264 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      if (dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (2)].expr)) == NULL)
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
#line 2281 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2289 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 2297 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2304 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2311 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2322 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                          NULL,  // no type
                                          NULL,  // no init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 2331 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), // type
                                          NULL,  // no init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 2340 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                          NULL,  // no type
                                          (yysemantic_stack_[(4) - (4)].expr),    // init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 2349 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), // type
                                          (yysemantic_stack_[(5) - (5)].expr),    // init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 2362 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 2370 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 2378 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2386 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2401 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2406 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2414 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2428 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2445 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2470 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2478 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2485 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2496 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2506 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2511 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2524 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (1)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      // Heuristics to improve the error message: if the $1 Expr is a QName (which in turn gets
      // promoted to a PathExpr), chances are that it's not a missing comma, so don't modify
      // the error message.
      if (dynamic_cast<PathExpr*>((yysemantic_stack_[(3) - (1)].expr)) == NULL)
        error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected expression (missing comma \",\" between expressions?)");
      delete (yysemantic_stack_[(3) - (1)].expr); // these need to be deleted here because the parser deallocator will skip them
      delete (yysemantic_stack_[(3) - (3)].expr);
      YYERROR;
    }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 2571 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2585 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2593 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2598 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2606 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2611 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2616 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2624 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2633 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2645 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2655 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2668 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2692 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2699 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2709 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2715 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2724 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2734 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2741 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2749 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2761 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2771 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2781 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2791 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2801 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2811 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2821 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2831 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2842 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2851 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2861 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2871 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2887 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2896 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2905 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2913 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2919 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2931 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2939 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2949 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2957 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 2969 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2975 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2988 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2992 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 3000 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 3004 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3013 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3017 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3021 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3031 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 3039 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3046 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3052 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3062 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3066 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3070 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3078 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3086 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3094 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3106 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3114 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3120 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3130 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3136 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3146 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3150 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3160 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3166 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3172 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3178 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3187 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3196 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3205 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3218 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3222 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3230 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3236 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3246 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3254 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3263 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3276 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3283 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3295 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3299 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3311 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3318 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3324 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3333 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3340 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3346 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3357 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3364 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3370 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3379 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3388 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3395 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3406 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3413 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3425 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3431 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 3443 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3449 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3460 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3466 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3477 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3483 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3494 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3500 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3511 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3520 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3524 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3533 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3537 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3545 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3549 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
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
#line 3559 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3566 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3575 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3584 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3589 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3598 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3607 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3616 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3629 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3633 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 3645 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3649 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3656 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3660 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3667 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3671 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3680 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3684 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3688 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3696 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3700 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3706 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3712 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3718 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3728 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3732 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3736 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3744 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3748 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3754 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3764 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3768 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3778 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3782 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3792 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3796 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3806 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3810 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3820 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3824 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3833 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3837 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3845 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3849 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3853 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3857 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3867 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3871 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3875 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3882 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3887 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3895 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3899 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3903 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3907 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3911 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3915 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3927 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3931 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3939 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3943 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3947 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3951 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3962 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3968 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3978 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3984 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3994 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3998 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4002 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4040 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4044 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 4054 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 4065 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4078 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4087 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 4097 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4101 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4110 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4115 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4124 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4130 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 4138 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4144 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 4156 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4162 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4172 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4176 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4180 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4184 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4188 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4194 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4200 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4208 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4212 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4220 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4224 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4235 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4239 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4243 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4249 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4253 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4267 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4271 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4279 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4283 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4293 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4297 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4301 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4305 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4314 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4318 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4322 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4326 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4334 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4340 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4350 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4358 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4362 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4366 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4370 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4374 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4378 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4382 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4386 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4390 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4394 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4399 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4403 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4407 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4411 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4426 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4430 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 4438 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4445 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4452 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4463 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4471 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4475 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4483 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4491 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4499 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4553 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4557 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 4579 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4585 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4591 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4597 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4607 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4611 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4619 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4627 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 4639 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4643 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4651 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4655 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4659 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4667 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 4675 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 4692 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 4700 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 4719 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 4738 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 4760 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4766 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4777 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4783 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4794 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4809 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4814 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4823 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4827 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4834 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4840 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4846 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4853 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4864 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4868 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4875 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4881 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4887 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4894 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4905 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4909 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4917 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4921 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4929 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4933 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4937 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4942 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4951 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4955 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4959 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4963 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4971 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4976 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4984 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4989 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4997 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 5005 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 5010 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 5015 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5020 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5025 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5030 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5041 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5049 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5053 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5070 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5074 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5082 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5090 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5098 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5102 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5110 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5114 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5122 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5130 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5134 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5138 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5173 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5179 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5185 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5195 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5199 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5203 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5207 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5211 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5215 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5219 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5226 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5232 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5242 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5250 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5258 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5262 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5266 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5270 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5274 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5278 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5282 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5286 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5290 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5294 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5302 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5310 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5314 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5318 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5326 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5333 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5341 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5349 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5353 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5357 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5365 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5369 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5375 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5381 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5385 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5395 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5403 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5407 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5413 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 5422 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 5431 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5437 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5443 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5453 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5470 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5477 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5492 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5519 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5523 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5531 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5539 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5543 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5554 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5571 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5577 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5583 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5593 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5597 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5603 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5609 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5613 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5619 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5623 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5629 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5635 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5652 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5657 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5665 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5671 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5681 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5703 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5712 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5718 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5731 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5745 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5752 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5758 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5768 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5777 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5785 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5791 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5809 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5817 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 5821 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 5828 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 5833 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 5841 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 5845 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 5852 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 5856 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 5863 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 5867 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 5874 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 5878 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 5887 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 5899 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 5903 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 5910 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 5914 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 5922 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 5930 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 5938 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 5942 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 5949 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 5953 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 5961 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 5972 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 5976 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 5984 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 5996 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 6002 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6011 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6015 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6023 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6027 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6031 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6038 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6042 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6049 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6053 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6061 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6065 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6069 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6073 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6077 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6085 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6093 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 6105 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 6117 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6121 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6125 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6133 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6139 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6149 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6153 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6157 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6161 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6165 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6169 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6173 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6177 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6185 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6189 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6193 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6197 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6205 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6211 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6221 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6231 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6235 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6243 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 6253 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 6264 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6271 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6275 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6282 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6286 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6293 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6298 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6307 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6316 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6320 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6327 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6331 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6339 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 6348 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6355 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6365 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6369 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6376 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6382 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6391 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6395 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6402 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6407 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 6419 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 6427 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 6439 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6447 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6451 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6459 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6463 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6467 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6475 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6483 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6487 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6491 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6495 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6503 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 6511 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 6523 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6527 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6535 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6549 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6553 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6560 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6565 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6573 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6578 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6587 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6595 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6601 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6611 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6617 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 6627 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6634 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6641 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 6666 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 6694 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 6722 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6726 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6730 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6737 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6744 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6751 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6768 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
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
#line 6781 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6782 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6783 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6784 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6785 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6786 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6787 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6788 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6789 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6790 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6791 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6792 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6793 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6794 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6795 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6796 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6801 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6802 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6803 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6804 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6805 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6806 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6807 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6808 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6809 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6810 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6811 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6812 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6813 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6814 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6815 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6816 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6817 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6818 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6819 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6820 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6821 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6822 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6823 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6824 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6825 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6826 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6827 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6828 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6829 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6830 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6831 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6832 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6833 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6834 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6835 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6836 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6837 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6838 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6839 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6840 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6841 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6842 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6843 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6844 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6845 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6846 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6847 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6848 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6849 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6850 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6851 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6852 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6853 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6854 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6855 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6856 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6857 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6858 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6859 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6860 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6861 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6862 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6863 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6864 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6865 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6866 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6867 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6868 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6869 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6870 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6871 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6872 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6873 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6874 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6875 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6876 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6877 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6878 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6879 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6880 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6881 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6882 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6883 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6884 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6885 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6886 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6887 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6888 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6889 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6890 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6891 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6892 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6893 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6894 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6895 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6896 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6897 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6898 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6899 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6900 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6901 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6902 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6903 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6904 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6905 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6906 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6907 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6908 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6909 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6910 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6911 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6912 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6913 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6914 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6915 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6916 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6917 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6918 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6919 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6920 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6921 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6922 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6923 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6924 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6925 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6926 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6927 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 6928 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 6929 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 6930 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 6931 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 6932 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 6933 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 6934 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 6935 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 6936 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 6937 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 6938 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 6939 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 6940 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 6941 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 6942 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 6943 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 6944 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 6945 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 6946 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 6947 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 6948 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 6949 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 6950 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 6951 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 6952 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 6953 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 6954 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 6955 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 6956 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 6957 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 6958 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 6959 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 6960 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 6961 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 6962 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 6963 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 6964 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 6965 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 6966 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 6967 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 6968 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 6969 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 6970 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 6971 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 6972 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 6973 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 6974 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 6975 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 6976 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 6977 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 6978 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 6979 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 6980 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 6981 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 6982 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 6983 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 6984 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 6985 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 6986 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 6987 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 6988 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 6989 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 6990 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 6991 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 6992 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 6993 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 6994 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 6995 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 6996 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 6997 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 6998 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1021:

/* Line 690 of lalr1.cc  */
#line 6999 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1022:

/* Line 690 of lalr1.cc  */
#line 7000 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1023:

/* Line 690 of lalr1.cc  */
#line 7001 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1024:

/* Line 690 of lalr1.cc  */
#line 7002 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1025:

/* Line 690 of lalr1.cc  */
#line 7003 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1026:

/* Line 690 of lalr1.cc  */
#line 7004 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1027:

/* Line 690 of lalr1.cc  */
#line 7005 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1028:

/* Line 690 of lalr1.cc  */
#line 7010 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12352 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1509;
  const short int
  xquery_parser::yypact_[] =
  {
      4822, -1509, -1509, -1509,  6386,  6386,  6386,  6386, -1509, -1509,
      80,   261, -1509,   943,   283, -1509, -1509, -1509,   791, -1509,
   -1509, -1509,   396,   451,   840,  4540,   535,   588,   181, -1509,
      71, -1509,   741, -1509, -1509, -1509, -1509, -1509,   853, -1509,
     807,   832, -1509, -1509, -1509, -1509,   471, -1509,   855, -1509,
     854,   857, -1509,   395, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,   702,   727,
   -1509, -1509, -1509, -1509,   719, 12626, -1509, -1509, -1509,   747,
   -1509, -1509, -1509,   905, -1509,   845,   903, -1509, -1509, 17031,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,   915, -1509,
   -1509,   918,   922, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
    5450,  8882,  9194, 17031, -1509, -1509,   770, -1509, -1509, -1509,
   -1509,   899, -1509, -1509,   935, 13525, -1509, 13830,   936,   937,
   -1509, -1509, -1509,   938, -1509, 12002, -1509, -1509, -1509, -1509,
   -1509, -1509,   909, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509,   150,   761, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509,   -75,   908,   -44, -1509,   203,   205, -1509, -1509, -1509,
   -1509, -1509, -1509,   947, -1509,   827,   828,   830, -1509, -1509,
     910,   917, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509,  9506,  9818, -1509,   762, -1509,
   -1509, -1509, -1509, -1509,  5136,  6698,  1075, -1509,  7010, -1509,
   -1509,   613,    98, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509,   102, -1509, -1509,
   -1509, -1509, -1509, -1509,   398, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509,  6386, -1509, -1509, -1509, -1509,    44, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509,   139, -1509,   884,
   -1509, -1509, -1509,   713, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509,   911,   987, -1509,   954,   831,   982,   621,   561,
     728,    55, -1509,  1036,   887,   989,   986, 10754, -1509,   906,
   -1509, -1509,    21, -1509, -1509, 12314, -1509,   824, -1509,   939,
   12626, -1509,   939, 12626, -1509, -1509, -1509,   632, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509,   781, -1509, -1509, -1509, -1509, -1509,   912, -1509,
    6386,   914,   916,   920,  6386,   416,   416,  1064,   339,   639,
     704, 17320, 17031,    41,  1055, 17031,   950,   988,   633, 13525,
     752,   861, 17031, 17031,   806,   647,    56, -1509, -1509, -1509,
   13525,  6386,   926,  6386,   158, 11066, 14719, 17031, -1509,   833,
     838, 17031,   996,   298,   962, 11066,  1125,   201,   470, 17031,
    1007,   984,  1020, -1509,   941, 11066, 13227, 17031, 17031, 17031,
    6386,   942, 11066, 11066, 17031,  6386,   977,   979, -1509, -1509,
   -1509, 11066, 15008,   978, -1509,   980, -1509, -1509, -1509, -1509,
     981, -1509,   983, -1509, -1509, -1509, -1509, -1509,   990, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, 17031, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509,   993, 17031, -1509, -1509, -1509,   956,  5762,  1017,    39,
     991,   992,   994, 17031,  6386, -1509,   998,   124, -1509,   778,
   -1509,   125,  1110, 11066, 11066, -1509, -1509,    97, -1509, -1509,
   -1509,  1130, -1509, -1509, -1509, -1509, 11066,   951, -1509,  1121,
   11066, 11066, 14132,   966, 11066, 11066, 11066, 11066, 14132, 11066,
     933,   940, 17031,   985,   997, 11066, 11066,  5450,   923, -1509,
      64, -1509,    42, 11066,  6698, -1509, -1509, -1509, -1509, -1509,
     943,   181,   110,   112,  1166,  7322,  3270,  7634,  3593,   905,
   -1509, -1509,   179,   905, -1509, 11066,  4217, -1509,  1051,   140,
      71,  1003,  1002,  1006,  6386, 11066, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, 11378, 11378, 11378, -1509, 11378, 11378,
   -1509, 11378, -1509, 11378, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, 11378, 11378,  1103, 11378, 11378, 11378, 11378, 11378, 11378,
   11378, 11378, 11378, 11378, 11378, 11378,   946,  1084,  1085,  1086,
   -1509, -1509, -1509, 11690, 10130, -1509, -1509, 12002, 12002, 11066,
     939, -1509, -1509,   939, -1509,  7946,   939,  1037,  8258, -1509,
   -1509, -1509, -1509,   251, -1509,   312, -1509, -1509, -1509, -1509,
   -1509, -1509,  1081,  1082,   535,  1162, -1509, -1509, 17320,   870,
     680, 17031,  1031,  1032,   870,  1064,  1066,  1062, -1509, -1509,
   -1509,   392,   949,  1102,   898, 17031,  1056, 11066,  1083, 17031,
   17031, -1509,  1067,  1016, -1509,  1018,   980,   832, -1509,  1019,
    1021,    93, -1509,   351,   373,  1096, -1509,    16, -1509, -1509,
    1096, 17031,    33, 17031,  1111,   421, -1509,  6386, -1509,   133,
   -1509, 13525,  1113,  1163, 13525,  1064,  1114,   623, 17031, 11066,
      71, -1509,   222,  1024, -1509,  1025,  1026,  1027,    36, -1509,
      75,  1033, -1509,   161,   162,  1063, -1509,  1034,  6386,  6386,
     272, -1509,   440,   454,   629, 11066,   276, -1509, -1509, 11066,
   11066, -1509, 11066, 11066, 11066, -1509, 11066, -1509, 11066, -1509,
   17031,  1110, -1509,   443,   285,   366, -1509, -1509, -1509,   375,
   -1509,   500, -1509, -1509,  1069,  1070,  1071,  1072,  1073,   632,
     781, -1509,   297,   369,    15,    60,  1126,   483,   995,  1004,
    1000,    22, -1509,  1077, -1509, -1509,  1038,   166,  5762,   383,
   12929,   923, -1509, -1509, -1509,  1001, -1509,   613,   760,  1183,
     635, -1509, -1509,   114, -1509, -1509, -1509,   116, -1509,    43,
   -1509, -1509, -1509, -1509, -1509,  3905, -1509, -1509, -1509, 17031,
    1057, 11066,  1119, -1509, -1509, -1509,   987, -1509, -1509, -1509,
   -1509, -1509, 11378, -1509, -1509, -1509,    77, -1509,   561,   561,
     271,   728,   728,   728,   728,    55,    55, -1509, -1509, 16164,
   16164, 17031, 17031, -1509, -1509,   397, -1509, -1509,   191, -1509,
   -1509, -1509, -1509,   457, -1509, -1509,   465,   416, -1509, -1509,
      48,   712,   750, -1509,   535, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509,   870, -1509,  1107, 16453,  1098,
   11066, -1509, -1509, -1509,  1147,  1064,  1064,   870, -1509,   892,
    1064,   693, 17031,   336,   667,  1215, -1509, -1509,   958,   653,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509,   392,    83,  1022,   634, 11066, -1509, 17031,  1151,   948,
    1064, -1509, -1509, -1509, -1509,  1095, 17031, -1509, 17031, -1509,
   16742,  1123, 16164,  1133, 11066,   234,  1105,    38,   527,   999,
   -1509, -1509,   580,    33,  1147, 16164,  1136,  1161,  1074,  1058,
    1131,  1064,  1097,  1132,  1169,  1064, 11066,    61, -1509, -1509,
   -1509,  1109, -1509, -1509, -1509, -1509,  1148, 11066, 11066,  1120,
   -1509,  1168,  1170,  6386, -1509,  1090,  1092,  1124, 17031, -1509,
   17031, -1509, 11066,  1137,  1088, 11066, -1509,  1160,   167,   218,
     228,  1248, -1509,   463, -1509,   237,  1138, -1509, -1509,  1256,
   -1509,   763, 11066, 11066, 11066,   780, 11066, 11066, 11066, 11066,
   11066, 11066, 11066, 11066, 11066, 14132,  1167, 11066, 11066, -1509,
    8570,   101,  1041, -1509,   267, -1509, 11066,   117,   136,    43,
    7634,  3593,  7634,  1211, -1509, -1509, 11066,   767,  1185, -1509,
   17031,  1186, -1509, -1509, 11066,    77,   638,   399, -1509,  1009,
     241,  1039,  1040, -1509, -1509,   861, -1509,  1029,   595,  1142,
    1145, 16453,  1149,  1153,  1154,  1155,  1156, -1509,   460, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509,  1159, -1509, -1509, -1509, -1509, 10442, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509,   759, -1509,  1279,
     849, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
    1028, -1509, -1509,  1285, -1509, -1509, -1509, -1509, -1509,   654,
    1287, -1509,   103, -1509, -1509, -1509,   978,   451,   741,   981,
     807,   983,   990,   908,  1153,  1154,  1155, -1509,   460,   460,
   11690,  1030,  1010, -1509,  1147,    83,  1091,  1129,  6386,  1139,
    1140,  1176,  1143,  1144, 17031, -1509,    90, -1509, 17031, -1509,
   11066,  1177, 11066,  1205, 11066,   239,  1189, 11066,  1190, -1509,
    1220,  1221, 11066, 17031,   934,  1263, -1509, -1509, -1509, -1509,
   -1509, -1509, 16164, -1509,  6386,  1064,  1226, -1509, -1509, -1509,
    1064,  1226, -1509, 11066,  1199,  6386, 17031, -1509, -1509, 11066,
   11066,   801, -1509,   147,   802, -1509, 15297,   805, -1509,   811,
   -1509,  1158, -1509, -1509,  6386,  1157,  1164, -1509, 11066, -1509,
   -1509, 11066,  1150,  1168,  1243, -1509,  1214, -1509,   583, -1509,
   -1509,  1342, -1509, -1509,  6386, 17031, -1509,   590, -1509, -1509,
   -1509,  6386,  1165,  1116,  1117, -1509, -1509, -1509,  1127,  1135,
   -1509, -1509, -1509,  1258, -1509, -1509, -1509, -1509,  1122,   314,
   17031,  1171, -1509,  1200,  1206,  1207,  1212, -1509,   884,   859,
   12929,  1041, -1509,  6074, 12929, -1509, -1509,  1183,   636, -1509,
   -1509, -1509,  1185, -1509,  1064, -1509,   900, -1509,   575,  1260,
   -1509, 11066,   689,  1119,   434,  1182, -1509,    77,  1128, -1509,
   -1509,   -35, -1509,   668,   113,  1146,    77,   668, 11378, -1509,
     291, -1509, -1509, -1509, -1509, -1509, -1509,    77,  1217,  1089,
     949,   113, -1509, -1509,  1093,  1292, -1509, -1509, -1509, 14430,
    1187,  1188,  1194,  1201,  1203,  1208,  1210, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
    1344,   290,  1348,   290,  1106,  1280, -1509, -1509,  1216, 17031,
    1141, -1509, -1509, 11690, -1509,  1224, -1509, -1509, -1509, -1509,
   -1509, -1509, 11066,  1247, -1509, -1509, 11066, -1509,   318, -1509,
   11066,  1252, 11066, -1509, 11066, 17031, 17031, -1509,   715, -1509,
   11066, -1509,  1275,  1283,  1314,  1064,  1226, -1509, 11066,  1228,
   -1509, -1509, -1509,  1229, -1509,   268, 11066,  6386,  1230,   295,
   -1509, 17031,   501, -1509, 15586,   309, -1509, 15875,  1231, -1509,
   -1509,  1234, -1509, -1509, -1509, -1509, 11066,   821,  1248, 17031,
     753, -1509,  1236,  1248, 17031, -1509,  1237, -1509, 11066, 11066,
   11066, 11066,  1108, 11066, 11066, -1509, 11066, 11066, 11066, 11066,
    8570,   308, -1509, -1509, -1509, -1509, -1509,  1260, -1509, -1509,
   -1509,  1064, 11066, -1509,  1272, -1509, -1509, -1509, -1509,  1238,
   11378, -1509, -1509, -1509, -1509, -1509,    89, 11378, 11378,   564,
   -1509,  1039, -1509,   577, -1509,  1040,    77,  1270, -1509, -1509,
    1152, -1509, -1509, -1509, -1509,  1331,  1244, -1509,   475, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509,   275,   275, -1509,
     290, -1509, -1509,   485, -1509,  1402,   113,  1337,  1249, 11690,
      10,  1172,  1265, -1509, -1509, 11066, -1509, 11066,  1290, -1509,
   11066, -1509, -1509, -1509,  1385, -1509, -1509,  8570, 11066,  1064,
   -1509, -1509, -1509, 11066, 11066, -1509, -1509, -1509,  8570,  8570,
    1349,  6386, 16164, 17031,   570, 17031, 11066, 17031,   658,  8570,
   -1509,   319,    32,  1248, 17031, -1509,  1250,  1248, -1509, -1509,
   -1509, -1509, -1509, 11066, -1509, -1509, -1509,   252,   265,   266,
   11066, -1509, -1509, -1509,  1338, 11066, -1509,   728, 11378, 11378,
     271,   660, -1509, -1509, -1509, -1509, -1509, -1509, 11066, -1509,
   16164, -1509, 16164,  1351, -1509, -1509, -1509,  1418, -1509, -1509,
   -1509,  1184,  1341, -1509, -1509,  1343, -1509,   825, 17031,  1333,
    1227, 17031, 11690, -1509, -1509, 11066, -1509,  1335, -1509, -1509,
    1226, -1509, -1509, 16164, -1509, -1509, -1509,  1360, 11066,  1269,
   -1509,  1362,  8570, -1509, 17031,   433,   593, -1509,  1261,  1248,
   -1509,  1264, -1509,  1259,  1168,  1170,   435, -1509,  1338,   271,
     271, 11378,   467, -1509, -1509, 16164, -1509, -1509,  1337, 11690,
   -1509,  1260,  1173, 17031,  1345,  1235,  1343, -1509, 17031,   675,
   16164,  6386, 16164,  1276, -1509, -1509,  1371,   530, -1509, -1509,
   -1509, -1509,  1282,   714, -1509, -1509, -1509,  1271, -1509,  8570,
     822, -1509, -1509,   271, -1509, -1509, -1509, -1509, -1509, 11066,
    1174, 17031,  1352, -1509,  6386,   678, -1509, -1509,   685, 11066,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509,  1353, -1509,  1179,
    1175, 17031, -1509, -1509, 11066,  8570, 17031,  1178, 11066,  1180,
    1281, 11690, -1509, 11690,  8570, -1509,  1267,  1195, 17031,  1251,
    1355, 17031,  1192, 11690, -1509
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
     874,     0,   824,   921,   846,   955,   954,   956,   830,   829,
     849,   961,   813,   953,   958,   959,   950,   852,   894,   952,
     962,   960,   951,   850,   957,   971,   972,   969,   970,   968,
     821,   973,   974,   975,   941,   940,   927,   844,   837,   934,
     930,   847,   843,   942,   943,   833,   834,   827,   836,   939,
     938,   935,   931,   948,   949,   947,   937,   933,   926,   835,
     946,   945,   839,   841,   840,   932,   936,   928,   842,   929,
     838,   944,   997,   998,   999,  1000,  1001,  1002,   978,   979,
     977,   983,   984,   985,   980,   981,   982,   851,  1003,  1004,
    1005,  1006,  1007,  1008,  1009,     0,     0,  1021,  1022,  1023,
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
    1020,  1015,   967,   961,   953,   959,   950,   850,   971,   972,
     969,   821,   973,  1022,   453,   805,   445,     0,   192,   446,
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
     -1509, -1509,  -217,  -191, -1509,  1213,  1218, -1509,  1222,  -544,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
    -998, -1509, -1509, -1509, -1509,  -225,  -596, -1509,   743,  -274,
   -1509, -1509, -1509, -1509, -1509,   289,   516, -1509, -1509,     4,
    -149,  1061, -1509,  1044, -1509, -1509,  -637, -1509,   455, -1509,
     257, -1509,  -219,  -265, -1509,  -549, -1509,    -3,    51,     6,
    -234,  -173, -1509,  -880, -1509, -1509,   334, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509,   624,   -96,  1475,
       0, -1509, -1509, -1509, -1509,   468, -1509, -1509,  -304, -1509,
      23, -1509,  1035,  -932,  -747,  -726, -1509, -1509,   716, -1509,
   -1509,    24,   243, -1509, -1509, -1509,   122, -1508, -1509,   382,
     128, -1509, -1509,   132, -1317, -1509,   959,   226, -1509, -1509,
     223, -1037, -1509, -1509,   219, -1509, -1509, -1264, -1249, -1509,
     217, -1418, -1509, -1509,   863,   864, -1509,  -563,   847, -1509,
   -1509,  -658,   358,  -641,   362,   364, -1509, -1509, -1509,   591,
   -1509, -1509,  1191, -1509, -1509, -1509, -1509, -1509,  -874,  -321,
    -675, -1509,  -101, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
     -24,  -826, -1509,  -546,  -153,   303, -1509,  -400, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509,   814, -1509, -1509, -1509, -1509,
   -1031, -1509,   206, -1509,   694,  -817, -1509, -1509, -1509, -1509,
   -1509,  -257,  -248, -1235,  -982, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509,  -765,  -863,  -178,  -848,
   -1509, -1509, -1509,  -808, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509,  1076,  1078,  -214,   513,   344, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,   184, -1509,
   -1509,   174, -1509,   176, -1067, -1509, -1509, -1509,   142,   135,
     -37,   407, -1509, -1509, -1509, -1509, -1509, -1509, -1509, -1509,
   -1509, -1509, -1509, -1509, -1509,   144, -1509, -1509, -1509,   -28,
     401,   546, -1509, -1509, -1509, -1509, -1509,   337, -1509, -1509,
   -1443, -1509, -1509, -1509,  -545, -1509,   105, -1509,   -50, -1509,
   -1509, -1509, -1509, -1314, -1509,   155, -1509, -1509, -1509, -1509,
   -1509,   957, -1509, -1509, -1509, -1509, -1509,  -917, -1509, -1509,
   -1509,  -394,  -370,   952,   255, -1509
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
    1517,   534,   857,  1021,  1326,   419,   419,   419,   423,   631,
     628,  1548,  1549,   615,   616,   624,  1157,  1170,  1385,   737,
      10,    11,  1186,   782,   786,  1253,   884,   888,   891,   893,
     752,   882,   886,    10,    11,  1229,  1644,   952,  1245,  1648,
    1029,   431,  1525,   908,   624,   909,   910,  1580,   911,   624,
     913,   432,   624,   624,   431,   836,   795,    12,   914,   915,
     309,   624,  1022,   624,  1023,   624,   557,   624,   624,   434,
    1190,  1160,  1160,  1216,   435,   624,   624,  1735,  1217,   756,
    1708,  1106,   434,   313,   624,   630,  1023,  1218,   819,  -169,
     624,   457,  1678,   458,  1219,  1056,  1220,   757,   820,   610,
     612,   635,   590,   633,   591,  1221,   436,   437,  1123,  1247,
    1160,   419,   624,   624,  1703,  1024,  1747,   624,   624,   820,
     748,  1022,  1270,   635,   427,   428,   694,   429,   430,  -170,
     624,   587,  1222,   594,  1561,   595,   631,  1254,  1023,    81,
     631,   469,   624,   684,  1228,   433,   700,   632,  1181,   703,
     127,  1210,   635,    92,   756,  1283,   466,   685,   459,  1193,
     635,  1566,   726,   460,  1160,  1182,   467,  1736,  1211,   624,
    1679,  1562,   757,   624,  1058,   821,  1057,  1160,   106,   624,
    1672,   716,  1134,   635,   635,  1135,   634,  1709,   425,  1462,
    1792,   592,   635,   468,   696,   727,  1319,  1320,   635,  1496,
    1099,  1368,  1030,   624,   309,   309,   127,  1499,   309,  1107,
     461,  1137,  1137,  1258,  1316,   649,   624,   624,  1506,  1269,
     635,   635,   596,   624,   837,   635,   635,   313,   313,  1015,
    1255,   313,  1486,   890,   892,  1525,   624,  1326,   635,  1031,
     625,   470,  1701,   309,   627,  1100,  1326,   630,   439,  1251,
     635,  1256,   877,  1421,   879,  1769,  1120,  1435,  1122,  1367,
    1223,   827,  1461,   470,   829,  1796,   313,  1187,  1229,  1710,
    1558,  1284,  1039,   631,   632,  -169,   702,   635,   632,   704,
     535,   635,   442,   882,   886,  1497,   470,   635,  1136,  1391,
     443,   978,  1321,  1160,   535,   749,   470,   758,   444,  1133,
    1061,  1062,  1805,   750,  1808,  1110,  1312,   874,   440,   761,
     947,   635,  1322,   781,  1323,  -170,   588,   624,   535,   779,
    1496,  1567,  1568,  1440,   635,   635,   624,   873,  1176,   792,
     535,   635,   535,  1250,   624,  1056,   803,   804,  1470,  1391,
    1760,  1044,  1324,  1091,   635,   810,   113,  1496,   624,   441,
     883,   887,  1224,  1225,  1226,   878,   880,  1313,  1051,  1481,
     903,  1040,  1392,   125,  1043,   895,  1023,  1314,   773,   426,
     309,   947,  1363,   876,   309,    10,    11,  1228,  1597,  1645,
     597,   675,   599,  1442,  1325,   624,   624,   600,  1774,  1734,
     948,  1743,  1319,   313,  1798,   450,    12,   313,   981,   676,
     982,   309,   151,   309,  1744,  1745,  1634,   424,  1067,   424,
    1016,   632,  1392,  1670,  1160,  1095,  1075,  1617,   624,  1451,
     699,  1086,   705,   484,   313,   635,   313,   834,   835,  1364,
     309,  1790,  1018,  1639,   635,   309,   424,   774,  1160,  1326,
     839,   424,   635,  1598,   983,  1393,  1394,  1646,  1395,  1463,
     716,   949,   753,   313,   755,  1396,   635,  1646,   313,   470,
     867,   869,   629,  1137,   470,  1397,  1138,  1092,  1093,   598,
    1364,   601,  1137,   718,   890,   892,   890,  1398,    81,  1471,
    1036,   801,  1094,  1137,  1113,  1774,   807,   719,  1543,  1319,
    1017,  1506,    92,   635,   635,  1393,  1394,  1180,  1395,  1068,
     485,   453,  1087,  1534,  1387,  1448,  1587,   309,  1322,  1349,
    1323,  1088,  1019,  1070,   309,  1397,  1177,   106,  1775,  1112,
     420,  1369,  1370,  1371,  1177,  1084,   635,  1398,   127,  1102,
     313,  1194,  1195,  1175,  1692,   783,  1198,   313,  1324,  1096,
    1097,   479,  1319,  1320,  1697,  1317,   936,   937,   935,  1319,
    1320,  1204,  1319,   938,  1098,   535,  1427,   309,   535,   454,
    1037,  1160,  1205,   868,   309,   419,  1237,  1554,   486,   487,
    1556,  1791,  1780,  1022,   446,   309,   309,   309,   309,  1069,
     313,  1720,   784,  1089,   631,  1260,   885,   313,  1428,   699,
    1261,   705,  1085,  1071,   309,   984,  1178,   620,   313,   313,
     313,   313,  1117,  1794,  1179,  1322,  1429,  1323,   985,  1262,
     986,  1124,  1318,   621,  1693,  1811,  1121,   313,    12,  1119,
     880,   987,   988,   989,  1698,   990,  1257,   991,  1023,   732,
     678,   733,   732,  1374,   733,  1324,   724,   535,  1321,  1641,
     535,  1188,  1090,   463,   535,  1321,  1160,   535,   535,  1160,
    1263,  1652,  1137,  1188,  1376,   535,  1656,  1499,  1322,   679,
    1323,   535,   535,  1642,   734,  1322,   535,  1323,  1322,  1022,
    1323,  1618,   680,  1319,   535,  1022,  1078,  1079,  1080,  1781,
     869,   535,   535,   535,   535,  1138,  1138,   675,  1324,   535,
    1573,   735,   113,  1780,   735,  1324,   465,   535,  1324,   113,
      81,  1210,  1440,  1779,  1785,   676,   638,   681,  1728,   125,
     639,   885,  1319,  1320,    92,   640,   125,  1046,  1211,  1441,
    1260,   890,  1111,  1072,  1038,  1261,   968,   309,  1612,  1726,
    1519,   675,  1642,   420,   641,  1022,   746,  1524,   699,   106,
     705,   747,   535,  1134,  1118,  1779,  1135,  1551,   151,   676,
     313,  1785,  1239,   736,  1242,   151,   736,   535,   309,   309,
     621,  1212,  1442,  1023,   424,   424,   695,   127,   535,   969,
     675,   638,   677,   720,   970,   639,   488,  1753,   419,  1754,
     640,   313,   313,  1552,  1160,  1682,  1738,   721,   676,  1322,
    1741,  1323,  1683,   490,  1414,  1415,  1732,   850,  1682,   641,
    1814,   489,  1684,   850,  1305,  1683,  1306,   535,  1321,  1065,
    1066,  1751,  1183,  1804,  1373,  1684,  1824,  1416,   309,  1324,
    1642,   536,   722,  1825,   491,  1374,  1357,   492,  1322,  1184,
    1323,  1484,  1160,   642,  1160,  1375,   643,  1642,   723,  1185,
    1642,   313,  1795,   446,   895,   309,  1376,  1642,  1434,   474,
     880,   644,   638,  1290,  1290,   777,   639,  1504,  1324,  1680,
    1681,   640,   113,  1507,   777,  1160,  1493,  1498,   313,  1677,
    1505,  1022,  1787,  1504,  1504,   573,  1508,   645,   707,   125,
     641,   682,  1206,  1374,  1707,  1231,  1651,  1817,  1563,   708,
     683,  1365,  1761,  1207,  1232,  1564,   451,  1160,   642,   452,
    1654,   643,   955,   956,   957,   958,   959,   960,   961,   962,
     963,   964,  1160,   894,  1160,   477,   828,   896,   151,   539,
      10,    11,  1199,  1200,  1201,   738,   739,   740,  1202,   589,
    1544,   427,   428,   954,   429,   430,   535,  1138,   969,  1260,
     478,   431,   645,   970,  1261,   455,  1138,  1333,   456,  1334,
     535,   432,   433,   939,   535,   535,   939,  1138,   475,   939,
     480,   476,   482,   481,  1338,   483,  1339,   697,   698,   434,
    1749,  1750,  1196,  1197,   435,   537,   535,   540,   535,   642,
    1545,  1546,   643,   918,   919,   552,   535,  1707,  1384,   535,
    1482,   551,   553,   535,   925,   926,   554,  1540,   927,   928,
    1446,  1447,  1694,  1695,   574,   649,   436,   437,   438,   575,
     582,   583,   584,   309,   586,   572,   593,   602,   606,   424,
     603,   604,   607,   645,   605,   617,   637,   578,   613,   581,
     654,   655,   673,   674,  1707,   535,   313,   686,   656,   687,
     689,  1630,   688,  1793,   716,   699,   657,   658,   709,   659,
     710,   693,   711,   728,   730,   439,   712,   660,   731,   741,
    1358,   661,   745,   662,  1301,   754,   771,   777,   663,   768,
     309,   309,   309,   446,   769,   535,   780,   788,   789,   790,
     791,   802,   808,  1359,   809,   664,   452,   815,   456,   476,
     819,   481,   817,   313,   313,   313,   830,   838,   492,   822,
     823,   841,   824,   826,   535,   851,  1835,  1673,  1836,   665,
     666,   667,   668,   669,   670,   440,   859,   840,  1844,   881,
     870,   899,   860,   900,   901,   916,  1138,   864,   902,   929,
     930,   931,   932,   608,   535,   535,   535,   535,   944,   865,
     950,   951,   953,   975,   976,   979,   980,  1001,  1002,  1003,
    1005,  1010,  1011,  1007,  1012,  1020,   441,  1035,  1013,  1042,
    1014,  1041,  1045,  1052,  1053,  1054,  1055,  1119,  1063,  1060,
    1064,  1108,  1101,   535,   451,   455,   475,   480,   491,  1126,
    1109,  1104,   442,  1105,  1103,  1455,  1116,   535,   309,  1130,
     443,  1189,   970,  1022,   420,  1208,  1209,  1235,   444,  1236,
    1238,  1230,  1246,  1248,  1252,  1259,   773,  1272,  1274,  1278,
    1273,   313,   535,  1636,  1285,  1275,  1279,  1280,  1286,  1289,
    1290,   535,  1296,   535,   309,   535,  1302,   535,  1303,  1304,
    1309,  1308,  1489,  1311,  1315,   309,  1332,  1350,  1360,   419,
     535,   420,   734,  1331,  1381,  1383,  1388,   313,  1411,  1407,
    1419,  1511,  1408,  1420,   309,  1431,   903,  1422,   313,    12,
     420,  1423,  1424,  1425,  1426,  1439,  1438,  1444,  1450,  1449,
    1453,  1454,  1458,   535,   309,   535,  1466,   313,  1456,  1457,
     424,   309,  1459,  1460,  1468,  1485,   419,   424,  1472,  1474,
    1475,  1476,  1480,  1488,  1510,  1504,  1512,   313,  1518,  1521,
    1516,  1528,  1529,  1513,   313,   419,  1532,  1527,  1537,  1536,
     850,  1533,  1530,  1358,  1538,  1539,  1576,  1363,  1374,   868,
    1531,  1557,  1583,  1577,  1596,  1522,  1589,  1590,  1602,  1605,
    1560,  1581,  1526,  1591,   725,   535,  1359,   729,  1609,  1607,
    1592,   578,  1593,  1718,   743,   744,  1615,  1594,  1570,  1595,
    1611,  1620,   578,  1627,  1722,  1636,   535,  1724,   764,   767,
    1613,  1628,  1629,   767,  1632,  1733,  1675,  1633,  1638,  1649,
    1650,   787,  1655,  1658,  1676,  1688,  1663,  1690,   578,   796,
     797,   800,  1699,  1691,  1689,  1210,   806,  1712,  1704,  1715,
    1717,  1667,  1668,  1669,   813,  1723,  1551,  1755,  1756,  1740,
    1758,  1757,  1759,  1763,  1764,  1768,  1770,  1771,  1772,  1789,
    1786,  1711,  1802,  1788,  1809,  1801,  1810,  1813,  1837,  1834,
    1816,   618,  1821,  1826,  1827,  1841,   619,   977,  1840,  1437,
    1799,  1819,  1828,   622,  1838,  1191,  1831,   715,  1833,   814,
     751,  1271,  1452,  1766,  1797,  1115,   770,   309,  1724,   535,
    1843,  1268,  1625,   535,   800,  1555,  1050,  1479,  1372,  1550,
    1547,   816,  1490,  1500,  1494,   825,  1509,   906,   535,   907,
     313,   917,   946,  1174,  1520,  1082,  1815,   535,   692,  1812,
     759,  1243,   760,  1436,  1535,  1542,  1541,  1806,  1571,  1687,
    1358,   535,  1575,  1386,  1574,  1686,  1410,  1215,  1604,  1445,
    1696,   535,  1572,   855,   863,  1482,     0,     0,     0,     0,
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
     114,   115,   116,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,     0,   126,   127,
       0,     0,   128,   129,   130,     0,     0,     0,   131,     0,
     132,   133,     0,   134,   135,     0,   136,     0,   137,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,     0,     0,   149,   150,   151,     0,   417,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,     0,   246,     0,   247,   248,   249,   250,
     251,   252,   253,  -165,   885,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,    12,     0,     0,     0,   889,   415,     0,
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
       0,   112,   113,   114,   115,   116,     0,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
       0,   126,   127,     0,     0,   128,   129,   130,     0,     0,
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
     240,   241,   242,   243,   244,   245,   885,   246,     0,   247,
     248,   249,   250,   251,   252,   253,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,    12,     0,     0,     0,   414,
     415,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   416,    29,    30,    31,    32,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     0,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    71,    72,    73,    74,    75,     0,    76,    77,    78,
       0,     0,    79,    80,     0,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     0,     0,
       0,    92,     0,    93,    94,    95,    96,     0,    97,     0,
       0,     0,    98,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     110,   111,     0,   112,   113,   114,   115,   116,     0,     0,
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
     238,   239,   240,   241,   242,   243,   244,   245,   885,   246,
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
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,     0,   126,   127,     0,     0,   128,
     129,   130,     0,     0,     0,   131,     0,   132,   133,     0,
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
    -863,   457,     0,   458,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -863,     0,     0,     0,  -863,     0,     0,
       0,  -863,  -863,     0,     0,     0,     0,  -863,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   459,     0,
       0,  -863,     0,   460,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -863,     0,  -863,  -863,  -863,     0,
       0,  -863,  -863,  -863,  -863,     0,     0,     0,  -863,  -863,
       0,     0,     0,     0,     0,  -863,     0,     0,  -863,  -863,
     461,     0,     0,  -863,     0,     0,     0,     0,  -863,  -863,
       0,     0,     0,     0,  -863,     0,     0,     0,  -863,     0,
       0,     0,  -863,  -863,     0,  -863,     0,  -863,  -863,     0,
       0,     0,  -863,  -863,     0,     0,  -863,  -863,  -863,  -863,
    -863,  -863,     0,     0,  -863,     0,     0,     0,     0,  -863,
    -863,     0,     0,  -863,     0,     0,     0,     0,  -863,     0,
       0,  -863,     0,     0,     0,     0,  -863,  -863,  -863,  -863,
    -863,     0,  -863,  -863,  -863,  -863,  -863,     0,     0,     0,
       0,  -863,  -863,  -863,     0,  -863,  -863,  -863,  -863,  -863,
    -863,     0,  -863,     0,  -863,     0,     0,     0,     0,  -863,
    -863,  -863,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -863,     0,  -863,     0,  -863,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -863,     0,     0,     0,     0,  -863,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    12,  -863,     0,  -863,    13,    14,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     0,    34,
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
     112,   113,   114,   115,   116,     0,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,     0,
     126,   127,     0,     0,   128,   129,   130,     0,     0,     0,
     131,     0,   132,   133,     0,   134,   135,     0,   136,     0,
     137,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,     0,     0,   149,   150,   151,     0,   152,
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
     249,   250,   251,   252,   253,   254,   255,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,    12,     0,     0,     0,
      13,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
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
     246,     0,   247,   248,   249,   250,   251,   252,   253,     0,
     614,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
      12,     0,     0,     0,   414,   415,     0,    15,    16,    17,
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
     114,   115,   116,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,     0,   126,   127,
       0,     0,   128,   129,   130,     0,   555,     0,   131,     0,
     132,   133,     0,   134,   135,     0,   136,     0,   137,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,     0,     0,   149,   150,   151,     0,   417,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,     0,   246,     0,   247,   248,   249,   250,
     251,   252,   253,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    12,     0,     0,     0,   414,   415,     0,    15,
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
     112,   113,   114,   115,   116,     0,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,     0,
     126,   127,     0,     0,   128,   129,   130,     0,   818,     0,
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
      24,    25,    26,  1353,   416,    29,    30,    31,    32,    33,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,     0,    47,    48,    49,  1354,  1355,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,    72,    73,    74,    75,     0,    76,    77,    78,     0,
       0,    79,    80,     0,     0,     0,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
      92,     0,    93,    94,    95,    96,     0,    97,     0,     0,
       0,    98,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   110,
     111,     0,   112,   113,   114,   115,   116,     0,     0,     0,
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
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,     0,   126,   127,     0,     0,   128,   129,
     130,     0,     0,     0,   131,     0,   132,   133,     0,   134,
     135,     0,   136,     0,   137,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,     0,     0,   149,
     150,   151,     0,   417,   153,   154,   155,   156,   157,   158,
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
     116,     0,     0,     0,     0,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,     0,   126,   127,     0,     0,
     128,   129,   130,     0,     0,     0,   131,     0,   132,   133,
       0,   134,   135,     0,   136,     0,   137,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,     0,
       0,   149,   150,   151,     0,   152,   153,   154,   155,   156,
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
     114,   115,   116,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,     0,   126,   127,
       0,     0,   128,   129,   130,     0,     0,     0,   131,     0,
     132,   133,     0,   134,   135,     0,   136,     0,   137,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,     0,     0,   149,   150,   151,     0,   417,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,     0,   246,     0,   247,   248,   249,   250,
     251,   252,   253,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    12,     0,     0,     0,    13,   415,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     0,    34,
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
     112,   113,   114,   115,   116,     0,     0,     0,     0,   117,
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
     241,   242,   243,   244,   245,     0,   246,     0,   247,   248,
     249,   250,   251,   252,   253,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,     0,    12,     0,     0,     0,   889,   415,
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
       0,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,     0,   126,   127,     0,     0,   128,   129,   130,     0,
       0,     0,   131,     0,   132,   133,     0,   134,   135,     0,
     136,     0,   137,     0,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,     0,     0,   149,   150,   151,
       0,   417,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
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
       0,     0,   940,     0,   103,   104,   105,   106,   107,   108,
     109,   564,   111,     0,   112,   113,   114,   115,   116,     0,
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,     0,   126,   127,     0,     0,   128,   129,
     130,     0,     0,     0,   131,   941,   132,   133,     0,   134,
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
     246,     0,   247,   248,   249,   250,   251,   252,   253,     1,
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
       0,     0,     0,     0,   940,     0,   103,   104,   105,   106,
     107,   108,   109,   564,   111,     0,   112,   113,   114,   115,
     116,     0,     0,     0,     0,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,     0,   126,   127,     0,     0,
     128,   129,   130,     0,     0,     0,   131,   945,   132,   133,
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
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
      12,     0,     0,     0,   414,   415,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,  1353,
     416,    29,    30,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
       0,    47,    48,    49,  1354,  1355,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,    71,    72,    73,    74,
      75,     0,    76,    77,    78,     0,     0,    79,    80,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,    92,     0,    93,    94,
      95,    96,     0,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     0,   112,   113,
     114,   115,   116,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,     0,   126,   127,
       0,     0,   128,   129,   130,     0,     0,     0,   131,     0,
     132,   133,     0,   134,   135,     0,   136,     0,   137,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,     0,     0,   149,   150,   151,     0,   417,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,  1356,   182,   183,   184,
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
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     103,   104,   105,   106,   107,   108,   109,   564,   111,     0,
     112,   113,   114,   115,   116,     0,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,     0,
     126,   127,     0,     0,   128,   129,   130,     0,     0,   565,
     131,     0,   132,   133,     0,   134,   135,     0,   136,     0,
     137,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,     0,     0,   149,   150,   151,     0,   417,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   528,   529,   530,   178,   179,   531,   566,   182,
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
     237,   238,   239,   240,   241,   242,   243,   244,   245,   609,
     246,     0,   247,   248,   249,   250,   251,   252,   253,     1,
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
     116,     0,     0,     0,     0,   117,   118,   119,   120,   121,
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
     245,     0,   246,   611,   247,   248,   249,   250,   251,   252,
     253,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,     0,     0,     0,
      12,     0,     0,     0,   414,   415,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   560,
     416,    29,    30,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
       0,    47,    48,    49,   561,   562,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,    71,    72,    73,    74,
      75,     0,    76,    77,    78,     0,     0,    79,    80,     0,
       0,     0,    81,    82,   510,    84,    85,    86,    87,    88,
     563,    90,    91,     0,     0,     0,    92,     0,    93,    94,
      95,    96,     0,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   564,   111,     0,   112,   113,
     114,   115,   116,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,     0,   126,   127,
       0,     0,   128,   129,   130,     0,   934,     0,   131,     0,
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
      99,   100,   101,   102,     0,     0,     0,     0,  1432,     0,
     103,   104,   105,   106,   107,   108,   109,   564,   111,     0,
     112,   113,   114,   115,   116,     0,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,     0,
     126,   127,     0,     0,   128,   129,   130,     0,     0,     0,
     131,     0,   132,   133,     0,   134,   135,     0,   136,     0,
     137,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,     0,     0,   149,   150,   151,     0,   417,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   528,   529,   530,   178,   179,   531,   566,   182,
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
      24,   496,    26,   498,   416,    29,   499,    31,    32,    33,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,   501,     0,    47,    48,    49,   503,   504,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,    72,    73,    74,    75,     0,    76,    77,    78,     0,
       0,    79,    80,     0,     0,     0,    81,    82,   510,    84,
      85,    86,    87,    88,   563,    90,    91,     0,     0,     0,
      92,     0,    93,    94,    95,    96,     0,    97,     0,     0,
       0,   513,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   564,
     111,     0,   112,   113,   690,   115,   116,     0,     0,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,     0,   691,   127,     0,     0,   128,   129,   130,     0,
       0,     0,   131,     0,   132,   133,     0,   134,   135,     0,
     136,     0,   137,     0,   138,   139,   140,   141,   142,   143,
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
     246,     0,   247,   248,   249,   250,   251,   252,   253,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,     0,     0,     0,    12,     0,
       0,     0,   414,   415,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   496,    26,   498,   416,    29,
     499,    31,    32,    33,     0,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,   501,     0,    47,
      48,    49,   503,   504,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,    71,    72,    73,    74,    75,     0,
      76,    77,    78,     0,     0,    79,    80,     0,     0,     0,
      81,    82,   510,    84,    85,    86,    87,    88,   563,    90,
      91,     0,     0,     0,    92,     0,    93,    94,    95,    96,
       0,    97,     0,     0,     0,   513,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   564,   111,     0,   112,   113,   114,   115,
     116,     0,     0,     0,     0,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,     0,   126,   127,     0,     0,
     128,   129,   130,     0,     0,     0,   131,     0,   132,   133,
       0,   134,   135,     0,   136,     0,   137,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,     0,
       0,   149,   150,   151,     0,   417,   153,   154,   155,   156,
     157,   158,   159,   160,   523,   162,   524,   164,   525,   526,
     167,   168,   169,   170,   171,   172,   527,   174,   528,   529,
     530,   178,   179,   531,   532,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,     0,   195,
     196,   197,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,     0,   246,     0,   247,   533,   249,   250,   251,   252,
     253,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,     0,     0,     0,
      12,     0,     0,     0,   414,   415,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   496,    26,   498,
     416,    29,   499,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,   501,
       0,    47,    48,    49,   503,   504,    52,   505,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,    71,    72,    73,    74,
      75,     0,    76,    77,    78,     0,     0,    79,    80,     0,
       0,     0,    81,    82,   510,    84,    85,    86,    87,    88,
     563,    90,    91,     0,     0,     0,    92,     0,    93,    94,
      95,    96,     0,    97,     0,     0,     0,   513,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   564,   111,     0,   112,   113,
       0,   115,   116,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,     0,     0,     0,
       0,     0,   128,   129,   130,     0,     0,     0,   131,     0,
     132,   133,     0,   134,   135,     0,   136,     0,   137,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,     0,     0,   149,   150,   151,     0,   417,   153,   154,
     155,   156,   157,   158,   159,   160,   523,   162,   524,   164,
     525,   526,   167,   168,   169,   170,   171,   172,   527,   174,
     528,   529,   530,   178,   179,   531,   532,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,     0,   246,     0,   247,   533,   249,   250,
     251,   252,   253,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,     0,
       0,     0,    12,     0,     0,     0,   414,   415,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   496,
      26,   498,   416,    29,   499,    31,    32,    33,     0,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,   501,     0,    47,    48,    49,   503,   504,    52,   505,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,    71,    72,
      73,    74,    75,     0,    76,    77,    78,     0,     0,    79,
      80,     0,     0,     0,    81,    82,   510,    84,    85,    86,
      87,    88,   563,    90,    91,     0,     0,     0,    92,     0,
      93,    94,    95,    96,     0,    97,     0,     0,     0,   513,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     103,   104,   105,   106,   107,   108,   109,   564,   111,     0,
     112,   113,     0,   115,   116,     0,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   124,     0,   125,     0,
       0,     0,     0,     0,   128,   129,   130,     0,     0,     0,
     131,     0,   132,   133,     0,     0,     0,     0,   136,     0,
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
       0,   513,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,     0,   108,   109,   564,
     111,     0,   112,   113,     0,   115,   116,     0,     0,     0,
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
       0,     0,     0,   117,   118,   119,   120,   517,   122,   123,
     518,     0,     0,     0,     0,     0,     0,     0,   519,   520,
     130,     0,     0,     0,   131,     0,   132,   521,     0,     0,
       0,     0,   136,     0,   137,     0,   138,   139,   140,   141,
     522,   143,   144,   145,   146,   147,   148,     0,     0,   149,
     150,     0,     0,   417,   153,   154,   155,   156,   157,   158,
     159,   160,   523,   162,   524,   164,   525,   526,   167,   168,
     169,   170,   171,   172,   527,   174,   528,   529,   530,   178,
     179,   531,   532,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     0,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,     0,     0,
       1,     2,   247,   533,   249,   250,   251,   252,   253,     3,
       0,     0,     0,     0,     8,     9,     0,     0,     0,     0,
       0,     0,     0,   414,   415,     0,    15,    16,    17,   541,
      19,    20,    21,   494,   542,   543,   496,   497,   498,   416,
      29,   499,    31,   544,    33,     0,    34,    35,    36,    37,
     545,    39,   546,   547,    42,    43,    44,    45,   501,     0,
      47,   548,    49,   503,   504,    52,   505,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,   506,   507,    70,     0,    71,    72,    73,   549,     0,
       0,    76,    77,    78,     0,     0,   509,    80,     0,     0,
       0,     0,    82,   510,    84,   511,   512,    87,    88,     0,
       0,     0,     0,     0,     0,     0,     0,    93,    94,    95,
      96,     0,    97,     0,     0,     0,   513,    99,   100,   514,
     515,     0,     0,     0,     0,     0,     0,   103,   104,   105,
       0,   107,   108,   109,     0,     0,     0,     0,     0,     0,
     115,   516,     0,     0,     0,     0,   117,   118,   119,   120,
     517,   122,   123,   518,     0,     0,     0,     0,     0,     0,
       0,   519,   520,   130,     0,     0,     0,   131,     0,   132,
     521,     0,     0,     0,     0,   136,     0,   137,     0,   138,
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
     244,     0,     0,   576,     0,   247,   533,   249,   250,   251,
     252,   253,     8,     9,     0,     0,     0,   793,     0,     0,
       0,   414,   415,     0,    15,    16,    17,   541,    19,    20,
      21,   494,   542,   543,   496,   497,   498,   416,    29,   499,
      31,   544,    33,     0,    34,    35,    36,    37,   545,    39,
     546,   547,    42,    43,    44,    45,   501,     0,    47,   548,
      49,   503,   504,    52,   505,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,   506,
     507,    70,     0,    71,    72,    73,   549,     0,     0,    76,
      77,    78,     0,     0,   509,    80,     0,     0,     0,     0,
      82,   510,    84,   511,   512,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    95,    96,     0,
      97,     0,     0,     0,   513,    99,   100,   514,   515,     0,
       0,     0,     0,     0,     0,   103,   104,   105,     0,   107,
     108,   109,     0,     0,     0,     0,     0,     0,   115,   516,
       0,     0,     0,     0,   117,   118,   119,   120,   517,   122,
     123,   518,     0,     0,     0,     0,     0,     0,     0,   519,
     520,   130,     0,     0,     0,   131,   794,   132,   521,     0,
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
       0,   576,     0,   247,   533,   249,   250,   251,   252,   253,
       8,     9,     0,     0,     0,     0,     0,     0,     0,   414,
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
       0,   247,   533,   249,   250,   251,   252,   253,   579,   580,
       0,     0,     0,     0,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,   414,   415,     0,    15,    16,    17,
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
       0,   115,   516,     0,     0,     0,     0,   117,   118,   119,
     120,   517,   122,   123,   518,     0,     0,     0,     0,     0,
       0,     0,   519,   520,   130,     0,     0,     0,   131,     0,
     132,   521,     0,     0,     0,     0,     0,     0,   137,     0,
     138,   139,   140,   141,   522,   143,   144,   145,   146,   147,
     148,     0,     0,   149,   150,     0,     0,   417,   153,   154,
     155,   156,   157,   158,   159,   160,   523,   550,   524,   164,
     525,   526,   167,   168,   169,   170,   171,   172,   527,   174,
     528,   529,   530,   178,   179,   531,   532,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,     0,     0,     0,   247,   533,   249,   250,
     251,   252,   253,     4,     5,     6,     7,     8,     9,     0,
       0,     0,    12,     0,     0,     0,   414,   415,     0,    15,
      16,    17,   844,    19,    20,    21,    22,     0,   845,   496,
      26,     0,   416,    29,   499,    31,     0,    33,     0,    34,
      35,    36,    37,   846,    39,     0,     0,    42,    43,    44,
      45,   501,     0,    47,   847,    49,     0,     0,    52,   505,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,   506,   507,    70,     0,    71,    72,
      73,   848,     0,     0,    76,    77,    78,     0,     0,   509,
      80,     0,     0,     0,    81,    82,   510,    84,   511,   512,
      87,    88,   563,    90,     0,     0,     0,     0,    92,     0,
      93,    94,    95,    96,     0,    97,     0,     0,     0,   513,
      99,   100,   514,   515,     0,     0,     0,     0,     0,     0,
     103,   104,   105,   106,   107,   108,     0,   564,   111,     0,
     112,   113,     0,   115,   116,     0,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,   518,     0,   125,     0,
       0,     0,     0,     0,   519,   520,   130,     0,     0,     0,
     131,     0,   132,   521,     0,     0,     0,     0,     0,     0,
     137,     0,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,     0,     0,     0,   150,   151,     0,   417,
     153,   154,   155,   156,   157,   158,   159,   160,   523,     0,
     524,   164,   525,   526,   167,   168,   169,   170,   171,   172,
     527,   174,   528,   529,   530,   178,   179,     0,   532,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,     0,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,     0,   246,     0,   247,   533,
     249,   250,   251,   252,   253,     8,     9,     0,     0,     0,
       0,     0,     0,     0,   414,   415,     0,    15,    16,    17,
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
       0,   115,   516,     0,     0,     0,     0,   117,   118,   119,
     120,   517,   122,   123,   518,     0,     0,     0,     0,     0,
       0,     0,   519,   520,   130,     0,     0,     0,   131,  1585,
     132,   521,     0,     0,     0,     0,  1586,     0,   137,     0,
     138,   139,   140,   141,   522,   143,   144,   145,   146,   147,
     148,     0,     0,  1152,   150,     0,     0,   417,   153,   154,
     155,   156,   157,   158,   159,   160,   523,   162,   524,   164,
     525,   526,   167,   168,   169,   170,   171,   172,   527,   174,
     528,   529,   530,   178,   179,   531,   532,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,     0,     8,     9,   247,   533,   249,  1153,
    1154,  1155,  1156,   414,   415,     0,    15,    16,    17,   541,
      19,    20,    21,   494,   542,   543,   496,   497,   498,   416,
      29,   499,    31,   544,    33,     0,    34,    35,    36,    37,
     545,    39,   546,   547,    42,    43,    44,    45,   501,     0,
      47,   548,    49,   503,   504,    52,   505,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,   506,   507,    70,     0,    71,    72,    73,   549,     0,
       0,    76,    77,    78,     0,     0,   509,    80,     0,     0,
       0,     0,    82,   510,    84,   511,   512,    87,    88,     0,
       0,     0,     0,     0,     0,     0,     0,    93,    94,    95,
      96,     0,    97,     0,     0,     0,   513,    99,   100,   514,
     515,     0,     0,     0,     0,     0,     0,   103,   104,   105,
       0,   107,   108,   109,     0,     0,     0,     0,     0,     0,
     115,   516,     0,     0,     0,     0,   117,   118,   119,   120,
     517,   122,   123,   518,     0,     0,     0,     0,     0,     0,
       0,   519,   520,   130,     0,     0,     0,   131,   762,   132,
     521,     0,     0,     0,     0,   763,     0,   137,     0,   138,
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
     252,   253,   414,   415,     0,    15,    16,    17,   541,    19,
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
     516,     0,     0,     0,     0,   117,   118,   119,   120,   517,
     122,   123,   518,     0,     0,     0,     0,     0,     0,     0,
     519,   520,   130,     0,     0,     0,   131,   811,   132,   521,
       0,     0,     0,     0,   812,     0,   137,     0,   138,   139,
     140,   141,   522,   143,   144,   145,   146,   147,   148,     0,
       0,   149,   150,     0,     0,   417,   153,   154,   155,   156,
     157,   158,   159,   160,   523,   550,   524,   164,   525,   526,
     167,   168,   169,   170,   171,   172,   527,   174,   528,   529,
     530,   178,   179,   531,   532,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,     0,   195,
     196,   197,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
       0,     0,     8,     9,   247,   533,   249,   250,   251,   252,
     253,   414,   415,     0,    15,    16,    17,   493,    19,    20,
      21,   494,    23,   495,   496,  1149,   498,   416,    29,   499,
      31,    32,    33,     0,    34,    35,    36,    37,   500,    39,
      40,    41,    42,    43,    44,    45,   501,     0,    47,   502,
      49,   503,   504,    52,   505,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,   506,
     507,    70,     0,    71,    72,    73,   508,     0,     0,    76,
      77,    78,     0,     0,   509,    80,     0,     0,     0,     0,
      82,   510,    84,   511,   512,    87,    88,  1501,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    95,    96,     0,
      97,     0,     0,     0,   513,    99,   100,   514,   515,     0,
       0,     0,     0,     0,     0,   103,   104,   105,     0,   107,
     108,  1150,     0,     0,     0,  1151,     0,     0,   115,   516,
       0,     0,     0,     0,   117,   118,   119,   120,   517,   122,
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
       0,     0,     0,   117,   118,   119,   120,   517,   122,   123,
     518,     0,     0,     0,     0,     0,     0,     0,   519,   520,
     130,     0,     0,     0,   131,     0,   132,   521,     0,     0,
       0,     0,     0,     0,   137,     0,   138,   139,   140,   141,
     522,   143,   144,   145,   146,   147,   148,     0,     0,  1152,
     150,     0,     0,   417,   153,   154,   155,   156,   157,   158,
     159,   160,   523,   162,   524,   164,   525,   526,   167,   168,
     169,   170,   171,   172,   527,   174,   528,   529,   530,   178,
     179,   531,   532,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     0,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,     0,     0,
       8,     9,   247,   533,   249,  1153,  1154,  1155,  1156,   414,
     415,     0,    15,    16,    17,   493,    19,    20,    21,   494,
      23,   495,   496,  1149,   498,   416,    29,   499,    31,    32,
      33,     0,    34,    35,    36,    37,   500,    39,    40,    41,
      42,    43,    44,    45,   501,     0,    47,   502,    49,   503,
     504,    52,   505,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,   506,   507,    70,
       0,    71,    72,    73,   508,     0,     0,    76,    77,    78,
       0,     0,   509,    80,     0,     0,     0,     0,    82,   510,
      84,   511,   512,    87,    88,  1647,     0,     0,     0,     0,
       0,     0,     0,    93,    94,    95,    96,     0,    97,     0,
       0,     0,   513,    99,   100,   514,   515,     0,     0,     0,
       0,     0,     0,   103,   104,   105,     0,   107,   108,  1150,
       0,     0,     0,  1151,     0,     0,   115,   516,     0,     0,
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
     511,   512,    87,    88,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,     0,    97,     0,     0,
       0,   513,    99,   100,   514,   515,     0,     0,     0,     0,
       0,     0,   103,   104,   105,     0,   107,   108,  1150,     0,
       0,     0,  1151,     0,     0,   115,   516,     0,     0,     0,
       0,   117,   118,   119,   120,   517,   122,   123,   518,     0,
       0,     0,     0,     0,     0,     0,   519,   520,   130,     0,
       0,     0,   131,     0,   132,   521,     0,     0,     0,     0,
       0,     0,   137,     0,   138,   139,   140,   141,   522,   143,
     144,   145,   146,   147,   148,     0,     0,  1152,   150,     0,
       0,   417,   153,   154,   155,   156,   157,   158,   159,   160,
     523,   162,   524,   164,   525,   526,   167,   168,   169,   170,
     171,   172,   527,   174,   528,   529,   530,   178,   179,   531,
     532,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,     0,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,     0,     0,     8,     9,
     247,   533,   249,  1153,  1154,  1155,  1156,   414,   415,     0,
      15,    16,    17,   493,    19,    20,    21,   494,    23,   495,
     496,  1149,   498,   416,    29,   499,    31,    32,    33,     0,
      34,    35,    36,    37,   500,    39,    40,    41,    42,    43,
      44,    45,   501,     0,    47,   502,    49,   503,   504,    52,
     505,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,   506,   507,    70,     0,    71,
      72,    73,   508,     0,     0,    76,    77,    78,     0,     0,
     509,    80,     0,     0,     0,     0,    82,   510,    84,   511,
     512,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    95,    96,     0,    97,     0,     0,     0,
     513,    99,   100,   514,   515,     0,     0,     0,     0,     0,
       0,   103,   104,   105,     0,   107,   108,  1150,     0,     0,
       0,  1151,     0,     0,   115,   516,     0,     0,     0,     0,
     117,   118,   119,   120,   517,   122,   123,   518,     0,     0,
       0,     0,     0,     0,     0,   519,   520,   130,     0,     0,
       0,   131,     0,   132,   521,     0,     0,     0,     0,     0,
       0,   137,     0,   138,   139,   140,   141,   522,   143,   144,
     145,   146,   147,   148,     0,     0,   149,   150,     0,     0,
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
      87,    88,  1244,     0,     0,     0,     0,     0,     0,     0,
      93,    94,    95,    96,     0,    97,     0,     0,     0,   513,
      99,   100,   514,   515,     0,     0,     0,     0,     0,     0,
     103,   104,   105,     0,   107,   108,   109,     0,     0,     0,
       0,     0,     0,   115,   516,     0,     0,     0,     0,   117,
     118,   119,   120,   517,   122,   123,   518,     0,     0,     0,
       0,     0,     0,     0,   519,   520,   130,     0,     0,     0,
     131,     0,   132,   521,     0,     0,     0,     0,     0,     0,
     137,     0,   138,   139,   140,   141,   522,   143,   144,   145,
     146,   147,   148,     0,     0,   149,   150,     0,     0,   417,
     153,   154,   155,   156,   157,   158,   159,   160,   523,   550,
     524,   164,   525,   526,   167,   168,   169,   170,   171,   172,
     527,   174,   528,   529,   530,   178,   179,   531,   532,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,     0,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,     0,     0,     8,     9,   247,   533,
     249,   250,   251,   252,   253,   414,   415,     0,    15,    16,
      17,   541,    19,    20,    21,   494,   542,   543,   496,   497,
     498,   416,    29,   499,    31,   544,    33,     0,    34,    35,
      36,    37,   545,    39,   546,   547,    42,    43,    44,    45,
     501,     0,    47,   548,    49,   503,   504,    52,   505,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,   506,   507,    70,     0,    71,    72,    73,
     549,     0,     0,    76,    77,    78,     0,     0,   509,    80,
       0,     0,     0,     0,    82,   510,    84,   511,   512,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    96,     0,    97,     0,     0,     0,   513,    99,
     100,   514,   515,     0,     0,     0,     0,     0,     0,   103,
     104,   105,     0,   107,   108,   109,     0,     0,     0,     0,
       0,     0,   115,   516,     0,     0,     0,     0,   117,   118,
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
     242,   243,   244,     0,     0,     8,     9,   247,   533,   249,
     250,   251,   252,   253,   414,   415,     0,    15,    16,    17,
       0,    19,    20,    21,   494,     0,     0,   496,   497,     0,
     416,    29,   499,    31,     0,    33,     0,    34,    35,    36,
      37,     0,    39,     0,     0,    42,    43,    44,    45,   501,
       0,    47,     0,    49,     0,     0,    52,   505,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,   506,   507,    70,     0,    71,    72,    73,     0,
       0,     0,    76,    77,    78,     0,     0,   509,    80,     0,
       0,     0,     0,    82,   510,    84,   511,   512,    87,    88,
       0,     0,     0,     0,     0,     0,     0,     0,    93,    94,
      95,    96,     0,    97,     0,     0,     0,   513,    99,   100,
     514,   515,     0,     0,     0,     0,     0,     0,   103,   104,
     105,     0,   107,   108,     0,     0,     0,     0,     0,     0,
       0,   115,   516,     0,     0,     0,     0,   117,   118,   119,
     120,   517,   122,   123,   518,     0,     0,     0,     0,     0,
       0,     0,   519,   520,   130,     0,     0,     0,   131,     0,
     132,   521,     0,     0,     0,     0,     0,     0,   137,     0,
     138,   139,   140,   141,   522,   143,   144,   145,   146,   147,
     148,     0,     0,     0,   150,     0,     0,   417,   153,   154,
     155,   156,   157,   158,   159,   160,   523,     0,   524,   164,
     525,   526,   167,   168,   169,   170,   171,   172,   527,   174,
     528,   529,   530,   178,   179,     0,   532,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,     0,     0,     0,   247,   533,   249,   250,
     251,   252,   253
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
    1314,    75,   598,    37,  1085,     4,     5,     6,     7,   293,
     277,  1378,  1379,   254,   255,     1,   929,   930,  1135,   439,
      27,    28,   952,   467,   468,    37,   625,   626,   627,   628,
     450,   625,   626,    27,    28,  1002,  1504,   724,  1020,  1507,
      57,    48,  1327,   656,     1,   658,   659,  1411,   661,     1,
     663,    58,     1,     1,    48,     8,   476,    30,   671,   672,
     110,     1,    96,     1,    98,     1,   110,     1,     1,    76,
     968,   929,   930,    40,    81,     1,     1,    95,    45,    46,
     120,   109,    76,   110,     1,   284,    98,    54,   123,     0,
       1,     1,    53,     3,    61,   109,    63,    64,   109,   245,
     246,   109,   227,   109,   229,    72,   113,   114,   115,  1022,
     968,   110,     1,     1,  1607,   149,  1674,     1,     1,   109,
     114,    96,  1035,   109,    38,    39,   155,    41,    42,     0,
       1,    31,    99,   227,   219,   229,   420,   149,    98,   112,
     424,   120,     1,   138,  1002,    59,   349,   293,   150,   352,
     179,    98,   109,   126,    46,   144,    25,   152,    68,   974,
     109,    98,   171,    73,  1022,   167,    35,   185,   115,     1,
     131,   256,    64,     1,   149,   186,   190,  1035,   151,     1,
    1547,    30,   155,   109,   109,   158,   192,   227,   158,   149,
    1748,   316,   109,    62,   345,   204,     9,    10,   109,   102,
     235,   115,   219,     1,   254,   255,   179,  1294,   258,   237,
     120,  1135,  1136,  1028,  1081,   569,     1,     1,  1517,  1034,
     109,   109,   316,     1,   177,   109,   109,   254,   255,   186,
    1027,   258,  1280,   879,   880,  1520,     1,  1318,   109,   256,
     192,   275,  1606,   293,   192,   235,  1327,   446,   162,  1025,
     109,  1027,   192,  1151,   192,  1723,   192,  1187,   192,   192,
     227,   187,  1244,   275,   189,  1758,   293,   954,  1235,   309,
    1387,  1047,   189,   557,   420,   186,   350,   109,   424,   353,
      75,   109,   289,   877,   878,   188,   275,   109,   261,    98,
     297,   735,   105,  1151,    89,   289,   275,   189,   305,   912,
     189,   189,  1770,   297,  1772,   189,   189,   315,   222,   455,
     109,   109,   125,   162,   127,   186,   216,     1,   113,   465,
     102,   258,   259,    98,   109,   109,     1,   313,   187,   475,
     125,   109,   127,   149,     1,   109,   482,   483,   149,    98,
    1707,   785,   155,    96,   109,   491,   159,   102,     1,   263,
     625,   626,   319,   320,   321,   622,   623,   189,   186,  1272,
     644,   781,   171,   176,   784,   632,    98,   189,   120,   158,
     420,   109,   155,   614,   424,    27,    28,  1235,   138,   120,
     227,   160,   227,   158,   197,     1,     1,   232,     5,   120,
     189,   189,     9,   420,  1761,   162,    30,   424,    56,   178,
      58,   451,   215,   453,   189,   189,   188,   451,   186,   453,
     109,   557,   171,   155,  1272,    96,   190,   149,     1,  1234,
     156,   186,   158,    78,   451,   109,   453,   573,   574,   212,
     480,  1745,   109,   188,   109,   485,   480,   189,  1296,  1520,
     586,   485,   109,   203,   102,   254,   255,   188,   257,  1246,
      30,   189,   451,   480,   453,   264,   109,   188,   485,   275,
     606,   607,   114,  1387,   275,   274,   916,   220,   221,   316,
     212,   316,  1396,   184,  1120,  1121,  1122,   286,   112,  1255,
     109,   480,   235,  1407,  1360,     5,   485,   198,  1364,     9,
     189,  1790,   126,   109,   109,   254,   255,   947,   257,   109,
     155,   155,   186,   239,   155,  1230,  1419,   557,   125,  1105,
     127,   186,   189,   109,   564,   274,   109,   151,   135,   186,
     564,  1120,  1121,  1122,   109,   132,   109,   286,   179,    96,
     557,   975,   976,   186,   109,   115,   980,   564,   155,   220,
     221,   120,     9,    10,   109,   132,   697,   698,   694,     9,
      10,   265,     9,   699,   235,   350,   146,   607,   353,   158,
     189,  1419,   276,   607,   614,   564,  1010,  1382,   223,   224,
     186,   186,    29,    96,   620,   625,   626,   627,   628,   189,
     607,  1629,   162,   133,   868,    55,     1,   614,   178,   156,
      60,   158,   199,   189,   644,   253,   189,    34,   625,   626,
     627,   628,   877,   186,   189,   125,   196,   127,   266,    79,
     268,   895,   199,    50,   189,   135,   883,   644,    30,    34,
     887,   279,   280,   281,   189,   283,   149,   285,    98,    46,
     119,    48,    46,   108,    48,   155,   431,   432,   105,   188,
     435,   965,   192,   158,   439,   105,  1504,   442,   443,  1507,
     120,  1518,  1576,   977,   129,   450,  1523,  1744,   125,   148,
     127,   456,   457,   212,    81,   125,   461,   127,   125,    96,
     127,  1468,   161,     9,   469,    96,   822,   823,   824,   136,
     826,   476,   477,   478,   479,  1135,  1136,   160,   155,   484,
    1398,   108,   159,    29,   108,   155,   158,   492,   155,   159,
     112,    98,    98,  1735,  1736,   178,    43,   196,   188,   176,
      47,     1,     9,    10,   126,    52,   176,   144,   115,   115,
      55,  1367,   868,   144,   777,    60,    96,   777,  1453,  1642,
     197,   160,   212,   777,    71,    96,   139,   197,   156,   151,
     158,   144,   537,   155,    34,  1777,   158,   108,   215,   178,
     777,  1783,  1016,   170,  1018,   215,   170,   552,   808,   809,
      50,   158,   158,    98,   808,   809,  1137,   179,   563,   139,
     160,    43,   201,   184,   144,    47,   124,  1690,   777,  1692,
      52,   808,   809,   144,  1642,   271,  1653,   198,   178,   125,
    1657,   127,   278,   124,   249,   250,   188,   592,   271,    71,
     136,   124,   288,   598,  1068,   278,  1070,   602,   105,   808,
     809,   201,   150,   188,    97,   288,   188,   272,   868,   155,
     212,   124,   168,   188,   155,   108,  1110,   158,   125,   167,
     127,  1275,  1690,   170,  1692,   118,   173,   212,   184,   139,
     212,   868,  1755,   889,  1111,   895,   129,   212,   139,   158,
    1117,   188,    43,   102,   102,   155,    47,   102,   155,  1567,
    1568,    52,   159,   102,   155,  1723,   115,   115,   895,  1560,
     115,    96,  1739,   102,   102,   155,   115,   214,   147,   176,
      71,   203,   265,   108,  1609,   301,   115,   115,   270,   158,
     212,  1114,  1707,   276,   310,   277,   155,  1755,   170,   158,
     197,   173,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,  1770,   629,  1772,   158,   188,   633,   215,   124,
      27,    28,   279,   280,   281,   223,   224,   225,   285,   218,
    1374,    38,    39,   728,    41,    42,   731,  1387,   139,    55,
     158,    48,   214,   144,    60,   155,  1396,   234,   158,   236,
     745,    58,    59,   700,   749,   750,   703,  1407,   155,   706,
     155,   158,   158,   158,   234,   158,   236,   193,   194,    76,
    1678,  1679,   130,   131,    81,   120,   771,   124,   773,   170,
     130,   131,   173,   675,   676,   120,   781,  1712,  1134,   784,
    1274,    89,   124,   788,   682,   683,   124,   188,   684,   685,
    1228,  1229,  1597,  1598,   155,  1359,   113,   114,   115,   124,
     124,   124,   124,  1063,   155,   113,   158,   120,   158,  1063,
     243,   243,   155,   214,   244,     0,   192,   125,   316,   127,
     169,    94,   251,   101,  1759,   830,  1063,    51,   134,   202,
     104,  1485,   103,  1751,    30,   156,   142,   143,   186,   145,
     186,   195,   186,    48,   154,   162,   186,   153,   120,   248,
    1110,   157,   306,   159,  1063,   189,   120,   155,   164,   286,
    1120,  1121,  1122,  1119,   286,   870,     1,   120,   144,   109,
     189,   189,   155,  1110,   155,   181,   158,   144,   158,   158,
     123,   158,   186,  1120,  1121,  1122,    36,    17,   158,   158,
     158,    30,   158,   155,   899,   189,  1831,  1551,  1833,   205,
     206,   207,   208,   209,   210,   222,   233,   216,  1843,     3,
     247,   120,   232,   170,   172,    72,  1576,   192,   172,   233,
      96,    96,    96,  1356,   929,   930,   931,   932,   151,   192,
     109,   109,    30,   162,   162,   129,   134,   248,    96,   301,
     144,   134,   186,   120,   186,   109,   263,    96,   189,    46,
     189,    98,    98,   189,   189,   189,   189,    34,   155,   186,
     186,   144,    96,   968,   155,   155,   155,   155,   155,   172,
     192,   227,   289,   233,   239,  1238,   235,   982,  1238,   120,
     297,   134,   144,    96,  1238,    30,   288,    96,   305,   301,
     155,   229,   129,   120,   149,   256,   120,    96,   200,   162,
     186,  1238,  1007,  1497,   155,   134,   134,    98,   120,   149,
     102,  1016,   102,  1018,  1274,  1020,   186,  1022,   186,   155,
     192,   144,  1285,   123,    36,  1285,    30,   120,   247,  1238,
    1035,  1285,    81,   155,   109,   109,   287,  1274,   269,   260,
     158,  1304,   262,   158,  1304,   146,  1540,   158,  1285,    30,
    1304,   158,   158,   158,   158,    30,   288,    30,   308,   289,
     229,   192,   146,  1068,  1324,  1070,   149,  1304,   189,   189,
    1324,  1331,   189,   189,   129,   109,  1285,  1331,   149,   149,
     120,   120,    79,   144,   186,   102,   189,  1324,   134,     7,
     200,   235,   235,   189,  1331,  1304,    98,   192,   158,   188,
    1105,   239,   235,  1363,   158,   158,   149,   155,   108,  1363,
     235,   189,    80,   284,    30,  1324,   189,   189,    30,   273,
     252,   288,  1331,   189,   432,  1130,  1363,   435,   172,   109,
     189,   439,   189,  1627,   442,   443,   149,   189,   252,   189,
     259,   149,   450,   128,  1638,  1639,  1151,  1641,   456,   457,
     186,   128,    98,   461,   186,  1649,   144,   188,   188,   188,
     186,   469,   186,   186,   186,   155,   318,    96,   476,   477,
     478,   479,    30,   189,   282,    98,   484,   172,   189,   149,
      55,  1537,  1538,  1539,   492,    96,   108,    96,    30,   199,
     109,   267,   109,   120,   227,   120,    96,   188,    96,   200,
     199,   289,   227,   199,   188,   120,    95,   185,   201,   188,
     199,   258,   120,   120,   295,   120,   258,   734,   227,  1190,
     307,   307,   307,   261,   289,   969,   308,   426,   308,   537,
     446,  1036,  1235,  1712,  1759,   871,   461,  1497,  1732,  1244,
     308,  1033,  1478,  1248,   552,  1383,   790,  1264,  1126,  1381,
    1378,   552,  1286,  1294,  1291,   563,  1299,   654,  1263,   655,
    1497,   674,   708,   932,  1318,   831,  1783,  1272,   337,  1777,
     454,  1018,   454,  1189,  1350,  1361,  1360,  1771,  1396,  1576,
    1540,  1286,  1407,  1136,  1400,  1573,  1145,  1001,  1443,  1212,
    1600,  1296,  1397,   596,   602,  1789,    -1,    -1,    -1,    -1,
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
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,   261,   262,   263,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    -1,   314,    -1,   316,   317,   318,   319,
     320,   321,   322,     0,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    -1,
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
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,   176,
      -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,   191,    -1,   193,   194,    -1,   196,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,   215,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,   261,   262,   263,    -1,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,     1,   314,    -1,   316,
     317,   318,   319,   320,   321,   322,    11,    12,    -1,    -1,
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
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,   184,
      -1,    -1,    -1,   188,    -1,   190,   191,    -1,   193,   194,
      -1,   196,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
     215,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,    -1,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,     1,   314,
      -1,   316,   317,   318,   319,   320,   321,   322,    11,    12,
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
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,
     183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,
     193,   194,    -1,   196,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,   261,   262,
     263,    -1,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
      -1,   314,    -1,   316,   317,   318,   319,   320,   321,   322,
       0,     1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    71,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    96,    97,    98,    -1,
      -1,   101,   102,   103,   104,    -1,    -1,    -1,   108,   109,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,   118,   119,
     120,    -1,    -1,   123,    -1,    -1,    -1,    -1,   128,   129,
      -1,    -1,    -1,    -1,   134,    -1,    -1,    -1,   138,    -1,
      -1,    -1,   142,   143,    -1,   145,    -1,   147,   148,    -1,
      -1,    -1,   152,   153,    -1,    -1,   156,   157,   158,   159,
     160,   161,    -1,    -1,   164,    -1,    -1,    -1,    -1,   169,
     170,    -1,    -1,   173,    -1,    -1,    -1,    -1,   178,    -1,
      -1,   181,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
     190,    -1,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,   201,   202,   203,    -1,   205,   206,   207,   208,   209,
     210,    -1,   212,    -1,   214,    -1,    -1,    -1,    -1,   219,
     220,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   235,    -1,   237,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,    -1,   256,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,   313,    -1,   315,    34,    35,    -1,    37,
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
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,   193,   194,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,    -1,   314,    -1,   316,   317,
     318,   319,   320,   321,   322,   323,   324,    11,    12,    -1,
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
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,   193,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,   261,   262,   263,
      -1,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,    -1,
     314,    -1,   316,   317,   318,   319,   320,   321,   322,    -1,
     324,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,   186,    -1,   188,    -1,
     190,   191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,   261,   262,   263,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    -1,   314,    -1,   316,   317,   318,   319,
     320,   321,   322,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,   186,    -1,
     188,    -1,   190,   191,    -1,   193,   194,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,    -1,   314,    -1,   316,   317,
     318,   319,   320,   321,   322,    11,    12,    -1,    -1,    -1,
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
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
     186,    -1,   188,    -1,   190,   191,    -1,   193,   194,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,   261,   262,   263,    -1,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,    -1,   314,    -1,
     316,   317,   318,   319,   320,   321,   322,    11,    12,    -1,
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
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,   193,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,   261,   262,   263,
      -1,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,    -1,
     314,    -1,   316,   317,   318,   319,   320,   321,   322,    11,
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
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,   261,
     262,   263,    -1,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    -1,   314,    -1,   316,   317,   318,   319,   320,   321,
     322,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,   261,   262,   263,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    -1,   314,    -1,   316,   317,   318,   319,
     320,   321,   322,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,   193,   194,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,    -1,   314,    -1,   316,   317,
     318,   319,   320,   321,   322,    11,    12,    -1,    -1,    -1,
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
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,   193,   194,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,   261,   262,   263,    -1,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,    -1,   314,    -1,
     316,   317,   318,   319,   320,   321,   322,    11,    12,    -1,
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
      -1,    -1,   146,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,   189,   190,   191,    -1,   193,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,   261,   262,   263,
      -1,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,    -1,
     314,    -1,   316,   317,   318,   319,   320,   321,   322,    11,
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
      -1,    -1,    -1,    -1,   146,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,   189,   190,   191,
      -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,   261,
     262,   263,    -1,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    -1,   314,    -1,   316,   317,   318,   319,   320,   321,
     322,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,   261,   262,   263,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    -1,   314,    -1,   316,   317,   318,   319,
     320,   321,   322,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,   187,
     188,    -1,   190,   191,    -1,   193,   194,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,    -1,   314,    -1,   316,   317,
     318,   319,   320,   321,   322,    11,    12,    -1,    -1,    -1,
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
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,   189,   190,   191,    -1,   193,   194,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,   261,   262,   263,    -1,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,    -1,   314,    -1,
     316,   317,   318,   319,   320,   321,   322,    11,    12,    -1,
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
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,   193,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,   261,   262,   263,
      -1,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,    -1,   316,   317,   318,   319,   320,   321,   322,    11,
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
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,   261,
     262,   263,    -1,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,   321,
     322,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,   186,    -1,   188,    -1,
     190,   191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,   261,   262,   263,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    -1,   314,    -1,   316,   317,   318,   319,
     320,   321,   322,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,   193,   194,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,    -1,   314,    -1,   316,   317,
     318,   319,   320,   321,   322,    11,    12,    -1,    -1,    -1,
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
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,   193,   194,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,   261,   262,   263,    -1,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,    -1,   314,    -1,
     316,   317,   318,   319,   320,   321,   322,    11,    12,    -1,
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
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,   193,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,   261,   262,   263,
      -1,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,    -1,
     314,    -1,   316,   317,   318,   319,   320,   321,   322,    11,
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
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,   261,
     262,   263,    -1,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    -1,   314,    -1,   316,   317,   318,   319,   320,   321,
     322,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,    -1,    -1,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,   261,   262,   263,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,    -1,   314,    -1,   316,   317,   318,   319,
     320,   321,   322,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     158,   159,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
      -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,    -1,   314,    -1,   316,   317,
     318,   319,   320,   321,   322,    11,    12,    -1,    -1,    -1,
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
      -1,   137,    -1,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,    -1,   153,   154,   155,
     156,    -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,   198,    -1,   200,    -1,   202,    -1,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,   261,   262,   263,    -1,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,    -1,   314,    -1,
     316,   317,   318,   319,   320,   321,   322,    11,    12,    -1,
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
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,    -1,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,   261,   262,   263,
      -1,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,    -1,    -1,
      11,    12,   316,   317,   318,   319,   320,   321,   322,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
      -1,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,    -1,    -1,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
     261,   262,   263,    -1,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,    -1,    -1,    16,    -1,   316,   317,   318,   319,   320,
     321,   322,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
     183,   184,    -1,    -1,    -1,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,    -1,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,   261,   262,
     263,    -1,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
      -1,    16,    -1,   316,   317,   318,   319,   320,   321,   322,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
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
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,
      -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
      -1,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,    -1,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    -1,    -1,    -1,
      -1,   316,   317,   318,   319,   320,   321,   322,    18,    19,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
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
      -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,    -1,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,   261,   262,   263,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,    -1,    -1,    -1,    -1,   316,   317,   318,   319,
     320,   321,   322,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    -1,    50,    51,    52,    53,    -1,    55,    -1,    57,
      58,    59,    60,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
      -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,   214,   215,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,    -1,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,    -1,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,    -1,   314,    -1,   316,   317,
     318,   319,   320,   321,   322,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
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
      -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,    -1,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,   261,   262,   263,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,    -1,    -1,    25,    26,   316,   317,   318,   319,
     320,   321,   322,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
      -1,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,    -1,    -1,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
     261,   262,   263,    -1,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,    -1,    -1,    25,    26,   316,   317,   318,   319,   320,
     321,   322,    34,    35,    -1,    37,    38,    39,    40,    41,
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
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,    -1,    -1,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,    -1,   261,
     262,   263,    -1,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
      -1,    -1,    25,    26,   316,   317,   318,   319,   320,   321,
     322,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,
     153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,   162,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
     183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,    -1,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,   261,   262,
     263,    -1,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
      -1,    25,    26,   316,   317,   318,   319,   320,   321,   322,
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
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,    -1,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,    -1,   261,   262,   263,
      -1,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,    -1,    -1,
      25,    26,   316,   317,   318,   319,   320,   321,   322,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,   154,
      -1,    -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,
      -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
      -1,    -1,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,    -1,   261,   262,   263,    -1,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    -1,    -1,    25,
      26,   316,   317,   318,   319,   320,   321,   322,    34,    35,
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
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,    -1,   261,   262,   263,    -1,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,    -1,    -1,    25,    26,
     316,   317,   318,   319,   320,   321,   322,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,    -1,   152,   153,   154,    -1,    -1,
      -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,   261,   262,   263,    -1,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,    -1,    -1,    25,    26,   316,
     317,   318,   319,   320,   321,   322,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,    -1,   261,   262,   263,    -1,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,    -1,    -1,    25,    26,   316,   317,
     318,   319,   320,   321,   322,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,    -1,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,    -1,    -1,    25,    26,   316,   317,   318,
     319,   320,   321,   322,    34,    35,    -1,    37,    38,    39,
      -1,    41,    42,    43,    44,    -1,    -1,    47,    48,    -1,
      50,    51,    52,    53,    -1,    55,    -1,    57,    58,    59,
      60,    -1,    62,    -1,    -1,    65,    66,    67,    68,    69,
      -1,    71,    -1,    73,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    -1,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,    -1,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,   214,    -1,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,    -1,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,    -1,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
      -1,   261,   262,   263,    -1,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,    -1,    -1,    -1,    -1,   316,   317,   318,   319,
     320,   321,   322
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
     155,   156,   158,   159,   160,   161,   162,   167,   168,   169,
     170,   171,   172,   173,   174,   176,   178,   179,   182,   183,
     184,   188,   190,   191,   193,   194,   196,   198,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   213,
     214,   215,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   261,   262,   263,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   314,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   337,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   358,   359,   360,   361,   362,   363,
     367,   368,   369,   373,   375,   376,   378,   385,   387,   390,
     391,   392,   394,   395,   396,   397,   398,   400,   401,   403,
     404,   405,   406,   407,   408,   410,   411,   414,   415,   416,
     417,   422,   424,   426,   427,   432,   451,   454,   458,   461,
     462,   468,   469,   470,   471,   473,   474,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   486,   487,   488,   489,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   522,   523,   524,
     525,   526,   527,   541,   542,   544,   545,   546,   547,   548,
     549,   550,   551,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   572,   577,   578,   579,   580,   581,
     582,   585,   643,   644,   645,   646,   648,   649,   650,   651,
     652,   659,   660,   661,    34,    35,    50,   217,   393,   394,
     395,   393,   393,   394,   395,   158,   158,    38,    39,    41,
      42,    48,    58,    59,    76,    81,   113,   114,   115,   162,
     222,   263,   289,   297,   305,   374,   375,   379,   380,   381,
     162,   155,   158,   155,   158,   155,   158,     1,     3,    68,
      73,   120,   419,   158,   382,   158,    25,    35,    62,   120,
     275,   431,   433,   434,   158,   155,   158,   158,   158,   120,
     155,   158,   158,   158,    78,   155,   223,   224,   124,   124,
     124,   155,   158,    40,    44,    46,    47,    48,    49,    52,
      61,    69,    72,    74,    75,    77,    92,    93,    99,   107,
     114,   116,   117,   137,   140,   141,   162,   171,   174,   182,
     183,   191,   204,   226,   228,   230,   231,   238,   240,   241,
     242,   245,   246,   317,   506,   660,   124,   120,   402,   124,
     124,    40,    45,    46,    54,    61,    63,    64,    72,    99,
     227,   659,   120,   124,   124,   186,   393,   395,   415,   647,
      49,    74,    75,   120,   155,   187,   246,   414,   416,   426,
     189,   414,   659,   155,   155,   124,    16,   658,   659,    18,
      19,   659,   124,   124,   124,   498,   155,    31,   216,   218,
     227,   229,   316,   158,   227,   229,   316,   227,   316,   227,
     232,   316,   120,   243,   243,   244,   158,   155,   397,   313,
     414,   315,   414,   316,   324,   339,   339,     0,   341,   342,
      34,    50,   344,   361,     1,   192,   338,   192,   338,   114,
     376,   396,   414,   109,   192,   109,   338,   192,    43,    47,
      52,    71,   170,   173,   188,   214,   409,   418,   423,   424,
     425,   439,   440,   444,   169,    94,   134,   142,   143,   145,
     153,   157,   159,   164,   181,   205,   206,   207,   208,   209,
     210,   490,   491,   251,   101,   160,   178,   201,   119,   148,
     161,   196,   203,   212,   138,   152,    51,   202,   103,   104,
     160,   178,   488,   195,   155,   495,   498,   193,   194,   156,
     510,   511,   506,   510,   506,   158,   510,   147,   158,   186,
     186,   186,   186,   377,   513,   377,    30,   657,   184,   198,
     184,   198,   168,   184,   660,   659,   171,   204,    48,   659,
     154,   120,    46,    48,    81,   108,   170,   658,   223,   224,
     225,   248,   616,   659,   659,   306,   139,   144,   114,   289,
     297,   379,   658,   394,   189,   394,    46,    64,   189,   568,
     569,   414,   189,   196,   659,   428,   429,   659,   286,   286,
     428,   120,   435,   120,   189,   383,   384,   155,   399,   414,
       1,   162,   657,   115,   162,   357,   657,   659,   120,   144,
     109,   189,   414,    30,   189,   658,   659,   659,   452,   453,
     659,   394,   189,   414,   414,   570,   659,   394,   155,   155,
     414,   189,   196,   659,   659,   144,   452,   186,   186,   123,
     109,   186,   158,   158,   158,   659,   155,   187,   188,   189,
      36,   529,   530,   531,   414,   414,     8,   177,    17,   414,
     216,    30,   415,   415,    40,    46,    61,    72,    99,   509,
     660,   189,   415,   415,   415,   647,   415,   509,   415,   233,
     232,   583,   584,   659,   192,   192,   415,   414,   395,   414,
     247,   412,   413,   313,   315,   415,   339,   192,   338,   192,
     338,     3,   345,   361,   391,     1,   345,   361,   391,    34,
     362,   391,   362,   391,   402,   338,   402,   415,   415,   120,
     170,   172,   172,   396,   415,   415,   470,   471,   473,   473,
     473,   473,   472,   473,   473,   473,    72,   474,   478,   478,
     477,   479,   479,   479,   479,   480,   480,   481,   481,   233,
      96,    96,    96,   496,   186,   414,   498,   498,   414,   511,
     146,   189,   415,   521,   151,   189,   521,   109,   189,   189,
     109,   109,   382,    30,   660,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,   364,   365,   366,    96,   139,
     144,   370,   371,   372,   659,   162,   162,   364,   657,   129,
     134,    56,    58,   102,   253,   266,   268,   279,   280,   281,
     283,   285,   617,   618,   619,   620,   621,   622,   629,   635,
     636,   248,    96,   301,   659,   144,   415,   120,   659,   659,
     134,   186,   186,   189,   189,   186,   109,   189,   109,   189,
     109,    37,    96,    98,   149,   430,   431,   552,   659,    57,
     219,   256,   420,   421,   659,    96,   109,   189,   393,   189,
     658,    98,    46,   658,   657,    98,   144,   552,   659,   415,
     434,   186,   189,   189,   189,   189,   109,   190,   149,   552,
     186,   189,   189,   155,   186,   394,   394,   186,   109,   189,
     109,   189,   144,   552,   415,   190,   415,   415,   414,   414,
     414,   659,   530,   531,   132,   199,   186,   186,   186,   133,
     192,    96,   220,   221,   235,    96,   220,   221,   235,   235,
     235,    96,    96,   239,   227,   233,   109,   237,   144,   192,
     189,   414,   186,   507,   589,   413,   235,   361,    34,    34,
     192,   338,   192,   115,   396,   659,   172,   415,   445,   446,
     120,   441,   442,   473,   155,   158,   261,   494,   513,   590,
     593,   594,   595,   596,   597,   601,   603,   605,   606,    48,
     154,   158,   213,   319,   320,   321,   322,   553,   555,   557,
     559,   573,   574,   575,   576,   653,   654,   655,   656,   659,
     553,   485,   558,   659,   485,   186,   187,   109,   189,   189,
     513,   150,   167,   150,   167,   139,   399,   382,   365,   134,
     555,   372,   415,   552,   657,   657,   130,   131,   657,   279,
     280,   281,   285,   659,   265,   276,   265,   276,    30,   288,
      98,   115,   158,   623,   626,   617,    40,    45,    54,    61,
      63,    72,    99,   227,   319,   320,   321,   386,   559,   653,
     229,   301,   310,   415,   659,    96,   301,   657,   155,   570,
     571,   659,   570,   571,   120,   429,   129,   553,   120,   415,
     149,   431,   149,    37,   149,   430,   431,   149,   552,   256,
      55,    60,    79,   120,   430,   436,   437,   438,   421,   552,
     553,   384,    96,   186,   200,   134,   356,   657,   162,   134,
      98,   356,   415,   144,   431,   155,   120,   415,   415,   149,
     102,   455,   456,   457,   459,   460,   102,   463,   464,   465,
     466,   394,   186,   186,   155,   570,   570,   415,   144,   192,
     415,   123,   189,   189,   189,    36,   531,   132,   199,     9,
      10,   105,   125,   127,   155,   197,   526,   528,   539,   540,
     543,   155,    30,   234,   236,   415,   415,   415,   234,   236,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   509,
     120,   415,   415,    49,    74,    75,   246,   396,   416,   426,
     247,   586,   587,   155,   212,   397,   415,   192,   115,   391,
     391,   391,   445,    97,   108,   118,   129,   447,   448,   449,
     450,   109,   659,   109,   414,   590,   597,   155,   287,   475,
     642,    98,   171,   254,   255,   257,   264,   274,   286,   591,
     592,   611,   612,   613,   614,   637,   640,   260,   262,   598,
     616,   269,   602,   638,   249,   250,   272,   607,   608,   158,
     158,   555,   158,   158,   158,   158,   158,   146,   178,   196,
     554,   146,   146,   415,   139,   399,   572,   371,   288,    30,
      98,   115,   158,   630,    30,   623,   554,   554,   496,   289,
     308,   552,   386,   229,   192,   393,   189,   189,   146,   189,
     189,   429,   149,   430,   659,   415,   149,   415,   129,   415,
     149,   431,   149,   415,   149,   120,   120,   415,   659,   438,
      79,   553,   396,   415,   657,   109,   356,   415,   144,   393,
     453,   415,   415,   115,   456,   457,   102,   188,   115,   457,
     460,   120,   467,   553,   102,   115,   464,   102,   115,   466,
     186,   393,   189,   189,   415,   415,   200,   463,   134,   197,
     528,     7,   394,   659,   197,   539,   394,   192,   235,   235,
     235,   235,    98,   239,   239,   584,   188,   158,   158,   158,
     188,   589,   587,   507,   657,   130,   131,   449,   450,   450,
     446,   108,   144,   443,   552,   442,   186,   189,   590,   604,
     252,   219,   256,   270,   277,   641,    98,   258,   259,   639,
     252,   594,   641,   477,   611,   595,   149,   284,   599,   600,
     639,   288,   610,    80,   609,   189,   196,   553,   556,   189,
     189,   189,   189,   189,   189,   189,    30,   138,   203,   632,
     633,   634,    30,   631,   632,   273,   627,   109,   624,   172,
     659,   259,   496,   186,   415,   149,   415,   149,   430,   415,
     149,   415,   415,   659,   659,   437,   415,   128,   128,    98,
     657,   415,   186,   188,   188,   415,   396,   415,   188,   188,
     659,   188,   212,   120,   467,   120,   188,   120,   467,   188,
     186,   115,   531,   659,   197,   186,   531,   659,   186,   415,
     415,   415,   415,   318,   415,   415,   415,   414,   414,   414,
     155,   588,   450,   657,   415,   144,   186,   479,    53,   131,
     477,   477,   271,   278,   288,   615,   615,   596,   155,   282,
      96,   189,   109,   189,   630,   630,   634,   109,   189,    30,
     628,   639,   625,   626,   189,   388,   389,   496,   120,   227,
     309,   289,   172,   415,   415,   149,   415,    55,   396,   415,
     356,   415,   396,    96,   396,   415,   553,   659,   188,   659,
     415,   659,   188,   396,   120,    95,   185,   532,   531,   659,
     199,   531,   415,   189,   189,   189,   414,   443,   415,   477,
     477,   201,   414,   553,   553,    96,    30,   267,   109,   109,
     450,   552,   659,   120,   227,   659,   388,   415,   120,   467,
      96,   188,    96,   659,     5,   135,   535,   536,   538,   540,
      29,   136,   533,   534,   537,   540,   199,   531,   199,   200,
     463,   186,   443,   477,   186,   553,   626,   389,   450,   307,
     659,   120,   227,   659,   188,   467,   396,   415,   467,   188,
      95,   135,   538,   185,   136,   537,   199,   115,   415,   307,
     659,   120,   396,   415,   188,   188,   120,   295,   307,   659,
     659,   308,   415,   308,   188,   496,   496,   201,   289,   659,
     227,   120,   659,   308,   496
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
     585,   586,   587,   588,   589,   590
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   336,   337,   337,   337,   337,   338,   338,   338,   339,
     339,   339,   339,   340,   340,   341,   341,   341,   341,   341,
     341,   341,   341,   342,   342,   342,   342,   343,   344,   344,
     344,   345,   345,   345,   345,   345,   346,   346,   346,   346,
     346,   346,   346,   346,   347,   347,   348,   349,   350,   350,
     351,   351,   352,   352,   353,   353,   353,   353,   354,   354,
     354,   355,   355,   355,   355,   356,   356,   357,   357,   358,
     358,   358,   358,   359,   360,   360,   361,   361,   361,   362,
     362,   362,   362,   362,   362,   362,   362,   363,   363,   364,
     364,   365,   366,   366,   366,   366,   366,   366,   366,   366,
     366,   366,   367,   368,   369,   370,   370,   371,   371,   371,
     372,   373,   373,   373,   374,   374,   374,   374,   375,   375,
     376,   376,   376,   376,   377,   377,   378,   378,   379,   379,
     380,   380,   381,   381,   382,   382,   382,   382,   383,   383,
     384,   384,   385,   385,   385,   385,   386,   386,   386,   386,
     387,   387,   388,   388,   389,   389,   389,   389,   390,   390,
     390,   390,   391,   392,   392,   392,   393,   393,   393,   394,
     394,   395,   395,   395,   396,   396,   396,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   397,   397,   398,   399,
     400,   401,   401,   401,   402,   402,   402,   402,   403,   404,
     405,   406,   407,   407,   408,   409,   410,   411,   412,   412,
     413,   414,   414,   414,   415,   415,   415,   415,   415,   415,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     416,   416,   417,   418,   419,   419,   420,   420,   420,   421,
     421,   422,   422,   423,   424,   424,   424,   425,   425,   425,
     425,   425,   426,   426,   427,   427,   427,   428,   428,   428,
     429,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   430,   431,   432,   433,   433,   434,   434,   434,
     434,   435,   435,   436,   436,   436,   437,   437,   437,   438,
     438,   438,   439,   440,   441,   441,   442,   442,   442,   442,
     442,   442,   443,   444,   444,   445,   445,   446,   446,   447,
     447,   447,   447,   447,   447,   447,   448,   448,   449,   449,
     450,   451,   451,   452,   452,   453,   453,   454,   455,   455,
     456,   457,   457,   458,   459,   459,   460,   461,   461,   462,
     462,   463,   463,   464,   464,   465,   465,   466,   466,   467,
     467,   468,   469,   469,   470,   470,   471,   471,   471,   471,
     471,   472,   471,   471,   471,   471,   473,   473,   474,   474,
     475,   475,   476,   476,   477,   477,   477,   478,   478,   478,
     478,   478,   479,   479,   479,   480,   480,   480,   481,   481,
     482,   482,   483,   483,   484,   484,   485,   485,   486,   486,
     487,   487,   487,   487,   488,   488,   488,   489,   489,   490,
     490,   490,   490,   490,   490,   491,   491,   491,   492,   492,
     492,   492,   493,   493,   494,   494,   495,   495,   495,   496,
     496,   496,   496,   497,   498,   498,   498,   499,   499,   500,
     500,   500,   500,   501,   501,   502,   502,   502,   502,   502,
     502,   502,   503,   503,   504,   504,   505,   505,   505,   505,
     505,   506,   506,   507,   507,   508,   508,   508,   508,   509,
     509,   509,   509,   510,   510,   511,   512,   512,   512,   512,
     512,   512,   512,   512,   512,   512,   512,   512,   512,   512,
     513,   513,   514,   514,   514,   515,   516,   516,   517,   518,
     519,   520,   520,   521,   521,   521,   521,   522,   522,   523,
     524,   525,   525,   526,   526,   526,   527,   527,   527,   527,
     527,   527,   528,   528,   529,   529,   530,   531,   531,   532,
     532,   533,   533,   534,   534,   534,   534,   535,   535,   536,
     536,   536,   536,   537,   537,   538,   538,   539,   539,   539,
     539,   540,   540,   540,   540,   541,   541,   542,   542,   543,
     544,   544,   544,   544,   544,   544,   544,   545,   546,   546,
     547,   547,   548,   549,   550,   550,   551,   551,   552,   553,
     553,   553,   554,   554,   554,   555,   555,   555,   555,   555,
     555,   555,   556,   556,   557,   558,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   560,   561,   561,   561,
     562,   563,   564,   565,   565,   565,   566,   566,   566,   566,
     566,   567,   568,   568,   568,   568,   568,   568,   568,   569,
     570,   571,   572,   573,   573,   574,   575,   575,   576,   577,
     577,   577,   578,   578,   578,   578,   578,   578,   578,   578,
     578,   578,   579,   579,   580,   580,   581,   582,   583,   583,
     584,   585,   586,   586,   587,   588,   589,   589,   590,   591,
     591,   592,   592,   593,   593,   594,   594,   595,   595,   596,
     596,   597,   598,   598,   599,   599,   600,   601,   601,   601,
     602,   602,   603,   604,   604,   605,   606,   606,   607,   607,
     608,   608,   608,   609,   609,   610,   610,   611,   611,   611,
     611,   611,   612,   613,   614,   615,   615,   615,   616,   616,
     617,   617,   617,   617,   617,   617,   617,   617,   618,   618,
     618,   618,   619,   619,   620,   621,   621,   622,   622,   622,
     623,   623,   624,   624,   625,   625,   626,   627,   627,   628,
     628,   629,   629,   629,   630,   630,   631,   631,   632,   632,
     633,   633,   634,   634,   635,   636,   636,   637,   637,   637,
     638,   639,   639,   639,   639,   640,   640,   641,   641,   642,
     643,   643,   644,   644,   645,   645,   646,   647,   647,   648,
     648,   648,   649,   650,   651,   652,   653,   653,   653,   654,
     655,   656,   657,   658,   658,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   661
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
  "\"'nodecomp'\"", "\"'?""?'\"", "\"'<no inherit>'\"",
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
       337,     0,    -1,   339,    -1,   323,   339,    -1,   324,   339,
      -1,   323,   324,   339,    -1,     1,    -1,     1,     3,    -1,
     338,     1,    -1,   341,    -1,   340,   341,    -1,   342,    -1,
     340,   342,    -1,   217,   218,    30,   192,    -1,   217,   218,
      30,   133,    30,   192,    -1,   344,   192,   391,    -1,   361,
     192,   391,    -1,   344,   192,   361,   192,   391,    -1,   391,
      -1,   344,   338,   391,    -1,   361,   338,   391,    -1,   344,
     192,   361,   338,   391,    -1,   344,   338,   361,   192,   391,
      -1,   343,    -1,   343,   344,   192,    -1,   343,   361,   192,
      -1,   343,   344,   192,   361,   192,    -1,    35,   162,   658,
     134,   657,   192,    -1,   345,    -1,   344,   192,   345,    -1,
     344,   338,   345,    -1,   346,    -1,   354,    -1,   359,    -1,
     360,    -1,   368,    -1,   347,    -1,   348,    -1,   349,    -1,
     350,    -1,   351,    -1,   352,    -1,   353,    -1,   577,    -1,
      34,    39,   184,    -1,    34,    39,   198,    -1,    34,   115,
     108,   657,    -1,    34,    38,   657,    -1,    34,    41,   184,
      -1,    34,    41,   198,    -1,    34,    59,   171,    -1,    34,
      59,   204,    -1,    34,   115,   170,   129,   130,    -1,    34,
     115,   170,   129,   131,    -1,    34,    42,   184,   109,   150,
      -1,    34,    42,   184,   109,   167,    -1,    34,    42,   168,
     109,   150,    -1,    34,    42,   168,   109,   167,    -1,   355,
      -1,   358,    -1,    50,    25,     1,    -1,    50,    62,   657,
      -1,    50,    62,   357,   657,    -1,    50,    62,   657,    98,
     356,    -1,    50,    62,   357,   657,    98,   356,    -1,   657,
      -1,   356,   109,   657,    -1,   162,   658,   134,    -1,   115,
      46,   162,    -1,    50,    35,   657,    -1,    50,    35,   162,
     658,   134,   657,    -1,    50,    35,   657,    98,   356,    -1,
      50,    35,   162,   658,   134,   657,    98,   356,    -1,    34,
     162,   658,   134,   657,    -1,    34,   115,    46,   162,   657,
      -1,    34,   115,    48,   162,   657,    -1,   362,    -1,   361,
     192,   362,    -1,   361,   338,   362,    -1,   363,    -1,   367,
      -1,   369,    -1,   373,    -1,   378,    -1,   385,    -1,   387,
      -1,   390,    -1,    34,   115,    81,   364,    -1,    34,    81,
     659,   364,    -1,   365,    -1,   364,   365,    -1,   366,   134,
     572,    -1,    82,    -1,    90,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    91,    -1,    87,    -1,    88,    -1,
      89,    -1,    34,    58,   659,    30,    -1,    34,   263,   616,
      -1,    34,   113,   154,   370,    -1,    96,   555,   371,    -1,
     371,    -1,   372,    -1,   139,    -1,   139,   372,    -1,   144,
     415,    -1,    34,   374,   144,   415,    -1,    34,   374,   139,
      -1,    34,   374,   139,   144,   415,    -1,   114,   120,   659,
      -1,   114,   120,   659,   552,    -1,   375,   114,   120,   659,
      -1,   375,   114,   120,   659,   552,    -1,   376,    -1,   375,
     376,    -1,    27,    -1,    27,   158,   377,   189,    -1,    28,
      -1,    28,   158,   377,   189,    -1,   513,    -1,   377,   109,
     513,    -1,    34,   379,    -1,    34,   375,   379,    -1,   380,
      -1,   381,    -1,    48,   660,   382,   399,    -1,    48,   660,
     382,   139,    -1,    76,    48,   660,   382,   399,    -1,    76,
      48,   660,   382,   139,    -1,   158,   189,    -1,   158,   383,
     189,    -1,   158,   189,    96,   553,    -1,   158,   383,   189,
      96,   553,    -1,   384,    -1,   383,   109,   384,    -1,   120,
     659,    -1,   120,   659,   552,    -1,    34,   289,   659,    -1,
      34,   289,   659,    96,   386,    -1,    34,   375,   289,   659,
      -1,    34,   375,   289,   659,    96,   386,    -1,   559,    -1,
     559,   554,    -1,   653,    -1,   653,   554,    -1,    34,   297,
     659,   301,   229,   496,   172,   388,    -1,    34,   375,   297,
     659,   301,   229,   496,   172,   388,    -1,   389,    -1,   388,
     109,   389,    -1,   496,    -1,   496,   552,    -1,   496,   450,
      -1,   496,   552,   450,    -1,    34,   305,   306,   659,   301,
     289,   659,   120,   659,   307,   415,    -1,    34,   305,   306,
     659,   301,   289,   659,   227,   120,   659,   307,   295,   308,
     496,    -1,    34,   305,   306,   659,   301,   289,   659,   309,
     227,   120,   659,   307,   415,    -1,    34,   305,   306,   659,
     310,   308,   259,   289,   659,   227,   120,   659,   308,   496,
     201,   289,   659,   227,   120,   659,   308,   496,    -1,   392,
      -1,   394,    -1,   395,    -1,    -1,   394,    -1,   395,    -1,
      -1,   414,    -1,   395,   414,    -1,   396,    -1,   395,   396,
      -1,   395,   414,   338,   396,    -1,   397,    -1,   400,    -1,
     403,    -1,   404,    -1,   405,    -1,   406,    -1,   407,    -1,
     408,    -1,   410,    -1,   462,    -1,   458,    -1,   411,    -1,
     155,   395,   186,    -1,   155,   186,    -1,   155,   393,   186,
      -1,   155,   393,   186,    -1,   401,   192,    -1,   401,   109,
     402,    -1,   114,   402,    -1,   375,   114,   402,    -1,   120,
     659,    -1,   120,   659,   552,    -1,   120,   659,   144,   415,
      -1,   120,   659,   552,   144,   415,    -1,   120,   659,   144,
     415,   192,    -1,   416,   192,    -1,   242,   244,   415,   192,
      -1,   245,   158,   414,   189,   396,    -1,   240,   243,   192,
      -1,   241,   243,   192,    -1,   426,   409,    -1,   188,   396,
      -1,    49,   158,   414,   189,   200,   396,   128,   396,    -1,
     246,   397,   412,    -1,   413,    -1,   412,   413,    -1,   247,
     589,   397,    -1,   415,    -1,   414,   109,   415,    -1,   414,
     338,   415,    -1,   417,    -1,   454,    -1,   461,    -1,   468,
      -1,   585,    -1,   416,    -1,   469,    -1,   451,    -1,   578,
      -1,   579,    -1,   581,    -1,   580,    -1,   582,    -1,   650,
      -1,   648,    -1,   651,    -1,   652,    -1,   649,    -1,   426,
     418,    -1,   188,   415,    -1,    68,   286,    -1,    73,   286,
      -1,   219,    -1,   256,    -1,    57,   256,    -1,   420,   436,
      79,   415,    -1,   420,    79,   415,    -1,    47,   419,   435,
     421,   421,    -1,    47,   419,   435,   421,    -1,    43,   120,
     659,    -1,   427,    -1,   432,    -1,   422,    -1,   424,    -1,
     439,    -1,   444,    -1,   440,    -1,   423,    -1,   424,    -1,
     426,   425,    -1,    47,   120,   428,    -1,    47,     1,   428,
      -1,    47,     3,    -1,   429,    -1,   428,   109,   120,   429,
      -1,   428,   109,   429,    -1,   659,   149,   415,    -1,   659,
      37,   129,   149,   415,    -1,   659,   552,   149,   415,    -1,
     659,   552,    37,   129,   149,   415,    -1,   659,   430,   149,
     415,    -1,   659,    37,   129,   430,   149,   415,    -1,   659,
     552,   430,   149,   415,    -1,   659,   552,    37,   129,   430,
     149,   415,    -1,   659,   431,   149,   415,    -1,   659,   552,
     431,   149,   415,    -1,   659,   430,   431,   149,   415,    -1,
     659,   552,   430,   431,   149,   415,    -1,    98,   120,   659,
      -1,   275,   120,   659,    -1,    52,   433,    -1,   434,    -1,
     433,   109,   434,    -1,   120,   659,   144,   415,    -1,   120,
     659,   552,   144,   415,    -1,   431,   144,   415,    -1,   120,
     659,   552,   431,   144,   415,    -1,   120,   659,   149,   415,
      -1,   120,   659,   552,   149,   415,    -1,   437,    -1,   120,
     659,    -1,   120,   659,   437,    -1,   430,    -1,   430,   438,
      -1,   438,    -1,    60,   120,   659,    55,   120,   659,    -1,
      55,   120,   659,    -1,    60,   120,   659,    -1,   214,   415,
      -1,   173,   172,   441,    -1,   442,    -1,   441,   109,   442,
      -1,   120,   659,    -1,   120,   659,   144,   415,    -1,   120,
     659,   552,   144,   415,    -1,   120,   659,   552,   144,   415,
     443,    -1,   120,   659,   144,   415,   443,    -1,   120,   659,
     443,    -1,   108,   657,    -1,   170,   172,   445,    -1,    71,
     170,   172,   445,    -1,   446,    -1,   445,   109,   446,    -1,
     415,    -1,   415,   447,    -1,   448,    -1,   449,    -1,   450,
      -1,   448,   449,    -1,   448,   450,    -1,   449,   450,    -1,
     448,   449,   450,    -1,    97,    -1,   118,    -1,   129,   130,
      -1,   129,   131,    -1,   108,   657,    -1,    69,   120,   452,
     190,   415,    -1,   137,   120,   452,   190,   415,    -1,   453,
      -1,   452,   109,   120,   453,    -1,   659,   149,   415,    -1,
     659,   552,   149,   415,    -1,    74,   158,   414,   189,   455,
     115,   188,   415,    -1,   456,    -1,   455,   456,    -1,   457,
     188,   415,    -1,   102,   415,    -1,   457,   102,   415,    -1,
      74,   158,   414,   189,   459,   115,   188,   396,    -1,   460,
      -1,   459,   460,    -1,   457,   188,   396,    -1,    75,   158,
     414,   189,   463,   115,   188,   415,    -1,    75,   158,   414,
     189,   463,   115,   120,   659,   188,   415,    -1,    75,   158,
     414,   189,   465,   115,   188,   396,    -1,    75,   158,   414,
     189,   463,   115,   120,   659,   188,   396,    -1,   464,    -1,
     463,   464,    -1,   102,   467,   188,   415,    -1,   102,   120,
     659,    96,   467,   188,   415,    -1,   466,    -1,   465,   466,
      -1,   102,   467,   188,   396,    -1,   102,   120,   659,    96,
     467,   188,   396,    -1,   553,    -1,   467,   212,   553,    -1,
      49,   158,   414,   189,   200,   415,   128,   415,    -1,   470,
      -1,   469,   169,   470,    -1,   471,    -1,   470,    94,   471,
      -1,   473,    -1,   473,   490,   473,    -1,   473,   491,   473,
      -1,   473,   134,   473,    -1,   473,   164,   473,    -1,    -1,
     473,   159,   472,   473,    -1,   473,   157,   473,    -1,   473,
     145,   473,    -1,   473,   143,   473,    -1,   474,    -1,   474,
     251,    72,   590,   475,    -1,   476,    -1,   476,   101,   474,
      -1,    -1,   642,    -1,   477,    -1,   477,   201,   477,    -1,
     478,    -1,   477,   178,   478,    -1,   477,   160,   478,    -1,
     479,    -1,   478,   196,   479,    -1,   478,   119,   479,    -1,
     478,   148,   479,    -1,   478,   161,   479,    -1,   480,    -1,
     479,   203,   480,    -1,   479,   212,   480,    -1,   481,    -1,
     480,   152,   481,    -1,   480,   138,   481,    -1,   482,    -1,
     482,    51,   233,   553,    -1,   483,    -1,   483,   202,    96,
     553,    -1,   484,    -1,   484,   103,    96,   485,    -1,   486,
      -1,   486,   104,    96,   485,    -1,   558,    -1,   558,   146,
      -1,   488,    -1,   487,   488,    -1,   178,    -1,   160,    -1,
     487,   178,    -1,   487,   160,    -1,   492,    -1,   489,    -1,
     493,    -1,   496,    -1,   489,   195,   496,    -1,   205,    -1,
     210,    -1,   209,    -1,   208,    -1,   207,    -1,   206,    -1,
     153,    -1,   181,    -1,   142,    -1,    77,   155,   394,   186,
      -1,    77,   224,   155,   394,   186,    -1,    77,   223,   155,
     394,   186,    -1,    77,    78,   570,   155,   394,   186,    -1,
     494,   155,   186,    -1,   494,   155,   414,   186,    -1,   495,
      -1,   494,   495,    -1,   179,   659,    17,    -1,   179,    18,
      -1,   179,    19,    -1,   497,    -1,   497,   498,    -1,   194,
     498,    -1,   498,    -1,   193,    -1,   499,    -1,   499,   193,
     498,    -1,   499,   194,   498,    -1,   500,    -1,   509,    -1,
     501,    -1,   501,   510,    -1,   504,    -1,   504,   510,    -1,
     502,   506,    -1,   503,    -1,   107,   124,    -1,   116,   124,
      -1,    99,   124,    -1,   191,   124,    -1,   117,   124,    -1,
     141,   124,    -1,   140,   124,    -1,   506,    -1,   100,   506,
      -1,   505,   506,    -1,   122,    -1,   174,   124,    -1,    92,
     124,    -1,   183,   124,    -1,   182,   124,    -1,    93,   124,
      -1,   559,    -1,   507,    -1,   659,    -1,   508,    -1,   196,
      -1,    11,    -1,    12,    -1,    20,    -1,   512,    -1,   509,
     510,    -1,   509,   158,   189,    -1,   509,   158,   521,   189,
      -1,   511,    -1,   510,   511,    -1,   156,   414,   187,    -1,
     513,    -1,   515,    -1,   516,    -1,   517,    -1,   520,    -1,
     525,    -1,   518,    -1,   519,    -1,   522,    -1,   398,    -1,
     646,    -1,   643,    -1,   644,    -1,   645,    -1,   514,    -1,
     572,    -1,   112,    -1,   151,    -1,   126,    -1,   120,   659,
      -1,   158,   189,    -1,   158,   414,   189,    -1,   121,    -1,
     171,   155,   414,   186,    -1,   204,   155,   414,   186,    -1,
     660,   158,   189,    -1,   660,   158,   521,   189,    -1,   146,
      -1,   521,   109,   146,    -1,   415,    -1,   521,   109,   415,
      -1,   523,    -1,   524,    -1,   660,   147,   151,    -1,    48,
     382,   399,    -1,   526,    -1,   544,    -1,   527,    -1,   541,
      -1,   542,    -1,   159,   659,   531,   132,    -1,   159,   659,
     531,   199,   197,   659,   531,   199,    -1,   159,   659,   529,
     531,   132,    -1,   159,   659,   529,   531,   199,   197,   659,
     531,   199,    -1,   159,   659,   531,   199,   528,   197,   659,
     531,   199,    -1,   159,   659,   529,   531,   199,   528,   197,
     659,   531,   199,    -1,   539,    -1,   528,   539,    -1,   530,
      -1,   529,   530,    -1,    36,   659,   531,   134,   531,   532,
      -1,    -1,    36,    -1,   185,   533,   185,    -1,    95,   535,
      95,    -1,    -1,   534,    -1,   136,    -1,   537,    -1,   534,
     136,    -1,   534,   537,    -1,    -1,   536,    -1,   135,    -1,
     538,    -1,   536,   135,    -1,   536,   538,    -1,    29,    -1,
     540,    -1,     5,    -1,   540,    -1,   526,    -1,    10,    -1,
     543,    -1,   540,    -1,     9,    -1,   125,    -1,   127,    -1,
     155,   394,   186,    -1,   215,    31,   216,    -1,   215,   216,
      -1,   176,   658,   177,    -1,   176,   658,     8,    -1,   105,
       7,    -1,   545,    -1,   546,    -1,   547,    -1,   548,    -1,
     549,    -1,   550,    -1,   551,    -1,    44,   155,   394,   186,
      -1,    21,   393,   186,    -1,    46,   155,   414,   186,   155,
     393,   186,    -1,    22,   393,   186,    -1,    99,   155,   414,
     186,   155,   393,   186,    -1,    72,   155,   394,   186,    -1,
      40,   155,   394,   186,    -1,    23,   393,   186,    -1,    61,
     155,   414,   186,   155,   393,   186,    -1,    24,   394,   186,
      -1,   162,   155,   414,   186,   155,   394,   186,    -1,    96,
     553,    -1,   555,    -1,   555,   554,    -1,   213,   158,   189,
      -1,   146,    -1,   196,    -1,   178,    -1,   557,    -1,   559,
      -1,   154,   158,   189,    -1,   322,   158,   189,    -1,   573,
      -1,   576,    -1,   653,    -1,   553,    -1,   556,   109,   553,
      -1,   659,    -1,   659,    -1,   561,    -1,   568,    -1,   566,
      -1,   569,    -1,   567,    -1,   565,    -1,   564,    -1,   563,
      -1,   562,    -1,   560,    -1,   227,   158,   189,    -1,    45,
     158,   189,    -1,    45,   158,   568,   189,    -1,    45,   158,
     569,   189,    -1,    54,   158,   189,    -1,    72,   158,   189,
      -1,    40,   158,   189,    -1,    61,   158,   189,    -1,    61,
     158,   658,   189,    -1,    61,   158,    30,   189,    -1,    99,
     158,   189,    -1,    99,   158,   659,   189,    -1,    99,   158,
     659,   109,   570,   189,    -1,    99,   158,   196,   189,    -1,
      99,   158,   196,   109,   570,   189,    -1,    63,   158,   659,
     189,    -1,    46,   158,   189,    -1,    46,   158,   659,   189,
      -1,    46,   158,   659,   109,   570,   189,    -1,    46,   158,
     659,   109,   571,   189,    -1,    46,   158,   196,   189,    -1,
      46,   158,   196,   109,   570,   189,    -1,    46,   158,   196,
     109,   571,   189,    -1,    64,   158,   659,   189,    -1,   659,
      -1,   659,   146,    -1,    30,    -1,   574,    -1,   575,    -1,
      48,   158,   196,   189,    -1,    48,   158,   189,    96,   553,
      -1,    48,   158,   556,   189,    96,   553,    -1,   158,   555,
     189,    -1,    34,   222,   223,    -1,    34,   222,   224,    -1,
      34,   222,   225,    -1,   228,   227,   415,   235,   415,    -1,
     228,   227,   415,    96,   234,   235,   415,    -1,   228,   227,
     415,    96,   236,   235,   415,    -1,   228,   227,   415,   220,
     415,    -1,   228,   227,   415,   221,   415,    -1,   228,   229,
     415,   235,   415,    -1,   228,   229,   415,    96,   234,   235,
     415,    -1,   228,   229,   415,    96,   236,   235,   415,    -1,
     228,   229,   415,   220,   415,    -1,   228,   229,   415,   221,
     415,    -1,   226,   227,   415,    -1,   226,   229,   415,    -1,
     231,   227,   415,   239,   415,    -1,   231,   232,   233,   227,
     415,   239,   415,    -1,   230,   227,   415,    96,   415,    -1,
     238,   120,   583,   237,   415,   188,   415,    -1,   584,    -1,
     583,   109,   120,   584,    -1,   659,   144,   415,    -1,   246,
     155,   414,   186,   586,    -1,   587,    -1,   586,   587,    -1,
     247,   589,   588,    -1,   155,   414,   186,    -1,   507,    -1,
     589,   212,   507,    -1,   593,   591,    -1,    -1,   592,    -1,
     611,    -1,   592,   611,    -1,   594,    -1,   593,   264,   594,
      -1,   595,    -1,   594,   260,   595,    -1,   596,    -1,   595,
     262,   149,   596,    -1,   597,    -1,   261,   597,    -1,   601,
     598,   599,    -1,    -1,   616,    -1,    -1,   600,    -1,   284,
     155,   414,   186,    -1,   605,   602,    -1,   158,   590,   189,
      -1,   603,    -1,    -1,   638,    -1,   494,   155,   604,   186,
      -1,    -1,   590,    -1,   606,   607,    -1,   513,    -1,   155,
     414,   186,    -1,    -1,   608,    -1,   250,   609,    -1,   249,
     610,    -1,   272,    -1,    -1,    80,    -1,    -1,   288,    -1,
     612,    -1,   613,    -1,   614,    -1,   640,    -1,   637,    -1,
     171,    -1,   286,   477,   615,    -1,   255,   639,   615,    -1,
     288,    -1,   278,    -1,   271,    -1,   248,   617,    -1,   616,
     248,   617,    -1,   618,    -1,   619,    -1,   620,    -1,   635,
      -1,   621,    -1,   629,    -1,   622,    -1,   636,    -1,   102,
     276,    -1,   102,   265,    -1,   268,    -1,   283,    -1,   253,
     276,    -1,   253,   265,    -1,    58,   659,    30,    -1,   279,
      -1,    56,   279,    -1,   281,   623,    -1,   281,   158,   623,
     624,   189,    -1,    56,   281,    -1,   626,    -1,   115,    -1,
      -1,   109,   625,    -1,   626,    -1,   625,   109,   626,    -1,
      98,    30,   627,   628,    -1,    -1,   273,    30,    -1,    -1,
     639,   267,    -1,   280,   288,   630,   632,    -1,   280,   288,
     115,   632,    -1,    56,   280,   288,    -1,    98,    30,    -1,
     158,   631,   189,    -1,    30,    -1,   631,   109,    30,    -1,
      -1,   633,    -1,   634,    -1,   633,   634,    -1,   203,   630,
      -1,   138,   630,    -1,   266,    30,    -1,   285,    -1,    56,
     285,    -1,    98,   219,    -1,    98,   256,    -1,   257,   252,
      -1,   269,   639,   282,    -1,   258,   477,    -1,    98,   131,
     477,    -1,    98,    53,   477,    -1,   259,   477,   201,   477,
      -1,   274,   641,    -1,   254,   641,    -1,   277,    -1,   270,
      -1,   287,   252,   479,    -1,   156,   187,    -1,   156,   414,
     187,    -1,   312,   313,    -1,   312,   414,   313,    -1,   314,
     315,    -1,   314,   414,   315,    -1,   155,   647,   186,    -1,
     415,   123,   415,    -1,   647,   109,   415,   123,   415,    -1,
     228,   316,   415,   235,   415,    -1,   228,   316,   647,   235,
     415,    -1,   228,   316,   415,   235,   415,    98,   318,   415,
      -1,   317,   316,   415,   235,   415,    -1,   226,   316,   509,
      -1,   230,   316,   509,    96,   415,    -1,   231,   316,   232,
     233,   509,   239,   415,    -1,   654,    -1,   655,    -1,   656,
      -1,   321,   158,   189,    -1,   319,   158,   189,    -1,   320,
     158,   189,    -1,    30,    -1,    16,    -1,   659,    -1,   660,
      -1,    99,    -1,    40,    -1,    45,    -1,    54,    -1,    46,
      -1,   154,    -1,    49,    -1,   227,    -1,    61,    -1,    63,
      -1,    64,    -1,    72,    -1,    75,    -1,    74,    -1,   213,
      -1,   245,    -1,   661,    -1,    25,    -1,   217,    -1,   129,
      -1,    39,    -1,   263,    -1,    38,    -1,   224,    -1,   223,
      -1,   148,    -1,    44,    -1,   261,    -1,   262,    -1,   276,
      -1,   265,    -1,   253,    -1,   287,    -1,   279,    -1,   281,
      -1,   280,    -1,   285,    -1,   257,    -1,   252,    -1,    80,
      -1,   219,    -1,   256,    -1,    53,    -1,   225,    -1,   238,
      -1,   304,    -1,   232,    -1,   205,    -1,   210,    -1,   209,
      -1,   208,    -1,   207,    -1,   206,    -1,    98,    -1,   113,
      -1,   114,    -1,   188,    -1,    47,    -1,    37,    -1,    68,
      -1,    73,    -1,    60,    -1,    55,    -1,    57,    -1,    79,
      -1,    43,    -1,   149,    -1,    52,    -1,   214,    -1,   172,
      -1,   173,    -1,   170,    -1,    71,    -1,    97,    -1,   118,
      -1,   130,    -1,   131,    -1,   108,    -1,    69,    -1,   137,
      -1,   190,    -1,   102,    -1,    96,    -1,   200,    -1,   128,
      -1,   169,    -1,    94,    -1,    51,    -1,   233,    -1,   103,
      -1,   201,    -1,   119,    -1,   161,    -1,   203,    -1,   152,
      -1,   138,    -1,    77,    -1,    78,    -1,   104,    -1,   202,
      -1,   153,    -1,   184,    -1,   198,    -1,   162,    -1,   139,
      -1,   133,    -1,   168,    -1,   150,    -1,   167,    -1,    34,
      -1,    41,    -1,    59,    -1,   115,    -1,    42,    -1,    58,
      -1,   218,    -1,    50,    -1,    62,    -1,    35,    -1,    48,
      -1,   275,    -1,   251,    -1,   284,    -1,   286,    -1,   255,
      -1,   269,    -1,   282,    -1,   274,    -1,   254,    -1,   268,
      -1,   283,    -1,   273,    -1,   267,    -1,   266,    -1,   250,
      -1,   249,    -1,   258,    -1,   259,    -1,   288,    -1,   278,
      -1,   277,    -1,   272,    -1,   270,    -1,   271,    -1,   231,
      -1,   237,    -1,   234,    -1,   228,    -1,   221,    -1,   220,
      -1,   222,    -1,   239,    -1,   229,    -1,   230,    -1,   236,
      -1,   226,    -1,   235,    -1,    67,    -1,    65,    -1,    76,
      -1,   171,    -1,   204,    -1,   244,    -1,   242,    -1,   243,
      -1,   240,    -1,   241,    -1,   246,    -1,   247,    -1,   248,
      -1,    66,    -1,   297,    -1,   295,    -1,   296,    -1,   301,
      -1,   302,    -1,   303,    -1,   298,    -1,   299,    -1,   300,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,
      -1,    91,    -1,   289,    -1,   290,    -1,   291,    -1,   292,
      -1,   293,    -1,   294,    -1,   305,    -1,   306,    -1,   307,
      -1,   308,    -1,   309,    -1,   310,    -1,   311,    -1,    92,
      -1,   107,    -1,   116,    -1,   174,    -1,   182,    -1,   191,
      -1,   140,    -1,    93,    -1,   117,    -1,   141,    -1,   183,
      -1,   316,    -1,   317,    -1,   318,    -1,   321,    -1,   320,
      -1,   319,    -1,   322,    -1,    26,    -1
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
         0,  1055,  1055,  1056,  1060,  1064,  1072,  1078,  1082,  1091,
    1097,  1105,  1111,  1122,  1127,  1135,  1142,  1149,  1158,  1165,
    1173,  1181,  1189,  1200,  1205,  1212,  1219,  1231,  1241,  1248,
    1255,  1267,  1268,  1269,  1270,  1271,  1276,  1277,  1278,  1279,
    1280,  1281,  1282,  1285,  1290,  1295,  1303,  1311,  1319,  1324,
    1332,  1337,  1345,  1350,  1358,  1363,  1368,  1373,  1381,  1383,
    1386,  1396,  1401,  1409,  1417,  1428,  1435,  1446,  1451,  1459,
    1466,  1473,  1482,  1495,  1503,  1510,  1520,  1527,  1534,  1545,
    1546,  1547,  1548,  1549,  1550,  1551,  1552,  1557,  1563,  1572,
    1579,  1589,  1599,  1600,  1601,  1602,  1603,  1604,  1605,  1606,
    1607,  1608,  1613,  1621,  1629,  1637,  1644,  1652,  1659,  1664,
    1672,  1680,  1694,  1708,  1725,  1730,  1738,  1746,  1757,  1762,
    1771,  1776,  1783,  1788,  1798,  1803,  1812,  1818,  1831,  1836,
    1844,  1855,  1870,  1882,  1897,  1902,  1907,  1912,  1920,  1927,
    1938,  1943,  1953,  1962,  1971,  1980,  1992,  1996,  2002,  2006,
    2016,  2026,  2039,  2045,  2054,  2059,  2066,  2073,  2084,  2094,
    2104,  2114,  2132,  2152,  2156,  2161,  2168,  2172,  2177,  2184,
    2189,  2201,  2208,  2218,  2233,  2234,  2235,  2236,  2237,  2238,
    2239,  2241,  2242,  2243,  2244,  2245,  2250,  2255,  2263,  2280,
    2288,  2296,  2303,  2310,  2321,  2330,  2339,  2348,  2361,  2369,
    2377,  2385,  2400,  2405,  2413,  2427,  2444,  2469,  2477,  2484,
    2495,  2505,  2510,  2523,  2540,  2541,  2542,  2543,  2544,  2545,
    2550,  2551,  2554,  2555,  2556,  2557,  2558,  2561,  2562,  2563,
    2564,  2565,  2570,  2584,  2592,  2597,  2605,  2610,  2615,  2623,
    2632,  2644,  2654,  2667,  2675,  2676,  2677,  2682,  2683,  2684,
    2685,  2686,  2691,  2698,  2708,  2714,  2723,  2733,  2740,  2748,
    2760,  2770,  2780,  2790,  2800,  2810,  2820,  2830,  2841,  2850,
    2860,  2870,  2886,  2895,  2904,  2912,  2918,  2930,  2938,  2948,
    2956,  2968,  2974,  2985,  2987,  2991,  2999,  3003,  3008,  3012,
    3016,  3020,  3030,  3038,  3045,  3051,  3061,  3065,  3069,  3077,
    3085,  3093,  3105,  3113,  3119,  3129,  3135,  3145,  3149,  3159,
    3165,  3171,  3177,  3186,  3195,  3204,  3217,  3221,  3229,  3235,
    3245,  3253,  3262,  3275,  3282,  3294,  3298,  3310,  3317,  3323,
    3332,  3339,  3345,  3356,  3363,  3369,  3378,  3387,  3394,  3405,
    3412,  3424,  3430,  3442,  3448,  3459,  3465,  3476,  3482,  3493,
    3499,  3510,  3519,  3523,  3532,  3536,  3544,  3548,  3558,  3565,
    3574,  3584,  3583,  3597,  3606,  3615,  3628,  3632,  3644,  3648,
    3656,  3659,  3666,  3670,  3679,  3683,  3687,  3695,  3699,  3705,
    3711,  3717,  3727,  3731,  3735,  3743,  3747,  3753,  3763,  3767,
    3777,  3781,  3791,  3795,  3805,  3809,  3819,  3823,  3832,  3836,
    3844,  3848,  3852,  3856,  3866,  3870,  3874,  3881,  3886,  3894,
    3898,  3902,  3906,  3910,  3914,  3922,  3926,  3930,  3938,  3942,
    3946,  3950,  3961,  3967,  3977,  3983,  3993,  3997,  4001,  4039,
    4043,  4053,  4064,  4077,  4086,  4096,  4100,  4109,  4114,  4123,
    4129,  4137,  4143,  4155,  4161,  4171,  4175,  4179,  4183,  4187,
    4193,  4199,  4207,  4211,  4219,  4223,  4234,  4238,  4242,  4248,
    4252,  4266,  4270,  4278,  4282,  4292,  4296,  4300,  4304,  4313,
    4317,  4321,  4325,  4333,  4339,  4349,  4357,  4361,  4365,  4369,
    4373,  4377,  4381,  4385,  4389,  4393,  4398,  4402,  4406,  4410,
    4425,  4429,  4437,  4444,  4451,  4462,  4470,  4474,  4482,  4490,
    4498,  4552,  4556,  4578,  4584,  4590,  4596,  4606,  4610,  4618,
    4626,  4638,  4642,  4650,  4654,  4658,  4666,  4674,  4691,  4699,
    4716,  4735,  4759,  4765,  4776,  4782,  4793,  4802,  4804,  4808,
    4813,  4823,  4826,  4833,  4839,  4845,  4852,  4864,  4867,  4874,
    4880,  4886,  4893,  4904,  4908,  4916,  4920,  4928,  4932,  4936,
    4941,  4950,  4954,  4958,  4962,  4970,  4975,  4983,  4988,  4996,
    5004,  5009,  5014,  5019,  5024,  5029,  5034,  5040,  5048,  5052,
    5069,  5073,  5081,  5089,  5097,  5101,  5109,  5113,  5121,  5129,
    5133,  5137,  5172,  5178,  5184,  5194,  5198,  5202,  5206,  5210,
    5214,  5218,  5225,  5231,  5241,  5249,  5257,  5261,  5265,  5269,
    5273,  5277,  5281,  5285,  5289,  5293,  5301,  5309,  5313,  5317,
    5325,  5332,  5340,  5348,  5352,  5356,  5364,  5368,  5374,  5380,
    5384,  5394,  5402,  5406,  5412,  5421,  5430,  5436,  5442,  5452,
    5469,  5476,  5491,  5518,  5522,  5530,  5538,  5542,  5553,  5570,
    5576,  5582,  5592,  5596,  5602,  5608,  5612,  5618,  5622,  5628,
    5634,  5641,  5651,  5656,  5664,  5670,  5680,  5702,  5711,  5717,
    5730,  5744,  5751,  5757,  5767,  5776,  5784,  5790,  5808,  5816,
    5820,  5827,  5832,  5840,  5844,  5851,  5855,  5862,  5866,  5873,
    5877,  5886,  5899,  5902,  5910,  5913,  5921,  5929,  5937,  5941,
    5949,  5952,  5960,  5972,  5975,  5983,  5995,  6001,  6011,  6014,
    6022,  6026,  6030,  6038,  6041,  6049,  6052,  6060,  6064,  6068,
    6072,  6076,  6084,  6092,  6104,  6116,  6120,  6124,  6132,  6138,
    6148,  6152,  6156,  6160,  6164,  6168,  6172,  6176,  6184,  6188,
    6192,  6196,  6204,  6210,  6220,  6230,  6234,  6242,  6252,  6263,
    6270,  6274,  6282,  6285,  6292,  6297,  6306,  6316,  6319,  6326,
    6330,  6338,  6347,  6354,  6364,  6368,  6375,  6381,  6391,  6394,
    6401,  6406,  6418,  6426,  6438,  6446,  6450,  6458,  6462,  6466,
    6474,  6482,  6486,  6490,  6494,  6502,  6510,  6522,  6526,  6534,
    6548,  6552,  6559,  6564,  6572,  6577,  6586,  6594,  6600,  6610,
    6616,  6626,  6633,  6640,  6665,  6693,  6721,  6725,  6729,  6736,
    6743,  6750,  6762,  6766,  6767,  6780,  6781,  6782,  6783,  6784,
    6785,  6786,  6787,  6788,  6789,  6790,  6791,  6792,  6793,  6794,
    6795,  6796,  6800,  6801,  6802,  6803,  6804,  6805,  6806,  6807,
    6808,  6809,  6810,  6811,  6812,  6813,  6814,  6815,  6816,  6817,
    6818,  6819,  6820,  6821,  6822,  6823,  6824,  6825,  6826,  6827,
    6828,  6829,  6830,  6831,  6832,  6833,  6834,  6835,  6836,  6837,
    6838,  6839,  6840,  6841,  6842,  6843,  6844,  6845,  6846,  6847,
    6848,  6849,  6850,  6851,  6852,  6853,  6854,  6855,  6856,  6857,
    6858,  6859,  6860,  6861,  6862,  6863,  6864,  6865,  6866,  6867,
    6868,  6869,  6870,  6871,  6872,  6873,  6874,  6875,  6876,  6877,
    6878,  6879,  6880,  6881,  6882,  6883,  6884,  6885,  6886,  6887,
    6888,  6889,  6890,  6891,  6892,  6893,  6894,  6895,  6896,  6897,
    6898,  6899,  6900,  6901,  6902,  6903,  6904,  6905,  6906,  6907,
    6908,  6909,  6910,  6911,  6912,  6913,  6914,  6915,  6916,  6917,
    6918,  6919,  6920,  6921,  6922,  6923,  6924,  6925,  6926,  6927,
    6928,  6929,  6930,  6931,  6932,  6933,  6934,  6935,  6936,  6937,
    6938,  6939,  6940,  6941,  6942,  6943,  6944,  6945,  6946,  6947,
    6948,  6949,  6950,  6951,  6952,  6953,  6954,  6955,  6956,  6957,
    6958,  6959,  6960,  6961,  6962,  6963,  6964,  6965,  6966,  6967,
    6968,  6969,  6970,  6971,  6972,  6973,  6974,  6975,  6976,  6977,
    6978,  6979,  6980,  6981,  6982,  6983,  6984,  6985,  6986,  6987,
    6988,  6989,  6990,  6991,  6992,  6993,  6994,  6995,  6996,  6997,
    6998,  6999,  7000,  7001,  7002,  7003,  7004,  7005,  7010
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
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 17642;
  const int xquery_parser::yynnts_ = 326;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 617;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 336;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 590;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17943 "/home/markos/zorba/repo/hof-next/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 7014 "/home/markos/zorba/repo/hof-next/src/compiler/parser/xquery_parser.y"


namespace zorba {

/*
 *  The error member function registers the errors to the driver.
 */
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
      // Error message heuristics: if the current error message has the "(missing comma "," between expressions?)" text,
      // and the old message has a "','" text, then replace the old message with the new one. Unfortunately this 
      // makes the parser error messages harder to internationalize.
      if (msg.find("(missing comma \",\" between expressions?)") != string::npos
          &&
          prevErr->msg.find(zstring("\",\"")) == zstring::npos)
        return;
    }

    // Replace the first occurrence of "unexpected "'QName'"" with "unexpected qualified name %actual_qname%"
    string message = msg;
    int pos;
    std::string unexpected_qname = "unexpected \"'QName'\"";
    if ((pos = message.find(unexpected_qname)) != -1)
      message = message.substr(0, pos) + "unexpected qualified name \"" + driver.symtab.get_last_qname() + "\"" + message.substr(pos+unexpected_qname.length());

    // remove the double quoting "''" from every token description
    while ((pos = message.find("\"'")) != -1 || (pos = message.find("'\"")) != -1)
      message.replace(pos, 2, "\"");
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err::XPST0003, message));
  }
}

} // namespace zorba

