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
#line 88 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"


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
#line 69 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"


#include "jsoniq_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1051 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"

#include "compiler/parser/jsoniq_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 99 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 185 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 911 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 290 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 299 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 909 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 308 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 344: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 317 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 345: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 326 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 346: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 335 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 344 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 353 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 362 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 371 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 380 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 389 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 398 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 407 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 416 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 425 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 434 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 443 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 452 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 461 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 470 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 479 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 488 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 497 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 506 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 366: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 515 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 524 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 533 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 542 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 371: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 551 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 372: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 560 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 373: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 569 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 578 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 587 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 596 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 605 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 614 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 623 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 632 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 641 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 650 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 659 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 668 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 677 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 386: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 686 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 695 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 704 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 713 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 391: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 722 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 392: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 731 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 393: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 740 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 749 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 758 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 767 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 776 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 785 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 401: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 402: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 821 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 830 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 839 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 407: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 848 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 408: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 857 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 409: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 866 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 875 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 884 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 893 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 902 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 911 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 947 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 419: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 956 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 420: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 965 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 974 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 983 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 425: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 992 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 426: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1001 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 427: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1010 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 428: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1019 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 430: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1028 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 431: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1037 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 433: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1046 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 434: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1055 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 435: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1064 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 436: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1073 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1082 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 438: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1091 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1100 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1109 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1118 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1127 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1136 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1145 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1154 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1163 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1172 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1181 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1190 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1199 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1208 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1217 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1226 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1235 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1244 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1253 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1262 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1271 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 459: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1280 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 460: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1289 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1298 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1307 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1316 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 466: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1325 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 467: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1334 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 468: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1343 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 469: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1352 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 472: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1361 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 473: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1370 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 474: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1379 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 475: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1388 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 476: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1397 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 478: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1406 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 479: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1415 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 480: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1424 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1433 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1442 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1451 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 484: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1460 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1469 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1478 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1487 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1496 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1505 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1514 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1523 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1532 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1541 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1550 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1559 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1568 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1577 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1586 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1595 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1604 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1613 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1622 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 503: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1631 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1640 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 505: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1649 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1658 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1667 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1676 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 509: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1685 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1694 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1703 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 513: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1712 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 514: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1721 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 515: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1730 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 516: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1739 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1748 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1757 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1766 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 520: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1775 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 521: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1784 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 522: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1793 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 523: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1802 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 524: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1811 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 525: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1820 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1829 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1838 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 529: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1847 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 530: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1856 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 531: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1865 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 532: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1874 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 533: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1883 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 534: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1892 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 535: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1901 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 536: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1910 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1919 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 538: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1928 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 539: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1937 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 540: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1946 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1955 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1964 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 543: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1973 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1982 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1991 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2000 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2009 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2018 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2027 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2036 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2045 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2054 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2063 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2072 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2081 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2090 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2099 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2108 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2117 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2126 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2135 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 562: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2144 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 563: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2153 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 564: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2162 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 565: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2171 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2180 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2189 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 572: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2198 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 573: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2207 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 576: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2216 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 577: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2225 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 578: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2234 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2243 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2252 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 581: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2261 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 582: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2270 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 583: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2279 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 584: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2288 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 585: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2297 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 586: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2306 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 587: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2315 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2324 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 591: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2333 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 592: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2342 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 593: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2351 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2360 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2369 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 596: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2378 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 598: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2387 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 599: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2396 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 600: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2405 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 601: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2414 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 603: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2423 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 604: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2432 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 606: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2441 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 609: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2450 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 610: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2459 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 611: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2468 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 612: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2477 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 613: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2486 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 614: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2495 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 615: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2504 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 616: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2513 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 617: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2522 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 618: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2531 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 619: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2540 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 620: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2549 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 624: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2558 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 627: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2567 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 628: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2576 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 632: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2585 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 633: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2594 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 634: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2603 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 635: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2612 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 636: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2621 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 637: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2630 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 638: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2639 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 639: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2648 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 640: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2657 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 641: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2666 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 642: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2675 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 643: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2684 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 644: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2693 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 645: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2702 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 646: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2711 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 647: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2720 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 648: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2729 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 649: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2738 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 650: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2747 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 657: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2756 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 658: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2765 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 659: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2774 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
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
#line 133 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2871 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 1069 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1073 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1077 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1085 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1091 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1095 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1104 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1110 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1118 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1124 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1135 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1140 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1148 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1155 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1162 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1171 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1178 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1186 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1194 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1202 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1213 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1218 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1225 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1232 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1244 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1254 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1261 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1268 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1303 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1308 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1316 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1324 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1332 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1337 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1345 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1350 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1358 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1363 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1371 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1376 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1381 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1386 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1399 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1409 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1414 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1422 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1430 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1441 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1448 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1459 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1464 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1472 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1479 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1486 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1495 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1508 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1516 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1523 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1533 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1540 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1547 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1570 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1576 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1585 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1592 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1602 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1611 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1612 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1613 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1614 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1615 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1616 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1617 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1618 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1619 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1620 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1626 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1634 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1642 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1650 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1657 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1665 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1672 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1677 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1685 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1693 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1707 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1721 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1738 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1743 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1751 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1759 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1770 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1775 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1784 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1789 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1796 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1801 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1811 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1816 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1825 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1831 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1844 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1849 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1857 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1868 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1883 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1895 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1910 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1915 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1925 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1951 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1956 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1966 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1975 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1984 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1993 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2005 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 2009 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 2015 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2019 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2029 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2039 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2052 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 2058 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 2067 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2072 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2079 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2086 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2098 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2108 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2118 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2129 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2145 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2165 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2169 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2173 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2181 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2185 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2189 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2197 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2202 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2214 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 2221 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 2231 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2263 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2268 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 2276 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2293 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2301 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 2309 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2316 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2323 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2334 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2343 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2352 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2361 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2374 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 2382 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 2390 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2398 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2413 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2418 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2426 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2440 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2457 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2482 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2490 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2497 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2508 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2518 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2523 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2536 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2583 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2597 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2605 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2610 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2618 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2623 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2628 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2636 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2645 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2657 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2667 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2680 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2704 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2711 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2721 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2727 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2736 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2746 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      // this adds on shift-reduce conflict (probably with FTRange expression)
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2754 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2761 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2769 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2781 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2791 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2801 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2811 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2821 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2831 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2841 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2851 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2862 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2871 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2881 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2891 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2907 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2916 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2925 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2939 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2951 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2959 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2969 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2977 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2989 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2995 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 3008 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 3012 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 3020 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3024 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3033 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3037 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 3041 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3051 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3059 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3066 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3072 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3082 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3086 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3090 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3098 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 3106 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3114 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3126 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3134 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3140 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3150 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3156 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3166 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3170 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3180 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3186 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3192 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3198 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3207 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3216 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3225 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3238 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3242 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3250 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3256 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3266 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3274 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3283 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3296 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3303 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3315 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3319 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3331 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3338 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3344 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3353 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3360 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3366 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3377 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3384 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3390 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3399 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 3408 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3415 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3426 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3433 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3445 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3451 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3463 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3469 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3480 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3486 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3497 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3503 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3514 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3520 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3531 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3540 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3544 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3553 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3557 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3565 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3569 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 360:

/* Line 690 of lalr1.cc  */
#line 3579 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3586 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3595 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3604 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3609 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3618 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3627 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3636 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3649 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3653 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3665 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3669 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3676 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3680 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3687 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3691 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3700 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3704 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3708 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3716 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3720 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3726 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3732 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3738 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3748 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3752 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3756 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3764 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3768 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3774 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3784 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3788 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3798 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3802 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3812 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3816 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3826 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3830 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3840 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3844 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3853 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3857 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3865 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3869 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3873 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3877 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3887 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3891 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3895 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3902 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3907 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3915 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3919 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3927 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3943 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3947 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3951 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3959 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3963 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3967 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3971 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3982 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3988 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3998 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 4004 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4014 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4018 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4022 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4085 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4107 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 433:

/* Line 690 of lalr1.cc  */
#line 4135 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4299 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4303 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4313 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4317 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4321 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4325 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4334 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4338 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4342 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4346 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4350 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4355 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4359 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4363 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4367 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4376 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4382 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4392 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4400 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4404 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4408 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4412 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4416 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4420 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4424 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4428 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4432 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4436 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4441 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4445 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4449 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4453 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4461 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4465 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4469 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4473 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new NullLiteral(LOC((yyloc)));
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4481 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4488 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4495 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4505 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), true);
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4509 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), false);
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4517 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4525 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4529 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4537 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4545 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4553 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4607 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4611 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                            dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4621 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4627 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4637 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4641 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4649 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4653 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4657 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4665 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4673 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 492:

/* Line 690 of lalr1.cc  */
#line 4690 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4698 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 494:

/* Line 690 of lalr1.cc  */
#line 4717 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 495:

/* Line 690 of lalr1.cc  */
#line 4736 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 496:

/* Line 690 of lalr1.cc  */
#line 4758 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4764 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4775 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4781 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4792 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4807 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4812 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4821 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4825 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4832 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4838 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4844 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4851 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4862 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4866 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4873 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4879 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4885 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4892 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4903 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4907 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4915 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4919 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4927 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4949 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4953 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4957 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4961 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4969 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4974 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4982 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4987 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4995 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 5003 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 5008 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 5013 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 5018 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 5023 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 5028 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 5039 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 5047 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 5051 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 5068 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 5072 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 5080 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 5088 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 5096 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 5100 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 5108 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 5112 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 5120 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 5128 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 5132 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 5136 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 5171 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 5177 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 5183 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 5193 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 5197 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 5201 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 5205 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5209 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5213 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5217 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5224 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5230 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5240 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5248 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5256 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5260 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5264 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5268 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5272 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5276 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5280 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5284 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5288 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5292 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5300 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5308 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5312 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5316 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5324 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5331 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5339 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5347 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5351 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5355 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5363 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5367 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5373 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5379 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5383 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5393 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5401 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5405 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5411 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5420 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5429 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5435 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5441 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5451 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5468 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5475 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5490 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5526 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5530 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5538 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5546 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5558 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5562 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5570 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5578 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5582 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5593 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5610 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5616 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5622 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5632 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5636 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5648 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5652 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5658 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5662 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5668 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5674 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5681 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5691 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5696 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5704 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5710 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5720 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5742 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5751 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5757 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5770 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5784 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5791 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5797 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5807 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5816 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5824 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5830 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5848 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5856 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5860 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5867 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5872 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5880 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5884 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5891 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5895 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5902 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5906 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5913 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5917 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5949 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5953 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5961 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5969 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5977 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5981 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5988 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5992 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 6000 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 6011 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 6015 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 6023 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 6035 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 6041 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 6050 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 6054 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 6062 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 6066 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 6070 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 6077 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 6081 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 6088 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 6092 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 6100 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 6104 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 6108 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 6112 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 6116 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 6124 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 6132 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 6144 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 6156 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 6160 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 6164 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 6172 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 6178 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6188 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6192 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6196 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6200 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6204 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6208 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6212 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6216 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6224 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6228 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6232 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6236 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6244 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6250 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6260 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6270 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6274 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6282 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 716:

/* Line 690 of lalr1.cc  */
#line 6292 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 717:

/* Line 690 of lalr1.cc  */
#line 6303 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6310 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6314 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6321 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6325 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6332 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6337 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6346 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6355 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6359 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6366 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6370 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6378 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6387 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6394 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6404 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6408 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6415 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6421 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6430 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6434 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6441 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6446 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6458 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6466 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6478 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6486 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6490 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6498 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6502 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6506 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6514 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6522 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6526 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6530 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6534 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6542 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6550 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6562 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6566 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6574 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6588 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6592 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6599 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6604 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6612 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6617 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6626 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6634 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6641 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6647 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6654 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)) );
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6665 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6671 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 771:

/* Line 690 of lalr1.cc  */
#line 6681 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6688 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6695 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 774:

/* Line 690 of lalr1.cc  */
#line 6720 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 775:

/* Line 690 of lalr1.cc  */
#line 6748 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 776:

/* Line 690 of lalr1.cc  */
#line 6776 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6780 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6784 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6792 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6799 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6806 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6823 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 786:

/* Line 690 of lalr1.cc  */
#line 6836 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6837 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6838 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6839 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6840 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 6841 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6842 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6843 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6844 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6845 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6846 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6847 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6848 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6849 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6850 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6851 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6856 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6857 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6858 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6859 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6860 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6861 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6862 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6863 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6864 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6865 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6866 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6867 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6868 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6869 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6870 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6871 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6872 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6873 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6874 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6875 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6876 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6877 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6878 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6879 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6880 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6881 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6882 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6883 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6884 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6885 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6886 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6887 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6888 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6889 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6890 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6891 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6892 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6893 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6894 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6895 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6896 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6897 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6898 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6899 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6900 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6901 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6902 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6903 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6904 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6905 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6906 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6907 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6908 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6909 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6910 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6911 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6912 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6913 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6914 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6915 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6916 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6917 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6918 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6919 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6921 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6922 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6924 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6925 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6927 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6932 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6934 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6937 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6939 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6941 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6943 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6944 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6945 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6946 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6947 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6948 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6949 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6950 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6951 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6952 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6953 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6954 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6955 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6956 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6957 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6958 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6959 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6960 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6961 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6962 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6963 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6964 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6965 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6966 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6967 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6968 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6969 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6970 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6971 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6972 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6973 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6974 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6975 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6976 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6977 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6978 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6979 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6980 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6981 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6982 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6983 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6984 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6985 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6986 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6987 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6988 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6989 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6990 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6991 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6992 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6993 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6994 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6995 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6996 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6997 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6998 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6999 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 7000 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 7001 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 7002 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 7003 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 7004 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 7005 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 7006 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 7007 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 7008 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 7009 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 7010 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 7011 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 7012 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 7013 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 7014 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 7015 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 7016 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 7017 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 7018 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 7019 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 7020 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 7021 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 7022 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 7023 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 7024 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 7025 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 7026 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 7027 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 7028 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 7029 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 7030 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 7031 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 7032 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 7033 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 7034 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 7035 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 7036 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 7037 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 7038 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 7039 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 7040 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 7041 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 7042 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 7043 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 7044 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 7045 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 7046 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 7047 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 7048 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 7049 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 7050 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 7051 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 7052 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 7053 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 7054 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 7055 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 7056 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 7058 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 7059 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 7060 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 7065 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12046 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
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
  const short int jsoniq_parser::yypact_ninf_ = -1458;
  const short int
  jsoniq_parser::yypact_[] =
  {
      6668,  8197,  8197,  8197,  8197, -1458, -1458,   175,   213, -1458,
    1760,   294, -1458, -1458, -1458,    56, -1458, -1458, -1458,   332,
   -1458,   487,   597,   439,   516,   875, -1458,   -38, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458,   560, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458,   588, -1458,   591, -1458,   640,   693, -1458,
     406, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458,   594, -1458, -1458, -1458, -1458, -1458, -1458, -1458,   746,
   -1458, -1458, -1458, -1458, -1458, 16006, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458,   761, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458,  4535, 10027, 10332, 16006, -1458,
   -1458,   758, -1458, -1458, -1458, -1458,   793, -1458, -1458, -1458,
    6055, -1458,  6363, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458,   797, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458,   151,   595, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458,   142, -1458,   159, -1458,
      88,   -57, -1458, -1458, -1458, -1458, -1458, -1458,   781, -1458,
     769,   771,   708, -1458, -1458,   840,   877, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,   692,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   10637, 10942, -1458,   717, -1458, -1458, -1458, -1458,  6975,  8502,
    1041, -1458,  8807, -1458, -1458,   431,    83, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458,    91, -1458, -1458, -1458, -1458, -1458, -1458,   629, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458,  8197, -1458, -1458,
   -1458, -1458,   293, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458,   167, -1458,   870, -1458, -1458, -1458,   417, -1458,   674,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458,   900,   976, -1458,
     943,   819,   973,    20,   465,   818,   341, -1458,  1024,   874,
     975,   977, 12162, -1458,   884, -1458, -1458,   715, -1458, -1458,
   -1458, -1458,    49, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458,   935,   925, -1458, -1458,
   -1458, -1458, -1458,   898, -1458,  8197,   903,   904,   905,  8197,
     558,   558,  1057,   438,   647,   704, 16298, 16006,   495,  1044,
   16006,   939,   974,   788,  6055,   751,   846, 16006, 16006,   786,
     684,    42, -1458, -1458, -1458,  6055,  8197,  8197, 12467,    31,
     948, 12467,  1103,   112,    72, 16006,   986,   965,   999, -1458,
   12467, 16006,  8197, 12467, 12467, 16006,  8197,   955,   956, 12467,
   16006, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458,   970, -1458, 16006, -1458, -1458,   930,  7282,
     994,   319,   995,   935,   963,   967,   969, 16006,  4843, -1458,
     968,   158, -1458,   578, -1458,   100,  1086, 12467, 12467,   133,
   -1458, -1458, -1458,  1112, 12467,   914, -1458,  1101, 12467, 12467,
   13077, 12467, 12467,  5151, 12467, 13077, 12467,   896,   907, 16006,
     941,   947, 12467, 12467,  7587,   890, -1458,    54, -1458,    39,
   12467,  8502, -1458, -1458, -1458, -1458, -1458,  1760,   875,    93,
      94,  1140,  9112,  2956,  9417,  3282,   746, -1458, -1458,   328,
     746, -1458, 12467,  3912, -1458,  1025, -1458,   -38,   984,   972,
     983,  8197, 12467, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, 16006, -1458,   857,   858, 16006,  1036, 12772, 12772,
   12772, -1458, 12772, 12772, -1458, 12772, -1458, 12772, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, 12772, 12772,  1085, 12772, 12772,
   12772, 12772, 12772, 12772, 12772, 12772, 12772, 12772, 12772, 12772,
     923,  1064,  1065,  1066, -1458, -1458, -1458, 13077, 11247, -1458,
    5453, 12467, 11552,  1009, -1458,  1016, 11857, -1458, -1458, -1458,
   -1458,    -3, -1458,   208, -1458, -1458, -1458, -1458, -1458, -1458,
    1059,  1061,   439,  1142, -1458, -1458, 16298,   964,   626, 16006,
    1011,  1013,   964,  1057,  1050,  1048, -1458, -1458, -1458,   137,
     932,  1088,   881, 16006,  1042, 12467,  1067, 16006, 16006, -1458,
    1054,  1006,  1007,   191, 16006,  1098,   229, -1458,  8197, -1458,
     107, -1458,  6055,  1099,  1150,  6055,  1057,  1104,    98, 16006,
   12467,   -38,   217,   134, -1458,   379,  1017,   118,   138,  1049,
   -1458,  1020,  8197,  8197,   321,   709, 12467,   255, -1458, -1458,
   12467,  5151, -1458, 12467, 12467, 12467, 12467, -1458, 12467, -1458,
   12467, -1458, 16006,  1086, -1458,   241,   334,   359, -1458, -1458,
   -1458,   361, -1458,    27, -1458, -1458,    49,   285,   429,    23,
     -13,  1113,   569,   957,   980,   979,    -5, -1458,  1068, -1458,
   -1458,  1019,   161,  7282,   362,  4227,   890, -1458, -1458, -1458,
     982, -1458,   431,   610,  1179,   705, -1458, -1458,    96, -1458,
   -1458, -1458,    99, -1458,    51, -1458, -1458, -1458, -1458, -1458,
    3597, -1458, -1458, -1458, 16006,  1045, 12467,  1102, -1458, -1458,
   -1458,  1109, -1458,    28, -1458, -1458,  1109, 16006,     7,   976,
   -1458, -1458, -1458, -1458, -1458, 12772, -1458, -1458, -1458,    59,
   -1458,   465,   465,   652,   818,   818,   818,   818,   341,   341,
   -1458, -1458, 14546, 14546, 16006, 16006, -1458, -1458,   387, -1458,
   -1458, -1458, -1458, -1458,   168, -1458, -1458,   274, -1458, -1458,
   -1458,   407,   558, -1458, -1458,   651,   676,   582, -1458,   439,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
     964, -1458,  1089, 14838,  1080, 12467, -1458, -1458, -1458,  1131,
    1057,  1057,   964, -1458,    53,  1057,   756, 16006,   752,   755,
    1200, -1458, -1458,   940,   547, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458,   137,    89,  1000,   729,
   12467, -1458, 16006,  1137,   933,  1057, -1458, -1458,  1079,  1131,
   14546,  1118,  1143,  1055,  1040,  1110,  1057,  1083,  1114,  1148,
    1057, 14546, 12467,   -14, -1458, -1458, -1458,  1092,  1130, 12467,
   12467,  1106, -1458,  1149,  1154,  8197, -1458,  1071,  1073,  1097,
   12467,  1119,  1070, 12467, -1458,  1141,  1144, -1458,   190,   195,
     221,  1229, -1458,   440, -1458,   605,  1111, -1458, -1458,  1238,
   -1458,   760, 12467, 12467, 12467,   798, 12467, 12467, 12467, 12467,
   12467, 12467, 12467, 12467, 12467, 13077,  1151, 12467, 12467, -1458,
    9722,   348,  1022, -1458, -1458, -1458, -1458, -1458, -1458,    -6,
   -1458, -1458, 12467,   106,   116,    51,  9417,  3282,  9417,  1188,
   -1458, -1458, 12467,   843,  1161, -1458, 16006,  1164, -1458, 15714,
    1152,  1158, 12467,   -18,  1133,    30,   551,  1021, -1458, -1458,
     844,     7, -1458, 12467,    59,   805,   730, -1458,   993,   658,
    1029,  1030, -1458, -1458,   846, -1458,  1012,   716,  1127,  1136,
    1138,  1139,  1145,  1146,  1153,  1155,  1156,  1159,  1160, 14838,
    1162,  1163,  1165,  1166, -1458,  1167, -1458,   728, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458,  1170, -1458, -1458, -1458, -1458, 12467, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458,   820, -1458,  1271,   861,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,  1015,
   -1458, -1458,  1277, -1458, -1458, -1458, -1458, -1458,   609,  1279,
   -1458,   778, -1458, -1458, -1458,  1127,  1136,  1138,  1145,  1146,
    1153,  1155,  1156,  1159,  1163,  1165,  1166, -1458,   728,   728,
   13077,  1027,  1001, -1458,  1131,    89,  1094,  1135,  8197, -1458,
   -1458, -1458, 14546, -1458,  8197,  1057,  1219, -1458, -1458, -1458,
    1057,  1219, -1458, -1458, 12467,  1186,  8197, 16006, -1458, -1458,
   12467, 12467,   871, -1458,    36,   872, -1458, 13670,   886, -1458,
     887, -1458,  1147, -1458, -1458,  8197, -1458, 12467, -1458, -1458,
   12467, 12467,  1132,  1149,  1232, -1458,  1197, -1458,   649, -1458,
   -1458,  1328, -1458, -1458,  8197, 16006, -1458,   682, -1458, -1458,
   -1458,  8197,  1168,  1100,  1105, -1458, -1458, -1458,  1107,  1108,
   -1458, -1458, -1458,  1241, -1458, -1458, -1458, -1458,  1115,   277,
   16006,  1171, -1458,  1178,  1182,  1183,  1187, -1458,   870,   633,
    4227,  1022, -1458,  7892,  4227, -1458, -1458,  1179,   494, -1458,
   -1458, -1458,  1161, -1458,  1057, -1458,   926, -1458,   286,  1236,
   -1458, 12467,   615,  1102, 16006, -1458,   522, 16006, -1458, 12467,
    1198, 12467,  1221, 12467,    25,  1199, 12467,  1202, -1458,  1233,
    1243, 12467, 16006,   889,  1282, -1458, -1458, -1458,   413,  1169,
   -1458,    59,  1117, -1458, -1458,   243, -1458,   354,    78,  1120,
      59,   354, 12772, -1458,   437, -1458, -1458, -1458, -1458, -1458,
   -1458,    59,  1207,  1077,   932,    78, -1458, -1458,  1074,  1287,
   -1458, -1458, -1458,  1180,    57, 15130, 13378,  1181,  5754, 16006,
   16006,  1185, 15422,  1189,  1190,  1191,  1192,  1193,  1194,  1195,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458,  1338,   479,  1346,   479,  1116,  1268, -1458, -1458,
    1213, 16006,  1124, -1458, -1458, 13077, -1458,  1201, -1458,  1260,
    1261,  1292,  1057,  1219, -1458, 12467,  1205, -1458, -1458, -1458,
    1208, -1458,   264, 12467,  8197,  1209,   475, -1458, 16006,   380,
   -1458, 13962,   270, -1458, 14254,  1210, -1458, -1458,  1214, -1458,
   -1458, -1458, 12467,   894,  1229, 16006,   807, -1458,  1215,  1229,
   16006, -1458,  1216, -1458, 12467, 12467, 12467, 12467,  1072, 12467,
   12467, -1458, 12467, 12467, 12467, 12467,  9722,   232, -1458, -1458,
   -1458, -1458, -1458,  1236, -1458, -1458, -1458,  1057, 12467, -1458,
    1251, -1458, -1458, 12467,  1254, -1458, -1458, 12467, -1458,   553,
   -1458, 12467,  1255, 12467, -1458, 12467, 16006, 16006, -1458,   767,
   -1458, 12467, -1458, -1458, -1458,  1220, 12772, -1458, -1458, -1458,
   -1458, -1458,   447, 12772, 12772,   655, -1458,  1029, -1458,   459,
   -1458,  1030,    59,  1250, -1458, -1458,  1122, -1458, -1458, -1458,
   -1458, -1458, -1458,  1222,  1223, -1458,   420,   489,  1312,  1224,
   -1458,   492, -1458,  1225, -1458,  1227,  1230,  1231, -1458, -1458,
     497,   498, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
      74,    74, -1458,   479, -1458, -1458,   507, -1458,  1379,   -17,
    1323,  1234, 13077,   -40,  1134,  1252, -1458,  9722, 12467,  1057,
   -1458, -1458, -1458, 12467, 12467, -1458, -1458, -1458,  9722,  9722,
    1314,  8197, 14546, 16006,   710, 16006, 12467, 16006,   714,  9722,
   -1458,   309,    52,  1229, 16006, -1458,  1226,  1229, -1458, -1458,
   -1458, -1458, -1458, 12467, -1458, -1458, -1458,   227,   228,   235,
   12467, -1458, -1458, -1458,  1319, 12467, -1458, 12467, -1458, 12467,
    1273, -1458, 12467, -1458, -1458, -1458,  1373, -1458, -1458, -1458,
     818, 12772, 12772,   652,   654, -1458, -1458, -1458, -1458, -1458,
   -1458, 12467, -1458, -1458, -1458, 16006, -1458, 16006, -1458, 14546,
   -1458, 14546,  1333, -1458, -1458, -1458, -1458, 16006, -1458, 16006,
   -1458, -1458, -1458, -1458,  1400, -1458, -1458, -1458,  1172,  1322,
   -1458, -1458,  1324, -1458,   885, 16006,  1315,  1204, 16006, 13077,
   -1458, -1458,  1219, -1458, -1458, 14546, -1458, -1458, -1458,  1336,
   12467,  1249, -1458,  1342,  9722, -1458, 16006,   468,   748, -1458,
    1240,  1229, -1458,  1247, -1458,  1248,  1149,  1154,   454, -1458,
    1319, -1458, -1458, 12467, -1458,  1320,   652,   652, 12772,   482,
    1258,  1262,  1303,  1263,  1264, -1458, -1458, 14546,  1265,  1266,
   -1458, -1458,  1323, 13077, -1458,  1236,  1157, 16006,  1330,  1235,
    1324,   726, 14546,  8197, 14546,  1269, -1458, -1458,  1361,   664,
   -1458, -1458, -1458, -1458,  1274,   753, -1458, -1458, -1458,  1267,
   -1458,  9722,   901, -1458, -1458, -1458, 16006,   652, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   12467,  1173, 16006,  1340,  8197,   731, -1458, -1458,   745, 12467,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458,  1343, -1458, -1458,
    1174,  1175, 16006, -1458, -1458, 12467,  9722, 16006,  1176, 12467,
    1177,  1280, 13077, -1458, 13077,  9722, -1458,  1270,  1184, 16006,
    1239,  1350, 16006,  1196, 13077, -1458
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       165,   168,   168,   168,     0,   803,  1007,   120,   122,   606,
     895,   904,   844,   808,   806,   787,   896,   899,   851,   812,
     788,   790,   257,   905,   792,   902,   873,   853,   828,   789,
     848,   849,   900,   897,   847,   794,   903,   795,   796,   944,
     956,   943,   845,   864,   858,   797,   846,   799,   798,   945,
     882,   883,   850,   825,   966,   967,   968,   969,   970,   971,
     972,   973,   974,   975,   976,   990,   997,   872,   868,   859,
     839,   786,   867,   875,   884,   991,   863,   470,   840,   841,
     898,   992,   998,   860,   877,     0,   478,   472,   870,   805,
     861,   862,   891,   865,   881,   890,   996,   999,   811,   852,
     893,   471,   880,   886,   791,     0,     0,     0,     0,   403,
     878,   889,   894,   892,   871,   857,   946,   855,   856,   993,
       0,   402,     0,   994,  1000,   887,   842,   866,   995,   888,
     869,   876,   885,   879,   947,   833,   838,   837,   836,   835,
     834,   800,   854,     0,   804,   901,   826,   469,   473,   474,
     935,   934,   936,   810,   809,   829,   941,   793,   933,   938,
     939,   930,   832,   874,   932,   942,   940,   931,   830,   937,
     951,   952,   949,   950,   948,   801,   953,   954,   955,   921,
     920,   907,   824,   817,   914,   910,   827,   823,   922,   258,
     813,   814,   807,   816,   919,   918,   915,   911,   928,   929,
     927,   917,   913,   906,   815,   926,   925,   819,   821,   820,
     912,   916,   908,   822,   909,   818,   924,   977,   978,   979,
     980,   981,   982,   958,   959,   957,   963,   964,   965,   960,
     961,   962,   831,   983,   984,   985,   986,   987,   988,   989,
       0,     0,  1001,  1002,  1003,  1005,  1004,  1006,   165,   165,
       0,     2,   165,     9,    11,    23,     0,    28,    31,    36,
      37,    38,    39,    40,    41,    42,    32,    58,    59,    33,
      34,     0,    76,    79,    80,    35,    81,    82,     0,   118,
      83,    84,    85,    86,    18,   162,   163,   164,   171,   174,
     461,   175,     0,   176,   177,   178,   179,   180,   181,   182,
     185,     0,   211,   219,   214,   246,   252,     0,   244,     0,
     245,   221,   215,   184,   216,   183,   217,   220,   354,   356,
     358,   368,   370,   374,   376,   379,   384,   387,   390,   392,
     394,   396,     0,   400,   407,   406,   408,     0,   426,   409,
     431,   432,   433,   440,   452,   466,   468,   453,   454,   455,
     458,   459,   456,   457,   485,   487,   488,   489,   486,   534,
     535,   536,   537,   538,   539,   540,   467,   460,   607,   608,
      43,   222,   223,   225,   224,   226,   218,   463,   464,   465,
     462,   228,   231,   227,   229,   230,     0,   785,   802,   895,
     904,   902,   804,     0,   166,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   276,   277,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   192,   787,   812,   790,   843,   905,   792,   853,   794,
     864,   797,   799,   798,   882,   786,   841,   865,   889,   946,
     947,   941,   933,   939,   930,   830,   951,   952,   949,   801,
     953,   923,  1002,   475,   785,     0,   783,   187,     0,     0,
     211,     0,     0,   784,   792,   799,   798,     0,   168,   758,
     953,     0,   219,     0,   476,     0,   501,     0,     0,     0,
     784,   429,   430,     0,     0,     0,   530,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   760,     0,   762,     0,
       0,   165,     3,     4,     1,    10,    12,     0,     0,     0,
       0,     6,   165,     0,   165,     0,     0,   119,   172,     0,
       0,   190,     0,     0,   199,     0,   257,     0,     0,     0,
       0,     0,     0,   258,   204,   232,   251,   247,   253,   248,
     250,   249,     0,   256,     0,     0,     0,     0,     0,     0,
       0,   419,     0,     0,   417,     0,   363,     0,   418,   411,
     416,   415,   414,   413,   412,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   405,   404,   401,     0,     0,   427,
       0,     0,     0,   441,   449,     0,     0,   542,   544,   548,
     550,     0,   124,     0,   782,    47,    44,    45,    48,    49,
       0,     0,     0,     0,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   617,   618,   619,     0,
     103,   142,     0,     0,   112,     0,     0,     0,     0,   127,
       0,     0,     0,     0,     0,   134,     0,   138,   168,   610,
       0,    60,     0,    69,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,   325,     0,     0,     0,     0,     0,
     604,     0,     0,     0,     0,   194,     0,     0,   188,   186,
       0,     0,   764,     0,     0,     0,     0,   475,     0,   759,
       0,   477,   502,   501,   498,     0,     0,     0,   532,   531,
     428,     0,   529,     0,   630,   631,   773,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   636,     0,   202,
     203,     0,     0,     0,     0,     0,   207,   208,   761,   763,
       0,     5,    24,     0,    25,     0,     7,    29,     0,    15,
       8,    30,     0,    19,   895,    77,    16,    78,    20,   193,
       0,   191,   212,   213,     0,     0,     0,     0,   205,   233,
     294,   255,   259,     0,   234,   235,   254,     0,     0,   355,
     357,   361,   367,   366,   365,     0,   362,   359,   360,     0,
     371,   378,   377,   375,   381,   382,   383,   380,   385,   386,
     389,   388,     0,     0,     0,     0,   410,   424,     0,   448,
     446,   445,   447,   444,     0,   442,   483,     0,   450,   609,
     481,     0,     0,   121,   123,     0,     0,     0,   102,     0,
      92,    94,    95,    96,    97,    99,   100,   101,    93,    98,
      88,    89,     0,     0,   108,     0,   104,   106,   107,   114,
       0,     0,    87,    46,     0,     0,     0,     0,     0,     0,
       0,   708,   713,     0,     0,   709,   743,   696,   698,   699,
     700,   702,   704,   703,   701,   705,     0,     0,     0,     0,
       0,   111,     0,   144,     0,     0,   547,   541,     0,   140,
       0,     0,   135,     0,     0,     0,     0,     0,     0,    62,
       0,     0,     0,     0,   275,   281,   278,     0,     0,     0,
       0,     0,   546,     0,     0,     0,   420,     0,     0,     0,
       0,   195,     0,     0,   766,     0,     0,   765,     0,     0,
       0,   501,   499,     0,   490,     0,     0,   479,   480,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
       0,     0,     0,   437,   438,   439,   436,   644,   435,     0,
     434,   209,     0,     0,     0,     0,   165,     0,   165,     0,
     173,   243,     0,   309,   305,   307,     0,   295,   296,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
       0,   242,   364,     0,     0,     0,     0,   674,   372,   647,
     651,   653,   655,   657,   660,   667,   668,   676,   787,   788,
     790,   905,   789,   794,   795,   796,   797,   786,   791,     0,
     800,   793,  1005,  1004,   779,  1006,   391,   553,   559,   560,
     579,   570,   578,   577,   576,   575,   572,   574,   571,   573,
     563,   611,   612,   564,   565,   776,   777,   778,   568,   393,
     395,   398,   569,   397,   425,   451,     0,   443,   482,   125,
      56,    57,    54,    55,   131,   130,     0,    90,     0,     0,
     109,   110,   115,    74,    75,    52,    53,    73,   714,     0,
     717,   744,     0,   707,   706,   711,   710,   742,     0,     0,
     719,     0,   715,   718,   697,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   146,   148,
       0,     0,     0,   113,   116,     0,     0,     0,   168,   141,
     136,   139,     0,   189,     0,     0,    71,    65,    68,    67,
       0,    63,   552,   279,     0,     0,   168,     0,   323,   327,
       0,     0,     0,   330,     0,     0,   336,     0,     0,   343,
       0,   347,     0,   422,   421,   168,   196,     0,   198,   324,
       0,     0,     0,     0,     0,   502,     0,   492,     0,   525,
     522,     0,   526,   527,     0,     0,   521,     0,   496,   524,
     523,     0,     0,     0,     0,   623,   624,   620,     0,     0,
     628,   629,   625,   769,   770,   634,   774,   632,     0,     0,
       0,     0,   638,   792,   799,   798,   953,   201,     0,     0,
       0,   639,   640,     0,     0,   210,   772,    26,     0,    17,
      21,    22,   306,   318,     0,   319,     0,   310,   311,   312,
     313,     0,   298,     0,     0,   261,     0,     0,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,     0,
       0,     0,     0,   288,     0,   285,   290,   241,     0,     0,
     658,   671,     0,   369,   373,     0,   690,     0,     0,     0,
       0,     0,     0,   646,   648,   649,   685,   686,   687,   689,
     688,     0,     0,   662,   661,     0,   665,   669,   683,   681,
     680,   673,   677,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     556,   558,   557,   554,   399,   484,   133,   132,    91,   105,
     731,   712,     0,   736,     0,   736,   725,   720,   147,   149,
       0,     0,     0,   117,   145,     0,    27,     0,   137,     0,
       0,    70,     0,    64,   280,     0,     0,   326,   328,   333,
       0,   331,     0,     0,     0,     0,     0,   337,     0,     0,
     351,     0,     0,   344,     0,     0,   348,   423,     0,   197,
     767,   768,     0,     0,   501,     0,     0,   533,     0,   501,
       0,   497,     0,    14,     0,     0,     0,     0,     0,     0,
       0,   637,     0,     0,     0,     0,     0,     0,   641,   645,
     322,   320,   321,   314,   315,   316,   308,     0,     0,   303,
       0,   297,   260,     0,     0,   274,   266,     0,   270,     0,
     264,     0,     0,     0,   283,     0,     0,     0,   240,   286,
     289,     0,   675,   666,   672,     0,     0,   745,   746,   756,
     755,   754,     0,     0,     0,     0,   747,   652,   753,     0,
     650,   654,     0,     0,   659,   663,     0,   684,   679,   682,
     678,   586,   581,     0,     0,   596,     0,     0,     0,     0,
     566,     0,   584,     0,   587,     0,     0,     0,   585,   590,
       0,     0,   561,   616,   555,   580,   780,   781,   562,   732,
       0,     0,   730,   737,   738,   734,     0,   729,     0,   727,
       0,     0,     0,     0,     0,     0,   543,     0,     0,     0,
      66,   282,   549,     0,     0,   334,   338,   332,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     545,     0,     0,   501,     0,   528,     0,   501,   551,   621,
     622,   626,   627,     0,   633,   775,   635,     0,     0,     0,
       0,   642,   317,   304,   299,     0,   263,     0,   272,     0,
       0,   268,     0,   271,   284,   292,   293,   287,   239,   670,
     757,     0,     0,   749,     0,   695,   694,   693,   692,   691,
     656,     0,   748,   582,   583,     0,   600,     0,   597,     0,
     613,     0,     0,   589,   588,   595,   603,     0,   593,     0,
     591,   741,   740,   739,     0,   733,   726,   724,     0,   721,
     722,   716,   150,   152,   154,     0,     0,     0,     0,     0,
     206,   353,    72,   329,   335,     0,   349,   345,   352,     0,
       0,     0,   339,     0,     0,   341,     0,   511,   505,   500,
       0,   501,   491,     0,   771,     0,     0,     0,     0,   302,
     300,   267,   265,     0,   273,     0,   751,   750,     0,     0,
       0,     0,   604,     0,     0,   614,   567,     0,     0,     0,
     735,   728,     0,     0,   156,   155,     0,     0,     0,     0,
     151,     0,     0,     0,     0,     0,   519,   513,     0,   512,
     514,   520,   517,   507,     0,   506,   508,   518,   493,     0,
     494,     0,     0,   643,   301,   269,     0,   752,   664,   601,
     602,   605,   598,   599,   615,   594,   592,   723,   153,   157,
       0,     0,     0,     0,     0,     0,   342,   340,     0,     0,
     504,   515,   516,   503,   509,   510,   495,     0,   291,   158,
       0,     0,     0,   350,   346,     0,     0,     0,     0,     0,
       0,     0,     0,   160,     0,     0,   159,     0,     0,     0,
       0,     0,     0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1458, -1458,  -203,  -187, -1458,  1228,  1237, -1458,  1218,  -478,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
    -901, -1458, -1458, -1458, -1458,  -221,  -516, -1458,   800,  -667,
   -1458, -1458, -1458, -1458, -1458,   365,   601, -1458, -1458,     9,
    -158,  1076, -1458,  1058, -1458, -1458,  -575, -1458,   557, -1458,
     326, -1458,  -175,  -227, -1458,  -441, -1458,    13,    40,    84,
    -259,  -166, -1458,  -791, -1458, -1458,   351, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458,   724,    10,  1203,
       0, -1458, -1458, -1458, -1458,   460, -1458, -1458,  -295, -1458,
       5, -1458, -1458,   906,  -965,  -770,  -752, -1458, -1458,   792,
   -1458, -1458,    26,   201, -1458, -1458, -1458,   223, -1457, -1458,
     485,   231, -1458, -1458,   230, -1220, -1458,  1014,   323, -1458,
   -1458,   322,  -917, -1458, -1458,   318, -1458, -1458, -1172, -1157,
   -1458,   316, -1344, -1458, -1458,   920,   921, -1458,  -393,   909,
   -1458, -1458,  -593,   449,  -590,   444,   445, -1458, -1458, -1458,
     677, -1458, -1458,  1206, -1458, -1458, -1458, -1458, -1458,  -721,
    -307,  -614, -1458, -1458,   257, -1458,  -473, -1458,   876, -1458,
    -380, -1458, -1458,   891,   892, -1458, -1458, -1458, -1458,   879,
   -1458,  -915, -1458,   311, -1458,   787,  -716, -1458, -1458, -1458,
   -1458, -1458,  -212,  -205, -1134,  -867, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458,  -678,  -787,   -83,
    -758, -1458, -1458, -1458,  -844, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458,   192,   194,  -645,   -98,  -595, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,
   -1458, -1458,   290, -1458, -1458,   280, -1458,   282,  -976, -1458,
   -1458, -1458,   224,   212,    43,   502, -1458, -1458, -1458, -1458,
   -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458, -1458,   225,
   -1458, -1458, -1458,    55,   496,   635, -1458, -1458, -1458, -1458,
   -1458,   411, -1458, -1458, -1447, -1458, -1458, -1458,  -463, -1458,
     178, -1458,    12, -1458, -1458, -1458, -1458, -1249, -1458,   237,
   -1458, -1458, -1458, -1458, -1458,  1023, -1458, -1458, -1458, -1458,
   -1458,  -835, -1458, -1458, -1458,  -311,  -109,   -49,   442, -1458
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   250,   563,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
    1166,   696,   268,   269,   270,   271,   272,   273,   870,   871,
     872,   274,   275,   276,   876,   877,   878,   277,   420,   278,
     279,   641,   280,   422,   423,   424,   430,   686,   687,   281,
    1147,   282,  1652,  1653,   283,   284,   285,   488,   286,   287,
     288,   289,   290,   689,   291,   292,   451,   293,   294,   295,
     296,   297,   298,   574,   299,   300,   766,   767,   301,   302,
     502,   304,   575,   587,  1030,  1031,   305,   576,   306,   578,
     503,   308,   309,   801,   802,  1293,   437,   310,   438,   439,
     808,  1294,  1295,  1296,   579,   580,  1017,  1018,  1449,   581,
    1014,  1015,  1267,  1268,  1269,  1270,   311,   703,   704,   312,
    1182,  1183,  1392,   313,  1185,  1186,   314,   315,  1188,  1189,
    1190,  1191,  1399,   316,   317,   318,   319,   815,   320,   321,
    1303,   322,   323,   324,   325,   326,   327,   328,   329,   330,
    1090,   331,   332,   333,   334,   605,   606,   335,   336,   337,
     338,   339,   340,   341,   997,   998,   342,   633,   634,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   847,
     353,   354,   355,  1217,   733,   734,   735,  1679,  1734,  1735,
    1728,  1729,  1736,  1730,  1218,  1219,   356,   357,  1220,   358,
     359,   360,   361,   362,   363,   364,   365,   933,  1400,  1353,
    1067,  1511,  1068,  1091,  1069,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,   709,  1701,   366,   367,   368,
     369,  1080,  1081,  1082,  1083,   370,   371,   372,   373,   374,
     375,   756,   757,   376,  1251,  1252,  1591,   999,  1038,  1313,
    1314,  1039,  1040,  1041,  1042,  1043,  1323,  1494,  1495,  1044,
    1326,  1045,  1475,  1046,  1047,  1331,  1332,  1500,  1498,  1315,
    1316,  1317,  1318,  1618,   670,   897,   898,   899,   900,   901,
     902,  1132,  1541,  1649,  1133,  1539,  1647,   903,  1365,  1536,
    1532,  1533,  1534,   904,   905,  1319,  1327,  1485,  1320,  1481,
    1304,   377,   378,   379,   380,   491,   381,   382,   383,   384,
     385,  1084,  1085,  1086,  1087,  1167,   492,   386,   387,   388
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -924;
  const short int
  jsoniq_parser::yytable_[] =
  {
       303,   303,   303,   303,   303,   307,   307,   307,   307,   307,
     535,   509,   577,   836,   393,   396,   397,   963,   823,   421,
     642,   642,   824,   825,   826,   827,  1184,   941,   558,  1171,
     629,  1403,  1413,  1023,   550,   842,   483,   951,   785,   787,
     551,   394,   394,   394,   398,  1066,  1089,   746,  1444,  1445,
    1216,  1024,   752,   553,  1275,   551,   493,  1564,  1299,   506,
    1568,   542,   543,  1148,  1027,  1020,  1105,  1282,   555,     7,
       8,   510,  1149,   513,   777,   781,  1496,   857,     7,     8,
    1655,  1482,   435,  1421,   551,   395,   395,   395,   399,     9,
     406,   645,   551,  1650,   551,   551,   721,   551,  1036,   406,
     551,   551,   644,  1137,   986,   303,   852,   551,   551,   407,
     307,   779,   783,   786,   788,  1109,   501,   505,   409,   551,
     557,  1141,   693,   697,   931,  1025,  1021,   409,  1021,  1135,
    1174,  1279,   410,  1160,  1136,  1137,   558,  1689,  1393,   551,
     558,   738,   644,  1138,  1172,   394,   720,  1677,   562,  1253,
    1139,   684,  1140,  1141,   402,   403,   676,   404,   405,   551,
     969,  1142,   551,   562,   411,   412,  1009,  -169,   551,   551,
     630,    77,  1362,   526,  1461,   408,  1482,  1022,   527,  1283,
     609,  1175,   515,  1115,  1116,    87,   853,   694,  1143,   489,
    1656,   551,   551,   886,   931,   887,   551,   811,   610,   812,
     813,  1112,   814,  1107,   816,   631,  1254,   632,   577,   562,
     101,   426,   817,   818,  1033,  1107,   562,  1034,   551,   970,
     685,   611,   551,  1592,  1394,   980,  1028,   562,   551,   551,
     558,  1258,  1364,  1744,   695,   987,   551,  1678,   122,   888,
     436,  1159,   932,   938,  1483,  1206,  1502,   562,   303,   303,
     537,   539,   303,   307,   307,  1284,  1403,   307,   785,   787,
     436,   979,   528,   557,   436,  1757,  1029,   562,  1396,  1383,
     562,  1280,  1657,  1285,   692,   552,   562,   562,   414,   147,
     148,   149,  1421,   554,  1106,   772,   774,   303,  1006,   731,
    1648,  1008,   307,  1216,   777,   781,   924,   559,  1257,   562,
     562,  1344,  1216,   436,   562,   665,   436,   943,   436,  1452,
     739,  1148,   798,  1036,  1036,  1357,   680,   852,   524,  1144,
    1149,  1721,   551,  1035,   939,  1474,   562,   944,  -170,   551,
     562,   778,   782,   400,   677,   551,   562,   562,   921,  1483,
    1484,   415,   678,   417,   562,   729,   773,   775,  1287,   551,
     990,   418,   883,  -169,   771,  1095,   790,   769,   653,   419,
     551,   657,   551,   551,   938,   510,  1393,   516,   671,   672,
     768,   401,   518,   964,   519,  1378,   510,   918,  1765,  1202,
    1768,   971,   416,  1096,  1203,   929,   698,  1590,   551,   521,
    1565,   522,   705,   889,  1264,   303,   710,   854,   630,   303,
     307,   715,   560,   937,   307,   559,   890,   525,   891,   559,
    1204,  1145,  1146,  1064,   551,  1266,  1685,  1686,   922,   892,
     893,   894,  1032,   895,  1687,   896,   303,   303,   721,  1676,
     562,   307,   307,   631,  1714,   632,   705,   562,   683,  1037,
     965,   690,   303,   562,  1254,   953,   303,   307,   727,   493,
     702,   307,  1554,   707,   708,   551,   425,   562,  1566,   714,
     565,   520,  1477,  1097,   566,   547,   681,   682,   562,   567,
     562,   562,  1099,  1726,   493,   931,  1373,  1209,   523,   618,
     758,   548,   706,   551,   445,   561,   711,   427,   568,   303,
     785,   787,   785,   619,   307,  1759,   562,  1566,   303,   559,
    1611,  1216,  1478,   307,   558,   722,  1454,   949,   972,   973,
     399,   399,  1239,  1358,  -170,  1742,  1096,   736,   737,  1430,
     966,   843,   562,   974,   741,   975,   399,   484,   940,  1625,
     399,  1010,  1462,   803,   303,  1305,  1370,   803,   394,   307,
     660,   303,   661,   762,   764,   967,   307,   968,   992,  1510,
     484,  1003,   303,   303,   303,   303,   421,   307,   307,   307,
     307,   446,   484,   562,   484,  1259,  1260,  1261,  1561,  1113,
    1114,   303,  1207,  1094,  1117,  1007,   307,  1393,  1612,   775,
    1036,   510,   395,   925,   612,  1403,   928,   569,     9,  1036,
     570,   562,  1562,  1212,  1450,  1213,  1098,   429,  1627,  1472,
    1036,  1631,   663,  1727,  1157,   571,  1637,  1639,  1306,  1626,
     879,   780,   956,   613,  1209,  1210,  1644,  1530,   763,   609,
    1021,   565,   646,  1214,   909,   566,   614,  1479,   913,   914,
     567,   572,   447,   448,  1480,   919,   647,   610,   838,  1208,
    1743,   844,   428,   510,  1004,  1129,   510,   931,  1662,   568,
     934,  1021,   976,   977,  1037,  1037,     7,     8,  1209,  1210,
     548,   615,  1130,  1559,   664,   982,   654,   978,  1748,  1726,
      77,  1453,   493,  1209,   431,   582,   565,   583,  1628,   573,
     566,  1632,  1531,   961,    87,   567,  1638,  1640,   303,  1600,
     630,  1209,  1210,   307,  1307,  1308,  1645,  1309,  1572,   655,
    1286,   923,  1599,  1576,   568,  1131,   780,  1362,   441,   101,
    1211,   931,   303,   303,  1311,   440,  1000,   307,   307,  1489,
    -843,  1104,   873,  1447,  1363,   631,  1312,   632,   394,   629,
    1212,  1247,  1213,  1615,   958,   959,   960,   688,   764,  1005,
    1616,   785,   584,   556,  -843,  1011,   442,   585,   569,   449,
    1617,   570,   947,   948,  1211,  -843,  1305,  1209,  1026,  1448,
    1214,  1545,  1209,   303,   108,   874,   730,  1364,   307,  1396,
     875,  1036,   395,   991,  1212,  1668,  1213,  1732,   147,   148,
     149,   120,  1732,  1088,  1088,  1092,  1092,  1211,   790,  1212,
     303,  1213,   572,   421,   586,   307,   399,   399,   443,  1771,
     775,  1100,  1215,   569,  1214,   931,   570,  1212,   108,  1213,
    1731,  1737,   609,   517,   609,  -923,  1209,  1210,  1101,  1214,
     143,  1436,  1289,   674,  1088,   120,  1102,  1290,   675,  1306,
     610,   648,   610,  1255,   660,     9,   661,  1214,  1122,  -923,
     573,   108,  1705,  1103,  1706,   649,  1415,   572,   652,   484,
    -923,   444,   484,   950,  1381,  1698,   484,  1680,   120,   484,
     484,  1683,  1731,  1154,   143,  1021,   450,   484,  1737,   662,
     628,  1088,   650,  1212,  1350,  1213,  1129,   484,  1212,  1420,
    1213,   485,  1088,   484,  1733,  1301,  1610,   484,   651,  1774,
    1613,  1614,   484,  1130,   122,   573,   663,   143,  1670,  1289,
     432,   529,  1674,  1214,  1290,  1379,  1351,   789,  1214,   122,
     433,   791,  1211,   507,  1764,  1307,  1308,    77,  1309,  1785,
    1754,  1037,  1562,  1291,  1352,  1310,  1562,   484,  1654,  1615,
    1037,    87,  1212,  1786,  1213,  1311,  1616,   434,  1562,   484,
    1263,  1037,  1021,  1562,  1289,   303,  1617,  1312,   508,  1290,
     307,  1264,   514,  1440,   577,   532,   101,  1562,   664,  1356,
    1033,  1265,  1214,  1034,  1292,  1739,   108,  1272,  1328,  1329,
     803,   484,  1266,  1181,  1181,   688,  1715,   666,   667,   668,
    1700,   931,  1703,   120,   122,  1192,  1390,  1395,  1401,  1404,
    1248,  1330,  1708,  1264,  1709,  1249,  1401,  1223,   533,  1224,
     874,  1402,  1405,  1401,  1574,   875,   303,   303,   303,  1571,
    1088,   307,   307,   307,   421,   530,  1777,   531,  1696,  1697,
    1123,   616,   143,  1125,   484,   147,   148,   149,   484,   399,
     617,  1124,   534,  1151,  1126,  1228,   540,  1229,  1118,  1119,
    1120,   544,  1152,  1298,  1121,  1654,   860,   861,   862,   863,
     864,   865,   866,   867,   868,   869,  1441,  1442,   821,   822,
     828,   829,   564,   830,   831,  1368,  1369,  1641,  1642,   588,
     589,  1550,   484,   607,   608,   620,   621,   590,   622,   627,
     535,   623,   635,   636,   637,   591,   592,   644,   593,   638,
     639,   640,   656,   658,   659,   673,   594,   669,   859,  1654,
     595,   484,   596,   688,   691,  1747,   699,   597,   701,   700,
     712,   713,  1037,  1088,   716,   484,   718,   720,   723,   484,
     484,   724,   732,   728,   598,   725,   484,   726,   705,   740,
     742,   743,   754,   759,   484,  1556,  1593,   484,  1088,   760,
     765,   484,   755,   776,   796,   794,   804,   805,   599,   600,
     601,   602,   603,   604,   795,   797,   807,   819,   303,   832,
     833,   834,   835,   307,   303,   631,  1419,   849,   855,   307,
     856,  1377,   858,   880,   484,   881,   303,   798,  1796,   884,
    1797,   307,   885,   906,   907,   908,   910,   912,   915,  1386,
    1805,   758,   916,   917,   920,   303,   927,   926,   394,   983,
     307,  1000,   930,   942,   945,  1000,   946,   484,  1408,   981,
     984,   989,   988,  1005,   303,   985,   394,  1012,  1019,   307,
    1002,   303,  1016,  1108,   875,   803,   307,   931,  1455,  1515,
    1127,  1128,  1150,  1155,  1158,   394,   484,  1156,   684,  1162,
    1164,  1163,   395,  1469,  1165,  1168,  1170,  1176,  1169,   484,
    1177,  1181,  1195,  1248,  1418,  1180,  1187,  1193,  1249,  1194,
     395,  1422,  1198,  1197,  1200,  1205,  1221,  1201,  1222,   662,
    1271,  1240,  1250,  1273,   484,   484,   484,   484,  1277,   395,
    1288,  1276,  1281,  1302,  1325,  1333,  1507,  1088,  1660,   510,
    1516,  1517,  1321,  1521,  1334,  1322,  1335,  1336,   399,  1664,
    1556,     9,  1666,  1337,  1338,   399,  1360,  1361,   490,  1366,
    1675,  1339,  1372,  1340,  1341,   484,  1354,  1342,  1343,  1371,
    1345,  1346,  1543,  1347,  1348,  1349,  1375,  1376,  1382,   484,
    1385,  1414,  1412,  1407,  1401,  1417,  1433,   763,  1424,  1428,
    1434,  1435,  1253,  1425,  1264,  1426,  1427,  1457,  1463,  1560,
    1459,  1465,  1088,  1466,   484,  1088,  1492,  1429,  1473,  1432,
    1423,  1471,   484,  1467,  1493,  1497,  1573,  1499,  1529,  1501,
    1512,  1577,  1476,   484,  1518,  1486,  1535,  1540,  1522,  1523,
    1524,  1525,  1526,  1527,  1528,  1542,  1544,  1546,  1547,  1548,
    1549,  1552,  1538,  1583,   303,  1595,  1553,  1558,  1569,   307,
    1570,  1575,  1578,  1597,  1602,  1621,  1609,  1622,  1629,  1646,
    1665,  1623,  1624,  1630,  1633,  1666,  1634,  1605,  1606,  1635,
    1636,  1129,  1693,  1651,  1659,  1682,  1658,  1447,  1695,  1707,
    1710,  1712,  1722,  1713,  1718,  1717,  1248,  1723,  1724,  1738,
    1746,  1249,  1711,  1587,  1588,  1589,  1740,  1749,  1741,  1751,
    1762,  1750,  1752,  1753,  1755,  1756,  1770,  1769,   484,  1773,
    1782,   484,   882,  1787,  1766,  1763,  1776,  1760,  1795,  1801,
    1802,  1798,  1788,   549,  1359,  1110,  1799,   643,  1161,   679,
     545,  1374,  1379,  1780,  1720,  1789,  1758,  1792,  1794,   546,
    1001,  1297,   806,   936,  1470,  1607,  1451,  1262,  1443,   717,
    1387,   484,  1446,  1397,  1391,  1783,  1406,  1804,   809,   848,
     810,  1439,  1093,  1088,  1669,   851,  1671,   820,  1673,  1416,
     962,   840,   841,  1775,  1772,  1681,  1503,  1783,  1504,  1704,
    1431,  1438,  1437,  1491,  1487,  1620,  1766,  1300,   626,  1490,
    1324,  1134,  1367,  1537,  1619,  1643,   750,  1248,  1488,     0,
       0,     0,  1249,     0,     0,     0,     0,     0,  1248,  1248,
       0,   303,     0,  1249,  1249,     0,   307,     0,     0,  1248,
       0,     0,     0,     0,  1249,     0,  1702,     0,  1702,     0,
    1088,     0,  1088,     0,     0,     0,     0,     0,   710,     0,
     710,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1688,     0,     0,     0,   484,     0,  1716,     0,     0,  1719,
       0,     0,     0,     0,     0,     0,  1088,     0,     0,   484,
       0,     0,     0,     0,     0,     0,     0,  1725,     0,   484,
       0,  1699,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,  1088,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1761,     0,
       0,     0,     0,  1088,  1248,  1088,     0,     0,     0,  1249,
       0,     0,   484,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   484,     0,     0,     0,   484,  1778,     0,     0,
       0,   490,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1781,     0,     0,   484,     0,     0,   484,
       0,   744,   745,   303,   747,   748,   749,   751,   307,   753,
       0,     0,     0,  1790,   484,   761,     0,     0,  1791,     0,
       0,  1248,     0,   770,     0,     0,  1249,     0,     0,     0,
    1800,     0,     0,  1803,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   303,   792,   793,     0,     0,   307,
       0,     0,     0,     0,   799,   800,     0,   484,   484,     0,
     484,   484,   484,     0,   484,     0,  1248,     7,     8,     0,
       0,  1249,     0,     0,     0,  1248,     0,     0,   402,   403,
    1249,   404,   405,     0,     0,     0,     0,     0,   406,     0,
       0,     0,     0,   484,     0,     0,     0,     0,   407,   408,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   846,   409,     0,     0,   846,
     484,   410,     0,   484,     0,     0,   484,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,     0,     0,
       0,     0,   484,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   411,   412,   413,     0,     0,   911,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   935,     0,     0,     0,     0,   484,   484,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   952,
       0,     0,   414,   954,   955,     0,   957,     0,     0,     0,
       0,     0,     0,   799,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   415,     0,     0,     0,     0,
       0,     0,     0,   793,     0,     0,     0,     0,     0,  1013,
       0,     0,     0,     0,   484,   484,     0,   484,     0,   484,
       0,     0,     0,     0,     0,     0,   484,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   416,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   417,     0,     0,     0,     0,     0,     0,     0,
     418,     0,     0,     0,     0,     0,     0,   484,   419,   484,
       0,   484,     0,   484,     0,     0,     0,     0,  1111,   484,
       0,   484,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,     0,     0,
     484,     0,     0,     0,     0,     0,     0,   484,     0,     0,
       0,     0,     0,  1153,     0,     0,     0,     0,   484,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1173,     0,     0,     0,     0,
       0,     0,  1178,  1179,     0,     0,     0,     0,     0,   484,
       0,     0,     0,  1196,     0,     0,  1199,     0,     0,   484,
       0,     0,     0,     0,   484,     0,   484,     0,     0,     0,
       0,     0,     0,     0,     0,  1225,  1226,  1227,     0,  1230,
    1231,  1232,  1233,  1234,  1235,  1236,  1237,  1238,   484,     0,
    1241,  1242,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   484,  1256,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1013,     0,     0,     0,     0,
       0,     0,     0,     0,   484,  1278,     0,     0,     0,   484,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   484,     0,     0,   484,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1355,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1380,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1384,     0,     0,
       0,     0,     0,  1388,  1389,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1409,     0,     0,  1410,  1411,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1013,     0,     0,     0,     0,     0,
       0,     0,  1456,     0,  1458,     0,  1460,     0,     0,  1464,
       0,     0,     0,     0,  1468,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1551,     0,
       0,     0,     0,     0,     0,     0,  1555,  1557,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1380,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1579,  1580,  1581,
    1582,     0,  1584,  1585,     0,  1586,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1594,     0,     0,     0,     0,  1596,     0,     0,     0,
    1598,     0,     0,     0,  1601,     0,  1603,     0,  1604,     0,
       0,     0,     0,     0,  1608,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1661,     0,     0,     0,     0,  1663,  1557,     0,     0,
       0,     0,     0,     0,  1667,     0,     0,     0,     0,  1672,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1684,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1690,     0,
    1691,     0,  1692,     0,     0,  1694,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1667,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1745,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1767,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -165,   780,     0,     0,
       0,     0,     0,  1779,     0,     0,     0,  1784,     0,     0,
       0,     0,  1767,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,  1784,     0,
      10,   390,  1793,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   392,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     0,   241,     0,   242,   243,   244,   245,   246,
       0,   247,  -165,   780,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,   784,   390,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   391,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   392,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   780,   241,
       0,   242,   243,   244,   245,   246,     0,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,   389,   390,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   391,    26,    27,
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
     141,   142,   143,     0,   392,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   780,   241,     0,   242,   243,   244,   245,
     246,     0,   247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   389,   390,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   494,   391,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   495,   496,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   466,    80,    81,    82,
      83,    84,   497,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   498,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   392,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   476,   477,   478,   173,   174,
     479,   500,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,   242,   243,   244,   245,   246,     0,   247,   993,   994,
       0,     0,     0,     0,     0,     0,     0,   995,     0,     0,
       0,     0,     5,     6,     0,     0,     0,     0,     0,     0,
       0,   389,   390,     0,    12,    13,    14,   452,    16,    17,
      18,   453,    20,   454,   455,   456,   457,   391,    26,   458,
      28,    29,    30,     0,    31,    32,    33,    34,   459,    36,
      37,    38,    39,    40,    41,    42,   460,     0,    44,   461,
      46,   462,   463,    49,   464,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,   465,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,     0,
      78,   466,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   467,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,     0,   102,
     103,   104,     0,     0,     0,     0,     0,     0,   110,   468,
       0,     0,     0,     0,   112,   113,   114,   115,   469,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,   996,     0,   129,     0,   130,   131,   132,
     133,   470,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   392,   145,   146,     0,     0,     0,
     150,   151,   152,   153,   154,   155,   471,   157,   472,   159,
     473,   474,   162,   163,   164,   165,   166,   167,   475,   169,
     476,   477,   478,   173,   174,   479,   480,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   481,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     0,     0,     0,     0,   242,   482,   244,   245,
     246,   486,   247,     0,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,   389,
     390,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   391,    26,    27,    28,    29,
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
     143,     0,   392,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   242,   243,   244,   245,   246,   486,
     247,     0,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,   389,   390,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   391,    26,    27,    28,    29,    30,     0,
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
     392,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,   242,   243,   244,   245,   246,   486,   247,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     9,     0,     0,     0,   389,   390,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     494,   391,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,   495,   496,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,   466,    80,    81,    82,    83,
      84,   497,    86,     0,     0,     0,     0,    87,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   498,   106,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   392,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   476,   477,   478,   173,   174,   479,
     500,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,   486,
     242,   243,   244,   245,   246,     0,   247,     0,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   389,   390,     0,
      12,    13,    14,   452,    16,    17,    18,   453,    20,   454,
     455,   456,   457,   391,    26,   458,    28,    29,    30,     0,
      31,    32,    33,    34,   459,    36,    37,    38,    39,    40,
      41,    42,   460,     0,    44,   461,    46,   462,   463,    49,
     464,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,   465,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   466,    80,    81,
      82,    83,    84,   497,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     467,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,   104,     0,     0,
       0,   107,     0,     0,   110,   468,     0,     0,     0,     0,
     112,   113,   114,   115,   469,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,   839,
       0,   129,     0,   130,   131,   132,   133,   470,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     392,   145,   146,     0,     0,     0,   150,   151,   152,   153,
     154,   155,   471,   157,   472,   159,   473,   474,   162,   163,
     164,   165,   166,   167,   475,   169,   476,   477,   478,   173,
     174,   479,   480,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   481,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     0,     0,
     486,     0,   242,   482,   244,   245,   246,     0,   247,     5,
       6,     0,     0,     0,  1513,     0,     0,     0,   389,   390,
       0,    12,    13,    14,   452,    16,    17,    18,   453,    20,
     454,   455,   456,   457,   391,    26,   458,    28,    29,    30,
       0,    31,    32,    33,    34,   459,    36,    37,    38,    39,
      40,    41,    42,   460,     0,    44,   461,    46,   462,   463,
      49,   464,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   465,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   466,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   467,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,   104,     0,
       0,     0,     0,     0,     0,   110,   468,     0,     0,     0,
       0,   112,   113,   114,   115,   469,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,   123,   124,   125,     0,
       0,     0,   126,  1514,   127,   128,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   470,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   392,   145,   146,     0,     0,     0,   150,   151,   152,
     153,   154,   155,   471,   157,   472,   159,   473,   474,   162,
     163,   164,   165,   166,   167,   475,   169,   476,   477,   478,
     173,   174,   479,   480,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   481,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     0,
       0,   486,     0,   242,   482,   244,   245,   246,     0,   247,
       5,     6,     0,     0,     0,     0,     0,     0,     0,   389,
     390,     0,    12,    13,    14,   452,    16,    17,    18,   453,
      20,   454,   455,   456,   457,   391,    26,   458,    28,    29,
      30,     0,    31,    32,    33,    34,   459,    36,    37,    38,
      39,    40,    41,    42,   460,     0,    44,   461,    46,   462,
     463,    49,   464,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,   465,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   466,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   467,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,   104,
       0,     0,     0,     0,     0,     0,   110,   468,     0,     0,
       0,     0,   112,   113,   114,   115,   469,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   470,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   392,   145,   146,     0,     0,     0,   150,   151,
     152,   153,   154,   155,   471,   157,   472,   159,   473,   474,
     162,   163,   164,   165,   166,   167,   475,   169,   476,   477,
     478,   173,   174,   479,   480,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   481,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       0,     0,     0,     0,   242,   482,   244,   245,   246,     0,
     247,   511,   512,     0,     0,     0,     0,     0,     5,     6,
       0,     0,     0,     0,     0,     0,     0,   389,   390,     0,
      12,    13,    14,   452,    16,    17,    18,   453,    20,   454,
     455,   456,   457,   391,    26,   458,    28,    29,    30,     0,
      31,    32,    33,    34,   459,    36,    37,    38,    39,    40,
      41,    42,   460,     0,    44,   461,    46,   462,   463,    49,
     464,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,   465,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   466,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     467,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,   104,     0,     0,
       0,     0,     0,     0,   110,   468,     0,     0,     0,     0,
     112,   113,   114,   115,   469,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   470,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     392,   145,   146,     0,     0,     0,   150,   151,   152,   153,
     154,   155,   471,   157,   472,   159,   473,   474,   162,   163,
     164,   165,   166,   167,   475,   169,   476,   477,   478,   173,
     174,   479,   480,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   481,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     0,     0,
       0,     0,   242,   482,   244,   245,   246,     0,   247,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,    10,    11,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
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
       0,   141,   142,   143,     0,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,     0,   242,   243,   244,
     245,   246,     0,   247,   248,   249,     1,     2,     3,     4,
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
     143,     0,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   242,   243,   244,   245,   246,     0,
     247,     0,   541,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,   389,   390,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   391,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,   719,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   392,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,   242,   243,   244,   245,   246,     0,   247,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,   389,   390,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   391,    26,    27,
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
     124,   125,     0,   487,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   392,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,   242,   243,   244,   245,
     246,     0,   247,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,   389,   390,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,  1243,   391,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,  1244,  1245,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,   487,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   392,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,  1246,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,   242,   243,   244,   245,   246,     0,   247,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,   389,   390,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   391,    26,    27,
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
     141,   142,   143,     0,   392,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,   242,   243,   244,   245,
     246,     0,   247,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,    10,    11,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,   242,   243,   244,   245,   246,     0,   247,     1,     2,
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
     141,   142,   143,     0,   392,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,   242,   243,   244,   245,
     246,     0,   247,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,    10,   390,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   392,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,   242,   243,   244,   245,   246,     0,   247,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,   784,   390,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   391,    26,    27,
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
     141,   142,   143,     0,   392,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,   242,   243,   244,   245,
     246,     0,   247,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,   389,   390,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,  1243,   391,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,  1244,  1245,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   392,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,  1246,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,   242,   243,   244,   245,   246,     0,   247,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     9,     0,     0,
       0,   389,   390,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   494,   391,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,   495,   496,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,   466,    80,    81,    82,    83,    84,   497,    86,     0,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   498,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,   499,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   392,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     476,   477,   478,   173,   174,   479,   500,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,   242,   243,   244,   245,
     246,     0,   247,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   389,   390,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   494,   391,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   495,   496,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   466,    80,    81,    82,
      83,    84,   497,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   498,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,   504,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   392,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   476,   477,   478,   173,   174,
     479,   500,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,   242,   243,   244,   245,   246,     0,   247,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     9,     0,     0,
       0,   389,   390,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   494,   391,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,   495,   496,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,   466,    80,    81,    82,    83,    84,   497,    86,     0,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   498,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   392,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     476,   477,   478,   173,   174,   479,   500,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   536,   241,     0,   242,   243,   244,   245,
     246,     0,   247,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   389,   390,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   494,   391,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   495,   496,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   466,    80,    81,    82,
      83,    84,   497,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   498,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   392,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   476,   477,   478,   173,   174,
     479,   500,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
     538,   242,   243,   244,   245,   246,     0,   247,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     9,     0,     0,
       0,   389,   390,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   494,   391,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,   495,   496,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,   466,    80,    81,    82,    83,    84,   497,    86,     0,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   498,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,   837,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   392,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     476,   477,   478,   173,   174,   479,   500,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,   242,   243,   244,   245,
     246,     0,   247,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   389,   390,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   494,   391,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   495,   496,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   466,    80,    81,    82,
      83,    84,   497,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   498,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,   845,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   392,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   476,   477,   478,   173,   174,
     479,   500,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,   242,   243,   244,   245,   246,     0,   247,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     9,     0,     0,
       0,   389,   390,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   494,   391,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,   495,   496,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,   466,    80,    81,    82,    83,    84,   497,    86,     0,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   498,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,   850,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   392,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     476,   477,   478,   173,   174,   479,   500,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,   242,   243,   244,   245,
     246,     0,   247,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   389,   390,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   455,
      23,   457,   391,    26,   458,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   460,     0,    44,    45,    46,   462,   463,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   466,    80,    81,    82,
      83,    84,   497,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   467,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   498,   106,     0,
     107,   108,   624,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     625,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   392,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   471,   157,   472,   159,   473,   474,   162,   163,   164,
     165,   166,   167,   475,   169,   476,   477,   478,   173,   174,
     479,   480,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   481,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,   242,   482,   244,   245,   246,     0,   247,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     9,     0,     0,
       0,   389,   390,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   494,   391,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,   495,   496,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,   466,    80,    81,    82,    83,    84,   497,    86,     0,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   498,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   392,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     476,   477,   478,   173,   174,   479,   500,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,   242,   243,   244,   245,
     246,     0,   247,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   389,   390,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   455,
      23,   457,   391,    26,   458,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   460,     0,    44,    45,    46,   462,   463,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   466,    80,    81,    82,
      83,    84,   497,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   467,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   498,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   392,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   471,   157,   472,   159,   473,   474,   162,   163,   164,
     165,   166,   167,   475,   169,   476,   477,   478,   173,   174,
     479,   480,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   481,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,   241,
       0,   242,   482,   244,   245,   246,     0,   247,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     9,     0,     0,
       0,   389,   390,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   455,    23,   457,   391,    26,   458,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   460,     0,    44,    45,
      46,   462,   463,    49,   464,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,   466,    80,    81,    82,    83,    84,   497,    86,     0,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   467,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   498,   106,     0,   107,   108,     0,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   392,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   471,   157,   472,   159,
     473,   474,   162,   163,   164,   165,   166,   167,   475,   169,
     476,   477,   478,   173,   174,   479,   480,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   481,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,   242,   482,   244,   245,
     246,     0,   247,     5,     6,     0,     0,     0,     0,     0,
       0,     0,   389,   390,     0,    12,    13,    14,  1048,    16,
      17,    18,   453,  1049,  1050,   455,  1051,   457,   391,    26,
     458,    28,  1052,    30,     0,    31,    32,    33,    34,  1053,
      36,  1054,  1055,    39,    40,    41,    42,   460,     0,    44,
    1056,    46,   462,   463,    49,   464,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,  1057,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
       0,    78,   466,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   467,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,  1058,     0,     0,     0,  1059,     0,     0,   110,
     468,     0,     0,     0,     0,   112,   113,   114,   115,   469,
     117,   118,   119,     0,     0,     0,     0,     0,     0,     0,
     123,   124,   125,     0,     0,     0,   126,  1508,   127,   128,
       0,     0,     0,     0,  1509,     0,   129,     0,   130,   131,
     132,   133,   470,   135,   136,   137,   138,   139,   140,     0,
       0,  1060,   142,     0,     0,   392,   145,   146,     0,     0,
       0,   150,   151,   152,   153,   154,   155,   471,  1061,   472,
     159,   473,   474,   162,   163,   164,   165,   166,   167,   475,
     169,   476,   477,   478,   173,   174,   479,   480,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     481,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     0,     0,     5,     6,   242,   482,   244,
    1062,  1063,  1064,  1065,   389,   390,     0,    12,    13,    14,
    1048,    16,    17,    18,   453,  1049,  1050,   455,  1051,   457,
     391,    26,   458,    28,  1052,    30,     0,    31,    32,    33,
      34,  1053,    36,  1054,  1055,    39,    40,    41,    42,   460,
       0,    44,  1056,    46,   462,   463,    49,   464,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,  1057,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   466,    80,    81,    82,    83,    84,
    1398,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   467,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,  1058,     0,     0,     0,  1059,     0,
       0,   110,   468,     0,     0,     0,     0,   112,   113,   114,
     115,   469,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   470,   135,   136,   137,   138,   139,
     140,     0,     0,  1060,   142,     0,     0,   392,   145,   146,
       0,     0,     0,   150,   151,   152,   153,   154,   155,   471,
    1061,   472,   159,   473,   474,   162,   163,   164,   165,   166,
     167,   475,   169,   476,   477,   478,   173,   174,   479,   480,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   481,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     0,     0,     5,     6,   242,
     482,   244,  1062,  1063,  1064,  1065,   389,   390,     0,    12,
      13,    14,  1048,    16,    17,    18,   453,  1049,  1050,   455,
    1051,   457,   391,    26,   458,    28,  1052,    30,     0,    31,
      32,    33,    34,  1053,    36,  1054,  1055,    39,    40,    41,
      42,   460,     0,    44,  1056,    46,   462,   463,    49,   464,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,  1057,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   466,    80,    81,    82,
      83,    84,  1563,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   467,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,  1058,     0,     0,     0,
    1059,     0,     0,   110,   468,     0,     0,     0,     0,   112,
     113,   114,   115,   469,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   470,   135,   136,   137,
     138,   139,   140,     0,     0,  1060,   142,     0,     0,   392,
     145,   146,     0,     0,     0,   150,   151,   152,   153,   154,
     155,   471,  1061,   472,   159,   473,   474,   162,   163,   164,
     165,   166,   167,   475,   169,   476,   477,   478,   173,   174,
     479,   480,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   481,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     0,     0,     5,
       6,   242,   482,   244,  1062,  1063,  1064,  1065,   389,   390,
       0,    12,    13,    14,  1048,    16,    17,    18,   453,  1049,
    1050,   455,  1051,   457,   391,    26,   458,    28,  1052,    30,
       0,    31,    32,    33,    34,  1053,    36,  1054,  1055,    39,
      40,    41,    42,   460,     0,    44,  1056,    46,   462,   463,
      49,   464,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,  1057,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   466,    80,
      81,    82,    83,    84,  1567,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   467,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,  1058,     0,
       0,     0,  1059,     0,     0,   110,   468,     0,     0,     0,
       0,   112,   113,   114,   115,   469,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   470,   135,
     136,   137,   138,   139,   140,     0,     0,  1060,   142,     0,
       0,   392,   145,   146,     0,     0,     0,   150,   151,   152,
     153,   154,   155,   471,  1061,   472,   159,   473,   474,   162,
     163,   164,   165,   166,   167,   475,   169,   476,   477,   478,
     173,   174,   479,   480,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   481,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     0,
       0,     5,     6,   242,   482,   244,  1062,  1063,  1064,  1065,
     389,   390,     0,    12,    13,    14,  1048,    16,    17,    18,
     453,  1049,  1050,   455,  1051,   457,   391,    26,   458,    28,
    1052,    30,     0,    31,    32,    33,    34,  1053,    36,  1054,
    1055,    39,    40,    41,    42,   460,     0,    44,  1056,    46,
     462,   463,    49,   464,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,  1057,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     466,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   467,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
    1058,     0,     0,     0,  1059,     0,     0,   110,   468,     0,
       0,     0,     0,   112,   113,   114,   115,   469,   117,   118,
     119,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     470,   135,   136,   137,   138,   139,   140,     0,     0,  1060,
     142,     0,     0,   392,   145,   146,     0,     0,     0,   150,
     151,   152,   153,   154,   155,   471,  1061,   472,   159,   473,
     474,   162,   163,   164,   165,   166,   167,   475,   169,   476,
     477,   478,   173,   174,   479,   480,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   481,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     0,     0,     5,     6,   242,   482,   244,  1062,  1063,
    1064,  1065,   389,   390,     0,    12,    13,    14,  1048,    16,
      17,    18,   453,  1049,  1050,   455,  1051,   457,   391,    26,
     458,    28,  1052,    30,     0,    31,    32,    33,    34,  1053,
      36,  1054,  1055,    39,    40,    41,    42,   460,     0,    44,
    1056,    46,   462,   463,    49,   464,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,  1057,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
       0,    78,   466,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   467,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,  1058,     0,     0,     0,  1059,     0,     0,   110,
     468,     0,     0,     0,     0,   112,   113,   114,   115,   469,
     117,   118,   119,     0,     0,     0,     0,     0,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   470,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   392,   145,   146,     0,     0,
       0,   150,   151,   152,   153,   154,   155,   471,  1061,   472,
     159,   473,   474,   162,   163,   164,   165,   166,   167,   475,
     169,   476,   477,   478,   173,   174,   479,   480,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     481,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     0,     0,     5,     6,   242,   482,   244,
    1062,  1063,  1064,  1065,   389,   390,     0,    12,    13,    14,
     452,    16,    17,    18,   453,    20,   454,   455,   456,   457,
     391,    26,   458,    28,    29,    30,     0,    31,    32,    33,
      34,   459,    36,    37,    38,    39,    40,    41,    42,   460,
       0,    44,   461,    46,   462,   463,    49,   464,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,   465,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   466,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   467,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,   104,     0,     0,     0,     0,     0,
       0,   110,   468,     0,     0,     0,     0,   112,   113,   114,
     115,   469,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,     0,   126,  1505,
     127,   128,     0,     0,     0,     0,  1506,     0,   129,     0,
     130,   131,   132,   133,   470,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   392,   145,   146,
       0,     0,     0,   150,   151,   152,   153,   154,   155,   471,
     157,   472,   159,   473,   474,   162,   163,   164,   165,   166,
     167,   475,   169,   476,   477,   478,   173,   174,   479,   480,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   481,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     0,     0,     5,     6,   242,
     482,   244,   245,   246,     0,   247,   389,   390,     0,    12,
      13,    14,   452,    16,    17,    18,   453,    20,   454,   455,
     456,   457,   391,    26,   458,    28,    29,    30,     0,    31,
      32,    33,    34,   459,    36,    37,    38,    39,    40,    41,
      42,   460,     0,    44,   461,    46,   462,   463,    49,   464,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,   465,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   466,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   467,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,   104,     0,     0,     0,
       0,     0,     0,   110,   468,     0,     0,     0,     0,   112,
     113,   114,   115,   469,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,   123,   124,   125,     0,     0,     0,
     126,  1519,   127,   128,     0,     0,     0,     0,  1520,     0,
     129,     0,   130,   131,   132,   133,   470,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   392,
     145,   146,     0,     0,     0,   150,   151,   152,   153,   154,
     155,   471,   157,   472,   159,   473,   474,   162,   163,   164,
     165,   166,   167,   475,   169,   476,   477,   478,   173,   174,
     479,   480,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   481,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     0,     0,     5,
       6,   242,   482,   244,   245,   246,     0,   247,   389,   390,
       0,    12,    13,    14,   452,    16,    17,    18,   453,    20,
     454,   455,   456,   457,   391,    26,   458,    28,    29,    30,
       0,    31,    32,    33,    34,   459,    36,    37,    38,    39,
      40,    41,    42,   460,     0,    44,   461,    46,   462,   463,
      49,   464,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   465,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   466,    80,
      81,    82,    83,    84,  1274,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   467,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,   104,     0,
       0,     0,     0,     0,     0,   110,   468,     0,     0,     0,
       0,   112,   113,   114,   115,   469,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   470,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   392,   145,   146,     0,     0,     0,   150,   151,   152,
     153,   154,   155,   471,   157,   472,   159,   473,   474,   162,
     163,   164,   165,   166,   167,   475,   169,   476,   477,   478,
     173,   174,   479,   480,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   481,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     0,
       0,     5,     6,   242,   482,   244,   245,   246,     0,   247,
     389,   390,     0,    12,    13,    14,   452,    16,    17,    18,
     453,    20,   454,   455,   456,   457,   391,    26,   458,    28,
      29,    30,     0,    31,    32,    33,    34,   459,    36,    37,
      38,    39,    40,    41,    42,   460,     0,    44,   461,    46,
     462,   463,    49,   464,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,   465,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     466,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   467,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
     104,     0,     0,     0,     0,     0,     0,   110,   468,     0,
       0,     0,     0,   112,   113,   114,   115,   469,   117,   118,
     119,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     470,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   392,   145,   146,     0,     0,     0,   150,
     151,   152,   153,   154,   155,   471,   157,   472,   159,   473,
     474,   162,   163,   164,   165,   166,   167,   475,   169,   476,
     477,   478,   173,   174,   479,   480,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   481,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     0,     0,     5,     6,   242,   482,   244,   245,   246,
       0,   247,   389,   390,     0,    12,    13,    14,     0,    16,
      17,    18,   453,     0,     0,   455,   456,     0,   391,    26,
     458,    28,     0,    30,     0,    31,    32,    33,    34,     0,
      36,     0,     0,    39,    40,    41,    42,   460,     0,    44,
       0,    46,     0,     0,    49,   464,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,     0,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
       0,    78,   466,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   467,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,     0,     0,     0,     0,     0,     0,     0,   110,
     468,     0,     0,     0,     0,   112,   113,   114,   115,   469,
     117,   118,   119,     0,     0,     0,     0,     0,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   470,   135,   136,   137,   138,   139,   140,     0,
       0,     0,   142,     0,     0,   392,   145,   146,     0,     0,
       0,   150,   151,   152,   153,   154,   155,   471,     0,   472,
     159,   473,   474,   162,   163,   164,   165,   166,   167,   475,
     169,   476,   477,   478,   173,   174,     0,   480,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     481,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     0,     0,     0,     0,   242,   482,   244,
     245,   246,     0,   247
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,     1,     2,     3,     4,     0,     1,     2,     3,     4,
     176,   120,   307,   627,     1,     2,     3,   733,   611,    10,
     400,   401,   612,   613,   614,   615,   943,   705,   287,   930,
     337,  1188,  1204,   803,   255,   630,    85,   715,   554,   555,
       1,     1,     2,     3,     4,   832,   833,   520,  1268,  1269,
     965,   803,   525,   256,  1019,     1,   105,  1401,  1034,   108,
    1404,   248,   249,   907,    57,    37,   857,    37,   271,    27,
      28,   120,   907,   122,   552,   553,  1325,   652,    27,    28,
     120,    98,   120,  1217,     1,     1,     2,     3,     4,    30,
      48,   402,     1,  1540,     1,     1,   109,     1,   819,    48,
       1,     1,    30,    46,   109,   105,   109,     1,     1,    58,
     105,   552,   553,   554,   555,   873,   106,   107,    76,     1,
     278,    64,   433,   434,    96,   803,    98,    76,    98,    40,
     144,   149,    81,   920,    45,    46,   395,  1594,   102,     1,
     399,     8,    30,    54,   931,   105,   123,    95,   109,   155,
      61,   120,    63,    64,    38,    39,   114,    41,    42,     1,
     133,    72,     1,   109,   113,   114,   115,     0,     1,     1,
     121,   112,    98,   230,   149,    59,    98,   149,   235,   149,
     160,   933,    31,   130,   131,   126,   189,   115,    99,   105,
     230,     1,     1,    56,    96,    58,     1,   590,   178,   592,
     593,   879,   595,   870,   597,   156,   212,   158,   503,   109,
     151,   155,   605,   606,   155,   882,   109,   158,     1,   192,
     189,   201,     1,  1443,   188,   238,   219,   109,     1,     1,
     489,   115,   158,  1690,   162,   240,     1,   185,   179,   102,
     278,   919,   144,   109,   261,   961,   189,   109,   248,   249,
     240,   241,   252,   248,   249,  1025,  1413,   252,   774,   775,
     278,   238,   319,   421,   278,  1712,   259,   109,  1185,  1170,
     109,  1023,   312,  1025,   162,   192,   109,   109,   162,   220,
     221,   222,  1416,   192,   859,   192,   192,   287,   192,   189,
    1539,   192,   287,  1208,   772,   773,   189,   287,   192,   109,
     109,  1059,  1217,   278,   109,   414,   278,   189,   278,  1274,
     177,  1155,   571,  1034,  1035,  1106,   425,   109,   230,   230,
    1155,  1665,     1,   264,   190,  1301,   109,   189,     0,     1,
     109,   552,   553,   158,   292,     1,   109,   109,   109,   261,
     262,   225,   300,   292,   109,   187,   549,   550,  1026,     1,
     189,   300,   663,   186,   541,   187,   559,   318,   407,   308,
       1,   410,     1,     1,   109,   414,   102,   216,   417,   418,
     316,   158,   230,   132,   232,  1162,   425,   186,  1722,   189,
    1724,    96,   266,   109,   189,   696,   435,   155,     1,   230,
     120,   232,   441,   256,   108,   395,   445,   189,   121,   399,
     395,   450,   109,   186,   399,   395,   269,   319,   271,   399,
     189,   322,   323,   324,     1,   129,   189,   189,   189,   282,
     283,   284,   815,   286,   189,   288,   426,   427,   109,   120,
     109,   426,   427,   156,  1654,   158,   485,   109,   428,   819,
     199,   431,   442,   109,   212,   190,   446,   442,   497,   498,
     440,   446,   188,   443,   444,     1,   162,   109,   188,   449,
      43,   319,   219,   189,    47,    34,   426,   427,   109,    52,
     109,   109,   852,     5,   523,    96,  1154,     9,   319,   138,
     529,    50,   442,     1,    78,   192,   446,   155,    71,   489,
    1006,  1007,  1008,   152,   489,  1715,   109,   188,   498,   489,
      53,  1416,   259,   498,   763,   186,  1276,   186,   223,   224,
     426,   427,   985,  1108,   186,  1687,   109,   507,   508,   242,
     186,   630,   109,   238,   514,    96,   442,    85,   149,   109,
     446,   790,  1284,   582,   534,    98,  1150,   586,   498,   534,
      46,   541,    48,   533,   534,   186,   541,   186,   186,  1336,
     108,   772,   552,   553,   554,   555,   547,   552,   553,   554,
     555,   155,   120,   109,   122,  1006,  1007,  1008,   188,   880,
     881,   571,   132,   186,   885,   778,   571,   102,   131,   782,
    1301,   630,   498,   692,   119,  1742,   695,   170,    30,  1310,
     173,   109,   212,   125,  1272,   127,   189,   158,   109,   186,
    1321,   109,   108,   135,   915,   188,   109,   109,   171,   189,
     659,     1,   721,   148,     9,    10,   109,   138,   534,   160,
      98,    43,   184,   155,   673,    47,   161,   273,   677,   678,
      52,   214,   226,   227,   280,   684,   198,   178,   628,   199,
     186,   631,   155,   692,    34,    98,   695,    96,  1549,    71,
     699,    98,   223,   224,  1034,  1035,    27,    28,     9,    10,
      50,   196,   115,   188,   170,    96,   171,   238,   186,     5,
     112,   149,   721,     9,   158,     1,    43,     3,   189,   262,
      47,   189,   203,   732,   126,    52,   189,   189,   688,  1459,
     121,     9,    10,   688,   257,   258,   189,   260,  1414,   204,
     149,   688,   149,  1419,    71,   158,     1,    98,   120,   151,
     105,    96,   712,   713,   277,   155,   765,   712,   713,  1312,
     123,   139,    96,   108,   115,   156,   289,   158,   688,  1036,
     125,   990,   127,   274,   724,   725,   726,   155,   728,    34,
     281,  1257,    68,   114,   147,   794,   155,    73,   170,   155,
     291,   173,   712,   713,   105,   158,    98,     9,   807,   144,
     155,  1375,     9,   763,   159,   139,   188,   158,   763,  1686,
     144,  1492,   688,   763,   125,  1562,   127,    29,   220,   221,
     222,   176,    29,   832,   833,   834,   835,   105,   991,   125,
     790,   127,   214,   784,   120,   790,   712,   713,   158,   135,
    1003,   150,   197,   170,   155,    96,   173,   125,   159,   127,
    1677,  1678,   160,   218,   160,   123,     9,    10,   167,   155,
     215,   188,    55,   139,   873,   176,   150,    60,   144,   171,
     178,   184,   178,   999,    46,    30,    48,   155,   887,   147,
     262,   159,  1629,   167,  1631,   198,   197,   214,   406,   407,
     158,   158,   410,   144,  1165,   201,   414,  1573,   176,   417,
     418,  1577,  1729,   912,   215,    98,   120,   425,  1735,    81,
     155,   920,   168,   125,   146,   127,    98,   435,   125,   197,
     127,   120,   931,   441,   136,   155,  1476,   445,   184,   136,
    1483,  1484,   450,   115,   179,   262,   108,   215,   188,    55,
      25,   120,   188,   155,    60,  1164,   178,   556,   155,   179,
      35,   560,   105,   155,   188,   257,   258,   112,   260,   188,
    1707,  1301,   212,    79,   196,   267,   212,   485,  1542,   274,
    1310,   126,   125,   188,   127,   277,   281,    62,   212,   497,
      97,  1321,    98,   212,    55,   945,   291,   289,   155,    60,
     945,   108,   155,  1264,  1249,   247,   151,   212,   170,   139,
     155,   118,   155,   158,   120,  1681,   159,  1016,   252,   253,
    1019,   529,   129,   102,   102,   155,  1654,   226,   227,   228,
    1625,    96,  1627,   176,   179,   945,   115,   115,   102,   102,
     990,   275,  1637,   108,  1639,   990,   102,   237,   158,   239,
     139,   115,   115,   102,   197,   144,  1006,  1007,  1008,   115,
    1059,  1006,  1007,  1008,  1005,   246,   115,   246,  1611,  1612,
     268,   203,   215,   268,   582,   220,   221,   222,   586,   945,
     212,   279,   155,   304,   279,   237,   319,   239,   282,   283,
     284,     0,   313,  1033,   288,  1659,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   130,   131,   609,   610,
     616,   617,   192,   618,   619,  1148,  1149,  1530,  1531,   169,
      94,  1382,   630,   254,   101,    51,   202,   134,   103,   195,
    1246,   104,   147,   158,   186,   142,   143,    30,   145,   186,
     186,   186,    48,   154,   120,   309,   153,   251,   656,  1713,
     157,   659,   159,   155,     1,  1698,   120,   164,   109,   144,
     155,   155,  1492,  1162,   144,   673,   186,   123,   123,   677,
     678,   158,    36,   155,   181,   158,   684,   158,  1177,    17,
     216,    30,   236,   192,   692,  1394,  1447,   695,  1187,   192,
     250,   699,   235,     3,   172,   120,   289,   289,   205,   206,
     207,   208,   209,   210,   170,   172,   120,    72,  1158,   236,
      96,    96,    96,  1158,  1164,   156,  1215,   151,   109,  1164,
     109,  1158,    30,   162,   732,   162,  1176,  1436,  1792,   129,
    1794,  1176,   134,   251,    96,   304,   144,   120,   134,  1176,
    1804,  1240,   186,   186,    96,  1195,    46,    98,  1158,   242,
    1195,  1250,    98,   186,   155,  1254,   186,   765,  1195,    96,
     230,   192,   144,    34,  1214,   236,  1176,   172,   109,  1214,
     238,  1221,   120,   134,   144,  1274,  1221,    96,  1277,  1338,
      30,   291,   232,    96,   155,  1195,   794,   304,   120,    96,
     200,   186,  1158,  1292,   134,   162,    98,   155,   134,   807,
     120,   102,   155,  1253,  1214,   149,   102,   186,  1253,   186,
    1176,  1221,   192,   144,   123,    36,   155,   123,    30,    81,
     109,   120,   250,   109,   832,   833,   834,   835,   120,  1195,
     259,   129,   149,   290,   272,   158,  1335,  1336,  1547,  1338,
    1339,  1340,   263,  1342,   158,   265,   158,   158,  1214,  1558,
    1559,    30,  1561,   158,   158,  1221,   291,    30,   105,    30,
    1569,   158,   311,   158,   158,   873,   146,   158,   158,   292,
     158,   158,  1371,   158,   158,   158,   232,   192,   109,   887,
     144,   134,   200,   186,   102,     7,   158,  1253,   238,    98,
     158,   158,   155,   238,   108,   238,   238,   149,   149,  1398,
     129,   149,  1401,   120,   912,  1404,   149,   242,   189,   188,
     192,    79,   920,   120,   287,   291,  1415,    80,    30,   189,
     189,  1420,   255,   931,   189,   255,    30,   109,   189,   189,
     189,   189,   189,   189,   189,   172,   262,   186,   128,   128,
      98,   186,   276,   321,  1394,   144,   188,   188,   188,  1394,
     186,   186,   186,   149,   149,   155,   186,   285,    96,    30,
      96,   189,   189,   189,   189,  1674,   189,  1466,  1467,   189,
     189,    98,   149,   189,   172,   199,   292,   108,    55,    96,
      30,   109,    96,   109,   230,   120,  1436,   188,    96,   199,
     120,  1436,   270,  1433,  1434,  1435,   199,   189,   200,   146,
     120,   189,   189,   189,   189,   189,    95,   188,  1016,   185,
     120,  1019,   662,   120,  1723,   230,   199,   310,   188,   230,
     120,   201,   298,   255,  1109,   874,   292,   401,   921,   421,
     252,  1155,  1741,   310,  1659,   310,  1713,   311,   311,   252,
     766,  1031,   586,   701,  1293,  1469,  1273,  1012,  1268,   485,
    1177,  1059,  1271,  1185,  1182,  1764,  1190,   311,   588,   633,
     589,  1254,   835,  1562,  1563,   636,  1565,   608,  1567,  1208,
     733,   630,   630,  1735,  1729,  1574,  1334,  1786,  1334,  1627,
    1240,  1251,  1250,  1321,  1310,  1492,  1795,  1035,   332,  1314,
    1044,   906,  1131,  1365,  1489,  1533,   523,  1547,  1311,    -1,
      -1,    -1,  1547,    -1,    -1,    -1,    -1,    -1,  1558,  1559,
      -1,  1561,    -1,  1558,  1559,    -1,  1561,    -1,    -1,  1569,
      -1,    -1,    -1,    -1,  1569,    -1,  1625,    -1,  1627,    -1,
    1629,    -1,  1631,    -1,    -1,    -1,    -1,    -1,  1637,    -1,
    1639,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1590,    -1,    -1,    -1,  1162,    -1,  1655,    -1,    -1,  1658,
      -1,    -1,    -1,    -1,    -1,    -1,  1665,    -1,    -1,  1177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1676,    -1,  1187,
      -1,  1621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1215,  1707,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1717,    -1,
      -1,    -1,    -1,  1722,  1674,  1724,    -1,    -1,    -1,  1674,
      -1,    -1,  1240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1250,    -1,    -1,    -1,  1254,  1746,    -1,    -1,
      -1,   498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1762,    -1,    -1,  1274,    -1,    -1,  1277,
      -1,   518,   519,  1723,   521,   522,   523,   524,  1723,   526,
      -1,    -1,    -1,  1782,  1292,   532,    -1,    -1,  1787,    -1,
      -1,  1741,    -1,   540,    -1,    -1,  1741,    -1,    -1,    -1,
    1799,    -1,    -1,  1802,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1764,   562,   563,    -1,    -1,  1764,
      -1,    -1,    -1,    -1,   571,   572,    -1,  1335,  1336,    -1,
    1338,  1339,  1340,    -1,  1342,    -1,  1786,    27,    28,    -1,
      -1,  1786,    -1,    -1,    -1,  1795,    -1,    -1,    38,    39,
    1795,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,  1371,    -1,    -1,    -1,    -1,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   632,    76,    -1,    -1,   636,
    1398,    81,    -1,  1401,    -1,    -1,  1404,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1415,    -1,    -1,
      -1,    -1,  1420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,    -1,    -1,   675,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   700,    -1,    -1,    -1,    -1,  1466,  1467,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   716,
      -1,    -1,   162,   720,   721,    -1,   723,    -1,    -1,    -1,
      -1,    -1,    -1,   730,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   790,    -1,    -1,    -1,    -1,    -1,   796,
      -1,    -1,    -1,    -1,  1562,  1563,    -1,  1565,    -1,  1567,
      -1,    -1,    -1,    -1,    -1,    -1,  1574,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   266,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   292,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     300,    -1,    -1,    -1,    -1,    -1,    -1,  1625,   308,  1627,
      -1,  1629,    -1,  1631,    -1,    -1,    -1,    -1,   875,  1637,
      -1,  1639,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1655,    -1,    -1,
    1658,    -1,    -1,    -1,    -1,    -1,    -1,  1665,    -1,    -1,
      -1,    -1,    -1,   910,    -1,    -1,    -1,    -1,  1676,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   932,    -1,    -1,    -1,    -1,
      -1,    -1,   939,   940,    -1,    -1,    -1,    -1,    -1,  1707,
      -1,    -1,    -1,   950,    -1,    -1,   953,    -1,    -1,  1717,
      -1,    -1,    -1,    -1,  1722,    -1,  1724,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   972,   973,   974,    -1,   976,
     977,   978,   979,   980,   981,   982,   983,   984,  1746,    -1,
     987,   988,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1762,  1002,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1012,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1782,  1022,    -1,    -1,    -1,  1787,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1799,    -1,    -1,  1802,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1096,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1164,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1174,    -1,    -1,
      -1,    -1,    -1,  1180,  1181,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1197,    -1,    -1,  1200,  1201,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1271,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1279,    -1,  1281,    -1,  1283,    -1,    -1,  1286,
      -1,    -1,    -1,    -1,  1291,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1385,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1393,  1394,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1412,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1424,  1425,  1426,
    1427,    -1,  1429,  1430,    -1,  1432,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1448,    -1,    -1,    -1,    -1,  1453,    -1,    -1,    -1,
    1457,    -1,    -1,    -1,  1461,    -1,  1463,    -1,  1465,    -1,
      -1,    -1,    -1,    -1,  1471,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1548,    -1,    -1,    -1,    -1,  1553,  1554,    -1,    -1,
      -1,    -1,    -1,    -1,  1561,    -1,    -1,    -1,    -1,  1566,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1583,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1595,    -1,
    1597,    -1,  1599,    -1,    -1,  1602,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1670,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1693,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1723,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,
      -1,    -1,    -1,  1760,    -1,    -1,    -1,  1764,    -1,    -1,
      -1,    -1,  1769,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,  1785,    -1,
      34,    35,  1789,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,   317,    -1,   319,   320,   321,   322,   323,
      -1,   325,     0,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
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
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,     1,   317,
      -1,   319,   320,   321,   322,   323,    -1,   325,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
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
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,     1,   317,    -1,   319,   320,   321,   322,
     323,    -1,   325,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,   317,
      -1,   319,   320,   321,   322,   323,    -1,   325,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
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
     183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,    -1,    -1,   217,   218,   219,    -1,    -1,    -1,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,    -1,    -1,    -1,    -1,   319,   320,   321,   322,
     323,    16,   325,    -1,    -1,    -1,    21,    22,    23,    24,
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
     255,   256,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    -1,   317,    -1,   319,   320,   321,   322,   323,    16,
     325,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
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
     257,   258,   259,   260,   261,   262,    -1,   264,   265,   266,
      -1,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
     317,    -1,   319,   320,   321,   322,   323,    16,   325,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    -1,    -1,
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
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    16,
     319,   320,   321,   322,   323,    -1,   325,    -1,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,    -1,
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,   150,    -1,   152,   153,   154,    -1,    -1,
      -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,
     217,   218,   219,    -1,    -1,    -1,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,    -1,   264,   265,   266,
      -1,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,    -1,    -1,
      16,    -1,   319,   320,   321,   322,   323,    -1,   325,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
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
      -1,    -1,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,   218,   219,    -1,    -1,    -1,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,    -1,
      -1,    16,    -1,   319,   320,   321,   322,   323,    -1,   325,
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
      -1,    -1,   217,   218,   219,    -1,    -1,    -1,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
      -1,    -1,    -1,    -1,   319,   320,   321,   322,   323,    -1,
     325,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,
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
      -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,
     217,   218,   219,    -1,    -1,    -1,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,    -1,   264,   265,   266,
      -1,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,    -1,    -1,
      -1,    -1,   319,   320,   321,   322,   323,    -1,   325,    21,
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
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,   317,    -1,   319,   320,   321,
     322,   323,    -1,   325,   326,   327,    21,    22,    23,    24,
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
     255,   256,   257,   258,   259,   260,   261,   262,    -1,   264,
     265,   266,    -1,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    -1,   317,    -1,   319,   320,   321,   322,   323,    -1,
     325,    -1,   327,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
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
     178,   179,    -1,    -1,   182,   183,   184,    -1,   186,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
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
      -1,   319,   320,   321,   322,   323,    -1,   325,    21,    22,
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
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,   317,    -1,   319,   320,   321,   322,
     323,    -1,   325,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
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
     178,   179,    -1,    -1,   182,   183,   184,    -1,   186,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
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
      -1,   319,   320,   321,   322,   323,    -1,   325,    21,    22,
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
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,   317,    -1,   319,   320,   321,   322,
     323,    -1,   325,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
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
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,   317,
      -1,   319,   320,   321,   322,   323,    -1,   325,    21,    22,
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
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,   317,    -1,   319,   320,   321,   322,
     323,    -1,   325,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
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
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,   317,
      -1,   319,   320,   321,   322,   323,    -1,   325,    21,    22,
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
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,   317,    -1,   319,   320,   321,   322,
     323,    -1,   325,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
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
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,   317,
      -1,   319,   320,   321,   322,   323,    -1,   325,    21,    22,
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
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,   317,    -1,   319,   320,   321,   322,
     323,    -1,   325,    21,    22,    23,    24,    25,    26,    -1,
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
     188,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
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
      -1,   319,   320,   321,   322,   323,    -1,   325,    21,    22,
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
     183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,    -1,   319,   320,   321,   322,
     323,    -1,   325,    21,    22,    23,    24,    25,    26,    -1,
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
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,   317,
     318,   319,   320,   321,   322,   323,    -1,   325,    21,    22,
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
     183,   184,    -1,   186,    -1,   188,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,   317,    -1,   319,   320,   321,   322,
     323,    -1,   325,    21,    22,    23,    24,    25,    26,    -1,
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
     188,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
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
      -1,   319,   320,   321,   322,   323,    -1,   325,    21,    22,
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
     183,   184,    -1,    -1,    -1,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,   317,    -1,   319,   320,   321,   322,
     323,    -1,   325,    21,    22,    23,    24,    25,    26,    -1,
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
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,   317,
      -1,   319,   320,   321,   322,   323,    -1,   325,    21,    22,
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
     183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,   317,    -1,   319,   320,   321,   322,
     323,    -1,   325,    21,    22,    23,    24,    25,    26,    -1,
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
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,   317,
      -1,   319,   320,   321,   322,   323,    -1,   325,    21,    22,
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
     153,   154,   155,   156,    -1,   158,   159,    -1,   161,   162,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,   176,    -1,    -1,    -1,    -1,    -1,   182,
     183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,   215,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
      -1,   264,   265,   266,    -1,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,   317,    -1,   319,   320,   321,   322,
     323,    -1,   325,    25,    26,    -1,    -1,    -1,    -1,    -1,
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
     152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,    -1,    -1,   217,   218,   219,    -1,    -1,
      -1,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,    -1,    -1,    25,    26,   319,   320,   321,
     322,   323,   324,   325,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
     150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,    -1,
      -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,    -1,    -1,   217,   218,   219,
      -1,    -1,    -1,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,    -1,    -1,    25,    26,   319,
     320,   321,   322,   323,   324,   325,    34,    35,    -1,    37,
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
     218,   219,    -1,    -1,    -1,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,    -1,    -1,    25,
      26,   319,   320,   321,   322,   323,   324,   325,    34,    35,
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
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,   218,   219,    -1,    -1,    -1,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,    -1,
      -1,    25,    26,   319,   320,   321,   322,   323,   324,   325,
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
     214,    -1,    -1,   217,   218,   219,    -1,    -1,    -1,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,    -1,    -1,    25,    26,   319,   320,   321,   322,   323,
     324,   325,    34,    35,    -1,    37,    38,    39,    40,    41,
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
     152,   153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,    -1,    -1,   217,   218,   219,    -1,    -1,
      -1,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,    -1,    -1,    25,    26,   319,   320,   321,
     322,   323,   324,   325,    34,    35,    -1,    37,    38,    39,
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
      -1,    -1,    -1,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,    -1,    -1,    25,    26,   319,
     320,   321,   322,   323,    -1,   325,    34,    35,    -1,    37,
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
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,
     218,   219,    -1,    -1,    -1,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,    -1,   264,   265,   266,    -1,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,    -1,    -1,    25,
      26,   319,   320,   321,   322,   323,    -1,   325,    34,    35,
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
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,   218,   219,    -1,    -1,    -1,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,    -1,
      -1,    25,    26,   319,   320,   321,   322,   323,    -1,   325,
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
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,    -1,    -1,   217,   218,   219,    -1,    -1,    -1,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,    -1,
     264,   265,   266,    -1,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,    -1,    -1,    25,    26,   319,   320,   321,   322,   323,
      -1,   325,    34,    35,    -1,    37,    38,    39,    -1,    41,
      42,    43,    44,    -1,    -1,    47,    48,    -1,    50,    51,
      52,    53,    -1,    55,    -1,    57,    58,    59,    60,    -1,
      62,    -1,    -1,    65,    66,    67,    68,    69,    -1,    71,
      -1,    73,    -1,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    -1,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,
     152,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,   214,    -1,    -1,   217,   218,   219,    -1,    -1,
      -1,   223,   224,   225,   226,   227,   228,   229,    -1,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,    -1,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,    -1,   264,   265,   266,    -1,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,    -1,    -1,    -1,    -1,   319,   320,   321,
     322,   323,    -1,   325
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
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     264,   265,   266,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   317,   319,   320,   321,   322,   323,   325,   326,   327,
     341,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   362,   363,
     364,   365,   366,   367,   371,   372,   373,   377,   379,   380,
     382,   389,   391,   394,   395,   396,   398,   399,   400,   401,
     402,   404,   405,   407,   408,   409,   410,   411,   412,   414,
     415,   418,   419,   420,   421,   426,   428,   430,   431,   432,
     437,   456,   459,   463,   466,   467,   473,   474,   475,   476,
     478,   479,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   491,   492,   493,   494,   497,   498,   499,   500,   501,
     502,   503,   506,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   520,   521,   522,   536,   537,   539,   540,
     541,   542,   543,   544,   545,   546,   567,   568,   569,   570,
     575,   576,   577,   578,   579,   580,   583,   641,   642,   643,
     644,   646,   647,   648,   649,   650,   657,   658,   659,    34,
      35,    50,   217,   397,   398,   399,   397,   397,   398,   399,
     158,   158,    38,    39,    41,    42,    48,    58,    59,    76,
      81,   113,   114,   115,   162,   225,   266,   292,   300,   308,
     378,   379,   383,   384,   385,   162,   155,   155,   155,   158,
     386,   158,    25,    35,    62,   120,   278,   436,   438,   439,
     155,   120,   155,   158,   158,    78,   155,   226,   227,   155,
     120,   406,    40,    44,    46,    47,    48,    49,    52,    61,
      69,    72,    74,    75,    77,    99,   114,   137,   162,   171,
     204,   229,   231,   233,   234,   241,   243,   244,   245,   248,
     249,   262,   320,   657,   658,   120,    16,   186,   397,   399,
     419,   645,   656,   657,    49,    74,    75,   120,   155,   187,
     249,   418,   420,   430,   189,   418,   657,   155,   155,   656,
     657,    18,    19,   657,   155,    31,   216,   218,   230,   232,
     319,   230,   232,   319,   230,   319,   230,   235,   319,   120,
     246,   246,   247,   158,   155,   401,   316,   418,   318,   418,
     319,   327,   343,   343,     0,   345,   346,    34,    50,   348,
     365,     1,   192,   342,   192,   342,   114,   380,   400,   418,
     109,   192,   109,   342,   192,    43,    47,    52,    71,   170,
     173,   188,   214,   262,   413,   422,   427,   428,   429,   444,
     445,   449,     1,     3,    68,    73,   120,   423,   169,    94,
     134,   142,   143,   145,   153,   157,   159,   164,   181,   205,
     206,   207,   208,   209,   210,   495,   496,   254,   101,   160,
     178,   201,   119,   148,   161,   196,   203,   212,   138,   152,
      51,   202,   103,   104,   160,   178,   493,   195,   155,   500,
     121,   156,   158,   507,   508,   147,   158,   186,   186,   186,
     186,   381,   510,   381,    30,   655,   184,   198,   184,   198,
     168,   184,   658,   657,   171,   204,    48,   657,   154,   120,
      46,    48,    81,   108,   170,   656,   226,   227,   228,   251,
     614,   657,   657,   309,   139,   144,   114,   292,   300,   383,
     656,   398,   398,   418,   120,   189,   387,   388,   155,   403,
     418,     1,   162,   655,   115,   162,   361,   655,   657,   120,
     144,   109,   418,   457,   458,   657,   398,   418,   418,   565,
     657,   398,   155,   155,   418,   657,   144,   457,   186,   186,
     123,   109,   186,   123,   158,   158,   158,   657,   155,   187,
     188,   189,    36,   524,   525,   526,   418,   418,     8,   177,
      17,   418,   216,    30,   419,   419,   506,   419,   419,   419,
     645,   419,   506,   419,   236,   235,   581,   582,   657,   192,
     192,   419,   418,   399,   418,   250,   416,   417,   316,   318,
     419,   343,   192,   342,   192,   342,     3,   349,   365,   395,
       1,   349,   365,   395,    34,   366,   395,   366,   395,   406,
     342,   406,   419,   419,   120,   170,   172,   172,   400,   419,
     419,   433,   434,   657,   289,   289,   433,   120,   440,   475,
     476,   478,   478,   478,   478,   477,   478,   478,   478,    72,
     479,   483,   483,   482,   484,   484,   484,   484,   485,   485,
     486,   486,   236,    96,    96,    96,   501,   186,   418,   196,
     513,   514,   567,   656,   418,   189,   419,   519,   508,   151,
     189,   519,   109,   189,   189,   109,   109,   386,    30,   658,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     368,   369,   370,    96,   139,   144,   374,   375,   376,   657,
     162,   162,   368,   655,   129,   134,    56,    58,   102,   256,
     269,   271,   282,   283,   284,   286,   288,   615,   616,   617,
     618,   619,   620,   627,   633,   634,   251,    96,   304,   657,
     144,   419,   120,   657,   657,   134,   186,   186,   186,   657,
      96,   109,   189,   397,   189,   656,    98,    46,   656,   655,
      98,    96,   144,   547,   657,   419,   439,   186,   109,   190,
     149,   547,   186,   189,   189,   155,   186,   398,   398,   186,
     144,   547,   419,   190,   419,   419,   656,   419,   418,   418,
     418,   657,   525,   526,   132,   199,   186,   186,   186,   133,
     192,    96,   223,   224,   238,    96,   223,   224,   238,   238,
     238,    96,    96,   242,   230,   236,   109,   240,   144,   192,
     189,   418,   186,    11,    12,    20,   196,   504,   505,   587,
     657,   417,   238,   365,    34,    34,   192,   342,   192,   115,
     400,   657,   172,   419,   450,   451,   120,   446,   447,   109,
      37,    98,   149,   435,   436,   547,   657,    57,   219,   259,
     424,   425,   478,   155,   158,   264,   499,   510,   588,   591,
     592,   593,   594,   595,   599,   601,   603,   604,    40,    45,
      46,    48,    54,    61,    63,    64,    72,    99,   154,   158,
     213,   230,   322,   323,   324,   325,   548,   550,   552,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     571,   572,   573,   574,   651,   652,   653,   654,   657,   548,
     490,   553,   657,   490,   186,   187,   109,   189,   189,   510,
     150,   167,   150,   167,   139,   403,   386,   369,   134,   550,
     376,   419,   547,   655,   655,   130,   131,   655,   282,   283,
     284,   288,   657,   268,   279,   268,   279,    30,   291,    98,
     115,   158,   621,   624,   615,    40,    45,    46,    54,    61,
      63,    64,    72,    99,   230,   322,   323,   390,   554,   651,
     232,   304,   313,   419,   657,    96,   304,   655,   155,   547,
     548,   388,    96,   186,   200,   134,   360,   655,   162,   134,
      98,   360,   548,   419,   144,   436,   155,   120,   419,   419,
     149,   102,   460,   461,   462,   464,   465,   102,   468,   469,
     470,   471,   398,   186,   186,   155,   419,   144,   192,   419,
     123,   123,   189,   189,   189,    36,   526,   132,   199,     9,
      10,   105,   125,   127,   155,   197,   521,   523,   534,   535,
     538,   155,    30,   237,   239,   419,   419,   419,   237,   239,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   506,
     120,   419,   419,    49,    74,    75,   249,   400,   420,   430,
     250,   584,   585,   155,   212,   401,   419,   192,   115,   395,
     395,   395,   450,    97,   108,   118,   129,   452,   453,   454,
     455,   109,   657,   109,   120,   434,   129,   120,   419,   149,
     436,   149,    37,   149,   435,   436,   149,   547,   259,    55,
      60,    79,   120,   435,   441,   442,   443,   425,   418,   588,
     595,   155,   290,   480,   640,    98,   171,   257,   258,   260,
     267,   277,   289,   589,   590,   609,   610,   611,   612,   635,
     638,   263,   265,   596,   614,   272,   600,   636,   252,   253,
     275,   605,   606,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   550,   158,   158,   158,   158,   158,
     146,   178,   196,   549,   146,   419,   139,   403,   567,   375,
     291,    30,    98,   115,   158,   628,    30,   621,   549,   549,
     501,   292,   311,   547,   390,   232,   192,   397,   548,   400,
     419,   655,   109,   360,   419,   144,   397,   458,   419,   419,
     115,   461,   462,   102,   188,   115,   462,   465,   120,   472,
     548,   102,   115,   469,   102,   115,   471,   186,   397,   419,
     419,   419,   200,   468,   134,   197,   523,     7,   398,   657,
     197,   534,   398,   192,   238,   238,   238,   238,    98,   242,
     242,   582,   188,   158,   158,   158,   188,   587,   585,   504,
     655,   130,   131,   454,   455,   455,   451,   108,   144,   448,
     547,   447,   434,   149,   435,   657,   419,   149,   419,   129,
     419,   149,   436,   149,   419,   149,   120,   120,   419,   657,
     443,    79,   186,   189,   588,   602,   255,   219,   259,   273,
     280,   639,    98,   261,   262,   637,   255,   592,   639,   482,
     609,   593,   149,   287,   597,   598,   637,   291,   608,    80,
     607,   189,   189,   563,   564,   189,   196,   657,   189,   196,
     548,   551,   189,    30,   189,   656,   657,   657,   189,   189,
     196,   657,   189,   189,   189,   189,   189,   189,   189,    30,
     138,   203,   630,   631,   632,    30,   629,   630,   276,   625,
     109,   622,   172,   657,   262,   501,   186,   128,   128,    98,
     655,   419,   186,   188,   188,   419,   400,   419,   188,   188,
     657,   188,   212,   120,   472,   120,   188,   120,   472,   188,
     186,   115,   526,   657,   197,   186,   526,   657,   186,   419,
     419,   419,   419,   321,   419,   419,   419,   418,   418,   418,
     155,   586,   455,   655,   419,   144,   419,   149,   419,   149,
     435,   419,   149,   419,   419,   657,   657,   442,   419,   186,
     484,    53,   131,   482,   482,   274,   281,   291,   613,   613,
     594,   155,   285,   189,   189,   109,   189,   109,   189,    96,
     189,   109,   189,   189,   189,   189,   189,   109,   189,   109,
     189,   628,   628,   632,   109,   189,    30,   626,   637,   623,
     624,   189,   392,   393,   501,   120,   230,   312,   292,   172,
     400,   419,   360,   419,   400,    96,   400,   419,   548,   657,
     188,   657,   419,   657,   188,   400,   120,    95,   185,   527,
     526,   657,   199,   526,   419,   189,   189,   189,   418,   448,
     419,   419,   419,   149,   419,    55,   482,   482,   201,   418,
     565,   566,   657,   565,   566,   548,   548,    96,   565,   565,
      30,   270,   109,   109,   455,   547,   657,   120,   230,   657,
     392,   472,    96,   188,    96,   657,     5,   135,   530,   531,
     533,   535,    29,   136,   528,   529,   532,   535,   199,   526,
     199,   200,   468,   186,   448,   419,   120,   482,   186,   189,
     189,   146,   189,   189,   548,   189,   189,   624,   393,   455,
     310,   657,   120,   230,   188,   472,   400,   419,   472,   188,
      95,   135,   533,   185,   136,   532,   199,   115,   657,   419,
     310,   657,   120,   400,   419,   188,   188,   120,   298,   310,
     657,   657,   311,   419,   311,   188,   501,   501,   201,   292,
     657,   230,   120,   657,   311,   501
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
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  jsoniq_parser::yyr1_[] =
  {
         0,   340,   341,   341,   341,   341,   342,   342,   342,   343,
     343,   343,   343,   344,   344,   345,   345,   345,   345,   345,
     345,   345,   345,   346,   346,   346,   346,   347,   348,   348,
     348,   349,   349,   349,   349,   349,   350,   350,   350,   350,
     350,   350,   350,   350,   351,   351,   352,   353,   354,   354,
     355,   355,   356,   356,   357,   357,   357,   357,   358,   358,
     358,   359,   359,   359,   359,   360,   360,   361,   361,   362,
     362,   362,   362,   363,   364,   364,   365,   365,   365,   366,
     366,   366,   366,   366,   366,   366,   366,   367,   367,   368,
     368,   369,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   371,   372,   373,   374,   374,   375,   375,   375,
     376,   377,   377,   377,   378,   378,   378,   378,   379,   379,
     380,   380,   380,   380,   381,   381,   382,   382,   383,   383,
     384,   384,   385,   385,   386,   386,   386,   386,   387,   387,
     388,   388,   389,   389,   389,   389,   390,   390,   390,   390,
     391,   391,   392,   392,   393,   393,   393,   393,   394,   394,
     394,   394,   395,   396,   396,   396,   397,   397,   397,   398,
     398,   399,   399,   399,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   401,   401,   402,   403,
     404,   405,   405,   405,   406,   406,   406,   406,   407,   408,
     409,   410,   411,   411,   412,   413,   414,   415,   416,   416,
     417,   418,   418,   418,   419,   419,   419,   419,   419,   419,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   421,   422,   423,   423,   424,   424,   424,   425,
     425,   426,   426,   427,   428,   428,   428,   429,   429,   429,
     429,   429,   430,   430,   431,   431,   431,   432,   432,   433,
     433,   433,   434,   434,   434,   434,   434,   434,   434,   434,
     434,   434,   434,   434,   435,   436,   437,   438,   438,   439,
     439,   439,   439,   440,   440,   441,   441,   441,   442,   442,
     442,   443,   443,   443,   444,   445,   446,   446,   447,   447,
     447,   447,   447,   447,   448,   449,   449,   450,   450,   451,
     451,   452,   452,   452,   452,   452,   452,   452,   453,   453,
     454,   454,   455,   456,   456,   457,   457,   458,   458,   459,
     460,   460,   461,   462,   462,   463,   464,   464,   465,   466,
     466,   467,   467,   468,   468,   469,   469,   470,   470,   471,
     471,   472,   472,   473,   474,   474,   475,   475,   476,   476,
     476,   476,   476,   477,   476,   476,   476,   476,   478,   478,
     479,   479,   480,   480,   481,   481,   482,   482,   482,   483,
     483,   483,   483,   483,   484,   484,   484,   485,   485,   485,
     486,   486,   487,   487,   488,   488,   489,   489,   490,   490,
     491,   491,   492,   492,   492,   492,   493,   493,   493,   494,
     494,   495,   495,   495,   495,   495,   495,   496,   496,   496,
     497,   497,   497,   497,   498,   498,   499,   499,   500,   500,
     500,   501,   502,   503,   504,   504,   505,   505,   505,   505,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   507,
     507,   508,   509,   509,   509,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   510,   510,   510,   510,
     511,   511,   511,   512,   512,   513,   514,   514,   515,   516,
     517,   518,   518,   519,   519,   520,   520,   521,   521,   521,
     522,   522,   522,   522,   522,   522,   523,   523,   524,   524,
     525,   526,   526,   527,   527,   528,   528,   529,   529,   529,
     529,   530,   530,   531,   531,   531,   531,   532,   532,   533,
     533,   534,   534,   534,   534,   535,   535,   535,   535,   536,
     536,   537,   537,   538,   539,   539,   539,   539,   539,   539,
     539,   540,   541,   541,   542,   542,   543,   544,   545,   545,
     546,   546,   547,   548,   548,   548,   549,   549,   549,   550,
     550,   550,   550,   550,   550,   550,   551,   551,   552,   553,
     554,   554,   554,   554,   554,   554,   554,   554,   554,   554,
     555,   556,   556,   556,   557,   558,   559,   560,   560,   560,
     561,   561,   561,   561,   561,   562,   563,   563,   563,   563,
     563,   563,   563,   564,   565,   566,   567,   568,   568,   569,
     570,   571,   571,   572,   573,   573,   574,   575,   575,   575,
     576,   576,   576,   576,   576,   576,   576,   576,   576,   576,
     577,   577,   578,   578,   579,   580,   581,   581,   582,   583,
     584,   584,   585,   586,   587,   587,   588,   589,   589,   590,
     590,   591,   591,   592,   592,   593,   593,   594,   594,   595,
     596,   596,   597,   597,   598,   599,   599,   599,   600,   600,
     601,   602,   602,   603,   604,   604,   605,   605,   606,   606,
     606,   607,   607,   608,   608,   609,   609,   609,   609,   609,
     610,   611,   612,   613,   613,   613,   614,   614,   615,   615,
     615,   615,   615,   615,   615,   615,   616,   616,   616,   616,
     617,   617,   618,   619,   619,   620,   620,   620,   621,   621,
     622,   622,   623,   623,   624,   625,   625,   626,   626,   627,
     627,   627,   628,   628,   629,   629,   630,   630,   631,   631,
     632,   632,   633,   634,   634,   635,   635,   635,   636,   637,
     637,   637,   637,   638,   638,   639,   639,   640,   641,   641,
     642,   642,   643,   643,   644,   645,   645,   645,   645,   646,
     646,   646,   647,   648,   649,   650,   651,   651,   651,   652,
     653,   654,   655,   656,   656,   657,   657,   657,   657,   657,
     657,   657,   657,   657,   657,   657,   657,   657,   657,   657,
     657,   657,   658,   658,   658,   658,   658,   658,   658,   658,
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
     658,   658,   658,   658,   658,   658,   658,   659
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
       1,     1,     1,     2,     3,     3,     2,     1,     1,     1,
       4,     3,     3,     5,     4,     6,     4,     6,     5,     7,
       4,     5,     5,     6,     3,     3,     2,     1,     3,     4,
       5,     3,     6,     4,     5,     1,     2,     3,     1,     2,
       1,     6,     3,     3,     2,     3,     1,     3,     2,     4,
       5,     6,     5,     3,     2,     3,     4,     1,     3,     1,
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
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     4,     3,     3,     3,     3,     3,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     1,     4,
       4,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       4,     8,     5,     9,     9,    10,     1,     2,     1,     2,
       6,     0,     1,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     7,     3,     7,     4,     4,     3,     7,
       3,     7,     2,     1,     2,     3,     1,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     4,     3,     3,     3,     3,     4,     4,
       3,     4,     6,     4,     6,     4,     3,     4,     6,     6,
       4,     6,     6,     4,     1,     2,     1,     1,     1,     3,
       3,     1,     1,     4,     5,     6,     3,     3,     3,     3,
       5,     7,     7,     5,     5,     5,     7,     7,     5,     5,
       3,     3,     5,     7,     5,     7,     1,     4,     3,     5,
       1,     2,     3,     3,     1,     3,     2,     0,     1,     1,
       2,     1,     3,     1,     3,     1,     4,     1,     2,     3,
       0,     1,     0,     1,     4,     2,     3,     1,     0,     1,
       4,     0,     1,     2,     1,     3,     0,     1,     2,     2,
       1,     0,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       2,     2,     3,     1,     2,     2,     5,     2,     1,     1,
       0,     2,     1,     3,     4,     0,     2,     0,     2,     4,
       4,     3,     2,     3,     1,     3,     0,     1,     1,     2,
       2,     2,     2,     1,     2,     2,     2,     2,     3,     2,
       3,     3,     4,     2,     2,     1,     1,     3,     2,     3,
       2,     3,     2,     3,     3,     3,     3,     5,     5,     5,
       5,     8,     5,     3,     5,     7,     1,     1,     1,     1,
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
  "\"'xquery'\"", "\"'version'\"", "\"'start'\"", "\"'null'\"",
  "\"'true'\"", "\"'false'\"", "\"'after'\"", "\"'before'\"",
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
  "MULTIPLICATIVE_REDUCE", "JSONLOOKUPEXPR_REDUCE", "$accept", "Module",
  "ERROR", "ModuleWithoutBOM", "VersionDecl", "MainModule",
  "LibraryModule", "ModuleDecl", "SIND_DeclList", "SIND_Decl", "Setter",
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
  "FLWORClauseList", "ForClause", "ForOrFrom", "VarInDeclList",
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
  "PathExpr", "RelativePathExpr", "StepExpr", "NameTest", "Wildcard",
  "FilterExpr", "PredicateList", "Predicate", "PrimaryExpr", "Literal",
  "NumericLiteral", "BooleanLiteral", "VarRef", "ParenthesizedExpr",
  "ContextItemExpr", "OrderedExpr", "UnorderedExpr", "FunctionCall",
  "ArgList", "Constructor", "DirectConstructor", "DirElemConstructor",
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
  "SimpleType", "KindTest", "AnyKindTest", "DocumentTest", "NamespaceTest",
  "TextTest", "CommentTest", "PITest", "AttributeTest",
  "SchemaAttributeTest", "ElementTest", "SchemaElementTest", "TypeName",
  "TypeName_WITH_HOOK", "StringLiteral", "FunctionItemExpr",
  "LiteralFunctionItem", "InlineFunction", "FunctionTest",
  "AnyFunctionTest", "TypedFunctionTest", "ParenthesizedItemType",
  "RevalidationDecl", "InsertExpr", "DeleteExpr", "ReplaceExpr",
  "RenameExpr", "TransformExpr", "VarNameList", "VarNameDecl", "TryExpr",
  "CatchListExpr", "CatchExpr", "BracedExpr", "NameTestList",
  "FTSelection", "opt_FTPosFilter_list", "FTPosFilter_list", "FTOr",
  "FTAnd", "FTMildNot", "FTUnaryNot", "FTPrimaryWithOptions",
  "opt_FTMatchOptions", "opt_FTWeight", "FTWeight", "FTPrimary",
  "opt_FTTimes", "FTExtensionSelection", "opt_FTSelection", "FTWords",
  "FTWordsValue", "opt_FTAnyallOption", "FTAnyallOption", "opt_word",
  "opt_words", "FTPosFilter", "FTOrder", "FTWindow", "FTDistance",
  "FTUnit", "FTMatchOptions", "FTMatchOption", "FTCaseOption",
  "FTDiacriticsOption", "FTExtensionOption", "FTStemOption",
  "FTThesaurusOption", "FTThesaurusID_or_default", "opt_FTThesaurus_list",
  "FTThesaurus_list", "FTThesaurusID", "opt_relationship", "opt_levels",
  "FTStopWordOption", "FTStopWords", "STRING_LITERAL_list",
  "opt_FTStopWordsInclExcl_list", "FTStopWordsInclExcl_list",
  "FTStopWordsInclExcl", "FTLanguageOption", "FTWildCardOption",
  "FTContent", "FTTimes", "FTRange", "FTScope", "FTBigUnit",
  "FTIgnoreOption", "JSONArrayConstructor", "JSONSimpleObjectUnion",
  "JSONAccumulatorObjectUnion", "JSONObjectConstructor", "JSONPairList",
  "JSONInsertExpr", "JSONAppendExpr", "JSONDeleteExpr", "JSONRenameExpr",
  "JSONReplaceExpr", "JSONTest", "JSONItemTest", "JSONObjectTest",
  "JSONArrayTest", "URI_LITERAL", "NCNAME", "QNAME", "FUNCTION_NAME",
  "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const jsoniq_parser::rhs_number_type
  jsoniq_parser::yyrhs_[] =
  {
       341,     0,    -1,   343,    -1,   326,   343,    -1,   327,   343,
      -1,   326,   327,   343,    -1,     1,    -1,     1,     3,    -1,
     342,     1,    -1,   345,    -1,   344,   345,    -1,   346,    -1,
     344,   346,    -1,   217,   218,    30,   192,    -1,   217,   218,
      30,   133,    30,   192,    -1,   348,   192,   395,    -1,   365,
     192,   395,    -1,   348,   192,   365,   192,   395,    -1,   395,
      -1,   348,   342,   395,    -1,   365,   342,   395,    -1,   348,
     192,   365,   342,   395,    -1,   348,   342,   365,   192,   395,
      -1,   347,    -1,   347,   348,   192,    -1,   347,   365,   192,
      -1,   347,   348,   192,   365,   192,    -1,    35,   162,   656,
     134,   655,   192,    -1,   349,    -1,   348,   192,   349,    -1,
     348,   342,   349,    -1,   350,    -1,   358,    -1,   363,    -1,
     364,    -1,   372,    -1,   351,    -1,   352,    -1,   353,    -1,
     354,    -1,   355,    -1,   356,    -1,   357,    -1,   575,    -1,
      34,    39,   184,    -1,    34,    39,   198,    -1,    34,   115,
     108,   655,    -1,    34,    38,   655,    -1,    34,    41,   184,
      -1,    34,    41,   198,    -1,    34,    59,   171,    -1,    34,
      59,   204,    -1,    34,   115,   170,   129,   130,    -1,    34,
     115,   170,   129,   131,    -1,    34,    42,   184,   109,   150,
      -1,    34,    42,   184,   109,   167,    -1,    34,    42,   168,
     109,   150,    -1,    34,    42,   168,   109,   167,    -1,   359,
      -1,   362,    -1,    50,    25,     1,    -1,    50,    62,   655,
      -1,    50,    62,   361,   655,    -1,    50,    62,   655,    98,
     360,    -1,    50,    62,   361,   655,    98,   360,    -1,   655,
      -1,   360,   109,   655,    -1,   162,   656,   134,    -1,   115,
      46,   162,    -1,    50,    35,   655,    -1,    50,    35,   162,
     656,   134,   655,    -1,    50,    35,   655,    98,   360,    -1,
      50,    35,   162,   656,   134,   655,    98,   360,    -1,    34,
     162,   656,   134,   655,    -1,    34,   115,    46,   162,   655,
      -1,    34,   115,    48,   162,   655,    -1,   366,    -1,   365,
     192,   366,    -1,   365,   342,   366,    -1,   367,    -1,   371,
      -1,   373,    -1,   377,    -1,   382,    -1,   389,    -1,   391,
      -1,   394,    -1,    34,   115,    81,   368,    -1,    34,    81,
     657,   368,    -1,   369,    -1,   368,   369,    -1,   370,   134,
     567,    -1,    82,    -1,    90,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    91,    -1,    87,    -1,    88,    -1,
      89,    -1,    34,    58,   657,    30,    -1,    34,   266,   614,
      -1,    34,   113,   154,   374,    -1,    96,   550,   375,    -1,
     375,    -1,   376,    -1,   139,    -1,   139,   376,    -1,   144,
     419,    -1,    34,   378,   144,   419,    -1,    34,   378,   139,
      -1,    34,   378,   139,   144,   419,    -1,   114,   120,   657,
      -1,   114,   120,   657,   547,    -1,   379,   114,   120,   657,
      -1,   379,   114,   120,   657,   547,    -1,   380,    -1,   379,
     380,    -1,    27,    -1,    27,   158,   381,   189,    -1,    28,
      -1,    28,   158,   381,   189,    -1,   510,    -1,   381,   109,
     510,    -1,    34,   383,    -1,    34,   379,   383,    -1,   384,
      -1,   385,    -1,    48,   658,   386,   403,    -1,    48,   658,
     386,   139,    -1,    76,    48,   658,   386,   403,    -1,    76,
      48,   658,   386,   139,    -1,   158,   189,    -1,   158,   387,
     189,    -1,   158,   189,    96,   548,    -1,   158,   387,   189,
      96,   548,    -1,   388,    -1,   387,   109,   388,    -1,   120,
     657,    -1,   120,   657,   547,    -1,    34,   292,   657,    -1,
      34,   292,   657,    96,   390,    -1,    34,   379,   292,   657,
      -1,    34,   379,   292,   657,    96,   390,    -1,   554,    -1,
     554,   549,    -1,   651,    -1,   651,   549,    -1,    34,   300,
     657,   304,   232,   501,   172,   392,    -1,    34,   379,   300,
     657,   304,   232,   501,   172,   392,    -1,   393,    -1,   392,
     109,   393,    -1,   501,    -1,   501,   547,    -1,   501,   455,
      -1,   501,   547,   455,    -1,    34,   308,   309,   657,   304,
     292,   657,   120,   657,   310,   419,    -1,    34,   308,   309,
     657,   304,   292,   657,   230,   120,   657,   310,   298,   311,
     501,    -1,    34,   308,   309,   657,   304,   292,   657,   312,
     230,   120,   657,   310,   419,    -1,    34,   308,   309,   657,
     313,   311,   262,   292,   657,   230,   120,   657,   311,   501,
     201,   292,   657,   230,   120,   657,   311,   501,    -1,   396,
      -1,   398,    -1,   399,    -1,    -1,   398,    -1,   399,    -1,
      -1,   418,    -1,   399,   418,    -1,   400,    -1,   399,   400,
      -1,   399,   418,   342,   400,    -1,   401,    -1,   404,    -1,
     407,    -1,   408,    -1,   409,    -1,   410,    -1,   411,    -1,
     412,    -1,   414,    -1,   467,    -1,   463,    -1,   415,    -1,
     155,   399,   186,    -1,   155,   186,    -1,   155,   397,   186,
      -1,   155,   397,   186,    -1,   405,   192,    -1,   405,   109,
     406,    -1,   114,   406,    -1,   379,   114,   406,    -1,   120,
     657,    -1,   120,   657,   547,    -1,   120,   657,   144,   419,
      -1,   120,   657,   547,   144,   419,    -1,   120,   657,   144,
     419,   192,    -1,   420,   192,    -1,   245,   247,   419,   192,
      -1,   248,   158,   418,   189,   400,    -1,   243,   246,   192,
      -1,   244,   246,   192,    -1,   430,   413,    -1,   188,   400,
      -1,    49,   158,   418,   189,   200,   400,   128,   400,    -1,
     249,   401,   416,    -1,   417,    -1,   416,   417,    -1,   250,
     587,   401,    -1,   419,    -1,   418,   109,   419,    -1,   418,
     342,   419,    -1,   421,    -1,   459,    -1,   466,    -1,   473,
      -1,   583,    -1,   420,    -1,   474,    -1,   456,    -1,   576,
      -1,   577,    -1,   579,    -1,   578,    -1,   580,    -1,   648,
      -1,   646,    -1,   649,    -1,   650,    -1,   647,    -1,   430,
     422,    -1,   188,   419,    -1,    68,   289,    -1,    73,   289,
      -1,   219,    -1,   259,    -1,    57,   259,    -1,   424,   441,
      79,   419,    -1,   424,    79,   419,    -1,   432,   423,   440,
     425,   425,    -1,   432,   423,   440,   425,    -1,    43,   120,
     657,    -1,   431,    -1,   437,    -1,   426,    -1,   428,    -1,
     444,    -1,   449,    -1,   445,    -1,   427,    -1,   428,    -1,
     430,   429,    -1,   432,   120,   433,    -1,   432,     1,   433,
      -1,   432,     3,    -1,    47,    -1,   262,    -1,   434,    -1,
     433,   109,   120,   434,    -1,   433,   109,   434,    -1,   657,
     149,   419,    -1,   657,    37,   129,   149,   419,    -1,   657,
     547,   149,   419,    -1,   657,   547,    37,   129,   149,   419,
      -1,   657,   435,   149,   419,    -1,   657,    37,   129,   435,
     149,   419,    -1,   657,   547,   435,   149,   419,    -1,   657,
     547,    37,   129,   435,   149,   419,    -1,   657,   436,   149,
     419,    -1,   657,   547,   436,   149,   419,    -1,   657,   435,
     436,   149,   419,    -1,   657,   547,   435,   436,   149,   419,
      -1,    98,   120,   657,    -1,   278,   120,   657,    -1,    52,
     438,    -1,   439,    -1,   438,   109,   439,    -1,   120,   657,
     144,   419,    -1,   120,   657,   547,   144,   419,    -1,   436,
     144,   419,    -1,   120,   657,   547,   436,   144,   419,    -1,
     120,   657,   149,   419,    -1,   120,   657,   547,   149,   419,
      -1,   442,    -1,   120,   657,    -1,   120,   657,   442,    -1,
     435,    -1,   435,   443,    -1,   443,    -1,    60,   120,   657,
      55,   120,   657,    -1,    55,   120,   657,    -1,    60,   120,
     657,    -1,   214,   419,    -1,   173,   172,   446,    -1,   447,
      -1,   446,   109,   447,    -1,   120,   657,    -1,   120,   657,
     144,   419,    -1,   120,   657,   547,   144,   419,    -1,   120,
     657,   547,   144,   419,   448,    -1,   120,   657,   144,   419,
     448,    -1,   120,   657,   448,    -1,   108,   655,    -1,   170,
     172,   450,    -1,    71,   170,   172,   450,    -1,   451,    -1,
     450,   109,   451,    -1,   419,    -1,   419,   452,    -1,   453,
      -1,   454,    -1,   455,    -1,   453,   454,    -1,   453,   455,
      -1,   454,   455,    -1,   453,   454,   455,    -1,    97,    -1,
     118,    -1,   129,   130,    -1,   129,   131,    -1,   108,   655,
      -1,    69,   120,   457,   190,   419,    -1,   137,   120,   457,
     190,   419,    -1,   458,    -1,   457,   109,   120,   458,    -1,
     657,   149,   419,    -1,   657,   547,   149,   419,    -1,    74,
     158,   418,   189,   460,   115,   188,   419,    -1,   461,    -1,
     460,   461,    -1,   462,   188,   419,    -1,   102,   419,    -1,
     462,   102,   419,    -1,    74,   158,   418,   189,   464,   115,
     188,   400,    -1,   465,    -1,   464,   465,    -1,   462,   188,
     400,    -1,    75,   158,   418,   189,   468,   115,   188,   419,
      -1,    75,   158,   418,   189,   468,   115,   120,   657,   188,
     419,    -1,    75,   158,   418,   189,   470,   115,   188,   400,
      -1,    75,   158,   418,   189,   468,   115,   120,   657,   188,
     400,    -1,   469,    -1,   468,   469,    -1,   102,   472,   188,
     419,    -1,   102,   120,   657,    96,   472,   188,   419,    -1,
     471,    -1,   470,   471,    -1,   102,   472,   188,   400,    -1,
     102,   120,   657,    96,   472,   188,   400,    -1,   548,    -1,
     472,   212,   548,    -1,    49,   158,   418,   189,   200,   419,
     128,   419,    -1,   475,    -1,   474,   169,   475,    -1,   476,
      -1,   475,    94,   476,    -1,   478,    -1,   478,   495,   478,
      -1,   478,   496,   478,    -1,   478,   134,   478,    -1,   478,
     164,   478,    -1,    -1,   478,   159,   477,   478,    -1,   478,
     157,   478,    -1,   478,   145,   478,    -1,   478,   143,   478,
      -1,   479,    -1,   479,   254,    72,   588,   480,    -1,   481,
      -1,   481,   101,   479,    -1,    -1,   640,    -1,   482,    -1,
     482,   201,   482,    -1,   483,    -1,   482,   178,   483,    -1,
     482,   160,   483,    -1,   484,    -1,   483,   196,   484,    -1,
     483,   119,   484,    -1,   483,   148,   484,    -1,   483,   161,
     484,    -1,   485,    -1,   484,   203,   485,    -1,   484,   212,
     485,    -1,   486,    -1,   485,   152,   486,    -1,   485,   138,
     486,    -1,   487,    -1,   487,    51,   236,   548,    -1,   488,
      -1,   488,   202,    96,   548,    -1,   489,    -1,   489,   103,
      96,   490,    -1,   491,    -1,   491,   104,    96,   490,    -1,
     553,    -1,   553,   146,    -1,   493,    -1,   492,   493,    -1,
     178,    -1,   160,    -1,   492,   178,    -1,   492,   160,    -1,
     497,    -1,   494,    -1,   498,    -1,   501,    -1,   494,   195,
     501,    -1,   205,    -1,   210,    -1,   209,    -1,   208,    -1,
     207,    -1,   206,    -1,   153,    -1,   181,    -1,   142,    -1,
      77,   155,   398,   186,    -1,    77,   227,   155,   398,   186,
      -1,    77,   226,   155,   398,   186,    -1,    77,    78,   565,
     155,   398,   186,    -1,   499,   155,   186,    -1,   499,   155,
     418,   186,    -1,   500,    -1,   499,   500,    -1,   179,   657,
      17,    -1,   179,    18,    -1,   179,    19,    -1,   502,    -1,
     503,    -1,   506,    -1,   657,    -1,   505,    -1,   196,    -1,
      11,    -1,    12,    -1,    20,    -1,   509,    -1,   506,   507,
      -1,   506,   158,   189,    -1,   506,   158,   519,   189,    -1,
     506,   121,   656,    -1,   506,   121,   514,    -1,   506,   121,
     513,    -1,   506,   121,   567,    -1,   506,   121,   196,    -1,
     508,    -1,   507,   508,    -1,   156,   418,   187,    -1,   510,
      -1,   513,    -1,   514,    -1,   515,    -1,   518,    -1,   520,
      -1,   516,    -1,   517,    -1,   568,    -1,   402,    -1,   644,
      -1,   641,    -1,   642,    -1,   643,    -1,   511,    -1,   567,
      -1,   512,    -1,   220,    -1,   112,    -1,   151,    -1,   126,
      -1,   221,    -1,   222,    -1,   120,   657,    -1,   158,   189,
      -1,   158,   418,   189,    -1,   121,    -1,   171,   155,   418,
     186,    -1,   204,   155,   418,   186,    -1,   658,   158,   189,
      -1,   658,   158,   519,   189,    -1,   419,    -1,   519,   109,
     419,    -1,   521,    -1,   539,    -1,   522,    -1,   536,    -1,
     537,    -1,   159,   657,   526,   132,    -1,   159,   657,   526,
     199,   197,   657,   526,   199,    -1,   159,   657,   524,   526,
     132,    -1,   159,   657,   524,   526,   199,   197,   657,   526,
     199,    -1,   159,   657,   526,   199,   523,   197,   657,   526,
     199,    -1,   159,   657,   524,   526,   199,   523,   197,   657,
     526,   199,    -1,   534,    -1,   523,   534,    -1,   525,    -1,
     524,   525,    -1,    36,   657,   526,   134,   526,   527,    -1,
      -1,    36,    -1,   185,   528,   185,    -1,    95,   530,    95,
      -1,    -1,   529,    -1,   136,    -1,   532,    -1,   529,   136,
      -1,   529,   532,    -1,    -1,   531,    -1,   135,    -1,   533,
      -1,   531,   135,    -1,   531,   533,    -1,    29,    -1,   535,
      -1,     5,    -1,   535,    -1,   521,    -1,    10,    -1,   538,
      -1,   535,    -1,     9,    -1,   125,    -1,   127,    -1,   155,
     398,   186,    -1,   215,    31,   216,    -1,   215,   216,    -1,
     176,   656,   177,    -1,   176,   656,     8,    -1,   105,     7,
      -1,   540,    -1,   541,    -1,   542,    -1,   543,    -1,   544,
      -1,   545,    -1,   546,    -1,    44,   155,   398,   186,    -1,
      21,   397,   186,    -1,    46,   155,   418,   186,   155,   397,
     186,    -1,    22,   397,   186,    -1,    99,   155,   418,   186,
     155,   397,   186,    -1,    72,   155,   398,   186,    -1,    40,
     155,   398,   186,    -1,    23,   397,   186,    -1,    61,   155,
     418,   186,   155,   397,   186,    -1,    24,   398,   186,    -1,
     162,   155,   418,   186,   155,   398,   186,    -1,    96,   548,
      -1,   550,    -1,   550,   549,    -1,   213,   158,   189,    -1,
     146,    -1,   196,    -1,   178,    -1,   552,    -1,   554,    -1,
     154,   158,   189,    -1,   325,   158,   189,    -1,   571,    -1,
     574,    -1,   651,    -1,   548,    -1,   551,   109,   548,    -1,
     657,    -1,   657,    -1,   556,    -1,   563,    -1,   561,    -1,
     564,    -1,   562,    -1,   560,    -1,   559,    -1,   558,    -1,
     557,    -1,   555,    -1,   230,   158,   189,    -1,    45,   158,
     189,    -1,    45,   158,   563,   189,    -1,    45,   158,   564,
     189,    -1,    54,   158,   189,    -1,    72,   158,   189,    -1,
      40,   158,   189,    -1,    61,   158,   189,    -1,    61,   158,
     656,   189,    -1,    61,   158,    30,   189,    -1,    99,   158,
     189,    -1,    99,   158,   657,   189,    -1,    99,   158,   657,
     109,   565,   189,    -1,    99,   158,   196,   189,    -1,    99,
     158,   196,   109,   565,   189,    -1,    63,   158,   657,   189,
      -1,    46,   158,   189,    -1,    46,   158,   657,   189,    -1,
      46,   158,   657,   109,   565,   189,    -1,    46,   158,   657,
     109,   566,   189,    -1,    46,   158,   196,   189,    -1,    46,
     158,   196,   109,   565,   189,    -1,    46,   158,   196,   109,
     566,   189,    -1,    64,   158,   657,   189,    -1,   657,    -1,
     657,   146,    -1,    30,    -1,   569,    -1,   570,    -1,   657,
     147,   151,    -1,    48,   386,   403,    -1,   572,    -1,   573,
      -1,    48,   158,   196,   189,    -1,    48,   158,   189,    96,
     548,    -1,    48,   158,   551,   189,    96,   548,    -1,   158,
     550,   189,    -1,    34,   225,   226,    -1,    34,   225,   227,
      -1,    34,   225,   228,    -1,   231,   230,   419,   238,   419,
      -1,   231,   230,   419,    96,   237,   238,   419,    -1,   231,
     230,   419,    96,   239,   238,   419,    -1,   231,   230,   419,
     223,   419,    -1,   231,   230,   419,   224,   419,    -1,   231,
     232,   419,   238,   419,    -1,   231,   232,   419,    96,   237,
     238,   419,    -1,   231,   232,   419,    96,   239,   238,   419,
      -1,   231,   232,   419,   223,   419,    -1,   231,   232,   419,
     224,   419,    -1,   229,   230,   419,    -1,   229,   232,   419,
      -1,   234,   230,   419,   242,   419,    -1,   234,   235,   236,
     230,   419,   242,   419,    -1,   233,   230,   419,    96,   419,
      -1,   241,   120,   581,   240,   419,   188,   419,    -1,   582,
      -1,   581,   109,   120,   582,    -1,   657,   144,   419,    -1,
     249,   155,   418,   186,   584,    -1,   585,    -1,   584,   585,
      -1,   250,   587,   586,    -1,   155,   418,   186,    -1,   504,
      -1,   587,   212,   504,    -1,   591,   589,    -1,    -1,   590,
      -1,   609,    -1,   590,   609,    -1,   592,    -1,   591,   267,
     592,    -1,   593,    -1,   592,   263,   593,    -1,   594,    -1,
     593,   265,   149,   594,    -1,   595,    -1,   264,   595,    -1,
     599,   596,   597,    -1,    -1,   614,    -1,    -1,   598,    -1,
     287,   155,   418,   186,    -1,   603,   600,    -1,   158,   588,
     189,    -1,   601,    -1,    -1,   636,    -1,   499,   155,   602,
     186,    -1,    -1,   588,    -1,   604,   605,    -1,   510,    -1,
     155,   418,   186,    -1,    -1,   606,    -1,   253,   607,    -1,
     252,   608,    -1,   275,    -1,    -1,    80,    -1,    -1,   291,
      -1,   610,    -1,   611,    -1,   612,    -1,   638,    -1,   635,
      -1,   171,    -1,   289,   482,   613,    -1,   258,   637,   613,
      -1,   291,    -1,   281,    -1,   274,    -1,   251,   615,    -1,
     614,   251,   615,    -1,   616,    -1,   617,    -1,   618,    -1,
     633,    -1,   619,    -1,   627,    -1,   620,    -1,   634,    -1,
     102,   279,    -1,   102,   268,    -1,   271,    -1,   286,    -1,
     256,   279,    -1,   256,   268,    -1,    58,   657,    30,    -1,
     282,    -1,    56,   282,    -1,   284,   621,    -1,   284,   158,
     621,   622,   189,    -1,    56,   284,    -1,   624,    -1,   115,
      -1,    -1,   109,   623,    -1,   624,    -1,   623,   109,   624,
      -1,    98,    30,   625,   626,    -1,    -1,   276,    30,    -1,
      -1,   637,   270,    -1,   283,   291,   628,   630,    -1,   283,
     291,   115,   630,    -1,    56,   283,   291,    -1,    98,    30,
      -1,   158,   629,   189,    -1,    30,    -1,   629,   109,    30,
      -1,    -1,   631,    -1,   632,    -1,   631,   632,    -1,   203,
     628,    -1,   138,   628,    -1,   269,    30,    -1,   288,    -1,
      56,   288,    -1,    98,   219,    -1,    98,   259,    -1,   260,
     255,    -1,   272,   637,   285,    -1,   261,   482,    -1,    98,
     131,   482,    -1,    98,    53,   482,    -1,   262,   482,   201,
     482,    -1,   277,   639,    -1,   257,   639,    -1,   280,    -1,
     273,    -1,   290,   255,   484,    -1,   156,   187,    -1,   156,
     418,   187,    -1,   315,   316,    -1,   315,   418,   316,    -1,
     317,   318,    -1,   317,   418,   318,    -1,   155,   645,   186,
      -1,   656,   123,   419,    -1,   419,   123,   419,    -1,   645,
     109,   419,   123,   419,    -1,   645,   109,   656,   123,   419,
      -1,   231,   319,   419,   238,   419,    -1,   231,   319,   645,
     238,   419,    -1,   231,   319,   419,   238,   419,    98,   321,
     419,    -1,   320,   319,   419,   238,   419,    -1,   229,   319,
     506,    -1,   233,   319,   506,    96,   419,    -1,   234,   319,
     235,   236,   506,   242,   419,    -1,   652,    -1,   653,    -1,
     654,    -1,   324,    -1,   322,   158,   189,    -1,   323,   158,
     189,    -1,    30,    -1,    16,    -1,   657,    -1,   658,    -1,
      99,    -1,    40,    -1,    45,    -1,    54,    -1,    46,    -1,
     154,    -1,    49,    -1,   230,    -1,    61,    -1,    63,    -1,
      64,    -1,    72,    -1,    75,    -1,    74,    -1,   213,    -1,
     248,    -1,   659,    -1,    25,    -1,   217,    -1,   129,    -1,
      39,    -1,   266,    -1,    38,    -1,   227,    -1,   226,    -1,
     148,    -1,    44,    -1,   264,    -1,   265,    -1,   279,    -1,
     268,    -1,   256,    -1,   290,    -1,   282,    -1,   284,    -1,
     283,    -1,   288,    -1,   260,    -1,   255,    -1,    80,    -1,
     219,    -1,   259,    -1,    53,    -1,   228,    -1,   241,    -1,
     307,    -1,   235,    -1,   205,    -1,   210,    -1,   209,    -1,
     208,    -1,   207,    -1,   206,    -1,    98,    -1,   113,    -1,
     114,    -1,   188,    -1,    47,    -1,    37,    -1,    68,    -1,
      73,    -1,    60,    -1,    55,    -1,    57,    -1,    79,    -1,
      43,    -1,   149,    -1,    52,    -1,   214,    -1,   172,    -1,
     173,    -1,   170,    -1,    71,    -1,    97,    -1,   118,    -1,
     130,    -1,   131,    -1,   108,    -1,    69,    -1,   137,    -1,
     190,    -1,   102,    -1,    96,    -1,   200,    -1,   128,    -1,
     169,    -1,    94,    -1,    51,    -1,   236,    -1,   103,    -1,
     201,    -1,   119,    -1,   161,    -1,   203,    -1,   152,    -1,
     138,    -1,    77,    -1,    78,    -1,   104,    -1,   202,    -1,
     153,    -1,   184,    -1,   198,    -1,   162,    -1,   139,    -1,
     133,    -1,   168,    -1,   150,    -1,   167,    -1,    34,    -1,
      41,    -1,    59,    -1,   115,    -1,    42,    -1,    58,    -1,
     218,    -1,    50,    -1,    62,    -1,    35,    -1,    48,    -1,
     278,    -1,   254,    -1,   287,    -1,   289,    -1,   258,    -1,
     272,    -1,   285,    -1,   277,    -1,   257,    -1,   271,    -1,
     286,    -1,   276,    -1,   270,    -1,   269,    -1,   253,    -1,
     252,    -1,   261,    -1,   262,    -1,   291,    -1,   281,    -1,
     280,    -1,   275,    -1,   273,    -1,   274,    -1,   234,    -1,
     240,    -1,   237,    -1,   231,    -1,   224,    -1,   223,    -1,
     225,    -1,   242,    -1,   232,    -1,   233,    -1,   239,    -1,
     229,    -1,   238,    -1,    67,    -1,    65,    -1,    76,    -1,
     171,    -1,   204,    -1,   247,    -1,   245,    -1,   246,    -1,
     243,    -1,   244,    -1,   249,    -1,   250,    -1,   251,    -1,
      66,    -1,   300,    -1,   298,    -1,   299,    -1,   304,    -1,
     305,    -1,   306,    -1,   301,    -1,   302,    -1,   303,    -1,
      81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,
      86,    -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,
      91,    -1,   292,    -1,   293,    -1,   294,    -1,   295,    -1,
     296,    -1,   297,    -1,   308,    -1,   309,    -1,   310,    -1,
     311,    -1,   312,    -1,   313,    -1,   314,    -1,    92,    -1,
     107,    -1,   116,    -1,   174,    -1,   182,    -1,   191,    -1,
     140,    -1,    93,    -1,   117,    -1,   141,    -1,   183,    -1,
     319,    -1,   320,    -1,   321,    -1,   323,    -1,   322,    -1,
     325,    -1,    26,    -1
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
     904,   906,   908,   910,   913,   917,   921,   924,   926,   928,
     930,   935,   939,   943,   949,   954,   961,   966,   973,   979,
     987,   992,   998,  1004,  1011,  1015,  1019,  1022,  1024,  1028,
    1033,  1039,  1043,  1050,  1055,  1061,  1063,  1066,  1070,  1072,
    1075,  1077,  1084,  1088,  1092,  1095,  1099,  1101,  1105,  1108,
    1113,  1119,  1126,  1132,  1136,  1139,  1143,  1148,  1150,  1154,
    1156,  1159,  1161,  1163,  1165,  1168,  1171,  1174,  1178,  1180,
    1182,  1185,  1188,  1191,  1197,  1203,  1205,  1210,  1214,  1219,
    1228,  1230,  1233,  1237,  1240,  1244,  1253,  1255,  1258,  1262,
    1271,  1282,  1291,  1302,  1304,  1307,  1312,  1320,  1322,  1325,
    1330,  1338,  1340,  1344,  1353,  1355,  1359,  1361,  1365,  1367,
    1371,  1375,  1379,  1383,  1384,  1389,  1393,  1397,  1401,  1403,
    1409,  1411,  1415,  1416,  1418,  1420,  1424,  1426,  1430,  1434,
    1436,  1440,  1444,  1448,  1452,  1454,  1458,  1462,  1464,  1468,
    1472,  1474,  1479,  1481,  1486,  1488,  1493,  1495,  1500,  1502,
    1505,  1507,  1510,  1512,  1514,  1517,  1520,  1522,  1524,  1526,
    1528,  1532,  1534,  1536,  1538,  1540,  1542,  1544,  1546,  1548,
    1550,  1555,  1561,  1567,  1574,  1578,  1583,  1585,  1588,  1592,
    1595,  1598,  1600,  1602,  1604,  1606,  1608,  1610,  1612,  1614,
    1616,  1618,  1621,  1625,  1630,  1634,  1638,  1642,  1646,  1650,
    1652,  1655,  1659,  1661,  1663,  1665,  1667,  1669,  1671,  1673,
    1675,  1677,  1679,  1681,  1683,  1685,  1687,  1689,  1691,  1693,
    1695,  1697,  1699,  1701,  1703,  1705,  1708,  1711,  1715,  1717,
    1722,  1727,  1731,  1736,  1738,  1742,  1744,  1746,  1748,  1750,
    1752,  1757,  1766,  1772,  1782,  1792,  1803,  1805,  1808,  1810,
    1813,  1820,  1821,  1823,  1827,  1831,  1832,  1834,  1836,  1838,
    1841,  1844,  1845,  1847,  1849,  1851,  1854,  1857,  1859,  1861,
    1863,  1865,  1867,  1869,  1871,  1873,  1875,  1877,  1879,  1883,
    1887,  1890,  1894,  1898,  1901,  1903,  1905,  1907,  1909,  1911,
    1913,  1915,  1920,  1924,  1932,  1936,  1944,  1949,  1954,  1958,
    1966,  1970,  1978,  1981,  1983,  1986,  1990,  1992,  1994,  1996,
    1998,  2000,  2004,  2008,  2010,  2012,  2014,  2016,  2020,  2022,
    2024,  2026,  2028,  2030,  2032,  2034,  2036,  2038,  2040,  2042,
    2044,  2048,  2052,  2057,  2062,  2066,  2070,  2074,  2078,  2083,
    2088,  2092,  2097,  2104,  2109,  2116,  2121,  2125,  2130,  2137,
    2144,  2149,  2156,  2163,  2168,  2170,  2173,  2175,  2177,  2179,
    2183,  2187,  2189,  2191,  2196,  2202,  2209,  2213,  2217,  2221,
    2225,  2231,  2239,  2247,  2253,  2259,  2265,  2273,  2281,  2287,
    2293,  2297,  2301,  2307,  2315,  2321,  2329,  2331,  2336,  2340,
    2346,  2348,  2351,  2355,  2359,  2361,  2365,  2368,  2369,  2371,
    2373,  2376,  2378,  2382,  2384,  2388,  2390,  2395,  2397,  2400,
    2404,  2405,  2407,  2408,  2410,  2415,  2418,  2422,  2424,  2425,
    2427,  2432,  2433,  2435,  2438,  2440,  2444,  2445,  2447,  2450,
    2453,  2455,  2456,  2458,  2459,  2461,  2463,  2465,  2467,  2469,
    2471,  2473,  2477,  2481,  2483,  2485,  2487,  2490,  2494,  2496,
    2498,  2500,  2502,  2504,  2506,  2508,  2510,  2513,  2516,  2518,
    2520,  2523,  2526,  2530,  2532,  2535,  2538,  2544,  2547,  2549,
    2551,  2552,  2555,  2557,  2561,  2566,  2567,  2570,  2571,  2574,
    2579,  2584,  2588,  2591,  2595,  2597,  2601,  2602,  2604,  2606,
    2609,  2612,  2615,  2618,  2620,  2623,  2626,  2629,  2632,  2636,
    2639,  2643,  2647,  2652,  2655,  2658,  2660,  2662,  2666,  2669,
    2673,  2676,  2680,  2683,  2687,  2691,  2695,  2699,  2705,  2711,
    2717,  2723,  2732,  2738,  2742,  2748,  2756,  2758,  2760,  2762,
    2764,  2768,  2772,  2774,  2776,  2778,  2780,  2782,  2784,  2786,
    2788,  2790,  2792,  2794,  2796,  2798,  2800,  2802,  2804,  2806,
    2808,  2810,  2812,  2814,  2816,  2818,  2820,  2822,  2824,  2826,
    2828,  2830,  2832,  2834,  2836,  2838,  2840,  2842,  2844,  2846,
    2848,  2850,  2852,  2854,  2856,  2858,  2860,  2862,  2864,  2866,
    2868,  2870,  2872,  2874,  2876,  2878,  2880,  2882,  2884,  2886,
    2888,  2890,  2892,  2894,  2896,  2898,  2900,  2902,  2904,  2906,
    2908,  2910,  2912,  2914,  2916,  2918,  2920,  2922,  2924,  2926,
    2928,  2930,  2932,  2934,  2936,  2938,  2940,  2942,  2944,  2946,
    2948,  2950,  2952,  2954,  2956,  2958,  2960,  2962,  2964,  2966,
    2968,  2970,  2972,  2974,  2976,  2978,  2980,  2982,  2984,  2986,
    2988,  2990,  2992,  2994,  2996,  2998,  3000,  3002,  3004,  3006,
    3008,  3010,  3012,  3014,  3016,  3018,  3020,  3022,  3024,  3026,
    3028,  3030,  3032,  3034,  3036,  3038,  3040,  3042,  3044,  3046,
    3048,  3050,  3052,  3054,  3056,  3058,  3060,  3062,  3064,  3066,
    3068,  3070,  3072,  3074,  3076,  3078,  3080,  3082,  3084,  3086,
    3088,  3090,  3092,  3094,  3096,  3098,  3100,  3102,  3104,  3106,
    3108,  3110,  3112,  3114,  3116,  3118,  3120,  3122,  3124,  3126,
    3128,  3130,  3132,  3134,  3136,  3138,  3140,  3142,  3144,  3146,
    3148,  3150,  3152,  3154,  3156,  3158,  3160,  3162,  3164,  3166,
    3168,  3170,  3172,  3174,  3176,  3178,  3180,  3182,  3184,  3186,
    3188,  3190,  3192,  3194,  3196,  3198,  3200,  3202,  3204,  3206,
    3208,  3210,  3212,  3214,  3216,  3218,  3220,  3222
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  jsoniq_parser::yyrline_[] =
  {
         0,  1067,  1067,  1068,  1072,  1076,  1084,  1090,  1094,  1103,
    1109,  1117,  1123,  1134,  1139,  1147,  1154,  1161,  1170,  1177,
    1185,  1193,  1201,  1212,  1217,  1224,  1231,  1243,  1253,  1260,
    1267,  1279,  1280,  1281,  1282,  1283,  1288,  1289,  1290,  1291,
    1292,  1293,  1294,  1297,  1302,  1307,  1315,  1323,  1331,  1336,
    1344,  1349,  1357,  1362,  1370,  1375,  1380,  1385,  1393,  1395,
    1398,  1408,  1413,  1421,  1429,  1440,  1447,  1458,  1463,  1471,
    1478,  1485,  1494,  1507,  1515,  1522,  1532,  1539,  1546,  1557,
    1558,  1559,  1560,  1561,  1562,  1563,  1564,  1569,  1575,  1584,
    1591,  1601,  1611,  1612,  1613,  1614,  1615,  1616,  1617,  1618,
    1619,  1620,  1625,  1633,  1641,  1649,  1656,  1664,  1671,  1676,
    1684,  1692,  1706,  1720,  1737,  1742,  1750,  1758,  1769,  1774,
    1783,  1788,  1795,  1800,  1810,  1815,  1824,  1830,  1843,  1848,
    1856,  1867,  1882,  1894,  1909,  1914,  1919,  1924,  1932,  1939,
    1950,  1955,  1965,  1974,  1983,  1992,  2004,  2008,  2014,  2018,
    2028,  2038,  2051,  2057,  2066,  2071,  2078,  2085,  2096,  2106,
    2116,  2126,  2144,  2164,  2168,  2173,  2180,  2184,  2189,  2196,
    2201,  2213,  2220,  2230,  2245,  2246,  2247,  2248,  2249,  2250,
    2251,  2253,  2254,  2255,  2256,  2257,  2262,  2267,  2275,  2292,
    2300,  2308,  2315,  2322,  2333,  2342,  2351,  2360,  2373,  2381,
    2389,  2397,  2412,  2417,  2425,  2439,  2456,  2481,  2489,  2496,
    2507,  2517,  2522,  2535,  2552,  2553,  2554,  2555,  2556,  2557,
    2562,  2563,  2566,  2567,  2568,  2569,  2570,  2573,  2574,  2575,
    2576,  2577,  2582,  2596,  2604,  2609,  2617,  2622,  2627,  2635,
    2644,  2656,  2666,  2679,  2687,  2688,  2689,  2694,  2695,  2696,
    2697,  2698,  2703,  2710,  2720,  2726,  2735,  2744,  2745,  2753,
    2760,  2768,  2780,  2790,  2800,  2810,  2820,  2830,  2840,  2850,
    2861,  2870,  2880,  2890,  2906,  2915,  2924,  2932,  2938,  2950,
    2958,  2968,  2976,  2988,  2994,  3005,  3007,  3011,  3019,  3023,
    3028,  3032,  3036,  3040,  3050,  3058,  3065,  3071,  3081,  3085,
    3089,  3097,  3105,  3113,  3125,  3133,  3139,  3149,  3155,  3165,
    3169,  3179,  3185,  3191,  3197,  3206,  3215,  3224,  3237,  3241,
    3249,  3255,  3265,  3273,  3282,  3295,  3302,  3314,  3318,  3330,
    3337,  3343,  3352,  3359,  3365,  3376,  3383,  3389,  3398,  3407,
    3414,  3425,  3432,  3444,  3450,  3462,  3468,  3479,  3485,  3496,
    3502,  3513,  3519,  3530,  3539,  3543,  3552,  3556,  3564,  3568,
    3578,  3585,  3594,  3604,  3603,  3617,  3626,  3635,  3648,  3652,
    3664,  3668,  3676,  3679,  3686,  3690,  3699,  3703,  3707,  3715,
    3719,  3725,  3731,  3737,  3747,  3751,  3755,  3763,  3767,  3773,
    3783,  3787,  3797,  3801,  3811,  3815,  3825,  3829,  3839,  3843,
    3852,  3856,  3864,  3868,  3872,  3876,  3886,  3890,  3894,  3901,
    3906,  3914,  3918,  3922,  3926,  3930,  3934,  3942,  3946,  3950,
    3958,  3962,  3966,  3970,  3981,  3987,  3997,  4003,  4013,  4017,
    4021,  4084,  4106,  4134,  4298,  4302,  4312,  4316,  4320,  4324,
    4333,  4337,  4341,  4345,  4349,  4354,  4358,  4362,  4366,  4375,
    4381,  4391,  4399,  4403,  4407,  4411,  4415,  4419,  4423,  4427,
    4431,  4435,  4440,  4444,  4448,  4452,  4460,  4464,  4468,  4472,
    4480,  4487,  4494,  4504,  4508,  4516,  4524,  4528,  4536,  4544,
    4552,  4606,  4610,  4620,  4626,  4636,  4640,  4648,  4652,  4656,
    4664,  4672,  4689,  4697,  4714,  4733,  4757,  4763,  4774,  4780,
    4791,  4800,  4802,  4806,  4811,  4821,  4824,  4831,  4837,  4843,
    4850,  4862,  4865,  4872,  4878,  4884,  4891,  4902,  4906,  4914,
    4918,  4926,  4930,  4934,  4939,  4948,  4952,  4956,  4960,  4968,
    4973,  4981,  4986,  4994,  5002,  5007,  5012,  5017,  5022,  5027,
    5032,  5038,  5046,  5050,  5067,  5071,  5079,  5087,  5095,  5099,
    5107,  5111,  5119,  5127,  5131,  5135,  5170,  5176,  5182,  5192,
    5196,  5200,  5204,  5208,  5212,  5216,  5223,  5229,  5239,  5247,
    5255,  5259,  5263,  5267,  5271,  5275,  5279,  5283,  5287,  5291,
    5299,  5307,  5311,  5315,  5323,  5330,  5338,  5346,  5350,  5354,
    5362,  5366,  5372,  5378,  5382,  5392,  5400,  5404,  5410,  5419,
    5428,  5434,  5440,  5450,  5467,  5474,  5489,  5525,  5529,  5537,
    5545,  5557,  5561,  5569,  5577,  5581,  5592,  5609,  5615,  5621,
    5631,  5635,  5641,  5647,  5651,  5657,  5661,  5667,  5673,  5680,
    5690,  5695,  5703,  5709,  5719,  5741,  5750,  5756,  5769,  5783,
    5790,  5796,  5806,  5815,  5823,  5829,  5847,  5855,  5859,  5866,
    5871,  5879,  5883,  5890,  5894,  5901,  5905,  5912,  5916,  5925,
    5938,  5941,  5949,  5952,  5960,  5968,  5976,  5980,  5988,  5991,
    5999,  6011,  6014,  6022,  6034,  6040,  6050,  6053,  6061,  6065,
    6069,  6077,  6080,  6088,  6091,  6099,  6103,  6107,  6111,  6115,
    6123,  6131,  6143,  6155,  6159,  6163,  6171,  6177,  6187,  6191,
    6195,  6199,  6203,  6207,  6211,  6215,  6223,  6227,  6231,  6235,
    6243,  6249,  6259,  6269,  6273,  6281,  6291,  6302,  6309,  6313,
    6321,  6324,  6331,  6336,  6345,  6355,  6358,  6365,  6369,  6377,
    6386,  6393,  6403,  6407,  6414,  6420,  6430,  6433,  6440,  6445,
    6457,  6465,  6477,  6485,  6489,  6497,  6501,  6505,  6513,  6521,
    6525,  6529,  6533,  6541,  6549,  6561,  6565,  6573,  6587,  6591,
    6598,  6603,  6611,  6616,  6625,  6633,  6640,  6646,  6653,  6664,
    6670,  6680,  6687,  6694,  6719,  6747,  6775,  6779,  6783,  6791,
    6798,  6805,  6817,  6821,  6822,  6835,  6836,  6837,  6838,  6839,
    6840,  6841,  6842,  6843,  6844,  6845,  6846,  6847,  6848,  6849,
    6850,  6851,  6855,  6856,  6857,  6858,  6859,  6860,  6861,  6862,
    6863,  6864,  6865,  6866,  6867,  6868,  6869,  6870,  6871,  6872,
    6873,  6874,  6875,  6876,  6877,  6878,  6879,  6880,  6881,  6882,
    6883,  6884,  6885,  6886,  6887,  6888,  6889,  6890,  6891,  6892,
    6893,  6894,  6895,  6896,  6897,  6898,  6899,  6900,  6901,  6902,
    6903,  6904,  6905,  6906,  6907,  6908,  6909,  6910,  6911,  6912,
    6913,  6914,  6915,  6916,  6917,  6918,  6919,  6920,  6921,  6922,
    6923,  6924,  6925,  6926,  6927,  6928,  6929,  6930,  6931,  6932,
    6933,  6934,  6935,  6936,  6937,  6938,  6939,  6940,  6941,  6942,
    6943,  6944,  6945,  6946,  6947,  6948,  6949,  6950,  6951,  6952,
    6953,  6954,  6955,  6956,  6957,  6958,  6959,  6960,  6961,  6962,
    6963,  6964,  6965,  6966,  6967,  6968,  6969,  6970,  6971,  6972,
    6973,  6974,  6975,  6976,  6977,  6978,  6979,  6980,  6981,  6982,
    6983,  6984,  6985,  6986,  6987,  6988,  6989,  6990,  6991,  6992,
    6993,  6994,  6995,  6996,  6997,  6998,  6999,  7000,  7001,  7002,
    7003,  7004,  7005,  7006,  7007,  7008,  7009,  7010,  7011,  7012,
    7013,  7014,  7015,  7016,  7017,  7018,  7019,  7020,  7021,  7022,
    7023,  7024,  7025,  7026,  7027,  7028,  7029,  7030,  7031,  7032,
    7033,  7034,  7035,  7036,  7037,  7038,  7039,  7040,  7041,  7042,
    7043,  7044,  7045,  7046,  7047,  7048,  7049,  7050,  7051,  7052,
    7053,  7054,  7055,  7056,  7058,  7059,  7060,  7065
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
     335,   336,   337,   338,   339
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int jsoniq_parser::yyeof_ = 0;
  const int jsoniq_parser::yylast_ = 16623;
  const int jsoniq_parser::yynnts_ = 320;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 544;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 340;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 594;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17405 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 7069 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"


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

