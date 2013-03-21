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
#line 88 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"


#include "common/common.h"

#ifdef WIN32
#pragma warning(disable: 4786)
#endif

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/api/compilercb.h"
#include "store/api/update_consts.h"
#include "compiler/parser/jsoniq_driver.h"
#include "compiler/parser/parser_helpers.h"

#define SYMTAB( n ) driver.symtab.get( (off_t)n )
#define SYMTAB_PUT( s ) driver.symtab.put( s )
#define LOC( p ) driver.createQueryLoc( p )


#define YYDEBUG 1

using namespace std;
using namespace zorba;



/* Line 293 of lalr1.cc  */
#line 69 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"


#include "jsoniq_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 908 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1039 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"

#include "compiler/parser/jsoniq_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 99 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"

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
#line 185 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"

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
  jsoniq_parser::jsoniq_parser (jsoniq_driver& driver_yyarg)
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
        case 112: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 906 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 290 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 905 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 299 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 308 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 340: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 317 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 341: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 326 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 342: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 335 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 343: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 344 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 344: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 353 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 345: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 362 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 346: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 371 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 380 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 389 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 398 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 407 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 416 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 425 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 434 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 443 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 452 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 461 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 470 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 479 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 488 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 497 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 506 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 515 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 524 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 533 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 542 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 551 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 560 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 569 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 370: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 578 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 371: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 587 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 372: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 596 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 373: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 605 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 614 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 623 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 632 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 641 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 650 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 659 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 668 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 677 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 686 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 695 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 704 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 713 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 722 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 731 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 740 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 390: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 749 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 391: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 758 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 392: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 767 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 393: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 776 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 785 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 821 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 830 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 839 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 848 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 857 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 405: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 866 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 406: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 875 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 407: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 884 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 408: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 409: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 902 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 911 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 938 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 947 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 956 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 965 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 974 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 983 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 992 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1001 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 423: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1010 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 424: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1019 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 426: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1028 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 427: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1037 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 428: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1046 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 429: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1055 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 430: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1064 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 431: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1073 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 432: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1082 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 433: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1091 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 434: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1100 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 435: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1109 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 436: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1118 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1127 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 438: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1136 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1145 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1154 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1163 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1172 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1181 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1190 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1199 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1208 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1217 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1226 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1235 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1244 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1253 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1262 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1271 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1280 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1289 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1298 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1307 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1316 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1325 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1334 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1343 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 464: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1352 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 467: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1361 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 468: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1370 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 469: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1379 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 470: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1388 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 471: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1397 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 473: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1406 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 474: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1415 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 475: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1424 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 476: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1433 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 477: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1442 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 478: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1451 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 479: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1460 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 480: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1469 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1478 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1487 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1496 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 484: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1505 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1514 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1523 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1532 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1541 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1550 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1559 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1568 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1577 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1586 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1595 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1604 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1613 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1622 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1631 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1640 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1649 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1658 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1667 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 503: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1676 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1685 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 505: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1694 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1703 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1712 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1721 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 509: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1730 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1739 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1748 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 512: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1757 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 513: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1766 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1775 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1784 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1793 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 520: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1802 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 521: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1811 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 522: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1820 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 524: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1829 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 525: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1838 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 526: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1847 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1856 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1865 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 529: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1874 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 530: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1883 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 531: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1892 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 532: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1901 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 533: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1910 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 534: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1919 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 535: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1928 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 536: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1937 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1946 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 538: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1955 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 539: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1964 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 540: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1973 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1982 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1991 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 543: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2000 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2009 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2018 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2027 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2036 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2045 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2054 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2063 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2072 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2081 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2090 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2099 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2108 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2117 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2126 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2135 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2144 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2153 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2162 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 562: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2171 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 563: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2180 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 564: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2189 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2198 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2207 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 570: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2216 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 571: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2225 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 572: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2234 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 573: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2243 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 574: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2252 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 575: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2261 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 576: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2270 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 577: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2279 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 578: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2288 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2297 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2306 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 581: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2315 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 582: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2324 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 585: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2333 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 586: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2342 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 587: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2351 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2360 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 589: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2369 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 590: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2378 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 592: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2387 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 593: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2396 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2405 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2414 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 597: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2423 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 598: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2432 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 600: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2441 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 603: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2450 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 604: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2459 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 605: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2468 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 606: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2477 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 607: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2486 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 608: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2495 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 609: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2504 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 610: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2513 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 611: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2522 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 612: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2531 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 613: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2540 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 614: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2549 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 618: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2558 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 621: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2567 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 622: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2576 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 626: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2585 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 627: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2594 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 628: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2603 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 629: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2612 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 630: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2621 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 631: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2630 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 632: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2639 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 633: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2648 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 634: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2657 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 635: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2666 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 636: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2675 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 637: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2684 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 638: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2693 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 639: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2702 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 640: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2711 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 641: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2720 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 642: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2729 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 643: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2738 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 644: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2747 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 651: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2756 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 652: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2765 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 653: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2774 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
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
#line 133 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2871 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"

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
#line 1057 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1061 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1065 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1073 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1079 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1083 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1092 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1098 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1106 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1112 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1123 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1128 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1136 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1143 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1150 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1159 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1166 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1174 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1182 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1190 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1201 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1206 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1213 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1220 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1232 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1242 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1249 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1256 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 1291 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1296 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1304 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1312 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1320 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1325 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1333 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1338 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1346 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1351 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1359 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1364 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1369 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1374 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1387 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1397 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1402 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1410 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1418 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1429 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1436 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1447 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1452 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1460 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1467 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1474 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1483 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 1496 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1504 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1511 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1521 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1528 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1535 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1558 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1564 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1573 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1580 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1590 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1599 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1600 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1601 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1602 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1603 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1604 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1605 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1606 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1607 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1608 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1614 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1622 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1630 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1638 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1645 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1653 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1660 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1665 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1673 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1681 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 1695 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 1709 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 1726 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1731 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1739 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1747 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1758 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1763 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1772 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1777 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1784 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1789 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1799 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1804 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1813 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1819 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1832 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1837 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1845 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 1856 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 1871 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 1883 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 1898 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1903 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1908 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1913 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1921 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1928 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1939 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1944 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1954 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 1963 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 1972 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 1981 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 1993 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1997 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 2003 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2007 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2017 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2027 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2040 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 2046 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 2055 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2060 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2067 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2074 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2086 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2096 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2106 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2117 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2133 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2153 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2157 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2161 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2169 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2173 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2177 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2185 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2190 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2202 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 2209 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 2219 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2251 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2256 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 2264 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2281 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2289 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 2297 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2304 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2311 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2322 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2331 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2340 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2349 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2362 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 2370 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 2378 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2386 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2401 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2406 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2414 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2428 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2445 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2470 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2478 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2485 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2496 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2506 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2511 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2524 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2571 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2585 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2593 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2598 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2606 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2611 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2616 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2624 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2633 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2645 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2655 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2668 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2692 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2699 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2709 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2715 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2724 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2734 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2741 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2749 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2761 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2771 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2781 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2791 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2801 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2811 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2821 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2831 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2842 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2851 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2861 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2871 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2887 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2896 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2905 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2913 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2919 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2931 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2939 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2949 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2957 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 2969 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2975 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2988 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2992 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 3000 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 3004 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3013 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3017 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3021 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3031 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 3039 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3046 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3052 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3062 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3066 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3070 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3078 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3086 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3094 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3106 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3114 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3120 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3130 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3136 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3146 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3150 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3160 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3166 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3172 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3178 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3187 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3196 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3205 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3218 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3222 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3230 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3236 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3246 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3254 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3263 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3276 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3283 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3295 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3299 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3311 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3318 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3324 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3333 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3340 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3346 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3357 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3364 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3370 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3379 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3388 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3395 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3406 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3413 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3425 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3431 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 3443 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3449 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3460 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3466 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3477 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3483 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3494 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3500 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3511 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3520 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3524 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3533 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3537 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3545 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3549 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3559 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3566 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3575 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3584 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3589 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3598 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3607 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3616 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3629 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3633 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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
#line 3645 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3649 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3656 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3660 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3667 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3671 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3680 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3684 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3688 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3696 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3700 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3706 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3712 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3718 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3728 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3732 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3736 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3744 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3748 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3754 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3764 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3768 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3778 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3782 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3792 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3796 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3806 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3810 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3820 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3824 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3833 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3837 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3845 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3849 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3853 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3857 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3867 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3871 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3875 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3882 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3887 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3895 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3899 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3903 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3907 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3911 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3915 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3927 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3931 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3939 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3943 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3947 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3951 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3962 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3968 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3978 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3984 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3994 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3998 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4002 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4065 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4087 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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

  case 431:

/* Line 690 of lalr1.cc  */
#line 4115 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4279 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4283 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4293 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4297 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4301 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4305 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4314 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4318 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4322 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4326 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4334 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4340 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4350 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4358 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4362 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4366 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4370 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4374 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4378 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4382 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4386 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4390 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4394 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4399 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4403 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4407 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4411 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4415 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
          ArgList *al = new ArgList( LOC((yyloc)) );
          al->push_back(sl);
          (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), al, false); 
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4426 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4430 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4438 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4445 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4452 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4463 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4471 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4475 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4483 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4491 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4499 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4553 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4557 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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

  case 473:

/* Line 690 of lalr1.cc  */
#line 4579 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4585 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4591 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4597 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4607 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4611 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4619 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4627 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4639 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4643 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4651 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4655 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4659 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4667 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4675 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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

  case 488:

/* Line 690 of lalr1.cc  */
#line 4692 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4700 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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

  case 490:

/* Line 690 of lalr1.cc  */
#line 4719 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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

  case 491:

/* Line 690 of lalr1.cc  */
#line 4738 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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

  case 492:

/* Line 690 of lalr1.cc  */
#line 4760 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4766 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4777 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4783 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4794 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4809 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4814 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4823 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4827 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4834 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4840 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4846 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4853 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4864 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4868 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4875 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4881 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4887 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4894 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4905 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4909 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4917 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4921 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4929 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4933 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4937 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4942 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4951 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4955 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4959 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4963 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4971 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4976 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4984 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4989 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4997 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 5005 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 5010 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 5015 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 5020 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 5025 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 5030 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 5041 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 5049 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 5053 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 5070 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 5074 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 5082 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 5090 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 5098 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 5102 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 5110 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 5114 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 5122 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 5130 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 5134 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 5138 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 5173 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 5179 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 5185 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 5195 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 5199 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 5203 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 5207 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 5211 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 5215 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 5219 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 5226 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5232 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5242 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5250 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5258 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5262 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5266 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5270 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5274 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5278 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5282 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5286 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5290 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5294 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5302 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5310 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5314 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5318 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5326 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5333 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5341 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5349 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5353 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5357 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5365 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5369 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5375 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5381 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5385 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5395 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5403 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5407 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5413 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5422 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5431 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5437 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5443 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5453 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5470 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5477 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5492 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5519 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5523 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5531 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5539 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5543 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5554 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5571 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5577 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5583 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5593 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5597 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5603 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5609 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5613 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5619 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5623 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5629 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5635 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5652 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5657 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5665 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5671 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5681 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5703 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5712 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5718 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5731 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5745 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5752 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5758 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5768 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5777 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5785 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5791 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5809 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5817 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5821 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5828 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5833 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5841 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5845 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5852 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5856 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5863 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5867 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5874 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5878 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5887 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5899 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5903 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5910 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5914 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5922 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5930 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5938 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5942 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5949 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5953 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5961 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5972 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5976 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5984 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5996 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 6002 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 6011 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 6015 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 6023 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 6027 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 6031 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 6038 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 6042 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 6049 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 6053 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 6061 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 6065 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 6069 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 6073 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 6077 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 6085 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 6093 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 6105 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 6117 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 6121 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 6125 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 6133 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 6139 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 6149 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 6153 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 6157 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 6161 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 6165 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 6169 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 6173 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 6177 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6185 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6189 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6193 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6197 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6205 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6211 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6221 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6231 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6235 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6243 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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

  case 708:

/* Line 690 of lalr1.cc  */
#line 6253 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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

  case 709:

/* Line 690 of lalr1.cc  */
#line 6264 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6271 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6275 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6282 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6286 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6293 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6298 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6307 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6316 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6320 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6327 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6331 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6339 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6348 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6355 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6365 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6369 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6376 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6382 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6391 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6395 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6402 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6407 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6419 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6427 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6439 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6447 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6451 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6459 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6463 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6467 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6475 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6483 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6487 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6491 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6495 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6503 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6511 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6523 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6527 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6535 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6549 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6553 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6560 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6565 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6573 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6578 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6587 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6595 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6601 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6611 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6617 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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

  case 761:

/* Line 690 of lalr1.cc  */
#line 6627 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6634 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6641 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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

  case 764:

/* Line 690 of lalr1.cc  */
#line 6666 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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

  case 765:

/* Line 690 of lalr1.cc  */
#line 6694 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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

  case 766:

/* Line 690 of lalr1.cc  */
#line 6722 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6726 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6730 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6737 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6744 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6751 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6768 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
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

  case 776:

/* Line 690 of lalr1.cc  */
#line 6781 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6782 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6783 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6784 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6785 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6786 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6787 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6788 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6789 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6790 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6791 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6792 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6793 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6794 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6795 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 6796 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6801 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6802 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6803 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6804 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6805 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6806 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6807 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6808 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6809 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 6810 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6811 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6812 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6813 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6814 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6815 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6816 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6817 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6818 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6819 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6820 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6821 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6822 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6823 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6824 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6825 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6826 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6827 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6828 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6829 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6830 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6831 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6832 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6833 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6834 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6835 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6836 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6837 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6838 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6839 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6840 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6841 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6842 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6843 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6844 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6845 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6846 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6847 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6848 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6849 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6850 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6851 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6852 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6853 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6854 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6855 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6856 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6857 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6858 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6859 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6860 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6861 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6862 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6863 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6864 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6865 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6866 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6867 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6868 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6869 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6870 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6871 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6872 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6873 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6874 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6875 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6876 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6877 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6878 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6879 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6880 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6881 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6882 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6883 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6884 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6885 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6886 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6887 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6888 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6889 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6890 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6891 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6892 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6893 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6894 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6895 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6896 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6897 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6898 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6899 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6900 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6901 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6902 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6903 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6904 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6905 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6906 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6907 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6908 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6909 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6910 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6911 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6912 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6913 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6914 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6915 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6916 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6917 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6918 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6919 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6920 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6921 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6922 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6923 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6924 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6925 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6926 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6927 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6928 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6929 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6930 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6931 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6932 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6933 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6934 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6935 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6936 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6937 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6938 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6939 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6940 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6941 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6942 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6943 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6944 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6945 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6946 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6947 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6948 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6949 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6950 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6951 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6952 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6953 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6954 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6955 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6956 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6957 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 6958 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 6959 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 6960 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 6961 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 6962 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 6963 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 6964 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 6965 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 6966 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 6967 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 6968 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 6969 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 6970 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 6971 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 6972 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 6973 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 6974 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 6975 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 6976 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 6977 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 6978 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 6979 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 6980 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 6981 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 6982 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 6983 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 6984 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 6985 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 6986 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 6987 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 6988 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 6989 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 6990 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 6991 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 6992 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 6993 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 6994 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 6995 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 6996 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 6997 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 6998 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 6999 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 7000 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 7001 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 7002 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 7003 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 7004 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 7005 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 7010 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 11983 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"
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
  const short int jsoniq_parser::yypact_ninf_ = -1462;
  const short int
  jsoniq_parser::yypact_[] =
  {
      5297,  6811,  6811,  6811,  6811, -1462, -1462,   125,   431, -1462,
     771,    80, -1462, -1462, -1462,   438, -1462, -1462, -1462,   465,
   -1462,   484,   706,   537,   633,   724, -1462,    -7, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462,   586, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462,   395, -1462,   677, -1462,   684,   738, -1462,
     520, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462,   734, -1462, -1462, -1462, -1462, -1462, -1462, -1462,   794,
   -1462, -1462, -1462, -1462, -1462, 14844, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462,   798, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462,  5905,  9227,  9529, 14844, -1462,
   -1462,   770, -1462, -1462, -1462, -1462,   792, -1462, -1462, -1462,
    4690, -1462,  4995, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462,   803, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462,    60,   757, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462,   208, -1462,   266, -1462,  -101,   -80, -1462,
   -1462, -1462, -1462, -1462, -1462,   866, -1462,   749,   765,   744,
   -1462, -1462,   851,   858, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462,  9831, 10133, -1462,
     698, -1462, -1462, -1462, -1462, -1462,  5601,  7113,  1015, -1462,
    7415, -1462, -1462,   686,    86, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,    88,
   -1462, -1462, -1462, -1462, -1462, -1462,   545, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462,  6811, -1462, -1462, -1462, -1462,
      29, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,   182,
   -1462,   825, -1462, -1462, -1462,   590, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462,   850,   929, -1462,  1096,   773,   924,
     575,   666,   678,   635, -1462,   975,   828,   925,   927, 11039,
   -1462,   834, -1462, -1462,    14, -1462, -1462, -1462, -1462,   820,
     911, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462,   890,   881, -1462, -1462, -1462, -1462, -1462,   855,
   -1462,  6811,   856,   859,   862,  6811,   479,   479,  1020,   622,
     679,   703, 15133, 14844,   247,  1004, 14844,   899,   934,   700,
    4690,   731,   808, 14844, 14844,   751,   265,    74, -1462, -1462,
   -1462,  4690,  6811,  6811, 11341, 14844, -1462,   775,   776, 14844,
     938,    50,   908, 11341,  1063,   200,    99, 14844,   945,   922,
     960, -1462, 11341, 14844,  6811, 11341, 11341, 14844,  6811,   915,
     917, 11341, 14844, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462,   931, -1462, 14844, -1462,   885,  6207,
     955,   281,   921,   926,   930, 14844,  6811, -1462,   932,   233,
   -1462,   687, -1462,    95,  1044, 11341, 11341, -1462,   164, -1462,
   -1462, -1462,  1073, 11341,   875, -1462,  1065, 11341, 11341, 11945,
   11341, 11341, 11341, 11341, 11945, 11341,   860,   865, 14844,   906,
     907, 11341, 11341,  5905,   853, -1462,    53, -1462,    34, 11341,
    7113, -1462, -1462, -1462, -1462, -1462,   771,   724,    97,   113,
    1098,  7717,  2835,  8019,  3158,   794, -1462, -1462,   231,   794,
   -1462, 11341,  3782, -1462,   982,   474,    -7,   933,   936,   940,
    6811, 11341, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   11643, 11643, 11643, -1462, 11643, 11643, -1462, 11643, -1462, 11643,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, 11643, 11643,  1033,
   11643, 11643, 11643, 11643, 11643, 11643, 11643, 11643, 11643, 11643,
   11643, 11643,   873,  1014,  1017,  1018, -1462, -1462, -1462, 11945,
   10435, -1462, 11341,  8321,   959, -1462,  4690,   966,  8623, -1462,
   -1462, -1462, -1462,   292, -1462,   322, -1462, -1462, -1462, -1462,
   -1462, -1462,  1009,  1010,   537,  1090, -1462, -1462, 15133,  1049,
     535, 14844,   961,   962,  1049,  1020,   992,   988, -1462, -1462,
   -1462,   131,   878,  1031,   840, 14844,   984, 11341,  1022, 14844,
   14844, -1462,   995,   957,   958,   184,  1037, -1462,    43, -1462,
   -1462,  1037, 14844,    21, 14844,  1051,   430, -1462,  6811, -1462,
     108, -1462,  4690,  1050,  1103,  4690,  1020,  1053,   282, 14844,
   11341,    -7,   343,   356, -1462,   542,   967,   114,   136,   997,
   -1462,   968,  6811,  6811,   349,   306, 11341,   360, -1462, -1462,
   11341, 11341, -1462, 11341, 11341, 11341, -1462, 11341, -1462, 11341,
   -1462, 14844,  1044, -1462,   293,   357,   404, -1462, -1462, -1462,
     414, -1462,   280, -1462, -1462,   820,    44,   263,     2,   116,
    1059,   485,   918,   935,   937,   139, -1462,  1016, -1462, -1462,
     971,   148,  6207,   423,  4094,   853, -1462, -1462, -1462,   939,
   -1462,   686,   682,  1125,   611, -1462, -1462,   127, -1462, -1462,
   -1462,   130, -1462,    84, -1462, -1462, -1462, -1462, -1462,  3470,
   -1462, -1462, -1462, 14844,   994, 11341,  1047, -1462, -1462, -1462,
     929, -1462, -1462, -1462, -1462, -1462, 11643, -1462, -1462, -1462,
      45, -1462,   666,   666,   516,   678,   678,   678,   678,   635,
     635, -1462, -1462, 13977, 13977, 14844, 14844, -1462, -1462,   428,
     234, -1462, -1462, -1462,   446, -1462, -1462, -1462, -1462,   459,
     479, -1462, -1462,    23,   616,   755, -1462,   537, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,  1049, -1462,
    1030, 14266,  1024, 11341, -1462, -1462, -1462,  1076,  1020,  1020,
    1049, -1462,   835,  1020,   692, 14844,   353,   480,  1139, -1462,
   -1462,   887,   464, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462,   131,    36,   948,   643, 11341, -1462,
   14844,  1082,   879,  1020, -1462, -1462,  1027, 14555,  1055, 13977,
    1066, 11341,    89,  1036,    46,   557,   923, -1462, -1462,   607,
      21,  1076, 13977,  1068,  1095,  1007,   990,  1060,  1020,  1034,
    1061,  1099,  1020, 11341,   -26, -1462, -1462, -1462,  1045,  1081,
   11341, 11341,  1056, -1462,  1100,  1102,  6811, -1462,  1023,  1026,
    1058, 11341,  1064,  1028, 11341, -1462,  1087,   158,   163,   183,
    1178, -1462,   309, -1462,   351,  1070, -1462, -1462,  1185, -1462,
     745, 11341, 11341, 11341,   746, 11341, 11341, 11341, 11341, 11341,
   11341, 11341, 11341, 11341, 11945,  1101, 11341, 11341, -1462,  8925,
     119,   969, -1462, -1462, -1462, -1462, -1462, -1462,   302, -1462,
   -1462, 11341,   132,    65,    84,  8019,  3158,  8019,  1137, -1462,
   -1462, 11341,   764,  1114, -1462, 14844,  1118, -1462, -1462, 11341,
      45,   725,   253, -1462,   941,   370,   972,   981, -1462, -1462,
     808, -1462,   964,   658,  1079,  1086,  1088,  1092,  1093,  1104,
    1106,  1107,  1108,  1109,  1111, 14266,  1112,  1113,  1115,  1117,
    1120,  1121, -1462,   594, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462,  1126, -1462, -1462,
   -1462, -1462, 10737, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462,   772, -1462,  1204,   806, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462,   970, -1462, -1462,  1215, -1462,
   -1462, -1462, -1462, -1462,   534,  1218, -1462,   730, -1462, -1462,
   -1462,  1079,  1086,  1088,  1093,  1104,  1106,  1107,  1108,  1109,
    1113,  1115,  1117,  1120, -1462,   594,   594, 11945,   963,   946,
   -1462,  1076,    36,  1032,  1067,  6811, 14844, -1462,    57, -1462,
   14844, -1462, 11341,  1127, 11341,  1128, 11341,    94,  1131, 11341,
    1133, -1462,  1163,  1164, 11341, 14844,   909,  1206, -1462, -1462,
   -1462, -1462, -1462, -1462, 13977, -1462,  6811,  1020,  1177, -1462,
   -1462, -1462,  1020,  1177, -1462, 11341,  1143,  6811, 14844, -1462,
   -1462, 11341, 11341,    66, -1462,    25,   801, -1462, 12532,   817,
   -1462,   826, -1462,  1105, -1462, -1462,  6811, -1462, 11341, -1462,
   -1462, 11341,  1089,  1100,  1186, -1462,  1156, -1462,   481, -1462,
   -1462,  1285, -1462, -1462,  6811, 14844, -1462,   606, -1462, -1462,
   -1462,  6811,  1116,  1062,  1072, -1462, -1462, -1462,  1074,  1075,
   -1462, -1462, -1462,  1195, -1462, -1462, -1462, -1462,  1057,   -10,
   14844,  1110, -1462,  1136,  1155,  1157,  1161, -1462,   825,   916,
    4094,   969, -1462,  6509,  4094, -1462, -1462,  1125,   334, -1462,
   -1462, -1462,  1114, -1462,  1020, -1462,   854, -1462,    78,  1209,
   -1462, 11341,    67,  1047,   460,  1129, -1462,    45,  1069, -1462,
   -1462,   224, -1462,   377,    76,  1071,    45,   377, 11643, -1462,
     248, -1462, -1462, -1462, -1462, -1462, -1462,    45,  1170,  1042,
     878,    76, -1462, -1462,  1039,  1248, -1462, -1462, -1462,  1141,
     156, 12821, 12243,  1142,  4392, 14844, 14844,  1144, 13110,  1145,
    1146,  1147,  1148,  1149,  1151,  1152,  1153, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
    1302,     7,  1313,     7,  1077,  1235, -1462, -1462,  1173, 14844,
    1097, -1462, -1462, 11945, -1462,  1160, -1462, 11341,  1198, -1462,
   -1462, 11341, -1462,   506, -1462, 11341,  1200, 11341, -1462, 11341,
   14844, 14844, -1462,   799, -1462, 11341, -1462,  1223,  1225,  1256,
    1020,  1177, -1462, 11341,  1169, -1462, -1462, -1462,  1171, -1462,
      28, 11341,  6811,  1172,   283, -1462, 14844,   440, -1462, 13399,
      81, -1462, 13688,  1175, -1462, -1462,  1179, -1462, -1462, 11341,
     827,  1178, 14844,   691, -1462,  1180,  1178, 14844, -1462,  1181,
   -1462, 11341, 11341, 11341, 11341,  1040, 11341, 11341, -1462, 11341,
   11341, 11341, 11341,  8925,   458, -1462, -1462, -1462, -1462, -1462,
    1209, -1462, -1462, -1462,  1020, 11341, -1462,  1213, -1462, -1462,
   -1462, -1462,  1182, 11643, -1462, -1462, -1462, -1462, -1462,   314,
   11643, 11643,   409, -1462,   972, -1462,   624, -1462,   981,    45,
    1214, -1462, -1462,  1091, -1462, -1462, -1462, -1462, -1462, -1462,
    1187,  1188, -1462,   469,   483,  1268,  1189, -1462,   488, -1462,
    1190, -1462,  1191,  1196,  1197, -1462, -1462,   492,   493, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,   305,   305,
   -1462,     7, -1462, -1462,   501, -1462,  1340,    76,  1273,  1199,
   11945,   -36,  1085,  1203, -1462, -1462, 11341, -1462, 11341,  1238,
   -1462, 11341, -1462, -1462, -1462,  1329, -1462, -1462,  8925, 11341,
    1020, -1462, -1462, -1462, 11341, 11341, -1462, -1462, -1462,  8925,
    8925,  1293,  6811, 13977, 14844,   563, 14844, 11341, 14844,   583,
    8925, -1462,   274,    24,  1178, 14844, -1462,  1192,  1178, -1462,
   -1462, -1462, -1462, -1462, 11341, -1462, -1462, -1462,   204,   217,
     218, 11341, -1462, -1462, -1462,  1282, 11341, -1462,   678, 11643,
   11643,   516,   610, -1462, -1462, -1462, -1462, -1462, -1462, 11341,
   -1462, -1462, -1462, 14844, -1462, 14844, -1462, 13977, -1462, 13977,
    1296, -1462, -1462, -1462, -1462, 14844, -1462, 14844, -1462, -1462,
   -1462, -1462,  1363, -1462, -1462, -1462,  1130,  1286, -1462, -1462,
    1287, -1462,   844, 14844,  1278,  1174, 14844, 11945, -1462, -1462,
   11341, -1462,  1280, -1462, -1462,  1177, -1462, -1462, 13977, -1462,
   -1462, -1462,  1307, 11341,  1216, -1462,  1309,  8925, -1462, 14844,
     680,   713, -1462,  1207,  1178, -1462,  1210, -1462,  1208,  1100,
    1102,   487, -1462,  1282,   516,   516, 11643,   498,  1221,  1222,
    1266,  1224,  1226, -1462, -1462, 13977,  1227,  1228, -1462, -1462,
    1273, 11945, -1462,  1209,  1119, 14844,  1294,  1193,  1287, -1462,
   14844,   636, 13977,  6811, 13977,  1230, -1462, -1462,  1324,   788,
   -1462, -1462, -1462, -1462,  1236,   891, -1462, -1462, -1462,  1229,
   -1462,  8925,   833, -1462, -1462,   516, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, 11341,  1122,
   14844,  1305, -1462,  6811,   653, -1462, -1462,   667, 11341, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462,  1310, -1462,  1132,  1124,
   14844, -1462, -1462, 11341,  8925, 14844,  1134, 11341,  1138,  1234,
   11945, -1462, 11945,  8925, -1462,  1231,  1150, 14844,  1217,  1315,
   14844,  1154, 11945, -1462
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       165,   168,   168,   168,     0,   793,   998,   120,   122,   602,
     885,   894,   834,   798,   796,   777,   886,   889,   841,   802,
     778,   780,     0,   895,   782,   892,   863,   843,   818,   779,
     838,   839,   890,   887,   837,   784,   893,   785,   786,   934,
     946,   933,   835,   854,   848,   787,   836,   789,   788,   935,
     872,   873,   840,   815,   956,   957,   958,   959,   960,   961,
     962,   963,   964,   965,   966,   980,   987,   862,   858,   849,
     829,   776,   857,   865,   874,   981,   853,   462,   830,   831,
     888,   982,   988,   850,   867,     0,   468,   464,   860,   795,
     851,   852,   881,   855,   871,   880,   986,   989,   801,   842,
     883,   463,   870,   876,   781,     0,     0,     0,     0,   401,
     868,   879,   884,   882,   861,   847,   936,   845,   846,   983,
       0,   400,     0,   984,   990,   877,   832,   856,   985,   878,
     859,   866,   875,   869,   937,   823,   828,   827,   826,   825,
     824,   790,   844,     0,   794,   891,   816,   925,   924,   926,
     800,   799,   819,   931,   783,   923,   928,   929,   920,   822,
     864,   922,   932,   930,   921,   820,   927,   941,   942,   939,
     940,   938,   791,   943,   944,   945,   911,   910,   897,   814,
     807,   904,   900,   817,   813,   912,   913,   803,   804,   797,
     806,   909,   908,   905,   901,   918,   919,   917,   907,   903,
     896,   805,   916,   915,   809,   811,   810,   902,   906,   898,
     812,   899,   808,   914,   967,   968,   969,   970,   971,   972,
     948,   949,   947,   953,   954,   955,   950,   951,   952,   821,
     973,   974,   975,   976,   977,   978,   979,     0,     0,   991,
     992,   993,   996,   995,   994,   997,   165,   165,     0,     2,
     165,     9,    11,    23,     0,    28,    31,    36,    37,    38,
      39,    40,    41,    42,    32,    58,    59,    33,    34,     0,
      76,    79,    80,    35,    81,    82,     0,   118,    83,    84,
      85,    86,    18,   162,   163,   164,   171,   174,   454,   175,
       0,   176,   177,   178,   179,   180,   181,   182,   185,     0,
     211,   219,   214,   246,   252,     0,   244,   245,   221,   215,
     184,   216,   183,   217,   220,   352,   354,   356,   366,   368,
     372,   374,   377,   382,   385,   388,   390,   392,   394,     0,
     398,   405,   404,   406,     0,   424,   407,   429,   430,   431,
     438,   445,   460,   446,   447,   448,   451,   452,   449,   453,
     477,   478,   450,   481,   483,   484,   485,   482,   530,   531,
     532,   533,   534,   535,   536,   461,    43,   222,   223,   225,
     224,   226,   218,   456,   457,   458,   455,   228,   231,   227,
     229,   230,     0,   775,   792,   885,   894,   892,   794,     0,
     166,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,   128,
     129,     0,     0,     0,     0,     0,   256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     274,   275,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   192,   777,   802,   780,   833,   895,   782,
     843,   784,   854,   787,   789,   788,   872,   776,   831,   855,
     879,   936,   937,   931,   923,   929,   920,   820,   941,   942,
     939,   791,   943,   992,   465,   775,     0,   187,     0,     0,
     211,     0,   782,   789,   788,     0,   168,   750,   943,     0,
     219,     0,   466,     0,   497,     0,     0,   773,     0,   774,
     427,   428,     0,     0,     0,   526,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   752,     0,   754,     0,     0,
     165,     3,     4,     1,    10,    12,     0,     0,     0,     0,
       6,   165,     0,   165,     0,     0,   119,   172,     0,     0,
     190,     0,     0,   199,     0,     0,     0,     0,     0,     0,
       0,     0,   204,   232,   251,   247,   253,   248,   250,   249,
       0,     0,     0,   417,     0,     0,   415,     0,   361,     0,
     416,   409,   414,   413,   412,   411,   410,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   403,   402,   399,     0,
       0,   425,     0,     0,   439,   442,     0,     0,     0,   538,
     540,   544,   546,     0,   124,     0,   772,    47,    44,    45,
      48,    49,     0,     0,     0,     0,    50,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   609,   610,
     611,     0,   103,   142,     0,     0,   112,     0,     0,     0,
       0,   127,     0,     0,     0,     0,   255,   257,     0,   234,
     235,   254,     0,     0,     0,   134,     0,   138,   168,   480,
       0,    60,     0,    69,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,   323,     0,     0,     0,     0,     0,
     600,     0,     0,     0,     0,   194,     0,     0,   188,   186,
       0,     0,   756,     0,     0,     0,   465,     0,   751,     0,
     467,   498,   497,   494,     0,     0,     0,   528,   527,   426,
       0,   525,     0,   622,   623,   763,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   628,     0,   202,   203,
       0,     0,     0,     0,     0,   207,   208,   753,   755,     0,
       5,    24,     0,    25,     0,     7,    29,     0,    15,     8,
      30,     0,    19,   885,    77,    16,    78,    20,   193,     0,
     191,   212,   213,     0,     0,     0,     0,   205,   233,   292,
     353,   355,   359,   365,   364,   363,     0,   360,   357,   358,
       0,   369,   376,   375,   373,   379,   380,   381,   378,   383,
     384,   387,   386,     0,     0,     0,     0,   408,   422,     0,
       0,   473,   440,   475,     0,   443,   459,   479,   471,     0,
       0,   121,   123,     0,     0,     0,   102,     0,    92,    94,
      95,    96,    97,    99,   100,   101,    93,    98,    88,    89,
       0,     0,   108,     0,   104,   106,   107,   114,     0,     0,
      87,    46,     0,     0,     0,     0,     0,     0,     0,   700,
     705,     0,     0,   701,   735,   688,   690,   691,   692,   694,
     696,   695,   693,   697,     0,     0,     0,     0,     0,   111,
       0,   144,     0,     0,   543,   537,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   237,     0,
     242,   140,     0,     0,   135,     0,     0,     0,     0,     0,
       0,    62,     0,     0,     0,   273,   279,   276,     0,     0,
       0,     0,     0,   542,     0,     0,     0,   418,     0,     0,
       0,     0,   195,     0,     0,   757,     0,     0,     0,     0,
     497,   495,     0,   486,     0,     0,   469,   470,     0,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,     0,
       0,     0,   435,   436,   437,   434,   636,   433,     0,   432,
     209,     0,     0,     0,     0,   165,     0,   165,     0,   173,
     243,     0,   307,   303,   305,     0,   293,   294,   362,     0,
       0,     0,     0,   666,   370,   639,   643,   645,   647,   649,
     652,   659,   660,   668,   777,   778,   780,   895,   779,   784,
     785,   786,   787,   776,   781,     0,   790,   783,   996,   995,
     994,   997,   389,   549,   555,   556,   575,   566,   574,   573,
     572,   571,   568,   570,   567,   569,   559,   603,   604,   560,
     561,   766,   767,   768,   564,   391,   393,   396,   565,   395,
     423,   444,     0,   441,   472,   125,    56,    57,    54,    55,
     131,   130,     0,    90,     0,     0,   109,   110,   115,    74,
      75,    52,    53,    73,   706,     0,   709,   736,     0,   699,
     698,   703,   702,   734,     0,     0,   711,     0,   707,   710,
     689,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   146,   148,     0,     0,     0,
     113,   116,     0,     0,     0,   168,     0,   259,     0,   548,
       0,   260,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,     0,     0,     0,   286,     0,   283,   288,
     241,   141,   136,   139,     0,   189,     0,     0,    71,    65,
      68,    67,     0,    63,   277,     0,     0,   168,     0,   321,
     325,     0,     0,     0,   328,     0,     0,   334,     0,     0,
     341,     0,   345,     0,   420,   419,   168,   196,     0,   198,
     322,     0,     0,     0,     0,   498,     0,   488,     0,   521,
     518,     0,   522,   523,     0,     0,   517,     0,   492,   520,
     519,     0,     0,     0,     0,   615,   616,   612,     0,     0,
     620,   621,   617,   759,   760,   626,   764,   624,     0,     0,
       0,     0,   630,   782,   789,   788,   943,   201,     0,     0,
       0,   631,   632,     0,     0,   210,   762,    26,     0,    17,
      21,    22,   304,   316,     0,   317,     0,   308,   309,   310,
     311,     0,   296,     0,     0,     0,   650,   663,     0,   367,
     371,     0,   682,     0,     0,     0,     0,     0,     0,   638,
     640,   641,   677,   678,   679,   681,   680,     0,     0,   654,
     653,     0,   657,   661,   675,   673,   672,   665,   669,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   552,   554,   553,
     550,   397,   474,   476,   133,   132,    91,   105,   723,   704,
       0,   728,     0,   728,   717,   712,   147,   149,     0,     0,
       0,   117,   145,     0,    27,     0,   258,     0,     0,   272,
     264,     0,   268,     0,   262,     0,     0,     0,   281,     0,
       0,     0,   240,   284,   287,     0,   137,     0,     0,    70,
       0,    64,   278,     0,     0,   324,   326,   331,     0,   329,
       0,     0,     0,     0,     0,   335,     0,     0,   349,     0,
       0,   342,     0,     0,   346,   421,     0,   197,   758,     0,
       0,   497,     0,     0,   529,     0,   497,     0,   493,     0,
      14,     0,     0,     0,     0,     0,     0,     0,   629,     0,
       0,     0,     0,     0,     0,   633,   637,   320,   318,   319,
     312,   313,   314,   306,     0,     0,   301,     0,   295,   667,
     658,   664,     0,     0,   737,   738,   748,   747,   746,     0,
       0,     0,     0,   739,   644,   745,     0,   642,   646,     0,
       0,   651,   655,     0,   676,   671,   674,   670,   582,   577,
       0,     0,   592,     0,     0,     0,     0,   562,     0,   580,
       0,   583,     0,     0,     0,   581,   586,     0,     0,   557,
     608,   551,   576,   770,   771,   769,   558,   724,     0,     0,
     722,   729,   730,   726,     0,   721,     0,   719,     0,     0,
       0,     0,     0,     0,   539,   261,     0,   270,     0,     0,
     266,     0,   269,   282,   290,   291,   285,   239,     0,     0,
       0,    66,   280,   545,     0,     0,   332,   336,   330,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   541,     0,     0,   497,     0,   524,     0,   497,   547,
     613,   614,   618,   619,     0,   625,   765,   627,     0,     0,
       0,     0,   634,   315,   302,   297,     0,   662,   749,     0,
       0,   741,     0,   687,   686,   685,   684,   683,   648,     0,
     740,   578,   579,     0,   596,     0,   593,     0,   605,     0,
       0,   585,   584,   591,   599,     0,   589,     0,   587,   733,
     732,   731,     0,   725,   718,   716,     0,   713,   714,   708,
     150,   152,   154,     0,     0,     0,     0,     0,   265,   263,
       0,   271,     0,   206,   351,    72,   327,   333,     0,   347,
     343,   350,     0,     0,     0,   337,     0,     0,   339,     0,
     507,   501,   496,     0,   497,   487,     0,   761,     0,     0,
       0,     0,   300,   298,   743,   742,     0,     0,     0,     0,
     600,     0,     0,   606,   563,     0,     0,     0,   727,   720,
       0,     0,   156,   155,     0,     0,     0,     0,   151,   267,
       0,     0,     0,     0,     0,     0,   515,   509,     0,   508,
     510,   516,   513,   503,     0,   502,   504,   514,   489,     0,
     490,     0,     0,   635,   299,   744,   656,   597,   598,   601,
     594,   595,   607,   590,   588,   715,   153,   157,     0,     0,
       0,     0,   289,     0,     0,   340,   338,     0,     0,   500,
     511,   512,   499,   505,   506,   491,     0,   158,     0,     0,
       0,   348,   344,     0,     0,     0,     0,     0,     0,     0,
       0,   160,     0,     0,   159,     0,     0,     0,     0,     0,
       0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1462, -1462,  -210,  -186, -1462,  1183,  1201, -1462,  1184,  -457,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
    -887, -1462, -1462, -1462, -1462,  -222,  -520, -1462,   782,    91,
   -1462, -1462, -1462, -1462, -1462,   345,   579, -1462, -1462,    18,
    -159,  1048, -1462,  1035, -1462, -1462,  -573, -1462,   524, -1462,
     307, -1462,  -197,  -243, -1462,  -486, -1462,    20,    16,    11,
     -91,  -162, -1462,  -783, -1462, -1462,   155, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462,   694,   -59,  1094,
       0, -1462, -1462, -1462, -1462,   540, -1462, -1462,  -289, -1462,
       5, -1462,  1038,  -844,  -648,  -626, -1462, -1462,   760, -1462,
   -1462,    82,   297, -1462, -1462, -1462,   181, -1461, -1462,   455,
     189, -1462, -1462,   194, -1206, -1462,   987,   286, -1462, -1462,
     284,  -915, -1462, -1462,   279, -1462, -1462, -1163, -1149, -1462,
     275, -1335, -1462, -1462,   898,   900, -1462,  -431,   880, -1462,
   -1462,  -579,  -425,  -564,   382,   385, -1462, -1462, -1462,   656,
   -1462, -1462,  1158, -1462, -1462, -1462, -1462, -1462,  -722,  -285,
    -609, -1462, -1462,   219, -1462,  -466, -1462,   861, -1462,  -370,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462,   864, -1462, -1462,
   -1462, -1462,  -907, -1462,   268, -1462,   752,  -700, -1462, -1462,
   -1462, -1462, -1462,  -237,  -230, -1148,  -902, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,  -659,  -786,
    -134,  -775, -1462, -1462, -1462,  -826, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462,   170,   173,  -691,  -121,   403, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462, -1462,
     251, -1462, -1462,   242, -1462,   244,  -956, -1462, -1462, -1462,
     210,   201,    30,   486, -1462, -1462, -1462, -1462, -1462, -1462,
   -1462, -1462, -1462, -1462, -1462, -1462, -1462,   211, -1462, -1462,
   -1462,    37,   482,   620, -1462, -1462, -1462, -1462, -1462,   393,
   -1462, -1462, -1367, -1462, -1462, -1462,  -515, -1462,   162, -1462,
      -5, -1462, -1462, -1462, -1462, -1226, -1462,   220, -1462, -1462,
   -1462, -1462, -1462,   996, -1462, -1462, -1462, -1462, -1462,  -825,
   -1462, -1462, -1462,  -343,  -385,   630,   174, -1462
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   248,   562,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
    1178,   696,   266,   267,   268,   269,   270,   271,   858,   859,
     860,   272,   273,   274,   864,   865,   866,   275,   416,   276,
     277,   633,   278,   418,   419,   420,   432,   686,   687,   279,
    1134,   280,  1640,  1641,   281,   282,   283,   488,   284,   285,
     286,   287,   288,   689,   289,   290,   453,   291,   292,   293,
     294,   295,   296,   572,   297,   298,   765,   766,   299,   300,
     500,   302,   573,   430,   919,   920,   303,   574,   304,   576,
     501,   306,   676,   677,  1166,   439,   307,   440,   441,   683,
    1167,  1168,  1169,   577,   578,  1016,  1017,  1456,   579,  1013,
    1014,  1277,  1278,  1279,  1280,   308,   703,   704,   309,  1193,
    1194,  1400,   310,  1196,  1197,   311,   312,  1199,  1200,  1201,
    1202,  1407,   313,   314,   315,   316,   806,   317,   318,  1289,
     319,   320,   321,   322,   323,   324,   325,   326,   327,  1076,
     328,   329,   330,   331,   597,   598,   332,   333,   334,   335,
     336,   337,   338,   996,   997,   339,   624,   625,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   834,   349,   350,
     351,   352,   353,   354,  1227,   732,   733,   734,  1672,  1724,
    1725,  1718,  1719,  1726,  1720,  1228,  1229,   355,   356,  1230,
     357,   358,   359,   360,   361,   362,   363,   364,   914,  1408,
    1340,  1053,  1498,  1054,  1077,  1055,  1056,  1057,  1058,  1059,
    1060,  1061,  1062,  1063,  1064,  1065,   709,  1689,   365,  1066,
    1067,  1068,  1069,   366,   367,   368,   369,   370,   371,   755,
     756,   372,  1261,  1262,  1592,   998,  1024,  1299,  1300,  1025,
    1026,  1027,  1028,  1029,  1309,  1481,  1482,  1030,  1312,  1031,
    1462,  1032,  1033,  1317,  1318,  1487,  1485,  1301,  1302,  1303,
    1304,  1606,   662,   885,   886,   887,   888,   889,   890,  1118,
    1529,  1637,  1119,  1527,  1635,   891,  1353,  1524,  1520,  1521,
    1522,   892,   893,  1305,  1313,  1472,  1306,  1468,  1290,   373,
     374,   375,   376,   491,   377,   378,   379,   380,   381,  1070,
    1071,  1072,  1073,  1179,   508,   382,   383,   384
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -834;
  const short int
  jsoniq_parser::yytable_[] =
  {
       301,   301,   301,   301,   301,   305,   305,   305,   305,   305,
     827,   534,   391,   391,   391,   395,   575,   390,   390,   390,
     394,   389,   392,   393,   814,   657,   634,   634,   417,  1195,
     912,   549,   962,   784,   786,   550,   672,  1052,  1075,   934,
     815,   816,   817,   818,   552,  1183,   942,   499,   503,   621,
    1411,  1420,   913,   745,   550,   637,   952,  1226,   751,   554,
     541,   542,  1091,  1147,  1285,   778,   782,   785,   787,  1135,
    1136,   845,  1451,  1452,  1565,     9,  1121,  1569,   916,  1428,
     908,  1122,  1123,  1155,  1643,  1483,  1095,   550,  1022,   550,
    1124,   514,   693,   697,   776,   780,   550,  1125,   550,  1126,
    1127,     7,     8,   398,   399,   301,   400,   401,  1128,   550,
     305,     7,     8,   437,   550,   550,   489,   556,  1185,  1670,
     550,   390,   402,  1149,   404,   720,   523,  1401,   550,   636,
    1401,   550,   402,   550,  1682,  1129,  1172,   550,   559,   909,
     970,   910,   403,   561,   910,  1518,   622,   525,   623,   550,
     405,   802,   526,   803,   804,   910,   805,    77,   807,   550,
     405,  1638,   561,   909,   550,   406,   808,   809,  1192,   620,
     684,    87,   737,  1086,  1469,  1454,   812,   813,   536,   538,
    1268,  1398,  -169,   550,   550,   550,  1274,   874,   668,   875,
    1087,  1644,   911,   122,   557,  1156,   101,   407,   408,  1008,
    1019,  1566,  1123,  1020,   561,   550,  1367,  1276,  1098,  1671,
    1519,  1455,   575,  1402,   694,   524,  1555,   561,   550,   550,
    1127,   560,  1734,   561,   122,   721,   558,   410,   561,  1437,
     636,  -170,   550,   876,   550,   550,   527,   978,  1152,   685,
     917,   836,   421,  1375,  1593,   561,   301,   301,   985,   438,
     301,   305,   305,   784,   786,   305,  1160,   561,   556,   485,
    1216,   695,  1171,  1130,   971,   972,  1157,   561,   438,  1567,
    1330,  1411,   561,  1645,  1092,  1428,   515,   918,   551,   973,
     553,  1404,   485,   396,   730,   301,  1153,   411,  1158,   771,
     305,   561,   561,   561,   485,  1391,   485,   926,  1022,  1022,
     557,  1636,  1366,   944,   557,   773,  1021,   927,  1186,  1345,
     930,  1226,   871,   561,   776,   780,  1135,  1136,   438,  1005,
    1226,   438,  1007,  1711,  1267,   945,   561,   561,   412,   777,
     781,  1461,   558,  1745,  1470,  1471,   558,   989,   772,   774,
     561,   738,   561,   561,   550,  1489,  1291,  1212,   789,   768,
     550,   979,  1213,   931,   770,  1131,  1132,  1133,   550,   974,
    1219,  1220,   692,   669,   438,   675,   767,  1599,  -169,   438,
     906,   670,  1214,   413,   690,  1018,   986,  1754,   909,  1757,
     652,   414,   653,   702,   877,  1401,   707,   708,  1386,   415,
     721,   301,   714,  1678,  1669,   301,   305,   878,   557,   879,
     305,   840,   909,  1350,   666,   550,  1679,  1680,  1287,   667,
     880,   881,   882,   968,   883,   550,   884,  -170,   646,  1292,
     728,  1081,   301,   301,   550,   963,   933,   305,   305,   550,
     558,   840,   122,   395,   395,   517,  1702,   518,   673,   674,
    1023,  1217,   655,  1464,   301,  1600,   735,   736,   301,   305,
     951,   647,   561,   305,   740,   395,  1221,  1263,   561,   395,
     706,   550,  1567,  1352,   711,   939,   561,   722,  1291,   939,
    1085,  1560,   969,   761,   763,   425,  1222,   426,  1223,   797,
    1465,   841,  1361,   975,   976,   784,   786,   784,   550,   301,
    1219,  1220,   964,   520,   305,   521,   301,  1747,   977,   550,
    1368,   305,  1293,  1294,   656,  1295,  1224,   391,  1218,     9,
     108,   842,   390,   561,  1264,   443,  1226,  1732,  1249,  1269,
    1270,  1271,  1297,   561,   519,  1099,  1100,   120,  1358,   938,
    1103,  1376,   561,   301,  1298,   950,  1497,   561,   305,   923,
     301,  1292,   427,   965,   762,   305,   940,   428,  1225,  1002,
     954,   301,   301,   301,   301,  1082,   305,   305,   305,   305,
    1144,   829,  1115,   830,   417,  1022,   143,  1006,  1082,   561,
     301,   774,     7,     8,  1022,   305,   644,   485,  1613,  1116,
     485,   981,   522,  1411,   485,  1022,  1221,   485,   485,   397,
     966,    77,  1615,   422,   429,   485,   561,  1619,   447,   485,
     967,  1625,  1627,   485,   910,    87,  1222,   561,  1223,   991,
    1632,   485,   779,  1591,  1080,  1219,  1220,   485,  1109,   924,
     423,   485,  1117,  1457,  1293,  1294,   485,  1295,  1562,  1110,
     101,   861,  1350,   564,  1296,  1083,  1224,   565,   909,   424,
     108,   622,   566,   623,  1297,  1004,  1459,  1466,  1084,  1351,
    1023,  1023,  1563,   909,  1467,  1538,  1298,   120,  1614,   555,
     485,   567,  1162,  1655,   957,   958,   959,  1163,   763,   485,
    1264,   557,  1616,  1733,   862,   448,   601,  1620,  1422,   863,
    1603,  1626,  1628,   779,  1736,  1716,  1164,  1604,   301,  1219,
    1633,   941,  1352,   305,   602,   431,   143,  1605,  1009,   391,
    1219,  1220,   485,   990,   390,   910,  1159,   425,   925,   426,
     788,  1221,   301,   301,   790,   484,  1003,   305,   305,  1476,
     546,  1573,  1219,   395,   395,  1539,  1577,  1165,   948,   949,
     564,  1222,   547,  1223,   565,   601,   547,   621,   504,   566,
    1337,   442,  1722,   449,   450,  1111,   652,   784,   653,   434,
     509,  1663,   512,   602,  1533,     9,  1112,  1022,   567,   435,
     568,  1224,   301,   569,  1404,   108,  1088,   305,  1721,  1727,
     601,  1667,  1338,   610,   427,  1563,   603,  1661,   570,   428,
     789,   654,   120,  1089,   601,   604,   436,   611,   602,   301,
    1339,   433,   774,  1716,   305,  1563,  1221,  1219,     7,     8,
     485,   417,   602,  1427,   571,  1222,   638,  1223,   655,   398,
     399,  1686,   400,   401,   605,  1717,  1222,  1721,  1223,   402,
     639,   143,   847,  1727,  1753,   485,   429,   606,  1115,   403,
     404,  1693,   444,  1694,  1389,  1224,  1265,    77,  1222,   485,
    1223,  1773,   445,   485,   485,  1116,  1224,   405,  1563,  1723,
     108,    87,   406,  -833,  1162,  1774,   485,   568,   485,  1163,
     569,  1273,   607,   640,  -833,  1563,   485,   120,  1224,   485,
     656,   642,  1274,   485,  1673,   729,   101,   641,  1676,  1563,
    1019,   608,  1275,  1020,   407,   408,   409,   643,  1575,   451,
     609,  1601,  1602,  1276,  1090,  1603,   446,   910,  1257,  1598,
    1219,   571,  1604,  1192,   122,   485,   143,  1314,  1315,  1742,
     688,  1344,  1605,  1222,   452,  1223,  1403,  1023,   486,  1409,
    1722,  1642,  1688,  1760,  1691,   505,  1023,   688,  1412,  1409,
    1316,  1447,  1410,   410,  1696,  1409,  1697,  1023,   485,  1502,
     909,  1413,  1572,  1224,  1138,   862,   301,   506,  1766,  1093,
     863,   305,  1274,  1139,   658,   659,   660,   395,   513,   564,
    1284,  1093,  1203,   565,  1162,  1101,  1102,   485,   566,  1163,
     575,  1104,  1105,  1106,  1729,   516,   622,  1107,   623,  1233,
    1238,  1234,  1239,  1703,  1448,  1449,   528,   567,   531,  1258,
     819,   820,   529,   411,  1259,   821,   822,   485,   485,   485,
     485,  1356,  1357,  1629,  1630,   301,   301,   301,   530,   532,
     305,   305,   305,   533,   539,   543,  1222,   563,  1223,   580,
    1684,  1685,   417,   581,   599,   600,   612,  1763,   614,   619,
     613,   615,   626,   645,   412,   485,   649,   627,  1642,   628,
     509,   629,   630,   663,   664,   631,  1224,  1551,   632,   485,
     636,   509,   648,   650,   651,   678,   661,   665,   682,   678,
     413,   679,   680,   688,   691,   699,   700,   698,   414,   701,
     712,   718,   713,   705,   485,   716,   415,   710,   720,   723,
     731,   485,   715,   485,   724,  1387,   568,   727,   725,   569,
     739,   741,  1642,   753,   534,   742,   485,   754,   758,   759,
     764,   775,   793,   794,  1443,   810,   823,  1735,   795,  1023,
     824,  1594,   796,   825,   826,   622,   705,   837,   843,   844,
     846,   872,   873,   868,   869,   726,   894,   895,   898,   903,
     571,   848,   849,   850,   851,   852,   853,   854,   855,   856,
     857,   896,   900,   904,   905,   301,   907,   922,   928,   929,
     305,   932,   946,   943,   947,   980,   391,   982,   757,  1004,
     987,   390,   983,   988,  1094,  1365,  1011,  1015,   863,  1113,
     984,  1784,   909,  1785,  1001,  1114,   301,  1137,  1142,  1161,
    1143,   305,  1145,  1793,  1148,  1154,  1150,   301,   684,   485,
    1176,  1174,   305,  1175,  1177,  1181,  1180,  1182,   391,   490,
    1187,  1188,  1192,   390,  1198,  1191,   301,  1394,  1208,  1204,
    1211,   305,  1205,  1206,  1215,  1232,  1260,   391,   654,   485,
    1209,  1250,   390,  1281,   301,  1231,  1416,  1283,  1288,   305,
     582,   301,  1307,  1311,     9,   395,   305,  1319,   583,   584,
    1425,   585,   395,  1308,  1320,  1349,  1321,  1429,  1354,   586,
    1322,  1323,  1359,   587,  1360,   588,   509,  1373,  1348,  1364,
     589,  1363,  1324,  1258,  1325,  1326,  1327,  1328,  1259,  1329,
    1331,  1332,  1341,  1333,   762,  1334,  1371,   590,  1335,  1336,
    1377,   867,  1379,  1380,  1381,  1385,  1390,  1393,  1409,  1419,
    1421,  1415,  1424,  1435,  1440,   897,  1436,  1431,  1439,   901,
     902,   591,   592,   593,   594,   595,   596,  1432,  1430,  1433,
    1434,  1557,   915,  1441,   921,  1442,  1263,  1274,  1460,  1479,
     485,  1463,   509,  1473,   485,   509,  1480,  1484,  1486,   935,
    1488,  1499,  1517,  1505,  1509,  1510,  1511,  1512,  1513,   485,
    1514,  1515,  1516,  1523,  1528,  1530,  1534,  1536,   485,  1541,
    1526,  1548,   797,  1549,  1550,  1553,  1532,  1596,  1584,  1554,
    1559,   960,   485,  1570,  1617,  1571,  1576,  1579,  1597,  1609,
    1634,  1115,   485,  1610,  1646,  1647,  1611,  1612,  1618,  1621,
    1622,  1588,  1589,  1590,  1652,  1623,  1624,  1650,  1639,  1658,
    1454,  1675,  1695,  1698,   999,  1700,  1701,  1699,  1705,   485,
    1710,  1706,   301,  1712,  1713,  1714,  1728,   305,  1731,  1730,
    1737,  1738,  1739,  1740,  1750,  1741,  1743,  1744,  1758,  1759,
    1751,  1762,  1783,  1010,   485,  1770,  1748,  1776,  1765,  1768,
    1775,  1777,  1786,   544,   485,  1790,   870,   548,   485,  1787,
    1347,  1096,  1780,  1258,  1789,   635,  1782,  1173,  1259,  1362,
    1708,   545,   671,  1074,  1074,  1078,  1078,  1653,  1746,  1000,
    1170,   937,  1792,  1384,  1458,  1546,  1272,   681,  1657,  1557,
    1453,  1659,  1450,   717,  1395,  1405,  1414,  1399,   800,  1668,
     811,   801,  1079,  1446,   961,   835,  1423,   618,  1764,  1761,
    1490,  1074,   839,  1491,  1692,   485,   485,  1346,   485,   485,
     485,  1438,   485,  1445,  1444,  1108,  1474,  1286,  1478,  1608,
    1355,  1477,  1310,  1607,  1120,  1525,  1631,  1475,   749,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1141,     0,  1681,   485,     0,     0,     0,   678,     0,  1074,
       0,     0,     0,     0,     0,     0,     0,     0,  1258,     0,
    1687,     0,  1074,  1259,   485,   485,     0,     0,     0,  1258,
    1258,     0,   301,     0,  1259,  1259,     0,   305,     0,     0,
    1258,     0,     0,     0,     0,  1259,  1659,     0,     0,     0,
     485,     0,     0,   485,     0,     0,   485,     0,     0,     0,
     490,     0,     0,     0,     0,     0,   485,     0,     0,     0,
       0,   485,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   743,   744,     0,   746,   747,   748,   750,     0,   752,
       0,     0,  1755,     0,     0,   760,     0,     0,     0,     0,
       0,     0,     0,   769,     0,     0,     0,     0,     0,     0,
    1387,     0,     0,     0,     0,  1282,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   791,   792,     0,     0,     0,
       0,     0,  1771,     0,   798,   799,     0,  1258,     0,     0,
       0,     0,  1259,     0,     0,  1074,     0,     0,     0,     0,
       0,     0,     0,  1771,     0,     0,     0,     0,     0,     0,
       0,     0,  1755,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   301,     0,     0,     0,   833,   305,     0,
       0,     0,   833,     0,     0,     0,     0,     0,     0,     0,
       0,  1258,     0,     0,     0,     0,  1259,   485,   485,     0,
     485,     0,   485,     0,     0,     0,     0,     0,     0,   485,
       0,     0,     0,   301,     0,     0,     0,     0,   305,     0,
       0,   899,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1258,     0,   678,     0,     0,  1259,
    1369,     0,     0,  1258,     0,     0,     0,   485,  1259,   485,
       0,   485,     0,   485,   936,  1383,     0,     0,     0,   485,
       0,   485,     0,     0,  1074,     0,     0,     0,     0,     0,
     953,     0,     0,     0,   955,   956,     0,   485,   705,     0,
     485,     0,     0,   798,     0,     0,     0,     0,  1074,     0,
       0,     0,   485,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   485,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1426,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   485,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   485,
     757,     0,     0,   792,   485,     0,   485,     0,   485,  1012,
     999,     0,     0,     0,   999,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   485,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   485,     0,     0,     0,     0,   485,
       0,  1494,  1074,     0,   509,  1503,  1504,  1097,  1508,     0,
       0,   485,     0,     0,   485,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1531,
       0,     0,  1140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1151,     0,     0,     0,     0,
    1544,  1545,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1184,     0,     0,
       0,     0,     0,     0,  1189,  1190,  1561,     0,     0,  1074,
       0,     0,  1074,     0,     0,  1207,     0,     0,  1210,     0,
       0,     0,  1574,     0,     0,     0,     0,  1578,     0,     0,
       0,     0,     0,     0,     0,  1235,  1236,  1237,     0,  1240,
    1241,  1242,  1243,  1244,  1245,  1246,  1247,  1248,     0,     0,
    1251,  1252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1266,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1012,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1343,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1074,  1662,     0,  1664,     0,  1666,     0,
       0,     0,     0,     0,     0,  1674,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1690,     0,  1690,  1370,  1074,  1372,  1074,
    1374,     0,     0,  1378,     0,   710,     0,   710,  1382,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1388,     0,     0,  1704,     0,     0,  1707,     0,     0,  1392,
       0,     0,     0,     0,     0,  1396,  1397,     0,  1074,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1715,
       0,     0,  1417,     0,     0,  1418,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1074,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1749,     0,     0,     0,     0,
    1752,     0,  1074,     0,  1074,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1012,     0,     0,     0,     0,
    1769,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1778,     0,     0,     0,     0,  1779,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1788,     0,     0,
    1791,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1535,     0,     0,     0,  1537,     0,     0,     0,  1540,
       0,  1542,     0,  1543,     0,     0,     0,     0,     0,  1547,
       0,     0,     0,     0,     0,     0,     0,  1552,     0,     0,
       0,     0,     0,     0,     0,  1556,  1558,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1388,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1580,  1581,  1582,  1583,     0,
    1585,  1586,     0,  1587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1595,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1648,     0,  1649,     0,     0,  1651,     0,     0,     0,     0,
       0,     0,     0,  1654,     0,     0,     0,     0,  1656,  1558,
       0,     0,     0,     0,     0,     0,  1660,     0,     0,     0,
       0,  1665,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1677,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1683,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1709,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1660,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1756,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -165,   779,     0,     0,     0,
       0,     0,  1767,     0,     0,     0,     0,  1772,     0,     0,
       0,     0,  1756,     0,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,  1772,     0,    10,
     386,  1781,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   388,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     0,   238,
       0,   239,   240,   241,   242,   243,   244,   245,  -165,   779,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,   783,   386,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   387,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   388,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,   187,
     188,   189,     0,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   779,   238,     0,   239,   240,   241,   242,   243,   244,
     245,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,   385,   386,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     387,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   388,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   779,   238,     0,   239,   240,   241,   242,
     243,   244,   245,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   385,   386,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   492,   387,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   493,   494,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   468,    80,    81,    82,
      83,    84,   495,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   496,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   388,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   478,   479,   480,   170,   171,   481,   498,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,     0,   187,   188,   189,     0,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,     0,   238,     0,   239,   240,
     241,   242,   243,   244,   245,   992,   993,     0,     0,     0,
       0,     0,     0,     0,   994,     0,     0,     0,     0,     5,
       6,     0,     0,     0,     0,     0,     0,     0,   385,   386,
       0,    12,    13,    14,   454,    16,    17,    18,   455,    20,
     456,   457,   458,   459,   387,    26,   460,    28,    29,    30,
       0,    31,    32,    33,    34,   461,    36,    37,    38,    39,
      40,    41,    42,   462,     0,    44,   463,    46,   464,   465,
      49,   466,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   467,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   468,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   469,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,   104,     0,
       0,     0,     0,     0,     0,   110,   470,     0,     0,     0,
       0,   112,   113,   114,   115,   471,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
     995,     0,   129,     0,   130,   131,   132,   133,   472,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   388,   145,   146,   147,   148,   149,   150,   151,   152,
     473,   154,   474,   156,   475,   476,   159,   160,   161,   162,
     163,   164,   477,   166,   478,   479,   480,   170,   171,   481,
     482,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,     0,     0,   507,     0,
     239,   483,   241,   242,   243,   244,   245,     5,     6,     0,
       0,     0,  1500,     0,     0,     0,   385,   386,     0,    12,
      13,    14,   454,    16,    17,    18,   455,    20,   456,   457,
     458,   459,   387,    26,   460,    28,    29,    30,     0,    31,
      32,    33,    34,   461,    36,    37,    38,    39,    40,    41,
      42,   462,     0,    44,   463,    46,   464,   465,    49,   466,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,   467,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   468,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   469,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,   104,     0,     0,     0,
       0,     0,     0,   110,   470,     0,     0,     0,     0,   112,
     113,   114,   115,   471,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,   123,   124,   125,     0,     0,     0,
     126,  1501,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   472,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   388,
     145,   146,   147,   148,   149,   150,   151,   152,   473,   154,
     474,   156,   475,   476,   159,   160,   161,   162,   163,   164,
     477,   166,   478,   479,   480,   170,   171,   481,   482,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,     0,   187,   188,   189,     0,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     0,     0,   507,     0,   239,   483,
     241,   242,   243,   244,   245,     5,     6,     0,     0,     0,
       0,     0,     0,     0,   385,   386,     0,    12,    13,    14,
     454,    16,    17,    18,   455,    20,   456,   457,   458,   459,
     387,    26,   460,    28,    29,    30,     0,    31,    32,    33,
      34,   461,    36,    37,    38,    39,    40,    41,    42,   462,
       0,    44,   463,    46,   464,   465,    49,   466,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,   467,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   468,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   469,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,   104,     0,     0,     0,     0,     0,
       0,   110,   470,     0,     0,     0,     0,   112,   113,   114,
     115,   471,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   472,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   388,   145,   146,
     147,   148,   149,   150,   151,   152,   473,   154,   474,   156,
     475,   476,   159,   160,   161,   162,   163,   164,   477,   166,
     478,   479,   480,   170,   171,   481,   482,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,     0,     0,     0,   239,   483,   241,   242,
     243,   244,   245,   510,   511,     0,     0,     0,     0,     0,
       5,     6,     0,     0,     0,     0,     0,     0,     0,   385,
     386,     0,    12,    13,    14,   454,    16,    17,    18,   455,
      20,   456,   457,   458,   459,   387,    26,   460,    28,    29,
      30,     0,    31,    32,    33,    34,   461,    36,    37,    38,
      39,    40,    41,    42,   462,     0,    44,   463,    46,   464,
     465,    49,   466,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,   467,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   468,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   469,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,   104,
       0,     0,     0,     0,     0,     0,   110,   470,     0,     0,
       0,     0,   112,   113,   114,   115,   471,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   472,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   388,   145,   146,   147,   148,   149,   150,   151,
     152,   473,   154,   474,   156,   475,   476,   159,   160,   161,
     162,   163,   164,   477,   166,   478,   479,   480,   170,   171,
     481,   482,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,     0,     0,
       0,   239,   483,   241,   242,   243,   244,   245,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,    10,    11,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,     0,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       0,   238,     0,   239,   240,   241,   242,   243,   244,   245,
     246,   247,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,    10,    11,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,     0,     0,     0,     0,    87,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,   238,     0,   239,   240,   241,
     242,   243,   244,   245,     0,   540,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,   385,
     386,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   387,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,   487,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   388,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     0,   238,
       0,   239,   240,   241,   242,   243,   244,   245,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,   385,   386,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   387,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,     0,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,   719,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   388,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       0,   238,     0,   239,   240,   241,   242,   243,   244,   245,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,   385,   386,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,  1253,   387,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,  1254,  1255,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,   487,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   388,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,  1256,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     0,   238,     0,   239,   240,   241,   242,   243,
     244,   245,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,   385,   386,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   387,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,     0,     0,     0,     0,    87,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   105,   106,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   388,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,   238,     0,   239,   240,   241,
     242,   243,   244,   245,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,    10,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,     0,    87,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     0,   238,     0,   239,
     240,   241,   242,   243,   244,   245,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,    10,
      11,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   388,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     0,   238,
       0,   239,   240,   241,   242,   243,   244,   245,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,    10,   386,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,     0,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   388,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       0,   238,     0,   239,   240,   241,   242,   243,   244,   245,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,   783,   386,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   387,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   105,   106,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   388,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     0,   238,     0,   239,   240,   241,   242,   243,
     244,   245,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     9,     0,     0,     0,   385,   386,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     492,   387,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,   493,   494,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,   468,    80,    81,    82,    83,
      84,   495,    86,     0,     0,     0,     0,    87,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,   831,     0,    98,
      99,   100,   101,   102,   103,   104,   496,   106,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
     832,   127,   128,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   388,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   478,   479,   480,   170,   171,   481,   498,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,   238,     0,   239,   240,   241,
     242,   243,   244,   245,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   385,   386,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   492,   387,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,   493,   494,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,   468,    80,    81,
      82,    83,    84,   495,    86,     0,     0,     0,     0,    87,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
      93,    94,    95,    96,    97,     0,     0,     0,     0,   831,
       0,    98,    99,   100,   101,   102,   103,   104,   496,   106,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,   838,   127,   128,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     388,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   478,   479,   480,   170,   171,   481,   498,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     0,   238,     0,   239,
     240,   241,   242,   243,   244,   245,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,   385,
     386,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,  1253,   387,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,  1254,
    1255,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   388,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,  1256,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     0,   238,
       0,   239,   240,   241,   242,   243,   244,   245,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     9,     0,     0,
       0,   385,   386,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   492,   387,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,   493,   494,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,   468,    80,    81,    82,    83,    84,   495,    86,     0,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   496,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,   497,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   388,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   478,   479,   480,
     170,   171,   481,   498,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       0,   238,     0,   239,   240,   241,   242,   243,   244,   245,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     9,
       0,     0,     0,   385,   386,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   492,   387,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,   493,   494,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,   468,    80,    81,    82,    83,    84,   495,
      86,     0,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   496,   106,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,   502,   127,
     128,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   388,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   478,
     479,   480,   170,   171,   481,   498,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     0,   238,     0,   239,   240,   241,   242,   243,
     244,   245,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     9,     0,     0,     0,   385,   386,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     492,   387,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,   493,   494,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,   468,    80,    81,    82,    83,
      84,   495,    86,     0,     0,     0,     0,    87,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   496,   106,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   388,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   478,   479,   480,   170,   171,   481,   498,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   535,   238,     0,   239,   240,   241,
     242,   243,   244,   245,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   385,   386,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   492,   387,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,   493,   494,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,   468,    80,    81,
      82,    83,    84,   495,    86,     0,     0,     0,     0,    87,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   496,   106,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     388,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   478,   479,   480,   170,   171,   481,   498,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     0,   238,   537,   239,
     240,   241,   242,   243,   244,   245,     1,     2,     3,     4,
       5,     6,     0,     0,     0,     9,     0,     0,     0,   385,
     386,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   492,   387,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,   493,
     494,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,   468,
      80,    81,    82,    83,    84,   495,    86,     0,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     496,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,   828,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   388,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   478,   479,   480,   170,   171,
     481,   498,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     0,   238,
       0,   239,   240,   241,   242,   243,   244,   245,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     9,     0,     0,
       0,   385,   386,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   492,   387,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,   493,   494,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,   468,    80,    81,    82,    83,    84,   495,    86,     0,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,  1342,     0,    98,    99,   100,   101,   102,
     103,   104,   496,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   388,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   478,   479,   480,
     170,   171,   481,   498,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       0,   238,     0,   239,   240,   241,   242,   243,   244,   245,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     9,
       0,     0,     0,   385,   386,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   457,    23,   459,   387,
      26,   460,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,   462,     0,
      44,    45,    46,   464,   465,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,   468,    80,    81,    82,    83,    84,   495,
      86,     0,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,   469,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   496,   106,     0,   107,   108,   616,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   617,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   388,   145,   146,   147,
     148,   149,   150,   151,   152,   473,   154,   474,   156,   475,
     476,   159,   160,   161,   162,   163,   164,   477,   166,   478,
     479,   480,   170,   171,   481,   482,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     0,   238,     0,   239,   483,   241,   242,   243,
     244,   245,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     9,     0,     0,     0,   385,   386,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     492,   387,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,   493,   494,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,   468,    80,    81,    82,    83,
      84,   495,    86,     0,     0,     0,     0,    87,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   496,   106,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   388,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   478,   479,   480,   170,   171,   481,   498,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,   238,     0,   239,   240,   241,
     242,   243,   244,   245,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   385,   386,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     457,    23,   459,   387,    26,   460,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   462,     0,    44,    45,    46,   464,   465,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,   468,    80,    81,
      82,    83,    84,   495,    86,     0,     0,     0,     0,    87,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     469,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   496,   106,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     388,   145,   146,   147,   148,   149,   150,   151,   152,   473,
     154,   474,   156,   475,   476,   159,   160,   161,   162,   163,
     164,   477,   166,   478,   479,   480,   170,   171,   481,   482,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     0,   238,     0,   239,
     483,   241,   242,   243,   244,   245,     1,     2,     3,     4,
       5,     6,     0,     0,     0,     9,     0,     0,     0,   385,
     386,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   457,    23,   459,   387,    26,   460,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   462,     0,    44,    45,    46,   464,
     465,    49,   466,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,   468,
      80,    81,    82,    83,    84,   495,    86,     0,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   469,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     496,   106,     0,   107,   108,     0,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,     0,     0,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   388,   145,   146,   147,   148,   149,   150,   151,
     152,   473,   154,   474,   156,   475,   476,   159,   160,   161,
     162,   163,   164,   477,   166,   478,   479,   480,   170,   171,
     481,   482,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     0,   238,
       0,   239,   483,   241,   242,   243,   244,   245,     5,     6,
       0,     0,     0,     0,     0,     0,     0,   385,   386,     0,
      12,    13,    14,  1034,    16,    17,    18,   455,  1035,  1036,
     457,  1037,   459,   387,    26,   460,    28,  1038,    30,     0,
      31,    32,    33,    34,  1039,    36,  1040,  1041,    39,    40,
      41,    42,   462,     0,    44,  1042,    46,   464,   465,    49,
     466,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,  1043,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   468,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     469,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,  1044,     0,     0,
       0,  1045,     0,     0,   110,   470,     0,     0,     0,     0,
     112,   113,   114,   115,   471,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,   123,   124,   125,     0,     0,
       0,   126,  1495,   127,   128,     0,     0,     0,     0,  1496,
       0,   129,     0,   130,   131,   132,   133,   472,   135,   136,
     137,   138,   139,   140,     0,     0,  1046,   142,     0,     0,
     388,   145,   146,   147,   148,   149,   150,   151,   152,   473,
    1047,   474,   156,   475,   476,   159,   160,   161,   162,   163,
     164,   477,   166,   478,   479,   480,   170,   171,   481,   482,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,     0,     5,     6,   239,
     483,   241,  1048,  1049,  1050,  1051,   385,   386,     0,    12,
      13,    14,  1034,    16,    17,    18,   455,  1035,  1036,   457,
    1037,   459,   387,    26,   460,    28,  1038,    30,     0,    31,
      32,    33,    34,  1039,    36,  1040,  1041,    39,    40,    41,
      42,   462,     0,    44,  1042,    46,   464,   465,    49,   466,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,  1043,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   468,    80,    81,    82,
      83,    84,  1406,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   469,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,  1044,     0,     0,     0,
    1045,     0,     0,   110,   470,     0,     0,     0,     0,   112,
     113,   114,   115,   471,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   472,   135,   136,   137,
     138,   139,   140,     0,     0,  1046,   142,     0,     0,   388,
     145,   146,   147,   148,   149,   150,   151,   152,   473,  1047,
     474,   156,   475,   476,   159,   160,   161,   162,   163,   164,
     477,   166,   478,   479,   480,   170,   171,   481,   482,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,     0,   187,   188,   189,     0,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     0,     0,     5,     6,   239,   483,
     241,  1048,  1049,  1050,  1051,   385,   386,     0,    12,    13,
      14,   454,    16,    17,    18,   455,    20,   456,   457,   458,
     459,   387,    26,   460,    28,    29,    30,     0,    31,    32,
      33,    34,   461,    36,    37,    38,    39,    40,    41,    42,
     462,     0,    44,   463,    46,   464,   465,    49,   466,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
     467,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   468,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   469,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,   102,   103,   104,     0,     0,     0,     0,
       0,     0,   110,   470,     0,     0,     0,     0,   112,   113,
     114,   115,   471,   117,   118,   119,     0,     0,     0,     0,
       0,     0,     0,   123,   124,   125,     0,     0,     0,   126,
    1492,   127,   128,     0,     0,     0,     0,  1493,     0,   129,
       0,   130,   131,   132,   133,   472,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   388,   145,
     146,   147,   148,   149,   150,   151,   152,   473,   154,   474,
     156,   475,   476,   159,   160,   161,   162,   163,   164,   477,
     166,   478,   479,   480,   170,   171,   481,   482,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,     5,     6,   239,   483,   241,
     242,   243,   244,   245,   385,   386,     0,    12,    13,    14,
     454,    16,    17,    18,   455,    20,   456,   457,   458,   459,
     387,    26,   460,    28,    29,    30,     0,    31,    32,    33,
      34,   461,    36,    37,    38,    39,    40,    41,    42,   462,
       0,    44,   463,    46,   464,   465,    49,   466,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,   467,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   468,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   469,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,   104,     0,     0,     0,     0,     0,
       0,   110,   470,     0,     0,     0,     0,   112,   113,   114,
     115,   471,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,     0,   126,  1506,
     127,   128,     0,     0,     0,     0,  1507,     0,   129,     0,
     130,   131,   132,   133,   472,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   388,   145,   146,
     147,   148,   149,   150,   151,   152,   473,   154,   474,   156,
     475,   476,   159,   160,   161,   162,   163,   164,   477,   166,
     478,   479,   480,   170,   171,   481,   482,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,     0,     5,     6,   239,   483,   241,   242,
     243,   244,   245,   385,   386,     0,    12,    13,    14,  1034,
      16,    17,    18,   455,  1035,  1036,   457,  1037,   459,   387,
      26,   460,    28,  1038,    30,     0,    31,    32,    33,    34,
    1039,    36,  1040,  1041,    39,    40,    41,    42,   462,     0,
      44,  1042,    46,   464,   465,    49,   466,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,  1043,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,     0,    78,   468,    80,    81,    82,    83,    84,  1564,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,   469,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
       0,   102,   103,  1044,     0,     0,     0,  1045,     0,     0,
     110,   470,     0,     0,     0,     0,   112,   113,   114,   115,
     471,   117,   118,   119,     0,     0,     0,     0,     0,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   472,   135,   136,   137,   138,   139,   140,
       0,     0,  1046,   142,     0,     0,   388,   145,   146,   147,
     148,   149,   150,   151,   152,   473,  1047,   474,   156,   475,
     476,   159,   160,   161,   162,   163,   164,   477,   166,   478,
     479,   480,   170,   171,   481,   482,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     0,     0,     5,     6,   239,   483,   241,  1048,  1049,
    1050,  1051,   385,   386,     0,    12,    13,    14,  1034,    16,
      17,    18,   455,  1035,  1036,   457,  1037,   459,   387,    26,
     460,    28,  1038,    30,     0,    31,    32,    33,    34,  1039,
      36,  1040,  1041,    39,    40,    41,    42,   462,     0,    44,
    1042,    46,   464,   465,    49,   466,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,  1043,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
       0,    78,   468,    80,    81,    82,    83,    84,  1568,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   469,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,  1044,     0,     0,     0,  1045,     0,     0,   110,
     470,     0,     0,     0,     0,   112,   113,   114,   115,   471,
     117,   118,   119,     0,     0,     0,     0,     0,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   472,   135,   136,   137,   138,   139,   140,     0,
       0,  1046,   142,     0,     0,   388,   145,   146,   147,   148,
     149,   150,   151,   152,   473,  1047,   474,   156,   475,   476,
     159,   160,   161,   162,   163,   164,   477,   166,   478,   479,
     480,   170,   171,   481,   482,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,   187,
     188,   189,     0,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,     0,     5,     6,   239,   483,   241,  1048,  1049,  1050,
    1051,   385,   386,     0,    12,    13,    14,  1034,    16,    17,
      18,   455,  1035,  1036,   457,  1037,   459,   387,    26,   460,
      28,  1038,    30,     0,    31,    32,    33,    34,  1039,    36,
    1040,  1041,    39,    40,    41,    42,   462,     0,    44,  1042,
      46,   464,   465,    49,   466,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,  1043,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,     0,
      78,   468,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   469,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,     0,   102,
     103,  1044,     0,     0,     0,  1045,     0,     0,   110,   470,
       0,     0,     0,     0,   112,   113,   114,   115,   471,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   472,   135,   136,   137,   138,   139,   140,     0,     0,
    1046,   142,     0,     0,   388,   145,   146,   147,   148,   149,
     150,   151,   152,   473,  1047,   474,   156,   475,   476,   159,
     160,   161,   162,   163,   164,   477,   166,   478,   479,   480,
     170,   171,   481,   482,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,     5,     6,   239,   483,   241,  1048,  1049,  1050,  1051,
     385,   386,     0,    12,    13,    14,  1034,    16,    17,    18,
     455,  1035,  1036,   457,  1037,   459,   387,    26,   460,    28,
    1038,    30,     0,    31,    32,    33,    34,  1039,    36,  1040,
    1041,    39,    40,    41,    42,   462,     0,    44,  1042,    46,
     464,   465,    49,   466,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,  1043,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     468,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   469,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
    1044,     0,     0,     0,  1045,     0,     0,   110,   470,     0,
       0,     0,     0,   112,   113,   114,   115,   471,   117,   118,
     119,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     472,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   388,   145,   146,   147,   148,   149,   150,
     151,   152,   473,  1047,   474,   156,   475,   476,   159,   160,
     161,   162,   163,   164,   477,   166,   478,   479,   480,   170,
     171,   481,   482,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     0,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,     0,     0,
       5,     6,   239,   483,   241,  1048,  1049,  1050,  1051,   385,
     386,     0,    12,    13,    14,   454,    16,    17,    18,   455,
      20,   456,   457,   458,   459,   387,    26,   460,    28,    29,
      30,     0,    31,    32,    33,    34,   461,    36,    37,    38,
      39,    40,    41,    42,   462,     0,    44,   463,    46,   464,
     465,    49,   466,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,   467,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   468,
      80,    81,    82,    83,    84,  1146,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   469,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,   104,
       0,     0,     0,     0,     0,     0,   110,   470,     0,     0,
       0,     0,   112,   113,   114,   115,   471,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   472,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   388,   145,   146,   147,   148,   149,   150,   151,
     152,   473,   154,   474,   156,   475,   476,   159,   160,   161,
     162,   163,   164,   477,   166,   478,   479,   480,   170,   171,
     481,   482,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,     0,     5,
       6,   239,   483,   241,   242,   243,   244,   245,   385,   386,
       0,    12,    13,    14,   454,    16,    17,    18,   455,    20,
     456,   457,   458,   459,   387,    26,   460,    28,    29,    30,
       0,    31,    32,    33,    34,   461,    36,    37,    38,    39,
      40,    41,    42,   462,     0,    44,   463,    46,   464,   465,
      49,   466,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   467,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   468,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   469,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,   104,     0,
       0,     0,     0,     0,     0,   110,   470,     0,     0,     0,
       0,   112,   113,   114,   115,   471,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   472,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   388,   145,   146,   147,   148,   149,   150,   151,   152,
     473,   154,   474,   156,   475,   476,   159,   160,   161,   162,
     163,   164,   477,   166,   478,   479,   480,   170,   171,   481,
     482,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,     0,     0,     5,     6,
     239,   483,   241,   242,   243,   244,   245,   385,   386,     0,
      12,    13,    14,     0,    16,    17,    18,   455,     0,     0,
     457,   458,     0,   387,    26,   460,    28,     0,    30,     0,
      31,    32,    33,    34,     0,    36,     0,     0,    39,    40,
      41,    42,   462,     0,    44,     0,    46,     0,     0,    49,
     466,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,     0,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   468,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     469,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,     0,     0,     0,
       0,     0,     0,     0,   110,   470,     0,     0,     0,     0,
     112,   113,   114,   115,   471,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   472,   135,   136,
     137,   138,   139,   140,     0,     0,     0,   142,     0,     0,
     388,   145,   146,   147,   148,   149,   150,   151,   152,   473,
       0,   474,   156,   475,   476,   159,   160,   161,   162,   163,
     164,   477,   166,   478,   479,   480,   170,   171,     0,   482,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,     0,     0,     0,   239,
     483,   241,   242,   243,   244,   245
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,     1,     2,     3,     4,     0,     1,     2,     3,     4,
     619,   173,     1,     2,     3,     4,   305,     1,     2,     3,
       4,     1,     2,     3,   603,   410,   396,   397,    10,   944,
     678,   253,   732,   553,   554,     1,   421,   823,   824,   698,
     604,   605,   606,   607,   254,   932,   705,   106,   107,   334,
    1199,  1214,   678,   519,     1,   398,   715,   964,   524,   269,
     246,   247,   845,   907,  1020,   551,   552,   553,   554,   895,
     895,   644,  1278,  1279,  1409,    30,    40,  1412,    57,  1227,
      37,    45,    46,    37,   120,  1311,   861,     1,   810,     1,
      54,    31,   435,   436,   551,   552,     1,    61,     1,    63,
      64,    27,    28,    38,    39,   105,    41,    42,    72,     1,
     105,    27,    28,   120,     1,     1,   105,   276,   144,    95,
       1,   105,    48,   909,    59,   123,   227,   102,     1,    30,
     102,     1,    48,     1,  1595,    99,   922,     1,   109,    96,
      96,    98,    58,   109,    98,   138,   156,   227,   158,     1,
      76,   582,   232,   584,   585,    98,   587,   112,   589,     1,
      76,  1528,   109,    96,     1,    81,   597,   598,   102,   155,
     120,   126,     8,   150,    98,   108,   601,   602,   237,   238,
     115,   115,     0,     1,     1,     1,   108,    56,   114,    58,
     167,   227,   149,   179,   285,   149,   151,   113,   114,   115,
     155,   120,    46,   158,   109,     1,   149,   129,   867,   185,
     203,   144,   501,   188,   115,   316,   188,   109,     1,     1,
      64,   192,  1683,   109,   179,   109,   285,   162,   109,   239,
      30,     0,     1,   102,     1,     1,   316,   235,   149,   189,
     219,   626,   162,   149,  1450,   109,   246,   247,   109,   275,
     250,   246,   247,   773,   774,   250,   915,   109,   417,    85,
     960,   162,   921,   227,   220,   221,   914,   109,   275,   188,
    1045,  1420,   109,   309,   847,  1423,   216,   256,   192,   235,
     192,  1196,   108,   158,   189,   285,   912,   222,   914,   192,
     285,   109,   109,   109,   120,  1182,   122,   189,  1020,  1021,
     391,  1527,  1146,   189,   395,   192,   261,   692,   934,  1092,
     695,  1218,   655,   109,   771,   772,  1142,  1142,   275,   192,
    1227,   275,   192,  1658,   192,   189,   109,   109,   263,   551,
     552,  1287,   391,  1700,   258,   259,   395,   189,   548,   549,
     109,   177,   109,   109,     1,   189,    98,   189,   558,   315,
       1,   235,   189,   696,   540,   319,   320,   321,     1,    96,
       9,    10,   162,   289,   275,   424,   313,    53,   186,   275,
     186,   297,   189,   289,   433,   806,   237,  1712,    96,  1714,
      46,   297,    48,   442,   253,   102,   445,   446,  1174,   305,
     109,   391,   451,   189,   120,   395,   391,   266,   489,   268,
     395,   109,    96,    98,   139,     1,   189,   189,   155,   144,
     279,   280,   281,   133,   283,     1,   285,   186,   171,   171,
     187,   187,   422,   423,     1,   132,   144,   422,   423,     1,
     489,   109,   179,   422,   423,   227,  1642,   229,   422,   423,
     810,   132,   108,   219,   444,   131,   505,   506,   448,   444,
     144,   204,   109,   448,   513,   444,   105,   155,   109,   448,
     444,     1,   188,   158,   448,   109,   109,   186,    98,   109,
     840,   188,   192,   532,   533,     1,   125,     3,   127,   570,
     256,   189,  1141,   220,   221,  1005,  1006,  1007,     1,   489,
       9,    10,   199,   227,   489,   229,   496,  1703,   235,     1,
    1148,   496,   254,   255,   170,   257,   155,   496,   199,    30,
     159,   189,   496,   109,   212,   120,  1423,  1680,   984,  1005,
    1006,  1007,   274,   109,   316,   868,   869,   176,  1137,   186,
     873,  1157,   109,   533,   286,   186,  1322,   109,   533,   109,
     540,   171,    68,   186,   533,   540,   190,    73,   197,   771,
     190,   551,   552,   553,   554,   109,   551,   552,   553,   554,
     903,   620,    98,   622,   546,  1287,   215,   777,   109,   109,
     570,   781,    27,    28,  1296,   570,   402,   403,   109,   115,
     406,    96,   316,  1732,   410,  1307,   105,   413,   414,   158,
     186,   112,   109,   155,   120,   421,   109,   109,    78,   425,
     186,   109,   109,   429,    98,   126,   125,   109,   127,   186,
     109,   437,     1,   155,   186,     9,    10,   443,   265,   189,
     155,   447,   158,  1282,   254,   255,   452,   257,   188,   276,
     151,    96,    98,    43,   264,   189,   155,    47,    96,   155,
     159,   156,    52,   158,   274,    34,   186,   270,   189,   115,
    1020,  1021,   212,    96,   277,   149,   286,   176,   189,   114,
     486,    71,    55,  1550,   723,   724,   725,    60,   727,   495,
     212,   762,   189,   186,   139,   155,   160,   189,   197,   144,
     271,   189,   189,     1,   186,     5,    79,   278,   688,     9,
     189,   149,   158,   688,   178,   158,   215,   288,   789,   688,
       9,    10,   528,   762,   688,    98,   149,     1,   688,     3,
     555,   105,   712,   713,   559,    85,    34,   712,   713,  1298,
      34,  1421,     9,   712,   713,  1373,  1426,   120,   712,   713,
      43,   125,    50,   127,    47,   160,    50,  1022,   108,    52,
     146,   155,    29,   223,   224,   265,    46,  1267,    48,    25,
     120,   188,   122,   178,  1363,    30,   276,  1479,    71,    35,
     170,   155,   762,   173,  1679,   159,   150,   762,  1670,  1671,
     160,   188,   178,   138,    68,   212,   201,  1563,   188,    73,
     990,    81,   176,   167,   160,   119,    62,   152,   178,   789,
     196,   158,  1002,     5,   789,   212,   105,     9,    27,    28,
     626,   783,   178,   197,   214,   125,   184,   127,   108,    38,
      39,   201,    41,    42,   148,   135,   125,  1719,   127,    48,
     198,   215,   648,  1725,   188,   651,   120,   161,    98,    58,
      59,  1617,   155,  1619,  1177,   155,   998,   112,   125,   665,
     127,   188,   158,   669,   670,   115,   155,    76,   212,   136,
     159,   126,    81,   147,    55,   188,   682,   170,   684,    60,
     173,    97,   196,   184,   158,   212,   692,   176,   155,   695,
     170,   168,   108,   699,  1574,   188,   151,   198,  1578,   212,
     155,   203,   118,   158,   113,   114,   115,   184,   197,   155,
     212,  1470,  1471,   129,   139,   271,   158,    98,   989,  1463,
       9,   214,   278,   102,   179,   731,   215,   249,   250,  1695,
     155,   139,   288,   125,   120,   127,   115,  1287,   120,   102,
      29,  1530,  1613,   135,  1615,   155,  1296,   155,   102,   102,
     272,  1274,   115,   162,  1625,   102,  1627,  1307,   764,  1324,
      96,   115,   115,   155,   301,   139,   946,   155,   115,   858,
     144,   946,   108,   310,   223,   224,   225,   946,   155,    43,
    1019,   870,   946,    47,    55,   130,   131,   793,    52,    60,
    1259,   279,   280,   281,  1674,   218,   156,   285,   158,   234,
     234,   236,   236,  1642,   130,   131,   120,    71,   244,   989,
     608,   609,   243,   222,   989,   610,   611,   823,   824,   825,
     826,  1135,  1136,  1518,  1519,  1005,  1006,  1007,   243,   158,
    1005,  1006,  1007,   155,   316,     0,   125,   192,   127,   169,
    1599,  1600,  1004,    94,   251,   101,    51,   136,   103,   195,
     202,   104,   121,   403,   263,   861,   406,   147,  1647,   158,
     410,   186,   186,   413,   414,   186,   155,  1390,   186,   875,
      30,   421,    48,   154,   120,   425,   248,   306,   120,   429,
     289,   286,   286,   155,     1,   120,   144,   437,   297,   109,
     155,   186,   155,   443,   900,   144,   305,   447,   123,   158,
      36,   907,   452,   909,   158,  1176,   170,   155,   158,   173,
      17,   216,  1701,   233,  1256,    30,   922,   232,   192,   192,
     247,     3,   120,   170,   188,    72,   233,  1686,   172,  1479,
      96,  1454,   172,    96,    96,   156,   486,   151,   109,   109,
      30,   129,   134,   162,   162,   495,   248,    96,   144,   134,
     214,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   301,   120,   186,   186,  1145,   109,    96,    98,    46,
    1145,    98,   155,   186,   186,    96,  1145,   239,   528,    34,
     144,  1145,   227,   192,   134,  1145,   172,   120,   144,    30,
     233,  1780,    96,  1782,   235,   288,  1176,   229,    96,   256,
     301,  1176,   155,  1792,   129,   149,   120,  1187,   120,  1015,
     200,    96,  1187,   186,   134,   134,   162,    98,  1187,   105,
     155,   120,   102,  1187,   102,   149,  1206,  1187,   144,   186,
     123,  1206,   186,   155,    36,    30,   247,  1206,    81,  1045,
     192,   120,  1206,   109,  1224,   155,  1206,   109,   287,  1224,
     134,  1231,   260,   269,    30,  1224,  1231,   158,   142,   143,
    1224,   145,  1231,   262,   158,    30,   158,  1231,    30,   153,
     158,   158,   289,   157,   308,   159,   626,   129,   288,   192,
     164,   229,   158,  1263,   158,   158,   158,   158,  1263,   158,
     158,   158,   146,   158,  1263,   158,   149,   181,   158,   158,
     149,   651,   149,   120,   120,    79,   109,   144,   102,   200,
     134,   186,     7,    98,   158,   665,   239,   235,   188,   669,
     670,   205,   206,   207,   208,   209,   210,   235,   192,   235,
     235,  1402,   682,   158,   684,   158,   155,   108,   189,   149,
    1146,   252,   692,   252,  1150,   695,   284,   288,    80,   699,
     189,   189,    30,   189,   189,   189,   189,   189,   189,  1165,
     189,   189,   189,    30,   109,   172,   186,   149,  1174,   149,
     273,   128,  1443,   128,    98,   186,   259,   144,   318,   188,
     188,   731,  1188,   188,    96,   186,   186,   186,   186,   155,
      30,    98,  1198,   282,   289,   172,   189,   189,   189,   189,
     189,  1440,  1441,  1442,    55,   189,   189,   149,   189,    96,
     108,   199,    96,    30,   764,   109,   109,   267,   120,  1225,
     120,   227,  1402,    96,   188,    96,   199,  1402,   200,   199,
     189,   189,   146,   189,   120,   189,   189,   189,   188,    95,
     227,   185,   188,   793,  1250,   120,   307,   295,   199,   307,
     120,   307,   201,   250,  1260,   120,   654,   253,  1264,   289,
    1095,   862,   308,  1443,   227,   397,   308,   923,  1443,  1142,
    1647,   250,   417,   823,   824,   825,   826,  1548,  1701,   765,
     920,   701,   308,  1166,  1283,  1383,  1011,   429,  1559,  1560,
    1281,  1562,  1278,   486,  1188,  1196,  1201,  1193,   580,  1570,
     600,   581,   826,  1264,   732,   624,  1218,   329,  1725,  1719,
    1320,   861,   628,  1320,  1615,  1321,  1322,  1094,  1324,  1325,
    1326,  1250,  1328,  1261,  1260,   875,  1296,  1021,  1307,  1479,
    1117,  1300,  1030,  1476,   894,  1353,  1521,  1297,   522,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     900,    -1,  1591,  1359,    -1,    -1,    -1,   907,    -1,   909,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1548,    -1,
    1609,    -1,   922,  1548,  1380,  1381,    -1,    -1,    -1,  1559,
    1560,    -1,  1562,    -1,  1559,  1560,    -1,  1562,    -1,    -1,
    1570,    -1,    -1,    -1,    -1,  1570,  1667,    -1,    -1,    -1,
    1406,    -1,    -1,  1409,    -1,    -1,  1412,    -1,    -1,    -1,
     496,    -1,    -1,    -1,    -1,    -1,  1422,    -1,    -1,    -1,
      -1,  1427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   517,   518,    -1,   520,   521,   522,   523,    -1,   525,
      -1,    -1,  1713,    -1,    -1,   531,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   539,    -1,    -1,    -1,    -1,    -1,    -1,
    1731,    -1,    -1,    -1,    -1,  1015,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   561,   562,    -1,    -1,    -1,
      -1,    -1,  1753,    -1,   570,   571,    -1,  1667,    -1,    -1,
      -1,    -1,  1667,    -1,    -1,  1045,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1774,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1783,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1713,    -1,    -1,    -1,   623,  1713,    -1,
      -1,    -1,   628,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1731,    -1,    -1,    -1,    -1,  1731,  1563,  1564,    -1,
    1566,    -1,  1568,    -1,    -1,    -1,    -1,    -1,    -1,  1575,
      -1,    -1,    -1,  1753,    -1,    -1,    -1,    -1,  1753,    -1,
      -1,   667,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1774,    -1,  1146,    -1,    -1,  1774,
    1150,    -1,    -1,  1783,    -1,    -1,    -1,  1613,  1783,  1615,
      -1,  1617,    -1,  1619,   700,  1165,    -1,    -1,    -1,  1625,
      -1,  1627,    -1,    -1,  1174,    -1,    -1,    -1,    -1,    -1,
     716,    -1,    -1,    -1,   720,   721,    -1,  1643,  1188,    -1,
    1646,    -1,    -1,   729,    -1,    -1,    -1,    -1,  1198,    -1,
      -1,    -1,  1658,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1669,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1695,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1705,
    1250,    -1,    -1,   789,  1710,    -1,  1712,    -1,  1714,   795,
    1260,    -1,    -1,    -1,  1264,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1750,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1770,    -1,    -1,    -1,    -1,  1775,
      -1,  1321,  1322,    -1,  1324,  1325,  1326,   863,  1328,    -1,
      -1,  1787,    -1,    -1,  1790,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1359,
      -1,    -1,   898,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   911,    -1,    -1,    -1,    -1,
    1380,  1381,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   933,    -1,    -1,
      -1,    -1,    -1,    -1,   940,   941,  1406,    -1,    -1,  1409,
      -1,    -1,  1412,    -1,    -1,   951,    -1,    -1,   954,    -1,
      -1,    -1,  1422,    -1,    -1,    -1,    -1,  1427,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   971,   972,   973,    -1,   975,
     976,   977,   978,   979,   980,   981,   982,   983,    -1,    -1,
     986,   987,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1001,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1011,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1082,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1563,  1564,    -1,  1566,    -1,  1568,    -1,
      -1,    -1,    -1,    -1,    -1,  1575,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1613,    -1,  1615,  1152,  1617,  1154,  1619,
    1156,    -1,    -1,  1159,    -1,  1625,    -1,  1627,  1164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1176,    -1,    -1,  1643,    -1,    -1,  1646,    -1,    -1,  1185,
      -1,    -1,    -1,    -1,    -1,  1191,  1192,    -1,  1658,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1669,
      -1,    -1,  1208,    -1,    -1,  1211,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1695,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1705,    -1,    -1,    -1,    -1,
    1710,    -1,  1712,    -1,  1714,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1281,    -1,    -1,    -1,    -1,
    1750,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1770,    -1,    -1,    -1,    -1,  1775,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1787,    -1,    -1,
    1790,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1367,    -1,    -1,    -1,  1371,    -1,    -1,    -1,  1375,
      -1,  1377,    -1,  1379,    -1,    -1,    -1,    -1,    -1,  1385,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1393,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1401,  1402,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1419,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1431,  1432,  1433,  1434,    -1,
    1436,  1437,    -1,  1439,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1455,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1536,    -1,  1538,    -1,    -1,  1541,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1549,    -1,    -1,    -1,    -1,  1554,  1555,
      -1,    -1,    -1,    -1,    -1,    -1,  1562,    -1,    -1,    -1,
      -1,  1567,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1584,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1596,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1650,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1663,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1713,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,    -1,
      -1,    -1,  1748,    -1,    -1,    -1,    -1,  1753,    -1,    -1,
      -1,    -1,  1758,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,  1773,    -1,    34,
      35,  1777,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,   184,
      -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
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
     305,   306,   307,   308,   309,   310,   311,   312,    -1,   314,
      -1,   316,   317,   318,   319,   320,   321,   322,     0,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
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
     312,     1,   314,    -1,   316,   317,   318,   319,   320,   321,
     322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
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
     310,   311,   312,     1,   314,    -1,   316,   317,   318,   319,
     320,   321,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,
     128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,   150,   151,   152,   153,   154,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,
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
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
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
     306,   307,   308,   309,   310,   311,    -1,    -1,    16,    -1,
     316,   317,   318,   319,   320,   321,   322,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
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
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
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
     308,   309,   310,   311,    -1,    -1,    16,    -1,   316,   317,
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
     320,   321,   322,    18,    19,    -1,    -1,    -1,    -1,    -1,
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
      -1,   316,   317,   318,   319,   320,   321,   322,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,
     183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
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
     323,   324,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,    -1,   178,
     179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,    -1,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,    -1,   314,    -1,   316,   317,   318,
     319,   320,   321,   322,    -1,   324,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,   184,
      -1,   186,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
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
     305,   306,   307,   308,   309,   310,   311,   312,    -1,   314,
      -1,   316,   317,   318,   319,   320,   321,   322,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,
     183,   184,    -1,   186,    -1,   188,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
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
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,   176,    -1,   178,   179,    -1,
      -1,   182,   183,   184,    -1,   186,    -1,   188,    -1,   190,
     191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,   215,    -1,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
     261,   262,   263,    -1,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,    -1,   314,    -1,   316,   317,   318,   319,   320,
     321,   322,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,    -1,   178,
     179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,    -1,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,    -1,   314,    -1,   316,   317,   318,
     319,   320,   321,   322,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,   176,
      -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
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
     307,   308,   309,   310,   311,   312,    -1,   314,    -1,   316,
     317,   318,   319,   320,   321,   322,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,   184,
      -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
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
     305,   306,   307,   308,   309,   310,   311,   312,    -1,   314,
      -1,   316,   317,   318,   319,   320,   321,   322,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,
     183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
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
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,   176,    -1,   178,   179,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,
     191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,   215,    -1,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
     261,   262,   263,    -1,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,    -1,   314,    -1,   316,   317,   318,   319,   320,
     321,   322,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,   146,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,    -1,   178,
     179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,    -1,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,    -1,   314,    -1,   316,   317,   318,
     319,   320,   321,   322,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,   146,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,   176,
      -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,
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
     307,   308,   309,   310,   311,   312,    -1,   314,    -1,   316,
     317,   318,   319,   320,   321,   322,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,   184,
      -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
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
     305,   306,   307,   308,   309,   310,   311,   312,    -1,   314,
      -1,   316,   317,   318,   319,   320,   321,   322,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,
     183,   184,    -1,    -1,   187,   188,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
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
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,   176,    -1,   178,   179,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,   215,    -1,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
     261,   262,   263,    -1,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,    -1,   314,    -1,   316,   317,   318,   319,   320,
     321,   322,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,    -1,   178,
     179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,    -1,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,    -1,   316,   317,   318,
     319,   320,   321,   322,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,   176,
      -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
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
     307,   308,   309,   310,   311,   312,    -1,   314,   315,   316,
     317,   318,   319,   320,   321,   322,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,   184,
      -1,   186,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
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
     305,   306,   307,   308,   309,   310,   311,   312,    -1,   314,
      -1,   316,   317,   318,   319,   320,   321,   322,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
      -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,   146,    -1,   148,   149,   150,   151,   152,
     153,   154,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,
     183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
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
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,
      -1,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,   126,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,   176,    -1,   178,   179,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,
     191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,   215,    -1,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,    -1,
     261,   262,   263,    -1,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,    -1,   314,    -1,   316,   317,   318,   319,   320,
     321,   322,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,   152,   153,   154,   155,   156,    -1,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,    -1,   178,
     179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,    -1,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,    -1,   314,    -1,   316,   317,   318,
     319,   320,   321,   322,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,   126,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,   176,
      -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
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
     307,   308,   309,   310,   311,   312,    -1,   314,    -1,   316,
     317,   318,   319,   320,   321,   322,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,   126,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    -1,   158,   159,    -1,   161,   162,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,   176,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,
      -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
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
     305,   306,   307,   308,   309,   310,   311,   312,    -1,   314,
      -1,   316,   317,   318,   319,   320,   321,   322,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
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
      -1,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
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
     158,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,
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
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
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
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
      -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,
     191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
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
      -1,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
     152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
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
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
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
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,
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
      37,    38,    39,    -1,    41,    42,    43,    44,    -1,    -1,
      47,    48,    -1,    50,    51,    52,    53,    -1,    55,    -1,
      57,    58,    59,    60,    -1,    62,    -1,    -1,    65,    66,
      67,    68,    69,    -1,    71,    -1,    73,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    -1,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
     117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,    -1,   214,    -1,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
      -1,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,    -1,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,    -1,   261,   262,   263,    -1,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,    -1,    -1,    -1,    -1,   316,
     317,   318,   319,   320,   321,   322
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  jsoniq_parser::yystos_[] =
  {
         0,    21,    22,    23,    24,    25,    26,    27,    28,    30,
      34,    35,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    96,    97,
      98,    99,   102,   103,   104,   107,   108,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   126,   128,   129,
     130,   131,   133,   137,   138,   139,   140,   141,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   158,   159,   160,
     161,   162,   167,   168,   169,   170,   171,   172,   173,   174,
     176,   178,   179,   182,   183,   184,   188,   190,   191,   198,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   213,   214,   215,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   261,   262,   263,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   314,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   337,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   358,   359,   360,   361,
     362,   363,   367,   368,   369,   373,   375,   376,   378,   385,
     387,   390,   391,   392,   394,   395,   396,   397,   398,   400,
     401,   403,   404,   405,   406,   407,   408,   410,   411,   414,
     415,   416,   417,   422,   424,   426,   427,   432,   451,   454,
     458,   461,   462,   468,   469,   470,   471,   473,   474,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   486,   487,
     488,   489,   492,   493,   494,   495,   496,   497,   498,   501,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   514,
     515,   516,   517,   518,   519,   533,   534,   536,   537,   538,
     539,   540,   541,   542,   543,   564,   569,   570,   571,   572,
     573,   574,   577,   635,   636,   637,   638,   640,   641,   642,
     643,   644,   651,   652,   653,    34,    35,    50,   217,   393,
     394,   395,   393,   393,   394,   395,   158,   158,    38,    39,
      41,    42,    48,    58,    59,    76,    81,   113,   114,   115,
     162,   222,   263,   289,   297,   305,   374,   375,   379,   380,
     381,   162,   155,   155,   155,     1,     3,    68,    73,   120,
     419,   158,   382,   158,    25,    35,    62,   120,   275,   431,
     433,   434,   155,   120,   155,   158,   158,    78,   155,   223,
     224,   155,   120,   402,    40,    44,    46,    47,    48,    49,
      52,    61,    69,    72,    74,    75,    77,    99,   114,   137,
     162,   171,   204,   226,   228,   230,   231,   238,   240,   241,
     242,   245,   246,   317,   651,   652,   120,   186,   393,   395,
     415,   639,    49,    74,    75,   120,   155,   187,   246,   414,
     416,   426,   189,   414,   651,   155,   155,    16,   650,   651,
      18,    19,   651,   155,    31,   216,   218,   227,   229,   316,
     227,   229,   316,   227,   316,   227,   232,   316,   120,   243,
     243,   244,   158,   155,   397,   313,   414,   315,   414,   316,
     324,   339,   339,     0,   341,   342,    34,    50,   344,   361,
       1,   192,   338,   192,   338,   114,   376,   396,   414,   109,
     192,   109,   338,   192,    43,    47,    52,    71,   170,   173,
     188,   214,   409,   418,   423,   424,   425,   439,   440,   444,
     169,    94,   134,   142,   143,   145,   153,   157,   159,   164,
     181,   205,   206,   207,   208,   209,   210,   490,   491,   251,
     101,   160,   178,   201,   119,   148,   161,   196,   203,   212,
     138,   152,    51,   202,   103,   104,   160,   178,   488,   195,
     155,   495,   156,   158,   502,   503,   121,   147,   158,   186,
     186,   186,   186,   377,   505,   377,    30,   649,   184,   198,
     184,   198,   168,   184,   652,   651,   171,   204,    48,   651,
     154,   120,    46,    48,    81,   108,   170,   650,   223,   224,
     225,   248,   608,   651,   651,   306,   139,   144,   114,   289,
     297,   379,   650,   394,   394,   414,   428,   429,   651,   286,
     286,   428,   120,   435,   120,   189,   383,   384,   155,   399,
     414,     1,   162,   649,   115,   162,   357,   649,   651,   120,
     144,   109,   414,   452,   453,   651,   394,   414,   414,   562,
     651,   394,   155,   155,   414,   651,   144,   452,   186,   186,
     123,   109,   186,   158,   158,   158,   651,   155,   187,   188,
     189,    36,   521,   522,   523,   414,   414,     8,   177,    17,
     414,   216,    30,   415,   415,   501,   415,   415,   415,   639,
     415,   501,   415,   233,   232,   575,   576,   651,   192,   192,
     415,   414,   395,   414,   247,   412,   413,   313,   315,   415,
     339,   192,   338,   192,   338,     3,   345,   361,   391,     1,
     345,   361,   391,    34,   362,   391,   362,   391,   402,   338,
     402,   415,   415,   120,   170,   172,   172,   396,   415,   415,
     470,   471,   473,   473,   473,   473,   472,   473,   473,   473,
      72,   474,   478,   478,   477,   479,   479,   479,   479,   480,
     480,   481,   481,   233,    96,    96,    96,   496,   186,   414,
     414,   146,   189,   415,   513,   503,   650,   151,   189,   513,
     109,   189,   189,   109,   109,   382,    30,   652,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,   364,   365,
     366,    96,   139,   144,   370,   371,   372,   651,   162,   162,
     364,   649,   129,   134,    56,    58,   102,   253,   266,   268,
     279,   280,   281,   283,   285,   609,   610,   611,   612,   613,
     614,   621,   627,   628,   248,    96,   301,   651,   144,   415,
     120,   651,   651,   134,   186,   186,   186,   109,    37,    96,
      98,   149,   430,   431,   544,   651,    57,   219,   256,   420,
     421,   651,    96,   109,   189,   393,   189,   650,    98,    46,
     650,   649,    98,   144,   544,   651,   415,   434,   186,   109,
     190,   149,   544,   186,   189,   189,   155,   186,   394,   394,
     186,   144,   544,   415,   190,   415,   415,   414,   414,   414,
     651,   522,   523,   132,   199,   186,   186,   186,   133,   192,
      96,   220,   221,   235,    96,   220,   221,   235,   235,   235,
      96,    96,   239,   227,   233,   109,   237,   144,   192,   189,
     414,   186,    11,    12,    20,   196,   499,   500,   581,   651,
     413,   235,   361,    34,    34,   192,   338,   192,   115,   396,
     651,   172,   415,   445,   446,   120,   441,   442,   473,   155,
     158,   261,   494,   505,   582,   585,   586,   587,   588,   589,
     593,   595,   597,   598,    40,    45,    46,    48,    54,    61,
      63,    64,    72,    99,   154,   158,   213,   227,   319,   320,
     321,   322,   545,   547,   549,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   565,   566,   567,   568,
     645,   646,   647,   648,   651,   545,   485,   550,   651,   485,
     186,   187,   109,   189,   189,   505,   150,   167,   150,   167,
     139,   399,   382,   365,   134,   547,   372,   415,   544,   649,
     649,   130,   131,   649,   279,   280,   281,   285,   651,   265,
     276,   265,   276,    30,   288,    98,   115,   158,   615,   618,
     609,    40,    45,    46,    54,    61,    63,    64,    72,    99,
     227,   319,   320,   321,   386,   551,   645,   229,   301,   310,
     415,   651,    96,   301,   649,   155,   120,   429,   129,   545,
     120,   415,   149,   431,   149,    37,   149,   430,   431,   149,
     544,   256,    55,    60,    79,   120,   430,   436,   437,   438,
     421,   544,   545,   384,    96,   186,   200,   134,   356,   649,
     162,   134,    98,   356,   415,   144,   431,   155,   120,   415,
     415,   149,   102,   455,   456,   457,   459,   460,   102,   463,
     464,   465,   466,   394,   186,   186,   155,   415,   144,   192,
     415,   123,   189,   189,   189,    36,   523,   132,   199,     9,
      10,   105,   125,   127,   155,   197,   518,   520,   531,   532,
     535,   155,    30,   234,   236,   415,   415,   415,   234,   236,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   501,
     120,   415,   415,    49,    74,    75,   246,   396,   416,   426,
     247,   578,   579,   155,   212,   397,   415,   192,   115,   391,
     391,   391,   445,    97,   108,   118,   129,   447,   448,   449,
     450,   109,   651,   109,   414,   582,   589,   155,   287,   475,
     634,    98,   171,   254,   255,   257,   264,   274,   286,   583,
     584,   603,   604,   605,   606,   629,   632,   260,   262,   590,
     608,   269,   594,   630,   249,   250,   272,   599,   600,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     547,   158,   158,   158,   158,   158,   158,   146,   178,   196,
     546,   146,   146,   415,   139,   399,   564,   371,   288,    30,
      98,   115,   158,   622,    30,   615,   546,   546,   496,   289,
     308,   544,   386,   229,   192,   393,   429,   149,   430,   651,
     415,   149,   415,   129,   415,   149,   431,   149,   415,   149,
     120,   120,   415,   651,   438,    79,   545,   396,   415,   649,
     109,   356,   415,   144,   393,   453,   415,   415,   115,   456,
     457,   102,   188,   115,   457,   460,   120,   467,   545,   102,
     115,   464,   102,   115,   466,   186,   393,   415,   415,   200,
     463,   134,   197,   520,     7,   394,   651,   197,   531,   394,
     192,   235,   235,   235,   235,    98,   239,   239,   576,   188,
     158,   158,   158,   188,   581,   579,   499,   649,   130,   131,
     449,   450,   450,   446,   108,   144,   443,   544,   442,   186,
     189,   582,   596,   252,   219,   256,   270,   277,   633,    98,
     258,   259,   631,   252,   586,   633,   477,   603,   587,   149,
     284,   591,   592,   631,   288,   602,    80,   601,   189,   189,
     560,   561,   189,   196,   651,   189,   196,   545,   548,   189,
      30,   189,   650,   651,   651,   189,   189,   196,   651,   189,
     189,   189,   189,   189,   189,   189,   189,    30,   138,   203,
     624,   625,   626,    30,   623,   624,   273,   619,   109,   616,
     172,   651,   259,   496,   186,   415,   149,   415,   149,   430,
     415,   149,   415,   415,   651,   651,   437,   415,   128,   128,
      98,   649,   415,   186,   188,   188,   415,   396,   415,   188,
     188,   651,   188,   212,   120,   467,   120,   188,   120,   467,
     188,   186,   115,   523,   651,   197,   186,   523,   651,   186,
     415,   415,   415,   415,   318,   415,   415,   415,   414,   414,
     414,   155,   580,   450,   649,   415,   144,   186,   479,    53,
     131,   477,   477,   271,   278,   288,   607,   607,   588,   155,
     282,   189,   189,   109,   189,   109,   189,    96,   189,   109,
     189,   189,   189,   189,   189,   109,   189,   109,   189,   622,
     622,   626,   109,   189,    30,   620,   631,   617,   618,   189,
     388,   389,   496,   120,   227,   309,   289,   172,   415,   415,
     149,   415,    55,   396,   415,   356,   415,   396,    96,   396,
     415,   545,   651,   188,   651,   415,   651,   188,   396,   120,
      95,   185,   524,   523,   651,   199,   523,   415,   189,   189,
     189,   414,   443,   415,   477,   477,   201,   414,   562,   563,
     651,   562,   563,   545,   545,    96,   562,   562,    30,   267,
     109,   109,   450,   544,   651,   120,   227,   651,   388,   415,
     120,   467,    96,   188,    96,   651,     5,   135,   527,   528,
     530,   532,    29,   136,   525,   526,   529,   532,   199,   523,
     199,   200,   463,   186,   443,   477,   186,   189,   189,   146,
     189,   189,   545,   189,   189,   618,   389,   450,   307,   651,
     120,   227,   651,   188,   467,   396,   415,   467,   188,    95,
     135,   530,   185,   136,   529,   199,   115,   415,   307,   651,
     120,   396,   415,   188,   188,   120,   295,   307,   651,   651,
     308,   415,   308,   188,   496,   496,   201,   289,   651,   227,
     120,   651,   308,   496
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
     585,   586,   587,   588,   589,   590
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  jsoniq_parser::yyr1_[] =
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
     497,   498,   499,   499,   500,   500,   500,   500,   501,   501,
     501,   501,   502,   502,   503,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     505,   505,   506,   506,   506,   507,   508,   508,   509,   510,
     511,   512,   512,   513,   513,   513,   513,   514,   514,   515,
     516,   517,   517,   518,   518,   518,   519,   519,   519,   519,
     519,   519,   520,   520,   521,   521,   522,   523,   523,   524,
     524,   525,   525,   526,   526,   526,   526,   527,   527,   528,
     528,   528,   528,   529,   529,   530,   530,   531,   531,   531,
     531,   532,   532,   532,   532,   533,   533,   534,   534,   535,
     536,   536,   536,   536,   536,   536,   536,   537,   538,   538,
     539,   539,   540,   541,   542,   542,   543,   543,   544,   545,
     545,   545,   546,   546,   546,   547,   547,   547,   547,   547,
     547,   547,   548,   548,   549,   550,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   552,   553,   553,   553,
     554,   555,   556,   557,   557,   557,   558,   558,   558,   558,
     558,   559,   560,   560,   560,   560,   560,   560,   560,   561,
     562,   563,   564,   565,   565,   566,   567,   567,   568,   569,
     569,   569,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   570,   571,   571,   572,   572,   573,   574,   575,   575,
     576,   577,   578,   578,   579,   580,   581,   581,   582,   583,
     583,   584,   584,   585,   585,   586,   586,   587,   587,   588,
     588,   589,   590,   590,   591,   591,   592,   593,   593,   593,
     594,   594,   595,   596,   596,   597,   598,   598,   599,   599,
     600,   600,   600,   601,   601,   602,   602,   603,   603,   603,
     603,   603,   604,   605,   606,   607,   607,   607,   608,   608,
     609,   609,   609,   609,   609,   609,   609,   609,   610,   610,
     610,   610,   611,   611,   612,   613,   613,   614,   614,   614,
     615,   615,   616,   616,   617,   617,   618,   619,   619,   620,
     620,   621,   621,   621,   622,   622,   623,   623,   624,   624,
     625,   625,   626,   626,   627,   628,   628,   629,   629,   629,
     630,   631,   631,   631,   631,   632,   632,   633,   633,   634,
     635,   635,   636,   636,   637,   637,   638,   639,   639,   640,
     640,   640,   641,   642,   643,   644,   645,   645,   645,   646,
     647,   648,   649,   650,   650,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   652,   652,
     652,   652,   652,   652,   652,   652,   652,   652,   653
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  jsoniq_parser::yyr2_[] =
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     4,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
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
  "ExtensionExpr", "Pragma_list", "Pragma", "PathExpr", "RelativePathExpr",
  "StepExpr", "NameTest", "Wildcard", "FilterExpr", "PredicateList",
  "Predicate", "PrimaryExpr", "Literal", "NumericLiteral", "VarRef",
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
  const jsoniq_parser::rhs_number_type
  jsoniq_parser::yyrhs_[] =
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
      -1,   343,   344,   192,   361,   192,    -1,    35,   162,   650,
     134,   649,   192,    -1,   345,    -1,   344,   192,   345,    -1,
     344,   338,   345,    -1,   346,    -1,   354,    -1,   359,    -1,
     360,    -1,   368,    -1,   347,    -1,   348,    -1,   349,    -1,
     350,    -1,   351,    -1,   352,    -1,   353,    -1,   569,    -1,
      34,    39,   184,    -1,    34,    39,   198,    -1,    34,   115,
     108,   649,    -1,    34,    38,   649,    -1,    34,    41,   184,
      -1,    34,    41,   198,    -1,    34,    59,   171,    -1,    34,
      59,   204,    -1,    34,   115,   170,   129,   130,    -1,    34,
     115,   170,   129,   131,    -1,    34,    42,   184,   109,   150,
      -1,    34,    42,   184,   109,   167,    -1,    34,    42,   168,
     109,   150,    -1,    34,    42,   168,   109,   167,    -1,   355,
      -1,   358,    -1,    50,    25,     1,    -1,    50,    62,   649,
      -1,    50,    62,   357,   649,    -1,    50,    62,   649,    98,
     356,    -1,    50,    62,   357,   649,    98,   356,    -1,   649,
      -1,   356,   109,   649,    -1,   162,   650,   134,    -1,   115,
      46,   162,    -1,    50,    35,   649,    -1,    50,    35,   162,
     650,   134,   649,    -1,    50,    35,   649,    98,   356,    -1,
      50,    35,   162,   650,   134,   649,    98,   356,    -1,    34,
     162,   650,   134,   649,    -1,    34,   115,    46,   162,   649,
      -1,    34,   115,    48,   162,   649,    -1,   362,    -1,   361,
     192,   362,    -1,   361,   338,   362,    -1,   363,    -1,   367,
      -1,   369,    -1,   373,    -1,   378,    -1,   385,    -1,   387,
      -1,   390,    -1,    34,   115,    81,   364,    -1,    34,    81,
     651,   364,    -1,   365,    -1,   364,   365,    -1,   366,   134,
     564,    -1,    82,    -1,    90,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    91,    -1,    87,    -1,    88,    -1,
      89,    -1,    34,    58,   651,    30,    -1,    34,   263,   608,
      -1,    34,   113,   154,   370,    -1,    96,   547,   371,    -1,
     371,    -1,   372,    -1,   139,    -1,   139,   372,    -1,   144,
     415,    -1,    34,   374,   144,   415,    -1,    34,   374,   139,
      -1,    34,   374,   139,   144,   415,    -1,   114,   120,   651,
      -1,   114,   120,   651,   544,    -1,   375,   114,   120,   651,
      -1,   375,   114,   120,   651,   544,    -1,   376,    -1,   375,
     376,    -1,    27,    -1,    27,   158,   377,   189,    -1,    28,
      -1,    28,   158,   377,   189,    -1,   505,    -1,   377,   109,
     505,    -1,    34,   379,    -1,    34,   375,   379,    -1,   380,
      -1,   381,    -1,    48,   652,   382,   399,    -1,    48,   652,
     382,   139,    -1,    76,    48,   652,   382,   399,    -1,    76,
      48,   652,   382,   139,    -1,   158,   189,    -1,   158,   383,
     189,    -1,   158,   189,    96,   545,    -1,   158,   383,   189,
      96,   545,    -1,   384,    -1,   383,   109,   384,    -1,   120,
     651,    -1,   120,   651,   544,    -1,    34,   289,   651,    -1,
      34,   289,   651,    96,   386,    -1,    34,   375,   289,   651,
      -1,    34,   375,   289,   651,    96,   386,    -1,   551,    -1,
     551,   546,    -1,   645,    -1,   645,   546,    -1,    34,   297,
     651,   301,   229,   496,   172,   388,    -1,    34,   375,   297,
     651,   301,   229,   496,   172,   388,    -1,   389,    -1,   388,
     109,   389,    -1,   496,    -1,   496,   544,    -1,   496,   450,
      -1,   496,   544,   450,    -1,    34,   305,   306,   651,   301,
     289,   651,   120,   651,   307,   415,    -1,    34,   305,   306,
     651,   301,   289,   651,   227,   120,   651,   307,   295,   308,
     496,    -1,    34,   305,   306,   651,   301,   289,   651,   309,
     227,   120,   651,   307,   415,    -1,    34,   305,   306,   651,
     310,   308,   259,   289,   651,   227,   120,   651,   308,   496,
     201,   289,   651,   227,   120,   651,   308,   496,    -1,   392,
      -1,   394,    -1,   395,    -1,    -1,   394,    -1,   395,    -1,
      -1,   414,    -1,   395,   414,    -1,   396,    -1,   395,   396,
      -1,   395,   414,   338,   396,    -1,   397,    -1,   400,    -1,
     403,    -1,   404,    -1,   405,    -1,   406,    -1,   407,    -1,
     408,    -1,   410,    -1,   462,    -1,   458,    -1,   411,    -1,
     155,   395,   186,    -1,   155,   186,    -1,   155,   393,   186,
      -1,   155,   393,   186,    -1,   401,   192,    -1,   401,   109,
     402,    -1,   114,   402,    -1,   375,   114,   402,    -1,   120,
     651,    -1,   120,   651,   544,    -1,   120,   651,   144,   415,
      -1,   120,   651,   544,   144,   415,    -1,   120,   651,   144,
     415,   192,    -1,   416,   192,    -1,   242,   244,   415,   192,
      -1,   245,   158,   414,   189,   396,    -1,   240,   243,   192,
      -1,   241,   243,   192,    -1,   426,   409,    -1,   188,   396,
      -1,    49,   158,   414,   189,   200,   396,   128,   396,    -1,
     246,   397,   412,    -1,   413,    -1,   412,   413,    -1,   247,
     581,   397,    -1,   415,    -1,   414,   109,   415,    -1,   414,
     338,   415,    -1,   417,    -1,   454,    -1,   461,    -1,   468,
      -1,   577,    -1,   416,    -1,   469,    -1,   451,    -1,   570,
      -1,   571,    -1,   573,    -1,   572,    -1,   574,    -1,   642,
      -1,   640,    -1,   643,    -1,   644,    -1,   641,    -1,   426,
     418,    -1,   188,   415,    -1,    68,   286,    -1,    73,   286,
      -1,   219,    -1,   256,    -1,    57,   256,    -1,   420,   436,
      79,   415,    -1,   420,    79,   415,    -1,    47,   419,   435,
     421,   421,    -1,    47,   419,   435,   421,    -1,    43,   120,
     651,    -1,   427,    -1,   432,    -1,   422,    -1,   424,    -1,
     439,    -1,   444,    -1,   440,    -1,   423,    -1,   424,    -1,
     426,   425,    -1,    47,   120,   428,    -1,    47,     1,   428,
      -1,    47,     3,    -1,   429,    -1,   428,   109,   120,   429,
      -1,   428,   109,   429,    -1,   651,   149,   415,    -1,   651,
      37,   129,   149,   415,    -1,   651,   544,   149,   415,    -1,
     651,   544,    37,   129,   149,   415,    -1,   651,   430,   149,
     415,    -1,   651,    37,   129,   430,   149,   415,    -1,   651,
     544,   430,   149,   415,    -1,   651,   544,    37,   129,   430,
     149,   415,    -1,   651,   431,   149,   415,    -1,   651,   544,
     431,   149,   415,    -1,   651,   430,   431,   149,   415,    -1,
     651,   544,   430,   431,   149,   415,    -1,    98,   120,   651,
      -1,   275,   120,   651,    -1,    52,   433,    -1,   434,    -1,
     433,   109,   434,    -1,   120,   651,   144,   415,    -1,   120,
     651,   544,   144,   415,    -1,   431,   144,   415,    -1,   120,
     651,   544,   431,   144,   415,    -1,   120,   651,   149,   415,
      -1,   120,   651,   544,   149,   415,    -1,   437,    -1,   120,
     651,    -1,   120,   651,   437,    -1,   430,    -1,   430,   438,
      -1,   438,    -1,    60,   120,   651,    55,   120,   651,    -1,
      55,   120,   651,    -1,    60,   120,   651,    -1,   214,   415,
      -1,   173,   172,   441,    -1,   442,    -1,   441,   109,   442,
      -1,   120,   651,    -1,   120,   651,   144,   415,    -1,   120,
     651,   544,   144,   415,    -1,   120,   651,   544,   144,   415,
     443,    -1,   120,   651,   144,   415,   443,    -1,   120,   651,
     443,    -1,   108,   649,    -1,   170,   172,   445,    -1,    71,
     170,   172,   445,    -1,   446,    -1,   445,   109,   446,    -1,
     415,    -1,   415,   447,    -1,   448,    -1,   449,    -1,   450,
      -1,   448,   449,    -1,   448,   450,    -1,   449,   450,    -1,
     448,   449,   450,    -1,    97,    -1,   118,    -1,   129,   130,
      -1,   129,   131,    -1,   108,   649,    -1,    69,   120,   452,
     190,   415,    -1,   137,   120,   452,   190,   415,    -1,   453,
      -1,   452,   109,   120,   453,    -1,   651,   149,   415,    -1,
     651,   544,   149,   415,    -1,    74,   158,   414,   189,   455,
     115,   188,   415,    -1,   456,    -1,   455,   456,    -1,   457,
     188,   415,    -1,   102,   415,    -1,   457,   102,   415,    -1,
      74,   158,   414,   189,   459,   115,   188,   396,    -1,   460,
      -1,   459,   460,    -1,   457,   188,   396,    -1,    75,   158,
     414,   189,   463,   115,   188,   415,    -1,    75,   158,   414,
     189,   463,   115,   120,   651,   188,   415,    -1,    75,   158,
     414,   189,   465,   115,   188,   396,    -1,    75,   158,   414,
     189,   463,   115,   120,   651,   188,   396,    -1,   464,    -1,
     463,   464,    -1,   102,   467,   188,   415,    -1,   102,   120,
     651,    96,   467,   188,   415,    -1,   466,    -1,   465,   466,
      -1,   102,   467,   188,   396,    -1,   102,   120,   651,    96,
     467,   188,   396,    -1,   545,    -1,   467,   212,   545,    -1,
      49,   158,   414,   189,   200,   415,   128,   415,    -1,   470,
      -1,   469,   169,   470,    -1,   471,    -1,   470,    94,   471,
      -1,   473,    -1,   473,   490,   473,    -1,   473,   491,   473,
      -1,   473,   134,   473,    -1,   473,   164,   473,    -1,    -1,
     473,   159,   472,   473,    -1,   473,   157,   473,    -1,   473,
     145,   473,    -1,   473,   143,   473,    -1,   474,    -1,   474,
     251,    72,   582,   475,    -1,   476,    -1,   476,   101,   474,
      -1,    -1,   634,    -1,   477,    -1,   477,   201,   477,    -1,
     478,    -1,   477,   178,   478,    -1,   477,   160,   478,    -1,
     479,    -1,   478,   196,   479,    -1,   478,   119,   479,    -1,
     478,   148,   479,    -1,   478,   161,   479,    -1,   480,    -1,
     479,   203,   480,    -1,   479,   212,   480,    -1,   481,    -1,
     480,   152,   481,    -1,   480,   138,   481,    -1,   482,    -1,
     482,    51,   233,   545,    -1,   483,    -1,   483,   202,    96,
     545,    -1,   484,    -1,   484,   103,    96,   485,    -1,   486,
      -1,   486,   104,    96,   485,    -1,   550,    -1,   550,   146,
      -1,   488,    -1,   487,   488,    -1,   178,    -1,   160,    -1,
     487,   178,    -1,   487,   160,    -1,   492,    -1,   489,    -1,
     493,    -1,   496,    -1,   489,   195,   496,    -1,   205,    -1,
     210,    -1,   209,    -1,   208,    -1,   207,    -1,   206,    -1,
     153,    -1,   181,    -1,   142,    -1,    77,   155,   394,   186,
      -1,    77,   224,   155,   394,   186,    -1,    77,   223,   155,
     394,   186,    -1,    77,    78,   562,   155,   394,   186,    -1,
     494,   155,   186,    -1,   494,   155,   414,   186,    -1,   495,
      -1,   494,   495,    -1,   179,   651,    17,    -1,   179,    18,
      -1,   179,    19,    -1,   497,    -1,   498,    -1,   501,    -1,
     651,    -1,   500,    -1,   196,    -1,    11,    -1,    12,    -1,
      20,    -1,   504,    -1,   501,   502,    -1,   501,   158,   189,
      -1,   501,   158,   513,   189,    -1,   503,    -1,   502,   503,
      -1,   156,   414,   187,    -1,   505,    -1,   507,    -1,   508,
      -1,   509,    -1,   512,    -1,   517,    -1,   510,    -1,   511,
      -1,   514,    -1,   398,    -1,   638,    -1,   635,    -1,   636,
      -1,   637,    -1,   504,   121,   650,    -1,   506,    -1,   564,
      -1,   112,    -1,   151,    -1,   126,    -1,   120,   651,    -1,
     158,   189,    -1,   158,   414,   189,    -1,   121,    -1,   171,
     155,   414,   186,    -1,   204,   155,   414,   186,    -1,   652,
     158,   189,    -1,   652,   158,   513,   189,    -1,   146,    -1,
     513,   109,   146,    -1,   415,    -1,   513,   109,   415,    -1,
     515,    -1,   516,    -1,   651,   147,   151,    -1,    48,   382,
     399,    -1,   518,    -1,   536,    -1,   519,    -1,   533,    -1,
     534,    -1,   159,   651,   523,   132,    -1,   159,   651,   523,
     199,   197,   651,   523,   199,    -1,   159,   651,   521,   523,
     132,    -1,   159,   651,   521,   523,   199,   197,   651,   523,
     199,    -1,   159,   651,   523,   199,   520,   197,   651,   523,
     199,    -1,   159,   651,   521,   523,   199,   520,   197,   651,
     523,   199,    -1,   531,    -1,   520,   531,    -1,   522,    -1,
     521,   522,    -1,    36,   651,   523,   134,   523,   524,    -1,
      -1,    36,    -1,   185,   525,   185,    -1,    95,   527,    95,
      -1,    -1,   526,    -1,   136,    -1,   529,    -1,   526,   136,
      -1,   526,   529,    -1,    -1,   528,    -1,   135,    -1,   530,
      -1,   528,   135,    -1,   528,   530,    -1,    29,    -1,   532,
      -1,     5,    -1,   532,    -1,   518,    -1,    10,    -1,   535,
      -1,   532,    -1,     9,    -1,   125,    -1,   127,    -1,   155,
     394,   186,    -1,   215,    31,   216,    -1,   215,   216,    -1,
     176,   650,   177,    -1,   176,   650,     8,    -1,   105,     7,
      -1,   537,    -1,   538,    -1,   539,    -1,   540,    -1,   541,
      -1,   542,    -1,   543,    -1,    44,   155,   394,   186,    -1,
      21,   393,   186,    -1,    46,   155,   414,   186,   155,   393,
     186,    -1,    22,   393,   186,    -1,    99,   155,   414,   186,
     155,   393,   186,    -1,    72,   155,   394,   186,    -1,    40,
     155,   394,   186,    -1,    23,   393,   186,    -1,    61,   155,
     414,   186,   155,   393,   186,    -1,    24,   394,   186,    -1,
     162,   155,   414,   186,   155,   394,   186,    -1,    96,   545,
      -1,   547,    -1,   547,   546,    -1,   213,   158,   189,    -1,
     146,    -1,   196,    -1,   178,    -1,   549,    -1,   551,    -1,
     154,   158,   189,    -1,   322,   158,   189,    -1,   565,    -1,
     568,    -1,   645,    -1,   545,    -1,   548,   109,   545,    -1,
     651,    -1,   651,    -1,   553,    -1,   560,    -1,   558,    -1,
     561,    -1,   559,    -1,   557,    -1,   556,    -1,   555,    -1,
     554,    -1,   552,    -1,   227,   158,   189,    -1,    45,   158,
     189,    -1,    45,   158,   560,   189,    -1,    45,   158,   561,
     189,    -1,    54,   158,   189,    -1,    72,   158,   189,    -1,
      40,   158,   189,    -1,    61,   158,   189,    -1,    61,   158,
     650,   189,    -1,    61,   158,    30,   189,    -1,    99,   158,
     189,    -1,    99,   158,   651,   189,    -1,    99,   158,   651,
     109,   562,   189,    -1,    99,   158,   196,   189,    -1,    99,
     158,   196,   109,   562,   189,    -1,    63,   158,   651,   189,
      -1,    46,   158,   189,    -1,    46,   158,   651,   189,    -1,
      46,   158,   651,   109,   562,   189,    -1,    46,   158,   651,
     109,   563,   189,    -1,    46,   158,   196,   189,    -1,    46,
     158,   196,   109,   562,   189,    -1,    46,   158,   196,   109,
     563,   189,    -1,    64,   158,   651,   189,    -1,   651,    -1,
     651,   146,    -1,    30,    -1,   566,    -1,   567,    -1,    48,
     158,   196,   189,    -1,    48,   158,   189,    96,   545,    -1,
      48,   158,   548,   189,    96,   545,    -1,   158,   547,   189,
      -1,    34,   222,   223,    -1,    34,   222,   224,    -1,    34,
     222,   225,    -1,   228,   227,   415,   235,   415,    -1,   228,
     227,   415,    96,   234,   235,   415,    -1,   228,   227,   415,
      96,   236,   235,   415,    -1,   228,   227,   415,   220,   415,
      -1,   228,   227,   415,   221,   415,    -1,   228,   229,   415,
     235,   415,    -1,   228,   229,   415,    96,   234,   235,   415,
      -1,   228,   229,   415,    96,   236,   235,   415,    -1,   228,
     229,   415,   220,   415,    -1,   228,   229,   415,   221,   415,
      -1,   226,   227,   415,    -1,   226,   229,   415,    -1,   231,
     227,   415,   239,   415,    -1,   231,   232,   233,   227,   415,
     239,   415,    -1,   230,   227,   415,    96,   415,    -1,   238,
     120,   575,   237,   415,   188,   415,    -1,   576,    -1,   575,
     109,   120,   576,    -1,   651,   144,   415,    -1,   246,   155,
     414,   186,   578,    -1,   579,    -1,   578,   579,    -1,   247,
     581,   580,    -1,   155,   414,   186,    -1,   499,    -1,   581,
     212,   499,    -1,   585,   583,    -1,    -1,   584,    -1,   603,
      -1,   584,   603,    -1,   586,    -1,   585,   264,   586,    -1,
     587,    -1,   586,   260,   587,    -1,   588,    -1,   587,   262,
     149,   588,    -1,   589,    -1,   261,   589,    -1,   593,   590,
     591,    -1,    -1,   608,    -1,    -1,   592,    -1,   284,   155,
     414,   186,    -1,   597,   594,    -1,   158,   582,   189,    -1,
     595,    -1,    -1,   630,    -1,   494,   155,   596,   186,    -1,
      -1,   582,    -1,   598,   599,    -1,   505,    -1,   155,   414,
     186,    -1,    -1,   600,    -1,   250,   601,    -1,   249,   602,
      -1,   272,    -1,    -1,    80,    -1,    -1,   288,    -1,   604,
      -1,   605,    -1,   606,    -1,   632,    -1,   629,    -1,   171,
      -1,   286,   477,   607,    -1,   255,   631,   607,    -1,   288,
      -1,   278,    -1,   271,    -1,   248,   609,    -1,   608,   248,
     609,    -1,   610,    -1,   611,    -1,   612,    -1,   627,    -1,
     613,    -1,   621,    -1,   614,    -1,   628,    -1,   102,   276,
      -1,   102,   265,    -1,   268,    -1,   283,    -1,   253,   276,
      -1,   253,   265,    -1,    58,   651,    30,    -1,   279,    -1,
      56,   279,    -1,   281,   615,    -1,   281,   158,   615,   616,
     189,    -1,    56,   281,    -1,   618,    -1,   115,    -1,    -1,
     109,   617,    -1,   618,    -1,   617,   109,   618,    -1,    98,
      30,   619,   620,    -1,    -1,   273,    30,    -1,    -1,   631,
     267,    -1,   280,   288,   622,   624,    -1,   280,   288,   115,
     624,    -1,    56,   280,   288,    -1,    98,    30,    -1,   158,
     623,   189,    -1,    30,    -1,   623,   109,    30,    -1,    -1,
     625,    -1,   626,    -1,   625,   626,    -1,   203,   622,    -1,
     138,   622,    -1,   266,    30,    -1,   285,    -1,    56,   285,
      -1,    98,   219,    -1,    98,   256,    -1,   257,   252,    -1,
     269,   631,   282,    -1,   258,   477,    -1,    98,   131,   477,
      -1,    98,    53,   477,    -1,   259,   477,   201,   477,    -1,
     274,   633,    -1,   254,   633,    -1,   277,    -1,   270,    -1,
     287,   252,   479,    -1,   156,   187,    -1,   156,   414,   187,
      -1,   312,   313,    -1,   312,   414,   313,    -1,   314,   315,
      -1,   314,   414,   315,    -1,   155,   639,   186,    -1,   415,
     123,   415,    -1,   639,   109,   415,   123,   415,    -1,   228,
     316,   415,   235,   415,    -1,   228,   316,   639,   235,   415,
      -1,   228,   316,   415,   235,   415,    98,   318,   415,    -1,
     317,   316,   415,   235,   415,    -1,   226,   316,   501,    -1,
     230,   316,   501,    96,   415,    -1,   231,   316,   232,   233,
     501,   239,   415,    -1,   646,    -1,   647,    -1,   648,    -1,
     321,   158,   189,    -1,   319,   158,   189,    -1,   320,   158,
     189,    -1,    30,    -1,    16,    -1,   651,    -1,   652,    -1,
      99,    -1,    40,    -1,    45,    -1,    54,    -1,    46,    -1,
     154,    -1,    49,    -1,   227,    -1,    61,    -1,    63,    -1,
      64,    -1,    72,    -1,    75,    -1,    74,    -1,   213,    -1,
     245,    -1,   653,    -1,    25,    -1,   217,    -1,   129,    -1,
      39,    -1,   263,    -1,    38,    -1,   224,    -1,   223,    -1,
     148,    -1,    44,    -1,   261,    -1,   262,    -1,   276,    -1,
     265,    -1,   253,    -1,   287,    -1,   279,    -1,   281,    -1,
     280,    -1,   285,    -1,   257,    -1,   252,    -1,    80,    -1,
     219,    -1,   256,    -1,    53,    -1,   225,    -1,   238,    -1,
     304,    -1,   232,    -1,   205,    -1,   210,    -1,   209,    -1,
     208,    -1,   207,    -1,   206,    -1,    98,    -1,   113,    -1,
     114,    -1,   188,    -1,    47,    -1,    37,    -1,    68,    -1,
      73,    -1,    60,    -1,    55,    -1,    57,    -1,    79,    -1,
      43,    -1,   149,    -1,    52,    -1,   214,    -1,   172,    -1,
     173,    -1,   170,    -1,    71,    -1,    97,    -1,   118,    -1,
     130,    -1,   131,    -1,   108,    -1,    69,    -1,   137,    -1,
     190,    -1,   102,    -1,    96,    -1,   200,    -1,   128,    -1,
     169,    -1,    94,    -1,    51,    -1,   233,    -1,   103,    -1,
     201,    -1,   119,    -1,   161,    -1,   203,    -1,   152,    -1,
     138,    -1,    77,    -1,    78,    -1,   104,    -1,   202,    -1,
     153,    -1,   184,    -1,   198,    -1,   162,    -1,   139,    -1,
     133,    -1,   168,    -1,   150,    -1,   167,    -1,    34,    -1,
      41,    -1,    59,    -1,   115,    -1,    42,    -1,    58,    -1,
     218,    -1,    50,    -1,    62,    -1,    35,    -1,    48,    -1,
     275,    -1,   251,    -1,   284,    -1,   286,    -1,   255,    -1,
     269,    -1,   282,    -1,   274,    -1,   254,    -1,   268,    -1,
     283,    -1,   273,    -1,   267,    -1,   266,    -1,   250,    -1,
     249,    -1,   258,    -1,   259,    -1,   288,    -1,   278,    -1,
     277,    -1,   272,    -1,   270,    -1,   271,    -1,   231,    -1,
     237,    -1,   234,    -1,   228,    -1,   221,    -1,   220,    -1,
     222,    -1,   239,    -1,   229,    -1,   230,    -1,   236,    -1,
     226,    -1,   235,    -1,    67,    -1,    65,    -1,    76,    -1,
     171,    -1,   204,    -1,   244,    -1,   242,    -1,   243,    -1,
     240,    -1,   241,    -1,   246,    -1,   247,    -1,   248,    -1,
      66,    -1,   297,    -1,   295,    -1,   296,    -1,   301,    -1,
     302,    -1,   303,    -1,   298,    -1,   299,    -1,   300,    -1,
      81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,
      86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,
      91,    -1,   289,    -1,   290,    -1,   291,    -1,   292,    -1,
     293,    -1,   294,    -1,   305,    -1,   306,    -1,   307,    -1,
     308,    -1,   309,    -1,   310,    -1,   311,    -1,    92,    -1,
     107,    -1,   116,    -1,   174,    -1,   182,    -1,   191,    -1,
     140,    -1,    93,    -1,   117,    -1,   141,    -1,   183,    -1,
     316,    -1,   317,    -1,   318,    -1,   321,    -1,   320,    -1,
     319,    -1,   322,    -1,    26,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  jsoniq_parser::yyprhs_[] =
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
    1596,  1598,  1600,  1602,  1604,  1606,  1608,  1610,  1612,  1614,
    1617,  1621,  1626,  1628,  1631,  1635,  1637,  1639,  1641,  1643,
    1645,  1647,  1649,  1651,  1653,  1655,  1657,  1659,  1661,  1663,
    1667,  1669,  1671,  1673,  1675,  1677,  1680,  1683,  1687,  1689,
    1694,  1699,  1703,  1708,  1710,  1714,  1716,  1720,  1722,  1724,
    1728,  1732,  1734,  1736,  1738,  1740,  1742,  1747,  1756,  1762,
    1772,  1782,  1793,  1795,  1798,  1800,  1803,  1810,  1811,  1813,
    1817,  1821,  1822,  1824,  1826,  1828,  1831,  1834,  1835,  1837,
    1839,  1841,  1844,  1847,  1849,  1851,  1853,  1855,  1857,  1859,
    1861,  1863,  1865,  1867,  1869,  1873,  1877,  1880,  1884,  1888,
    1891,  1893,  1895,  1897,  1899,  1901,  1903,  1905,  1910,  1914,
    1922,  1926,  1934,  1939,  1944,  1948,  1956,  1960,  1968,  1971,
    1973,  1976,  1980,  1982,  1984,  1986,  1988,  1990,  1994,  1998,
    2000,  2002,  2004,  2006,  2010,  2012,  2014,  2016,  2018,  2020,
    2022,  2024,  2026,  2028,  2030,  2032,  2034,  2038,  2042,  2047,
    2052,  2056,  2060,  2064,  2068,  2073,  2078,  2082,  2087,  2094,
    2099,  2106,  2111,  2115,  2120,  2127,  2134,  2139,  2146,  2153,
    2158,  2160,  2163,  2165,  2167,  2169,  2174,  2180,  2187,  2191,
    2195,  2199,  2203,  2209,  2217,  2225,  2231,  2237,  2243,  2251,
    2259,  2265,  2271,  2275,  2279,  2285,  2293,  2299,  2307,  2309,
    2314,  2318,  2324,  2326,  2329,  2333,  2337,  2339,  2343,  2346,
    2347,  2349,  2351,  2354,  2356,  2360,  2362,  2366,  2368,  2373,
    2375,  2378,  2382,  2383,  2385,  2386,  2388,  2393,  2396,  2400,
    2402,  2403,  2405,  2410,  2411,  2413,  2416,  2418,  2422,  2423,
    2425,  2428,  2431,  2433,  2434,  2436,  2437,  2439,  2441,  2443,
    2445,  2447,  2449,  2451,  2455,  2459,  2461,  2463,  2465,  2468,
    2472,  2474,  2476,  2478,  2480,  2482,  2484,  2486,  2488,  2491,
    2494,  2496,  2498,  2501,  2504,  2508,  2510,  2513,  2516,  2522,
    2525,  2527,  2529,  2530,  2533,  2535,  2539,  2544,  2545,  2548,
    2549,  2552,  2557,  2562,  2566,  2569,  2573,  2575,  2579,  2580,
    2582,  2584,  2587,  2590,  2593,  2596,  2598,  2601,  2604,  2607,
    2610,  2614,  2617,  2621,  2625,  2630,  2633,  2636,  2638,  2640,
    2644,  2647,  2651,  2654,  2658,  2661,  2665,  2669,  2673,  2679,
    2685,  2691,  2700,  2706,  2710,  2716,  2724,  2726,  2728,  2730,
    2734,  2738,  2742,  2744,  2746,  2748,  2750,  2752,  2754,  2756,
    2758,  2760,  2762,  2764,  2766,  2768,  2770,  2772,  2774,  2776,
    2778,  2780,  2782,  2784,  2786,  2788,  2790,  2792,  2794,  2796,
    2798,  2800,  2802,  2804,  2806,  2808,  2810,  2812,  2814,  2816,
    2818,  2820,  2822,  2824,  2826,  2828,  2830,  2832,  2834,  2836,
    2838,  2840,  2842,  2844,  2846,  2848,  2850,  2852,  2854,  2856,
    2858,  2860,  2862,  2864,  2866,  2868,  2870,  2872,  2874,  2876,
    2878,  2880,  2882,  2884,  2886,  2888,  2890,  2892,  2894,  2896,
    2898,  2900,  2902,  2904,  2906,  2908,  2910,  2912,  2914,  2916,
    2918,  2920,  2922,  2924,  2926,  2928,  2930,  2932,  2934,  2936,
    2938,  2940,  2942,  2944,  2946,  2948,  2950,  2952,  2954,  2956,
    2958,  2960,  2962,  2964,  2966,  2968,  2970,  2972,  2974,  2976,
    2978,  2980,  2982,  2984,  2986,  2988,  2990,  2992,  2994,  2996,
    2998,  3000,  3002,  3004,  3006,  3008,  3010,  3012,  3014,  3016,
    3018,  3020,  3022,  3024,  3026,  3028,  3030,  3032,  3034,  3036,
    3038,  3040,  3042,  3044,  3046,  3048,  3050,  3052,  3054,  3056,
    3058,  3060,  3062,  3064,  3066,  3068,  3070,  3072,  3074,  3076,
    3078,  3080,  3082,  3084,  3086,  3088,  3090,  3092,  3094,  3096,
    3098,  3100,  3102,  3104,  3106,  3108,  3110,  3112,  3114,  3116,
    3118,  3120,  3122,  3124,  3126,  3128,  3130,  3132,  3134,  3136,
    3138,  3140,  3142,  3144,  3146,  3148,  3150,  3152,  3154,  3156,
    3158,  3160,  3162,  3164,  3166,  3168,  3170,  3172,  3174,  3176,
    3178,  3180,  3182,  3184,  3186,  3188,  3190,  3192,  3194
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  jsoniq_parser::yyrline_[] =
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
    3946,  3950,  3961,  3967,  3977,  3983,  3993,  3997,  4001,  4064,
    4086,  4114,  4278,  4282,  4292,  4296,  4300,  4304,  4313,  4317,
    4321,  4325,  4333,  4339,  4349,  4357,  4361,  4365,  4369,  4373,
    4377,  4381,  4385,  4389,  4393,  4398,  4402,  4406,  4410,  4414,
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
     335
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int jsoniq_parser::yyeof_ = 0;
  const int jsoniq_parser::yylast_ = 15455;
  const int jsoniq_parser::yynnts_ = 318;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 543;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 336;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 590;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17097 "/home/markos/zorba/repo/hof-merge/build-opt/src/compiler/parser/jsoniq_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 7014 "/home/markos/zorba/repo/hof-merge/src/compiler/parser/jsoniq_parser.y"


namespace zorba {

/*
 *  The error member function registers the errors to the driver.
 */
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

