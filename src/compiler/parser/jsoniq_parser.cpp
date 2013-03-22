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
#line 88 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"


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
#line 69 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"


#include "jsoniq_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1052 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"

#include "compiler/parser/jsoniq_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 99 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 185 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 912 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 290 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 911 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 299 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 308 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 345: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 317 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 346: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 326 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 335 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 344 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 353 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 362 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 371 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 380 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 389 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 398 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 407 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 416 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 425 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 434 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 443 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 452 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 461 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 470 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 479 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 488 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 497 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 366: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 506 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 515 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 524 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 533 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 370: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 542 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 372: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 551 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 373: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 560 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 569 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 578 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 587 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 596 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 605 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 614 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 623 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 632 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 641 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 650 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 659 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 668 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 386: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 677 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 686 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 695 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 704 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 390: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 713 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 392: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 722 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 393: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 731 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 740 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 749 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 758 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 767 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 776 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 785 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 794 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 401: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 803 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 402: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 812 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 821 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 830 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 405: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 839 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 408: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 848 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 409: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 857 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 866 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 875 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 884 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 893 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 902 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 911 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 938 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 419: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 947 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 420: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 956 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 965 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 974 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 423: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 983 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 426: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 992 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 427: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1001 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 428: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1010 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 429: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1019 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 431: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1028 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 432: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1037 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 434: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1046 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 435: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1055 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 436: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1064 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1073 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 438: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1082 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1091 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1100 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1109 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1118 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1127 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1136 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1145 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1154 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1163 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1172 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1181 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1190 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1199 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1208 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1217 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1226 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1235 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1244 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1253 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1262 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 459: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1271 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 460: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1280 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1289 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1298 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1307 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 464: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1316 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 467: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1325 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 468: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1334 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 469: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1343 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 470: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1352 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 473: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1361 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 474: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1370 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 475: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1379 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 476: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1388 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 477: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1397 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 479: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1406 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 480: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1415 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1424 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1433 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1442 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 484: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1451 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1460 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1469 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1478 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1487 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1496 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1505 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1514 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1523 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1532 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1541 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1550 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1559 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1568 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1577 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1586 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1595 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1604 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1613 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 503: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1622 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1631 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 505: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1640 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1649 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1658 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1667 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 509: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1676 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1685 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1694 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 512: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1703 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 514: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1712 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 515: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1721 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 516: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1730 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1739 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1748 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1757 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 520: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1766 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 524: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1775 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 525: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1784 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 526: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1793 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1802 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1811 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 529: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1820 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 531: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1829 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 532: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1838 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 533: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1847 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 534: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1856 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 535: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1865 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 536: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1874 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1883 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 538: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1892 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 539: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1901 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 540: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1910 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1919 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1928 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 543: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1937 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1946 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1955 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1964 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1973 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1982 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1991 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2000 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2009 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2018 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2027 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2036 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2045 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2054 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2063 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2072 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2081 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2090 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2099 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 562: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2108 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 563: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2117 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 564: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2126 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 565: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2135 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2144 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2153 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 568: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2162 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 569: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2171 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 570: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2180 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 571: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2189 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 573: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2198 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 574: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2207 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 577: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2216 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 578: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2225 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2234 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2243 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 581: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2252 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 582: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2261 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 583: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2270 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 584: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2279 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 585: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2288 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 586: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2297 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 587: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2306 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2315 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 589: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2324 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 592: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2333 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 593: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2342 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2351 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2360 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 596: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2369 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 597: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2378 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 599: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2387 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 600: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2396 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 601: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2405 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 602: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2414 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 604: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2423 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 605: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2432 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 607: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2441 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 610: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2450 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 611: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2459 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 612: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2468 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 613: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2477 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 614: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2486 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 615: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2495 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 616: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2504 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 617: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2513 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 618: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2522 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 619: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2531 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 620: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2540 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 621: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2549 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 625: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2558 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 628: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2567 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 629: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2576 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 633: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2585 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 634: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2594 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 635: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2603 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 636: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2612 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 637: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2621 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 638: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2630 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 639: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2639 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 640: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2648 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 641: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2657 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 642: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2666 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 643: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2675 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 644: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2684 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 645: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2693 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 646: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2702 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 647: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2711 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 648: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2720 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 649: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2729 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 650: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2738 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 651: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2747 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 658: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2756 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 659: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2765 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 660: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2774 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
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
#line 133 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2871 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 1070 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1074 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1078 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1086 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1092 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1096 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1105 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1111 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1119 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1125 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1136 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1141 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1145 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8", VersionDecl::jsoniq );
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1150 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl(
        LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)), VersionDecl::jsoniq );
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1159 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1166 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1173 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1182 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1189 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1197 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1205 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1213 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1224 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1229 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1236 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1243 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1255 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1265 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 1272 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 1279 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      // error
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1314 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1319 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1327 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1335 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1343 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1348 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1356 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1361 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1369 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1374 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1382 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1387 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1392 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1397 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1410 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1420 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1425 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1433 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1441 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1452 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1459 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1470 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1475 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1483 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1490 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1497 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1506 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1519 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1527 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1534 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1544 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 1551 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 1558 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1581 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1587 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1596 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1603 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1613 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1622 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1623 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1624 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1625 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1626 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1627 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1628 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1629 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1630 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1631 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1637 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1645 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1653 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1661 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1668 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1676 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1683 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1688 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1696 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1704 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 114:

/* Line 690 of lalr1.cc  */
#line 1718 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 115:

/* Line 690 of lalr1.cc  */
#line 1732 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 116:

/* Line 690 of lalr1.cc  */
#line 1749 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1754 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1762 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1770 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1781 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1786 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1795 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1800 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1807 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1812 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1822 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1827 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1836 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1842 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1855 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1860 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1868 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 133:

/* Line 690 of lalr1.cc  */
#line 1879 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 134:

/* Line 690 of lalr1.cc  */
#line 1894 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 135:

/* Line 690 of lalr1.cc  */
#line 1906 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 136:

/* Line 690 of lalr1.cc  */
#line 1921 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1926 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1931 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1936 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1944 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1951 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1962 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1967 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1977 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1986 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1995 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 2004 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 2016 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2020 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2026 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 2030 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 2040 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);

      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(8) - (1)].sval)) );
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 2050 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));

      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(9) - (1)].sval)) );
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 2063 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2069 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2078 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2083 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2090 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 2097 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 2109 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 161:

/* Line 690 of lalr1.cc  */
#line 2119 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 2129 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 2140 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 164:

/* Line 690 of lalr1.cc  */
#line 2156 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 165:

/* Line 690 of lalr1.cc  */
#line 2176 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2180 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2184 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2192 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2196 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2200 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2208 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 2213 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 2225 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 2232 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 2242 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 188:

/* Line 690 of lalr1.cc  */
#line 2274 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 2279 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2287 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 191:

/* Line 690 of lalr1.cc  */
#line 2304 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2312 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2320 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2327 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 2334 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 2345 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                          NULL,  // no type
                                          NULL,  // no init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 2354 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), // type
                                          NULL,  // no init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 2363 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                          NULL,  // no type
                                          (yysemantic_stack_[(4) - (4)].expr),    // init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 2372 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), // type
                                          (yysemantic_stack_[(5) - (5)].expr),    // init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 2385 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2393 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2401 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2409 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 204:

/* Line 690 of lalr1.cc  */
#line 2424 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2429 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 2437 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 207:

/* Line 690 of lalr1.cc  */
#line 2451 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 208:

/* Line 690 of lalr1.cc  */
#line 2468 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 209:

/* Line 690 of lalr1.cc  */
#line 2493 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2501 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2508 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2519 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2529 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2534 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2547 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 234:

/* Line 690 of lalr1.cc  */
#line 2594 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2608 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2616 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2621 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2629 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2634 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2639 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2647 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2656 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2668 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2678 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2691 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2715 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2722 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2732 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2738 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2747 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2757 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      // this adds on shift-reduce conflict (probably with FTRange expression)
    }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2765 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2772 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2780 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2792 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2802 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2812 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2822 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2832 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2842 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2852 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2862 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2873 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2882 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2892 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2902 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2918 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2927 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2936 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2944 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2950 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2962 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2970 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2980 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2988 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3000 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 3006 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 3019 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3023 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3031 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3035 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 3044 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3048 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3052 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3062 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3070 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3077 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3083 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3093 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3097 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 3101 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3109 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3117 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3125 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3137 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3145 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3151 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3161 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3167 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3177 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3181 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3191 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3197 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 3203 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 3209 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3218 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3227 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3236 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3249 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3253 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3261 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3267 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3277 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3285 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3294 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3307 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3314 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3326 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3330 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3342 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3349 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3355 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3364 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3371 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3377 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3388 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3395 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 3401 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3410 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 3419 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3426 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3437 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3444 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3456 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3462 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3474 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3480 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3491 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3497 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3508 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3514 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3525 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3531 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3542 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3551 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3555 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3564 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3568 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3576 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3580 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 362:

/* Line 690 of lalr1.cc  */
#line 3590 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3597 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3606 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3615 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3620 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3629 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3638 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3647 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3660 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3664 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3676 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3680 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3687 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3691 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3698 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3702 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3711 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3715 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3719 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3727 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3731 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3737 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3743 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3749 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3759 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3763 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3767 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3775 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3779 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3785 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3795 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3799 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3809 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3813 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3823 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3827 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3837 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3841 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3851 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3855 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3864 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3868 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3876 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3880 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3884 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3888 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3898 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3902 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3906 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3913 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3918 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3926 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3930 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3934 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3938 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3942 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3946 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3954 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3958 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3962 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3970 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3974 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3978 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3982 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3993 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3999 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4009 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4015 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4025 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4029 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4033 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4096 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4118 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 4146 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4310 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4314 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4324 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4328 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4332 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4336 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4345 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4349 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4353 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4357 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4361 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4366 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4370 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4374 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4378 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4387 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4393 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4403 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4411 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4415 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4419 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4423 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4427 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4431 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4435 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4439 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4443 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4447 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4452 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4456 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4460 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4464 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4472 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4476 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4480 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4484 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new NullLiteral(LOC((yyloc)));
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4492 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4499 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4506 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4516 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), true);
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4520 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), false);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4528 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4536 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4540 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4548 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4556 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4564 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4618 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4622 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 485:

/* Line 690 of lalr1.cc  */
#line 4644 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4650 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4656 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4662 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4672 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4676 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4684 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 4692 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4704 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4708 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4716 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4720 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4724 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4732 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4740 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 500:

/* Line 690 of lalr1.cc  */
#line 4757 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4765 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 502:

/* Line 690 of lalr1.cc  */
#line 4784 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 503:

/* Line 690 of lalr1.cc  */
#line 4803 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 504:

/* Line 690 of lalr1.cc  */
#line 4825 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4831 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4842 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4848 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4859 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4874 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4879 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4888 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4892 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4899 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4905 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4911 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4918 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4933 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4940 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4946 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4952 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4959 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4970 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4974 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4982 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4986 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4994 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4998 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 5002 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 5007 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 5016 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 5020 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 5024 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 5028 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 5036 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 5041 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 5049 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 5054 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 5062 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 5070 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 5075 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 5080 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 5085 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 5090 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 5095 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 5106 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 5114 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 5118 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 5135 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 5139 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 5147 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 5155 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 5163 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 5167 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 5175 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 5179 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 5187 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 5195 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 5199 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5203 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5238 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5244 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5250 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5260 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5264 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5268 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5272 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5276 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5280 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5284 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5291 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5297 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5307 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5315 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5323 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5327 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5331 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5335 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5339 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5343 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5347 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5351 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5355 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5359 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5367 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5375 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5379 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5383 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5391 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5398 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5406 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5414 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5418 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5422 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5430 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5434 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5440 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5446 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5450 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5460 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5468 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5472 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5478 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5487 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5496 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5502 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5508 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5518 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5535 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5542 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5557 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5584 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5588 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5596 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5604 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5608 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5619 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5636 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5648 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5658 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5662 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5668 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5674 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5678 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5684 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5688 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5694 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5700 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5707 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5717 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5722 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5730 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5736 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5746 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5768 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5777 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5783 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5796 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5810 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5817 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5823 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5833 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5842 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5850 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5856 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5874 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5882 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5886 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5893 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5898 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5906 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5910 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5917 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5921 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5928 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5939 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5943 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5952 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5964 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5968 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5975 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5979 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5987 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5995 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 6003 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 6007 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 6014 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 6018 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 6026 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 6037 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 6041 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 6049 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 6061 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 6067 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 6076 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 6080 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 6088 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 6092 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 6096 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 6103 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 6107 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 6114 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 6118 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 6126 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 6130 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 6134 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 6138 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 6142 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 6150 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 6158 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 6170 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 6182 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6186 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6190 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6198 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6204 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6214 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6218 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6222 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6226 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6230 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6234 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6238 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6242 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6250 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6254 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6258 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6262 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6270 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6276 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6286 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6296 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6300 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6308 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 720:

/* Line 690 of lalr1.cc  */
#line 6318 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 721:

/* Line 690 of lalr1.cc  */
#line 6329 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6336 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6340 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6347 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6351 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6358 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6363 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6372 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6381 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6385 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6392 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6396 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6404 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6413 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6420 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6430 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6434 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6441 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6447 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6456 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6460 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6467 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6472 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6484 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6492 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6504 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6512 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6516 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6524 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6528 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6532 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6540 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6548 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6552 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6556 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6560 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6568 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6576 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6588 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6592 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6600 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6614 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6618 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6625 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6630 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6638 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6643 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6652 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6660 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6667 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6673 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6680 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)) );
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6691 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6697 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 775:

/* Line 690 of lalr1.cc  */
#line 6707 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6714 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6721 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 778:

/* Line 690 of lalr1.cc  */
#line 6746 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 779:

/* Line 690 of lalr1.cc  */
#line 6774 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 780:

/* Line 690 of lalr1.cc  */
#line 6802 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6806 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6810 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6818 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6825 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6832 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6849 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 790:

/* Line 690 of lalr1.cc  */
#line 6862 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 6863 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6864 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6865 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6866 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6867 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6868 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6869 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6870 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6871 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6872 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6873 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 6874 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6875 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6876 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6877 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6882 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6883 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6884 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6885 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6886 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6887 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6888 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6889 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6890 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6891 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6892 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6893 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6894 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6895 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6896 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6897 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6898 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6899 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6900 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6901 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6902 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6903 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6904 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6905 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6906 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6907 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6908 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6909 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6910 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6911 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6912 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6913 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6914 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6915 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6916 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6917 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6918 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6919 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6920 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6921 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6922 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6923 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6924 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6925 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6926 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6927 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6928 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6929 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6930 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6931 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6932 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6933 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6934 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6935 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6936 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6937 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6938 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6939 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6940 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6941 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6942 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6943 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6944 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6945 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6946 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6947 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6948 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6949 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6950 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6951 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6952 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6953 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6954 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6955 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6956 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6957 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6958 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6959 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6960 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6961 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6962 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6963 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6964 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6965 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6966 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6967 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6968 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6969 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6970 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6971 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6972 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6973 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6974 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6975 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6976 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6977 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6978 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6979 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6980 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6981 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6982 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6983 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6984 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6985 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6986 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6987 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6988 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6989 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6990 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6991 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6992 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6993 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6994 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6995 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6996 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6997 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6998 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6999 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 7000 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 7001 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 7002 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 7003 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 7004 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 7005 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 7006 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 7007 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 7008 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 7009 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 7010 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 7011 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 7012 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 7013 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 7014 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 7015 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 7016 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 7017 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 7018 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 7019 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 7020 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 7021 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 7022 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 7023 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 7024 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 7025 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 7026 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 7027 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 7028 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 7029 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 7030 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 7031 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 7032 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 7033 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 7034 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 7035 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 7036 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 7037 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 7038 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 7039 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 7040 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 7041 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 7042 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 7043 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 7044 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 7045 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 7046 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 7047 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 7048 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 7049 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 7050 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 7051 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 7052 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 7053 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 7054 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 7055 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 7056 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 7057 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 7058 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 7059 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 7060 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 7061 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 7062 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 7063 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 7064 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 7065 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 7066 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 7067 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 7068 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 7069 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 7070 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 7071 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 7072 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 7073 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 7074 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 7075 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 7076 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 7077 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 7078 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 7079 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 7080 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 7081 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 7082 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 7084 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 7085 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 7086 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 7091 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12099 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
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
  const short int jsoniq_parser::yypact_ninf_ = -1503;
  const short int
  jsoniq_parser::yypact_[] =
  {
      6825,  8665,  8665,  8665,  8665, -1503, -1503,     1,    11, -1503,
     598,    22, -1503, -1503, -1503,    32, -1503, -1503, -1503,   209,
   -1503,   364,   705,   223,   450,   620, -1503,     2, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503,   387, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503,   548, -1503,   704, -1503,   632,   683, -1503,
     339, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503,   758, -1503, -1503, -1503, -1503, -1503, -1503, -1503,   797,
   -1503, -1503, -1503, -1503, -1503, 16500, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503,   816, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503,  4685, 10807, 11113, 16500, -1503,
   -1503,   808, -1503, -1503, -1503, -1503,   811, -1503, -1503, -1503,
    6210, -1503,  6519, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503,   830, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503,   105,   750,   780, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503,   153, -1503,   192,
   -1503,   163,   200, -1503, -1503, -1503, -1503, -1503, -1503,   887,
   -1503,   745,   783,   789, -1503, -1503,   889,   903, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
     719, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, 11419, 11725, -1503,   746, -1503, -1503, -1503, -1503,  7133,
    7441,  1065, -1503,  8971, -1503, -1503,   646,    68, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503,    82, -1503, -1503, -1503, -1503, -1503, -1503,   547,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,  8665, -1503,
   -1503, -1503, -1503,     8, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503,   152, -1503,   875, -1503, -1503, -1503,   634, -1503,
     650, -1503, -1503, -1503, -1503, -1503, -1503, -1503,   900,   976,
   -1503,  1223,   817,   972,   645,   540,   552,   623, -1503,  1026,
     876,   978,   980, 12643, -1503,   890, -1503, -1503,   237, -1503,
   -1503, -1503, -1503,   636, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503,   935,   929, -1503,
   -1503, -1503, -1503, -1503,   902, -1503,  8665,   904,   905,   907,
    8665,   358,   358,  1059,   762,   763,   507, 16793, 16500,   458,
    1047, 16500,   942,   977,   536,  6210,   827,   847, 16500, 16500,
     792,   850,    43, -1503, -1503, -1503,  6210,  8665,  8665, 12949,
     426,   948, 12949,  1104,   183,   407, 16500,   986,   963,  1000,
   -1503, 12949, 16500,  8665, 12949, 12949, 16500,  8665,   957,   958,
   12949, 16500, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503,   970, -1503, 16500, -1503, -1503,   931,
    7747,   992,   300,   996,   935,   962,   967,   968, 16500,  4994,
   -1503,   973,    85, -1503,   656, -1503,   113,  1091, 12949, 12949,
     142, -1503, -1503, -1503,  1113, 12949,   915, -1503,  1102,  1103,
   12949, 12949, 13561, 12949, 12949,  5303, 12949, 13561, 12949,   897,
     899, 16500,   946,   949, 12949, 12949,  8053,   892, -1503,    61,
   -1503,    58, 12949,  7441, -1503, -1503, -1503, -1503, -1503,   598,
     620,    95,    98,  1139,  9277,  3101,  9583,  3428,   797, -1503,
   -1503,   353,   797, -1503, 12949,  4060, -1503,  1035, -1503,     2,
     987,   984,   989,  8665, 12949, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, 16500, -1503,   868,   873, 16500,  1039,
   13255, 13255, 13255, -1503, 13255, 13255, -1503, 13255, -1503, 13255,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, 13255, 13255,  1090,
   13255, 13255, 13255, 13255, 13255, 13255, 13255, 13255, 13255, 13255,
   13255, 13255,   928,  1070,  1071,  1072, -1503, -1503, -1503, 13561,
   12031, -1503,  5606, 12949,  9889,  1015, -1503,  1021, 10195, -1503,
   -1503, -1503, -1503,    49, -1503,    73, -1503, -1503, -1503, -1503,
   -1503, -1503,  1064,  1069,   223,  1144, -1503, -1503, 16793,  1063,
     642, 16500,  1018,  1019,  1063,  1059,  1054,  1050, -1503, -1503,
   -1503,   631,   933,  1092,   881, 16500,  1045, 12949,  1073, 16500,
   16500, -1503,  1056,  1005,  1006,   112, 16500,  1100,   233, -1503,
    8665, -1503,   119, -1503,  6210,  1101,  1152,  6210,  1059,  1105,
     635, 16500, 12949,     2,   120,    14, -1503,   391,  1014,   131,
     139,  1049, -1503,  1016,  8665,  8665,   224,   658, 12949,   278,
   -1503, -1503, 12949,  5303, -1503, 12949, 12949, 12949, 12949, -1503,
   12949, -1503, 12949, -1503, 16500,  1091, -1503,   292,   256,   303,
   -1503, -1503, -1503,   366, -1503,   286,   435, -1503, -1503,   636,
     385,   389,   228,    -7,  1109,   641,   965,   979,   975,   122,
   -1503,  1074, -1503, -1503,  1017,   143,  7747,   367,  4376,   892,
   -1503, -1503, -1503,   982, -1503,   646,   140,  1181,   782, -1503,
   -1503,    99, -1503, -1503, -1503,   107, -1503,    97, -1503, -1503,
   -1503, -1503, -1503,  3744, -1503, -1503, -1503, 16500,  1044, 12949,
    1097, -1503, -1503, -1503,  1110, -1503,    37, -1503, -1503,  1110,
   16500,    15,   976, -1503, -1503, -1503, -1503, -1503, 13255, -1503,
   -1503, -1503,   118, -1503,   540,   540,   679,   552,   552,   552,
     552,   623,   623, -1503, -1503, 15035, 15035, 16500, 16500, -1503,
   -1503,   384, -1503, -1503, -1503, -1503, -1503,    93, -1503, -1503,
   -1503,   266, -1503, -1503, -1503,   288,   358, -1503, -1503,   433,
     550,   751, -1503,   223, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503,  1063, -1503,  1088, 15328,  1079, 12949,
   -1503, -1503, -1503,  1128,  1059,  1059,  1063, -1503,   628,  1059,
     756, 16500,   726,   729,  1196, -1503, -1503,   936,   630, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
     631,   135,   997,   643, 12949, -1503, 16500,  1135,   930,  1059,
   -1503, -1503,  1078,  1128, 15035,  1114,  1140,  1051,  1038,  1107,
    1059,  1080,  1111,  1146,  1059, 15035, 12949,   -59, -1503, -1503,
   -1503,  1093,  1126, 12949, 12949,  1098, -1503,  1147,  1149,  8665,
   -1503,  1066,  1068,  1106, 12949,  1112,  1067, 12949, -1503,  1132,
    1134, -1503,   214,   226,   250,  1222, -1503,   444, -1503,   800,
    1108, -1503, -1503,  1232, -1503,  1234, -1503,   640, 12949, 12949,
   12949,   812, 12949, 12949, 12949, 12949, 12949, 12949, 12949, 12949,
   12949, 13561,  1150, 12949, 12949, -1503, 10501,   357,  1020, -1503,
   -1503, -1503, -1503, -1503, -1503,   217, -1503, -1503, 12949,   108,
     167,    97,  9583,  3428,  9583,  1185, -1503, -1503, 12949,   814,
    1160, -1503, 16500,  1163, -1503, 16207,  1145,  1153, 12949,   -34,
    1127,    30,   523,  1022, -1503, -1503,   669,    15, -1503, 12949,
     118,   295,   515, -1503,   993,   121,  1011,  1023, -1503, -1503,
     847, -1503,  1004,  -111,  1125,  1130,  1133,  1136,  1137,  1138,
    1141,  1142,  1151,  1156,  1157, 15328,  1158,  1159,  1161,  1164,
   -1503,  1166, -1503,   520, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503,  1162, -1503, -1503,
   -1503, -1503, 12337, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503,   787, -1503,  1255,   872, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503,   994, -1503, -1503,  1262, -1503,
   -1503, -1503, -1503, -1503,   653,  1267, -1503,   757, -1503, -1503,
   -1503,  1125,  1130,  1133,  1137,  1138,  1141,  1142,  1151,  1156,
    1159,  1161,  1164, -1503,   520,   520, 13561,  1012,   998, -1503,
    1128,   135,  1085,  1119,  8665, -1503, -1503, -1503, 15035, -1503,
    8665,  1059,  1189, -1503, -1503, -1503,  1059,  1189, -1503, -1503,
   12949,  1177,  8665, 16500, -1503, -1503, 12949, 12949,   718, -1503,
      -5,   837, -1503, 14156,   862, -1503,   863, -1503,  1143, -1503,
   -1503,  8665, -1503, 12949, -1503, -1503, 12949, 12949,  1131,  1147,
    1224, -1503,  1191, -1503,   877, -1503, -1503,  1321, -1503, -1503,
    8665, 16500, -1503,   883, -1503, -1503, -1503,  8665,  1148,  1169,
    1094,  1096, -1503, -1503, -1503,  1099,  1115, -1503, -1503, -1503,
    1238, -1503, -1503, -1503, -1503,  1089,   491, 16500,  1154, -1503,
    1179,  1186,  1192,  1184, -1503,   875,   765,  4376,  1020, -1503,
    8359,  4376, -1503, -1503,  1181,   602, -1503, -1503, -1503,  1160,
   -1503,  1059, -1503,   891, -1503,    56,  1235, -1503, 12949,   723,
    1097, 16500, -1503,   493, 16500, -1503, 12949,  1202, 12949,  1226,
   12949,    39,  1203, 12949,  1204, -1503,  1236,  1242, 12949, 16500,
     770,  1279, -1503, -1503, -1503,   417,  1174, -1503,   118,  1116,
   -1503, -1503,   -43, -1503,   482,    94,  1117,   118,   482, 13255,
   -1503,   -22, -1503, -1503, -1503, -1503, -1503, -1503,   118,  1215,
    1081,   933,    94, -1503, -1503,  1082,  1290, -1503, -1503, -1503,
    1182,    52, 15621, 13863,  1188,  5908, 16500, 16500,  1194, 15914,
    1195,  1201,  1205,  1207,  1208,  1209,  1210, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
    1345,   235,  1351,   235,  1123,  1276, -1503, -1503,  1229, 16500,
    1155, -1503, -1503, 13561, -1503,  1217, -1503,  1277,  1278,  1310,
    1059,  1189, -1503, 12949,  1225, -1503, -1503, -1503,  1221, -1503,
      35, 12949,  8665,  1227,    54, -1503, 16500,   485, -1503, 14449,
     -16, -1503, 14742,  1228, -1503, -1503,  1233, -1503, -1503, -1503,
   12949,   869,  1222, 16500,   924, -1503,  1237,  1222, 16500, -1503,
    1240, -1503, -1503, 12949, 12949, 12949, 12949,  1118, 12949, 12949,
   -1503, 12949, 12949, 12949, 12949, 10501,   442, -1503, -1503, -1503,
   -1503, -1503,  1235, -1503, -1503, -1503,  1059, 12949, -1503,  1266,
   -1503, -1503, 12949,  1263, -1503, -1503, 12949, -1503,   518, -1503,
   12949,  1264, 12949, -1503, 12949, 16500, 16500, -1503,   686, -1503,
   12949, -1503, -1503, -1503,  1241, 13255, -1503, -1503, -1503, -1503,
   -1503,   318, 13255, 13255,   698, -1503,  1011, -1503,   460, -1503,
    1023,   118,  1259, -1503, -1503,  1165, -1503, -1503, -1503, -1503,
   -1503, -1503,  1231,  1245, -1503,   326,   360,  1325,  1246, -1503,
     463, -1503,  1247, -1503,  1248,  1249,  1250, -1503, -1503,   487,
     495, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,   365,
     365, -1503,   235, -1503, -1503,   496, -1503,  1392,    -3,  1326,
    1252, 13561,   -17,  1167,  1270, -1503, 10501, 12949,  1059, -1503,
   -1503, -1503, 12949, 12949, -1503, -1503, -1503, 10501, 10501,  1347,
    8665, 15035, 16500,   561, 16500, 12949, 16500,   615, 10501, -1503,
       7,    16,  1222, 16500, -1503,  1254,  1222, -1503, -1503, -1503,
   -1503, -1503, 12949, -1503, -1503, -1503,   282,   321,   342, 12949,
   -1503, -1503, -1503,  1338, 12949, -1503, 12949, -1503, 12949,  1298,
   -1503, 12949, -1503, -1503, -1503,  1393, -1503, -1503, -1503,   552,
   13255, 13255,   679,   675, -1503, -1503, -1503, -1503, -1503, -1503,
   12949, -1503, -1503, -1503, 16500, -1503, 16500, -1503, 15035, -1503,
   15035,  1353, -1503, -1503, -1503, -1503, 16500, -1503, 16500, -1503,
   -1503, -1503, -1503,  1424, -1503, -1503, -1503,  1190,  1348, -1503,
   -1503,  1350, -1503,   813, 16500,  1336,  1239, 16500, 13561, -1503,
   -1503,  1189, -1503, -1503, 15035, -1503, -1503, -1503,  1366, 12949,
    1275, -1503,  1368, 10501, -1503, 16500,   660,   831, -1503,  1268,
    1222, -1503,  1272, -1503,  1273,  1147,  1149,   425, -1503,  1338,
   -1503, -1503, 12949, -1503,  1352,   679,   679, 13255,   455,  1286,
    1287,  1331,  1289,  1291, -1503, -1503, 15035,  1292,  1293, -1503,
   -1503,  1326, 13561, -1503,  1235,  1168, 16500,  1363,  1256,  1350,
     625, 15035,  8665, 15035,  1297, -1503, -1503,  1391,   773, -1503,
   -1503, -1503, -1503,  1303,   921, -1503, -1503, -1503,  1294, -1503,
   10501,   885, -1503, -1503, -1503, 16500,   679, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, 12949,
    1178, 16500,  1370,  8665,   633, -1503, -1503,   659, 12949, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503,  1371, -1503, -1503,  1193,
    1183, 16500, -1503, -1503, 12949, 10501, 16500,  1187, 12949,  1197,
    1307, 13561, -1503, 13561, 10501, -1503,  1295,  1212, 16500,  1269,
    1377, 16500,  1198, 13561, -1503
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       167,   170,   170,   170,     0,   807,  1011,   122,   124,   614,
     899,   908,   848,   812,   810,   791,   900,   903,   855,   816,
     792,   794,   259,   909,   796,   906,   877,   857,   832,   793,
     852,   853,   904,   901,   851,   798,   907,   799,   800,   948,
     960,   947,   849,   868,   862,   801,   850,   803,   802,   949,
     886,   887,   854,   829,   970,   971,   972,   973,   974,   975,
     976,   977,   978,   979,   980,   994,  1001,   876,   872,   863,
     843,   790,   871,   879,   888,   995,   867,   472,   844,   845,
     902,   996,  1002,   864,   881,     0,   480,   474,   874,   809,
     865,   866,   895,   869,   885,   894,  1000,  1003,   815,   856,
     897,   473,   884,   890,   795,     0,     0,     0,     0,   405,
     882,   893,   898,   896,   875,   861,   950,   859,   860,   997,
       0,   404,     0,   998,  1004,   891,   846,   870,   999,   892,
     873,   880,   889,   883,   951,   837,   842,   841,   840,   839,
     838,   804,   858,     0,   808,     0,   905,   830,   471,   475,
     476,   939,   938,   940,   814,   813,   833,   945,   797,   937,
     942,   943,   934,   836,   878,   936,   946,   944,   935,   834,
     941,   955,   956,   953,   954,   952,   805,   957,   958,   959,
     925,   924,   911,   828,   821,   918,   914,   831,   827,   926,
     260,   817,   818,   811,   820,   923,   922,   919,   915,   932,
     933,   931,   921,   917,   910,   819,   930,   929,   823,   825,
     824,   916,   920,   912,   826,   913,   822,   928,   981,   982,
     983,   984,   985,   986,   962,   963,   961,   967,   968,   969,
     964,   965,   966,   835,   987,   988,   989,   990,   991,   992,
     993,     0,     0,  1005,  1006,  1007,  1009,  1008,  1010,   167,
     167,     0,     2,   167,     9,    11,    25,     0,    30,    33,
      38,    39,    40,    41,    42,    43,    44,    34,    60,    61,
      35,    36,     0,    78,    81,    82,    37,    83,    84,     0,
     120,    85,    86,    87,    88,    20,   164,   165,   166,   173,
     176,   463,   177,     0,   178,   179,   180,   181,   182,   183,
     184,   187,     0,   213,   221,   216,   248,   254,     0,   246,
       0,   247,   223,   217,   186,   218,   185,   219,   222,   356,
     358,   360,   370,   372,   376,   378,   381,   386,   389,   392,
     394,   396,   398,     0,   402,   409,   408,   410,     0,   428,
     411,   433,   434,   435,   442,   454,   468,   470,   455,   456,
     457,   460,   461,   458,   462,   489,   490,   459,   493,   495,
     496,   497,   494,   542,   543,   544,   545,   546,   547,   548,
     469,    45,   224,   225,   227,   226,   228,   220,   465,   466,
     467,   464,   230,   233,   229,   231,   232,     0,   789,   806,
     899,   908,   906,   808,     0,   168,   169,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,   130,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
     279,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   194,   791,   816,   794,   847,   909,   796,   857,
     798,   868,   801,   803,   802,   886,   790,   845,   869,   893,
     950,   951,   945,   937,   943,   934,   834,   955,   956,   953,
     805,   957,   927,  1006,   477,   789,     0,   787,   189,     0,
       0,   213,     0,     0,   788,   796,   803,   802,     0,   170,
     762,   957,     0,   221,     0,   478,     0,   509,     0,     0,
       0,   788,   431,   432,     0,     0,     0,   538,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   764,     0,
     766,     0,     0,   167,     3,     4,     1,    10,    12,     0,
       0,     0,     0,     6,   167,     0,   167,     0,     0,   121,
     174,     0,     0,   192,     0,     0,   201,     0,   259,     0,
       0,     0,     0,     0,     0,   260,   206,   234,   253,   249,
     255,   250,   252,   251,     0,   258,     0,     0,     0,     0,
       0,     0,     0,   421,     0,     0,   419,     0,   365,     0,
     420,   413,   418,   417,   416,   415,   414,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   407,   406,   403,     0,
       0,   429,     0,     0,     0,   443,   451,     0,     0,   550,
     552,   556,   558,     0,   126,     0,   786,    49,    46,    47,
      50,    51,     0,     0,     0,     0,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   621,   622,
     623,     0,   105,   144,     0,     0,   114,     0,     0,     0,
       0,   129,     0,     0,     0,     0,     0,   136,     0,   140,
     170,   492,     0,    62,     0,    71,     0,     0,     0,    63,
       0,     0,     0,     0,     0,     0,   327,     0,     0,     0,
       0,     0,   612,     0,     0,     0,     0,   196,     0,     0,
     190,   188,     0,     0,   768,     0,     0,     0,     0,   477,
       0,   763,     0,   479,   510,   509,   506,     0,     0,     0,
     540,   539,   430,     0,   537,     0,     0,   634,   635,   777,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     640,     0,   204,   205,     0,     0,     0,     0,     0,   209,
     210,   765,   767,     0,     5,    26,     0,    27,     0,     7,
      31,     0,    17,     8,    32,     0,    21,   899,    79,    18,
      80,    22,   195,     0,   193,   214,   215,     0,     0,     0,
       0,   207,   235,   296,   257,   261,     0,   236,   237,   256,
       0,     0,   357,   359,   363,   369,   368,   367,     0,   364,
     361,   362,     0,   373,   380,   379,   377,   383,   384,   385,
     382,   387,   388,   391,   390,     0,     0,     0,     0,   412,
     426,     0,   450,   448,   447,   449,   446,     0,   485,   444,
     487,     0,   452,   491,   483,     0,     0,   123,   125,     0,
       0,     0,   104,     0,    94,    96,    97,    98,    99,   101,
     102,   103,    95,   100,    90,    91,     0,     0,   110,     0,
     106,   108,   109,   116,     0,     0,    89,    48,     0,     0,
       0,     0,     0,     0,     0,   712,   717,     0,     0,   713,
     747,   700,   702,   703,   704,   706,   708,   707,   705,   709,
       0,     0,     0,     0,     0,   113,     0,   146,     0,     0,
     555,   549,     0,   142,     0,     0,   137,     0,     0,     0,
       0,     0,     0,    64,     0,     0,     0,     0,   277,   283,
     280,     0,     0,     0,     0,     0,   554,     0,     0,     0,
     422,     0,     0,     0,     0,   197,     0,     0,   770,     0,
       0,   769,     0,     0,     0,   509,   507,     0,   498,     0,
       0,   481,   482,     0,    13,     0,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,     0,     0,     0,   439,
     440,   441,   438,   648,   437,     0,   436,   211,     0,     0,
       0,     0,   167,     0,   167,     0,   175,   245,     0,   311,
     307,   309,     0,   297,   298,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   238,   239,     0,   244,   366,     0,
       0,     0,     0,   678,   374,   651,   655,   657,   659,   661,
     664,   671,   672,   680,   791,   792,   794,   909,   793,   798,
     799,   800,   801,   790,   795,     0,   804,   797,  1009,  1008,
     783,  1010,   393,   561,   567,   568,   587,   578,   586,   585,
     584,   583,   580,   582,   579,   581,   571,   615,   616,   572,
     573,   780,   781,   782,   576,   395,   397,   400,   577,   399,
     427,   453,     0,   445,   484,   127,    58,    59,    56,    57,
     133,   132,     0,    92,     0,     0,   111,   112,   117,    76,
      77,    54,    55,    75,   718,     0,   721,   748,     0,   711,
     710,   715,   714,   746,     0,     0,   723,     0,   719,   722,
     701,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,   148,   150,     0,     0,     0,   115,
     118,     0,     0,     0,   170,   143,   138,   141,     0,   191,
       0,     0,    73,    67,    70,    69,     0,    65,   560,   281,
       0,     0,   170,     0,   325,   329,     0,     0,     0,   332,
       0,     0,   338,     0,     0,   345,     0,   349,     0,   424,
     423,   170,   198,     0,   200,   326,     0,     0,     0,     0,
       0,   510,     0,   500,     0,   533,   530,     0,   534,   535,
       0,     0,   529,     0,   504,   532,   531,     0,     0,     0,
       0,     0,   627,   628,   624,     0,     0,   632,   633,   629,
     773,   774,   638,   778,   636,     0,     0,     0,     0,   642,
     796,   803,   802,   957,   203,     0,     0,     0,   643,   644,
       0,     0,   212,   776,    28,     0,    19,    23,    24,   308,
     320,     0,   321,     0,   312,   313,   314,   315,     0,   300,
       0,     0,   263,     0,     0,   264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   240,     0,     0,     0,     0,
     290,     0,   287,   292,   243,     0,     0,   662,   675,     0,
     371,   375,     0,   694,     0,     0,     0,     0,     0,     0,
     650,   652,   653,   689,   690,   691,   693,   692,     0,     0,
     666,   665,     0,   669,   673,   687,   685,   684,   677,   681,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   564,   566,   565,
     562,   401,   486,   488,   135,   134,    93,   107,   735,   716,
       0,   740,     0,   740,   729,   724,   149,   151,     0,     0,
       0,   119,   147,     0,    29,     0,   139,     0,     0,    72,
       0,    66,   282,     0,     0,   328,   330,   335,     0,   333,
       0,     0,     0,     0,     0,   339,     0,     0,   353,     0,
       0,   346,     0,     0,   350,   425,     0,   199,   771,   772,
       0,     0,   509,     0,     0,   541,     0,   509,     0,   505,
       0,    14,    16,     0,     0,     0,     0,     0,     0,     0,
     641,     0,     0,     0,     0,     0,     0,   645,   649,   324,
     322,   323,   316,   317,   318,   310,     0,     0,   305,     0,
     299,   262,     0,     0,   276,   268,     0,   272,     0,   266,
       0,     0,     0,   285,     0,     0,     0,   242,   288,   291,
       0,   679,   670,   676,     0,     0,   749,   750,   760,   759,
     758,     0,     0,     0,     0,   751,   656,   757,     0,   654,
     658,     0,     0,   663,   667,     0,   688,   683,   686,   682,
     594,   589,     0,     0,   604,     0,     0,     0,     0,   574,
       0,   592,     0,   595,     0,     0,     0,   593,   598,     0,
       0,   569,   620,   563,   588,   784,   785,   570,   736,     0,
       0,   734,   741,   742,   738,     0,   733,     0,   731,     0,
       0,     0,     0,     0,     0,   551,     0,     0,     0,    68,
     284,   557,     0,     0,   336,   340,   334,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   553,
       0,     0,   509,     0,   536,     0,   509,   559,   625,   626,
     630,   631,     0,   637,   779,   639,     0,     0,     0,     0,
     646,   319,   306,   301,     0,   265,     0,   274,     0,     0,
     270,     0,   273,   286,   294,   295,   289,   241,   674,   761,
       0,     0,   753,     0,   699,   698,   697,   696,   695,   660,
       0,   752,   590,   591,     0,   608,     0,   605,     0,   617,
       0,     0,   597,   596,   603,   611,     0,   601,     0,   599,
     745,   744,   743,     0,   737,   730,   728,     0,   725,   726,
     720,   152,   154,   156,     0,     0,     0,     0,     0,   208,
     355,    74,   331,   337,     0,   351,   347,   354,     0,     0,
       0,   341,     0,     0,   343,     0,   519,   513,   508,     0,
     509,   499,     0,   775,     0,     0,     0,     0,   304,   302,
     269,   267,     0,   275,     0,   755,   754,     0,     0,     0,
       0,   612,     0,     0,   618,   575,     0,     0,     0,   739,
     732,     0,     0,   158,   157,     0,     0,     0,     0,   153,
       0,     0,     0,     0,     0,   527,   521,     0,   520,   522,
     528,   525,   515,     0,   514,   516,   526,   501,     0,   502,
       0,     0,   647,   303,   271,     0,   756,   668,   609,   610,
     613,   606,   607,   619,   602,   600,   727,   155,   159,     0,
       0,     0,     0,     0,     0,   344,   342,     0,     0,   512,
     523,   524,   511,   517,   518,   503,     0,   293,   160,     0,
       0,     0,   352,   348,     0,     0,     0,     0,     0,     0,
       0,     0,   162,     0,     0,   161,     0,     0,     0,     0,
       0,     0,     0,     0,   163
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1503, -1503,  -191,  -196, -1503,  1253,  1258, -1503,  1257,  -491,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
    -898, -1503, -1503, -1503, -1503,  -228,  -511, -1503,   834,    38,
   -1503, -1503, -1503, -1503, -1503,   386,   624, -1503, -1503,     9,
    -204,  1121, -1503,  1095, -1503, -1503,  -586, -1503,   578, -1503,
     351, -1503,  -153,  -208, -1503,  -506, -1503,    12,   159,    86,
    -266,  -167, -1503,  -800, -1503, -1503,  -154, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503,   747,   -95,  1339,
       0, -1503, -1503, -1503, -1503,   481, -1503, -1503,  -288, -1503,
       5, -1503, -1503,   932,  -967,  -785,  -766, -1503, -1503,   821,
   -1503, -1503,    41,   225, -1503, -1503, -1503,   246, -1502, -1503,
     509,   252, -1503, -1503,   253, -1219, -1503,  1046,   348, -1503,
   -1503,   345,  -921, -1503, -1503,   343, -1503, -1503, -1172, -1150,
   -1503,   340, -1357, -1503, -1503,   947,   950, -1503,  -515,   934,
   -1503, -1503,  -597,   414,  -583,   415,   423, -1503, -1503, -1503,
     701, -1503, -1503,  1213, -1503, -1503, -1503, -1503, -1503,  -710,
    -303,  -606, -1503, -1503,   279, -1503,  -480, -1503,   908, -1503,
    -377, -1503, -1503,   910,   913, -1503, -1503, -1503, -1503,   909,
   -1503, -1503, -1503, -1503,  -928, -1503,   334, -1503,   815,  -718,
   -1503, -1503, -1503, -1503, -1503,  -195,  -187, -1145,  -994, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
    -680,  -806,   -94,  -771, -1503, -1503, -1503,  -851, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503,   211,   212,  -643,   -82,
    -593, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,
   -1503, -1503,   308, -1503, -1503,   299, -1503,   301,  -997, -1503,
   -1503, -1503,   242,   232,    62,   521, -1503, -1503, -1503, -1503,
   -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503, -1503,   243,
   -1503, -1503, -1503,    67,   516,   661, -1503, -1503, -1503, -1503,
   -1503,   432, -1503, -1503, -1373, -1503, -1503, -1503,  -476, -1503,
     201, -1503,    34, -1503, -1503, -1503, -1503, -1259, -1503,   259,
   -1503, -1503, -1503, -1503, -1503,  1055, -1503, -1503, -1503, -1503,
   -1503,  -846, -1503, -1503, -1503,  -296,  -102,    46,   443, -1503
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   251,   565,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
    1172,   698,   269,   270,   271,   272,   273,   274,   874,   875,
     876,   275,   276,   277,   880,   881,   882,   278,   421,   279,
     280,   643,   281,   423,   424,   425,   431,   688,   689,   282,
    1153,   283,  1661,  1662,   284,   285,   286,   489,   287,   288,
     289,   290,   291,   691,   292,   293,   452,   294,   295,   296,
     297,   298,   299,   576,   300,   301,   769,   770,   302,   303,
     503,   305,   577,   589,  1036,  1037,   306,   578,   307,   580,
     504,   309,   310,   804,   805,  1300,   438,   311,   439,   440,
     811,  1301,  1302,  1303,   581,   582,  1023,  1024,  1458,   583,
    1020,  1021,  1274,  1275,  1276,  1277,   312,   705,   706,   313,
    1188,  1189,  1400,   314,  1191,  1192,   315,   316,  1194,  1195,
    1196,  1197,  1407,   317,   318,   319,   320,   818,   321,   322,
    1310,   323,   324,   325,   326,   327,   328,   329,   330,   331,
    1096,   332,   333,   334,   335,   607,   608,   336,   337,   338,
     339,   340,   341,   342,  1003,  1004,   343,   635,   636,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   851,
     354,   355,   356,   357,   358,   359,  1223,   735,   736,   737,
    1688,  1743,  1744,  1737,  1738,  1745,  1739,  1224,  1225,   360,
     361,  1226,   362,   363,   364,   365,   366,   367,   368,   369,
     937,  1408,  1360,  1073,  1520,  1074,  1097,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,   711,  1710,
     370,  1086,  1087,  1088,  1089,   371,   372,   373,   374,   375,
     376,   759,   760,   377,  1258,  1259,  1600,  1005,  1044,  1320,
    1321,  1045,  1046,  1047,  1048,  1049,  1330,  1503,  1504,  1050,
    1333,  1051,  1484,  1052,  1053,  1338,  1339,  1509,  1507,  1322,
    1323,  1324,  1325,  1627,   672,   901,   902,   903,   904,   905,
     906,  1138,  1550,  1658,  1139,  1548,  1656,   907,  1373,  1545,
    1541,  1542,  1543,   908,   909,  1326,  1334,  1494,  1327,  1490,
    1311,   378,   379,   380,   381,   492,   382,   383,   384,   385,
     386,  1090,  1091,  1092,  1093,  1173,   493,   387,   388,   389
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -928;
  const short int
  jsoniq_parser::yytable_[] =
  {
       304,   304,   304,   304,   304,   308,   308,   308,   308,   308,
     537,   502,   506,   394,   397,   398,   826,   967,   510,   422,
     579,  1029,   560,   839,   644,   644,  1190,   945,   552,  1072,
    1095,   827,   828,   829,   830,   631,  1177,   955,  1421,   845,
    1030,  1222,   749,  1306,  1411,   788,   790,   755,   782,   786,
     789,   791,  1573,   544,   545,  1577,  1453,  1454,  1282,   553,
    1154,  1111,   553,   780,   784,  1155,   555,  1289,   861,   553,
       7,     8,  1033,  1505,  1026,   559,  1312,   814,  1429,   815,
     816,   557,   817,   553,   819,  1180,   553,   396,   396,   396,
     400,   407,   820,   821,   553,  1491,   553,  1401,  1143,   553,
     553,  1698,   723,  1664,  1574,   304,  1115,   647,   553,   553,
     308,  1686,  1042,   553,   553,  1286,  1147,   562,  1166,   410,
     553,   553,   436,   942,     7,     8,  1031,  1685,  1027,  1178,
     560,   484,   553,   935,   560,  1027,   516,  1401,   695,   699,
     553,   783,  1335,  1336,   553,   407,   539,   541,     9,  1313,
     740,   494,  -171,   553,   507,   408,  1401,   678,   856,   401,
     395,   395,   395,   399,  1271,  1337,   511,   564,   514,   402,
     564,  1181,  1575,   410,  1010,  1141,  1659,  1486,   411,  1290,
    1142,  1143,   856,  1402,   426,  1273,  1028,   427,  1470,  1144,
     550,   490,  1491,   561,   564,  1575,  1145,  1753,  1146,  1147,
     563,  1687,   564,  1118,   943,   403,   404,  1148,   405,   406,
     412,   413,  1015,   646,  1665,   553,   579,  1487,   559,  1312,
     437,   564,   564,  1563,   560,   553,   409,   553,   564,   564,
      77,   992,   986,  1601,  1149,  1034,  1314,  1315,   857,  1316,
     564,  1511,  1568,  1165,    87,   437,  1291,  1212,   564,   304,
     304,   553,   564,   304,   308,   308,  1318,   553,   308,  1492,
     554,   564,   858,  1287,   395,  1292,   788,   790,  1319,   101,
    1404,  1411,   731,  1039,   556,  1035,  1040,  1112,  1391,  1429,
    1101,   437,  1265,   553,   780,   784,  1222,   775,   304,  1657,
     777,  1012,  1313,   308,  1351,  1222,  1666,   122,   922,  1014,
    1264,   561,   733,  1038,   553,   561,   941,   801,   928,   437,
    1154,  1483,  1365,   667,  1461,  1155,   437,  1730,   437,   741,
     947,   517,   553,   564,   682,     9,   781,   785,   948,   415,
    1042,  1042,   996,   564,   685,   564,   679,   692,  -171,   148,
     149,   150,   925,   553,   680,   694,   704,   774,  1766,   709,
     710,   722,  1294,  -172,   553,   716,  1492,  1493,   553,   564,
     776,   778,  1386,   993,   428,   564,  1150,   553,   553,   887,
     793,  1620,  1260,  1539,  1774,  1102,  1777,   772,   771,  1314,
    1315,   430,  1316,  1041,   520,   553,   521,   942,     9,  1317,
     418,   564,   630,   416,   526,   561,   304,  1102,   419,  1318,
     304,   308,   933,  1208,   792,   308,   420,    77,   794,   723,
     953,  1319,   564,   738,   739,  1209,   122,   446,   553,   973,
     743,    87,   926,   523,   968,   524,   553,   304,   304,  1261,
     564,   528,   308,   308,   417,  1634,   529,   646,  1540,  1210,
     765,   767,   970,   304,  1723,  1043,   101,   304,   308,  1621,
    1039,   564,   308,  1040,   655,  1103,   553,   659,  1151,  1152,
    1070,   511,   564,  1370,   673,   674,   564,   985,   957,  1636,
      77,  1694,   511,   522,   122,   564,   564,  1104,   974,  1105,
    1381,   977,   700,   527,    87,   981,   724,   935,   707,   971,
     304,   969,   712,   564,   447,   308,  1222,   717,  1463,   304,
     560,   788,   790,   788,   308,  1768,  1266,  1267,  1268,   101,
    1695,  1246,   525,   400,   400,  1635,   148,   149,   150,   429,
     530,  1366,   696,  1372,  1751,  1471,   564,  1016,   485,   400,
     846,  1696,   707,   400,   564,   841,   304,  1519,   847,  -172,
     944,   308,   441,   304,   729,   494,   686,  1009,   308,  1637,
    1378,   485,   972,   998,   304,   304,   304,   304,   422,   308,
     308,   308,   308,   485,   564,   485,   448,   449,   975,   697,
    1100,   494,  1640,   304,     7,     8,  1213,   761,   308,   148,
     149,   150,   662,  1106,   663,   396,   683,   684,  1119,  1120,
    1013,  1027,   929,  1123,   778,   932,  1646,  1599,  1042,  1459,
    1107,  1411,   708,  1481,  1648,  1653,   713,  1042,   432,   978,
     979,  1752,   632,   982,   983,   687,  1027,   664,  1042,   935,
     611,   960,   766,  1163,   980,     7,     8,   976,   984,   656,
     806,   962,   963,   964,   806,   767,   403,   404,   612,   405,
     406,  1757,  1462,  1214,   665,   433,   407,   633,   662,   634,
     663,   584,  1641,   585,  1261,   434,   408,   409,   395,   614,
    1671,   558,   657,  1043,  1043,  1735,  1357,  1608,   442,  1215,
    1308,   997,  1293,  1570,   410,   652,  1647,   567,   511,   411,
     549,   568,   435,  1609,  1649,  1654,   569,   890,   615,   891,
     304,   653,  1740,  1746,   122,   308,   550,  1571,  1358,   567,
    1108,   616,   927,   568,  1581,   570,   666,   883,   569,  1585,
     665,   412,   413,   414,   304,   304,  1359,  1109,   586,   308,
     308,   913,  1498,   587,  1296,   917,   918,   570,  1135,  1297,
    1254,   935,   923,   892,  1439,  1624,   617,   988,   877,   631,
     511,  1296,  1625,   511,  1740,  1136,  1297,   938,  1298,  1679,
    1746,  1370,  1626,   788,   935,   618,  1488,   632,  1121,  1122,
     415,   620,   632,  1489,   619,  1677,   304,  1027,  1371,   494,
     588,   308,   666,  1571,  1404,   621,   396,  1554,  1735,   936,
     965,   878,  1215,   783,  1027,  1218,   879,  1219,  1137,  1299,
     444,  1042,   633,   304,   634,  1736,   422,   633,   308,   634,
     400,   400,   954,  1683,   571,   611,   793,   572,   567,  1215,
    1216,  1372,   568,  1773,  1006,  1220,  1011,   569,   778,   935,
    1187,  1794,   573,   612,   416,  1296,   571,  1571,  -847,   572,
    1297,  1456,  1714,  1398,  1715,   611,   570,  1571,  1262,   611,
    1215,   445,  -927,  1017,   732,  1571,   613,  1795,   574,   395,
     654,   485,  -847,   612,   485,  1135,  1032,   612,   485,   443,
    1741,   485,   485,  -847,  1689,   417,  -927,  1457,  1692,   485,
     574,  1571,  1136,   951,   952,  1389,  1707,  -927,  1230,   485,
    1231,  1094,  1094,  1098,  1098,   485,  1215,  1216,   893,   485,
    1110,   418,  1215,  1216,   485,  1622,  1623,   575,  1218,   419,
    1219,   894,  1619,   895,  1387,  1217,   690,   420,  1780,   935,
    1763,  1270,  1113,   450,   896,   897,   898,   451,   899,   575,
     900,  1271,  1271,  1094,  1113,  1218,  1364,  1219,  1220,   485,
    1215,  1043,  1272,  1215,  1216,   571,   486,  1128,   572,  1187,
    1043,   485,   690,  1273,  1305,  1663,   648,   650,  1157,   304,
    1741,  1043,  1403,  1445,   308,  1220,  1218,  1158,  1219,   108,
     649,   651,  1160,   508,  1409,  1412,   509,  1742,   579,   518,
    1094,  1409,  1748,  1624,   485,  1449,   120,  1410,  1413,   574,
    1625,  1094,  1217,  1724,  1580,   515,  1220,  1409,  1217,   676,
    1626,  1709,   532,  1712,   677,  1129,  1255,  1221,  1131,   519,
    1786,  1256,  1218,  1717,  1219,  1718,  1130,   531,  1218,  1132,
    1219,   878,   304,   304,   304,   143,   879,   308,   308,   308,
     422,  1450,  1451,  1705,  1706,   824,   825,   485,   575,  1217,
     533,   485,  1220,   831,   832,   400,   108,   534,  1220,  1124,
    1125,  1126,   108,   833,   834,  1127,  1218,   535,  1219,  1218,
    1235,  1219,  1236,   120,   668,   669,   670,  1783,   536,   120,
    1376,  1377,  1663,  1650,  1651,   546,   542,   566,  1279,   590,
     591,   806,   609,   610,  1423,   485,  1220,   622,   623,  1220,
    1428,   624,   637,   108,   625,   629,   537,   638,   639,   646,
     640,   641,   143,   642,  1559,   658,   660,   661,   143,   671,
     120,   863,   675,   690,   485,   693,   701,   702,  1198,   703,
    1756,  1094,   714,   715,   718,   722,  1663,   720,   485,   725,
     726,  1583,   485,   485,  1043,   727,   728,   734,   730,   485,
     742,   744,   745,   746,   757,   758,  1565,   485,   762,   143,
     485,   763,   779,   768,   485,   864,   865,   866,   867,   868,
     869,   870,   871,   872,   873,   797,   799,   798,   807,   810,
    1602,   800,   822,   808,   304,   835,   836,   837,   838,   308,
     304,   633,   853,   859,   862,   308,  1385,   485,   860,   801,
     884,   885,   304,   888,   889,   910,   912,   308,   911,   914,
     919,   920,   921,   916,  1394,  1805,   924,  1806,   931,   930,
     946,   304,   950,   934,   949,   987,   308,  1814,   989,   995,
     990,   485,   991,  1416,  1094,  1011,  1018,  1022,   994,  1025,
     304,  1008,  1114,   879,   935,   308,  1133,   304,  1134,   707,
    1156,  1161,   308,  1164,   686,  1162,  1168,  1169,  1170,  1094,
     485,  1171,  1174,  1524,  1176,  1175,  1183,  1186,  1182,  1187,
     396,  1193,  1199,   485,  1200,  1206,  1203,  1207,  1211,  1204,
    1255,  1201,  1228,  1227,  1229,  1256,   664,  1427,   396,  1278,
    1247,  1257,  1280,  1284,  1283,  1328,  1288,  1332,   485,   485,
     485,   485,  1295,  1340,  1309,     9,  1368,   396,  1341,  1329,
    1669,  1342,  1369,   761,  1343,  1344,  1345,  1374,  1390,  1346,
    1347,  1673,  1565,  1006,  1675,  1379,   400,  1006,  1361,  1348,
    1380,  1384,  1684,   400,  1349,  1350,  1352,  1353,  1383,  1354,
     485,  1393,  1355,   395,  1356,  1422,  1409,   806,  1425,  1415,
    1464,  1420,  1438,  1433,   485,  1434,  1437,  1442,  1435,  1260,
    1431,   395,  1441,  1271,  1443,  1478,   766,  1596,  1597,  1598,
    1444,  1466,  1472,  1474,  1436,  1468,  1475,   592,  1480,   485,
     395,  1432,  1476,  1482,  1501,   593,   594,   485,   595,  1502,
    1508,  1510,  1485,  1495,  1506,  1538,   596,  1521,   485,  1426,
     597,  1544,   598,  1527,  1531,  1549,  1430,   599,  1516,  1094,
    1532,   511,  1525,  1526,  1533,  1530,  1534,  1535,  1536,  1537,
    1547,  1551,   304,  1555,   600,  1556,  1557,   308,  1558,  1562,
    1604,  1561,  1606,  1611,  1630,  1567,  1578,  1675,  1553,  1579,
    1632,  1638,  1655,  1584,  1135,  1552,  1587,  1618,   601,   602,
     603,   604,   605,   606,  1633,  1639,  1642,  1643,  1644,  1645,
    1592,  1660,  1668,  1674,   491,  1255,  1456,  1702,  1704,  1716,
    1256,  1631,  1569,  1691,  1719,  1094,  1726,  1721,  1094,  1722,
    1667,  1720,  1731,  1732,  1733,   485,  1775,  1747,   485,  1582,
    1727,  1749,  1755,  1750,  1586,  1758,  1759,  1760,  1761,  1769,
    1762,  1764,  1765,  1771,  1387,  1778,  1779,  1772,  1782,  1789,
    1791,  1796,  1797,  1785,  1798,  1804,  1807,  1811,   886,  1801,
    1810,  1367,  1116,  1167,  1697,  1808,   547,  1792,   485,  1803,
    1813,   548,  1382,   551,  1767,  1729,  1007,   681,  1304,  1616,
     809,  1614,  1615,   645,   940,  1479,  1460,  1269,  1452,  1792,
    1455,  1395,   719,  1399,  1405,  1708,  1414,   812,  1775,  1099,
    1448,   813,   843,   852,   823,   844,   628,   855,  1424,  1784,
     966,  1781,  1512,  1513,  1713,  1440,  1255,  1447,  1446,  1496,
    1500,  1256,  1307,  1629,  1499,  1628,  1331,  1255,  1255,  1375,
     304,  1140,  1256,  1256,  1546,   308,  1652,  1497,  1255,     0,
     753,     0,     0,  1256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   485,     0,     0,     0,     0,     0,  1094,  1678,     0,
    1680,     0,  1682,     0,     0,     0,   485,     0,     0,  1690,
       0,     0,     0,     0,     0,     0,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   485,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1711,     0,  1711,  1255,  1094,     0,  1094,     0,  1256,     0,
     485,     0,   712,     0,   712,     0,     0,     0,     0,     0,
     485,     0,     0,     0,   485,     0,     0,     0,     0,     0,
    1725,     0,     0,  1728,     0,     0,     0,     0,     0,     0,
    1094,     0,     0,     0,   485,     0,     0,   485,     0,     0,
       0,  1734,   304,     0,     0,     0,     0,   308,     0,     0,
       0,     0,   485,     0,     0,     0,     0,     0,     0,     0,
    1255,     0,     0,     0,     0,  1256,     0,     0,     0,     0,
       0,     0,  1094,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1770,   304,     0,     0,     0,  1094,   308,  1094,
       0,     0,     0,     0,     0,   485,   485,     0,   485,   485,
     485,     0,   485,     0,     0,  1255,     0,     0,     0,     0,
    1256,  1787,     0,     0,  1255,     0,     0,     0,     0,  1256,
       0,     0,     0,     0,     0,     0,     0,  1790,     0,     0,
       0,     0,   485,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1799,   491,     0,
       0,     0,  1800,     0,     0,     0,     0,     0,     0,   485,
       0,     0,   485,     0,  1809,   485,     0,  1812,     0,   747,
     748,     0,   750,   751,   752,   754,   485,   756,     0,     0,
       0,   485,     0,   764,     0,     0,     0,     0,     0,     0,
       0,   773,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   795,   796,     0,     0,     0,     0,     0,
       0,     0,   802,   803,     0,     0,     0,     0,   485,   485,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   850,     0,     0,     0,   850,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   485,   485,   915,   485,     0,   485,
       0,     0,     0,     0,     0,     0,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   939,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   956,     0,     0,
       0,   958,   959,     0,   961,     0,     0,     0,     0,     0,
       0,   802,     0,     0,     0,     0,     0,   485,     0,   485,
       0,   485,     0,   485,     0,     0,     0,     0,     0,   485,
       0,   485,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   485,     0,     0,
     485,     0,     0,     0,     0,     0,     0,   485,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   485,     0,
       0,     0,   796,     0,     0,     0,     0,     0,  1019,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   485,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   485,
       0,     0,     0,     0,   485,     0,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   485,     0,     0,     0,  1117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   485,     0,     0,     0,     0,   485,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   485,     0,  1159,   485,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1179,     0,     0,     0,     0,
       0,     0,  1184,  1185,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1202,     0,     0,  1205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1232,  1233,  1234,
       0,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,
       0,     0,  1248,  1249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1263,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1019,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1285,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1363,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1388,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1392,
       0,     0,     0,     0,     0,  1396,  1397,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1417,     0,     0,  1418,  1419,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1019,     0,     0,
       0,     0,     0,     0,     0,  1465,     0,  1467,     0,  1469,
       0,     0,  1473,     0,     0,     0,     0,  1477,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1560,     0,     0,     0,     0,     0,     0,     0,
    1564,  1566,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1388,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1588,  1589,  1590,  1591,     0,  1593,  1594,     0,
    1595,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1603,     0,     0,     0,
       0,  1605,     0,     0,     0,  1607,     0,     0,     0,  1610,
       0,  1612,     0,  1613,     0,     0,     0,     0,     0,  1617,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1670,     0,     0,     0,
       0,  1672,  1566,     0,     0,     0,     0,     0,     0,  1676,
       0,     0,     0,     0,  1681,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1693,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1699,     0,  1700,     0,  1701,     0,     0,
    1703,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1676,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1754,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1776,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -167,   783,     0,     0,     0,     0,     0,  1788,     0,
       0,     0,  1793,     0,     0,     0,     0,  1776,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,  1793,     0,    10,   391,  1802,    12,    13,
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
     139,   140,     0,     0,   141,   142,   143,     0,   393,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     0,   242,
       0,   243,   244,   245,   246,   247,     0,   248,  -167,   783,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,   787,   391,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   392,    26,
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
       0,   141,   142,   143,     0,   393,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   783,   242,     0,   243,   244,
     245,   246,   247,     0,   248,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,   390,   391,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   392,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   393,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   783,   242,     0,   243,   244,   245,   246,   247,     0,
     248,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   390,   391,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   495,
     392,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   496,   497,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   467,    80,    81,    82,    83,    84,
     498,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   499,   106,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   393,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   477,   478,   479,   174,   175,   480,
     501,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,   242,     0,
     243,   244,   245,   246,   247,     0,   248,   999,  1000,     0,
       0,     0,     0,     0,     0,     0,  1001,     0,     0,     0,
       0,     5,     6,     0,     0,     0,     0,     0,     0,     0,
     390,   391,     0,    12,    13,    14,   453,    16,    17,    18,
     454,    20,   455,   456,   457,   458,   392,    26,   459,    28,
      29,    30,     0,    31,    32,    33,    34,   460,    36,    37,
      38,    39,    40,    41,    42,   461,     0,    44,   462,    46,
     463,   464,    49,   465,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,   466,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     467,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   468,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
     104,     0,     0,     0,     0,     0,     0,   110,   469,     0,
       0,     0,     0,   112,   113,   114,   115,   470,   117,   118,
     119,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,  1002,     0,   129,     0,   130,   131,   132,   133,
     471,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   393,     0,   146,   147,     0,     0,     0,
     151,   152,   153,   154,   155,   156,   472,   158,   473,   160,
     474,   475,   163,   164,   165,   166,   167,   168,   476,   170,
     477,   478,   479,   174,   175,   480,   481,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   482,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     0,     0,     0,     0,   243,   483,   245,   246,
     247,   487,   248,     0,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,   390,
     391,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   392,    26,    27,    28,    29,
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
       0,   488,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   393,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     0,   242,     0,   243,   244,   245,   246,   247,
     487,   248,     0,     0,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,   390,   391,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   392,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   393,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,   242,     0,   243,   244,   245,   246,   247,   487,
     248,     0,     0,     0,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   390,   391,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   495,   392,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,   496,   497,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,   467,    80,    81,
      82,    83,    84,   498,    86,     0,     0,     0,     0,    87,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   499,   106,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     393,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   477,   478,   479,
     174,   175,   480,   501,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       0,   242,   487,   243,   244,   245,   246,   247,     0,   248,
       0,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     390,   391,     0,    12,    13,    14,   453,    16,    17,    18,
     454,    20,   455,   456,   457,   458,   392,    26,   459,    28,
      29,    30,     0,    31,    32,    33,    34,   460,    36,    37,
      38,    39,    40,    41,    42,   461,     0,    44,   462,    46,
     463,   464,    49,   465,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,   466,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     467,    80,    81,    82,    83,    84,   498,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   468,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
     104,     0,     0,     0,   107,     0,     0,   110,   469,     0,
       0,     0,     0,   112,   113,   114,   115,   470,   117,   118,
     119,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,   842,     0,   129,     0,   130,   131,   132,   133,
     471,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   393,     0,   146,   147,     0,     0,     0,
     151,   152,   153,   154,   155,   156,   472,   158,   473,   160,
     474,   475,   163,   164,   165,   166,   167,   168,   476,   170,
     477,   478,   479,   174,   175,   480,   481,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   482,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     0,     0,   487,     0,   243,   483,   245,   246,
     247,     0,   248,     5,     6,     0,     0,     0,  1522,     0,
       0,     0,   390,   391,     0,    12,    13,    14,   453,    16,
      17,    18,   454,    20,   455,   456,   457,   458,   392,    26,
     459,    28,    29,    30,     0,    31,    32,    33,    34,   460,
      36,    37,    38,    39,    40,    41,    42,   461,     0,    44,
     462,    46,   463,   464,    49,   465,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,   466,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
       0,    78,   467,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   468,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,   104,     0,     0,     0,     0,     0,     0,   110,
     469,     0,     0,     0,     0,   112,   113,   114,   115,   470,
     117,   118,   119,     0,     0,     0,     0,     0,     0,     0,
     123,   124,   125,     0,     0,     0,   126,  1523,   127,   128,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   471,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   393,     0,   146,   147,     0,
       0,     0,   151,   152,   153,   154,   155,   156,   472,   158,
     473,   160,   474,   475,   163,   164,   165,   166,   167,   168,
     476,   170,   477,   478,   479,   174,   175,   480,   481,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   482,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,     0,   487,     0,   243,   483,
     245,   246,   247,     0,   248,     5,     6,     0,     0,     0,
       0,     0,     0,     0,   390,   391,     0,    12,    13,    14,
     453,    16,    17,    18,   454,    20,   455,   456,   457,   458,
     392,    26,   459,    28,    29,    30,     0,    31,    32,    33,
      34,   460,    36,    37,    38,    39,    40,    41,    42,   461,
       0,    44,   462,    46,   463,   464,    49,   465,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,   466,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   467,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   468,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,   104,     0,     0,     0,     0,     0,
       0,   110,   469,     0,     0,     0,     0,   112,   113,   114,
     115,   470,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   471,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   393,     0,   146,
     147,     0,     0,     0,   151,   152,   153,   154,   155,   156,
     472,   158,   473,   160,   474,   475,   163,   164,   165,   166,
     167,   168,   476,   170,   477,   478,   479,   174,   175,   480,
     481,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   482,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,     0,     0,     0,
     243,   483,   245,   246,   247,     0,   248,   512,   513,     0,
       0,     0,     0,     0,     5,     6,     0,     0,     0,     0,
       0,     0,     0,   390,   391,     0,    12,    13,    14,   453,
      16,    17,    18,   454,    20,   455,   456,   457,   458,   392,
      26,   459,    28,    29,    30,     0,    31,    32,    33,    34,
     460,    36,    37,    38,    39,    40,    41,    42,   461,     0,
      44,   462,    46,   463,   464,    49,   465,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,   466,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,     0,    78,   467,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,   468,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
       0,   102,   103,   104,     0,     0,     0,     0,     0,     0,
     110,   469,     0,     0,     0,     0,   112,   113,   114,   115,
     470,   117,   118,   119,     0,     0,     0,     0,     0,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   471,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   393,     0,   146,   147,
       0,     0,     0,   151,   152,   153,   154,   155,   156,   472,
     158,   473,   160,   474,   475,   163,   164,   165,   166,   167,
     168,   476,   170,   477,   478,   479,   174,   175,   480,   481,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   482,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,     0,     0,     0,   243,
     483,   245,   246,   247,     0,   248,     1,     2,     3,     4,
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
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     0,   242,     0,   243,   244,   245,   246,   247,
       0,   248,   249,   250,     1,     2,     3,     4,     5,     6,
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
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       0,   242,     0,   243,   244,   245,   246,   247,     0,   248,
       0,   543,     1,     2,     3,     4,     5,     6,     7,     8,
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
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     0,   242,
       0,   243,   244,   245,   246,   247,     0,   248,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,   390,   391,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   392,    26,    27,
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
     124,   125,     0,   721,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   393,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     0,   242,     0,   243,   244,   245,
     246,   247,     0,   248,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,   390,   391,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   392,    26,    27,    28,    29,    30,     0,
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
       0,   121,   122,     0,     0,   123,   124,   125,     0,   488,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     393,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       0,   242,     0,   243,   244,   245,   246,   247,     0,   248,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,   390,   391,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,  1250,   392,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,  1251,  1252,    49,    50,    51,    52,    53,
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
       0,   123,   124,   125,     0,   488,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   393,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,  1253,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     0,   242,     0,   243,
     244,   245,   246,   247,     0,   248,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,   390,
     391,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   392,    26,    27,    28,    29,
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
     143,     0,   393,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     0,   242,     0,   243,   244,   245,   246,   247,
       0,   248,     1,     2,     3,     4,     5,     6,     7,     8,
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
     139,   140,     0,     0,   141,   142,   143,     0,   393,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     0,   242,
       0,   243,   244,   245,   246,   247,     0,   248,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,    10,   391,     0,    12,    13,    14,    15,    16,    17,
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
     141,   142,   143,     0,   393,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     0,   242,     0,   243,   244,   245,
     246,   247,     0,   248,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,   787,   391,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   392,    26,    27,    28,    29,    30,     0,
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
     393,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       0,   242,     0,   243,   244,   245,   246,   247,     0,   248,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     9,
       0,     0,     0,   390,   391,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   495,   392,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,   496,   497,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,   467,    80,    81,    82,    83,    84,   498,
      86,     0,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,   848,     0,    98,    99,   100,
     101,   102,   103,   104,   499,   106,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,   849,   127,
     128,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   393,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   477,   478,   479,   174,   175,   480,   501,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     0,   242,     0,   243,
     244,   245,   246,   247,     0,   248,     1,     2,     3,     4,
       5,     6,     0,     0,     0,     9,     0,     0,     0,   390,
     391,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   495,   392,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,   496,
     497,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,   467,
      80,    81,    82,    83,    84,   498,    86,     0,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,   848,     0,    98,    99,   100,   101,   102,   103,   104,
     499,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,   854,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   393,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   477,
     478,   479,   174,   175,   480,   501,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     0,   242,     0,   243,   244,   245,   246,   247,
       0,   248,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,   390,   391,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
    1250,   392,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,  1251,  1252,    49,    50,    51,
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
     139,   140,     0,     0,   141,   142,   143,     0,   393,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,  1253,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     0,   242,
       0,   243,   244,   245,   246,   247,     0,   248,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     9,     0,     0,
       0,   390,   391,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   495,   392,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,   496,   497,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,   467,    80,    81,    82,    83,    84,   498,    86,     0,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   499,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,   500,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   393,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   477,   478,   479,   174,   175,   480,   501,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     0,   242,     0,   243,   244,   245,
     246,   247,     0,   248,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   390,   391,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   495,   392,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,   496,   497,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,   467,    80,    81,
      82,    83,    84,   498,    86,     0,     0,     0,     0,    87,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   499,   106,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,   505,   127,   128,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     393,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   477,   478,   479,
     174,   175,   480,   501,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       0,   242,     0,   243,   244,   245,   246,   247,     0,   248,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     9,
       0,     0,     0,   390,   391,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   495,   392,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,   496,   497,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,   467,    80,    81,    82,    83,    84,   498,
      86,     0,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   499,   106,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   393,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   477,   478,   479,   174,   175,   480,   501,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   538,   242,     0,   243,
     244,   245,   246,   247,     0,   248,     1,     2,     3,     4,
       5,     6,     0,     0,     0,     9,     0,     0,     0,   390,
     391,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   495,   392,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,   496,
     497,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,   467,
      80,    81,    82,    83,    84,   498,    86,     0,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     499,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   393,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   477,
     478,   479,   174,   175,   480,   501,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     0,   242,   540,   243,   244,   245,   246,   247,
       0,   248,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     9,     0,     0,     0,   390,   391,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     495,   392,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,   496,   497,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,   467,    80,    81,    82,    83,
      84,   498,    86,     0,     0,     0,     0,    87,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   499,   106,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,   840,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   393,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   477,   478,   479,   174,   175,
     480,   501,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     0,   242,
       0,   243,   244,   245,   246,   247,     0,   248,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     9,     0,     0,
       0,   390,   391,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   495,   392,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,   496,   497,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,   467,    80,    81,    82,    83,    84,   498,    86,     0,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,  1362,     0,    98,    99,   100,   101,   102,
     103,   104,   499,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   393,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   477,   478,   479,   174,   175,   480,   501,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     0,   242,     0,   243,   244,   245,
     246,   247,     0,   248,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   390,   391,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     456,    23,   458,   392,    26,   459,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   461,     0,    44,    45,    46,   463,   464,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,   467,    80,    81,
      82,    83,    84,   498,    86,     0,     0,     0,     0,    87,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     468,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   499,   106,
       0,   107,   108,   626,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   627,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     393,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   472,   158,   473,   160,   474,   475,   163,
     164,   165,   166,   167,   168,   476,   170,   477,   478,   479,
     174,   175,   480,   481,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   482,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       0,   242,     0,   243,   483,   245,   246,   247,     0,   248,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     9,
       0,     0,     0,   390,   391,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   495,   392,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,   496,   497,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,   467,    80,    81,    82,    83,    84,   498,
      86,     0,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   499,   106,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   393,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   477,   478,   479,   174,   175,   480,   501,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     0,   242,     0,   243,
     244,   245,   246,   247,     0,   248,     1,     2,     3,     4,
       5,     6,     0,     0,     0,     9,     0,     0,     0,   390,
     391,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,   456,    23,   458,   392,    26,   459,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   461,     0,    44,    45,    46,   463,
     464,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,   467,
      80,    81,    82,    83,    84,   498,    86,     0,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   468,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     499,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   393,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   472,   158,   473,   160,   474,
     475,   163,   164,   165,   166,   167,   168,   476,   170,   477,
     478,   479,   174,   175,   480,   481,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   482,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     0,   242,     0,   243,   483,   245,   246,   247,
       0,   248,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     9,     0,     0,     0,   390,   391,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   456,    23,
     458,   392,    26,   459,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     461,     0,    44,    45,    46,   463,   464,    49,   465,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,   467,    80,    81,    82,    83,
      84,   498,    86,     0,     0,     0,     0,    87,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   468,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   499,   106,     0,   107,
     108,     0,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,     0,
       0,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   393,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   472,   158,   473,   160,   474,   475,   163,   164,   165,
     166,   167,   168,   476,   170,   477,   478,   479,   174,   175,
     480,   481,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   482,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     0,   242,
       0,   243,   483,   245,   246,   247,     0,   248,     5,     6,
       0,     0,     0,     0,     0,     0,     0,   390,   391,     0,
      12,    13,    14,  1054,    16,    17,    18,   454,  1055,  1056,
     456,  1057,   458,   392,    26,   459,    28,  1058,    30,     0,
      31,    32,    33,    34,  1059,    36,  1060,  1061,    39,    40,
      41,    42,   461,     0,    44,  1062,    46,   463,   464,    49,
     465,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,  1063,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   467,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     468,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,  1064,     0,     0,
       0,  1065,     0,     0,   110,   469,     0,     0,     0,     0,
     112,   113,   114,   115,   470,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,   123,   124,   125,     0,     0,
       0,   126,  1517,   127,   128,     0,     0,     0,     0,  1518,
       0,   129,     0,   130,   131,   132,   133,   471,   135,   136,
     137,   138,   139,   140,     0,     0,  1066,   142,     0,     0,
     393,     0,   146,   147,     0,     0,     0,   151,   152,   153,
     154,   155,   156,   472,  1067,   473,   160,   474,   475,   163,
     164,   165,   166,   167,   168,   476,   170,   477,   478,   479,
     174,   175,   480,   481,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   482,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
       0,     5,     6,   243,   483,   245,  1068,  1069,  1070,  1071,
     390,   391,     0,    12,    13,    14,  1054,    16,    17,    18,
     454,  1055,  1056,   456,  1057,   458,   392,    26,   459,    28,
    1058,    30,     0,    31,    32,    33,    34,  1059,    36,  1060,
    1061,    39,    40,    41,    42,   461,     0,    44,  1062,    46,
     463,   464,    49,   465,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,  1063,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     467,    80,    81,    82,    83,    84,  1406,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   468,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
    1064,     0,     0,     0,  1065,     0,     0,   110,   469,     0,
       0,     0,     0,   112,   113,   114,   115,   470,   117,   118,
     119,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     471,   135,   136,   137,   138,   139,   140,     0,     0,  1066,
     142,     0,     0,   393,     0,   146,   147,     0,     0,     0,
     151,   152,   153,   154,   155,   156,   472,  1067,   473,   160,
     474,   475,   163,   164,   165,   166,   167,   168,   476,   170,
     477,   478,   479,   174,   175,   480,   481,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   482,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     0,     0,     5,     6,   243,   483,   245,  1068,
    1069,  1070,  1071,   390,   391,     0,    12,    13,    14,  1054,
      16,    17,    18,   454,  1055,  1056,   456,  1057,   458,   392,
      26,   459,    28,  1058,    30,     0,    31,    32,    33,    34,
    1059,    36,  1060,  1061,    39,    40,    41,    42,   461,     0,
      44,  1062,    46,   463,   464,    49,   465,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,  1063,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,     0,    78,   467,    80,    81,    82,    83,    84,  1572,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,   468,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
       0,   102,   103,  1064,     0,     0,     0,  1065,     0,     0,
     110,   469,     0,     0,     0,     0,   112,   113,   114,   115,
     470,   117,   118,   119,     0,     0,     0,     0,     0,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   471,   135,   136,   137,   138,   139,   140,
       0,     0,  1066,   142,     0,     0,   393,     0,   146,   147,
       0,     0,     0,   151,   152,   153,   154,   155,   156,   472,
    1067,   473,   160,   474,   475,   163,   164,   165,   166,   167,
     168,   476,   170,   477,   478,   479,   174,   175,   480,   481,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   482,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,     0,     5,     6,   243,
     483,   245,  1068,  1069,  1070,  1071,   390,   391,     0,    12,
      13,    14,  1054,    16,    17,    18,   454,  1055,  1056,   456,
    1057,   458,   392,    26,   459,    28,  1058,    30,     0,    31,
      32,    33,    34,  1059,    36,  1060,  1061,    39,    40,    41,
      42,   461,     0,    44,  1062,    46,   463,   464,    49,   465,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,  1063,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   467,    80,    81,    82,
      83,    84,  1576,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   468,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,  1064,     0,     0,     0,
    1065,     0,     0,   110,   469,     0,     0,     0,     0,   112,
     113,   114,   115,   470,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   471,   135,   136,   137,
     138,   139,   140,     0,     0,  1066,   142,     0,     0,   393,
       0,   146,   147,     0,     0,     0,   151,   152,   153,   154,
     155,   156,   472,  1067,   473,   160,   474,   475,   163,   164,
     165,   166,   167,   168,   476,   170,   477,   478,   479,   174,
     175,   480,   481,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   482,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,     0,
       5,     6,   243,   483,   245,  1068,  1069,  1070,  1071,   390,
     391,     0,    12,    13,    14,  1054,    16,    17,    18,   454,
    1055,  1056,   456,  1057,   458,   392,    26,   459,    28,  1058,
      30,     0,    31,    32,    33,    34,  1059,    36,  1060,  1061,
      39,    40,    41,    42,   461,     0,    44,  1062,    46,   463,
     464,    49,   465,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,  1063,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   467,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   468,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,  1064,
       0,     0,     0,  1065,     0,     0,   110,   469,     0,     0,
       0,     0,   112,   113,   114,   115,   470,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   471,
     135,   136,   137,   138,   139,   140,     0,     0,  1066,   142,
       0,     0,   393,     0,   146,   147,     0,     0,     0,   151,
     152,   153,   154,   155,   156,   472,  1067,   473,   160,   474,
     475,   163,   164,   165,   166,   167,   168,   476,   170,   477,
     478,   479,   174,   175,   480,   481,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   482,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,     0,     5,     6,   243,   483,   245,  1068,  1069,
    1070,  1071,   390,   391,     0,    12,    13,    14,  1054,    16,
      17,    18,   454,  1055,  1056,   456,  1057,   458,   392,    26,
     459,    28,  1058,    30,     0,    31,    32,    33,    34,  1059,
      36,  1060,  1061,    39,    40,    41,    42,   461,     0,    44,
    1062,    46,   463,   464,    49,   465,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,  1063,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
       0,    78,   467,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   468,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,  1064,     0,     0,     0,  1065,     0,     0,   110,
     469,     0,     0,     0,     0,   112,   113,   114,   115,   470,
     117,   118,   119,     0,     0,     0,     0,     0,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   471,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   393,     0,   146,   147,     0,
       0,     0,   151,   152,   153,   154,   155,   156,   472,  1067,
     473,   160,   474,   475,   163,   164,   165,   166,   167,   168,
     476,   170,   477,   478,   479,   174,   175,   480,   481,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   482,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,     0,     5,     6,   243,   483,
     245,  1068,  1069,  1070,  1071,   390,   391,     0,    12,    13,
      14,   453,    16,    17,    18,   454,    20,   455,   456,   457,
     458,   392,    26,   459,    28,    29,    30,     0,    31,    32,
      33,    34,   460,    36,    37,    38,    39,    40,    41,    42,
     461,     0,    44,   462,    46,   463,   464,    49,   465,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
     466,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   467,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   468,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,   102,   103,   104,     0,     0,     0,     0,
       0,     0,   110,   469,     0,     0,     0,     0,   112,   113,
     114,   115,   470,   117,   118,   119,     0,     0,     0,     0,
       0,     0,     0,   123,   124,   125,     0,     0,     0,   126,
    1514,   127,   128,     0,     0,     0,     0,  1515,     0,   129,
       0,   130,   131,   132,   133,   471,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   393,     0,
     146,   147,     0,     0,     0,   151,   152,   153,   154,   155,
     156,   472,   158,   473,   160,   474,   475,   163,   164,   165,
     166,   167,   168,   476,   170,   477,   478,   479,   174,   175,
     480,   481,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   482,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,     0,     5,
       6,   243,   483,   245,   246,   247,     0,   248,   390,   391,
       0,    12,    13,    14,   453,    16,    17,    18,   454,    20,
     455,   456,   457,   458,   392,    26,   459,    28,    29,    30,
       0,    31,    32,    33,    34,   460,    36,    37,    38,    39,
      40,    41,    42,   461,     0,    44,   462,    46,   463,   464,
      49,   465,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   466,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   467,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   468,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,   104,     0,
       0,     0,     0,     0,     0,   110,   469,     0,     0,     0,
       0,   112,   113,   114,   115,   470,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,   123,   124,   125,     0,
       0,     0,   126,  1528,   127,   128,     0,     0,     0,     0,
    1529,     0,   129,     0,   130,   131,   132,   133,   471,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   393,     0,   146,   147,     0,     0,     0,   151,   152,
     153,   154,   155,   156,   472,   158,   473,   160,   474,   475,
     163,   164,   165,   166,   167,   168,   476,   170,   477,   478,
     479,   174,   175,   480,   481,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   482,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
       0,     0,     5,     6,   243,   483,   245,   246,   247,     0,
     248,   390,   391,     0,    12,    13,    14,   453,    16,    17,
      18,   454,    20,   455,   456,   457,   458,   392,    26,   459,
      28,    29,    30,     0,    31,    32,    33,    34,   460,    36,
      37,    38,    39,    40,    41,    42,   461,     0,    44,   462,
      46,   463,   464,    49,   465,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,   466,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,     0,
      78,   467,    80,    81,    82,    83,    84,  1281,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   468,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,     0,   102,
     103,   104,     0,     0,     0,     0,     0,     0,   110,   469,
       0,     0,     0,     0,   112,   113,   114,   115,   470,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   471,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   393,     0,   146,   147,     0,     0,
       0,   151,   152,   153,   154,   155,   156,   472,   158,   473,
     160,   474,   475,   163,   164,   165,   166,   167,   168,   476,
     170,   477,   478,   479,   174,   175,   480,   481,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     482,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,     0,     5,     6,   243,   483,   245,
     246,   247,     0,   248,   390,   391,     0,    12,    13,    14,
     453,    16,    17,    18,   454,    20,   455,   456,   457,   458,
     392,    26,   459,    28,    29,    30,     0,    31,    32,    33,
      34,   460,    36,    37,    38,    39,    40,    41,    42,   461,
       0,    44,   462,    46,   463,   464,    49,   465,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,   466,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   467,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   468,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,   104,     0,     0,     0,     0,     0,
       0,   110,   469,     0,     0,     0,     0,   112,   113,   114,
     115,   470,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   471,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   393,     0,   146,
     147,     0,     0,     0,   151,   152,   153,   154,   155,   156,
     472,   158,   473,   160,   474,   475,   163,   164,   165,   166,
     167,   168,   476,   170,   477,   478,   479,   174,   175,   480,
     481,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   482,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,     0,     5,     6,
     243,   483,   245,   246,   247,     0,   248,   390,   391,     0,
      12,    13,    14,     0,    16,    17,    18,   454,     0,     0,
     456,   457,     0,   392,    26,   459,    28,     0,    30,     0,
      31,    32,    33,    34,     0,    36,     0,     0,    39,    40,
      41,    42,   461,     0,    44,     0,    46,     0,     0,    49,
     465,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,     0,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   467,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     468,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,     0,     0,     0,
       0,     0,     0,     0,   110,   469,     0,     0,     0,     0,
     112,   113,   114,   115,   470,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   471,   135,   136,
     137,   138,   139,   140,     0,     0,     0,   142,     0,     0,
     393,     0,   146,   147,     0,     0,     0,   151,   152,   153,
     154,   155,   156,   472,     0,   473,   160,   474,   475,   163,
     164,   165,   166,   167,   168,   476,   170,   477,   478,   479,
     174,   175,     0,   481,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   482,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
       0,     0,     0,   243,   483,   245,   246,   247,     0,   248
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,     1,     2,     3,     4,     0,     1,     2,     3,     4,
     177,   106,   107,     1,     2,     3,   613,   735,   120,    10,
     308,   806,   288,   629,   401,   402,   947,   707,   256,   835,
     836,   614,   615,   616,   617,   338,   934,   717,  1210,   632,
     806,   969,   522,  1040,  1194,   556,   557,   527,   554,   555,
     556,   557,  1409,   249,   250,  1412,  1275,  1276,  1025,     1,
     911,   861,     1,   554,   555,   911,   257,    37,   654,     1,
      27,    28,    57,  1332,    37,   279,    98,   592,  1223,   594,
     595,   272,   597,     1,   599,   144,     1,     1,     2,     3,
       4,    48,   607,   608,     1,    98,     1,   102,    46,     1,
       1,  1603,   109,   120,   120,   105,   877,   403,     1,     1,
     105,    95,   822,     1,     1,   149,    64,   109,   924,    76,
       1,     1,   120,   109,    27,    28,   806,   120,    98,   935,
     396,    85,     1,    96,   400,    98,    31,   102,   434,   435,
       1,     1,   253,   254,     1,    48,   241,   242,    30,   171,
       8,   105,     0,     1,   108,    58,   102,   114,   109,   158,
       1,     2,     3,     4,   108,   276,   120,   109,   122,   158,
     109,   937,   188,    76,    34,    40,  1549,   220,    81,   149,
      45,    46,   109,   188,   162,   129,   149,   155,   149,    54,
      50,   105,    98,   288,   109,   188,    61,  1699,    63,    64,
     192,   185,   109,   883,   190,    38,    39,    72,    41,    42,
     113,   114,   115,    30,   231,     1,   504,   260,   422,    98,
     279,   109,   109,   188,   490,     1,    59,     1,   109,   109,
     112,   109,   239,  1452,    99,   220,   258,   259,   189,   261,
     109,   189,   188,   923,   126,   279,  1031,   965,   109,   249,
     250,     1,   109,   253,   249,   250,   278,     1,   253,   262,
     192,   109,   189,  1029,   105,  1031,   777,   778,   290,   151,
    1191,  1421,   187,   155,   192,   260,   158,   863,  1176,  1424,
     187,   279,   115,     1,   775,   776,  1214,   192,   288,  1548,
     192,   192,   171,   288,  1065,  1223,   313,   179,   186,   192,
     192,   396,   189,   818,     1,   400,   186,   573,   189,   279,
    1161,  1308,  1112,   415,  1281,  1161,   279,  1674,   279,   177,
     189,   216,     1,   109,   426,    30,   554,   555,   189,   162,
    1040,  1041,   189,   109,   429,   109,   293,   432,   186,   221,
     222,   223,   109,     1,   301,   162,   441,   543,  1721,   444,
     445,   123,  1032,     0,     1,   450,   262,   263,     1,   109,
     551,   552,  1168,   241,   155,   109,   231,     1,     1,   665,
     561,    53,   155,   138,  1731,   109,  1733,   319,   317,   258,
     259,   158,   261,   265,   231,     1,   233,   109,    30,   268,
     293,   109,   155,   226,   231,   490,   396,   109,   301,   278,
     400,   396,   698,   189,   558,   400,   309,   112,   562,   109,
     186,   290,   109,   508,   509,   189,   179,    78,     1,   133,
     515,   126,   189,   231,   132,   233,     1,   427,   428,   212,
     109,   231,   427,   428,   267,   109,   236,    30,   203,   189,
     535,   536,   186,   443,  1663,   822,   151,   447,   443,   131,
     155,   109,   447,   158,   408,   189,     1,   411,   323,   324,
     325,   415,   109,    98,   418,   419,   109,   239,   190,   109,
     112,   189,   426,   320,   179,   109,   109,   189,   192,   856,
    1160,    96,   436,   320,   126,    96,   186,    96,   442,   186,
     490,   199,   446,   109,   155,   490,  1424,   451,  1283,   499,
     766,  1012,  1013,  1014,   499,  1724,  1012,  1013,  1014,   151,
     189,   991,   320,   427,   428,   189,   221,   222,   223,   155,
     320,  1114,   115,   158,  1696,  1291,   109,   793,    85,   443,
     632,   189,   486,   447,   109,   630,   536,  1343,   633,   186,
     149,   536,   155,   543,   498,   499,   120,   775,   543,   189,
    1156,   108,   186,   186,   554,   555,   556,   557,   549,   554,
     555,   556,   557,   120,   109,   122,   227,   228,   133,   162,
     186,   525,   109,   573,    27,    28,   132,   531,   573,   221,
     222,   223,    46,   150,    48,   499,   427,   428,   884,   885,
     781,    98,   694,   889,   785,   697,   109,   155,  1308,  1279,
     167,  1751,   443,   186,   109,   109,   447,  1317,   158,   224,
     225,   186,   121,   224,   225,   189,    98,    81,  1328,    96,
     160,   723,   536,   919,   239,    27,    28,   192,   239,   171,
     584,   726,   727,   728,   588,   730,    38,    39,   178,    41,
      42,   186,   149,   199,   108,    25,    48,   156,    46,   158,
      48,     1,   189,     3,   212,    35,    58,    59,   499,   119,
    1558,   114,   204,  1040,  1041,     5,   146,   149,   120,     9,
     155,   766,   149,   188,    76,   168,   189,    43,   632,    81,
      34,    47,    62,  1468,   189,   189,    52,    56,   148,    58,
     690,   184,  1686,  1687,   179,   690,    50,   212,   178,    43,
     150,   161,   690,    47,  1422,    71,   170,   661,    52,  1427,
     108,   113,   114,   115,   714,   715,   196,   167,    68,   714,
     715,   675,  1319,    73,    55,   679,   680,    71,    98,    60,
     996,    96,   686,   102,   243,   275,   196,    96,    96,  1042,
     694,    55,   282,   697,  1738,   115,    60,   701,    79,   188,
    1744,    98,   292,  1264,    96,   203,   274,   121,   130,   131,
     162,   138,   121,   281,   212,  1571,   766,    98,   115,   723,
     120,   766,   170,   212,  1695,   152,   690,  1383,     5,   144,
     734,   139,     9,     1,    98,   125,   144,   127,   158,   120,
     158,  1501,   156,   793,   158,   135,   787,   156,   793,   158,
     714,   715,   144,   188,   170,   160,   997,   173,    43,     9,
      10,   158,    47,   188,   768,   155,    34,    52,  1009,    96,
     102,   188,   188,   178,   226,    55,   170,   212,   123,   173,
      60,   108,  1638,   115,  1640,   160,    71,   212,  1005,   160,
       9,   158,   123,   797,   188,   212,   201,   188,   214,   690,
     407,   408,   147,   178,   411,    98,   810,   178,   415,   155,
      29,   418,   419,   158,  1582,   267,   147,   144,  1586,   426,
     214,   212,   115,   714,   715,  1171,   201,   158,   238,   436,
     240,   835,   836,   837,   838,   442,     9,    10,   257,   446,
     139,   293,     9,    10,   451,  1492,  1493,   263,   125,   301,
     127,   270,  1485,   272,  1170,   105,   155,   309,   135,    96,
    1716,    97,   874,   155,   283,   284,   285,   120,   287,   263,
     289,   108,   108,   877,   886,   125,   139,   127,   155,   486,
       9,  1308,   118,     9,    10,   170,   120,   891,   173,   102,
    1317,   498,   155,   129,  1039,  1551,   184,   184,   305,   949,
      29,  1328,   115,   188,   949,   155,   125,   314,   127,   159,
     198,   198,   916,   155,   102,   102,   155,   136,  1256,   219,
     924,   102,  1690,   275,   531,  1271,   176,   115,   115,   214,
     282,   935,   105,  1663,   115,   155,   155,   102,   105,   139,
     292,  1634,   247,  1636,   144,   269,   996,   197,   269,   219,
     115,   996,   125,  1646,   127,  1648,   280,   120,   125,   280,
     127,   139,  1012,  1013,  1014,   215,   144,  1012,  1013,  1014,
    1011,   130,   131,  1620,  1621,   611,   612,   584,   263,   105,
     247,   588,   155,   618,   619,   949,   159,   248,   155,   283,
     284,   285,   159,   620,   621,   289,   125,   158,   127,   125,
     238,   127,   240,   176,   227,   228,   229,   136,   155,   176,
    1154,  1155,  1668,  1539,  1540,     0,   320,   192,  1022,   169,
      94,  1025,   255,   101,   197,   632,   155,    51,   202,   155,
     197,   103,   147,   159,   104,   195,  1253,   158,   186,    30,
     186,   186,   215,   186,  1390,    48,   154,   120,   215,   252,
     176,   658,   310,   155,   661,     1,   120,   144,   949,   109,
    1707,  1065,   155,   155,   144,   123,  1722,   186,   675,   123,
     158,   197,   679,   680,  1501,   158,   158,    36,   155,   686,
      17,   216,    30,    30,   237,   236,  1402,   694,   192,   215,
     697,   192,     3,   251,   701,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,   120,   172,   170,   290,   120,
    1456,   172,    72,   290,  1164,   237,    96,    96,    96,  1164,
    1170,   156,   151,   109,    30,  1170,  1164,   734,   109,  1445,
     162,   162,  1182,   129,   134,   252,   305,  1182,    96,   144,
     134,   186,   186,   120,  1182,  1801,    96,  1803,    46,    98,
     186,  1201,   186,    98,   155,    96,  1201,  1813,   243,   192,
     231,   768,   237,  1201,  1168,    34,   172,   120,   144,   109,
    1220,   239,   134,   144,    96,  1220,    30,  1227,   292,  1183,
     233,    96,  1227,   155,   120,   305,    96,   186,   200,  1193,
     797,   134,   162,  1345,    98,   134,   120,   149,   155,   102,
    1164,   102,   186,   810,   186,   123,   144,   123,    36,   192,
    1260,   155,    30,   155,    30,  1260,    81,  1221,  1182,   109,
     120,   251,   109,   120,   129,   264,   149,   273,   835,   836,
     837,   838,   260,   158,   291,    30,   292,  1201,   158,   266,
    1556,   158,    30,  1247,   158,   158,   158,    30,   109,   158,
     158,  1567,  1568,  1257,  1570,   293,  1220,  1261,   146,   158,
     312,   192,  1578,  1227,   158,   158,   158,   158,   233,   158,
     877,   144,   158,  1164,   158,   134,   102,  1281,     7,   186,
    1284,   200,   243,   239,   891,   239,    98,   158,   239,   155,
     192,  1182,   188,   108,   158,  1299,  1260,  1442,  1443,  1444,
     158,   149,   149,   149,   239,   129,   120,   134,    79,   916,
    1201,   192,   120,   189,   149,   142,   143,   924,   145,   288,
      80,   189,   256,   256,   292,    30,   153,   189,   935,  1220,
     157,    30,   159,   189,   189,   109,  1227,   164,  1342,  1343,
     189,  1345,  1346,  1347,   189,  1349,   189,   189,   189,   189,
     277,   172,  1402,   186,   181,   128,   128,  1402,    98,   188,
     144,   186,   149,   149,   155,   188,   188,  1683,   263,   186,
     189,    96,    30,   186,    98,  1379,   186,   186,   205,   206,
     207,   208,   209,   210,   189,   189,   189,   189,   189,   189,
     322,   189,   172,    96,   105,  1445,   108,   149,    55,    96,
    1445,   286,  1406,   199,    30,  1409,   120,   109,  1412,   109,
     293,   271,    96,   188,    96,  1022,  1732,   199,  1025,  1423,
     231,   199,   120,   200,  1428,   189,   189,   146,   189,   311,
     189,   189,   189,   120,  1750,   188,    95,   231,   185,   311,
     120,   120,   299,   199,   311,   188,   201,   120,   664,   312,
     231,  1115,   878,   925,  1599,   293,   253,  1773,  1065,   312,
     312,   253,  1161,   256,  1722,  1668,   769,   422,  1037,  1478,
     588,  1475,  1476,   402,   703,  1300,  1280,  1018,  1275,  1795,
    1278,  1183,   486,  1188,  1191,  1630,  1196,   590,  1804,   838,
    1261,   591,   632,   635,   610,   632,   333,   638,  1214,  1744,
     735,  1738,  1341,  1341,  1636,  1247,  1556,  1258,  1257,  1317,
    1328,  1556,  1041,  1501,  1321,  1498,  1050,  1567,  1568,  1137,
    1570,   910,  1567,  1568,  1373,  1570,  1542,  1318,  1578,    -1,
     525,    -1,    -1,  1578,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1168,    -1,    -1,    -1,    -1,    -1,  1571,  1572,    -1,
    1574,    -1,  1576,    -1,    -1,    -1,  1183,    -1,    -1,  1583,
      -1,    -1,    -1,    -1,    -1,    -1,  1193,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1634,    -1,  1636,  1683,  1638,    -1,  1640,    -1,  1683,    -1,
    1247,    -1,  1646,    -1,  1648,    -1,    -1,    -1,    -1,    -1,
    1257,    -1,    -1,    -1,  1261,    -1,    -1,    -1,    -1,    -1,
    1664,    -1,    -1,  1667,    -1,    -1,    -1,    -1,    -1,    -1,
    1674,    -1,    -1,    -1,  1281,    -1,    -1,  1284,    -1,    -1,
      -1,  1685,  1732,    -1,    -1,    -1,    -1,  1732,    -1,    -1,
      -1,    -1,  1299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1750,    -1,    -1,    -1,    -1,  1750,    -1,    -1,    -1,    -1,
      -1,    -1,  1716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1726,  1773,    -1,    -1,    -1,  1731,  1773,  1733,
      -1,    -1,    -1,    -1,    -1,  1342,  1343,    -1,  1345,  1346,
    1347,    -1,  1349,    -1,    -1,  1795,    -1,    -1,    -1,    -1,
    1795,  1755,    -1,    -1,  1804,    -1,    -1,    -1,    -1,  1804,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1771,    -1,    -1,
      -1,    -1,  1379,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1791,   499,    -1,
      -1,    -1,  1796,    -1,    -1,    -1,    -1,    -1,    -1,  1406,
      -1,    -1,  1409,    -1,  1808,  1412,    -1,  1811,    -1,   520,
     521,    -1,   523,   524,   525,   526,  1423,   528,    -1,    -1,
      -1,  1428,    -1,   534,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   542,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   564,   565,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   573,   574,    -1,    -1,    -1,    -1,  1475,  1476,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   634,    -1,    -1,    -1,   638,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1571,  1572,   677,  1574,    -1,  1576,
      -1,    -1,    -1,    -1,    -1,    -1,  1583,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   702,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   718,    -1,    -1,
      -1,   722,   723,    -1,   725,    -1,    -1,    -1,    -1,    -1,
      -1,   732,    -1,    -1,    -1,    -1,    -1,  1634,    -1,  1636,
      -1,  1638,    -1,  1640,    -1,    -1,    -1,    -1,    -1,  1646,
      -1,  1648,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1664,    -1,    -1,
    1667,    -1,    -1,    -1,    -1,    -1,    -1,  1674,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1685,    -1,
      -1,    -1,   793,    -1,    -1,    -1,    -1,    -1,   799,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1716,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1726,
      -1,    -1,    -1,    -1,  1731,    -1,  1733,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1755,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1771,    -1,    -1,    -1,   879,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1791,    -1,    -1,    -1,    -1,  1796,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1808,    -1,   914,  1811,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   936,    -1,    -1,    -1,    -1,
      -1,    -1,   943,   944,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   954,    -1,    -1,   957,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   978,   979,   980,
      -1,   982,   983,   984,   985,   986,   987,   988,   989,   990,
      -1,    -1,   993,   994,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1008,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1018,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1028,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1170,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1180,
      -1,    -1,    -1,    -1,    -1,  1186,  1187,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1203,    -1,    -1,  1206,  1207,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1278,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1286,    -1,  1288,    -1,  1290,
      -1,    -1,  1293,    -1,    -1,    -1,    -1,  1298,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1393,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1401,  1402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1420,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1433,  1434,  1435,  1436,    -1,  1438,  1439,    -1,
    1441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1457,    -1,    -1,    -1,
      -1,  1462,    -1,    -1,    -1,  1466,    -1,    -1,    -1,  1470,
      -1,  1472,    -1,  1474,    -1,    -1,    -1,    -1,    -1,  1480,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1557,    -1,    -1,    -1,
      -1,  1562,  1563,    -1,    -1,    -1,    -1,    -1,    -1,  1570,
      -1,    -1,    -1,    -1,  1575,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1604,    -1,  1606,    -1,  1608,    -1,    -1,
    1611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1679,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1702,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1732,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,    -1,    -1,    -1,    -1,  1769,    -1,
      -1,    -1,  1773,    -1,    -1,    -1,    -1,  1778,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,  1794,    -1,    34,    35,  1798,    37,    38,
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
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,    -1,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,   318,
      -1,   320,   321,   322,   323,   324,    -1,   326,     0,     1,
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
      -1,   213,   214,   215,    -1,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     1,   318,    -1,   320,   321,
     322,   323,   324,    -1,   326,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,     1,   318,    -1,   320,   321,   322,   323,   324,    -1,
     326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
     210,    -1,    -1,   213,   214,   215,    -1,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
     320,   321,   322,   323,   324,    -1,   326,    11,    12,    -1,
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
     214,    -1,    -1,   217,    -1,   219,   220,    -1,    -1,    -1,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,    -1,    -1,    -1,   320,   321,   322,   323,
     324,    16,   326,    -1,    -1,    -1,    21,    22,    23,    24,
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
     215,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    -1,   318,    -1,   320,   321,   322,   323,   324,
      16,   326,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,    -1,    -1,    -1,
     126,    -1,   128,   129,   130,   131,    -1,   133,    -1,    -1,
      -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,   320,   321,   322,   323,   324,    16,
     326,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
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
     217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      -1,   318,    16,   320,   321,   322,   323,   324,    -1,   326,
      -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
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
      -1,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,    -1,    -1,   217,    -1,   219,   220,    -1,    -1,    -1,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,    -1,    16,    -1,   320,   321,   322,   323,
     324,    -1,   326,    25,    26,    -1,    -1,    -1,    30,    -1,
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
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,   189,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,    -1,    -1,   217,    -1,   219,   220,    -1,
      -1,    -1,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,    -1,    16,    -1,   320,   321,
     322,   323,   324,    -1,   326,    25,    26,    -1,    -1,    -1,
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
     210,    -1,    -1,   213,   214,    -1,    -1,   217,    -1,   219,
     220,    -1,    -1,    -1,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,    -1,    -1,    -1,
     320,   321,   322,   323,   324,    -1,   326,    18,    19,    -1,
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
     191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,    -1,    -1,   217,    -1,   219,   220,
      -1,    -1,    -1,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,    -1,    -1,    -1,    -1,   320,
     321,   322,   323,   324,    -1,   326,    21,    22,    23,    24,
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
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    -1,   318,    -1,   320,   321,   322,   323,   324,
      -1,   326,   327,   328,    21,    22,    23,    24,    25,    26,
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
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      -1,   318,    -1,   320,   321,   322,   323,   324,    -1,   326,
      -1,   328,    21,    22,    23,    24,    25,    26,    27,    28,
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
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,   318,
      -1,   320,   321,   322,   323,   324,    -1,   326,    21,    22,
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
     213,   214,   215,    -1,   217,    -1,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,    -1,   318,    -1,   320,   321,   322,
     323,   324,    -1,   326,    21,    22,    23,    24,    25,    26,
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
      -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,   186,
      -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,   215,    -1,
     217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      -1,   318,    -1,   320,   321,   322,   323,   324,    -1,   326,
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
      -1,    -1,   213,   214,   215,    -1,   217,    -1,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,    -1,   318,    -1,   320,
     321,   322,   323,   324,    -1,   326,    21,    22,    23,    24,
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
     215,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    -1,   318,    -1,   320,   321,   322,   323,   324,
      -1,   326,    21,    22,    23,    24,    25,    26,    27,    28,
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
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,    -1,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,   318,
      -1,   320,   321,   322,   323,   324,    -1,   326,    21,    22,
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
     213,   214,   215,    -1,   217,    -1,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,    -1,   318,    -1,   320,   321,   322,
     323,   324,    -1,   326,    21,    22,    23,    24,    25,    26,
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
     217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      -1,   318,    -1,   320,   321,   322,   323,   324,    -1,   326,
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
     141,    -1,    -1,    -1,    -1,   146,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,   176,    -1,   178,   179,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,   213,   214,   215,    -1,   217,    -1,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,    -1,   318,    -1,   320,
     321,   322,   323,   324,    -1,   326,    21,    22,    23,    24,
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
      -1,   146,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,   184,
      -1,    -1,    -1,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
     215,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    -1,   318,    -1,   320,   321,   322,   323,   324,
      -1,   326,    21,    22,    23,    24,    25,    26,    27,    28,
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
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,    -1,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,   318,
      -1,   320,   321,   322,   323,   324,    -1,   326,    21,    22,
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
     213,   214,   215,    -1,   217,    -1,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,    -1,   318,    -1,   320,   321,   322,
     323,   324,    -1,   326,    21,    22,    23,    24,    25,    26,
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
      -1,   188,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,   215,    -1,
     217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      -1,   318,    -1,   320,   321,   322,   323,   324,    -1,   326,
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
      -1,    -1,   213,   214,   215,    -1,   217,    -1,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,    -1,   320,
     321,   322,   323,   324,    -1,   326,    21,    22,    23,    24,
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
      -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
     215,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    -1,   318,   319,   320,   321,   322,   323,   324,
      -1,   326,    21,    22,    23,    24,    25,    26,    -1,    -1,
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
     179,    -1,    -1,   182,   183,   184,    -1,   186,    -1,   188,
      -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,    -1,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,   318,
      -1,   320,   321,   322,   323,   324,    -1,   326,    21,    22,
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
     213,   214,   215,    -1,   217,    -1,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,    -1,   318,    -1,   320,   321,   322,
     323,   324,    -1,   326,    21,    22,    23,    24,    25,    26,
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
     217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
      -1,   318,    -1,   320,   321,   322,   323,   324,    -1,   326,
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
      -1,    -1,   213,   214,   215,    -1,   217,    -1,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,    -1,   318,    -1,   320,
     321,   322,   323,   324,    -1,   326,    21,    22,    23,    24,
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
      -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
     215,    -1,   217,    -1,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    -1,   318,    -1,   320,   321,   322,   323,   324,
      -1,   326,    21,    22,    23,    24,    25,    26,    -1,    -1,
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
     159,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,    -1,    -1,
      -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,   215,    -1,   217,    -1,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,   318,
      -1,   320,   321,   322,   323,   324,    -1,   326,    25,    26,
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
     217,    -1,   219,   220,    -1,    -1,    -1,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
      -1,    25,    26,   320,   321,   322,   323,   324,   325,   326,
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
     214,    -1,    -1,   217,    -1,   219,   220,    -1,    -1,    -1,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,    -1,    25,    26,   320,   321,   322,   323,
     324,   325,   326,    34,    35,    -1,    37,    38,    39,    40,
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
      -1,    -1,   213,   214,    -1,    -1,   217,    -1,   219,   220,
      -1,    -1,    -1,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,    -1,    -1,    25,    26,   320,
     321,   322,   323,   324,   325,   326,    34,    35,    -1,    37,
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
      -1,   219,   220,    -1,    -1,    -1,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,    -1,
      25,    26,   320,   321,   322,   323,   324,   325,   326,    34,
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
      -1,    -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,
      -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
      -1,    -1,   217,    -1,   219,   220,    -1,    -1,    -1,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    -1,    -1,    25,    26,   320,   321,   322,   323,   324,
     325,   326,    34,    35,    -1,    37,    38,    39,    40,    41,
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
      -1,   213,   214,    -1,    -1,   217,    -1,   219,   220,    -1,
      -1,    -1,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,    -1,    25,    26,   320,   321,
     322,   323,   324,   325,   326,    34,    35,    -1,    37,    38,
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
     209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,    -1,
     219,   220,    -1,    -1,    -1,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,    -1,    25,
      26,   320,   321,   322,   323,   324,    -1,   326,    34,    35,
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
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,    -1,   219,   220,    -1,    -1,    -1,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,    -1,    25,    26,   320,   321,   322,   323,   324,    -1,
     326,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
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
     153,   154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
     183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
     213,   214,    -1,    -1,   217,    -1,   219,   220,    -1,    -1,
      -1,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,    -1,    25,    26,   320,   321,   322,
     323,   324,    -1,   326,    34,    35,    -1,    37,    38,    39,
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
     210,    -1,    -1,   213,   214,    -1,    -1,   217,    -1,   219,
     220,    -1,    -1,    -1,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,    -1,    25,    26,
     320,   321,   322,   323,   324,    -1,   326,    34,    35,    -1,
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
     217,    -1,   219,   220,    -1,    -1,    -1,   224,   225,   226,
     227,   228,   229,   230,    -1,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
      -1,    -1,    -1,   320,   321,   322,   323,   324,    -1,   326
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
     263,   265,   266,   267,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   318,   320,   321,   322,   323,   324,   326,   327,
     328,   342,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   363,
     364,   365,   366,   367,   368,   372,   373,   374,   378,   380,
     381,   383,   390,   392,   395,   396,   397,   399,   400,   401,
     402,   403,   405,   406,   408,   409,   410,   411,   412,   413,
     415,   416,   419,   420,   421,   422,   427,   429,   431,   432,
     433,   438,   457,   460,   464,   467,   468,   474,   475,   476,
     477,   479,   480,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   492,   493,   494,   495,   498,   499,   500,   501,
     502,   503,   504,   507,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   521,   522,   523,   524,   525,   526,
     540,   541,   543,   544,   545,   546,   547,   548,   549,   550,
     571,   576,   577,   578,   579,   580,   581,   584,   642,   643,
     644,   645,   647,   648,   649,   650,   651,   658,   659,   660,
      34,    35,    50,   217,   398,   399,   400,   398,   398,   399,
     400,   158,   158,    38,    39,    41,    42,    48,    58,    59,
      76,    81,   113,   114,   115,   162,   226,   267,   293,   301,
     309,   379,   380,   384,   385,   386,   162,   155,   155,   155,
     158,   387,   158,    25,    35,    62,   120,   279,   437,   439,
     440,   155,   120,   155,   158,   158,    78,   155,   227,   228,
     155,   120,   407,    40,    44,    46,    47,    48,    49,    52,
      61,    69,    72,    74,    75,    77,    99,   114,   137,   162,
     171,   204,   230,   232,   234,   235,   242,   244,   245,   246,
     249,   250,   263,   321,   658,   659,   120,    16,   186,   398,
     400,   420,   646,   657,   658,    49,    74,    75,   120,   155,
     187,   250,   419,   421,   431,   189,   419,   658,   155,   155,
     657,   658,    18,    19,   658,   155,    31,   216,   219,   219,
     231,   233,   320,   231,   233,   320,   231,   320,   231,   236,
     320,   120,   247,   247,   248,   158,   155,   402,   317,   419,
     319,   419,   320,   328,   344,   344,     0,   346,   347,    34,
      50,   349,   366,     1,   192,   343,   192,   343,   114,   381,
     401,   419,   109,   192,   109,   343,   192,    43,    47,    52,
      71,   170,   173,   188,   214,   263,   414,   423,   428,   429,
     430,   445,   446,   450,     1,     3,    68,    73,   120,   424,
     169,    94,   134,   142,   143,   145,   153,   157,   159,   164,
     181,   205,   206,   207,   208,   209,   210,   496,   497,   255,
     101,   160,   178,   201,   119,   148,   161,   196,   203,   212,
     138,   152,    51,   202,   103,   104,   160,   178,   494,   195,
     155,   501,   121,   156,   158,   508,   509,   147,   158,   186,
     186,   186,   186,   382,   511,   382,    30,   656,   184,   198,
     184,   198,   168,   184,   659,   658,   171,   204,    48,   658,
     154,   120,    46,    48,    81,   108,   170,   657,   227,   228,
     229,   252,   615,   658,   658,   310,   139,   144,   114,   293,
     301,   384,   657,   399,   399,   419,   120,   189,   388,   389,
     155,   404,   419,     1,   162,   656,   115,   162,   362,   656,
     658,   120,   144,   109,   419,   458,   459,   658,   399,   419,
     419,   569,   658,   399,   155,   155,   419,   658,   144,   458,
     186,   186,   123,   109,   186,   123,   158,   158,   158,   658,
     155,   187,   188,   189,    36,   528,   529,   530,   419,   419,
       8,   177,    17,   419,   216,    30,    30,   420,   420,   507,
     420,   420,   420,   646,   420,   507,   420,   237,   236,   582,
     583,   658,   192,   192,   420,   419,   400,   419,   251,   417,
     418,   317,   319,   420,   344,   192,   343,   192,   343,     3,
     350,   366,   396,     1,   350,   366,   396,    34,   367,   396,
     367,   396,   407,   343,   407,   420,   420,   120,   170,   172,
     172,   401,   420,   420,   434,   435,   658,   290,   290,   434,
     120,   441,   476,   477,   479,   479,   479,   479,   478,   479,
     479,   479,    72,   480,   484,   484,   483,   485,   485,   485,
     485,   486,   486,   487,   487,   237,    96,    96,    96,   502,
     186,   419,   196,   514,   515,   571,   657,   419,   146,   189,
     420,   520,   509,   151,   189,   520,   109,   189,   189,   109,
     109,   387,    30,   659,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,   369,   370,   371,    96,   139,   144,
     375,   376,   377,   658,   162,   162,   369,   656,   129,   134,
      56,    58,   102,   257,   270,   272,   283,   284,   285,   287,
     289,   616,   617,   618,   619,   620,   621,   628,   634,   635,
     252,    96,   305,   658,   144,   420,   120,   658,   658,   134,
     186,   186,   186,   658,    96,   109,   189,   398,   189,   657,
      98,    46,   657,   656,    98,    96,   144,   551,   658,   420,
     440,   186,   109,   190,   149,   551,   186,   189,   189,   155,
     186,   399,   399,   186,   144,   551,   420,   190,   420,   420,
     657,   420,   419,   419,   419,   658,   529,   530,   132,   199,
     186,   186,   186,   133,   192,   133,   192,    96,   224,   225,
     239,    96,   224,   225,   239,   239,   239,    96,    96,   243,
     231,   237,   109,   241,   144,   192,   189,   419,   186,    11,
      12,    20,   196,   505,   506,   588,   658,   418,   239,   366,
      34,    34,   192,   343,   192,   115,   401,   658,   172,   420,
     451,   452,   120,   447,   448,   109,    37,    98,   149,   436,
     437,   551,   658,    57,   220,   260,   425,   426,   479,   155,
     158,   265,   500,   511,   589,   592,   593,   594,   595,   596,
     600,   602,   604,   605,    40,    45,    46,    48,    54,    61,
      63,    64,    72,    99,   154,   158,   213,   231,   323,   324,
     325,   326,   552,   554,   556,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   572,   573,   574,   575,
     652,   653,   654,   655,   658,   552,   491,   557,   658,   491,
     186,   187,   109,   189,   189,   511,   150,   167,   150,   167,
     139,   404,   387,   370,   134,   554,   377,   420,   551,   656,
     656,   130,   131,   656,   283,   284,   285,   289,   658,   269,
     280,   269,   280,    30,   292,    98,   115,   158,   622,   625,
     616,    40,    45,    46,    54,    61,    63,    64,    72,    99,
     231,   323,   324,   391,   558,   652,   233,   305,   314,   420,
     658,    96,   305,   656,   155,   551,   552,   389,    96,   186,
     200,   134,   361,   656,   162,   134,    98,   361,   552,   420,
     144,   437,   155,   120,   420,   420,   149,   102,   461,   462,
     463,   465,   466,   102,   469,   470,   471,   472,   399,   186,
     186,   155,   420,   144,   192,   420,   123,   123,   189,   189,
     189,    36,   530,   132,   199,     9,    10,   105,   125,   127,
     155,   197,   525,   527,   538,   539,   542,   155,    30,    30,
     238,   240,   420,   420,   420,   238,   240,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   507,   120,   420,   420,
      49,    74,    75,   250,   401,   421,   431,   251,   585,   586,
     155,   212,   402,   420,   192,   115,   396,   396,   396,   451,
      97,   108,   118,   129,   453,   454,   455,   456,   109,   658,
     109,   120,   435,   129,   120,   420,   149,   437,   149,    37,
     149,   436,   437,   149,   551,   260,    55,    60,    79,   120,
     436,   442,   443,   444,   426,   419,   589,   596,   155,   291,
     481,   641,    98,   171,   258,   259,   261,   268,   278,   290,
     590,   591,   610,   611,   612,   613,   636,   639,   264,   266,
     597,   615,   273,   601,   637,   253,   254,   276,   606,   607,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   554,   158,   158,   158,   158,   158,   146,   178,   196,
     553,   146,   146,   420,   139,   404,   571,   376,   292,    30,
      98,   115,   158,   629,    30,   622,   553,   553,   502,   293,
     312,   551,   391,   233,   192,   398,   552,   401,   420,   656,
     109,   361,   420,   144,   398,   459,   420,   420,   115,   462,
     463,   102,   188,   115,   463,   466,   120,   473,   552,   102,
     115,   470,   102,   115,   472,   186,   398,   420,   420,   420,
     200,   469,   134,   197,   527,     7,   399,   658,   197,   538,
     399,   192,   192,   239,   239,   239,   239,    98,   243,   243,
     583,   188,   158,   158,   158,   188,   588,   586,   505,   656,
     130,   131,   455,   456,   456,   452,   108,   144,   449,   551,
     448,   435,   149,   436,   658,   420,   149,   420,   129,   420,
     149,   437,   149,   420,   149,   120,   120,   420,   658,   444,
      79,   186,   189,   589,   603,   256,   220,   260,   274,   281,
     640,    98,   262,   263,   638,   256,   593,   640,   483,   610,
     594,   149,   288,   598,   599,   638,   292,   609,    80,   608,
     189,   189,   567,   568,   189,   196,   658,   189,   196,   552,
     555,   189,    30,   189,   657,   658,   658,   189,   189,   196,
     658,   189,   189,   189,   189,   189,   189,   189,    30,   138,
     203,   631,   632,   633,    30,   630,   631,   277,   626,   109,
     623,   172,   658,   263,   502,   186,   128,   128,    98,   656,
     420,   186,   188,   188,   420,   401,   420,   188,   188,   658,
     188,   212,   120,   473,   120,   188,   120,   473,   188,   186,
     115,   530,   658,   197,   186,   530,   658,   186,   420,   420,
     420,   420,   322,   420,   420,   420,   419,   419,   419,   155,
     587,   456,   656,   420,   144,   420,   149,   420,   149,   436,
     420,   149,   420,   420,   658,   658,   443,   420,   186,   485,
      53,   131,   483,   483,   275,   282,   292,   614,   614,   595,
     155,   286,   189,   189,   109,   189,   109,   189,    96,   189,
     109,   189,   189,   189,   189,   189,   109,   189,   109,   189,
     629,   629,   633,   109,   189,    30,   627,   638,   624,   625,
     189,   393,   394,   502,   120,   231,   313,   293,   172,   401,
     420,   361,   420,   401,    96,   401,   420,   552,   658,   188,
     658,   420,   658,   188,   401,   120,    95,   185,   531,   530,
     658,   199,   530,   420,   189,   189,   189,   419,   449,   420,
     420,   420,   149,   420,    55,   483,   483,   201,   419,   569,
     570,   658,   569,   570,   552,   552,    96,   569,   569,    30,
     271,   109,   109,   456,   551,   658,   120,   231,   658,   393,
     473,    96,   188,    96,   658,     5,   135,   534,   535,   537,
     539,    29,   136,   532,   533,   536,   539,   199,   530,   199,
     200,   469,   186,   449,   420,   120,   483,   186,   189,   189,
     146,   189,   189,   552,   189,   189,   625,   394,   456,   311,
     658,   120,   231,   188,   473,   401,   420,   473,   188,    95,
     135,   537,   185,   136,   536,   199,   115,   658,   420,   311,
     658,   120,   401,   420,   188,   188,   120,   299,   311,   658,
     658,   312,   420,   312,   188,   502,   502,   201,   293,   658,
     231,   120,   658,   312,   502
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
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  jsoniq_parser::yyr1_[] =
  {
         0,   341,   342,   342,   342,   342,   343,   343,   343,   344,
     344,   344,   344,   345,   345,   345,   345,   346,   346,   346,
     346,   346,   346,   346,   346,   347,   347,   347,   347,   348,
     349,   349,   349,   350,   350,   350,   350,   350,   351,   351,
     351,   351,   351,   351,   351,   351,   352,   352,   353,   354,
     355,   355,   356,   356,   357,   357,   358,   358,   358,   358,
     359,   359,   359,   360,   360,   360,   360,   361,   361,   362,
     362,   363,   363,   363,   363,   364,   365,   365,   366,   366,
     366,   367,   367,   367,   367,   367,   367,   367,   367,   368,
     368,   369,   369,   370,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   372,   373,   374,   375,   375,   376,
     376,   376,   377,   378,   378,   378,   379,   379,   379,   379,
     380,   380,   381,   381,   381,   381,   382,   382,   383,   383,
     384,   384,   385,   385,   386,   386,   387,   387,   387,   387,
     388,   388,   389,   389,   390,   390,   390,   390,   391,   391,
     391,   391,   392,   392,   393,   393,   394,   394,   394,   394,
     395,   395,   395,   395,   396,   397,   397,   397,   398,   398,
     398,   399,   399,   400,   400,   400,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   401,   401,   402,   402,
     403,   404,   405,   406,   406,   406,   407,   407,   407,   407,
     408,   409,   410,   411,   412,   412,   413,   414,   415,   416,
     417,   417,   418,   419,   419,   419,   420,   420,   420,   420,
     420,   420,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   422,   423,   424,   424,   425,   425,
     425,   426,   426,   427,   427,   428,   429,   429,   429,   430,
     430,   430,   430,   430,   431,   431,   432,   432,   432,   433,
     433,   434,   434,   434,   435,   435,   435,   435,   435,   435,
     435,   435,   435,   435,   435,   435,   436,   437,   438,   439,
     439,   440,   440,   440,   440,   441,   441,   442,   442,   442,
     443,   443,   443,   444,   444,   444,   445,   446,   447,   447,
     448,   448,   448,   448,   448,   448,   449,   450,   450,   451,
     451,   452,   452,   453,   453,   453,   453,   453,   453,   453,
     454,   454,   455,   455,   456,   457,   457,   458,   458,   459,
     459,   460,   461,   461,   462,   463,   463,   464,   465,   465,
     466,   467,   467,   468,   468,   469,   469,   470,   470,   471,
     471,   472,   472,   473,   473,   474,   475,   475,   476,   476,
     477,   477,   477,   477,   477,   478,   477,   477,   477,   477,
     479,   479,   480,   480,   481,   481,   482,   482,   483,   483,
     483,   484,   484,   484,   484,   484,   485,   485,   485,   486,
     486,   486,   487,   487,   488,   488,   489,   489,   490,   490,
     491,   491,   492,   492,   493,   493,   493,   493,   494,   494,
     494,   495,   495,   496,   496,   496,   496,   496,   496,   497,
     497,   497,   498,   498,   498,   498,   499,   499,   500,   500,
     501,   501,   501,   502,   503,   504,   505,   505,   506,   506,
     506,   506,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   508,   508,   509,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   511,   511,
     511,   511,   512,   512,   512,   513,   513,   514,   515,   515,
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
     646,   646,   646,   647,   647,   647,   648,   649,   650,   651,
     652,   652,   652,   653,   654,   655,   656,   657,   657,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   659,   659,   659,   659,
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
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   660
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  jsoniq_parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     3,     1,     2,     2,     1,
       2,     1,     2,     4,     6,     4,     6,     3,     3,     5,
       1,     3,     3,     5,     5,     1,     3,     3,     5,     6,
       1,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     3,
       3,     3,     3,     3,     5,     5,     5,     5,     5,     5,
       1,     1,     3,     3,     4,     5,     6,     1,     3,     3,
       3,     3,     6,     5,     8,     5,     5,     5,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     3,     4,     3,     1,     1,
       1,     2,     2,     4,     3,     5,     3,     4,     4,     5,
       1,     2,     1,     4,     1,     4,     1,     3,     2,     3,
       1,     1,     4,     4,     5,     5,     2,     3,     4,     5,
       1,     3,     2,     3,     3,     5,     4,     6,     1,     2,
       1,     2,     8,     9,     1,     3,     1,     2,     2,     3,
      11,    14,    13,    22,     1,     1,     1,     0,     1,     1,
       0,     1,     2,     1,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     3,     2,     3,     2,     3,     2,     3,     4,     5,
       5,     2,     4,     5,     3,     3,     2,     2,     8,     3,
       1,     2,     3,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       2,     4,     3,     5,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     3,     2,     1,
       1,     1,     4,     3,     3,     5,     4,     6,     4,     6,
       5,     7,     4,     5,     5,     6,     3,     3,     2,     1,
       3,     4,     5,     3,     6,     4,     5,     1,     2,     3,
       1,     2,     1,     6,     3,     3,     2,     3,     1,     3,
       2,     4,     5,     6,     5,     3,     2,     3,     4,     1,
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
       1,     1,     4,     5,     5,     6,     3,     4,     1,     2,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     4,     3,     3,     3,     3,
       3,     1,     2,     3,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
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
       3,     5,     5,     5,     5,     8,     5,     3,     5,     7,
       1,     1,     1,     1,     3,     3,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
  "\"'xquery'\"", "\"'jsoniq'\"", "\"'version'\"", "\"'start'\"",
  "\"'null'\"", "\"'true'\"", "\"'false'\"", "\"'after'\"", "\"'before'\"",
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
  "ArgList", "FunctionItemExpr", "LiteralFunctionItem", "InlineFunction",
  "Constructor", "DirectConstructor", "DirElemConstructor",
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
       342,     0,    -1,   344,    -1,   327,   344,    -1,   328,   344,
      -1,   327,   328,   344,    -1,     1,    -1,     1,     3,    -1,
     343,     1,    -1,   346,    -1,   345,   346,    -1,   347,    -1,
     345,   347,    -1,   217,   219,    30,   192,    -1,   217,   219,
      30,   133,    30,   192,    -1,   218,   219,    30,   192,    -1,
     218,   219,    30,   133,    30,   192,    -1,   349,   192,   396,
      -1,   366,   192,   396,    -1,   349,   192,   366,   192,   396,
      -1,   396,    -1,   349,   343,   396,    -1,   366,   343,   396,
      -1,   349,   192,   366,   343,   396,    -1,   349,   343,   366,
     192,   396,    -1,   348,    -1,   348,   349,   192,    -1,   348,
     366,   192,    -1,   348,   349,   192,   366,   192,    -1,    35,
     162,   657,   134,   656,   192,    -1,   350,    -1,   349,   192,
     350,    -1,   349,   343,   350,    -1,   351,    -1,   359,    -1,
     364,    -1,   365,    -1,   373,    -1,   352,    -1,   353,    -1,
     354,    -1,   355,    -1,   356,    -1,   357,    -1,   358,    -1,
     576,    -1,    34,    39,   184,    -1,    34,    39,   198,    -1,
      34,   115,   108,   656,    -1,    34,    38,   656,    -1,    34,
      41,   184,    -1,    34,    41,   198,    -1,    34,    59,   171,
      -1,    34,    59,   204,    -1,    34,   115,   170,   129,   130,
      -1,    34,   115,   170,   129,   131,    -1,    34,    42,   184,
     109,   150,    -1,    34,    42,   184,   109,   167,    -1,    34,
      42,   168,   109,   150,    -1,    34,    42,   168,   109,   167,
      -1,   360,    -1,   363,    -1,    50,    25,     1,    -1,    50,
      62,   656,    -1,    50,    62,   362,   656,    -1,    50,    62,
     656,    98,   361,    -1,    50,    62,   362,   656,    98,   361,
      -1,   656,    -1,   361,   109,   656,    -1,   162,   657,   134,
      -1,   115,    46,   162,    -1,    50,    35,   656,    -1,    50,
      35,   162,   657,   134,   656,    -1,    50,    35,   656,    98,
     361,    -1,    50,    35,   162,   657,   134,   656,    98,   361,
      -1,    34,   162,   657,   134,   656,    -1,    34,   115,    46,
     162,   656,    -1,    34,   115,    48,   162,   656,    -1,   367,
      -1,   366,   192,   367,    -1,   366,   343,   367,    -1,   368,
      -1,   372,    -1,   374,    -1,   378,    -1,   383,    -1,   390,
      -1,   392,    -1,   395,    -1,    34,   115,    81,   369,    -1,
      34,    81,   658,   369,    -1,   370,    -1,   369,   370,    -1,
     371,   134,   571,    -1,    82,    -1,    90,    -1,    83,    -1,
      84,    -1,    85,    -1,    86,    -1,    91,    -1,    87,    -1,
      88,    -1,    89,    -1,    34,    58,   658,    30,    -1,    34,
     267,   615,    -1,    34,   113,   154,   375,    -1,    96,   554,
     376,    -1,   376,    -1,   377,    -1,   139,    -1,   139,   377,
      -1,   144,   420,    -1,    34,   379,   144,   420,    -1,    34,
     379,   139,    -1,    34,   379,   139,   144,   420,    -1,   114,
     120,   658,    -1,   114,   120,   658,   551,    -1,   380,   114,
     120,   658,    -1,   380,   114,   120,   658,   551,    -1,   381,
      -1,   380,   381,    -1,    27,    -1,    27,   158,   382,   189,
      -1,    28,    -1,    28,   158,   382,   189,    -1,   511,    -1,
     382,   109,   511,    -1,    34,   384,    -1,    34,   380,   384,
      -1,   385,    -1,   386,    -1,    48,   659,   387,   404,    -1,
      48,   659,   387,   139,    -1,    76,    48,   659,   387,   404,
      -1,    76,    48,   659,   387,   139,    -1,   158,   189,    -1,
     158,   388,   189,    -1,   158,   189,    96,   552,    -1,   158,
     388,   189,    96,   552,    -1,   389,    -1,   388,   109,   389,
      -1,   120,   658,    -1,   120,   658,   551,    -1,    34,   293,
     658,    -1,    34,   293,   658,    96,   391,    -1,    34,   380,
     293,   658,    -1,    34,   380,   293,   658,    96,   391,    -1,
     558,    -1,   558,   553,    -1,   652,    -1,   652,   553,    -1,
      34,   301,   658,   305,   233,   502,   172,   393,    -1,    34,
     380,   301,   658,   305,   233,   502,   172,   393,    -1,   394,
      -1,   393,   109,   394,    -1,   502,    -1,   502,   551,    -1,
     502,   456,    -1,   502,   551,   456,    -1,    34,   309,   310,
     658,   305,   293,   658,   120,   658,   311,   420,    -1,    34,
     309,   310,   658,   305,   293,   658,   231,   120,   658,   311,
     299,   312,   502,    -1,    34,   309,   310,   658,   305,   293,
     658,   313,   231,   120,   658,   311,   420,    -1,    34,   309,
     310,   658,   314,   312,   263,   293,   658,   231,   120,   658,
     312,   502,   201,   293,   658,   231,   120,   658,   312,   502,
      -1,   397,    -1,   399,    -1,   400,    -1,    -1,   399,    -1,
     400,    -1,    -1,   419,    -1,   400,   419,    -1,   401,    -1,
     400,   401,    -1,   400,   419,   343,   401,    -1,   402,    -1,
     405,    -1,   408,    -1,   409,    -1,   410,    -1,   411,    -1,
     412,    -1,   413,    -1,   415,    -1,   468,    -1,   464,    -1,
     416,    -1,   155,   400,   186,    -1,   155,   186,    -1,   155,
     398,   186,    -1,   155,   398,   186,    -1,   406,   192,    -1,
     406,   109,   407,    -1,   114,   407,    -1,   380,   114,   407,
      -1,   120,   658,    -1,   120,   658,   551,    -1,   120,   658,
     144,   420,    -1,   120,   658,   551,   144,   420,    -1,   120,
     658,   144,   420,   192,    -1,   421,   192,    -1,   246,   248,
     420,   192,    -1,   249,   158,   419,   189,   401,    -1,   244,
     247,   192,    -1,   245,   247,   192,    -1,   431,   414,    -1,
     188,   401,    -1,    49,   158,   419,   189,   200,   401,   128,
     401,    -1,   250,   402,   417,    -1,   418,    -1,   417,   418,
      -1,   251,   588,   402,    -1,   420,    -1,   419,   109,   420,
      -1,   419,   343,   420,    -1,   422,    -1,   460,    -1,   467,
      -1,   474,    -1,   584,    -1,   421,    -1,   475,    -1,   457,
      -1,   577,    -1,   578,    -1,   580,    -1,   579,    -1,   581,
      -1,   649,    -1,   647,    -1,   650,    -1,   651,    -1,   648,
      -1,   431,   423,    -1,   188,   420,    -1,    68,   290,    -1,
      73,   290,    -1,   220,    -1,   260,    -1,    57,   260,    -1,
     425,   442,    79,   420,    -1,   425,    79,   420,    -1,   433,
     424,   441,   426,   426,    -1,   433,   424,   441,   426,    -1,
      43,   120,   658,    -1,   432,    -1,   438,    -1,   427,    -1,
     429,    -1,   445,    -1,   450,    -1,   446,    -1,   428,    -1,
     429,    -1,   431,   430,    -1,   433,   120,   434,    -1,   433,
       1,   434,    -1,   433,     3,    -1,    47,    -1,   263,    -1,
     435,    -1,   434,   109,   120,   435,    -1,   434,   109,   435,
      -1,   658,   149,   420,    -1,   658,    37,   129,   149,   420,
      -1,   658,   551,   149,   420,    -1,   658,   551,    37,   129,
     149,   420,    -1,   658,   436,   149,   420,    -1,   658,    37,
     129,   436,   149,   420,    -1,   658,   551,   436,   149,   420,
      -1,   658,   551,    37,   129,   436,   149,   420,    -1,   658,
     437,   149,   420,    -1,   658,   551,   437,   149,   420,    -1,
     658,   436,   437,   149,   420,    -1,   658,   551,   436,   437,
     149,   420,    -1,    98,   120,   658,    -1,   279,   120,   658,
      -1,    52,   439,    -1,   440,    -1,   439,   109,   440,    -1,
     120,   658,   144,   420,    -1,   120,   658,   551,   144,   420,
      -1,   437,   144,   420,    -1,   120,   658,   551,   437,   144,
     420,    -1,   120,   658,   149,   420,    -1,   120,   658,   551,
     149,   420,    -1,   443,    -1,   120,   658,    -1,   120,   658,
     443,    -1,   436,    -1,   436,   444,    -1,   444,    -1,    60,
     120,   658,    55,   120,   658,    -1,    55,   120,   658,    -1,
      60,   120,   658,    -1,   214,   420,    -1,   173,   172,   447,
      -1,   448,    -1,   447,   109,   448,    -1,   120,   658,    -1,
     120,   658,   144,   420,    -1,   120,   658,   551,   144,   420,
      -1,   120,   658,   551,   144,   420,   449,    -1,   120,   658,
     144,   420,   449,    -1,   120,   658,   449,    -1,   108,   656,
      -1,   170,   172,   451,    -1,    71,   170,   172,   451,    -1,
     452,    -1,   451,   109,   452,    -1,   420,    -1,   420,   453,
      -1,   454,    -1,   455,    -1,   456,    -1,   454,   455,    -1,
     454,   456,    -1,   455,   456,    -1,   454,   455,   456,    -1,
      97,    -1,   118,    -1,   129,   130,    -1,   129,   131,    -1,
     108,   656,    -1,    69,   120,   458,   190,   420,    -1,   137,
     120,   458,   190,   420,    -1,   459,    -1,   458,   109,   120,
     459,    -1,   658,   149,   420,    -1,   658,   551,   149,   420,
      -1,    74,   158,   419,   189,   461,   115,   188,   420,    -1,
     462,    -1,   461,   462,    -1,   463,   188,   420,    -1,   102,
     420,    -1,   463,   102,   420,    -1,    74,   158,   419,   189,
     465,   115,   188,   401,    -1,   466,    -1,   465,   466,    -1,
     463,   188,   401,    -1,    75,   158,   419,   189,   469,   115,
     188,   420,    -1,    75,   158,   419,   189,   469,   115,   120,
     658,   188,   420,    -1,    75,   158,   419,   189,   471,   115,
     188,   401,    -1,    75,   158,   419,   189,   469,   115,   120,
     658,   188,   401,    -1,   470,    -1,   469,   470,    -1,   102,
     473,   188,   420,    -1,   102,   120,   658,    96,   473,   188,
     420,    -1,   472,    -1,   471,   472,    -1,   102,   473,   188,
     401,    -1,   102,   120,   658,    96,   473,   188,   401,    -1,
     552,    -1,   473,   212,   552,    -1,    49,   158,   419,   189,
     200,   420,   128,   420,    -1,   476,    -1,   475,   169,   476,
      -1,   477,    -1,   476,    94,   477,    -1,   479,    -1,   479,
     496,   479,    -1,   479,   497,   479,    -1,   479,   134,   479,
      -1,   479,   164,   479,    -1,    -1,   479,   159,   478,   479,
      -1,   479,   157,   479,    -1,   479,   145,   479,    -1,   479,
     143,   479,    -1,   480,    -1,   480,   255,    72,   589,   481,
      -1,   482,    -1,   482,   101,   480,    -1,    -1,   641,    -1,
     483,    -1,   483,   201,   483,    -1,   484,    -1,   483,   178,
     484,    -1,   483,   160,   484,    -1,   485,    -1,   484,   196,
     485,    -1,   484,   119,   485,    -1,   484,   148,   485,    -1,
     484,   161,   485,    -1,   486,    -1,   485,   203,   486,    -1,
     485,   212,   486,    -1,   487,    -1,   486,   152,   487,    -1,
     486,   138,   487,    -1,   488,    -1,   488,    51,   237,   552,
      -1,   489,    -1,   489,   202,    96,   552,    -1,   490,    -1,
     490,   103,    96,   491,    -1,   492,    -1,   492,   104,    96,
     491,    -1,   557,    -1,   557,   146,    -1,   494,    -1,   493,
     494,    -1,   178,    -1,   160,    -1,   493,   178,    -1,   493,
     160,    -1,   498,    -1,   495,    -1,   499,    -1,   502,    -1,
     495,   195,   502,    -1,   205,    -1,   210,    -1,   209,    -1,
     208,    -1,   207,    -1,   206,    -1,   153,    -1,   181,    -1,
     142,    -1,    77,   155,   399,   186,    -1,    77,   228,   155,
     399,   186,    -1,    77,   227,   155,   399,   186,    -1,    77,
      78,   569,   155,   399,   186,    -1,   500,   155,   186,    -1,
     500,   155,   419,   186,    -1,   501,    -1,   500,   501,    -1,
     179,   658,    17,    -1,   179,    18,    -1,   179,    19,    -1,
     503,    -1,   504,    -1,   507,    -1,   658,    -1,   506,    -1,
     196,    -1,    11,    -1,    12,    -1,    20,    -1,   510,    -1,
     507,   508,    -1,   507,   158,   189,    -1,   507,   158,   520,
     189,    -1,   507,   121,   657,    -1,   507,   121,   515,    -1,
     507,   121,   514,    -1,   507,   121,   571,    -1,   507,   121,
     196,    -1,   509,    -1,   508,   509,    -1,   156,   419,   187,
      -1,   511,    -1,   514,    -1,   515,    -1,   516,    -1,   519,
      -1,   524,    -1,   517,    -1,   518,    -1,   521,    -1,   403,
      -1,   645,    -1,   642,    -1,   643,    -1,   644,    -1,   512,
      -1,   571,    -1,   513,    -1,   221,    -1,   112,    -1,   151,
      -1,   126,    -1,   222,    -1,   223,    -1,   120,   658,    -1,
     158,   189,    -1,   158,   419,   189,    -1,   121,    -1,   171,
     155,   419,   186,    -1,   204,   155,   419,   186,    -1,   659,
     158,   189,    -1,   659,   158,   520,   189,    -1,   146,    -1,
     520,   109,   146,    -1,   420,    -1,   520,   109,   420,    -1,
     522,    -1,   523,    -1,   658,   147,   151,    -1,    48,   387,
     404,    -1,   525,    -1,   543,    -1,   526,    -1,   540,    -1,
     541,    -1,   159,   658,   530,   132,    -1,   159,   658,   530,
     199,   197,   658,   530,   199,    -1,   159,   658,   528,   530,
     132,    -1,   159,   658,   528,   530,   199,   197,   658,   530,
     199,    -1,   159,   658,   530,   199,   527,   197,   658,   530,
     199,    -1,   159,   658,   528,   530,   199,   527,   197,   658,
     530,   199,    -1,   538,    -1,   527,   538,    -1,   529,    -1,
     528,   529,    -1,    36,   658,   530,   134,   530,   531,    -1,
      -1,    36,    -1,   185,   532,   185,    -1,    95,   534,    95,
      -1,    -1,   533,    -1,   136,    -1,   536,    -1,   533,   136,
      -1,   533,   536,    -1,    -1,   535,    -1,   135,    -1,   537,
      -1,   535,   135,    -1,   535,   537,    -1,    29,    -1,   539,
      -1,     5,    -1,   539,    -1,   525,    -1,    10,    -1,   542,
      -1,   539,    -1,     9,    -1,   125,    -1,   127,    -1,   155,
     399,   186,    -1,   215,    31,   216,    -1,   215,   216,    -1,
     176,   657,   177,    -1,   176,   657,     8,    -1,   105,     7,
      -1,   544,    -1,   545,    -1,   546,    -1,   547,    -1,   548,
      -1,   549,    -1,   550,    -1,    44,   155,   399,   186,    -1,
      21,   398,   186,    -1,    46,   155,   419,   186,   155,   398,
     186,    -1,    22,   398,   186,    -1,    99,   155,   419,   186,
     155,   398,   186,    -1,    72,   155,   399,   186,    -1,    40,
     155,   399,   186,    -1,    23,   398,   186,    -1,    61,   155,
     419,   186,   155,   398,   186,    -1,    24,   399,   186,    -1,
     162,   155,   419,   186,   155,   399,   186,    -1,    96,   552,
      -1,   554,    -1,   554,   553,    -1,   213,   158,   189,    -1,
     146,    -1,   196,    -1,   178,    -1,   556,    -1,   558,    -1,
     154,   158,   189,    -1,   326,   158,   189,    -1,   572,    -1,
     575,    -1,   652,    -1,   552,    -1,   555,   109,   552,    -1,
     658,    -1,   658,    -1,   560,    -1,   567,    -1,   565,    -1,
     568,    -1,   566,    -1,   564,    -1,   563,    -1,   562,    -1,
     561,    -1,   559,    -1,   231,   158,   189,    -1,    45,   158,
     189,    -1,    45,   158,   567,   189,    -1,    45,   158,   568,
     189,    -1,    54,   158,   189,    -1,    72,   158,   189,    -1,
      40,   158,   189,    -1,    61,   158,   189,    -1,    61,   158,
     657,   189,    -1,    61,   158,    30,   189,    -1,    99,   158,
     189,    -1,    99,   158,   658,   189,    -1,    99,   158,   658,
     109,   569,   189,    -1,    99,   158,   196,   189,    -1,    99,
     158,   196,   109,   569,   189,    -1,    63,   158,   658,   189,
      -1,    46,   158,   189,    -1,    46,   158,   658,   189,    -1,
      46,   158,   658,   109,   569,   189,    -1,    46,   158,   658,
     109,   570,   189,    -1,    46,   158,   196,   189,    -1,    46,
     158,   196,   109,   569,   189,    -1,    46,   158,   196,   109,
     570,   189,    -1,    64,   158,   658,   189,    -1,   658,    -1,
     658,   146,    -1,    30,    -1,   573,    -1,   574,    -1,    48,
     158,   196,   189,    -1,    48,   158,   189,    96,   552,    -1,
      48,   158,   555,   189,    96,   552,    -1,   158,   554,   189,
      -1,    34,   226,   227,    -1,    34,   226,   228,    -1,    34,
     226,   229,    -1,   232,   231,   420,   239,   420,    -1,   232,
     231,   420,    96,   238,   239,   420,    -1,   232,   231,   420,
      96,   240,   239,   420,    -1,   232,   231,   420,   224,   420,
      -1,   232,   231,   420,   225,   420,    -1,   232,   233,   420,
     239,   420,    -1,   232,   233,   420,    96,   238,   239,   420,
      -1,   232,   233,   420,    96,   240,   239,   420,    -1,   232,
     233,   420,   224,   420,    -1,   232,   233,   420,   225,   420,
      -1,   230,   231,   420,    -1,   230,   233,   420,    -1,   235,
     231,   420,   243,   420,    -1,   235,   236,   237,   231,   420,
     243,   420,    -1,   234,   231,   420,    96,   420,    -1,   242,
     120,   582,   241,   420,   188,   420,    -1,   583,    -1,   582,
     109,   120,   583,    -1,   658,   144,   420,    -1,   250,   155,
     419,   186,   585,    -1,   586,    -1,   585,   586,    -1,   251,
     588,   587,    -1,   155,   419,   186,    -1,   505,    -1,   588,
     212,   505,    -1,   592,   590,    -1,    -1,   591,    -1,   610,
      -1,   591,   610,    -1,   593,    -1,   592,   268,   593,    -1,
     594,    -1,   593,   264,   594,    -1,   595,    -1,   594,   266,
     149,   595,    -1,   596,    -1,   265,   596,    -1,   600,   597,
     598,    -1,    -1,   615,    -1,    -1,   599,    -1,   288,   155,
     419,   186,    -1,   604,   601,    -1,   158,   589,   189,    -1,
     602,    -1,    -1,   637,    -1,   500,   155,   603,   186,    -1,
      -1,   589,    -1,   605,   606,    -1,   511,    -1,   155,   419,
     186,    -1,    -1,   607,    -1,   254,   608,    -1,   253,   609,
      -1,   276,    -1,    -1,    80,    -1,    -1,   292,    -1,   611,
      -1,   612,    -1,   613,    -1,   639,    -1,   636,    -1,   171,
      -1,   290,   483,   614,    -1,   259,   638,   614,    -1,   292,
      -1,   282,    -1,   275,    -1,   252,   616,    -1,   615,   252,
     616,    -1,   617,    -1,   618,    -1,   619,    -1,   634,    -1,
     620,    -1,   628,    -1,   621,    -1,   635,    -1,   102,   280,
      -1,   102,   269,    -1,   272,    -1,   287,    -1,   257,   280,
      -1,   257,   269,    -1,    58,   658,    30,    -1,   283,    -1,
      56,   283,    -1,   285,   622,    -1,   285,   158,   622,   623,
     189,    -1,    56,   285,    -1,   625,    -1,   115,    -1,    -1,
     109,   624,    -1,   625,    -1,   624,   109,   625,    -1,    98,
      30,   626,   627,    -1,    -1,   277,    30,    -1,    -1,   638,
     271,    -1,   284,   292,   629,   631,    -1,   284,   292,   115,
     631,    -1,    56,   284,   292,    -1,    98,    30,    -1,   158,
     630,   189,    -1,    30,    -1,   630,   109,    30,    -1,    -1,
     632,    -1,   633,    -1,   632,   633,    -1,   203,   629,    -1,
     138,   629,    -1,   270,    30,    -1,   289,    -1,    56,   289,
      -1,    98,   220,    -1,    98,   260,    -1,   261,   256,    -1,
     273,   638,   286,    -1,   262,   483,    -1,    98,   131,   483,
      -1,    98,    53,   483,    -1,   263,   483,   201,   483,    -1,
     278,   640,    -1,   258,   640,    -1,   281,    -1,   274,    -1,
     291,   256,   485,    -1,   156,   187,    -1,   156,   419,   187,
      -1,   316,   317,    -1,   316,   419,   317,    -1,   318,   319,
      -1,   318,   419,   319,    -1,   155,   646,   186,    -1,   657,
     123,   420,    -1,   420,   123,   420,    -1,   646,   109,   420,
     123,   420,    -1,   646,   109,   657,   123,   420,    -1,   232,
     320,   420,   239,   420,    -1,   232,   320,   646,   239,   420,
      -1,   232,   320,   420,   239,   420,    98,   322,   420,    -1,
     321,   320,   420,   239,   420,    -1,   230,   320,   507,    -1,
     234,   320,   507,    96,   420,    -1,   235,   320,   236,   237,
     507,   243,   420,    -1,   653,    -1,   654,    -1,   655,    -1,
     325,    -1,   323,   158,   189,    -1,   324,   158,   189,    -1,
      30,    -1,    16,    -1,   658,    -1,   659,    -1,    99,    -1,
      40,    -1,    45,    -1,    54,    -1,    46,    -1,   154,    -1,
      49,    -1,   231,    -1,    61,    -1,    63,    -1,    64,    -1,
      72,    -1,    75,    -1,    74,    -1,   213,    -1,   249,    -1,
     660,    -1,    25,    -1,   217,    -1,   129,    -1,    39,    -1,
     267,    -1,    38,    -1,   228,    -1,   227,    -1,   148,    -1,
      44,    -1,   265,    -1,   266,    -1,   280,    -1,   269,    -1,
     257,    -1,   291,    -1,   283,    -1,   285,    -1,   284,    -1,
     289,    -1,   261,    -1,   256,    -1,    80,    -1,   220,    -1,
     260,    -1,    53,    -1,   229,    -1,   242,    -1,   308,    -1,
     236,    -1,   205,    -1,   210,    -1,   209,    -1,   208,    -1,
     207,    -1,   206,    -1,    98,    -1,   113,    -1,   114,    -1,
     188,    -1,    47,    -1,    37,    -1,    68,    -1,    73,    -1,
      60,    -1,    55,    -1,    57,    -1,    79,    -1,    43,    -1,
     149,    -1,    52,    -1,   214,    -1,   172,    -1,   173,    -1,
     170,    -1,    71,    -1,    97,    -1,   118,    -1,   130,    -1,
     131,    -1,   108,    -1,    69,    -1,   137,    -1,   190,    -1,
     102,    -1,    96,    -1,   200,    -1,   128,    -1,   169,    -1,
      94,    -1,    51,    -1,   237,    -1,   103,    -1,   201,    -1,
     119,    -1,   161,    -1,   203,    -1,   152,    -1,   138,    -1,
      77,    -1,    78,    -1,   104,    -1,   202,    -1,   153,    -1,
     184,    -1,   198,    -1,   162,    -1,   139,    -1,   133,    -1,
     168,    -1,   150,    -1,   167,    -1,    34,    -1,    41,    -1,
      59,    -1,   115,    -1,    42,    -1,    58,    -1,   219,    -1,
      50,    -1,    62,    -1,    35,    -1,    48,    -1,   279,    -1,
     255,    -1,   288,    -1,   290,    -1,   259,    -1,   273,    -1,
     286,    -1,   278,    -1,   258,    -1,   272,    -1,   287,    -1,
     277,    -1,   271,    -1,   270,    -1,   254,    -1,   253,    -1,
     262,    -1,   263,    -1,   292,    -1,   282,    -1,   281,    -1,
     276,    -1,   274,    -1,   275,    -1,   235,    -1,   241,    -1,
     238,    -1,   232,    -1,   225,    -1,   224,    -1,   226,    -1,
     243,    -1,   233,    -1,   234,    -1,   240,    -1,   230,    -1,
     239,    -1,    67,    -1,    65,    -1,    76,    -1,   171,    -1,
     204,    -1,   248,    -1,   246,    -1,   247,    -1,   244,    -1,
     245,    -1,   250,    -1,   251,    -1,   252,    -1,    66,    -1,
     301,    -1,   299,    -1,   300,    -1,   305,    -1,   306,    -1,
     307,    -1,   302,    -1,   303,    -1,   304,    -1,    81,    -1,
      82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,
      87,    -1,    88,    -1,    89,    -1,    90,    -1,    91,    -1,
     293,    -1,   294,    -1,   295,    -1,   296,    -1,   297,    -1,
     298,    -1,   309,    -1,   310,    -1,   311,    -1,   312,    -1,
     313,    -1,   314,    -1,   315,    -1,    92,    -1,   107,    -1,
     116,    -1,   174,    -1,   182,    -1,   191,    -1,   140,    -1,
      93,    -1,   117,    -1,   141,    -1,   183,    -1,   320,    -1,
     321,    -1,   322,    -1,   324,    -1,   323,    -1,   326,    -1,
      26,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  jsoniq_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    15,    17,    20,    23,
      25,    28,    30,    33,    38,    45,    50,    57,    61,    65,
      71,    73,    77,    81,    87,    93,    95,    99,   103,   109,
     116,   118,   122,   126,   128,   130,   132,   134,   136,   138,
     140,   142,   144,   146,   148,   150,   152,   156,   160,   165,
     169,   173,   177,   181,   185,   191,   197,   203,   209,   215,
     221,   223,   225,   229,   233,   238,   244,   251,   253,   257,
     261,   265,   269,   276,   282,   291,   297,   303,   309,   311,
     315,   319,   321,   323,   325,   327,   329,   331,   333,   335,
     340,   345,   347,   350,   354,   356,   358,   360,   362,   364,
     366,   368,   370,   372,   374,   379,   383,   388,   392,   394,
     396,   398,   401,   404,   409,   413,   419,   423,   428,   433,
     439,   441,   444,   446,   451,   453,   458,   460,   464,   467,
     471,   473,   475,   480,   485,   491,   497,   500,   504,   509,
     515,   517,   521,   524,   528,   532,   538,   543,   550,   552,
     555,   557,   560,   569,   579,   581,   585,   587,   590,   593,
     597,   609,   624,   638,   661,   663,   665,   667,   668,   670,
     672,   673,   675,   678,   680,   683,   688,   690,   692,   694,
     696,   698,   700,   702,   704,   706,   708,   710,   712,   716,
     719,   723,   727,   730,   734,   737,   741,   744,   748,   753,
     759,   765,   768,   773,   779,   783,   787,   790,   793,   802,
     806,   808,   811,   815,   817,   821,   825,   827,   829,   831,
     833,   835,   837,   839,   841,   843,   845,   847,   849,   851,
     853,   855,   857,   859,   861,   864,   867,   870,   873,   875,
     877,   880,   885,   889,   895,   900,   904,   906,   908,   910,
     912,   914,   916,   918,   920,   922,   925,   929,   933,   936,
     938,   940,   942,   947,   951,   955,   961,   966,   973,   978,
     985,   991,   999,  1004,  1010,  1016,  1023,  1027,  1031,  1034,
    1036,  1040,  1045,  1051,  1055,  1062,  1067,  1073,  1075,  1078,
    1082,  1084,  1087,  1089,  1096,  1100,  1104,  1107,  1111,  1113,
    1117,  1120,  1125,  1131,  1138,  1144,  1148,  1151,  1155,  1160,
    1162,  1166,  1168,  1171,  1173,  1175,  1177,  1180,  1183,  1186,
    1190,  1192,  1194,  1197,  1200,  1203,  1209,  1215,  1217,  1222,
    1226,  1231,  1240,  1242,  1245,  1249,  1252,  1256,  1265,  1267,
    1270,  1274,  1283,  1294,  1303,  1314,  1316,  1319,  1324,  1332,
    1334,  1337,  1342,  1350,  1352,  1356,  1365,  1367,  1371,  1373,
    1377,  1379,  1383,  1387,  1391,  1395,  1396,  1401,  1405,  1409,
    1413,  1415,  1421,  1423,  1427,  1428,  1430,  1432,  1436,  1438,
    1442,  1446,  1448,  1452,  1456,  1460,  1464,  1466,  1470,  1474,
    1476,  1480,  1484,  1486,  1491,  1493,  1498,  1500,  1505,  1507,
    1512,  1514,  1517,  1519,  1522,  1524,  1526,  1529,  1532,  1534,
    1536,  1538,  1540,  1544,  1546,  1548,  1550,  1552,  1554,  1556,
    1558,  1560,  1562,  1567,  1573,  1579,  1586,  1590,  1595,  1597,
    1600,  1604,  1607,  1610,  1612,  1614,  1616,  1618,  1620,  1622,
    1624,  1626,  1628,  1630,  1633,  1637,  1642,  1646,  1650,  1654,
    1658,  1662,  1664,  1667,  1671,  1673,  1675,  1677,  1679,  1681,
    1683,  1685,  1687,  1689,  1691,  1693,  1695,  1697,  1699,  1701,
    1703,  1705,  1707,  1709,  1711,  1713,  1715,  1717,  1720,  1723,
    1727,  1729,  1734,  1739,  1743,  1748,  1750,  1754,  1756,  1760,
    1762,  1764,  1768,  1772,  1774,  1776,  1778,  1780,  1782,  1787,
    1796,  1802,  1812,  1822,  1833,  1835,  1838,  1840,  1843,  1850,
    1851,  1853,  1857,  1861,  1862,  1864,  1866,  1868,  1871,  1874,
    1875,  1877,  1879,  1881,  1884,  1887,  1889,  1891,  1893,  1895,
    1897,  1899,  1901,  1903,  1905,  1907,  1909,  1913,  1917,  1920,
    1924,  1928,  1931,  1933,  1935,  1937,  1939,  1941,  1943,  1945,
    1950,  1954,  1962,  1966,  1974,  1979,  1984,  1988,  1996,  2000,
    2008,  2011,  2013,  2016,  2020,  2022,  2024,  2026,  2028,  2030,
    2034,  2038,  2040,  2042,  2044,  2046,  2050,  2052,  2054,  2056,
    2058,  2060,  2062,  2064,  2066,  2068,  2070,  2072,  2074,  2078,
    2082,  2087,  2092,  2096,  2100,  2104,  2108,  2113,  2118,  2122,
    2127,  2134,  2139,  2146,  2151,  2155,  2160,  2167,  2174,  2179,
    2186,  2193,  2198,  2200,  2203,  2205,  2207,  2209,  2214,  2220,
    2227,  2231,  2235,  2239,  2243,  2249,  2257,  2265,  2271,  2277,
    2283,  2291,  2299,  2305,  2311,  2315,  2319,  2325,  2333,  2339,
    2347,  2349,  2354,  2358,  2364,  2366,  2369,  2373,  2377,  2379,
    2383,  2386,  2387,  2389,  2391,  2394,  2396,  2400,  2402,  2406,
    2408,  2413,  2415,  2418,  2422,  2423,  2425,  2426,  2428,  2433,
    2436,  2440,  2442,  2443,  2445,  2450,  2451,  2453,  2456,  2458,
    2462,  2463,  2465,  2468,  2471,  2473,  2474,  2476,  2477,  2479,
    2481,  2483,  2485,  2487,  2489,  2491,  2495,  2499,  2501,  2503,
    2505,  2508,  2512,  2514,  2516,  2518,  2520,  2522,  2524,  2526,
    2528,  2531,  2534,  2536,  2538,  2541,  2544,  2548,  2550,  2553,
    2556,  2562,  2565,  2567,  2569,  2570,  2573,  2575,  2579,  2584,
    2585,  2588,  2589,  2592,  2597,  2602,  2606,  2609,  2613,  2615,
    2619,  2620,  2622,  2624,  2627,  2630,  2633,  2636,  2638,  2641,
    2644,  2647,  2650,  2654,  2657,  2661,  2665,  2670,  2673,  2676,
    2678,  2680,  2684,  2687,  2691,  2694,  2698,  2701,  2705,  2709,
    2713,  2717,  2723,  2729,  2735,  2741,  2750,  2756,  2760,  2766,
    2774,  2776,  2778,  2780,  2782,  2786,  2790,  2792,  2794,  2796,
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
    3178,  3180,  3182,  3184,  3186,  3188,  3190,  3192,  3194,  3196,
    3198,  3200,  3202,  3204,  3206,  3208,  3210,  3212,  3214,  3216,
    3218,  3220,  3222,  3224,  3226,  3228,  3230,  3232,  3234,  3236,
    3238,  3240
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  jsoniq_parser::yyrline_[] =
  {
         0,  1068,  1068,  1069,  1073,  1077,  1085,  1091,  1095,  1104,
    1110,  1118,  1124,  1135,  1140,  1144,  1149,  1158,  1165,  1172,
    1181,  1188,  1196,  1204,  1212,  1223,  1228,  1235,  1242,  1254,
    1264,  1271,  1278,  1290,  1291,  1292,  1293,  1294,  1299,  1300,
    1301,  1302,  1303,  1304,  1305,  1308,  1313,  1318,  1326,  1334,
    1342,  1347,  1355,  1360,  1368,  1373,  1381,  1386,  1391,  1396,
    1404,  1406,  1409,  1419,  1424,  1432,  1440,  1451,  1458,  1469,
    1474,  1482,  1489,  1496,  1505,  1518,  1526,  1533,  1543,  1550,
    1557,  1568,  1569,  1570,  1571,  1572,  1573,  1574,  1575,  1580,
    1586,  1595,  1602,  1612,  1622,  1623,  1624,  1625,  1626,  1627,
    1628,  1629,  1630,  1631,  1636,  1644,  1652,  1660,  1667,  1675,
    1682,  1687,  1695,  1703,  1717,  1731,  1748,  1753,  1761,  1769,
    1780,  1785,  1794,  1799,  1806,  1811,  1821,  1826,  1835,  1841,
    1854,  1859,  1867,  1878,  1893,  1905,  1920,  1925,  1930,  1935,
    1943,  1950,  1961,  1966,  1976,  1985,  1994,  2003,  2015,  2019,
    2025,  2029,  2039,  2049,  2062,  2068,  2077,  2082,  2089,  2096,
    2107,  2117,  2127,  2137,  2155,  2175,  2179,  2184,  2191,  2195,
    2200,  2207,  2212,  2224,  2231,  2241,  2256,  2257,  2258,  2259,
    2260,  2261,  2262,  2264,  2265,  2266,  2267,  2268,  2273,  2278,
    2286,  2303,  2311,  2319,  2326,  2333,  2344,  2353,  2362,  2371,
    2384,  2392,  2400,  2408,  2423,  2428,  2436,  2450,  2467,  2492,
    2500,  2507,  2518,  2528,  2533,  2546,  2563,  2564,  2565,  2566,
    2567,  2568,  2573,  2574,  2577,  2578,  2579,  2580,  2581,  2584,
    2585,  2586,  2587,  2588,  2593,  2607,  2615,  2620,  2628,  2633,
    2638,  2646,  2655,  2667,  2677,  2690,  2698,  2699,  2700,  2705,
    2706,  2707,  2708,  2709,  2714,  2721,  2731,  2737,  2746,  2755,
    2756,  2764,  2771,  2779,  2791,  2801,  2811,  2821,  2831,  2841,
    2851,  2861,  2872,  2881,  2891,  2901,  2917,  2926,  2935,  2943,
    2949,  2961,  2969,  2979,  2987,  2999,  3005,  3016,  3018,  3022,
    3030,  3034,  3039,  3043,  3047,  3051,  3061,  3069,  3076,  3082,
    3092,  3096,  3100,  3108,  3116,  3124,  3136,  3144,  3150,  3160,
    3166,  3176,  3180,  3190,  3196,  3202,  3208,  3217,  3226,  3235,
    3248,  3252,  3260,  3266,  3276,  3284,  3293,  3306,  3313,  3325,
    3329,  3341,  3348,  3354,  3363,  3370,  3376,  3387,  3394,  3400,
    3409,  3418,  3425,  3436,  3443,  3455,  3461,  3473,  3479,  3490,
    3496,  3507,  3513,  3524,  3530,  3541,  3550,  3554,  3563,  3567,
    3575,  3579,  3589,  3596,  3605,  3615,  3614,  3628,  3637,  3646,
    3659,  3663,  3675,  3679,  3687,  3690,  3697,  3701,  3710,  3714,
    3718,  3726,  3730,  3736,  3742,  3748,  3758,  3762,  3766,  3774,
    3778,  3784,  3794,  3798,  3808,  3812,  3822,  3826,  3836,  3840,
    3850,  3854,  3863,  3867,  3875,  3879,  3883,  3887,  3897,  3901,
    3905,  3912,  3917,  3925,  3929,  3933,  3937,  3941,  3945,  3953,
    3957,  3961,  3969,  3973,  3977,  3981,  3992,  3998,  4008,  4014,
    4024,  4028,  4032,  4095,  4117,  4145,  4309,  4313,  4323,  4327,
    4331,  4335,  4344,  4348,  4352,  4356,  4360,  4365,  4369,  4373,
    4377,  4386,  4392,  4402,  4410,  4414,  4418,  4422,  4426,  4430,
    4434,  4438,  4442,  4446,  4451,  4455,  4459,  4463,  4471,  4475,
    4479,  4483,  4491,  4498,  4505,  4515,  4519,  4527,  4535,  4539,
    4547,  4555,  4563,  4617,  4621,  4643,  4649,  4655,  4661,  4671,
    4675,  4683,  4691,  4703,  4707,  4715,  4719,  4723,  4731,  4739,
    4756,  4764,  4781,  4800,  4824,  4830,  4841,  4847,  4858,  4867,
    4869,  4873,  4878,  4888,  4891,  4898,  4904,  4910,  4917,  4929,
    4932,  4939,  4945,  4951,  4958,  4969,  4973,  4981,  4985,  4993,
    4997,  5001,  5006,  5015,  5019,  5023,  5027,  5035,  5040,  5048,
    5053,  5061,  5069,  5074,  5079,  5084,  5089,  5094,  5099,  5105,
    5113,  5117,  5134,  5138,  5146,  5154,  5162,  5166,  5174,  5178,
    5186,  5194,  5198,  5202,  5237,  5243,  5249,  5259,  5263,  5267,
    5271,  5275,  5279,  5283,  5290,  5296,  5306,  5314,  5322,  5326,
    5330,  5334,  5338,  5342,  5346,  5350,  5354,  5358,  5366,  5374,
    5378,  5382,  5390,  5397,  5405,  5413,  5417,  5421,  5429,  5433,
    5439,  5445,  5449,  5459,  5467,  5471,  5477,  5486,  5495,  5501,
    5507,  5517,  5534,  5541,  5556,  5583,  5587,  5595,  5603,  5607,
    5618,  5635,  5641,  5647,  5657,  5661,  5667,  5673,  5677,  5683,
    5687,  5693,  5699,  5706,  5716,  5721,  5729,  5735,  5745,  5767,
    5776,  5782,  5795,  5809,  5816,  5822,  5832,  5841,  5849,  5855,
    5873,  5881,  5885,  5892,  5897,  5905,  5909,  5916,  5920,  5927,
    5931,  5938,  5942,  5951,  5964,  5967,  5975,  5978,  5986,  5994,
    6002,  6006,  6014,  6017,  6025,  6037,  6040,  6048,  6060,  6066,
    6076,  6079,  6087,  6091,  6095,  6103,  6106,  6114,  6117,  6125,
    6129,  6133,  6137,  6141,  6149,  6157,  6169,  6181,  6185,  6189,
    6197,  6203,  6213,  6217,  6221,  6225,  6229,  6233,  6237,  6241,
    6249,  6253,  6257,  6261,  6269,  6275,  6285,  6295,  6299,  6307,
    6317,  6328,  6335,  6339,  6347,  6350,  6357,  6362,  6371,  6381,
    6384,  6391,  6395,  6403,  6412,  6419,  6429,  6433,  6440,  6446,
    6456,  6459,  6466,  6471,  6483,  6491,  6503,  6511,  6515,  6523,
    6527,  6531,  6539,  6547,  6551,  6555,  6559,  6567,  6575,  6587,
    6591,  6599,  6613,  6617,  6624,  6629,  6637,  6642,  6651,  6659,
    6666,  6672,  6679,  6690,  6696,  6706,  6713,  6720,  6745,  6773,
    6801,  6805,  6809,  6817,  6824,  6831,  6843,  6847,  6848,  6861,
    6862,  6863,  6864,  6865,  6866,  6867,  6868,  6869,  6870,  6871,
    6872,  6873,  6874,  6875,  6876,  6877,  6881,  6882,  6883,  6884,
    6885,  6886,  6887,  6888,  6889,  6890,  6891,  6892,  6893,  6894,
    6895,  6896,  6897,  6898,  6899,  6900,  6901,  6902,  6903,  6904,
    6905,  6906,  6907,  6908,  6909,  6910,  6911,  6912,  6913,  6914,
    6915,  6916,  6917,  6918,  6919,  6920,  6921,  6922,  6923,  6924,
    6925,  6926,  6927,  6928,  6929,  6930,  6931,  6932,  6933,  6934,
    6935,  6936,  6937,  6938,  6939,  6940,  6941,  6942,  6943,  6944,
    6945,  6946,  6947,  6948,  6949,  6950,  6951,  6952,  6953,  6954,
    6955,  6956,  6957,  6958,  6959,  6960,  6961,  6962,  6963,  6964,
    6965,  6966,  6967,  6968,  6969,  6970,  6971,  6972,  6973,  6974,
    6975,  6976,  6977,  6978,  6979,  6980,  6981,  6982,  6983,  6984,
    6985,  6986,  6987,  6988,  6989,  6990,  6991,  6992,  6993,  6994,
    6995,  6996,  6997,  6998,  6999,  7000,  7001,  7002,  7003,  7004,
    7005,  7006,  7007,  7008,  7009,  7010,  7011,  7012,  7013,  7014,
    7015,  7016,  7017,  7018,  7019,  7020,  7021,  7022,  7023,  7024,
    7025,  7026,  7027,  7028,  7029,  7030,  7031,  7032,  7033,  7034,
    7035,  7036,  7037,  7038,  7039,  7040,  7041,  7042,  7043,  7044,
    7045,  7046,  7047,  7048,  7049,  7050,  7051,  7052,  7053,  7054,
    7055,  7056,  7057,  7058,  7059,  7060,  7061,  7062,  7063,  7064,
    7065,  7066,  7067,  7068,  7069,  7070,  7071,  7072,  7073,  7074,
    7075,  7076,  7077,  7078,  7079,  7080,  7081,  7082,  7084,  7085,
    7086,  7091
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
     335,   336,   337,   338,   339,   340
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int jsoniq_parser::yyeof_ = 0;
  const int jsoniq_parser::yylast_ = 17119;
  const int jsoniq_parser::yynnts_ = 320;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 546;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 341;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 595;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17565 "/home/markos/zorba/repo/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 7095 "/home/markos/zorba/repo/new-jsoniq/src/compiler/parser/jsoniq_parser.y"


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

